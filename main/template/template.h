#pragma once

#include "page_manager.h"
#include "template_view.h"
#include "template_model.h"



typedef struct 
{
    const char* name;
    page_vtable_t page_param;
    // template_model_t* template_model;
    template_view_t* template_view;
}template_t;

page_vtable_t template_create(const char* name);