/*
 * function: gpiProcessPeerConnected
 * address:  0x0218E9E8
 * packet:   pkt_ov009_0218E9E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessPeerConnected (libdwcgsgp.TWL.HYB.a gpipeer.o)
 *
 * symbols:
 *   gpiSendBufferToPeer  0x02189A7C  arm  ov009
 *   gpiPeerSendMessages  0x0218E91C  arm  ov009
 *   gsiTimeNitro  0x02184098  arm  ov009
 *   gpiReadMessageFromBuffer  0x02189BE4  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   goastrdup  0x0217F1E0  arm  ov009
 *   gpiAddCallback  0x02189DFC  arm  ov009
 *   gpiSendBuddyMessage  0x021889A0  arm  ov009
 *   gpiBuddyHandleKeyRequest  0x02188B0C  arm  ov009
 *   gpiBuddyHandleKeyReply  0x02188BA0  arm  ov009
 *   gpiHandleTransferMessage  0x02192FD0  arm  ov009
 *   gpiClipBufferToPosition  0x02189D28  arm  ov009
 *   gsUdpEngineGetPeerState  0x02181010  arm  ov009
 *   gGpiPeerErrorOutOfMemory     0x021A4F1C  data
 *   gGpiPeerStatusChar     0x021A4F2C  data
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIPeerOpQueue {
    void *first;
    void *last;
    void *opList;
} GPIPeerOpQueue;

typedef struct GPIPeer_s {
    int state;                       /* 0x00 */
    int initiated;                   /* 0x04 */
    unsigned int ip;                 /* 0x08 */
    unsigned short port;             /* 0x0C */
    int profile;                     /* 0x10 */
    long timeout;                    /* 0x14 */
    int nackCount;                   /* 0x18 */
    GPIBuffer inputBuffer;           /* 0x1C */
    GPIBuffer outputBuffer;          /* 0x2C */
    struct DArrayImplementation *messages; /* 0x3C */
    GPIPeerOpQueue peerOpQueue;      /* 0x40 */
    struct GPIPeer_s *pnext;         /* 0x4C */
} GPIPeer;

typedef struct GPIProfile {
    int profileId;                   /* 0x00 */
    int userId;                      /* 0x04 */
    void *buddyStatus;               /* 0x08 */
    void *buddyStatusInfo;           /* 0x0C */
    void *cache;                     /* 0x10 */
    char *authSig;                   /* 0x14 */
    int requestCount;                /* 0x18 */
    char *peerSig;                   /* 0x1C */
    int blocked;                     /* 0x20 */
    int blockIndex;                  /* 0x24 */
    int buddyOrBlockCache;           /* 0x28 */
    int deletedLocally;              /* 0x2C */
} GPIProfile;

typedef struct GPICallback {
    void *callback;
    void *param;
} GPICallback;

typedef struct GPIConnection {
    char errorString[256];           /* 0x000 */
    int infoCaching;                 /* 0x100 */
    int infoCachingBuddyAndBlockOnly; /* 0x104 */
    int simulation;                  /* 0x108 */
    int firewall;                    /* 0x10C */
    char nick[31];                   /* 0x110 */
    char uniquenick[21];             /* 0x12F */
    char email[51];                  /* 0x144 */
    char password[31];               /* 0x177 */
    int sessKey;                     /* 0x198 */
    int userid;                      /* 0x19C */
    int profileid;                   /* 0x1A0 */
    int partnerID;                   /* 0x1A4 */
    GPICallback callbacks[9];        /* 0x1A8 */
    char pad1F0[0x3E8];
    GPIPeer *peerList;               /* 0x5D8 */
} GPIConnection;

typedef struct GPRecvBuddyMessageArg {
    int profile;
    unsigned int date;
    char *message;
} GPRecvBuddyMessageArg;

typedef struct GPRecvBuddyUTMArg {
    int profile;
    unsigned int date;
    char *message;
} GPRecvBuddyUTMArg;

extern char gGpiPeerErrorOutOfMemory[];
extern char gGpiPeerStatusChar[];

extern int gpiSendBufferToPeer(void **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer,
                         int *closed, int mustSend);
struct GPIPeer;
extern int gpiPeerSendMessages(void **connection, struct GPIPeer *peer);
extern long gsiTimeNitro(long *timer);
extern int gpiReadMessageFromBuffer(void **connection, GPIBuffer *inputBuffer, char **message, int *type, int *plen);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(int *p, int b);
extern char *goastrdup(char *src);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, void *operation, int type);
extern int gpiSendBuddyMessage(void **connection, int profileid, int type, char *message, int sendOption, void *op);
extern int gpiBuddyHandleKeyRequest(void **connection, struct GPIPeer *peer);
extern int gpiBuddyHandleKeyReply(void **connection, struct GPIPeer *peer, char *buffer);
extern void gpiHandleTransferMessage(void **connection, void *peer, int unused, char *headers, char *buffer, int len);
extern int gpiClipBufferToPosition(void **connection, GPIBuffer *buffer);
extern int gsUdpEngineGetPeerState(unsigned int theIp, unsigned short thePort, int *thePeerState);

int gpiProcessPeerConnected(void **connection, GPIPeer *peer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int aPeerState;
    int connClosed;
    GPICallback callback;
    char *buffer;
    int type;
    int messageLen;
    int result;

    if (!peer)
        return 3;

    if (peer->outputBuffer.len) {
        result = gpiSendBufferToPeer(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
        if (connClosed || result) {
            peer->state = 0x6A;
            return 0;
        }
    }

    if (!peer->outputBuffer.len) {
        {
            int __result__ = gpiPeerSendMessages(connection, (struct GPIPeer *)peer);
            if (__result__ != 0)
                return __result__;
        }
        if (peer->state == 0x6A)
            return 0;
    }

    if (peer->inputBuffer.len > 0)
        peer->timeout = gsiTimeNitro(0) + 10000;

    do {
        {
            int __result__ = gpiReadMessageFromBuffer(connection, &peer->inputBuffer, &buffer, &type, &messageLen);
            if (__result__ != 0)
                return __result__;
        }

        if (buffer) {
            switch (type) {
            case 1:
                callback = iconnection->callbacks[3];
                if (callback.callback) {
                    GPRecvBuddyMessageArg *arg;
                    arg = (GPRecvBuddyMessageArg *)gsimalloc(sizeof(GPRecvBuddyMessageArg));
                    if (arg == 0) {
                        gpiSetErrorString((int *)connection, (int)gGpiPeerErrorOutOfMemory);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = goastrdup(buffer);
                    arg->date = gsiTimeNitro(0);
                    {
                        int __result__ = gpiAddCallback(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 5:
                callback = iconnection->callbacks[4];
                if (callback.callback) {
                    GPRecvBuddyUTMArg *arg;
                    arg = (GPRecvBuddyUTMArg *)gsimalloc(sizeof(GPRecvBuddyUTMArg));
                    if (arg == 0) {
                        gpiSetErrorString((int *)connection, (int)gGpiPeerErrorOutOfMemory);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = goastrdup(buffer);
                    arg->date = gsiTimeNitro(0);
                    {
                        int __result__ = gpiAddCallback(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 0x66:
                gpiSendBuddyMessage(connection, peer->profile, 0x67, gGpiPeerStatusChar, 0, 0);
                break;

            case 0x68:
                {
                    int __result__ = gpiBuddyHandleKeyRequest(connection, (struct GPIPeer *)peer);
                    if (__result__ != 0)
                        return __result__;
                }
                break;

            case 0x69:
                {
                    int __result__ = gpiBuddyHandleKeyReply(connection, (struct GPIPeer *)peer, buffer);
                    if (__result__ != 0)
                        return __result__;
                }
                break;

            case 200:
            case 201:
            case 202:
            case 203:
            case 204:
            case 205:
            case 206:
            case 207:
            case 208:
                gpiHandleTransferMessage(connection, peer, type, peer->inputBuffer.buffer, buffer, messageLen);
                break;

            default:
                break;
            }

            gpiClipBufferToPosition(connection, &peer->inputBuffer);
        }
    } while (buffer);

    gsUdpEngineGetPeerState(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3)
        peer->state = 0x6A;

    return 0;
}
