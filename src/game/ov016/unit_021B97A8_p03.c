/*
 * file:     unit_021B97A8_p03.c
 * unit:     yes
 * function: func_021B9E8C, func_021B9EA4
 * address:  0x021B9E8C
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SOC_SendTo  0x0215F5B4  arm
 *   SOCL_GetHostID         0x0215EF48  arm
 *   SOC_U32to4U8           0x0215FBAC  arm
 */
typedef struct {
    unsigned long addr;
} SOCInAddr;

typedef struct {
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    SOCInAddr      addr;
} SOCSockAddrIn;

extern int SOC_SendTo(int s, void *buf, int len, int flags, void *sockTo);
extern unsigned long SOCL_GetHostID(void);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata);
int SendBroadcast(int sock, unsigned char *lpb, int size);


int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata)
{
    int ret;

    ret = SOC_SendTo(sock, lpdata, cbdata, 0, target);
    if (ret < 0)
        return -4;
    return ret;
}


int SendBroadcast(int sock, unsigned char *lpb, int size)
{
    int retv;
    SOCSockAddrIn target;
    unsigned char ipaddr[4];

    target.len = sizeof(target);
    target.family = 2;
    target.addr.addr = 0xFFFFFFFF;
    target.port = 0x1E6;
    SOC_U32to4U8(SOCL_GetHostID(), ipaddr);
    retv = SendFrameViaInterface(sock, &target, ipaddr, lpb, size);
    return retv;
}
