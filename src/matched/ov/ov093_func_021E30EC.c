/*
 * function: HAND_WAZA_AddBlizzard
 * address: 0x021E30EC
 * packet: pkt_ov093_021E30EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E3050.c and filed here.
 *
 * symbols:
 *   gBlizzardHandlers 0x021F246C data ov093 a4
 */

int *HAND_WAZA_AddBlizzard(int *p);
extern int gBlizzardHandlers[];

int *HAND_WAZA_AddBlizzard(int *p)
{
    *p = 1;
    return gBlizzardHandlers;
}
