#ifndef _CLOG_H_
#define _CLOG_H

#include <stdio.h>
#include <time.h>

extern int g_log_level;

typedef enum
{
    LOG_DETAIL = 0,
    LOG_INFO = 1,
    LOG_WARNING = 2,
    LOG_ERROR = 3,
    LOG_FATAL = 4,
}LOG_LEVEL;

// struct tm 
// {
//     int tm_sec;       /* 秒 – 取值区间为[0,59] */
//     int tm_min;       /* 分 - 取值区间为[0,59] */
//     int tm_hour;      /* 时 - 取值区间为[0,23] */
//     int tm_mday;      /* 一个月中的日期 - 取值区间为[1,31] */
//     int tm_mon;       /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
//     int tm_year;      /* 年份，其值等于实际年份减去1900 */
//     int tm_wday;      /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
//     int tm_yday;      /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
//     int tm_isdst;     /* 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
// };

void set_log_level(int level);

#define LOGD(fmt, ...) \
{\
    if (g_log_level == LOG_DETAIL) \
    { \
        time_t t = time(NULL); \
        struct tm* local = localtime(&t); \
        printf("%d-%d-%d %d:%d:%d DETAIL %s(%d): " fmt "\n", \
            local->tm_year + 1900, \
            local->tm_mon, \
            local->tm_mday, \
            local->tm_hour, \
            local->tm_min, \
            local->tm_sec, \
            __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
}

#define LOGI(fmt, ...) \
{\
    if (g_log_level == LOG_DETAIL || g_log_level == LOG_INFO) \
    { \
        time_t t = time(NULL); \
        struct tm* local = localtime(&t); \
        printf("%d-%d-%d %d:%d:%d INFO %s(%d): " fmt "\n", \
            local->tm_year + 1900, \
            local->tm_mon, \
            local->tm_mday, \
            local->tm_hour, \
            local->tm_min, \
            local->tm_sec, \
            __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
}

#define LOGW(fmt, ...) \
{\
    if (g_log_level == LOG_DETAIL || g_log_level == LOG_INFO || g_log_level == LOG_WARNING) \
    { \
        time_t t = time(NULL); \
        struct tm* local = localtime(&t); \
        printf("%d-%d-%d %d:%d:%d WARNING %s(%d): " fmt "\n", \
            local->tm_year + 1900, \
            local->tm_mon, \
            local->tm_mday, \
            local->tm_hour, \
            local->tm_min, \
            local->tm_sec, \
            __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
}

#define LOGE(fmt, ...) \
{\
    if (g_log_level == LOG_DETAIL || g_log_level == LOG_INFO || \
        g_log_level == LOG_WARNING || g_log_level == LOG_ERROR) \
    { \
        time_t t = time(NULL); \
        struct tm* local = localtime(&t); \
        printf("%d-%d-%d %d:%d:%d ERROR %s(%d): " fmt "\n", \
            local->tm_year + 1900, \
            local->tm_mon, \
            local->tm_mday, \
            local->tm_hour, \
            local->tm_min, \
            local->tm_sec, \
            __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
}

#define LOGF(fmt, ...) \
{\
    if (g_log_level >= 0) \
    { \
        time_t t = time(NULL); \
        struct tm* local = localtime(&t); \
        printf("%d-%d-%d %d:%d:%d FATAL %s(%d): " fmt "\n", \
            local->tm_year + 1900, \
            local->tm_mon, \
            local->tm_mday, \
            local->tm_hour, \
            local->tm_min, \
            local->tm_sec, \
            __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
}

#endif