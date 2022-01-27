#include "template.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static template_t template;

static void template_event_cb(lv_obj_t *obj, lv_event_t event)
{
    page_base_t *page_base = (page_base_t *)obj->user_data;
    page_manager_t *manager = page_base->manager;
    if (event == LV_EVENT_LEAVE)
    {
        pm_pop(manager);
    }
}

static void on_custom_attr_config(page_base_t *self)
{
    page_set_custom_root_event_cb(self, template_event_cb);
    page_set_custom_auto_cache_enable(self, true);
    page_set_custom_load_anim_type(self, LOAD_ANIM_OVER_BOTTOM, 1000, lv_anim_path_overshoot);
}

/* Page load */
static void on_view_load(page_base_t *self)
{
    char count_str[15];
    sprintf(count_str, "count:%d", template_get_count());
    template.template_view = template_view_create(self->root);
    template_view_set_title(template.template_view, self->name);
    template_view_set_count(template.template_view, count_str);
}

/* Page load complete */
static void on_view_did_load(page_base_t *self)
{
    
}

/* Page will be displayed soon  */
static void on_view_will_appear(page_base_t *self)
{
}

/* The page is displayed  */
static void on_view_did_appear(page_base_t *self)
{
}

/* Page is about to disappear */
static void on_view_will_disappear(page_base_t *self)
{
}

/* Page disappeared complete  */
static void on_view_did_disappear(page_base_t *self)
{
}

/* Page uninstall complete  */
static void on_view_did_unload(page_base_t *self)
{
}

static page_vtable_t page_param = {
    .on_custom_attr_config = on_custom_attr_config,
    .on_view_load = on_view_load,
    .on_view_did_load = on_view_did_load,
    .on_view_will_appear = on_view_will_appear,
    .on_view_did_appear = on_view_did_appear,
    .on_view_will_disappear = on_view_will_disappear,
    .on_view_did_disappear = on_view_did_disappear,
    .on_view_did_unload = on_view_did_unload,
};

page_vtable_t* template_create(const char *name)
{

    template.page_param = &page_param;
    template.name = name;

    return template.page_param;
}