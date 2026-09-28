/*
 * function: func_021B9A5C
 * address:  0x021B9A5C
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9A5C   0x021B9A5C  thumb
 *
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: cmp r0, #0; bne loc_021B9A64; movs r0, #1; b loc_021B9A66; movs r0, #0; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021B9A5C  cmp r0,#0; bne; movs r0,#1; else 0; zext8 */
u8 func_021B9A5C(u32 x) { return x == 0; }

