/*
 * function: func_021BAD14
 * address:  0x021BAD14
 * packet:   pkt_ov068_021BAD14
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB000  0x021BB000  thumb
 *   func_021BACF4  0x021BACF4  thumb
 */
#include "../include/Obj09870.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_021BB000(u8 *p, int i, int delta);
extern void func_021BACF4(u8 *p, u32 a, u32 b);

void func_021BAD14(u8 *p, u32 v)
{
    if (((struct Obj09870 *)p)->f4 < 5) {
        func_021BB000(p + 0x44, ((struct Obj09870 *)p)->f4, v);
        func_021BACF4(p, *(s8 *)(p + 0x44 + ((struct Obj09870 *)p)->f4), 0);
    }
}
