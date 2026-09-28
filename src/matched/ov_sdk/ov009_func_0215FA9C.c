/*
 * function: SOC_InetNtoA
 * address:  0x0215fa9c
 * packet:   pkt_ov009_0215FA9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_InetNtoA (soc.o)
 *
 * symbols:
 *   SOC_InetNtoP                          0x0215fb28 arm
 *   _ZZ12SOC_InetNtoA9SOCInAddrE6buffer   0x021aa4ec data
 */

struct SOCInAddr {
    unsigned long addr;
};

extern char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len);
extern char _ZZ12SOC_InetNtoA9SOCInAddrE6buffer[16];

char *SOC_InetNtoA(struct SOCInAddr in)
{
    SOC_InetNtoP(2, &in, _ZZ12SOC_InetNtoA9SOCInAddrE6buffer, 16);
    return _ZZ12SOC_InetNtoA9SOCInAddrE6buffer;
}
