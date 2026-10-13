/*
 * function: func_021BB37C
 * address: 0x021BB37C
 * packet: pkt_ov217_021BB37C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 *   func_021BBA00 0x021BBA00 thumb ov217
 *   func_021BC5A8 0x021BC5A8 thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BB934 0x021BB934 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   func_021BB9A0 0x021BB9A0 thumb ov217
 *   func_021BB9D0 0x021BB9D0 thumb ov217
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj02928.h"
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void func_020061E4(u32 a);
extern void func_021BB91C(void *p);
extern void func_021BB910(unsigned char *a0, u32 a1);
extern u32 func_021BBA00(u32 a0, u32 a1);
typedef unsigned char  u8;
extern void func_021BC5A8(u8 *a0, int a1);
extern void func_021BC580(char *p, int i);
extern void func_021BB934(u8 *a0, u32 a1);
extern u32 func_021BC6D0(void *p);
extern u32 func_021BB9A0(u32 a0);
extern u32 func_021BB9D0(u32 a0);

void func_021BB37C(char *p)
{
    u32 keys = func_020362DC();
    int st = TOUCHPANEL_HitTrg(p + 0x58);
    if (keys & 0x40) {
        func_021BB9A0((u32)p);
    }
    if (keys & 0x80) {
        func_021BB9D0((u32)p);
    }
    if (keys & 1) {
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        switch (*(int *)&((struct Obj02928 *)p)->f2C) {
        case 0:
            func_021BB934((u8 *)p, 0);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 12);
            break;
        case 1:
            func_020061E4(0x551);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 11);
            func_021BB910((unsigned char *)p, 2);
            break;
        }
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_020061E4(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}
