/*
 * unit: yes
 * function: BTL_ITEM_FlavorHealAttackIfForcedUse, BTL_ITEM_GetFlavorHealDefenseHandlers
 * address: 0x021DD624
 * packet: pkt_ov093_021DD624
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ITEM_FlavorHeal 0x021DD7B8 thumb ov093
 *   gBtlItemFlavorHealDefenseHandlers 0x021F1C2C data a4
 */
typedef unsigned char u8;
extern void BTL_ITEM_FlavorHeal(int, u8 *, int, int *, int);
void BTL_ITEM_FlavorHealAttackIfForcedUse(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) BTL_ITEM_FlavorHeal(a, b, c, d, 0);
}
extern u8 gBtlItemFlavorHealDefenseHandlers[];
void *BTL_ITEM_GetFlavorHealDefenseHandlers(int *p) { *p = 5; return gBtlItemFlavorHealDefenseHandlers; }
