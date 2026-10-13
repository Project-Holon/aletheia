/*
 * function: HAND_WAZA_GetFusionHandlers
 * address: 0x021E8304
 * packet: pkt_ov093_021E8304
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E8270.c and filed here.
 *
 * symbols:
 *   gFusionFlareFusionBoltHandlers 0x021F27E4 data ov093 a4
 */

int *HAND_WAZA_GetFusionHandlers(int *p);
extern int gFusionFlareFusionBoltHandlers[];

int *HAND_WAZA_GetFusionHandlers(int *p)
{
    *p = 1;
    return gFusionFlareFusionBoltHandlers;
}
