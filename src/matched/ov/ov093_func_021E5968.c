/*
 * function: HAND_WAZA_GetUTurnHandlers
 * address: 0x021E5968
 * packet: pkt_ov093_021E5968
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5974.c and filed here.
 *
 * symbols:
 *   gUTurnHandlers 0x021F2584 data ov093 a4
 *
 * symbols:
 *   gUTurnHandlers     0x021F2584  data   ov093  a4
 */

extern int gUTurnHandlers[];
int *HAND_WAZA_GetUTurnHandlers(int *p);

int *HAND_WAZA_GetUTurnHandlers(int *p)
{
    *p = 1;
    return gUTurnHandlers;
}
