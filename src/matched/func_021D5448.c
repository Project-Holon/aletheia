/*
 * function: func_021D5448
 * address:  0x021D5448
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5448   0x021D5448  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #5; lsls r1, r1, #6; ldrb r0, [r0, r1]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D5448  movs r1,#5; lsls r1,#6; ldrb r0,[r0,r1] */
struct QG { u8 pad[0x140]; u8 v; };
u8 func_021D5448(struct QG *p) { return p->v; }

