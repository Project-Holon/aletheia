/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_RawstBerryOnEaten, BTL_HANDLER_ITEM_AddRawstBerry
 * address: 0x021DD0B0
 * packet: pkt_ov093_021DD0B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_HANDLER_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gHandlerTableRawstBerry 0x021F1DE4 data a4
 */
extern void BTL_HANDLER_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gHandlerTableRawstBerry[];
void BTL_HANDLER_ITEM_RawstBerryOnEaten(void *a, void *b, int c)
{
    BTL_HANDLER_ITEM_CureSickOnEaten(a, b, c, 4);
}
const void *BTL_HANDLER_ITEM_AddRawstBerry(int *p)
{
    *p = 5;
    return gHandlerTableRawstBerry;
}
