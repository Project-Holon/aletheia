/*
 * function: func_02202840
 * address:  0x02202840
 * packet:   pkt_02202840
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Non-zero unless the +0x10 handle is absent or the query answers 2.
 */
#include "../include/Obj18615.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_0201CE30(void *p);

u32 func_02202840(u8 *p)
{
    u32 r;
    u32 x;

    r = 0;
    x = ((struct Obj18615 *)p)->f10;
    if (x != 0 && func_0201CE30((void *)x) != 2) {
        r = 1;
    }
    return r;
}
