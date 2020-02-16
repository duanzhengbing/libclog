#include "clog.h"

int g_log_level = 0;

void set_log_level(int level)
{
    g_log_level = level;
}