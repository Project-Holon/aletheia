/*
 * function: gt2GetLocalIP
 * address:  0x02195E38
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +4.
 */

int gt2GetLocalIP(const int *p)
{
    return p[1];
}
