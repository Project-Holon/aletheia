/*
 * function: HAND_WAZA_AddSuckerPunch
 * address: 0x021E1C80
 * packet: pkt_ov093_021E1C80
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
 *   gSuckerPunchHandlers 0x021F24B4 data ov093 a4
 */

int *HAND_WAZA_AddSuckerPunch(int *p);
extern int gSuckerPunchHandlers[];

int *HAND_WAZA_AddSuckerPunch(int *p)
{
    *p = 1;
    return gSuckerPunchHandlers;
}
