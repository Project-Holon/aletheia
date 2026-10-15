/*
 * function: StartReport
 * address:  0x021994F0
 * packet:   pkt_ov009_021994F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      StartReport (natneg.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   SendReportPacket  0x02199394  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   gNatNegReportFailFmt  0x021A5AF8  data
 *   gNatNegReportDoneFmt  0x021A5B30  data
 */

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned char port[2];
    unsigned char addr[4];
} SOCSockAddrIn;

typedef struct _NATNegotiator {
    int state0;
    int cookie;
    unsigned char pad8[8];
    void (*reportCallback)(int result, int socket, SOCSockAddrIn *remoteaddr, void *userdata);
    void *userdata;
    unsigned char pad18[4];
    int state;
    unsigned char pad20[0x10];
    int retryCount;
    int retryTime;
    unsigned int timeout;
    unsigned char pad3C[8];
    int result;
    int socket;
    SOCSockAddrIn remoteaddr;
} NATNegotiator;

extern char gNatNegReportFailFmt[];
extern char gNatNegReportDoneFmt[];
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_02199FB4(int cookie);
struct NATNegotiator;
extern void SendReportPacket(struct NATNegotiator *neg);
extern unsigned int current_time(void);

void StartReport(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr)
{
    neg->result = result;
    neg->socket = socket;
    if (remoteaddr)
        neg->remoteaddr = *remoteaddr;
    if (result == 1 || result == 2) {
        func_0217D254(7, (char *)3, 8, gNatNegReportFailFmt, neg->cookie);
        neg->state = 5;
        neg->reportCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
        func_02199FB4(neg->cookie);
    } else {
        func_0217D254(7, (char *)3, 8, gNatNegReportDoneFmt, neg->cookie);
        SendReportPacket((struct NATNegotiator *)neg);
        neg->state = 7;
        neg->timeout = current_time() + 500;
        neg->retryCount = 0;
        neg->retryTime = 4;
        neg->reportCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
    }
}

