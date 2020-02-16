#include "clog.h"

int main(int argc, char *argv[])
{
    set_log_level(LOG_WARNING);
    if (argc < 2)
    {
        LOGE("Invalid arguments!");
        return 0;
    }

    char *str = argv[1];
    LOGD("%s", str);
    LOGE("%s", str);
    LOGW("%s", str);
    return 0;
}