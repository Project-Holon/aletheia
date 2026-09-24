/*
 * function: func_021EA044
 * address:  0x021EA044
 * packet:   pkt_021E8CFC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EA044   0x021EA044  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x4b; lsls r1, r1, #2; ldrb r0, [r0, r1]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021EA044  movs r1,#0x4b; lsls r1,#2; ldrb r0,[r0,r1] */
struct QV { u8 pad[0x12c]; u8 v; };
u8 func_021EA044(struct QV *p) { return p->v; }

