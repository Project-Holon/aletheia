/*
 * function: BTL_ABILITY_GetPranksterHandlers
 * address: 0x021DCACC
 * packet: pkt_ov093_021DCACC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCA98.c and filed here.
 *
 * symbols:
 *   gPranksterHandlers 0x021F0630 data ov093 a4
 */

extern int gPranksterHandlers[];
int *BTL_ABILITY_GetPranksterHandlers(int *p);

int *BTL_ABILITY_GetPranksterHandlers(int *p)
{
    *p = 1;
    return gPranksterHandlers;
}
