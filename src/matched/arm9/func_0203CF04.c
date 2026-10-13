/*
 * function: GFL_NET_ClearExitFlag
 * address:  0x0203CF04
 * packet:   pkt_0203CF04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_STATE_ClearExitFlag  0x0203BFF0  arm
 */

extern void GFL_NET_STATE_ClearExitFlag(void);

void GFL_NET_ClearExitFlag(void)
{
    GFL_NET_STATE_ClearExitFlag();
}
