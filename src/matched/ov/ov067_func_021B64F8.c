/*
 * function: func_021B64F8
 * address:  0x021B64F8
 * packet:   pkt_021B64F8
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6A1C  0x021B6A1C  thumb
 */
#include "../include/Obj20603.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_021B6A1C(void *e, u32 v);

void func_021B64F8(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20603 *)p)->f4; i++) {
        func_021B6A1C(p + 0x20 + i * 0x38, v);
    }
}
