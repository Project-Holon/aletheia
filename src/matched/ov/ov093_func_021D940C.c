/*
 * function: HAND_TOKUSEI_GetParalysisGuardHandlers
 * address: 0x021D940C
 * packet: pkt_ov093_021D940C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gParalysisGuardHandlers 0x021F0BFC data ov093 a4
 */

int *HAND_TOKUSEI_GetParalysisGuardHandlers(int *p);
extern int gParalysisGuardHandlers[];

int *HAND_TOKUSEI_GetParalysisGuardHandlers(int *p)
{
    *p = 5;
    return gParalysisGuardHandlers;
}
