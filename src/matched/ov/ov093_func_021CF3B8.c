/*
 * function: func_021CF3B8
 * address: 0x021CF3B8
 * packet: pkt_ov093_021CF3B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: func_021B90BC consumes the live r2 halfword as its third argument;
 * its matched body forwards it to func_02007E50.
 * symbols:
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B90BC 0x021B90BC thumb ov093
 */
#include "../include/Obj05200.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
extern u8 func_021B8FF4(u8 *p);
extern void func_021B90BC(u8 *p, u8 k, u32 v);
void func_021CF3B8(u8 *p, u32 i)
{
    if (p[0x1aa] == 0) {
        if (p[0x1a6] == func_021B8FF4(*(u8 * *)&((struct Obj05200 *)p)->f0)) {
            u16 *a = (u16 *)(p + 0x1a0);
            u32 v = a[i];
            if (v != 0) {
                a[i] = 0;
                func_021B90BC(*(u8 * *)&((struct Obj05200 *)p)->f0, p[0x1a6], v);
            }
        }
    }
}
