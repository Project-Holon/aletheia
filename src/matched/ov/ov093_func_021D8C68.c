/*
 * function: BTL_CALC_GetTorrentHandlers
 * address: 0x021D8C68
 * packet: pkt_ov093_021D8C68
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8B50.c and filed here.
 *
 * symbols:
 *   gTorrentHandlers 0x021F0610 data ov093 a4
 */

int *BTL_CALC_GetTorrentHandlers(int *p);
extern int gTorrentHandlers[];

int *BTL_CALC_GetTorrentHandlers(int *p)
{
    *p = 1;
    return gTorrentHandlers;
}
