/*
 * function: BTL_HANDLER_ITEM_GetToxicOrbHandlers
 * address: 0x021DF588
 * packet: pkt_ov093_021DF588
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
 *   gToxicOrbHandlers 0x021F168C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetToxicOrbHandlers(int *p);
extern int gToxicOrbHandlers[];

int *BTL_HANDLER_ITEM_GetToxicOrbHandlers(int *p)
{
    *p = 2;
    return gToxicOrbHandlers;
}
