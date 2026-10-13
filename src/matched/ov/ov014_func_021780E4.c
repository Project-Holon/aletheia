/*
 * function: NET_WHPIPE_StartJoinLock
 * address: 0x021780E4
 * packet: pkt_ov014_021780E4
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
typedef unsigned short u16;
extern u8 *g_pWhPipeWork;
void NET_WHPIPE_StartJoinLock(int a)
{
    if (g_pWhPipeWork)
        *(u16 *)(g_pWhPipeWork + 0xc6c) = 20;
}
