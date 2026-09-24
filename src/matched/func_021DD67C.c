/*
 * function: func_021DD67C
 * address:  0x021DD67C
 * packet:   pkt_021DD614
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD67C   0x021DD67C  thumb
 *   func_021DD7B8   0x021DD7B8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021DD7B8; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD67C  stack-arg wrapper: func_021DD7B8(a, b, c, d, 0x2) */
void func_021DD67C(int a, int b, int c, int d) { func_021DD7B8(a, b, c, d, 0x2); }

