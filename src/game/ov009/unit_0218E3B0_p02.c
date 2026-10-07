/*
 * file:     unit_0218E3B0_p02.c
 * unit:     yes
 * function: func_0218F0E8, func_0218F134, func_0218F150, func_0218F1E0, func_0218F248
 * address:  0x0218F0E8
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
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_02184098  0x02184098  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   gpiAddOperation  0x0218E114  arm
 *   gpiSendGetInfo   0x0218D40C  arm
 *   func_0218FD9C  0x0218fd9c  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_02181010  0x02181010  arm   ov009
 *   func_021810CC  0x021810cc  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189d78  arm   ov009
 *   g_021A4E7C     0x021a4e7c  data
 *   g_021A4F8C     0x021a4f8c  data
 */
typedef unsigned int   u32;

typedef unsigned short u16;

struct GPIPeer_s_0218F0E8 {
    int  state;      /* +0x00 */
    int  initiated;  /* +0x04 */
    u32  ip;         /* +0x08 */
    u16  port;       /* +0x0c */
    u16  pad0e;      /* +0x0e */
    int  profile;    /* +0x10 */
    char pad14[0x4c - 0x14];
    struct GPIPeer_s_0218F0E8 *pnext; /* +0x4c */
};

typedef struct GPIConnection_0218F0E8 {
    char pad0[0x5d8];
    struct GPIPeer_s_0218F0E8 *peers;  /* +0x5d8 */
} GPIConnection_0218F0E8;

struct GPIPeer {
    int state;
    int initiated;
    char pad0[8];
    int profile;
    int timeout;
    char pad1[0x24];
    void *messages;
    int ptype;
    int gotHeader;
    int sizeReceived;
    struct GPIPeer *pnext;
};

struct GPIConnection_0218F150 {
    char pad[0x5d8];
    struct GPIPeer *peerList;
};

struct GPIOperation_s {
    char pad0[0x18];
    int  field18;    /* +0x18 */
};

struct GPIPeer_s_0218F1E0 {
    int  state;      /* +0x00 */
    int  initiated;  /* +0x04 */
    char pad08[0x10 - 0x08];
    int  profile;    /* +0x10 */
};

typedef struct {
    int state;
    int initiated;
    unsigned int ip;
    unsigned short port;
    int profile;
} GPIPeer;

typedef struct {
    char pad[0x1c];
    unsigned int ip;
    unsigned short port;
} GPIProfileInfo;

typedef struct {
    char pad[0xc];
    GPIProfileInfo *buddyStatusInfo;
} GPIProfile;

typedef struct {
    char pad[0x220];
    char initMsg[1];
} GPIConnection_0218F248;

extern void func_0217EAE0(void *p);
extern void *func_0217EAB0(unsigned long size);
extern void *func_020923B0(void *p, int c, u32 n);
extern long func_02184098(long *timer);
extern void *func_02184144(int elemSize, int numElems, void (*freeFn)(void *));
extern int gpiAddOperation(void **connection, int type, void *data,
                           struct GPIOperation_s **op, int blocking,
                           void (*callback)(void **, void *, void *),
                           void *param);
extern int gpiSendGetInfo(void **connection, int profileid, int operationid);
extern int func_0218FD9C(void *connection, int profileid, GPIProfile **pProfile);
extern void func_02193734(int *p, int b);
extern int func_02181010(unsigned int ip, unsigned short port, int *state);
extern int func_021810CC(unsigned int ip, unsigned short port, char *msg, int timeOut);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
struct GPIPeer_s_0218F0E8 *gpiGetPeerByAddr(void **connection, u32 ip, u16 port);
void func_0218F134(void **p);
struct GPIPeer *func_0218F150(void **connection, int profileid, int initiate);
int gpiPeerGetSig(void **connection, struct GPIPeer_s_0218F1E0 *peer);
int func_0218F248(void **connection, GPIPeer *peer);
extern char g_021A4E7C[];
extern char g_021A4F8C[];


struct GPIPeer_s_0218F0E8 *gpiGetPeerByAddr(void **connection, u32 ip, u16 port)
{
    GPIConnection_0218F0E8 *iconnection = (GPIConnection_0218F0E8 *)*connection;
    struct GPIPeer_s_0218F0E8 *pcurr;

    if (ip == 0 && port == 0)
        return 0;
    for (pcurr = iconnection->peers; pcurr != 0; pcurr = pcurr->pnext) {
        if (pcurr->ip == ip && pcurr->port == port)
            return pcurr;
    }
    return 0;
}


void func_0218F134(void **p)
{
    func_0217EAE0(*p);
    *p = 0;
}


/*
 * sdk:      gpiAddPeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
struct GPIPeer *func_0218F150(void **connection, int profileid, int initiate)
{
    struct GPIConnection_0218F150 *iconnection = (struct GPIConnection_0218F150 *)*connection;
    struct GPIPeer *peer;

    peer = (struct GPIPeer *)func_0217EAB0(sizeof(struct GPIPeer));
    if (peer == 0)
        return 0;
    func_020923B0(peer, 0, sizeof(struct GPIPeer));
    peer->state = 0x64;
    peer->initiated = initiate;
    peer->profile = profileid;
    peer->timeout = func_02184098(0) + 10000;
    peer->pnext = iconnection->peerList;
    peer->messages = func_02184144(0x18, 0, (void (*)(void *))func_0218F134);
    iconnection->peerList = peer;
    peer->gotHeader = 0;
    peer->sizeReceived = 0;
    peer->ptype = 0;
    return peer;
}


int gpiPeerGetSig(void **connection, struct GPIPeer_s_0218F1E0 *peer)
{
    struct GPIOperation_s *operation;
    int result;

    result = gpiAddOperation(connection, 2, 0, &operation, 0, 0, 0);
    if (result != 0)
        return result;
    result = gpiSendGetInfo(connection, peer->profile, operation->field18);
    if (result == 0) {
        peer->state = 0x65;
        return 0;
    }
    return result;
}


/*
 * sdk:      gpiPeerStartConnect (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
int func_0218F248(void **connection, GPIPeer *peer)
{
    GPIProfile *profile;
    GPIConnection_0218F248 *iconnection;
    int anError;
    int result;
    int aPeerState;

    iconnection = (GPIConnection_0218F248 *)*connection;
    if (!func_0218FD9C(connection, peer->profile, &profile)) {
        func_02193734((int *)connection, (int)g_021A4E7C);
        return 3;
    }
    if (profile->buddyStatusInfo) {
        func_02181010(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port, &aPeerState);
        if (aPeerState != 1 || aPeerState != 0) {
            anError = func_021810CC(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port,
                                    iconnection->initMsg, 10000);
            if (anError != 5) {
                func_02193710((int *)connection, 5, (int)g_021A4F8C);
                result = 3;
                func_02189D78((int *)connection, result, 0);
                return result;
            }
        }
        peer->ip = profile->buddyStatusInfo->ip;
        peer->port = profile->buddyStatusInfo->port;
    }
    peer->state = 0x67;
    return 0;
}
