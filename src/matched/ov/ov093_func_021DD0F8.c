/*
 * unit: yes
 * function: HAND_ITEM_PersimBerryOnEaten, HAND_ITEM_AddPersimBerry
 * address: 0x021DD0F8
 * packet: pkt_ov093_021DD0F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gPersimBerryHandlers 0x021F1B3C data a4
 */
extern void HAND_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gPersimBerryHandlers[];
void HAND_ITEM_PersimBerryOnEaten(void *a, void *b, int c)
{
    HAND_ITEM_CureSickOnEaten(a, b, c, 6);
}
const void *HAND_ITEM_AddPersimBerry(int *p)
{
    *p = 5;
    return gPersimBerryHandlers;
}
