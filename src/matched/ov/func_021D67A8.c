/*
 * function: func_021D67A8
 * address:  0x021D67A8
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D67A8   0x021D67A8  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x53; lsls r1, r1, #2; ldrh r0, [r0, r1]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D67A8  movs r1,#0x53; lsls r1,#2; ldrh r0,[r0,r1] */
struct QL { u8 pad[0x14c]; u16 v; };
u16 func_021D67A8(struct QL *p) { return p->v; }

