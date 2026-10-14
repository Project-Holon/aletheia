/*
 * function: GDS_SOCKET_GetReplySize
 * address:  0x021D85F4
 * packet:   pkt_ov125_021D85F4
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
 *   GDS_SOCKET_GetReplySizeUnlocked  0x021D7C14  arm ov125
 */

extern int GDS_SOCKET_GetReplySizeUnlocked(void);

int GDS_SOCKET_GetReplySize(void)
{
    return GDS_SOCKET_GetReplySizeUnlocked();
}
