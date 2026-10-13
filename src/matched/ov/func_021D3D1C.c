/*
 * function: func_021D3D1C
 * address:  0x021D3D1C
 * packet:   pkt_021D3D1C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D3D1C   0x021D3D1C  thumb
 *   BTL_FIELD_TickSlots   0x021EFC78  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0x34]; movs r1, #0; movs r2, #0; bl BTL_FIELD_TickSlots; movs r0, #1; pop {r3, pc}.
 */
#include "../include/Obj18395.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D3D1C  3-arg call on field 0x34, then returns 1 */
int func_021D3D1C(u8 *p)
{
    BTL_FIELD_TickSlots(((struct Obj18395 *)p)->f34, 0, 0);
    return 1;
}

