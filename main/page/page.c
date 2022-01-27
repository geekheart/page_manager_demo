#include "page.h"
#include "page_manager.h"
#include "demo/demo.h"
#include "template/template.h"
#include "esp_log.h"

#define APP_CLASS_MATCH(NAME)           \
    do                                  \
    {                                   \
        if (strcmp(name, #NAME) == 0)   \
        {                               \
            return NAME##_create(name); \
        }                               \
    } while (0)

static const char* tag = "page"; 
static page_manager_t *s_manager = NULL;

void page_init(void)
{
    s_manager = page_manager_create();
    pm_set_global_load_anim_type(s_manager, LOAD_ANIM_OVER_TOP, 500, lv_anim_path_overshoot);
}

page_vtable_t *_page_create(const char *name)
{
    APP_CLASS_MATCH(demo);
    APP_CLASS_MATCH(template);
    return NULL;
}

void page_install(const char *name)
{
    page_vtable_t* page = _page_create(name);
    if (page != NULL)
    {
        pm_install(s_manager, name, page);
    }
    else
    {
        ESP_LOGI(tag, "page not exist");
    }
}

void page_start(const char *name)
{
    pm_push(s_manager, name, NULL);
}