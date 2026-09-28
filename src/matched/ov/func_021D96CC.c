/*
 * function: func_021D96CC
 * address:  0x021D96CC
 * packet:   pkt_021D8A8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D96CC   0x021D96CC  thumb
 *   func_021D9670   0x021D9670  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0xd2; str r4, [sp]; bl func_021D9670; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D96CC  stack-arg wrapper: func_021D9670(a, b, c, d, 0xd2) */
void func_021D96CC(int a, int b, int c, int d) { func_021D9670(a, b, c, d, 0xd2); }

