/*
 * unit: yes
 * function: HAND_ITEM_AguavBerryFlavorHealIfForcedUse, HAND_ITEM_GetIapapaBerryHandlers
 * address: 0x021DD6C0
 * packet: pkt_ov093_021DD6C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_ITEM_FlavorHeal 0x021DD7B8 thumb ov093
 *   gIapapaBerryHandlers 0x021F1CA4 data a4
 */
typedef unsigned char u8;
extern void HAND_ITEM_FlavorHeal(int, u8 *, int, int *, int);
void HAND_ITEM_AguavBerryFlavorHealIfForcedUse(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) HAND_ITEM_FlavorHeal(a, b, c, d, 3);
}
extern u8 gIapapaBerryHandlers[];
void *HAND_ITEM_GetIapapaBerryHandlers(int *p) { *p = 5; return gIapapaBerryHandlers; }
