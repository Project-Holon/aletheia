/*
 * function: BTL_HANDLER_ITEM_GetFlameOrbHandlers
 * address: 0x021DF634
 * packet: pkt_ov093_021DF634
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
 *   gFlameOrbHandlers 0x021F169C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetFlameOrbHandlers(int *p);
extern int gFlameOrbHandlers[];

int *BTL_HANDLER_ITEM_GetFlameOrbHandlers(int *p)
{
    *p = 2;
    return gFlameOrbHandlers;
}
