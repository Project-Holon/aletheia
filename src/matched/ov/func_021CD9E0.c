/*
 * function: BTL_CLIENT_IsMainStepActive
 * address:  0x021CD9E0
 * packet:   pkt_021CD9C8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive   0x021CD9E0  thumb
 * 8 instructions, 16 bytes: ldr r1, [r0, #0x28]; ldr r0, pool_021CD9F0; cmp r1, r0; bne loc_021CD9EC; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
#include "../include/Obj18367.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CD9E0  function-pointer slot 0x28 compared with 0x021CDC0D */
u32 BTL_CLIENT_IsMainStepActive(u8 *p)
{
    return (((struct Obj18367 *)p)->f28 == 0x021CDC0D);
}

