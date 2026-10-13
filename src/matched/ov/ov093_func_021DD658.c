/*
 * unit: yes
 * function: BTL_ITEM_FlavorHealDefenseIfForcedUse, BTL_ITEM_GetFlavorHealSpeedHandlers
 * address: 0x021DD658
 * packet: pkt_ov093_021DD658
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ITEM_FlavorHeal 0x021DD7B8 thumb ov093
 *   gBtlItemFlavorHealSpeedHandlers 0x021F1C54 data a4
 */
typedef unsigned char u8;
extern void BTL_ITEM_FlavorHeal(int, u8 *, int, int *, int);
void BTL_ITEM_FlavorHealDefenseIfForcedUse(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) BTL_ITEM_FlavorHeal(a, b, c, d, 1);
}
extern u8 gBtlItemFlavorHealSpeedHandlers[];
void *BTL_ITEM_GetFlavorHealSpeedHandlers(int *p) { *p = 5; return gBtlItemFlavorHealSpeedHandlers; }
