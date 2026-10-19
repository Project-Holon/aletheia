/*
 * function: BTL_POKEPARAM_HasStoredPokeMove
 * address:  0x021D6E74
 * packet:   pkt_021D6D7C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasStoredPokeMove   0x021D6E74  thumb
 * 8 instructions, 16 bytes: ldr r1, pool_021D6E84; ldrb r0, [r0, r1]; cmp r0, #0x1f; beq loc_021D6E80; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
#include "../include/Obj18422.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D6E74  first round: `== 0x1f` gave bne; the image is beq. */
u32 BTL_POKEPARAM_HasStoredPokeMove(u8 *p)
{
    return (((struct Obj18422 *)p)->f1F6 != 0x1f);
}

