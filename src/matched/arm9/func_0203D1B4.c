/*
 * function: GFL_NET_GetNegotiationNum
 * address:  0x0203D1B4
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 */

extern int GFL_NET_HANDLE_GetNegotiationNum(void);

int GFL_NET_GetNegotiationNum(void)
{
    return GFL_NET_HANDLE_GetNegotiationNum();
}
