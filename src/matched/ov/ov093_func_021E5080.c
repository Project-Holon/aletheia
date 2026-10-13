/*
 * function: HAND_WAZA_AddPowerSplit
 * address: 0x021E5080
 * packet: pkt_ov093_021E5080
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4FF4.c and filed here.
 *
 * symbols:
 *   gPowerSplitHandlers 0x021F26E4 data ov093 a4
 */

extern int gPowerSplitHandlers[];
int *HAND_WAZA_AddPowerSplit(int *p);

int *HAND_WAZA_AddPowerSplit(int *p)
{
    *p = 1;
    return gPowerSplitHandlers;
}
