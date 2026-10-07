/*
 * function: func_021CA738
 * address:  0x021CA738
 * packet:   pkt_021CA738
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA738   0x021CA738  thumb
 *   func_021CD4B0   0x021CD4B0  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0xc]; movs r1, #0x56; movs r2, #0; bl func_021CD4B0; movs r0, #1; pop {r3, pc}.
 */
#include "../../../matched/include/Obj18348.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CA738  3-arg call on field 0xc, then returns 1 */
int func_021CA738(u8 *p)
{
    func_021CD4B0(((struct Obj18348 *)p)->fC, 0x56, 0);
    return 1;
}

