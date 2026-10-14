/*
 * function: GDS_SOCKET_GetReply
 * address:  0x021D85E8
 * packet:   pkt_ov125_021D85E8
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
 *   GDS_SOCKET_GetReplyUnlocked  0x021D7BDC  arm ov125
 */

extern char *GDS_SOCKET_GetReplyUnlocked(void);

char *GDS_SOCKET_GetReply(void)
{
    return GDS_SOCKET_GetReplyUnlocked();
}
