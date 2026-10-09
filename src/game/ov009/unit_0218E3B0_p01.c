/*
 * file:     unit_0218E3B0_p01.c
 * unit:     yes
 * function: func_0218E3B0, func_0218E6DC, func_0218E91C, func_0218E9E8
 * address:  0x0218E3B0
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
 *   func_02193418  0x02193418  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_02084F40  0x02084F40  arm
 *   func_0209477C  0x0209477C  arm
 *   func_021858A8  0x021858A8  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   g_021A4F14     0x021A4F14  data
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_02184098  0x02184098  arm  ov009
 *   func_02189BE4  0x02189BE4  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_02189DFC  0x02189DFC  arm  ov009
 *   func_021889A0  0x021889A0  arm  ov009
 *   func_02188B0C  0x02188B0C  arm  ov009
 *   func_02188BA0  0x02188BA0  arm  ov009
 *   func_02192FD0  0x02192FD0  arm  ov009
 *   func_02189D28  0x02189D28  arm  ov009
 *   g_021A4F1C     0x021A4F1C  data
 *   g_021A4F2C     0x021A4F2C  data
 */
struct GPIPeer;
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

typedef struct GPIConnection_0218E3B0 {
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
} GPIConnection_0218E3B0;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct GPIConnection_0218E6DC {
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
} GPIConnection_0218E6DC;

struct GPIMessage {
    char *buffer;
    int size;
    int length;
    int pos;
};

struct GPIPeer {
    int state;
    char pad0[4];
    unsigned int ip;
    unsigned short port;
    char pad1[0x26];
    int connecting;
    char pad2[4];
    void *messages;
};

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

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0218F248(void **connection, GPIPeer *peer);
extern int func_02181010(unsigned int theIp, unsigned short thePort, int *thePeerState);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void func_02193734(int *p, int b);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern void func_0217EAE0(void *ptr);
extern int func_02190140(char *p);
extern void func_0218FF24(const int *p, void *profile);
extern char *func_02094B20(const char *s1, const char *s2);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int func_0218F1E0(void **connection, GPIPeer *peer);
extern int func_02189A7C(void **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer,
                         int *closed, int mustSend);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int func_020964E0(u32 a0);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern int func_0209477C(const u8 *s);
extern void func_021858A8(unsigned char *input, unsigned int len, char *output);
extern int func_020948E0(const char *s1, const char *s2);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_0218437C(int a, int b);
extern long func_02184098(long *timer);
extern int func_02189BE4(void **connection, GPIBuffer *inputBuffer, char **message, int *type, int *plen);
extern void *func_0217EAB0(unsigned long size);
extern char *func_0217F1E0(char *src);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, void *operation, int type);
extern int func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, void *op);
extern int func_02188B0C(void **connection, struct GPIPeer *peer);
extern int func_02188BA0(void **connection, struct GPIPeer *peer, char *buffer);
extern void func_02192FD0(void **connection, void *peer, int unused, char *headers, char *buffer, int len);
extern int func_02189D28(void **connection, GPIBuffer *buffer);
int func_0218E3B0(void **connection, GPIPeer *peer);
int func_0218E6DC(void **connection, GPIPeer *peer);
int func_0218E91C(void **connection, struct GPIPeer *peer);
int func_0218E9E8(void **connection, GPIPeer *peer);
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
extern char g_021A4F14[];
extern char g_021A4F1C[];
extern char g_021A4F2C[];




int func_0218E3B0(void **connection, GPIPeer *peer)
{
    GPIConnection_0218E3B0 *iconnection = (GPIConnection_0218E3B0 *)*connection;
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
                    func_0218FF24((const int *)connection, pProfile);
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




int func_0218E6DC(void **connection, GPIPeer *peer)
{
    GPIConnection_0218E6DC *iconnection = (GPIConnection_0218E6DC *)*connection;
    int aPeerState;
    char *str;
    int connClosed;
    char intValue[16];
    int pid;
    char nick[31];
    char sig[33];
    char sigCheck[33];
    char buffer[256];

    if (peer->state != 0x68)
        return 3;

    func_02181010(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3) {
        peer->state = 0x6A;
        return 0;
    }

    str = (char *)(unsigned char *)func_02094B20((const char *)((const unsigned char *)peer->inputBuffer.buffer), (const char *)((const unsigned char *)g_021A4EB8));
    if (str) {
        *str = '\0';

        str = peer->inputBuffer.buffer;
        if (func_020949F4((const unsigned char *)str, (const unsigned char *)g_021A4E98, 6) == 0) {
            if (!func_02193418(str, g_021A4EA0, intValue, sizeof(intValue))) {
                peer->state = 0x6A;
                return 0;
            }
            pid = func_020964E0((u32)intValue);

            if (!func_02193418(peer->inputBuffer.buffer, g_021A4EA8, nick, sizeof(nick))) {
                peer->state = 0x6A;
                return 0;
            }

            if (!func_02193418(peer->inputBuffer.buffer, g_021A4EB0, sig, sizeof(sig))) {
                peer->state = 0x6A;
                return 0;
            }

            func_02084F40(buffer, g_021A4F14, iconnection->password, iconnection->profileid, pid);
            func_021858A8((unsigned char *)buffer, func_0209477C((const u8 *)buffer), sigCheck);

            if (func_020948E0(sig, sigCheck) != 0) {
                func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EC0);
                func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EB8);
                func_02189A7C(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
                peer->state = 0x6A;
                return 0;
            }

            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EEC);
            func_0218946C((int *)connection, (int *)(&peer->outputBuffer), g_021A4EB8);

            peer->state = 0x69;
            peer->profile = pid;
        } else {
            peer->state = 0x6A;
            return 0;
        }

        peer->inputBuffer.len = 0;
    }

    return 0;
}



int func_0218E91C(void **connection, struct GPIPeer *peer)
{
    struct GPIMessage *message;
    int result;
    int connClosed;

    if (peer == 0)
        return 3;
    if (peer->connecting != 0)
        return 0;
    while (func_02184200(peer->messages) != 0) {
        message = (struct GPIMessage *)func_02184208(peer->messages, 0);
        result = func_02189A7C(connection, peer->ip, peer->port, (GPIBuffer *)message, &connClosed, 0);
        if (connClosed != 0 || result != 0) {
            peer->state = 0x6a;
            return 0;
        }
        if (message->pos != message->length)
            break;
        func_0218437C((int)peer->messages, 0);
    }
    return 0;
}


int func_0218E9E8(void **connection, GPIPeer *peer)
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
        result = func_02189A7C(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
        if (connClosed || result) {
            peer->state = 0x6A;
            return 0;
        }
    }

    if (!peer->outputBuffer.len) {
        {
            int __result__ = func_0218E91C(connection, (struct GPIPeer *)peer);
            if (__result__ != 0)
                return __result__;
        }
        if (peer->state == 0x6A)
            return 0;
    }

    if (peer->inputBuffer.len > 0)
        peer->timeout = func_02184098(0) + 10000;

    do {
        {
            int __result__ = func_02189BE4(connection, &peer->inputBuffer, &buffer, &type, &messageLen);
            if (__result__ != 0)
                return __result__;
        }

        if (buffer) {
            switch (type) {
            case 1:
                callback = iconnection->callbacks[3];
                if (callback.callback) {
                    GPRecvBuddyMessageArg *arg;
                    arg = (GPRecvBuddyMessageArg *)func_0217EAB0(sizeof(GPRecvBuddyMessageArg));
                    if (arg == 0) {
                        func_02193734((int *)connection, (int)g_021A4F1C);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = func_0217F1E0(buffer);
                    arg->date = func_02184098(0);
                    {
                        int __result__ = func_02189DFC(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 5:
                callback = iconnection->callbacks[4];
                if (callback.callback) {
                    GPRecvBuddyUTMArg *arg;
                    arg = (GPRecvBuddyUTMArg *)func_0217EAB0(sizeof(GPRecvBuddyUTMArg));
                    if (arg == 0) {
                        func_02193734((int *)connection, (int)g_021A4F1C);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = func_0217F1E0(buffer);
                    arg->date = func_02184098(0);
                    {
                        int __result__ = func_02189DFC(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 0x66:
                func_021889A0(connection, peer->profile, 0x67, g_021A4F2C, 0, 0);
                break;

            case 0x68:
                {
                    int __result__ = func_02188B0C(connection, (struct GPIPeer *)peer);
                    if (__result__ != 0)
                        return __result__;
                }
                break;

            case 0x69:
                {
                    int __result__ = func_02188BA0(connection, (struct GPIPeer *)peer, buffer);
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
                func_02192FD0(connection, peer, type, peer->inputBuffer.buffer, buffer, messageLen);
                break;

            default:
                break;
            }

            func_02189D28(connection, &peer->inputBuffer);
        }
    } while (buffer);

    func_02181010(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3)
        peer->state = 0x6A;

    return 0;
}
