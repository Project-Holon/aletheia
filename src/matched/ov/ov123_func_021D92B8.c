/*
 * function: func_021D92B8
 * address:  0x021D92B8
 * packet:   pkt_021D92B8
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02051C6C  0x02051C6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10453.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02051C6C(void *);

void func_021D92B8(u8 *p)
{
    if (((struct Obj10453 *)p)->f1C) {
        func_02051C6C(((struct Obj10453 *)p)->f1C);
        *(u32 *)&((struct Obj10453 *)p)->f1C = 0;
    }
}
