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
        lv_obj_t* labelTitle;
        lv_obj_t* labelTick;
    } ui;
}template_view_t;

template_view_t* template_view_create(lv_obj_t *root);