#pragma once

#include "page_manager.h"
#include "demo_view.h"
#include "demo_model.h"



typedef struct 
{
    const char* name;
    page_vtable_t page_param;
    demo_view_t* demo_view;
    lv_task_t* task;
    struct
    {
        uint16_t time;
        lv_color_t color;
    } param;
}demo_t;

page_vtable_t demo_create(const char* name);
