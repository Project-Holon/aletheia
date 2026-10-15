/*
 * function: WIFIBATTLEMATCH_NET_IsBufferZero
 * address: 0x021DC5AC
 * packet: pkt_ov175_021DC5AC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unlabelled zero-word test blocking matched caller021DC338.
 */
typedef unsigned int u32;
int WIFIBATTLEMATCH_NET_IsBufferZero(const u32 *p,u32 bytes)
{
    u32 i;
    for(i=0;i<(bytes>>2);i++)if(p[i]!=0)return 0;
    return 1;
}
