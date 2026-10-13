/*
 * function: BTL_HANDLER_ITEM_GetHardStoneHandlers
 * address: 0x021DF71C
 * packet: pkt_ov093_021DF71C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF48C.c and filed here.
 *
 * symbols:
 *   gHardStoneHandlers 0x021F13AC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetHardStoneHandlers(int *p);
extern int gHardStoneHandlers[];

int *BTL_HANDLER_ITEM_GetHardStoneHandlers(int *p)
{
    *p = 1;
    return gHardStoneHandlers;
}
