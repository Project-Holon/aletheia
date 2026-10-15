/*
 * function: NegotiateThink
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
 *   RemoveNegotiator  0x021991C8  arm  ov009
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   NNProcessData  0x0219AB8C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   StartReport  0x021994F0  arm  ov009
 *   SendPreinitPacket  0x021995E4  arm  ov009
 *   SendInitPackets  0x0219972C  arm  ov009
 *   SendPingPacket  0x02199A90  arm  ov009
 *   SendReportPacket  0x02199394  arm  ov009
 *   RemoveFinishedNegotiator  0x0219A034  arm  ov009
 *   gNatNegThinkNullFmt     0x021A5E88  data
 *   gNatNegThinkRemoveFmt     0x021A5EAC  data
 *   gNatNegRecvBuf     0x021AE7A0  data
 *   gNatNegRecvErrFmt     0x021A5EE8  data
 *   gNatNegInitTimeoutFmt     0x021A5F1C  data
 *   gNatNegResendInitFmt     0x021A5F5C  data
 *   gNatNegNoPingFmt     0x021A5FA0  data
 *   gNatNegPingTimeoutFmt     0x021A5FE8  data
 *   gNatNegResendPingFmt     0x021A6028  data
 *   gNatNegReportTimeoutFmt     0x021A606C  data
 *   gNatNegResendReportFmt     0x021A60B8  data
 *   gNatNegBothDoneFmt     0x021A60FC  data
 *   gNatNegLingerDoneFmt     0x021A6150  data
 *   gNatNegRemovePostFmt     0x021A61A0  data
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
extern void RemoveNegotiator(NATNegotiator *neg);
extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int GOAGetLastError(int sock);
extern void NNProcessData(char *data, int len, SOCSockAddrIn *fromaddr);
extern unsigned long current_time(void);
extern void StartReport(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
struct NATNegotiator;
extern void SendPreinitPacket(struct NATNegotiator *neg);
extern void SendInitPackets(NATNegotiator *neg);
extern void SendPingPacket(struct NATNegotiator *neg);
extern void SendReportPacket(struct NATNegotiator *neg);
extern void RemoveFinishedNegotiator(int *p);

extern char gNatNegThinkNullFmt[];
extern char gNatNegThinkRemoveFmt[];
extern char gNatNegRecvBuf[];
extern char gNatNegRecvErrFmt[];
extern char gNatNegInitTimeoutFmt[];
extern char gNatNegResendInitFmt[];
extern char gNatNegNoPingFmt[];
extern char gNatNegPingTimeoutFmt[];
extern char gNatNegResendPingFmt[];
extern char gNatNegReportTimeoutFmt[];
extern char gNatNegResendReportFmt[];
extern char gNatNegBothDoneFmt[];
extern char gNatNegLingerDoneFmt[];
extern char gNatNegRemovePostFmt[];

void NegotiateThink(NATNegotiator *neg)
{
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);
    int error;

    if (neg == 0) {
        func_0217D254(7, (char *)4, 4, gNatNegThinkNullFmt);
        return;
    }

    if (neg->state == ns_canceled) {
        func_0217D254(7, (char *)2, 8, gNatNegThinkRemoveFmt, neg->cookie);
        RemoveNegotiator(neg);
        return;
    }

    if (neg->negotiateSock != -1) {
        do {
            if (!func_0217EF50(neg->negotiateSock))
                break;
            error = func_0217EC60(neg->negotiateSock, gNatNegRecvBuf, 512, 0, &saddr, &saddrlen);
            if (error == -1) {
                func_0217D254(7, 0, 8, gNatNegRecvErrFmt, neg->cookie, GOAGetLastError(neg->negotiateSock));
                break;
            }
            NNProcessData(gNatNegRecvBuf, error, &saddr);
            if (neg->state == ns_canceled)
                break;
        } while (neg->negotiateSock != -1);
    }

    if ((neg->state == ns_preinitsent || neg->state == ns_preinitack || neg->state == ns_initsent ||
         neg->state == ns_connectping) && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, 0, 8, gNatNegInitTimeoutFmt, neg->cookie);
            if ((unsigned int)neg->state <= ns_initsent)
                StartReport(neg, 2, -1, 0);
            else
                StartReport(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            func_0217D254(7, 0, 8, gNatNegResendInitFmt, neg->cookie, neg->retryCount);
            if ((unsigned int)neg->state <= ns_preinitack)
                SendPreinitPacket((struct NATNegotiator *)neg);
            else if (neg->state == ns_initsent)
                SendInitPackets(neg);
            else
                SendPingPacket((struct NATNegotiator *)neg);
        }
    }

    if (neg->state == ns_initack && current_time() > neg->retryTime) {
        func_0217D254(7, 0, 8, gNatNegNoPingFmt, neg->cookie);
        StartReport(neg, 1, -1, 0);
    }

    if (neg->state == ns_connectping && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, 0, 8, gNatNegPingTimeoutFmt, neg->cookie);
            StartReport(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            func_0217D254(7, 0, 8, gNatNegResendPingFmt, neg->cookie, neg->retryCount);
            SendPingPacket((struct NATNegotiator *)neg);
            neg->retryTime = current_time() + 700;
        }
    }

    if (neg->state == ns_reportsent && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, (char *)3, 8, gNatNegReportTimeoutFmt, neg->cookie);
            neg->state = ns_finished;
        } else {
            SendReportPacket((struct NATNegotiator *)neg);
            neg->retryCount++;
            func_0217D254(7, 0, 8, gNatNegResendReportFmt, neg->cookie, neg->retryCount);
            neg->retryTime = current_time() + 500;
        }
    }

    if (neg->state == ns_finished || neg->state == ns_reportack) {
        if (neg->sendGotRemoteData)
            func_0217D254(7, (char *)3, 8, gNatNegBothDoneFmt, neg->cookie);
        else if (current_time() > neg->retryTime)
            func_0217D254(7, (char *)3, 8, gNatNegLingerDoneFmt, neg->cookie);
        RemoveFinishedNegotiator((int *)neg);
    }

    if (neg->state == ns_canceled) {
        func_0217D254(7, (char *)2, 8, gNatNegRemovePostFmt, neg->cookie);
        RemoveNegotiator(neg);
    }
}
