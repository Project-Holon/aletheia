/*
 * function: func_021994F0
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
 *   func_02199394  0x02199394  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   g_021A5AF8  0x021A5AF8  data
 *   g_021A5B30  0x021A5B30  data
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

extern char g_021A5AF8[];
extern char g_021A5B30[];
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_02199FB4(int cookie);
extern void func_02199394(NATNegotiator *neg);
extern unsigned int func_0217F264(void);

void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr)
{
    neg->result = result;
    neg->socket = socket;
    if (remoteaddr)
        neg->remoteaddr = *remoteaddr;
    if (result == 1 || result == 2) {
        func_0217D254(7, (char *)3, 8, g_021A5AF8, neg->cookie);
        neg->state = 5;
        neg->reportCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
        func_02199FB4(neg->cookie);
    } else {
        func_0217D254(7, (char *)3, 8, g_021A5B30, neg->cookie);
        func_02199394(neg);
        neg->state = 7;
        neg->timeout = func_0217F264() + 500;
        neg->retryCount = 0;
        neg->retryTime = 4;
        neg->reportCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
    }
}

