/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_LumBerryOnEaten, BTL_HANDLER_ITEM_AddLumBerry
 * address: 0x021DD140
 * packet: pkt_ov093_021DD140
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_HANDLER_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gHandlerTableLumBerry 0x021F1B8C data a4
 */
extern void BTL_HANDLER_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gHandlerTableLumBerry[];
void BTL_HANDLER_ITEM_LumBerryOnEaten(void *a, void *b, int c)
{
    BTL_HANDLER_ITEM_CureSickOnEaten(a, b, c, 37);
}
const void *BTL_HANDLER_ITEM_AddLumBerry(int *p)
{
    *p = 5;
    return gHandlerTableLumBerry;
}
