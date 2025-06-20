/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --no-compress --font Montserrat-Regular.ttf --symbols ÄÖÜäöüßẞ --format lvgl -o Monsterat.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MONSTERAT
#define MONSTERAT 1
#endif

#if MONSTERAT

 /*-----------------
  *    BITMAPS
  *----------------*/

  /*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+00C4 "Ä" */
    0x6, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x80, 0x1, 0x80, 0x3, 0xc0, 0x2, 0x40,
    0x6, 0x60, 0x4, 0x20, 0xc, 0x30, 0xc, 0x30,
    0x18, 0x18, 0x18, 0x18, 0x30, 0x8, 0x3f, 0xfc,
    0x20, 0x4, 0x60, 0x6, 0x40, 0x2, 0xc0, 0x3,
    0xc0, 0x3,

    /* U+00D6 "Ö" */
    0x3, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xf0, 0x3, 0x3, 0x3, 0x80, 0x70,
    0xc0, 0xc, 0x60, 0x1, 0xb8, 0x0, 0x6c, 0x0,
    0xf, 0x0, 0x3, 0xc0, 0x0, 0xf0, 0x0, 0x3c,
    0x0, 0xf, 0x80, 0x6, 0x60, 0x1, 0x8c, 0x0,
    0xc3, 0x80, 0x70, 0x30, 0x30, 0x3, 0xf0, 0x0,

    /* U+00DC "Ü" */
    0xc, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0,
    0xf, 0x0, 0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf,
    0x0, 0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0,
    0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xd, 0x80, 0x66,
    0x1, 0x8e, 0x1c, 0xf, 0xc0,

    /* U+00DF "ß" */
    0x1f, 0x1, 0x86, 0x18, 0x19, 0x80, 0xcc, 0x6,
    0x60, 0x33, 0x3, 0x18, 0x30, 0xc7, 0x86, 0x3,
    0x30, 0xd, 0x80, 0x3c, 0x1, 0xe0, 0xf, 0x0,
    0x78, 0x6, 0xc0, 0x66, 0x7e, 0x0,

    /* U+00E4 "ä" */
    0x31, 0x80, 0x0, 0x0, 0x0, 0x3, 0xf0, 0xc3,
    0x90, 0x38, 0x3, 0x0, 0x60, 0xc, 0xff, 0xb0,
    0x3c, 0x7, 0x80, 0xf0, 0x3b, 0xf, 0x3e, 0x60,

    /* U+00F6 "ö" */
    0x18, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8,
    0x1c, 0x71, 0x80, 0xcc, 0x6, 0xc0, 0x1e, 0x0,
    0xf0, 0x7, 0x80, 0x3c, 0x1, 0xb0, 0x19, 0x80,
    0xc7, 0x1c, 0xf, 0x80,

    /* U+00FC "ü" */
    0x19, 0x80, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x3c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xc0, 0x3c, 0x3, 0x60, 0x77, 0xf,
    0x1f, 0x30,

    /* U+1E9E "ẞ" */
    0xf, 0xe0, 0xe0, 0xc6, 0x3, 0x18, 0x18, 0xc0,
    0xc3, 0x3, 0xc, 0x18, 0x30, 0xf8, 0xc0, 0x3b,
    0x0, 0x6c, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0,
    0x3c, 0x1, 0xb1, 0xe, 0xc7, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 275, .box_w = 16, .box_h = 21, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 322, .box_w = 18, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 304, .box_w = 14, .box_h = 21, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 257, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 227, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 241, .box_w = 13, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 258, .box_w = 12, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 290, .box_w = 14, .box_h = 17, .ofs_x = 3, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x12, 0x18, 0x1b, 0x20, 0x32, 0x38, 0x1dda
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 196, .range_length = 7643, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 8, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
 /*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_24;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

 /*Initialize a public general font descriptor*/
 #if LVGL_VERSION_MAJOR >= 8
 const lv_font_t Monsterat = {
 #else
 lv_font_t Monsterat = {
 #endif
     .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
     .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
     .line_height = 21,          /*The maximum line height required by the font*/
     .base_line = 0,             /*Baseline measured from the bottom of the line*/
 #if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
     .subpx = LV_FONT_SUBPX_NONE,
 #endif
 #if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
     .underline_position = -2,
     .underline_thickness = 1,
 #endif
     .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
 #if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
     .fallback = &lv_font_montserrat_24,
 #endif
     .user_data = NULL,
 };



 #endif /*#if MONSTERAT*/


