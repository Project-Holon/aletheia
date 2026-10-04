/*
 * function: func_021D698C
 * address:  0x021D698C
 * packet:   pkt_021D698C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B639C  0x021B639C  thumb  ov067
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10392.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021B639C(u8 *p);

void func_021D698C(u8 *p)
{
    if (((struct Obj10392 *)p)->fC) {
        func_021B639C(((struct Obj10392 *)p)->fC);
        *(u32 *)&((struct Obj10392 *)p)->fC = 0;
    }
}
