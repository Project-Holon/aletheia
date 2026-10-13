/*
 * function: valid_IP
 * address:  0x02158F84
 * packet:   pkt_ov009_02158F84
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      valid_IP (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   is_broadcast  0x021578EC  arm  ov009
 *   is_multicast  0x02157928  arm  ov009
 */

extern unsigned long is_broadcast(unsigned long ip);
extern int is_multicast(unsigned v);

unsigned long valid_IP(unsigned long ip1, unsigned long ip2)
{
    if (ip1 != 0 && !is_broadcast(ip1) && !is_multicast(ip1) &&
        ip2 != 0 && !is_broadcast(ip2) && !is_multicast(ip2))
        return 1;
    return 0;
}
