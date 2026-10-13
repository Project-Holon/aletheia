/*
 * function: HAND_WAZA_AddNightmare
 * address: 0x021E1C40
 * packet: pkt_ov093_021E1C40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1B4C.c and filed here.
 *
 * symbols:
 *   gNightmareHandlers 0x021F24DC data ov093 a4
 */

int *HAND_WAZA_AddNightmare(int *p);
extern int gNightmareHandlers[];

int *HAND_WAZA_AddNightmare(int *p)
{
    *p = 1;
    return gNightmareHandlers;
}
