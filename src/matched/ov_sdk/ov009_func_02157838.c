/*
 * function: check_tcpudpsum
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
 *   calc_checksum_do  0x02157700  arm  ov009
 */

extern unsigned long calc_checksum_do(unsigned char *s, unsigned long len, unsigned long sum);

unsigned long check_tcpudpsum(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto)
{
    unsigned long sum = calc_checksum_do(tcpudp_hdr, len, proto);

    sum = calc_checksum_do(ip_hdr + 0xc, 8, sum);
    sum += len;
    if (sum & 0x10000)
        sum = (unsigned short)(sum + 1);
    return sum != 0xffff;
}
