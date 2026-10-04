/*
 * function: func_021B64D0
 * address:  0x021B64D0
 * packet:   pkt_021B64D0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B69BC  0x021B69BC  thumb
 */
#include "../include/Obj20602.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_021B69BC(void *e, u32 v);

void func_021B64D0(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20602 *)p)->f4; i++) {
        func_021B69BC(p + 0x20 + i * 0x38, v);
    }
}
