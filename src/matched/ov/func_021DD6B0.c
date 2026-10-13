/*
 * function: HAND_ITEM_FlavorHealSpAttack
 * address:  0x021DD6B0
 * packet:   pkt_021DD614
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_ITEM_FlavorHealSpAttack   0x021DD6B0  thumb
 *   HAND_ITEM_FlavorHeal   0x021DD7B8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl HAND_ITEM_FlavorHeal; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD6B0  stack-arg wrapper: HAND_ITEM_FlavorHeal(a, b, c, d, 0x3) */
void HAND_ITEM_FlavorHealSpAttack(int a, int b, int c, int d) { HAND_ITEM_FlavorHeal(a, b, c, d, 0x3); }

