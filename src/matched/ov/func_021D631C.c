/*
 * function: func_021D631C
 * address:  0x021D631C
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D631C   0x021D631C  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0xac; ldrb r0, [r0]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D631C  adds r0,r0,r1; adds r0,#0xac; ldrb r0,[r0] */
u8 func_021D631C(u8 *p, int i) { return *(u8 *)(p + i + 0xac); }

