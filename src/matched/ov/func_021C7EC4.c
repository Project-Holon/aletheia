/*
 * function: func_021C7EC4
 * address:  0x021C7EC4
 * packet:   pkt_021C7EC4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7EC4   0x021C7EC4  thumb
 * 8 instructions, 16 bytes: ldr r1, pool_021C7ED4; ldr r0, [r0, r1]; cmp r0, #0; beq loc_021C7ED0; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
#include "../include/Obj18325.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C7EC4  nonzero test of the pooled offset 0x774 */
u32 func_021C7EC4(u8 *p)
{
    return (((struct Obj18325 *)p)->f774 != 0);
}

