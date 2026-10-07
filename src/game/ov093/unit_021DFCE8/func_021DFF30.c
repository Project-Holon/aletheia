/*
 * function: func_021DFF30
 * address:  0x021DFF30
 * packet:   pkt_021DFEF4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DFF30   0x021DFF30  thumb
 *   func_021E01D4   0x021E01D4  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0xa; str r4, [sp]; bl func_021E01D4; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DFF30  stack-arg wrapper: func_021E01D4(a, b, c, d, 0xa) */
void func_021DFF30(int a, int b, int c, int d) { func_021E01D4(a, b, c, d, 0xa); }

