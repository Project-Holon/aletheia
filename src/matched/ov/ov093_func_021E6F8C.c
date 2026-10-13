/*
 * function: HAND_WAZA_AddAllStatBoostChance
 * address: 0x021E6F8C
 * packet: pkt_ov093_021E6F8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6F14_p02.c and filed here.
 *
 * symbols:
 *   gAllStatBoostChanceHandlers 0x021F262C data ov093 a4
 */

extern int gAllStatBoostChanceHandlers[];
int *HAND_WAZA_AddAllStatBoostChance(int *p);

int *HAND_WAZA_AddAllStatBoostChance(int *p)
{
    *p = 1;
    return gAllStatBoostChanceHandlers;
}
