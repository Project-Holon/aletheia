/*
 * function: GDS_SOCKET_GetMaxReplySize
 * address:  0x021D8600
 * packet:   pkt_ov125_021D8600
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM tail call: ldr ip, =target; bx ip.
 *
 * symbols:
 *   GDS_SOCKET_GetMaxReplySizeOf  0x021D89EC  arm ov125
 */

extern int GDS_SOCKET_GetMaxReplySizeOf(int n);

int GDS_SOCKET_GetMaxReplySize(int n)
{
    return GDS_SOCKET_GetMaxReplySizeOf(n);
}
