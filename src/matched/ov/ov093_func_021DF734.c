/*
 * function: HAND_ITEM_GetMiracleSeedHandlers
 * address: 0x021DF734
 * packet: pkt_ov093_021DF734
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
 *   gMiracleSeedHandlers 0x021F137C data ov093 a4
 */

int *HAND_ITEM_GetMiracleSeedHandlers(int *p);
extern int gMiracleSeedHandlers[];

/*
 * sdk:      DWCi_ScSetUseSSL (libdwcsc.TWL.HYB.a(dwc_sc.o))
 */
int *HAND_ITEM_GetMiracleSeedHandlers(int *p)
{
    *p = 1;
    return gMiracleSeedHandlers;
}
