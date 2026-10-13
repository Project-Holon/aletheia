/*
 * function: tcpip
 * address:  0x0215A900
 * packet:   pkt_ov009_0215A900
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      tcpip (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   receive_packet  0x02157C7C  arm  ov009
 *   dispatch_ip  0x0215A71C  arm  ov009
 *   dispatch_arp  0x02158C68  arm  ov009
 *   throw_packet  0x02157D48  arm  ov009
 */

extern unsigned char *receive_packet(unsigned long *len);
extern void dispatch_ip(unsigned char *buf, unsigned long len);
extern void dispatch_arp(unsigned char *buf, unsigned long len);
extern void throw_packet(void);

void tcpip(void)
{
    unsigned long len;
    unsigned char *buf;

    for (;;) {
        buf = receive_packet(&len);
        if (len > 0x22) {
            unsigned short t = *(unsigned short *)(buf + 0xc);
            unsigned short type = (unsigned short)((t >> 8) | (t << 8));

            switch (type) {
            case 0x800:
                dispatch_ip(buf + 0xe, len - 0xe);
                break;
            case 0x806:
                dispatch_arp(buf + 0xe, len - 0xe);
                break;
            }
        }
        throw_packet();
    }
}
