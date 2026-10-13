/*
 * function: HAND_WAZA_AddLevelDamage
 * address: 0x021E15A4
 * packet: pkt_ov093_021E15A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E14E4.c and filed here.
 *
 * symbols:
 *   gLevelDamageHandlers 0x021F2554 data ov093 a4
 */

int *HAND_WAZA_AddLevelDamage(int *p);
extern int gLevelDamageHandlers[];

int *HAND_WAZA_AddLevelDamage(int *p)
{
    *p = 1;
    return gLevelDamageHandlers;
}
