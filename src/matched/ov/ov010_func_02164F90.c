/*
 * function: GAME_BEACON_SEARCH_OnConnected
 * address: 0x02164F90
 * packet: pkt_ov010_02164F90
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov010/game_beacon_search.c and filed here.
 */

typedef unsigned char u8;
int GAME_BEACON_SEARCH_OnConnected(int a, int b, u8 *c);

int GAME_BEACON_SEARCH_OnConnected(int a, int b, u8 *c)
{
    c[8] = 1;
    return 1;
}
