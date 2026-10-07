/*
 * function: func_021C0C34
 * address:  0x021C0C34
 * packet:   pkt_021C0C34
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0C34   0x021C0C34  thumb
 *
 * Reads the u8 field at #2 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C0C34  ldrb r0,[r0,#2] */
u32 func_021C0C34(u8 *p) { return p[2]; }

