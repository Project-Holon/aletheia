/*
 * function: HAND_ITEM_NormalGemMovePower
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
 *   HAND_ITEM_NormalGemMovePower   0x021E01C4  thumb
 *   HAND_ITEM_GemMovePower   0x021E0284  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0; str r4, [sp]; bl HAND_ITEM_GemMovePower; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E01C4  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0x0) */
void HAND_ITEM_NormalGemMovePower(int a, int b, int c, int d) { HAND_ITEM_GemMovePower(a, b, c, d, 0x0); }

