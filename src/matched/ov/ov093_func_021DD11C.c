/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_PechaBerryOnEaten, BTL_HANDLER_ITEM_AddPechaBerry
 * address: 0x021DD11C
 * packet: pkt_ov093_021DD11C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_HANDLER_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gHandlerTablePechaBerry 0x021F1B64 data a4
 */
extern void BTL_HANDLER_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gHandlerTablePechaBerry[];
void BTL_HANDLER_ITEM_PechaBerryOnEaten(void *a, void *b, int c)
{
    BTL_HANDLER_ITEM_CureSickOnEaten(a, b, c, 5);
}
const void *BTL_HANDLER_ITEM_AddPechaBerry(int *p)
{
    *p = 5;
    return gHandlerTablePechaBerry;
}
