/*
 * unit: yes
 * function: HAND_ITEM_FlavorHealSpeedIfForcedUse, HAND_ITEM_GetFlavorHealSpAttackHandlers
 * address: 0x021DD68C
 * packet: pkt_ov093_021DD68C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_ITEM_FlavorHeal 0x021DD7B8 thumb ov093
 *   gBtlItemFlavorHealSpAttackHandlers 0x021F1C7C data a4
 */
typedef unsigned char u8;
extern void HAND_ITEM_FlavorHeal(int, u8 *, int, int *, int);
void HAND_ITEM_FlavorHealSpeedIfForcedUse(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) HAND_ITEM_FlavorHeal(a, b, c, d, 2);
}
extern u8 gBtlItemFlavorHealSpAttackHandlers[];
void *HAND_ITEM_GetFlavorHealSpAttackHandlers(int *p) { *p = 5; return gBtlItemFlavorHealSpAttackHandlers; }
