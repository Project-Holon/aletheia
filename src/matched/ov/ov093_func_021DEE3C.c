/*
 * function: HAND_ITEM_GetPowerHerbHandlers
 * address: 0x021DEE3C
 * packet: pkt_ov093_021DEE3C
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
 *   gPowerHerbHandlers 0x021F197C data ov093 a4
 */

int *HAND_ITEM_GetPowerHerbHandlers(int *p);
extern int gPowerHerbHandlers[];

/*
 * sdk:      DWC_ScInitialize (libdwcsc.TWL.HYB.a dwc_sc.o)
 */
int *HAND_ITEM_GetPowerHerbHandlers(int *p)
{
    *p = 3;
    return gPowerHerbHandlers;
}
