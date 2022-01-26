#include "template_view.h"
#include <stdlib.h>

template_view_t* template_view_create(lv_obj_t *root)
{
    lv_obj_set_click(root, true);

    template_view_t *template_view = (template_view_t *)malloc(sizeof(template_view_t));

    lv_obj_t* label = lv_label_create(root, NULL);
    lv_obj_align(label, root,LV_ALIGN_IN_TOP_MID, 0, 20);
    lv_label_set_text(label, "");
    template_view->ui.labelTitle = label;

    label = lv_label_create(root, NULL);
    lv_label_set_text(label, "");
    lv_obj_align(label, root, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_auto_realign(label, true);
    template_view->ui.labelTick = label;

    return template_view;
}