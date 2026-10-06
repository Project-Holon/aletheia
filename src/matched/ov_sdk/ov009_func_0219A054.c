/*
 * function: func_0219A054
 * address:  0x0219A054
 * packet:   pkt_ov009_0219A054
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NegotiateThink (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021991C8  0x021991C8  arm  ov009
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_0219AB8C  0x0219AB8C  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_021994F0  0x021994F0  arm  ov009
 *   func_021995E4  0x021995E4  arm  ov009
 *   func_0219972C  0x0219972C  arm  ov009
 *   func_02199A90  0x02199A90  arm  ov009
 *   func_02199394  0x02199394  arm  ov009
 *   func_0219A034  0x0219A034  arm  ov009
 *   g_021A5E88     0x021A5E88  data
 *   g_021A5EAC     0x021A5EAC  data
 *   g_021AE7A0     0x021AE7A0  data
 *   g_021A5EE8     0x021A5EE8  data
 *   g_021A5F1C     0x021A5F1C  data
 *   g_021A5F5C     0x021A5F5C  data
 *   g_021A5FA0     0x021A5FA0  data
 *   g_021A5FE8     0x021A5FE8  data
 *   g_021A6028     0x021A6028  data
 *   g_021A606C     0x021A606C  data
 *   g_021A60B8     0x021A60B8  data
 *   g_021A60FC     0x021A60FC  data
 *   g_021A6150     0x021A6150  data
 *   g_021A61A0     0x021A61A0  data
 *
 * State enum is compared unsigned in the two range tests (bhi), so those
 * two reads are cast to unsigned int. The receive loop is a do/while with
 * the socket test at the bottom, inside an outer socket test.
 */

typedef enum NegotiateState {
    ns_preinitsent, ns_preinitack, ns_initsent, ns_initack, ns_connectping,
    ns_finished, ns_canceled, ns_reportsent, ns_reportack
} NegotiateState;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct _NATNegotiator {
    int gameSock;                                    /* 0x00 */
    int cookie;                                      /* 0x04 */
    int clientindex;                                 /* 0x08 */
    void (*progressCallback)(int state, void *userdata);                              /* 0x0C */
    void (*completedCallback)(int result, int gameSocket, SOCSockAddrIn *remoteaddr, void *userdata); /* 0x10 */
    void *userdata;                                  /* 0x14 */
    int negotiateSock;                               /* 0x18 */
    NegotiateState state;                            /* 0x1C */
    int initAckRecv[4];                              /* 0x20 */
    int retryCount;                                  /* 0x30 */
    int maxRetryCount;                               /* 0x34 */
    unsigned long retryTime;                         /* 0x38 */
    unsigned int guessedIP;                          /* 0x3C */
    unsigned short guessedPort;                      /* 0x40 */
    unsigned char gotRemoteData;                     /* 0x42 */
    unsigned char sendGotRemoteData;                 /* 0x43 */
    int result;                                      /* 0x44 */
    int connectedSocket;                             /* 0x48 */
    SOCSockAddrIn remoteaddr;                        /* 0x4C */
} NATNegotiator;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_021991C8(NATNegotiator *neg);
extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int func_0217ED54(int sock);
extern void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr);
extern unsigned long func_0217F264(void);
extern void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
struct NATNegotiator;
extern void func_021995E4(struct NATNegotiator *neg);
extern void func_0219972C(NATNegotiator *neg);
extern void func_02199A90(struct NATNegotiator *neg);
extern void func_02199394(struct NATNegotiator *neg);
extern void func_0219A034(int *p);

extern char g_021A5E88[];
extern char g_021A5EAC[];
extern char g_021AE7A0[];
extern char g_021A5EE8[];
extern char g_021A5F1C[];
extern char g_021A5F5C[];
extern char g_021A5FA0[];
extern char g_021A5FE8[];
extern char g_021A6028[];
extern char g_021A606C[];
extern char g_021A60B8[];
extern char g_021A60FC[];
extern char g_021A6150[];
extern char g_021A61A0[];

void func_0219A054(NATNegotiator *neg)
{
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);
    int error;

    if (neg == 0) {
        func_0217D254(7, (char *)4, 4, g_021A5E88);
        return;
    }

    if (neg->state == ns_canceled) {
        func_0217D254(7, (char *)2, 8, g_021A5EAC, neg->cookie);
        func_021991C8(neg);
        return;
    }

    if (neg->negotiateSock != -1) {
        do {
            if (!func_0217EF50(neg->negotiateSock))
                break;
            error = func_0217EC60(neg->negotiateSock, g_021AE7A0, 512, 0, &saddr, &saddrlen);
            if (error == -1) {
                func_0217D254(7, 0, 8, g_021A5EE8, neg->cookie, func_0217ED54(neg->negotiateSock));
                break;
            }
            func_0219AB8C(g_021AE7A0, error, &saddr);
            if (neg->state == ns_canceled)
                break;
        } while (neg->negotiateSock != -1);
    }

    if ((neg->state == ns_preinitsent || neg->state == ns_preinitack || neg->state == ns_initsent ||
         neg->state == ns_connectping) && func_0217F264() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, 0, 8, g_021A5F1C, neg->cookie);
            if ((unsigned int)neg->state <= ns_initsent)
                func_021994F0(neg, 2, -1, 0);
            else
                func_021994F0(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            func_0217D254(7, 0, 8, g_021A5F5C, neg->cookie, neg->retryCount);
            if ((unsigned int)neg->state <= ns_preinitack)
                func_021995E4((struct NATNegotiator *)neg);
            else if (neg->state == ns_initsent)
                func_0219972C(neg);
            else
                func_02199A90((struct NATNegotiator *)neg);
        }
    }

    if (neg->state == ns_initack && func_0217F264() > neg->retryTime) {
        func_0217D254(7, 0, 8, g_021A5FA0, neg->cookie);
        func_021994F0(neg, 1, -1, 0);
    }

    if (neg->state == ns_connectping && func_0217F264() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, 0, 8, g_021A5FE8, neg->cookie);
            func_021994F0(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            func_0217D254(7, 0, 8, g_021A6028, neg->cookie, neg->retryCount);
            func_02199A90((struct NATNegotiator *)neg);
            neg->retryTime = func_0217F264() + 700;
        }
    }

    if (neg->state == ns_reportsent && func_0217F264() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, (char *)3, 8, g_021A606C, neg->cookie);
            neg->state = ns_finished;
        } else {
            func_02199394((struct NATNegotiator *)neg);
            neg->retryCount++;
            func_0217D254(7, 0, 8, g_021A60B8, neg->cookie, neg->retryCount);
            neg->retryTime = func_0217F264() + 500;
        }
    }

    if (neg->state == ns_finished || neg->state == ns_reportack) {
        if (neg->sendGotRemoteData)
            func_0217D254(7, (char *)3, 8, g_021A60FC, neg->cookie);
        else if (func_0217F264() > neg->retryTime)
            func_0217D254(7, (char *)3, 8, g_021A6150, neg->cookie);
        func_0219A034((int *)neg);
    }

    if (neg->state == ns_canceled) {
        func_0217D254(7, (char *)2, 8, g_021A61A0, neg->cookie);
        func_021991C8(neg);
    }
}
