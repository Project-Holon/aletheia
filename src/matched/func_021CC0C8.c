/*
 * function: func_021CC0C8
 * address:  0x021CC0C8
 * packet:   pkt_021CBF30
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC0C8   0x021CC0C8  thumb
 *   func_021CC438   0x021CC438  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CC0C8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x4) */
void func_021CC0C8(int a, int b, int c, int d) { func_021CC438(a, b, c, d, 0x4); }

