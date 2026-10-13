/*
 * function: BTL_ITEM_FlavorHealDefense
 * address:  0x021DD648
 * packet:   pkt_021DD614
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ITEM_FlavorHealDefense   0x021DD648  thumb
 *   BTL_ITEM_FlavorHeal   0x021DD7B8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl BTL_ITEM_FlavorHeal; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD648  stack-arg wrapper: BTL_ITEM_FlavorHeal(a, b, c, d, 0x1) */
void BTL_ITEM_FlavorHealDefense(int a, int b, int c, int d) { BTL_ITEM_FlavorHeal(a, b, c, d, 0x1); }

