/*
 * function: func_02157838
 * address:  0x02157838
 * packet:   pkt_ov009_02157838
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      check_tcpudpsum (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02157700  0x02157700  arm  ov009
 */

extern unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);

unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto)
{
    unsigned long sum = func_02157700(tcpudp_hdr, len, proto);

    sum = func_02157700(ip_hdr + 0xc, 8, sum);
    sum += len;
    if (sum & 0x10000)
        sum = (unsigned short)(sum + 1);
    return sum != 0xffff;
}
