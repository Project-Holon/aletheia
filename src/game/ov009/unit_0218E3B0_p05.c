/*
 * file:     unit_0218E3B0_p05.c
 * unit:     yes
 * function: func_0218ED58, func_0218EE48, func_0218EEC0, func_0218EF04, func_0218EFEC, func_0218F0B8, func_0218F0E8, func_0218F134, func_0218F150, func_0218F1E0, func_0218F248, func_0218F350, func_0218F4BC, func_0218F51C
 * address:  0x0218ED58
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
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02189DFC  0x02189DFC  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0218F900  0x0218F900  arm  ov009
 *   g_021A4F30  0x021A4F30  data
 *   gpiProcessPeerInitiatingConnection  0x0218E3B0  arm
 *   gpiProcessPeerAcceptingConnection   0x0218E6DC  arm
 *   gpiProcessPeerConnected             0x0218E9E8  arm
 *   gpiCheckTimedOutPeerOperations      0x0218ED58  arm
 *   gsifree     0x0217EAE0  arm
 *   ArrayFree   0x021841B0  arm
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_021888C0  0x021888C0  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_0218EEC0  0x0218EEC0  arm  ov009
 *   g_021A4F4C  0x021A4F4C  data
 *   func_021814EC  0x021814EC  arm  ov009
 *   func_0218EE48  0x0218EE48  arm  ov009
 *   func_02184098  0x02184098  arm  ov009
 *   g_021A4F70  0x021A4F70  data
 *   func_020923B0  0x020923B0  arm
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
 *   func_0209477C  0x0209477c  arm
 *   func_0218946C  0x0218946c  arm   ov009
 *   func_0218949C  0x0218949c  arm   ov009
 *   func_021893C8  0x021893c8  arm   ov009
 *   func_0218934C  0x0218934c  arm   ov009
 *   func_02184234  0x02184234  arm   ov009
 *   g_021A4FC4     0x021a4fc4  data
 *   g_021A4FC8     0x021a4fc8  data
 *   g_021A4FD0     0x021a4fd0  data
 *   OS_SPrintf             0x02084F40  arm
 *   gpiSendOrBufferString  0x02189750  arm
 *   g_021A4FD8             0x021A4FD8  data
 *   func_02084F40  0x02084F40  arm
 *   func_02189750  0x02189750  arm  ov009
 *   func_0218964C  0x0218964C  arm  ov009
 *   func_02189644  0x02189644  arm  ov009
 *   g_021A4FEC  0x021A4FEC  data
 *   g_021A4FF0  0x021A4FF0  data
 */
struct DArrayImplementation;
struct GPIPeer_s;
struct GPICallback {
    void *callback;
    void *param;
};

struct GPIPeerOp {
    int type;
    void *param;
    void *callback;
    struct GPIPeerOp *pnext;
    int state;
    unsigned int timeout;
};

struct GPIPeer_0218ED58 {
    char pad0[0x10];
    int profile;
    char pad1[0x30];
    struct GPIPeerOp *first;
    struct GPIPeerOp *last;
};

struct GetBuddyStatusInfoKeysArg {
    int profileid;
    int a;
    int b;
    int c;
};

struct GPIPeer_s_0218EE48 {
    int  state;      /* +0x00 */
    int  initiated;  /* +0x04 */
};

struct GPIBuffer {
    char *data;  /* +0x00 */
    int   len;   /* +0x04 */
    int   size;  /* +0x08 */
    int   pad;   /* +0x0c */
};

struct GPIPeer_s_0218EEC0 {
    char pad0[0x1c];
    struct GPIBuffer inputBuffer;   /* +0x1c */
    struct GPIBuffer outputBuffer;  /* +0x2c */
    struct DArrayImplementation *messages; /* +0x3c */
};

struct GPIMessage {
    char *buffer;
    char pad0[0xc];
    int type;
    int start;
};

struct GPIPeer_0218E3B0 {
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
    struct GPIPeer_0218E3B0 *pnext;
};

struct GPIConnection {
    char pad[0x5d8];
    struct GPIPeer_0218E3B0 *peerList;
};

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

struct GPIPeer_0 {
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
    struct GPIPeer_0 *pnext;
};

struct GPIConnection_0218F150 {
    char pad[0x5d8];
    struct GPIPeer_0 *peerList;
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
} GPIPeer_0;

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

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct {
    GPIBuffer buffer;
    int type;
    int start;
} GPIMessage;

typedef struct {
    char pad[0x14];
    int timeout;
    char pad2[0x24];
    void *messages;
} GPIPeer_0218E3B0;

typedef unsigned char  u8;

struct GPITransferID_s {
    int          profileid;  /* +0x00 */
    unsigned int count;      /* +0x04 */
    unsigned int time;       /* +0x08 */
};

extern unsigned int func_0217F264(void);
extern void *func_0217EAB0(unsigned long size);
extern int func_02189DFC(void **connection, struct GPICallback callback, void *arg, void *operation, int type);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0218F900(struct GPIPeer_0218ED58 *peer, struct GPIPeerOp *operation);
extern int  gpiProcessPeerInitiatingConnection(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern int  gpiProcessPeerAcceptingConnection(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern int  gpiProcessPeerConnected(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern void gpiCheckTimedOutPeerOperations(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern void gsifree(void *ptr);
extern void ArrayFree(struct DArrayImplementation *array);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_021888C0(void **connection, int profileid, int type, char *message);
extern void func_0218437C(int a, int b);
extern void func_0218EEC0(void **connection, struct GPIPeer_0218E3B0 *peer);
extern int func_021814EC(void);
extern int func_0218EE48(void **connection, struct GPIPeer_0218E3B0 *peer);
extern long func_02184098(long *timer);
extern void func_0217EAE0(void *p);
extern void *func_020923B0(void *p, int c, u32 n);
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
extern int func_0209477C(const u8 *s);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern int func_021893C8(int *connection, int *buffer, int src, int n);
extern int func_0218934C(int *connection, int *buffer, int c);
extern void func_02184234(void *array, void *elem);
extern int  OS_SPrintf(char *dst, char *fmt, ...);
extern int  gpiSendOrBufferString(void **connection, struct GPIPeer_s *peer,
                                  char *string);
extern int func_02084F40(char *dst, char *fmt, ...);
extern int func_02189750(void **connection, struct GPIPeer_0218E3B0 *peer, char *string);
extern int func_0218964C(void **connection, struct GPIPeer_0218E3B0 *peer, char *string, int stringLen);
extern int func_02189644();
void func_0218ED58(void **connection, struct GPIPeer_0218ED58 *peer);
void gpiDestroyPeer(void **connection, struct GPIPeer_s_0218EEC0 *peer);
/* * sdk: gpiRemovePeer (libdwcgsgp.TWL.HYB.a(gpipeer.o)) */ void func_0218EF04(void **connection, struct GPIPeer_0218E3B0 *peer);
/* * sdk: gpiProcessPeers (libdwcgsgp.TWL.HYB.a(gpipeer.o)) */ int func_0218EFEC(void **connection);
/* * Walks the list hanging off the +0x5d8 member of the object and returns the * node whose +0x10 word equals v, or 0 when the list runs out. */ char *func_0218F0B8(void **p, int v);
struct GPIPeer_s_0218F0E8 *gpiGetPeerByAddr(void **connection, u32 ip, u16 port);
void func_0218F134(void **p);
/* * sdk: gpiAddPeer (libdwcgsgp.TWL.HYB.a(gpipeer.o)) */ struct GPIPeer_0 *func_0218F150(void **connection, int profileid, int initiate);
int gpiPeerGetSig(void **connection, struct GPIPeer_s_0218F1E0 *peer);
/* * sdk: gpiPeerStartConnect (libdwcgsgp.TWL.HYB.a gpipeer.o) */ int func_0218F248(void **connection, GPIPeer_0 *peer);
/* * sdk: gpiPeerAddMessage (libdwcgsgp.TWL.HYB.a gpipeer.o) */ int func_0218F350(void **connection, GPIPeer_0218E3B0 *peer, int type, char *message);
int gpiPeerStartTransferMessage(void **connection, struct GPIPeer_s *peer, int type, struct GPITransferID_s *transferID);
/* * Byte-correct (216/216), 8 of 8 relocation sites resolved. * * The two pool words at the end are in the order the code first names them: * the `ldreq` at +0028 (the `message == 0` default) addresses +00D0, which the * image fills with 0x021A4FEC -- the compiler's 1-byte empty string @15025 -- * and the `ldr` at +0044 (OS_SPrintf's format) addresses +00D4 = 0x021A4FF0, * "\len\%d\msg\\\n", @15026. Spelling them the other way round still * reproduces every instruction, because the pool slots are the same either * way, but the two words come out exchanged and `sole-ref/self`, which * compares the word it is about to write with the ROM word at the site, * refuses both. Both literals are attested by the overlay's own image * (ov009 window, the only two candidate windows holding them are ov009 and * ov021 and only ov009's bytes are read, the function under test living there). * * The DWARF carries three separate `enum _GPResult __result__` locals, all in * r0, one per if-chain, so the original almost certainly declared a result in * each of three sibling blocks rather than reusing one. The single `result` * below colours identically -- r0 in all three, r4 never live across a call -- * and reproduces all 216 bytes, so the extra scopes buy nothing here. * * sdk: gpiPeerFinishTransferMessage (libdwcgsgp.TWL.HYB.a(gpipeer.o)) */ int func_0218F51C(void **connection, struct GPIPeer_0218E3B0 *peer, char *message, int len);
extern char g_021A4F30[];
extern char g_021A4F4C[];
extern char g_021A4F70[];
extern char g_021A4E7C[];
extern char g_021A4F8C[];
extern char g_021A4FC4[];
extern char g_021A4FC8[];
extern char g_021A4FD0[];
extern char g_021A4FD8[];
extern char g_021A4FEC[];   /* "" -- the default when message is 0 */
extern char g_021A4FF0[];   /* "\len\%d\msg\\\n" -- OS_SPrintf's format */




void func_0218ED58(void **connection, struct GPIPeer_0218ED58 *peer)
{
    struct GetBuddyStatusInfoKeysArg *arg;
    struct GPICallback callback;
    struct GPIPeerOp *anIterator = peer->first;

    if (peer == 0)
        return;
    for (; anIterator != 0 && anIterator != peer->last; anIterator = anIterator->pnext) {
        if (anIterator->type == 2)
            continue;
        if (func_0217F264() <= anIterator->timeout)
            continue;
        if (anIterator->callback == 0)
            continue;
        if (anIterator->state == 0x68) {
            arg = (struct GetBuddyStatusInfoKeysArg *)func_0217EAB0(sizeof(struct GetBuddyStatusInfoKeysArg));
            callback.callback = anIterator->callback;
            callback.param = anIterator->param;
            arg->a = 0;
            arg->c = 0;
            arg->b = 0;
            arg->profileid = peer->profile;
            func_02189DFC(connection, callback, arg, 0, 0);
        }
        func_0217D254(1, (char *)4, 8, g_021A4F30);
        func_0218F900(peer, anIterator);
    }
}





static int gpiProcessPeer(void **connection, struct GPIPeer_s_0218EE48 *peer)
{
    int result = 0;

    if (peer->state == 100)
        return 3;
    if (peer->state != 0x69) {
        if (peer->initiated != 0)
            result = gpiProcessPeerInitiatingConnection(connection, peer);
        else
            result = gpiProcessPeerAcceptingConnection(connection, peer);
    }
    if (result == 0 && peer->state == 0x69) {
        result = gpiProcessPeerConnected(connection, peer);
        gpiCheckTimedOutPeerOperations(connection, peer);
    }
    return result;
}





void gpiDestroyPeer(void **connection, struct GPIPeer_s_0218EEC0 *peer)
{
    gsifree(peer->inputBuffer.data);
    peer->inputBuffer.data = 0;
    gsifree(peer->outputBuffer.data);
    peer->outputBuffer.data = 0;
    if (peer->messages != 0) {
        ArrayFree(peer->messages);
        peer->messages = 0;
    }
    gsifree(peer);
}





/*
 * sdk:      gpiRemovePeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
void func_0218EF04(void **connection, struct GPIPeer_0218E3B0 *peer)
{
    struct GPIMessage *message;
    struct GPIConnection *iconnection;
    struct GPIPeer_0218E3B0 *pprev;

    iconnection = (struct GPIConnection *)*connection;
    if (peer == 0 || (pprev = iconnection->peerList) == 0)
        return;
    if (pprev == peer) {
        iconnection->peerList = peer->pnext;
    } else {
        while (pprev->pnext != peer) {
            if (pprev->pnext == 0) {
                func_0217D254(1, (char *)4, 1, g_021A4F4C);
                return;
            }
            pprev = pprev->pnext;
        }
        pprev->pnext = peer->pnext;
    }
    while (func_02184200(peer->messages) != 0) {
        message = (struct GPIMessage *)func_02184208(peer->messages, 0);
        if (message->type < 100)
            func_021888C0(connection, peer->profile, message->type, message->buffer + message->start);
        func_0218437C((int)peer->messages, 0);
    }
    func_0218EEC0(connection, peer);
}





/*
 * sdk:      gpiProcessPeers (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
int func_0218EFEC(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    struct GPIPeer_0218E3B0 *nextPeer;
    struct GPIPeer_0218E3B0 *peer;
    int result;

    func_021814EC();
    peer = iconnection->peerList;
    while (peer != 0) {
        nextPeer = peer->pnext;
        if (peer->state == 0x6a) {
            func_0217D254(1, (char *)4, 8, g_021A4F70, peer->profile);
            func_0218EF04(connection, peer);
        } else {
            result = func_0218EE48(connection, peer);
            if (peer->state == 0x6a || result != 0 || func_02184098(0) > peer->timeout) {
                func_0217D254(1, (char *)4, 8, g_021A4F70, peer->profile);
                func_0218EF04(connection, peer);
            }
        }
        peer = nextPeer;
    }
    return 0;
}




/*
 * Walks the list hanging off the +0x5d8 member of the object and returns the
 * node whose +0x10 word equals v, or 0 when the list runs out.
 */
char *func_0218F0B8(void **p, int v)
{
    char *q = *(char **)(*(char **)p + 0x5d8);

    while (q != 0) {
        if (*(int *)(q + 0x10) == v) return q;
        q = *(char **)(q + 0x4c);
    }
    return 0;
}




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
struct GPIPeer_0 *func_0218F150(void **connection, int profileid, int initiate)
{
    struct GPIConnection_0218F150 *iconnection = (struct GPIConnection_0218F150 *)*connection;
    struct GPIPeer_0 *peer;

    peer = (struct GPIPeer_0 *)func_0217EAB0(sizeof(struct GPIPeer_0));
    if (peer == 0)
        return 0;
    func_020923B0(peer, 0, sizeof(struct GPIPeer_0));
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
int func_0218F248(void **connection, GPIPeer_0 *peer)
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



/*
 * sdk:      gpiPeerAddMessage (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
int func_0218F350(void **connection, GPIPeer_0218E3B0 *peer, int type, char *message)
{
    int len;

    if (peer == 0)
        return 3;
    if (message == 0)
        return 3;
    len = func_0209477C((const u8 *)message);
    {
        GPIMessage gpiMessage = {0};
        gpiMessage.type = type;
        {
            int __result__ = func_0218946C((int *)connection, (int *)(&gpiMessage.buffer), g_021A4FC4);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C((int *)connection, (int *)(&gpiMessage.buffer), type);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C((int *)connection, (int *)(&gpiMessage.buffer), g_021A4FC8);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C((int *)connection, (int *)(&gpiMessage.buffer), len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C((int *)connection, (int *)(&gpiMessage.buffer), g_021A4FD0);
            if (__result__ != 0)
                return __result__;
        }
        gpiMessage.start = gpiMessage.buffer.len;
        {
            int __result__ = func_021893C8((int *)connection, (int *)(&gpiMessage.buffer), (int)message, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218934C((int *)connection, (int *)(&gpiMessage.buffer), 0);
            if (__result__ != 0)
                return __result__;
        }
        func_02184234(peer->messages, &gpiMessage);
        peer->timeout = func_02184098(0) + 10000;
        return 0;
    }
}



int gpiPeerStartTransferMessage(void **connection, struct GPIPeer_s *peer,
                                int type, struct GPITransferID_s *transferID)
{
    char buffer[64];
    int profileid;
    unsigned int count;
    unsigned int time;

    profileid = transferID->profileid;
    count = transferID->count;
    time = transferID->time;
    if (transferID == 0)
        return 3;
    OS_SPrintf(buffer, g_021A4FD8, type, profileid, count, time);
    return gpiSendOrBufferString(connection, peer, buffer);
}



/*
 * Byte-correct (216/216), 8 of 8 relocation sites resolved.
 *
 * The two pool words at the end are in the order the code first names them:
 * the `ldreq` at +0028 (the `message == 0` default) addresses +00D0, which the
 * image fills with 0x021A4FEC -- the compiler's 1-byte empty string @15025 --
 * and the `ldr` at +0044 (OS_SPrintf's format) addresses +00D4 = 0x021A4FF0,
 * "\len\%d\msg\\\n", @15026.  Spelling them the other way round still
 * reproduces every instruction, because the pool slots are the same either
 * way, but the two words come out exchanged and `sole-ref/self`, which
 * compares the word it is about to write with the ROM word at the site,
 * refuses both.  Both literals are attested by the overlay's own image
 * (ov009 window, the only two candidate windows holding them are ov009 and
 * ov021 and only ov009's bytes are read, the function under test living there).
 *
 * The DWARF carries three separate `enum _GPResult __result__` locals, all in
 * r0, one per if-chain, so the original almost certainly declared a result in
 * each of three sibling blocks rather than reusing one.  The single `result`
 * below colours identically -- r0 in all three, r4 never live across a call --
 * and reproduces all 216 bytes, so the extra scopes buy nothing here.
 *
 * sdk:      gpiPeerFinishTransferMessage (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
int func_0218F51C(void **connection, struct GPIPeer_0218E3B0 *peer, char *message, int len)
{
    char buffer[32];
    int result;

    if (peer == 0)
        return 3;
    if (message == 0)
        message = g_021A4FEC;
    if (len == -1)
        len = func_0209477C((const u8 *)message);
    func_02084F40(buffer, g_021A4FF0, len);
    result = func_02189750(connection, peer, buffer);
    if (result != 0)
        return result;
    result = func_0218964C(connection, peer, message, len);
    if (result != 0)
        return result;
    result = func_02189644(connection, peer, 0);
    if (result != 0)
        return result;
    peer->timeout = func_02184098(0) + 10000;
    return 0;
}
