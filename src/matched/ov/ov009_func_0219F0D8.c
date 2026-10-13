/*
 * function: ServerBrowserGetMyPublicIPAddr
 * address:  0x0219F0D8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x704.
 */

int ServerBrowserGetMyPublicIPAddr(const int *p)
{
    return p[0x1c1];
}
