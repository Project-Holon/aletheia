/*
 * function: func_021B6470
 * address:  0x021B6470
 * packet:   pkt_021B6470
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B69B8  0x021B69B8  thumb
 */
#include "../include/Obj09860.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_021B69B8(void *e);

int func_021B6470(u8 *p)
{
    if (((struct Obj09860 *)p)->f8 == 1 && ((struct Obj09860 *)p)->f0 != 0xffffffff) {
        return func_021B69B8(p + 0x20 + ((struct Obj09860 *)p)->f0 * 0x38);
    }
    return -1;
}
