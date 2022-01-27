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
        lv_obj_t* label_count;
    } ui;
}template_view_t;

template_view_t* template_view_create(lv_obj_t *root);
void template_view_set_title(template_view_t* self, const char* title);
void template_view_set_count(template_view_t* self, const char* count);