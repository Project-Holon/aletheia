/*
 * function: HAND_ITEM_GetIronBallHandlers
 * address: 0x021DFA14
 * packet: pkt_ov093_021DFA14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF9C8.c and filed here.
 *
 * symbols:
 *   gBtlHandlerItemIronBallHandlers 0x021F166C data ov093 a4
 */

int *HAND_ITEM_GetIronBallHandlers(int *p);
extern int gBtlHandlerItemIronBallHandlers[];

int *HAND_ITEM_GetIronBallHandlers(int *p)
{
    *p = 2;
    return gBtlHandlerItemIronBallHandlers;
}
