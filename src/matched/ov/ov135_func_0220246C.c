/*
 * function: WORLDTRADE_ADAPTER_StoreDateAsLastId
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
 *   WORLDTRADE_SetLastSearchId  0x0200ADD8  thumb
 *   WORLDTRADE_SetLastTradeId  0x0200ADD0  thumb
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
struct RegB;
extern void WORLDTRADE_SetLastSearchId(struct RegB *p, u32 value);
extern void WORLDTRADE_SetLastTradeId(struct RegB *p, u32 value);

void WORLDTRADE_ADAPTER_StoreDateAsLastId(void *p, int which)
{
    RTCDate date;
    RTCTime time;
    u32 v;

    DWC_GetDateTime(&date, &time);
    v = ((u32)date.year << 24) | (((u32)date.month << 24) >> 8) | (((u32)date.day << 24) >> 16) | date.week;
    if (which == 1) {
        WORLDTRADE_SetLastSearchId(p, v);
    } else {
        WORLDTRADE_SetLastTradeId(p, v);
    }
}
