/*
 * function: HAND_ITEM_FlyingGemMoveUsed
 * address:  0x021E0064
 * packet:   pkt_021DFEF4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_FlyingGemMoveUsed   0x021E0064  thumb
 *   HAND_ITEM_GemMoveUsed   0x021E01D4  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl HAND_ITEM_GemMoveUsed; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E0064  stack-arg wrapper: HAND_ITEM_GemMoveUsed(a, b, c, d, 0x2) */
void HAND_ITEM_FlyingGemMoveUsed(int a, int b, int c, int d) { HAND_ITEM_GemMoveUsed(a, b, c, d, 0x2); }

