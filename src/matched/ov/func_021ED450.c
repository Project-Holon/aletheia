/*
 * function: func_021ED450
 * address:  0x021ED450
 * packet:   pkt_021ED450
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED450   0x021ED450  thumb
 *
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: adds r0, #0x41; ldrb r0, [r0]; cmp r0, #0; bne loc_021ED45C; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
#include "../include/Obj18521.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021ED450  adds r0,#0x41; ldrb; cmp #0; bne ->0 else 1 */
int func_021ED450(u8 *p) { return ((struct Obj18521 *)p)->f41 == 0; }

