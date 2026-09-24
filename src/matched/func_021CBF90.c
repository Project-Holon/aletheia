/*
 * function: func_021CBF90
 * address:  0x021CBF90
 * packet:   pkt_021CBF30
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CBF90   0x021CBF90  thumb
 *   func_021CC398   0x021CC398  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021CC398; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CBF90  stack-arg wrapper: func_021CC398(a, b, c, d, 0x7) */
void func_021CBF90(int a, int b, int c, int d) { func_021CC398(a, b, c, d, 0x7); }

