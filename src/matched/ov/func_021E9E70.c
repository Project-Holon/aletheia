/*
 * function: BTLV_CORE_SkipBagPartyPrompt
 * address:  0x021E9E70
 * packet:   pkt_021E8CE0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_SkipBagPartyPrompt   0x021E9E70  thumb
 *
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: adds r1, r0, #0; movs r2, #1; adds r1, #0xe8; str r2, [r1]; movs r1, #0x4f; lsls r1, r1, #2; str r2, [r0, r1]; bx lr.
 */
#include "../include/Obj12163.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E9E70  str 1 at p+0xe8 and at p+0x13c */
void BTLV_CORE_SkipBagPartyPrompt(u8 *p)
{
    ((struct Obj12163 *)p)->fE8 = 1;
    ((struct Obj12163 *)p)->f13C = 1;
}

