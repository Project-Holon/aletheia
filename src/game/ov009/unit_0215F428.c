/*
 * file:     unit_0215F428.c
 * unit:     yes
 * function: func_0215F428, func_0215F454, func_0215F480, func_0215F4DC, func_0215F500, func_0215F590, func_0215F5B4
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
 *   SOCL_ReadFrom   0x0215d6c8 arm
 *   SOCL_WriteTo   0x0215e024 arm
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

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int SOCL_CreateSocket(struct SOCLSocketParam *param);
extern int SOCL_Bind(int s, unsigned short local_port);
extern int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip);
extern int SOCL_ReadFrom(int s, void *buffer, int buffer_len,
                         unsigned short *remote_port, unsigned long *remote_ip,
                         int flags);
extern int func_0215D6C8(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, int flags);
extern int SOCL_WriteTo(int s, void *buffer, int buffer_len,
                        unsigned short remote_port, unsigned long remote_ip,
                        int flags);
int SOC_Socket(int unused, int type);
int SOC_Bind(int s, void *sockAddr);
int SOC_Connect(int s, void * sockAddr);
int SOC_Recv(int s, void *buf, int len, int flags);
int func_0215F500(int a0, int a1, int a2, int a3, u8 *out);
int SOC_Send(int s, void *buf, int len, int flags);
int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo);
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




int SOC_Recv(int s, void *buf, int len, int flags)
{
    return SOCL_ReadFrom(s, buf, len, 0, 0, flags);
}




/*
 * Ask func_0215D6C8 for a two-word header into locals; on success and with a
 * non-null destination object, write the byte-swapped halfword to +2 and the
 * byte-swapped word to +4.  Returns the callee's result.
 */
int func_0215F500(int a0, int a1, int a2, int a3, u8 *out)
{
    u16 h;
    u32 w;
    int r;

    r = func_0215D6C8(a0, (void *)a1, a2, &h, (long unsigned int *)(&w), a3);
    if (r < 0)
        return r;
    if (out == 0)
        return r;

    *(u16 *)(out + 2) = (u16)(((h >> 8) & 0xff) | ((h << 8) & 0xff00));
    *(u32 *)(out + 4) = ((w >> 24) & 0xff) | ((w >> 8) & 0xff00)
                      | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
    return r;
}



int SOC_Send(int s, void *buf, int len, int flags)
{
    return SOCL_WriteTo(s, buf, len, 0, 0, flags);
}



int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo)
{
    struct SOCSockAddrIn * addr = (struct SOCSockAddrIn *)sockTo;
    unsigned short port;
    unsigned long ip;

    if (sockTo != 0) {
        port = addr->port;
        ip = addr->addr;
        port = (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00));
        ip = ((ip >> 24) & 0xff) | ((ip >> 8) & 0xff00) | ((ip << 8) & 0xff0000)
           | ((ip << 24) & 0xff000000);
    } else {
        port = 0;
        ip = 0;
    }
    return SOCL_WriteTo(s, buf, len, port, ip, flags);
}
