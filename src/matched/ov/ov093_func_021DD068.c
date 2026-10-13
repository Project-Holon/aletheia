/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_CheriBerryOnEaten, BTL_HANDLER_ITEM_AddCheriBerry
 * address: 0x021DD068
 * packet: pkt_ov093_021DD068
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_HANDLER_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gHandlerTableCheriBerry 0x021F1AC4 data a4
 */
extern void BTL_HANDLER_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gHandlerTableCheriBerry[];
void BTL_HANDLER_ITEM_CheriBerryOnEaten(void *a, void *b, int c)
{
    BTL_HANDLER_ITEM_CureSickOnEaten(a, b, c, 1);
}
const void *BTL_HANDLER_ITEM_AddCheriBerry(int *p)
{
    *p = 5;
    return gHandlerTableCheriBerry;
}
