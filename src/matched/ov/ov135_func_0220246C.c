/*
 * function: func_0220246C
 * address:  0x0220246C
 * packet:   pkt_0220246C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DWC_GetDateTime  0x02167ED8  arm  ov009
 *   func_0200ADD8  0x0200ADD8  thumb
 *   func_0200ADD0  0x0200ADD0  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int year;
    int month;
    int day;
    int week;
} RTCDate;

typedef struct {
    int hour;
    int minute;
    int second;
} RTCTime;

extern int DWC_GetDateTime(RTCDate *date, RTCTime *time);
extern void func_0200ADD8(void *p, u32 value);
extern void func_0200ADD0(void *p, u32 value);

void func_0220246C(void *p, int which)
{
    RTCDate date;
    RTCTime time;
    u32 v;

    DWC_GetDateTime(&date, &time);
    v = ((u32)date.year << 24) | (((u32)date.month << 24) >> 8) | (((u32)date.day << 24) >> 16) | date.week;
    if (which == 1) {
        func_0200ADD8(p, v);
    } else {
        func_0200ADD0(p, v);
    }
}
