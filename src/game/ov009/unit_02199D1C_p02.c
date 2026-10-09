/*
 * file:     unit_02199D1C_p02.c
 * unit:     yes
 * function: func_0219A968, func_0219AA08, func_0219AB8C
 * address:  0x0219A968
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
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0219972C  0x0219972C  arm  ov009
 *   g_021A6450  0x021A6450  data
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   current_time   0x0217F264  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   g_021A6470     0x021A6470  data
 *   g_021A648C     0x021A648C  data
 *   g_021A6498     0x021A6498  data
 *   func_02199284  0x02199284  arm  ov009
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   func_021990D4  0x021990D4  arm  ov009
 *   func_0219A620  0x0219A620  arm  ov009
 *   func_0219A7AC  0x0219A7AC  arm  ov009
 *   g_021A64D4     0x021A64D4  data
 *   g_021A6504     0x021A6504  data
 *   g_021A6538     0x021A6538  data
 *   g_021A657C     0x021A657C  data
 *   g_021A65BC     0x021A65BC  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

#define NN_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))
#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHL(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
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
    int socket;                                      /* 0x48 */
    SOCSockAddrIn remoteaddr;                        /* 0x4C */
} NATNegotiator;

typedef struct _NatNegPacket {
    unsigned char pad0[0xD];
    unsigned char porttype;
} NatNegPacket;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct SOCSockAddrIn_02199D1C
{
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn_02199D1C;

typedef struct NatNegPacket_02199D1C
{
    u8 magic[6];
    u8 version;
    u8 packettype;
    int cookie;
    u8 clientindex;
    u8 rest[0x3F];
} NatNegPacket_02199D1C;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern unsigned int func_0217F264(void);
extern void func_0219972C(NATNegotiator *neg);
extern void gsDebugFormat();
extern u32 current_time(void);
extern void SendPacket();
extern int func_02199284(char *data);
extern char *func_0215FA9C(unsigned int in);
extern NATNegotiator *func_021990D4(int cookie);
extern void func_0219A620(NATNegotiator *neg, NatNegPacket_02199D1C *p, SOCSockAddrIn_02199D1C *fromaddr);
extern void func_0219A7AC(NATNegotiator *neg, NatNegPacket_02199D1C *p, SOCSockAddrIn_02199D1C *fromaddr);
void func_0219A968(NATNegotiator *neg, NatNegPacket *p);
void func_0219AA08(NATNegotiator *neg, NatNegPacket_02199D1C *p, SOCSockAddrIn_02199D1C *fromaddr);
void func_0219AB8C(char *data, int len, SOCSockAddrIn_02199D1C *fromaddr);
extern char g_021A6450[];
extern char g_021A6470[];
extern char g_021A648C[];
extern char g_021A6498[];
extern char g_021A64D4[];
extern char g_021A6504[];
extern char g_021A6538[];
extern char g_021A657C[];
extern char g_021A65BC[];


/*
 * sdk:      ProcessPreinitAckPacket (natneg.o)
 */
void func_0219A968(NATNegotiator *neg, NatNegPacket *p)
{
    func_0217D254(7, 0, 8, g_021A6450, p->porttype);
    if (neg->state != 1) {
        neg->state = 1;
        neg->progressCallback(1, neg->userdata);
        neg->retryTime = func_0217F264() + 10000;
        neg->retryCount = 0;
        neg->maxRetryCount = 12;
    }
    switch (p->porttype) {
    case 0:
    case 1:
        return;
    case 2:
        func_0219972C(neg);
        break;
    }
}



void func_0219AA08(NATNegotiator *neg, NatNegPacket_02199D1C *p, SOCSockAddrIn_02199D1C *fromaddr)
{
    switch (p->packettype)
    {
    case 1:
        if (p->clientindex > 3)
            return;
        gsDebugFormat(7, 0, 8, g_021A6470, p->clientindex);
        neg->initAckRecv[p->clientindex] = 1;
        if (neg->state != 2)
            return;
        if (!neg->initAckRecv[1] || !neg->initAckRecv[2] || !neg->initAckRecv[3])
            return;
        if (neg->gameSock != -1)
        {
            if (!neg->initAckRecv[0])
                return;
        }
        neg->state = 3;
        neg->retryTime = current_time() + 60000;
        neg->progressCallback(neg->state, neg->userdata);
        break;
    case 2:
        gsDebugFormat(7, 0, 8, g_021A648C);
        p->packettype = 3;
        SendPacket(neg->negotiateSock, fromaddr->addr, (u16)NN_SWAP16(fromaddr->port), p, 0x15);
        break;
    case 14:
        gsDebugFormat(7, 0, 8, g_021A6498, neg->cookie);
        neg->state = 8;
        break;
    }
}



void func_0219AB8C(char *data, int len, SOCSockAddrIn_02199D1C *fromaddr)
{
    NatNegPacket_02199D1C p;
    NATNegotiator *neg;
    unsigned char ptype;

    if (!func_02199284(data)) {
        func_0217D254(7, 0, 4, g_021A64D4);
        return;
    }

    ptype = ((NatNegPacket_02199D1C *)data)->packettype;
    func_0217D254(7, 0, 8, g_021A6504, ptype, len, func_0215FA9C(fromaddr->addr), NN_NTOHS(fromaddr->port));

    if (ptype == 5 || ptype == 7) {
        if (len < 20) {
            func_0217D254(7, 0, 4, g_021A6538);
            return;
        }
        memcpy(&p, data, 20);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            func_0217D254(7, (char *)0, 4, g_021A657C, NN_NTOHL((unsigned int)p.cookie));
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
        func_0219A968(neg, (NatNegPacket *)&p);
    } else {
        if (len < 21) {
            func_0217D254(7, 0, 4, g_021A65BC);
            return;
        }
        memcpy(&p, data, 21);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            func_0217D254(7, (char *)0, 4, g_021A657C, NN_NTOHL((unsigned int)p.cookie));
            return;
        }
        func_0219AA08(neg, &p, fromaddr);
    }
}
