/*
 * function: HAND_ITEM_FlavorHealAttack
 * address:  0x021DD614
 * packet:   pkt_021DD614
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_ITEM_FlavorHealAttack   0x021DD614  thumb
 *   HAND_ITEM_FlavorHeal   0x021DD7B8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0; str r4, [sp]; bl HAND_ITEM_FlavorHeal; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD614  stack-arg wrapper: HAND_ITEM_FlavorHeal(a, b, c, d, 0x0) */
void HAND_ITEM_FlavorHealAttack(int a, int b, int c, int d) { HAND_ITEM_FlavorHeal(a, b, c, d, 0x0); }

