/*
 * function: SBServerGetPrivateInetAddress
 * address:  0x0219E238
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +8.
 */

int SBServerGetPrivateInetAddress(const int *p)
{
    return p[2];
}
