/*
 * function: SendFrameViaInterface
 * address:  0x021B9E8C
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SOC_SendTo  0x0215F5B4  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol SendFrameViaInterface (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * DWARF leaves out the unused third parameter; SendBroadcast passes its ipaddr there.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B9E8C.c \
 *       --func SendFrameViaInterface --addr 0x021B9E8C --region ov016 --cc ../2.0/sp1p2 --thumb
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

int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata)
{
    int ret;

    ret = SOC_SendTo(sock, lpdata, cbdata, 0, target);
    if (ret < 0)
        return -4;
    return ret;
}
