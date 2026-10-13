/*
 * function: BTL_HANDLER_ITEM_GetStonePlateHandlers
 * address: 0x021DF328
 * packet: pkt_ov093_021DF328
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DEFC4.c and filed here.
 *
 * symbols:
 *   d_021F1574 0x021F1574 data ov093 a4
 */

extern int d_021F1574[];
int *BTL_HANDLER_ITEM_GetStonePlateHandlers(int *p);

int *BTL_HANDLER_ITEM_GetStonePlateHandlers(int *p)
{
    *p = 1;
    return d_021F1574;
}
