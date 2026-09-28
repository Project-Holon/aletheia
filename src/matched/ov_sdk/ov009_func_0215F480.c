/*
 * function: SOC_Connect
 * address:  0x0215F480
 * packet:   pkt_ov009_0215F480
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Connect (soc.o)
 *
 * symbols:
 *   SOCL_Connect     0x0215d4ac arm
 */

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

extern int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip);

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

int SOC_Connect(int s, void * sockAddr)
{
    struct SOCSockAddrIn * addr = (struct SOCSockAddrIn *)sockAddr;

    return SOCL_Connect(s, SWAP16(addr->port), SWAP32(addr->addr));
}
