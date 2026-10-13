/*
 * function: HAND_ITEM_GetAirBalloonHandlers
 * address: 0x021DFB40
 * packet: pkt_ov093_021DFB40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFABC.c and filed here.
 *
 * symbols:
 *   gBtlHandlerItemAirBalloonHandlers 0x021F1934 data ov093 a4
 */

int *HAND_ITEM_GetAirBalloonHandlers(int *p);
extern int gBtlHandlerItemAirBalloonHandlers[];

int *HAND_ITEM_GetAirBalloonHandlers(int *p)
{
    *p = 3;
    return gBtlHandlerItemAirBalloonHandlers;
}
