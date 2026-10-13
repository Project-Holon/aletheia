/*
 * function: GIMMICK_OBJ_ELBOARD_AddDailyMessage1
 * address:  0x021F4104
 * packet:   pkt_ov048_021F4104
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02088864  0x02088864  arm
 *   GIMMICK_OBJ_ELBOARD_AddMessage  0x021F3D38  thumb
 *   gElboardLayout     0x021F50C0  data  a4
 */

#include "../include/G_T.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RTCDate;
extern int func_02088864(struct RTCDate *date);
extern void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int unused, int b, int *c);
extern struct T gElboardLayout;

void GIMMICK_OBJ_ELBOARD_AddDailyMessage1(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    func_02088864((struct RTCDate *)buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x3c); break;
    case 1: s.f = *(int *)(p[7] + 0x30); break;
    case 2: s.f = *(int *)(p[7] + 0x24); break;
    case 3: s.f = *(int *)(p[7] + 0x34); break;
    case 4: s.f = *(int *)(p[7] + 0x28); break;
    case 5: s.f = *(int *)(p[7] + 0x38); break;
    case 6: s.f = *(int *)(p[7] + 0x2c); break;
    }
    s.a = *(u16 *)(((u8 *)&gElboardLayout) + 0xa);
    s.b = *(int *)(((u8 *)&gElboardLayout) + 0x38);
    s.c = *(int *)(((u8 *)&gElboardLayout) + 0x54);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(p, (int)&s, 4, 0);
}
