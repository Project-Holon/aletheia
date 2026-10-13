/*
 * function: HAND_WAZA_AddHealBell
 * address: 0x021E493C
 * packet: pkt_ov093_021E493C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E492C.c and filed here.
 *
 * symbols:
 *   gHealBellHandlers 0x021F2BA0 data ov093 a4
 */

int *HAND_WAZA_AddHealBell(int *p);

/* 021E4948  stack-arg wrapper: HAND_WAZA_CureParty(a, b, c, d, 0x6f) */
extern int gHealBellHandlers[];

int *HAND_WAZA_AddHealBell(int *p)
{
    *p = 3;
    return gHealBellHandlers;
}
