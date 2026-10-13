/*
 * function: BTL_SERVER_GetActionTableValue
 * address:  0x021BB8A8
 * packet:   pkt_021BB840
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_GetActionTableValue   0x021BB8A8  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0x30; ldrb r0, [r0]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021BB8A8  adds r0,r0,r1; adds r0,#0x30; ldrb r0,[r0] */
u8 BTL_SERVER_GetActionTableValue(u8 *p, u8 i) { return *(u8 *)(p + i + 0x30); }

