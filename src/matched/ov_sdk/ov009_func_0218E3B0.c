/*
 * function: func_0218E3B0
 * address:  0x0218E3B0
 * packet:   pkt_ov009_0218E3B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessPeerInitiatingConnection (libdwcgsgp.TWL.HYB.a gpipeer.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0218F248  0x0218F248  arm  ov009
 *   func_02181010  0x02181010  arm  ov009
 *   func_0218FD9C  0x0218FD9C  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_0218949C  0x0218949C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02190140  0x02190140  arm  ov009
 *   func_0218FF24  0x0218FF24  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_020949F4  0x020949F4  arm
 *   func_0218F1E0  0x0218F1E0  arm  ov009
 *   func_02189A7C  0x02189A7C  arm  ov009
 *   g_021A4E50     0x021A4E50  data
 *   g_021A4E7C     0x021A4E7C  data
 *   g_021A4E98     0x021A4E98  data
 *   g_021A4EA0     0x021A4EA0  data
 *   g_021A4EA8     0x021A4EA8  data
 *   g_021A4EB0     0x021A4EB0  data
 *   g_021A4EB8     0x021A4EB8  data
 *   g_021A4EC0     0x021A4EC0  data
 *   g_021A4EC8     0x021A4EC8  data
 *   g_021A4EEC     0x021A4EEC  data
 *   g_021A4EF4     0x021A4EF4  data
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
    char pad1A8[0x430];
    GPIPeer *peerList;               /* 0x5D8 */
} GPIConnection;

extern char g_021A4E50[];
extern char g_021A4E7C[];
extern char g_021A4E98[];
extern char g_021A4EA0[];
extern char g_021A4EA8[];
extern char g_021A4EB0[];
extern char g_021A4EB8[];
extern char g_021A4EC0[];
extern char g_021A4EC8[];
extern char g_021A4EEC[];
extern char g_021A4EF4[];

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0218F248(void **connection, GPIPeer *peer);
extern int func_02181010(unsigned int theIp, unsigned short thePort, int *thePeerState);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void func_02193734(int *p, int b);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern void func_0217EAE0(void *ptr);
extern int func_02190140(char *p);
extern void func_0218FF24(void **connection, GPIProfile *profile);
extern char *func_02094B20(const char *s1, const char *s2);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int func_0218F1E0(void **connection, GPIPeer *peer);
extern int func_02189A7C(void **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer,
                         int *closed, int mustSend);

int func_0218E3B0(void **connection, GPIPeer *peer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char *str = 0;
    int connClosed;
    GPIProfile *pProfile;
    int result;
    int aPeerState;

    if (!peer)
        return 3;

    if (peer->state == 0x6A || peer->state == 0x64)
        return 3;

    switch (peer->state) {
    case 0x65:
        break;

    case 0x66:
        func_0217D254(1, (char *)3, 0x1F, g_021A4E50, peer->profile);
        {
            int __result__ = func_0218F248(connection, peer);
            if (__result__ != 0)
                return __result__;
        }
        break;

    case 0x67:
        func_02181010(peer->ip, peer->port, &aPeerState);
        if (aPeerState == 1) {
            GPIPeer *pcurr;
            int freePeerSig = 1;

            if (!func_0218FD9C(connection, peer->profile, &pProfile)) {
                func_02193734((int *)connection, (int)g_021A4E7C);
                return 3;
            }

            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4E98);
            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EA0);
            func_0218949C((int *)connection, (int *)(&peer->outputBuffer), iconnection->profileid);
            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EA8);
            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), iconnection->nick);
            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EB0);
            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), pProfile->peerSig);
            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EB8);

            for (pcurr = iconnection->peerList; pcurr; pcurr = pcurr->pnext) {
                if (pcurr->profile == peer->profile && pcurr != peer && pcurr->state <= 0x67)
                    freePeerSig = 0;
            }

            if (freePeerSig) {
                func_0217EAE0(pProfile->peerSig);
                pProfile->peerSig = 0;
                if (func_02190140((char *)pProfile))
                    func_0218FF24(connection, pProfile);
            }

            peer->state = 0x68;
        }
        break;

    case 0x68:
        if (peer->inputBuffer.buffer)
            str = func_02094B20(peer->inputBuffer.buffer, g_021A4EB8);
        if (str) {
            *str = 0;
            str = peer->inputBuffer.buffer;
            if (!func_020949F4((const u8 *)str, (const u8 *)g_021A4EC0, 7)) {
                peer->nackCount++;
                if (peer->nackCount > 1) {
                    func_02193734((int *)connection, (int)g_021A4EC8);
                    return 3;
                }
                {
                    int __result__ = func_0218F1E0(connection, peer);
                    if (__result__ != 0)
                        return __result__;
                }
            } else if (func_020949F4((const u8 *)str, (const u8 *)g_021A4EEC, 6)) {
                func_02193734((int *)connection, (int)g_021A4EF4);
                return 3;
            }
            peer->state = 0x69;
            peer->inputBuffer.len = 0;
        }
        break;
    }

    if (peer->outputBuffer.len > 0) {
        result = func_02189A7C(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
        if (connClosed || result)
            peer->state = 0x6A;
    }

    return 0;
}
