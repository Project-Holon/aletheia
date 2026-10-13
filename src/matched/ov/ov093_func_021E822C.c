/*
 * function: HAND_WAZA_GetMiracleEyeHandlers
 * address: 0x021E822C
 * packet: pkt_ov093_021E822C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E8200.c and filed here.
 *
 * symbols:
 *   gMiracleEyeHandlers 0x021F2958 data ov093 a4
 */

int *HAND_WAZA_GetMiracleEyeHandlers(int *p);
extern int gMiracleEyeHandlers[];

int *HAND_WAZA_GetMiracleEyeHandlers(int *p)
{
    *p = 2;
    return gMiracleEyeHandlers;
}
