/*
 * function: func_021C8828
 * address:  0x021C8828
 * packet:   pkt_021C7EC4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8828   0x021C8828  thumb
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrh r0, [r0, #2]; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; beq loc_021C8834; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
#include "../include/Obj18339.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C8828  u8 of the low halfword, != 0 */
u32 func_021C8828(u8 *p)
{
    return ((u8)((struct Obj18339 *)p)->f2 != 0);
}

