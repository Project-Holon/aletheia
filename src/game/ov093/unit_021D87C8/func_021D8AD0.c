/*
 * function: func_021D8AD0
 * address:  0x021D8AD0
 * packet:   pkt_021D8A8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D8AD0   0x021D8AD0  thumb
 *   func_021D8AEC   0x021D8AEC  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021D8AEC; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D8AD0  stack-arg wrapper: func_021D8AEC(a, b, c, d, 0x3) */
void func_021D8AD0(int a, int b, int c, int d) { func_021D8AEC(a, b, c, d, 0x3); }

