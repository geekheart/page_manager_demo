#pragma once

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

typedef struct 
{
    struct
    {
        lv_obj_t* label_title;
        lv_obj_t* label_tick;
    } ui;
}demo_view_t;

demo_view_t* demo_view_create(lv_obj_t *root);
void demo_view_set_title(demo_view_t* self, const char* title);
void demo_view_set_tick(demo_view_t* self, const char* tick);
