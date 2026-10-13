/*
 * function: HAND_ITEM_DragonGemMovePower
 * address:  0x021E0130
 * packet:   pkt_021DFEF4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_ITEM_DragonGemMovePower   0x021E0130  thumb
 *   HAND_ITEM_GemMovePower   0x021E0284  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0xf; str r4, [sp]; bl HAND_ITEM_GemMovePower; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E0130  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0xf) */
void HAND_ITEM_DragonGemMovePower(int a, int b, int c, int d) { HAND_ITEM_GemMovePower(a, b, c, d, 0xf); }

