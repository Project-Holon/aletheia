/*
 * function: NET_WHPIPE_SetWatchDisconnect
 * address: 0x02177B0C
 * packet: pkt_ov014_02177B0C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov014/net_whpipe_p02.c and filed here.
 *
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
void NET_WHPIPE_SetWatchDisconnect(u8 v);
extern u8 *g_pWhPipeWork;

void NET_WHPIPE_SetWatchDisconnect(u8 v)
{
    u8 *w = g_pWhPipeWork;
    if (w != 0) {
        w[0xCEC] = v;
        *(u16 *)(w + 0xC6A) = 0xFFFF;
    }
}
