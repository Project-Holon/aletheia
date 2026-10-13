/*
 * function: NET_WHPIPE_SetNotifyCallback
 * address: 0x02178118
 * packet: pkt_ov014_02178118
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker leaf for ov122 func_021D4B74; two stores to the game-global object.
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *g_pWhPipeWork;
void NET_WHPIPE_SetNotifyCallback(u32 callback, u32 value)
{
    if (g_pWhPipeWork) {
        *(u32 *)(g_pWhPipeWork + 0xc38) = callback;
        *(u32 *)(g_pWhPipeWork + 0xc3c) = value;
    }
}
