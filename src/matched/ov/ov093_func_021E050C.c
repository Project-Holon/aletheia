/*
 * function: HAND_WAZA_GetCamouflageHandlers
 * address: 0x021E050C
 * packet: pkt_ov093_021E050C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0284.c and filed here.
 *
 * symbols:
 *   gHandWazaCamouflageHandlers 0x021F2414 data ov093 a4
 */

int *HAND_WAZA_GetCamouflageHandlers(int *p);
extern int gHandWazaCamouflageHandlers[];

/*
 * extent: 021E05C2 alignment padding.
 */
int *HAND_WAZA_GetCamouflageHandlers(int *p)
{
    *p = 1;
    return gHandWazaCamouflageHandlers;
}
