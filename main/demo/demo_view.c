#include "demo_view.h"
#include <stdlib.h>

demo_view_t *demo_view_create(lv_obj_t *root)
{
    lv_obj_set_click(root, true);

    demo_view_t *demo_view = (demo_view_t *)malloc(sizeof(demo_view_t));

    demo_view->ui.label_title = lv_label_create(root, NULL);
    lv_obj_align(demo_view->ui.label_title, root,LV_ALIGN_IN_TOP_MID, 0, 20);
    lv_label_set_text(demo_view->ui.label_title, "");

    demo_view->ui.label_tick = lv_label_create(root, NULL);
    lv_label_set_text(demo_view->ui.label_tick, "");
    lv_obj_align(demo_view->ui.label_tick, root, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_auto_realign(demo_view->ui.label_tick, true);

    return demo_view;
}

void demo_view_set_title(demo_view_t* self, const char* title)
{
    lv_label_set_text(self->ui.label_tick, title);
}

void demo_view_set_tick(demo_view_t* self, const char* tick)
{
    lv_label_set_text(self->ui.label_tick, tick);
}
