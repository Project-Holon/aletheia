/*
 * function: BTL_HANDLER_ITEM_GetLeftoversHandlers
 * address: 0x021DEEF0
 * packet: pkt_ov093_021DEEF0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DEDF8.c and filed here.
 *
 * symbols:
 *   d_021F16EC 0x021F16EC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetLeftoversHandlers(int *p);
extern int d_021F16EC[];

int *BTL_HANDLER_ITEM_GetLeftoversHandlers(int *p)
{
    *p = 2;
    return d_021F16EC;
}
