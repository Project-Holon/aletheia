/*
 * function: BTL_POKEPARAM_GetLastTargetPos
 * address:  0x021D67B0
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetLastTargetPos   0x021D67B0  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x51; lsls r1, r1, #2; ldrb r0, [r0, r1]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D67B0  movs r1,#0x51; lsls r1,#2; ldrb r0,[r0,r1] */
struct QM { u8 pad[0x144]; u8 v; };
u8 BTL_POKEPARAM_GetLastTargetPos(struct QM *p) { return p->v; }

