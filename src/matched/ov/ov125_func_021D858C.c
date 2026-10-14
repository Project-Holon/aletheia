/*
 * function: GDS_SOCKET_InitSsl
 * address:  0x021D858C
 * packet:   pkt_ov125_021D858C
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
 *   GDS_SOCKET_InitSslTemplate  0x021D8B44  arm ov125
 */

extern void GDS_SOCKET_InitSslTemplate(void);

void GDS_SOCKET_InitSsl(void)
{
    GDS_SOCKET_InitSslTemplate();
}
