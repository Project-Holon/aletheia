/*
 * function: HAND_WAZA_AddMetronome
 * address: 0x021E6A78
 * packet: pkt_ov093_021E6A78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E69E8.c and filed here.
 *
 * symbols:
 *   gMetronomeWazaHandlers 0x021F28F8 data a4
 */

int *HAND_WAZA_AddMetronome(int *p);
extern int gMetronomeWazaHandlers[];

int *HAND_WAZA_AddMetronome(int *p)
{
    *p = 2;
    return gMetronomeWazaHandlers;
}
