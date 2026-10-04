/*
 * function: func_021B65C8
 * address:  0x021B65C8
 * packet:   pkt_021B65C8
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
#include "../include/Obj20605.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_021B69B8(void *p);

void *func_021B65C8(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20605 *)p)->f4; i++) {
        if (func_021B69B8(p + 0x20 + i * 0x38) == v) {
            return (u8 *)(p + 0x20) + i * 0x38;
        }
    }
    return 0;
}
