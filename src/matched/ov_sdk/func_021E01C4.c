/*
 * function: func_021E01C4
 * address:  0x021E01C4
 * packet:   pkt_021DFEF4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E01C4   0x021E01C4  thumb
 *   func_021E0284   0x021E0284  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0; str r4, [sp]; bl func_021E0284; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E01C4  stack-arg wrapper: func_021E0284(a, b, c, d, 0x0) */
void func_021E01C4(int a, int b, int c, int d) { func_021E0284(a, b, c, d, 0x0); }

