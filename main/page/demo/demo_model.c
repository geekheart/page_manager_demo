#include "demo_model.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


uint32_t demo_model_get_tick(void)
{
    return lv_tick_get()/1000;
}