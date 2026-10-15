/*
 * function: GIMMICK_OBJ_ELBOARD_AddWeekdayMessage
 * address:  0x021F4290
 * packet:   pkt_ov048_021F4290
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RTC_GetDate  0x02088864  arm
 *   GIMMICK_OBJ_ELBOARD_AddMessage  0x021F3D38  thumb
 *   gElboardLayout     0x021F50C0  data  a4
 */

#include "../include/G_T.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RTCDate;
extern int RTC_GetDate(struct RTCDate *date);
extern void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int unused, int b, int *c);
extern struct T gElboardLayout;

void GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    RTC_GetDate((struct RTCDate *)buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x60); break;
    case 1: s.f = *(int *)(p[7] + 0x48); break;
    case 2: s.f = *(int *)(p[7] + 0x4c); break;
    case 3: s.f = *(int *)(p[7] + 0x50); break;
    case 4: s.f = *(int *)(p[7] + 0x54); break;
    case 5: s.f = *(int *)(p[7] + 0x58); break;
    case 6: s.f = *(int *)(p[7] + 0x5c); break;
    }
    s.a = *(u16 *)(((u8 *)&gElboardLayout) + 0x10);
    s.b = *(int *)(((u8 *)&gElboardLayout) + 0x44);
    s.c = *(int *)(((u8 *)&gElboardLayout) + 0x60);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(p, (int)&s, 7, 0);
}
