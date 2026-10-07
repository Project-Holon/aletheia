/*
 * file:     unit_0215F428_p01.c
 * unit:     yes
 * function: func_0215F428, func_0215F454, func_0215F480
 * address:  0x0215F428
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SOCL_CreateSocket    0x0215d070 arm
 *   SOCLSocketParamTCP   0x021a1cfc data
 *   SOCLSocketParamUDP   0x021a1ce4 data
 *   SOCL_Bind   0x0215d43c arm
 *   SOCL_Connect     0x0215d4ac arm
 */
#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
struct SOCLSocketParam {
    unsigned long w[16];
};

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

extern int SOCL_CreateSocket(struct SOCLSocketParam *param);
extern int SOCL_Bind(int s, unsigned short local_port);
extern int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip);
int SOC_Socket(int unused, int type);
int SOC_Bind(int s, void *sockAddr);
int SOC_Connect(int s, void * sockAddr);
extern struct SOCLSocketParam SOCLSocketParamTCP;
extern struct SOCLSocketParam SOCLSocketParamUDP;


int SOC_Socket(int unused, int type)
{
    if (type == 1)
        return SOCL_CreateSocket(&SOCLSocketParamTCP);
    return SOCL_CreateSocket(&SOCLSocketParamUDP);
}


int SOC_Bind(int s, void *sockAddr)
{
    unsigned short port = *(unsigned short *)((char *)sockAddr + 2);

    return SOCL_Bind(s, (unsigned short)(((port >> 8) & 0xff)
                                       | ((port << 8) & 0xff00)));
}


int SOC_Connect(int s, void * sockAddr)
{
    struct SOCSockAddrIn * addr = (struct SOCSockAddrIn *)sockAddr;

    return SOCL_Connect(s, SWAP16(addr->port), SWAP32(addr->addr));
}
