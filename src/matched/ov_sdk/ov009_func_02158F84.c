/*
 * function: func_02158F84
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
 *   func_021578EC  0x021578EC  arm  ov009
 *   func_02157928  0x02157928  arm  ov009
 */

extern unsigned long func_021578EC(unsigned long ip);
extern int func_02157928(unsigned v);

unsigned long func_02158F84(unsigned long ip1, unsigned long ip2)
{
    if (ip1 != 0 && !func_021578EC(ip1) && !func_02157928(ip1) &&
        ip2 != 0 && !func_021578EC(ip2) && !func_02157928(ip2))
        return 1;
    return 0;
}
