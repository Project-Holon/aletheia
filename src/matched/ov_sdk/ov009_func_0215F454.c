/*
 * function: SOC_Bind
 * address:  0x0215f454
 * packet:   pkt_ov009_0215F454
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Bind (soc.o)
 *
 * symbols:
 *   SOCL_Bind   0x0215d43c arm
 */

extern int SOCL_Bind(int s, unsigned short local_port);

int SOC_Bind(int s, void *sockAddr)
{
    unsigned short port = *(unsigned short *)((char *)sockAddr + 2);

    return SOCL_Bind(s, (unsigned short)(((port >> 8) & 0xff)
                                       | ((port << 8) & 0xff00)));
}
