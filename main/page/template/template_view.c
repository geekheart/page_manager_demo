#include "template_view.h"
#include <stdlib.h>

template_view_t* template_view_create(lv_obj_t *root)
{
    lv_obj_set_click(root, true);

    template_view_t *template_view = (template_view_t *)malloc(sizeof(template_view_t));

    template_view->ui.label_title = lv_label_create(root, NULL);
    lv_obj_align(template_view->ui.label_title, root,LV_ALIGN_IN_TOP_MID, 0, 20);
    lv_label_set_text(template_view->ui.label_title, "");
    lv_obj_set_auto_realign(template_view->ui.label_title, true);

    template_view->ui.label_count = lv_label_create(root, NULL);
    lv_label_set_text(template_view->ui.label_count, "");
    lv_obj_align(template_view->ui.label_count, root, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_auto_realign(template_view->ui.label_count, true);

    return template_view;
}

void template_view_set_title(template_view_t* self, const char* title)
{
    lv_label_set_text(self->ui.label_title, title);
}

void template_view_set_count(template_view_t* self, const char* count)
{
    lv_label_set_text(self->ui.label_count, count);
}