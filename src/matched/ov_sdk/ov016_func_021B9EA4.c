/*
 * function: SendBroadcast
 * address:  0x021B9EA4
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SOCL_GetHostID         0x0215EF48  arm
 *   SOC_U32to4U8           0x0215FBAC  arm
 *   SendFrameViaInterface  0x021B9E8C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol SendBroadcast (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B9EA4.c \
 *       --func SendBroadcast --addr 0x021B9EA4 --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern unsigned long SOCL_GetHostID(void);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
extern int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata);

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
