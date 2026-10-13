/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_AspearBerryOnEaten, BTL_HANDLER_ITEM_AddAspearBerry
 * address: 0x021DD0D4
 * packet: pkt_ov093_021DD0D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_HANDLER_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gHandlerTableAspearBerry 0x021F1B14 data a4
 */
extern void BTL_HANDLER_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gHandlerTableAspearBerry[];
void BTL_HANDLER_ITEM_AspearBerryOnEaten(void *a, void *b, int c)
{
    BTL_HANDLER_ITEM_CureSickOnEaten(a, b, c, 3);
}
const void *BTL_HANDLER_ITEM_AddAspearBerry(int *p)
{
    *p = 5;
    return gHandlerTableAspearBerry;
}
