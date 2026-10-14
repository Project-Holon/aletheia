/*
 * function: GDS_SOCKET_Shutdown
 * address:  0x021D85B4
 * packet:   pkt_ov125_021D85B4
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
 *   GDS_SOCKET_Reset  0x021D770C  arm ov125
 */

extern void GDS_SOCKET_Reset(void);

void GDS_SOCKET_Shutdown(void)
{
    GDS_SOCKET_Reset();
}
