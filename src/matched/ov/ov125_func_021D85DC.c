/*
 * function: GDS_SOCKET_GetError
 * address:  0x021D85DC
 * packet:   pkt_ov125_021D85DC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM tail call: ldr ip, =target; bx ip.  The listing labels the
 * two-instruction body func_021D85DC between GDS_SOCKET_GetState and
 * GDS_SOCKET_GetReply; the C is the error getter of gds_socket.c.
 *
 * symbols:
 *   GDS_SOCKET_GetErrorUnlocked  0x021D7C48  arm  ov125
 */

extern int GDS_SOCKET_GetErrorUnlocked(void);

int GDS_SOCKET_GetError(void)
{
    return GDS_SOCKET_GetErrorUnlocked();
}
