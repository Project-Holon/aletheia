/*
 * unit: yes
 * function: HAND_ITEM_FigyBerryFlavorHealIfForcedUse, HAND_ITEM_GetWikiBerryHandlers
 * address: 0x021DD624
 * packet: pkt_ov093_021DD624
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_ITEM_FlavorHeal 0x021DD7B8 thumb ov093
 *   gWikiBerryHandlers 0x021F1C2C data a4
 */
typedef unsigned char u8;
extern void HAND_ITEM_FlavorHeal(int, u8 *, int, int *, int);
void HAND_ITEM_FigyBerryFlavorHealIfForcedUse(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) HAND_ITEM_FlavorHeal(a, b, c, d, 0);
}
extern u8 gWikiBerryHandlers[];
void *HAND_ITEM_GetWikiBerryHandlers(int *p) { *p = 5; return gWikiBerryHandlers; }
