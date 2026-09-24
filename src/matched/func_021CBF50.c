/*
 * function: func_021CBF50
 * address:  0x021CBF50
 * packet:   pkt_021CBF30
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CBF50   0x021CBF50  thumb
 *   func_021CC350   0x021CC350  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CBF50  stack-arg wrapper: func_021CC350(a, b, c, d, 0x4) */
void func_021CBF50(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x4); }

