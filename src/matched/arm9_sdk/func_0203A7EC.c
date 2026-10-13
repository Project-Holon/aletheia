/*
 * function: GFL_NET_COMMAND_IsCommandValid
 * address:  0x0203A7EC
 * packet:   pkt_0203A7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_COMMAND_GetRecvFunc   0x0203A70C  arm
 */

extern int GFL_NET_COMMAND_GetRecvFunc(unsigned int idx);

int GFL_NET_COMMAND_IsCommandValid(unsigned int idx)
{
    return GFL_NET_COMMAND_GetRecvFunc(idx) != 0;
}
