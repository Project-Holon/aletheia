/*
 * function: BTLV_INPUT_GetPendingResult
 * address: 0x022033F0
 * packet: pkt_ov094_022033F0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov094/btlv_effvm.c and filed here.
 */

int BTLV_INPUT_GetPendingResult(int *p);

int BTLV_INPUT_GetPendingResult(int *p)
{
    return p[0x58 / 4];
}
