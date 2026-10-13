/*
 * file:     dwc_nastime.c
 * function: DWC_Auth_SetNasTimeDiff
 * address:  0x02168250
 * packet:   pkt_ov009_02168250
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_SetNasTimeDiff (libdwcnas.TWL.HYB.a(dwc_nastime.o))
 *
 * symbols:
 *   strlen                           0x0209477c arm
 *   RTC_GetDateTime                  0x020889c0 arm
 *   RTC_ConvertDateTimeToSecond      0x02089004 arm
 *   strcpy                           0x02094798 arm
 *   atoi                             0x020964e0 arm
 *   strcmp                           0x020948e0 arm
 *   g_021A1FD8                       0x021a1fd8 data
 *   errno                            0x02153fac data
 *   monthname                        0x021a1fa8 data
 *   DWCnastimediffvalid              0x021aa834 data
 */

typedef struct RTCTime_ {
    unsigned long hour;
    unsigned long minute;
    unsigned long second;
} RTCTime;

typedef struct RTCDate_ {
    unsigned long year;
    unsigned long month;
    unsigned long day;
    int week;
} RTCDate;

typedef struct NasTimeDiff_ {
    int valid;
    long long base;
    long long diff;
} NasTimeDiff;

extern void *strlen(const char *);
extern int RTC_GetDateTime(RTCDate *date, RTCTime *time);
extern long long RTC_ConvertDateTimeToSecond(RTCDate *date, RTCTime *time);
extern void strcpy(char *dst, const char *src);
extern int atoi(const char *s);
extern int strcmp(const char *a, const char *b);

extern char g_021A1FD8[];
extern int errno;
extern char *monthname[12];
extern NasTimeDiff DWCnastimediffvalid;

#define ERANGE 34

int DWC_Auth_SetNasTimeDiff(char *datestr)
{
    int i;
    RTCDate rtcdate;
    RTCTime rtctime;
    long long localsec;
    long long serversec;
    char datestr2[30];

    if (strlen(datestr) != strlen(g_021A1FD8) ||
        datestr[7] != 0x20 || datestr[11] != 0x20 || datestr[16] != 0x20 ||
        datestr[19] != 0x3a || datestr[22] != 0x3a || datestr[25] != 0x20)
        goto fail;

    if (RTC_GetDateTime(&rtcdate, &rtctime) != 0)
        goto fail;

    serversec = RTC_ConvertDateTimeToSecond(&rtcdate, &rtctime);
    if (serversec == -1)
        goto fail;

    strcpy(datestr2, datestr);

    errno = 0;
    datestr2[7] = 0;
    datestr2[11] = 0;
    datestr2[16] = 0;
    datestr2[19] = 0;
    datestr2[22] = 0;
    datestr2[25] = 0;

    rtcdate.year = atoi(&datestr2[12]);
    if (errno == ERANGE)
        goto fail;
    rtcdate.year = rtcdate.year - 2000;

    rtcdate.month = 13;
    for (i = 0; i < 12; i++) {
        if (strcmp(monthname[i], &datestr2[8]) == 0) {
            rtcdate.month = i + 1;
            break;
        }
    }
    if (rtcdate.month > 12)
        goto fail;

    errno = 0;
    rtcdate.day = atoi(&datestr2[5]);
    if (errno == ERANGE)
        goto fail;
    errno = 0;
    rtctime.hour = atoi(&datestr2[17]);
    if (errno == ERANGE)
        goto fail;
    errno = 0;
    rtctime.minute = atoi(&datestr2[20]);
    if (errno == ERANGE)
        goto fail;
    errno = 0;
    rtctime.second = atoi(&datestr2[23]);
    if (errno == ERANGE)
        goto fail;

    localsec = RTC_ConvertDateTimeToSecond(&rtcdate, &rtctime);
    if (localsec == -1)
        goto fail;

    DWCnastimediffvalid.diff = serversec - localsec;
    DWCnastimediffvalid.base = serversec;
    DWCnastimediffvalid.valid = 1;

    return 1;

fail:
    return 0;
}
