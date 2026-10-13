/*
 * function: BTL_HANDLER_ITEM_GetMindPlateHandlers
 * address: 0x021DF310
 * packet: pkt_ov093_021DF310
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
 *   d_021F13F4 0x021F13F4 data ov093 a4
 */

extern int d_021F13F4[];
int *BTL_HANDLER_ITEM_GetMindPlateHandlers(int *p);

int *BTL_HANDLER_ITEM_GetMindPlateHandlers(int *p)
{
    *p = 1;
    return d_021F13F4;
}
