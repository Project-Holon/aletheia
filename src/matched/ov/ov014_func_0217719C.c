/*
 * function: GFL_NET_DEVWIRELESS_SetEventCallback
 * address:  0x0217719C
 * packet:   pkt_0217719C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   NET_WHPIPE_SetEventCallback  0x02177310  thumb
 */

typedef unsigned int u32;

void NET_WHPIPE_SetEventCallback(u32 v);

int GFL_NET_DEVWIRELESS_SetEventCallback(u32 v)
{
    NET_WHPIPE_SetEventCallback(v);
    return 1;
}
