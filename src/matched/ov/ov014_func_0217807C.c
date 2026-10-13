/*
 * function: NET_WHPIPE_OnChildDisconnected
 * address: 0x0217807C
 * packet: pkt_ov014_0217807C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *g_pWhPipeWork;
void NET_WHPIPE_OnChildDisconnected(void)
{
    if (g_pWhPipeWork[0xcec])
        g_pWhPipeWork[0xceb] = 1;
}
