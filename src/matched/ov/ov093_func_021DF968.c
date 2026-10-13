/*
 * function: BTL_HANDLER_ITEM_GetLustrousOrbHandlers
 * address: 0x021DF968
 * packet: pkt_ov093_021DF968
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF8E8.c and filed here.
 *
 * symbols:
 *   gLustrousOrbHandlers 0x021F141C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetLustrousOrbHandlers(int *p);
extern int gLustrousOrbHandlers[];

/*
 * sdk:      sciGetServiceUrl (libdwcgssc.TWL.HYB.a(sciinterface.o))
 */
int *BTL_HANDLER_ITEM_GetLustrousOrbHandlers(int *p)
{
    *p = 1;
    return gLustrousOrbHandlers;
}
