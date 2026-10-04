/*
 * function: func_0218E6DC
 * address:  0x0218E6DC
 * packet:   pkt_ov009_0218E6DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessPeerAcceptingConnection (libdwcgsgp.TWL.HYB.a gpipeer.o)
 *
 * symbols:
 *   func_02181010  0x02181010  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_020949F4  0x020949F4  arm
 *   func_02193418  0x02193418  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_02084F40  0x02084F40  arm
 *   func_0209477C  0x0209477C  arm
 *   func_021858A8  0x021858A8  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_02189A7C  0x02189A7C  arm  ov009
 *   g_021A4EB8     0x021A4EB8  data
 *   g_021A4E98     0x021A4E98  data
 *   g_021A4EA0     0x021A4EA0  data
 *   g_021A4EA8     0x021A4EA8  data
 *   g_021A4EB0     0x021A4EB0  data
 *   g_021A4F14     0x021A4F14  data
 *   g_021A4EC0     0x021A4EC0  data
 *   g_021A4EEC     0x021A4EEC  data
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
} GPIConnection;

extern char g_021A4EB8[];
extern char g_021A4E98[];
extern char g_021A4EA0[];
extern char g_021A4EA8[];
extern char g_021A4EB0[];
extern char g_021A4F14[];
extern char g_021A4EC0[];
extern char g_021A4EEC[];

extern int func_02181010(unsigned int theIp, unsigned short thePort, int *thePeerState);
extern char *func_02094B20(const char *s1, const char *s2);
extern int func_020949F4(const char *s1, const char *s2, unsigned long n);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern unsigned long func_0209477C(const char *s);
extern void func_021858A8(unsigned char *input, unsigned int len, char *output);
extern int func_020948E0(const char *s1, const char *s2);
extern int func_0218946C(void **connection, GPIBuffer *outputBuffer, char *buffer);
extern int func_02189A7C(void **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer,
                         int *closed, int mustSend);

int func_0218E6DC(void **connection, GPIPeer *peer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
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

    str = func_02094B20(peer->inputBuffer.buffer, g_021A4EB8);
    if (str) {
        *str = '\0';

        str = peer->inputBuffer.buffer;
        if (func_020949F4(str, g_021A4E98, 6) == 0) {
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
            func_021858A8((unsigned char *)buffer, func_0209477C(buffer), sigCheck);

            if (func_020948E0(sig, sigCheck) != 0) {
                func_0218946C(connection, &peer->outputBuffer, g_021A4EC0);
                func_0218946C(connection, &peer->outputBuffer, g_021A4EB8);
                func_02189A7C(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
                peer->state = 0x6A;
                return 0;
            }

            func_0218946C(connection, &peer->outputBuffer, g_021A4EEC);
            func_0218946C(connection, &peer->outputBuffer, g_021A4EB8);

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
