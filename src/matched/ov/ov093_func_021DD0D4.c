/*
 * unit: yes
 * function: HAND_ITEM_AspearBerryOnEaten, HAND_ITEM_AddAspearBerry
 * address: 0x021DD0D4
 * packet: pkt_ov093_021DD0D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gAspearBerryHandlers 0x021F1B14 data a4
 */
extern void HAND_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gAspearBerryHandlers[];
void HAND_ITEM_AspearBerryOnEaten(void *a, void *b, int c)
{
    HAND_ITEM_CureSickOnEaten(a, b, c, 3);
}
const void *HAND_ITEM_AddAspearBerry(int *p)
{
    *p = 5;
    return gAspearBerryHandlers;
}
