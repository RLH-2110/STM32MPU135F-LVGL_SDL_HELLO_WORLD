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

volatile sig_atomic_t noStop = 1;

void on_termination(int signal){
  noStop = 0;
}

void btn_hello_world_click_cb(lv_event_t* e);

static lv_display_t *disp;
static lv_indev_t *lvMouse;
static pthread_t thread1;
static void* tick_thread(void* data);


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

  // gui here

  static lv_style_t german_font_style;
  lv_style_init(&german_font_style);
  lv_style_set_text_font(&german_font_style, &Monsterat);


  lv_obj_t* screen = lv_obj_create(NULL);

  lv_obj_t* button = lv_button_create(screen);
  lv_obj_align(button, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t* button_label = lv_label_create(button);
  lv_label_set_text(button_label, "Testus");
  lv_obj_align(button_label, LV_ALIGN_CENTER,0,0);
  lv_obj_add_style(button_label, &german_font_style, 0);

  lv_obj_add_event_cb(button, btn_hello_world_click_cb, LV_EVENT_CLICKED, NULL);


  lv_screen_load(screen);


  // gui end


  int i = 0;
  while(noStop){
    uint32_t time_till_next = lv_timer_handler();
    usleep(time_till_next*MICROSECOND_TO_MILISECOND_RATE ); 
  }

  puts("Stopping thread and exiting...");
  pthread_join(thread1,NULL);
  puts("counter joined");
  lv_indev_delete(lvMouse);
  puts("\"mouse\" deleted");
  lv_disp_remove(disp);
  puts("display removed");
  lv_sdl_quit();
  puts("quit sql");
  lv_deinit();
  puts("Exiting...");

  return 0;

}


static void *tick_thread(void* data) {
    (void) data;
    while(noStop) {
        usleep(5 * 1000);
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }
}


void btn_hello_world_click_cb(lv_event_t* e) {
    static char text[] = "1. Gedrückt!";
    lv_obj_t* label = lv_obj_get_child(lv_event_get_target_obj(e),0);
    lv_label_set_text(label, text);

    text[0]++;
    if (text[0] > '9')
        text[0] = '1';
}

