#include "template_model.h"

static uint8_t s_count = 0;

uint8_t template_get_count(void)
{
    return s_count++;
}