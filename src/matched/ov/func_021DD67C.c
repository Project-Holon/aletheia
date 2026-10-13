/*
 * function: HAND_ITEM_FlavorHealSpeed
 * address:  0x021DD67C
 * packet:   pkt_021DD614
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_ITEM_FlavorHealSpeed   0x021DD67C  thumb
 *   HAND_ITEM_FlavorHeal   0x021DD7B8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl HAND_ITEM_FlavorHeal; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD67C  stack-arg wrapper: HAND_ITEM_FlavorHeal(a, b, c, d, 0x2) */
void HAND_ITEM_FlavorHealSpeed(int a, int b, int c, int d) { HAND_ITEM_FlavorHeal(a, b, c, d, 0x2); }

