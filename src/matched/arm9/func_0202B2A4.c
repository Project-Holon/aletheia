/*
 * function: func_0202B2A4
 * address:  0x0202B2A4
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lowers the object's +4 value by 8, saturating at 0, and refreshes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B2A4.c \
 *       --func func_0202B2A4 --addr 0x0202B2A4 --thumb --cc 1.1p1
 */
#include "../include/Obj03001.h"

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

extern void func_0202B2BC(u8 *p);

void func_0202B2A4(u8 *p)
{
    s32 v = (s32)((struct Obj03001 *)p)->f4;

    if (v > 0) {
        v -= 8;
        if (v < 0) {
            v = 0;
        }
        ((struct Obj03001 *)p)->f4 = (u32)v;
        func_0202B2BC(p);
    }
}
