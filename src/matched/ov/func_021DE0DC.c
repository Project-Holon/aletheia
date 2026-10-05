/*
 * function: func_021DE0DC
 * address:  0x021DE0DC
 * packet:   pkt_021DD614
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DE0DC   0x021DE0DC  thumb
 *   func_021DE108   0x021DE108  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl func_021DE108; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DE0DC  stack-arg wrapper: func_021DE108(a, b, c, d, 0x1) */
void func_021DE0DC(int a, int b, int c, int d) { func_021DE108(a, b, c, d, 0x1); }

