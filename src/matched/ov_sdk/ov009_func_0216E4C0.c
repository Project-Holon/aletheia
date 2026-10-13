/*
 * function: DWCi_GT2UnrecognizedMessageCallback
 * address:  0x0216E4C0
 * packet:   pkt_ov009_0216E4C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2UnrecognizedMessageCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02175F3C   0x02175F3C  arm  ov009
 *   qr2_parse_queryA   0x0219C7C0  arm  ov009
 *   func_020923F0   0x020923F0  arm
 *   func_0219AB8C   0x0219AB8C  arm  ov009
 *   g_021A5A7C      0x021A5A7C  data
 */

#include "../include/G_Magic6.h"

typedef struct SockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SockAddrIn;

typedef struct MatchCnt {
    unsigned char pad0[0x10];
    void *f10;
} MatchCnt;

extern void MIi_CpuClear32(int v, void *p, int size);
extern int func_02175F3C(void);
extern void qr2_parse_queryA(void *qr2, unsigned char *message, int len, SockAddrIn *saddr);
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);
struct SOCSockAddrIn;
extern void func_0219AB8C(char *data, int len, struct SOCSockAddrIn *fromaddr);
extern struct Magic6 g_021A5A7C;

int DWCi_GT2UnrecognizedMessageCallback(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len)
{
    SockAddrIn saddr;

    if (len == 0 || message == 0)
        return 0;
    MIi_CpuClear32(0, &saddr, 8);
    saddr.family = 2;
    saddr.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
    saddr.addr = ip;
    ip = message[0];
    if ((ip == 0xFE && message[1] == 0xFD) || ip == 0x5C) {
        if (((MatchCnt *)func_02175F3C())->f10 != 0)
            qr2_parse_queryA(((MatchCnt *)func_02175F3C())->f10, message, len, &saddr);
    } else if (func_020923F0(message, (const u8 *)((char *)&g_021A5A7C), 6) == 0) {
        func_0219AB8C((char *)message, len, (struct SOCSockAddrIn *)(&saddr));
    } else {
        return 0;
    }
    return 1;
}
