#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>

#include "lv_drv_conf.h"
#include "lvgl/lvgl.h"
#include "lvgl/src/drivers/sdl/lv_sdl_mouse.h"

#define H_RES (480)
#define V_RES (272)

#define NANOSECOND_TO_MILISECOND_RATE 1000000
#define MICROSECOND_TO_MILISECOND_RATE 1000

#include "font.c"


/* lvgl stuff and threats */
static lv_display_t *disp;
static lv_indev_t *lvMouse;

static pthread_t thread1;
static void* tick_thread(void* data);
volatile sig_atomic_t noStop = 1; /* programms runs as long as this is set */

/* screens */
void main_screen(void);
void sub_menu(void);

/* callbacks */
void btn_main_screen_hello_world_click_cb(lv_event_t* e);
void btn_main_screen_open_submenu_click_cb(lv_event_t* e);
void btn_matrix_sub_menu_valchange_cb(lv_event_t* e);

/* other */
lv_obj_t * arc = NULL; 
bool arc_updates = false;
bool arc_increase = true;
int arc_val = 0;
#define ARC_MAX_RANGE 10

char test_button_text[] = "1. Gedrückt!";

lv_style_t german_font_style; /* style that includes german symbols */
  
enum sub_btn_names { /* button ids for the button matrix in the sub menu */
  sub_btn_back = 0, sub_btn_messageBox = 1, sub_btn_exit = 2, sub_btn_first_oob_index
};

int hello_world_button_total_clicks = 0;

/* signal handler */
void on_termination(int signal){
  noStop = 0;
}

/* macro functions */

#define obj_pos_half_left(obj)  (lv_obj_get_x(obj) - lv_obj_get_width(obj) / 2) /* gets position of the object if it was moved left by half the objects size */
#define obj_pos_half_right(obj) (lv_obj_get_x(obj) + lv_obj_get_width(obj) / 2)

int main(){

  puts("hello world");

  lv_init();

  signal(SIGINT,on_termination);
  signal(SIGTERM,on_termination);
  pthread_create( &thread1, NULL, tick_thread,NULL);

  disp = lv_sdl_window_create(H_RES, V_RES);
  if (disp == NULL){
    puts("Display error!");
    return 1;
  }
  lvMouse = lv_sdl_mouse_create();


  /* gui stuff here */

  lv_style_init(&german_font_style);
  lv_style_set_text_font(&german_font_style, &Monsterat);

  main_screen();

  /* end gui stuff*/


  int i = 0;
  while(noStop){
    uint32_t time_till_next = lv_timer_handler();
    usleep(time_till_next*MICROSECOND_TO_MILISECOND_RATE ); 
    
    if (arc_updates) {

      if(arc_increase){
        arc_val++;
        if (arc_val >= ARC_MAX_RANGE)
          arc_increase = false;
      }else{
        arc_val--;
        if (arc_val <= 0)
          arc_increase = true;
      }      

     lv_arc_set_value(arc,arc_val);

    }
  }

  puts("Stopping thread and exiting...");
  pthread_join(thread1,NULL);
  puts("counter joined");
  lv_indev_delete(lvMouse);
  puts("\"mouse\" deleted");
  lv_disp_remove(disp);
  puts("display removed");
  lv_sdl_quit();
  puts("quit sdl");
  lv_deinit();
  puts("Exiting...");

  return 0;

}

/* screens */
void main_screen(void)
{
  puts("loading main screen...");

  arc_updates = false;
  
  /* reset clivked test button text*/
  test_button_text[0] = '1';

  static lv_obj_t *screen; screen = lv_obj_create(NULL);

  /* hello world button */
  static lv_obj_t* hello_world_button; hello_world_button = lv_button_create(screen);

  /* hello world button label*/
  static lv_obj_t *hello_world_button_label; hello_world_button_label = lv_label_create(hello_world_button);
  lv_label_set_text(hello_world_button_label, "Test Button");
  lv_obj_add_style(hello_world_button_label, &german_font_style, 0);
  lv_obj_align(hello_world_button_label, LV_ALIGN_CENTER,0,0);

  /* submenu button */
  static lv_obj_t *submenu_button; submenu_button = lv_button_create(screen);

  /* submenu button label*/
  static lv_obj_t *submenu_button_label; submenu_button_label = lv_label_create(submenu_button);
  lv_label_set_text(submenu_button_label, "Sub Menu");
  lv_obj_add_style(submenu_button_label, &german_font_style, 0);
  lv_obj_align(submenu_button_label, LV_ALIGN_CENTER,0,0);

  /* tot. click bar till 100 */
  lv_obj_t *bar; bar = lv_bar_create(screen);
  lv_bar_set_value(bar, hello_world_button_total_clicks, LV_ANIM_OFF);
  lv_obj_align(bar, LV_ALIGN_TOP_MID, 0, 90); 

  /* button click events */
  lv_obj_add_event_cb(hello_world_button,btn_main_screen_hello_world_click_cb, LV_EVENT_CLICKED, bar);
  lv_obj_add_event_cb(submenu_button,btn_main_screen_open_submenu_click_cb, LV_EVENT_CLICKED, NULL);


  /* positioning buttons */
  {
    /* calculate current positions */
    lv_obj_update_layout(hello_world_button); 
    lv_obj_update_layout(submenu_button);

    /* hello world button */
    lv_obj_align(hello_world_button, LV_ALIGN_CENTER, obj_pos_half_left(hello_world_button) - 1, 0); /* move button left by half its size plus 1 (the one is so the buttons dont intersect on the border)*/
   
    /* sub menu button   */ 
    lv_obj_align(submenu_button, LV_ALIGN_CENTER, obj_pos_half_right(submenu_button) + 1, 0); 
  }

  lv_screen_load_anim(screen,LV_SCR_LOAD_ANIM_NONE,0,0,true);
  puts("main screen loaded");
}

void sub_menu(void)
{
  puts("loading sub menu...");

  static lv_obj_t* screen; screen = lv_obj_create(NULL);

  /* arc */
  arc = lv_arc_create(screen);
  lv_arc_set_range(arc,0,ARC_MAX_RANGE);
  lv_arc_set_bg_angles(arc, 225, 315);
  /* lv_obj_set_width(arc,400); */ /* does not resize the arc */
  lv_obj_remove_style(arc, NULL, LV_PART_INDICATOR);
  lv_obj_remove_flag(arc, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_align(arc, LV_ALIGN_TOP_MID, 0, 35);
  lv_arc_set_knob_offset(arc,0);
  arc_updates = true;

  /* button matrix */
  static lv_obj_t *buttons; buttons = lv_buttonmatrix_create(screen);
  static char const * const button_map[] = { "Back", "MsgBox", "Exit", NULL};
  lv_buttonmatrix_set_map(buttons, button_map);
  lv_obj_add_style(buttons, &german_font_style, 0);
  lv_obj_align(buttons, LV_ALIGN_BOTTOM_MID,0,-35);
  lv_obj_set_width(buttons, H_RES - 40); /* -40, so we have 20 pixel space on each side of the screen */   

  /* for all buttons */
  for (int i = 0; i < sub_btn_first_oob_index; i++){
    lv_buttonmatrix_set_button_ctrl(buttons, i, LV_BUTTONMATRIX_CTRL_NO_REPEAT);
    lv_buttonmatrix_set_button_width(buttons, i, 3);
  }

  lv_obj_add_event_cb(buttons, btn_matrix_sub_menu_valchange_cb, LV_EVENT_VALUE_CHANGED, NULL);
  
  lv_screen_load_anim(screen,LV_SCR_LOAD_ANIM_NONE,0,0,true);
  puts("sub menu loaded");
}


/* callbacks */

void btn_main_screen_hello_world_click_cb(lv_event_t *e) {
  /* get button label, and change text */
  lv_obj_t* label = lv_obj_get_child(lv_event_get_target_obj(e),0);
  lv_label_set_text(label, test_button_text);

  if (hello_world_button_total_clicks < 100) /* we want to stop counting after 100 */
  {
    hello_world_button_total_clicks++;
    lv_bar_set_value(lv_event_get_user_data(e),hello_world_button_total_clicks,LV_ANIM_OFF); /* lv_event_get_user_data(e) is bar */
  }
  /* update button text for next time */
  test_button_text[0]++;
  if (test_button_text[0] > '9')
    test_button_text[0] = '1';
}


void btn_main_screen_open_submenu_click_cb(lv_event_t *e) {
  sub_menu();
}

void btn_matrix_sub_menu_valchange_cb(lv_event_t *e)
{
  int btn_id = lv_buttonmatrix_get_selected_button(lv_event_get_target_obj(e));
  
  switch(btn_id){
    case sub_btn_back:
      main_screen();
      break;
    
    case sub_btn_messageBox:
      lv_obj_t *msgbox = lv_msgbox_create(NULL);
      lv_msgbox_add_text(msgbox, "This is a test!");
      lv_msgbox_add_title(msgbox, "Info");
      lv_msgbox_add_close_button(msgbox);
      break;    
    
    case sub_btn_exit:
      noStop = 0;
      break;

    default:
      printf("INVALID BUTTON ID IN SUBMENU! ID: %d\n",btn_id);
  }
}

/* other functions */
static void *tick_thread(void* data) {
  (void) data;
  while(noStop) {
    usleep(5 * 1000);
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }
}


