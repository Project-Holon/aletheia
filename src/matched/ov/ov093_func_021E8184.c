/*
 * function: HAND_WAZA_GetRelicSongHandlers
 * address: 0x021E8184
 * packet: pkt_ov093_021E8184
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E7E58.c and filed here.
 *
 * symbols:
 *   gRelicSongHandlers 0x021F281C data ov093 a4
 */

int *HAND_WAZA_GetRelicSongHandlers(int *p);
extern int gRelicSongHandlers[];

int *HAND_WAZA_GetRelicSongHandlers(int *p)
{
    *p = 1;
    return gRelicSongHandlers;
}
