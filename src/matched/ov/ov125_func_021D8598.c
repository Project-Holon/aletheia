/*
 * function: GDS_SOCKET_Begin
 * address:  0x021D8598
 * packet:   pkt_021D8598
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GDS_SOCKET_Start  0x021D7770  arm
 *
 * Addresses are Black-image addresses.
 */

extern void GDS_SOCKET_Start(int, int, int);

void GDS_SOCKET_Begin(int a, int b, int c)
{
    GDS_SOCKET_Start(b, c, a);
}
