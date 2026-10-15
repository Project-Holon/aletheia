/*
 * function: gpiProcessPeerAcceptingConnection
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
 *   gsUdpEngineGetPeerState  0x02181010  arm  ov009
 *   strstr  0x02094B20  arm
 *   strncmp  0x020949F4  arm
 *   gpiValueForKey  0x02193418  arm  ov009
 *   atoi  0x020964E0  arm
 *   OS_SPrintf  0x02084F40  arm
 *   strlen  0x0209477C  arm
 *   GSMD5Digest  0x021858A8  arm  ov009
 *   strcmp  0x020948E0  arm
 *   gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   gpiSendBufferToPeer  0x02189A7C  arm  ov009
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

extern int gsUdpEngineGetPeerState(unsigned int theIp, unsigned short thePort, int *thePeerState);
extern unsigned char *strstr(const unsigned char *s1, const unsigned char *s2);
extern int strncmp(const unsigned char *s1, const unsigned char *s2, unsigned int n);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern void GSMD5Digest(unsigned char *input, unsigned int len, char *output);
extern int strcmp(const char *s1, const char *s2);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiSendBufferToPeer(void **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer,
                         int *closed, int mustSend);

int gpiProcessPeerAcceptingConnection(void **connection, GPIPeer *peer)
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

    gsUdpEngineGetPeerState(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3) {
        peer->state = 0x6A;
        return 0;
    }

    str = (char *)strstr((const unsigned char *)peer->inputBuffer.buffer, (const unsigned char *)g_021A4EB8);
    if (str) {
        *str = '\0';

        str = peer->inputBuffer.buffer;
        if (strncmp((const unsigned char *)str, (const unsigned char *)g_021A4E98, 6) == 0) {
            if (!gpiValueForKey(str, g_021A4EA0, intValue, sizeof(intValue))) {
                peer->state = 0x6A;
                return 0;
            }
            pid = atoi((u32)intValue);

            if (!gpiValueForKey(peer->inputBuffer.buffer, g_021A4EA8, nick, sizeof(nick))) {
                peer->state = 0x6A;
                return 0;
            }

            if (!gpiValueForKey(peer->inputBuffer.buffer, g_021A4EB0, sig, sizeof(sig))) {
                peer->state = 0x6A;
                return 0;
            }

            OS_SPrintf(buffer, g_021A4F14, iconnection->password, iconnection->profileid, pid);
            GSMD5Digest((unsigned char *)buffer, strlen((const u8 *)buffer), sigCheck);

            if (strcmp(sig, sigCheck) != 0) {
                gpiAppendStringToBuffer((int *)connection, (int *)(&peer->outputBuffer), g_021A4EC0);
                gpiAppendStringToBuffer((int *)connection, (int *)(&peer->outputBuffer), g_021A4EB8);
                gpiSendBufferToPeer(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
                peer->state = 0x6A;
                return 0;
            }

            gpiAppendStringToBuffer((int *)connection, (int *)(&peer->outputBuffer), g_021A4EEC);
            gpiAppendStringToBuffer((int *)connection, (int *)(&peer->outputBuffer), g_021A4EB8);

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
