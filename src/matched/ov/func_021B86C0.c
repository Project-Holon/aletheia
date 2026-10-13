/*
 * function: BTL_MAIN_GetCommPos
 * address:  0x021B86C0
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetCommPos   0x021B86C0  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x20; ldrb r0, [r0]; bx lr.
 */
#include "../include/Obj18127.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021B86C0  ldr r0,[r0]; adds r0,#0x20; ldrb r0,[r0] */
u8 BTL_MAIN_GetCommPos(u8 **p) { return ((struct Obj18127 *)(*p))->f20; }

