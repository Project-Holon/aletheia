/*
 * function: func_021CC96C
 * address:  0x021CC96C
 * packet:   pkt_021CC95C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC96C   0x021CC96C  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #1; lsrs r0, r0, #0x1f; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CC96C  ldr r0,[r0]; lsls #1; lsrs #0x1f */
struct Q9 { u32 a : 30; u32 b : 1; u32 c : 1; };
int func_021CC96C(struct Q9 *p) { return p->b; }

