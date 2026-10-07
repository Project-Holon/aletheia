/*
 * function: func_021F4290
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
 *   func_02088864  0x02088864  arm
 *   func_021F3D38  0x021F3D38  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 */

#include "../include/G_T.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RTCDate;
extern int func_02088864(struct RTCDate *date);
extern void func_021F3D38(int *p, int unused, int b, int *c);
extern struct T d_021F50C0;

void func_021F4290(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    func_02088864((struct RTCDate *)buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x60); break;
    case 1: s.f = *(int *)(p[7] + 0x48); break;
    case 2: s.f = *(int *)(p[7] + 0x4c); break;
    case 3: s.f = *(int *)(p[7] + 0x50); break;
    case 4: s.f = *(int *)(p[7] + 0x54); break;
    case 5: s.f = *(int *)(p[7] + 0x58); break;
    case 6: s.f = *(int *)(p[7] + 0x5c); break;
    }
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 0x10);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x44);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x60);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    func_021F3D38(p, (int)&s, 7, 0);
}
