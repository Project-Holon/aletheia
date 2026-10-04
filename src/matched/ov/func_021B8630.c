/*
 * function: func_021B8630
 * address:  0x021B8630
 * packet:   pkt_021B8630
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8630   0x021B8630  thumb
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldr r1, [r0]; ldr r0, [r1]; cmp r0, #1; bhi loc_021B863C; ldr r0, [r1, #0x70]; bx lr; movs r0, #0; bx lr.
 */
#include "../include/Obj12104.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021B8630  first round: `if (*q > 1) return 0;` came back bls.  The image
 * takes the guard, so the guarded read is the fall-through arm. */
u32 func_021B8630(u32 **p)
{
    u32 *q = *p;
    if (*q <= 1)
        return ((struct Obj12104 *)q)->f70;
    return 0;
}

