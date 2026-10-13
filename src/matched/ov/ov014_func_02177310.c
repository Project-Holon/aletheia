/*
 * function: NET_WHPIPE_SetEventCallback
 * address:  0x02177310
 * packet:   pkt_02177310
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork  0x021797A4  data  a4
 */

typedef unsigned int u32;

void NET_WHPIPE_SetEventCallback(u32 v)
{
    *(u32 *)(*(u32 *)0x021797A4 + 4) = v;
}
