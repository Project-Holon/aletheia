/*
 * function: GFL_NET_COMMAND_IsHugeCommand
 * address:  0x0203A804
 * packet:   pkt_0203A804
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_COMMAND_GetSizeFunc   0x0203A748  arm
 */

extern int GFL_NET_COMMAND_GetSizeFunc(unsigned int idx);

int GFL_NET_COMMAND_IsHugeCommand(unsigned int idx)
{
    return GFL_NET_COMMAND_GetSizeFunc(idx) != 0;
}
