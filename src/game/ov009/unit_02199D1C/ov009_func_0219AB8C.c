/*
 * function: func_0219AB8C
 * address:  0x0219AB8C
 * packet:   pkt_ov009_0219AB8C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NNProcessData (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   func_02199284  0x02199284  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   func_021990D4  0x021990D4  arm  ov009
 *   func_0219A620  0x0219A620  arm  ov009
 *   func_0219A7AC  0x0219A7AC  arm  ov009
 *   func_0219A968  0x0219A968  arm  ov009
 *   func_0219AA08  0x0219AA08  arm  ov009
 *   g_021A64D4     0x021A64D4  data
 *   g_021A6504     0x021A6504  data
 *   g_021A6538     0x021A6538  data
 *   g_021A657C     0x021A657C  data
 *   g_021A65BC     0x021A65BC  data
 */

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct _NATNegotiator {
    int gameSock;                                    /* 0x00 */
    int cookie;                                      /* 0x04 */
    int clientIndex;                                 /* 0x08 */
    void (*progressCallback)(int state, void *userdata);                              /* 0x0C */
    void (*completedCallback)(int result, int gameSocket, SOCSockAddrIn *remoteaddr, void *userdata); /* 0x10 */
    void *userdata;                                  /* 0x14 */
    int negotiateSock;                               /* 0x18 */
    int state;                                       /* 0x1C */
    int initAckRecv[4];                              /* 0x20 */
    int retryCount;                                  /* 0x30 */
    int maxRetryCount;                               /* 0x34 */
    unsigned int retryTime;                          /* 0x38 */
    unsigned int guessedIP;                          /* 0x3C */
    unsigned short guessedPort;                      /* 0x40 */
    unsigned char gotRemoteData;                     /* 0x42 */
    unsigned char sendGotRemoteData;                 /* 0x43 */
    int result;                                      /* 0x44 */
} NATNegotiator;

typedef struct _NatNegPacket {
    unsigned char magic[6];                          /* 0x00 */
    unsigned char version;                           /* 0x06 */
    unsigned char packettype;                        /* 0x07 */
    int cookie;                                      /* 0x08 */
    unsigned int ipaddr;                             /* 0x0C */
    unsigned short port;                             /* 0x10 */
    unsigned char gotyourdata;                       /* 0x12 */
    unsigned char finished;                          /* 0x13 */
    unsigned char rest[0x38];                        /* 0x14 */
} NatNegPacket;

#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHL(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))

#include "../../../matched/arm9_sdk/libc/string.h"
extern int func_02199284(char *data);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern char *func_0215FA9C(unsigned int in);
extern NATNegotiator *func_021990D4(int cookie);
extern void func_0219A620(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
extern void func_0219A7AC(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
extern void func_0219A968(NATNegotiator *neg, NatNegPacket *p);
extern void func_0219AA08(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);

extern char g_021A64D4[];
extern char g_021A6504[];
extern char g_021A6538[];
extern char g_021A657C[];
extern char g_021A65BC[];

void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr)
{
    NatNegPacket p;
    NATNegotiator *neg;
    unsigned char ptype;

    if (!func_02199284(data)) {
        func_0217D254(7, 0, 4, g_021A64D4);
        return;
    }

    ptype = ((NatNegPacket *)data)->packettype;
    func_0217D254(7, 0, 8, g_021A6504, ptype, len, func_0215FA9C(fromaddr->addr), NN_NTOHS(fromaddr->port));

    if (ptype == 5 || ptype == 7) {
        if (len < 20) {
            func_0217D254(7, 0, 4, g_021A6538);
            return;
        }
        memcpy(&p, data, 20);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            func_0217D254(7, 0, 4, g_021A657C, NN_NTOHL((unsigned int)p.cookie));
            return;
        }
        if (ptype == 5)
            func_0219A620(neg, &p, fromaddr);
        else
            func_0219A7AC(neg, &p, fromaddr);
    } else if (ptype == 16) {
        if (len < 18)
            return;
        memcpy(&p, data, 18);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0)
            return;
        func_0219A968(neg, &p);
    } else {
        if (len < 21) {
            func_0217D254(7, 0, 4, g_021A65BC);
            return;
        }
        memcpy(&p, data, 21);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            func_0217D254(7, 0, 4, g_021A657C, NN_NTOHL((unsigned int)p.cookie));
            return;
        }
        func_0219AA08(neg, &p, fromaddr);
    }
}
