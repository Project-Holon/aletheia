/*
 * function: BTL_HANDLER_ITEM_GetNeverMeltIceHandlers
 * address: 0x021DF834
 * packet: pkt_ov093_021DF834
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF7D0.c and filed here.
 *
 * symbols:
 *   gNeverMeltIceHandlers 0x021F15AC data a4
 */

int *BTL_HANDLER_ITEM_GetNeverMeltIceHandlers(int *p);
extern int gNeverMeltIceHandlers[];

int *BTL_HANDLER_ITEM_GetNeverMeltIceHandlers(int *p)
{
    *p = 1;
    return gNeverMeltIceHandlers;
}
