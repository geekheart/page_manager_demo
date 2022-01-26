#include "demo.h"
#include <stdio.h>
#include <stdlib.h>

static demo_t demo;

static void demo_event_cb(lv_obj_t *obj, lv_event_t event)
{
    page_base_t *page_base = (page_base_t *)obj->user_data;
    page_manager_t *manager = page_base->manager;
    if (event == LV_EVENT_CLICKED)
    {
        pm_push(manager, "temp", NULL);
    }
}

static void onTimerUpdate(lv_task_t *timer)
{
    char tick[20];
    sprintf(tick, "tick:%d", demo_model_get_tick());
    demo_view_set_title(demo.demo_view, tick);
}

static void on_custom_attr_config(page_base_t *self)
{
    page_set_custom_root_event_cb(self, demo_event_cb);
    page_set_custom_auto_cache_enable(self, true);
    page_set_custom_load_anim_type(self, LOAD_ANIM_OVER_BOTTOM, 1000, lv_anim_path_overshoot);
}

/* Page load */
static void on_view_load(page_base_t *self)
{
    demo.demo_view = demo_view_create(self->root);
    demo_view_set_title(demo.demo_view, self->name);
}

/* Page load complete */
static void on_view_did_load(page_base_t *self)
{
}

/* Page will be displayed soon  */
static void on_view_will_appear(page_base_t *self)
{
    demo.param.color = LV_COLOR_WHITE;
    demo.param.time = 1000;
    demo.task = lv_task_create(onTimerUpdate, demo.param.time, LV_TASK_PRIO_HIGH, NULL);
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

page_vtable_t demo_create(const char *name)
{

    demo.page_param = page_param;
    demo.name = name;

    return demo.page_param;
}