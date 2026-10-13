/*
 * function: HAND_WAZA_GetThunderWaveHandlers
 * address: 0x021E0F44
 * packet: pkt_ov093_021E0F44
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0DC4.c and filed here.
 *
 * symbols:
 *   gThunderWaveHandlers 0x021F24D4 data ov093 a4
 */

int *HAND_WAZA_GetThunderWaveHandlers(int *p);
extern int gThunderWaveHandlers[];

int *HAND_WAZA_GetThunderWaveHandlers(int *p)
{
    *p = 1;
    return gThunderWaveHandlers;
}
