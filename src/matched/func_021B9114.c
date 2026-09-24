/*
 * function: func_021B9114
 * address:  0x021B9114
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9114   0x021B9114  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x23; ldrb r0, [r0]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021B9114  ldr r0,[r0]; adds r0,#0x23; ldrb r0,[r0] */
u8 func_021B9114(u8 **p) { return *(u8 *)(*p + 0x23); }

