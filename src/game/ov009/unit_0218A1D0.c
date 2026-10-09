/*
 * file:     unit_0218A1D0.c
 * unit:     yes
 * function: func_0218A1D0, func_0218A238, func_0218A624, func_0218A830, func_0218AC4C, func_0218AE9C, func_0218B5A0, func_0218B618, func_0218B760, func_0218B914
 * address:  0x0218A1D0
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
 *   func_02094694  0x02094694  arm
 *   g_021A4618     0x021A4618  data  ov009
 *   func_02094860  0x02094860  arm
 *   func_02180E48  0x02180E48  arm   ov009
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_02180E58  0x02180E58  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   func_0218158C  0x0218158C  arm   ov009
 *   func_021815C8  0x021815C8  arm   ov009
 *   func_0217EB18  0x0217EB18  arm   ov009
 *   func_0217EE50  0x0217EE50  arm   ov009
 *   func_0217ED38  0x0217ED38  arm   ov009
 *   func_0215F650  0x0215F650  arm   ov009
 *   func_0217EC08  0x0217EC08  arm   ov009
 *   func_0217ED54  0x0217ED54  arm   ov009
 *   func_0218F5F4  0x0218F5F4  arm   ov009
 *   func_0218F880  0x0218F880  arm   ov009
 *   func_0218F65C  0x0218F65C  arm   ov009
 *   func_0218F7B8  0x0218F7B8  arm   ov009
 *   g_021A4658     0x021A4658  data
 *   g_021A4664     0x021A4664  data
 *   g_021A467C     0x021A467C  data
 *   g_021A46A0     0x021A46A0  data
 *   g_021A46D4     0x021A46D4  data
 *   g_021A46FC     0x021A46FC  data
 *   g_021A4734     0x021A4734  data
 *   g_021A4760     0x021A4760  data
 *   g_021A4788     0x021A4788  data
 *   g_021A45D8     0x021A45D8  data
 *   g_021A47BC     0x021A47BC  data
 *   g_021A47F0     0x021A47F0  data
 *   func_021867E8  0x021867E8  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_0219327C  0x0219327C  arm   ov009
 *   func_0217F21C  0x0217F21C  arm   ov009
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_020923B0  0x020923B0  arm
 *   func_0218E114  0x0218E114  arm   ov009
 *   func_0218DD88  0x0218DD88  arm   ov009
 *   func_02186E9C  0x02186E9C  arm   ov009
 *   g_021A4818     0x021A4818  data
 *   g_021A482C     0x021A482C  data
 *   func_0209477C  0x0209477C  arm
 *   func_021858A8  0x021858A8  arm   ov009
 *   func_02084F40  0x02084F40  arm
 *   func_0218FF98  0x0218FF98  arm   ov009
 *   func_0218946C  0x0218946C  arm   ov009
 *   func_0218949C  0x0218949C  arm   ov009
 *   g_021A483C     0x021A483C  data
 *   g_021A4840     0x021A4840  data
 *   g_021A4848     0x021A4848  data
 *   g_021A4850     0x021A4850  data
 *   g_021A4860     0x021A4860  data
 *   g_021A4894     0x021A4894  data
 *   g_021A489C     0x021A489C  data
 *   g_021A48A8     0x021A48A8  data
 *   g_021A48B4     0x021A48B4  data
 *   g_021A48C4     0x021A48C4  data
 *   g_021A48CC     0x021A48CC  data
 *   g_021A48D0     0x021A48D0  data
 *   g_021A48DC     0x021A48DC  data
 *   g_021A48E8     0x021A48E8  data
 *   g_021A48F4     0x021A48F4  data
 *   g_021A4900     0x021A4900  data
 *   g_021A490C     0x021A490C  data
 *   g_021A4914     0x021A4914  data
 *   g_021A4920     0x021A4920  data
 *   g_021ACEFC     0x021ACEFC  data
 *   g_021A492C     0x021A492C  data
 *   g_021A493C     0x021A493C  data
 *   g_021A494C     0x021A494C  data
 *   g_021A4954     0x021A4954  data
 *   g_021A495C     0x021A495C  data
 *   func_02193748  0x02193748  arm   ov009
 *   func_0217F790  0x0217F790  arm   ov009
 *   func_0217F7AC  0x0217F7AC  arm   ov009
 *   func_0217FA90  0x0217FA90  arm   ov009
 *   g_021A4964     0x021A4964  data
 *   g_021A4970     0x021A4970  data
 *   g_021A4978     0x021A4978  data
 *   g_021A4980     0x021A4980  data
 *   g_021A4990     0x021A4990  data
 *   func_0219329C  0x0219329C  arm   ov009
 *   func_0218FEF0  0x0218FEF0  arm   ov009
 *   func_02193418  0x02193418  arm   ov009
 *   func_020964E0  0x020964E0  arm
 *   func_020949F4  0x020949F4  arm
 *   func_020923F0  0x020923F0  arm
 *   func_0218FCD8  0x0218FCD8  arm   ov009
 *   func_02189DFC  0x02189DFC  arm   ov009
 *   func_0218E240  0x0218E240  arm   ov009
 *   g_021A499C     0x021A499C  data
 *   g_021A49A4     0x021A49A4  data
 *   g_021A49AC     0x021A49AC  data
 *   g_021A49DC     0x021A49DC  data
 *   g_021A49E4     0x021A49E4  data
 *   g_021A4A14     0x021A4A14  data
 *   g_021A4A1C     0x021A4A1C  data
 *   g_021A4A28     0x021A4A28  data
 *   g_021A4A30     0x021A4A30  data
 *   g_021A4A38     0x021A4A38  data
 *   func_02193488  0x02193488  arm   ov009
 *   g_021A4A58     0x021A4A58  data  ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_021841B0  0x021841b0  arm   ov009
 *   func_0218FF24  0x0218ff24  arm   ov009
 *   func_0218998C  0x0218998C  arm   ov009
 *   func_0217EB9C  0x0217EB9C  arm   ov009
 *   func_0217EB2C  0x0217EB2C  arm   ov009
 *   func_02181748  0x02181748  arm   ov009
 *   func_02181828  0x02181828  arm   ov009
 *   func_02181874  0x02181874  arm   ov009
 *   func_02181530  0x02181530  arm   ov009
 *   func_0218EEC0  0x0218EEC0  arm   ov009
 *   func_0218FFFC  0x0218FFFC  arm   ov009
 *   g_021A4A80     0x021A4A80  data
 *   g_021A4A94     0x021A4A94  data
 */
struct GPIOperation;
typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    GPICallback callback;
    int state;
    int id;
    int result;
    struct GPIOperation_s *pnext;
} GPIOperation;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
} SOCHostEnt;

typedef struct GPIConnection {
    char pad0[0x10c];
    int firewall;
    char pad110[0x1f0 - 0x110];
    int cmSocket;
    int connectState;
    char pad1f8[0x220 - 0x1f8];
    char mHeader[16];
    unsigned short peerPort;
} GPIConnection;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct GPIConnectData {
    char serverChallenge[128];
    char userChallenge[33];
    char passwordHash[33];
    char authtoken[256];
    char partnerchallenge[256];
    char cdkey[65];
    int newuser;
} GPIConnectData;

typedef struct GPIConnection_0218A624 {
    char pad0[0x10c];
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    char pad198[0x1f4 - 0x198];
    int connectState;
} GPIConnection_0218A624;

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIProfile {
    int profileId;
    int userId;
} GPIProfile;

typedef struct GPIConnection_0218A830 {
    char pad0[0x100];
    int infoCaching;
    char pad104[0x10c - 0x104];
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    int sessKey;
    int userid;
    int profileid;
    int partnerID;
    char pad1a8[0x210 - 0x1a8];
    GPIBuffer outputBuffer;
    char pad220[0x230 - 0x220];
    unsigned short peerPort;
    char pad232[0x60c - 0x232];
    int productID;
    int namespaceID;
    char pad614[0x630 - 0x614];
    int quietModeFlags;
} GPIConnection_0218A830;

typedef struct GPIConnection_0218AC4C {
    char pad0[0x110];
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    int sessKey;
    int userid;
    int profileid;
    int partnerID;
    char pad1a8[0x210 - 0x1a8];
    GPIBuffer outputBuffer;
    char pad220[0x60c - 0x220];
    int productID;
    int namespaceID;
} GPIConnection_0218AC4C;

typedef struct GPIProfile_0218AE9C {
    int profileId;
    int userId;
    void *buddyStatus;
    void *buddyStatusInfo;
    void *cache;
    char *authSig;
    int requestCount;
    char *peerSig;
    int blocked;
    int blockIndex;
    int buddyOrBlockCache;
    int deletedLocally;
} GPIProfile_0218AE9C;

typedef struct GPConnectResponseArg {
    int result;
    int profile;
    char uniquenick[21];
} GPConnectResponseArg;

typedef struct GPIConnection_0218AE9C {
    char errorString[256];
    int infoCaching;
    int infoCachingBuddyAndBlockOnly;
    int simulation;
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    int sessKey;
    int userid;
    int profileid;
    int partnerID;
    GPICallback callbacks[9];
    int cmSocket;
    int connectState;
    GPIBuffer socketBuffer;
    char *inputBuffer;
    int inputBufferSize;
    GPIBuffer outputBuffer;
    char mHeader[16];
    unsigned short peerPort;
    int nextOperationID;
    int numSearches;
    int lastStatusState;
    unsigned int hostIp;
    unsigned int hostPrivateIp;
    unsigned short queryPort;
    unsigned short hostPort;
    unsigned int sessionFlags;
    char richStatus[256];
    char gameType[33];
    char gameVariant[33];
    char gameMapName[33];
    void *extendedInfoKeys;
    char lastStatusString[256];
    char lastLocationString[256];
    int errorCode;
    int fatalError;
    void *diskCache;
    GPIOperation *operationList;
    char profileList[16];
    void *peerList;
    void *callbackList;
    void *lastCallback;
    GPIBuffer updateproBuffer;
    GPIBuffer updateuiBuffer;
    void *transfers;
    unsigned int nextTransferID;
    int productID;
    int namespaceID;
    char loginTicket[25];
    int quietModeFlags;
    unsigned int kaTransmit;
} GPIConnection_0218AE9C;

typedef struct GPIConnection_0218B5A0 {
    unsigned char pad[0x1F0];
    int socket;
    int state;
} GPIConnection_0218B5A0;

typedef struct {
    int f0;
    int f4;
    char *f8;
    char *fC;
} GPIBuddyStatus;

typedef struct {
    int f0;
    int f4;
    char *f8;
    char *fC;
    char *f10;
    char *f14;
    char pad[0x20];
    void *f38;
} GPIBuddyStatusInfo;

typedef struct {
    int f0;
    int f4;
    GPIBuddyStatus *buddyStatus;
    GPIBuddyStatusInfo *statusInfo;
    int f10;
    char *f14;
    int f18;
    char *f1C;
    int f20;
    int f24;
    int f28;
} GPIProfile_0218B618;

typedef struct {
    char pad[0x104];
    int state;
} GPIConnection_0218B618;

typedef struct GPIPeer_s {
    char pad0[0x4c];
    struct GPIPeer_s *pnext;
} GPIPeer;

typedef struct GPIConnection_0218B760 {
    char pad0[0x198];
    int sessKey;
    int userid;
    int profileid;
    char pad1a4[0x1f0 - 0x1a4];
    int cmSocket;
    int connectState;
    GPIBuffer socketBuffer;
    char *inputBuffer;
    int inputBufferSize;
    GPIBuffer outputBuffer;
    char mHeader[16];
    char pad230[0x5c4 - 0x230];
    void *operationList;
    char pad5c8[0x5d8 - 0x5c8];
    GPIPeer *peerList;
    char pad5dc[0x5e4 - 0x5dc];
    GPIBuffer updateproBuffer;
    GPIBuffer updateuiBuffer;
} GPIConnection_0218B760;

typedef struct GPIConnection_0218B914 {
    unsigned char pad0[0x1A4];
    int f1A4;
    unsigned char pad1[0x208 - 0x1A8];
    char *f208;
    unsigned char pad2[0x610 - 0x20C];
    int f610;
} GPIConnection_0218B914;

extern unsigned int func_02094694();
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern int func_02180E48(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02180E58(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize, void (*theAppNetworkError)(int, void *), void (*theAppConnected)(unsigned int, unsigned short, int, int, void *), void (*theAppClosed)(unsigned int, unsigned short, int, void *), void (*theAppPing)(unsigned int, unsigned short, unsigned int, void *), void (*theAppReceive)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), int (*theAppUnownMsg)(unsigned int, unsigned short, unsigned char *, unsigned int, void *), void (*theAppConnectAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *), void *theAppUserData);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern unsigned short func_0218158C(void);
extern int func_021815C8(char *theInitMsg, char *theHeader, void (*theMsgHandlerError)(int, void *), void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *), void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *), void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *), void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), void *theUserData);
extern int func_0217EB18(int pf, int type, int protocol);
extern int func_0217EE50(int sock, int isblocking);
extern int func_0217ED38(int a);
extern SOCHostEnt *func_0215F650(char *name);
extern int func_0217EC08(int sock, void *addr, int len);
extern int func_0217ED54(int sock);
extern void func_0218F5F4(void);
extern void func_0218F880(void);
extern void func_0218F65C(unsigned int ip, unsigned short port, unsigned char *message, int messageLength, int unused, void *userData);
extern void func_0218F7B8(unsigned int ip, unsigned short port, int unused, int rejected, void *userData);
extern int func_021867E8(void **connection);
extern void func_02193734(int *p, int b);
extern void func_0219327C(char *p, int b, int n);
extern char *func_0217F21C(char *string);
extern void *func_0217EAB0(unsigned long size);
extern void *func_020923B0(void *dst, int val, unsigned long len);
extern int func_0218E114(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int func_0218DD88(void **connection, const struct GPIOperation_s *operation);
extern int func_02186E9C(void **connection, int blockingOperationID);
extern int func_0209477C(const u8 *s);
extern void func_021858A8(unsigned char *input, unsigned int len, char *output);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern int func_0218FF98(void **connection, char *nick, char *email, GPIProfile **profile);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern void func_02193748(const char *plaintext, char *encoded);
extern void func_0217F790(unsigned long seed);
extern unsigned int func_0217F7AC(unsigned int min, unsigned int max);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
extern int func_0219329C(int *connection, const char *input, int fatal);
extern void func_0218FEF0(void **connection, int profileid);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int func_020964E0(u32 a0);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern GPIProfile_0218AE9C *func_0218FCD8(void **connection, int id);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, struct GPIOperation *operation);
extern int func_02193488(int *connection, int sock, int *state);
extern void func_0217EAE0(void *ptr);
extern void func_021841B0(void *array);
extern void func_0218FF24(const int *p, void *profile);
extern int func_0218998C(void **connection, int sock, GPIBuffer *outputBuffer, int *connClosed, int clipSentData, char *id);
extern int func_0217EB9C(int sock, int how);
extern int func_0217EB2C(int sock);
extern int func_02181748(char *theHeader);
extern int func_02181828(void);
extern int func_02181874(void);
extern int func_02181530(void);
extern void func_0218EEC0(void **connection, GPIPeer *peer);
extern int func_0218FFFC(void **connection, int (*func)(void **, void *, void *), void *data);
void func_0218A1D0(char *buffer, int numChars);
int func_0218A238(void **connection, GPIOperation *operation);
int func_0218A624(void **connection, char *nick, char *uniquenick, char *email, char *password, char *authtoken, char *partnerchallenge, char *cdkey, int firewall, int newuser, int blocking, void (*callback)(void **, void *, void *), void *param);
int func_0218A830(void **connection, GPIConnectData *data);
int func_0218AC4C(void **connection, GPIConnectData *data);
int func_0218AE9C(void **connection, GPIOperation *operation, char *input);
int func_0218B5A0(void **connection);
int func_0218B618(GPIConnection_0218B618 **connection, GPIProfile_0218B618 *profile);
void func_0218B760(void **connection, int tellServer);
int func_0218B914(void **connection, char *input);
extern char g_021A4618[];
extern char g_021A4658[];
extern char g_021A4664[];
extern char g_021A467C[];
extern char g_021A46A0[];
extern char g_021A46D4[];
extern char g_021A46FC[];
extern char g_021A4734[];
extern char g_021A4760[];
extern char g_021A4788[];
extern char g_021A45D8[];
extern char g_021A47BC[];
extern char g_021A47F0[];
extern char g_021A4818[];
extern char g_021A482C[];
extern char g_021A483C[];
extern char g_021A4840[];
extern char g_021A4848[];
extern char g_021A4850[];
extern char g_021A4860[];
extern char g_021A4894[];
extern char g_021A489C[];
extern char g_021A48A8[];
extern char g_021A48B4[];
extern char g_021A48C4[];
extern char g_021A48CC[];
extern char g_021A48D0[];
extern char g_021A48DC[];
extern char g_021A48E8[];
extern char g_021A48F4[];
extern char g_021A4900[];
extern char g_021A490C[];
extern char g_021A4914[];
extern char g_021A4920[];
extern char g_021ACEFC[];
extern char g_021A492C[];
extern char g_021A493C[];
extern char g_021A494C[];
extern char g_021A4954[];
extern char g_021A495C[];
extern char g_021A4964[];
extern char g_021A4970[];
extern char g_021A4978[];
extern char g_021A4980[];
extern char g_021A4990[];
extern char g_021A499C[];
extern char g_021A49A4[];
extern char g_021A49AC[];
extern char g_021A49DC[];
extern char g_021A49E4[];
extern char g_021A4A14[];
extern char g_021A4A1C[];
extern char g_021A4A28[];
extern char g_021A4A30[];
extern char g_021A4A38[];
extern char g_021A4A58[];
extern char g_021A4A80[];
extern char g_021A4A94[];




/*
 * sdk:      randomString (gpiconnect.o)
 */
void func_0218A1D0(char *buffer, int numChars)
{
    int i;

    for (i = 0; i < numChars; i++)
        buffer[i] = g_021A4618[func_02094694() % 0x3E];
    buffer[i] = 0;
}




/*
 * sdk:      gpiStartConnect (gpiconnect.o)
 *
 * gpiPeerPingReplyCallback (func_0218F880) is its own 4-byte function since
 * 2026-09-29 (w4_nm: seeded start, catalog row, EXACT stub).
 * The port-retry loop sits under its own if (anError != 0): the object tests
 * the first gsUdpEngineInitialize result once and skips both the loop and the
 * failure test on success. The SOCSockAddrIn is zeroed with two word stores
 * through a pointer to the local (w2 ghiDoConnecting spelling).
 */
int func_0218A238(void **connection, GPIOperation *operation)
{
    SOCSockAddrIn address;
    int rcode;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    SOCHostEnt *host;
    int anError;
    unsigned short peerPort;
    int error;

    func_02094860((u8 *)iconnection->mHeader, (const u8 *)g_021A4658, 16);

    if (!func_02180E48()) {
        peerPort = 6500;
        func_0217D254(1, 0, 8, g_021A4664);
        anError = func_02180E58(peerPort, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        if (anError != 0) {
            while (anError != 0 && peerPort < 6500 + 100) {
                func_0217D254(1, 0, 16, g_021A467C, peerPort);
                peerPort++;
                anError = func_02180E58(peerPort, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            }
            if (anError != 0) {
                func_0217D254(1, 0, 1, g_021A46A0);
                func_02193710((int *)connection, 8, (int)g_021A46D4);
                func_02189D78((int *)connection, 3, 1);
                return 3;
            }
        }
        if (iconnection->firewall == 0)
            iconnection->peerPort = peerPort;
    } else {
        func_0217D254(1, 0, 8, g_021A46FC);
        iconnection->peerPort = func_0218158C();
    }

    anError = func_021815C8(iconnection->mHeader, iconnection->mHeader, 0,
                            (void *)func_0218F7B8, (void *)func_0218F5F4,
                            (void *)func_0218F880, (void *)func_0218F65C, connection);
    if (anError != 0) {
        func_02193710((int *)connection, 8, (int)g_021A4734);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    if (iconnection->firewall)
        iconnection->peerPort = 0;

    iconnection->cmSocket = func_0217EB18(2, 1, 0);
    if (iconnection->cmSocket == -1) {
        func_02193710((int *)connection, 5, (int)g_021A4760);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    rcode = func_0217EE50(iconnection->cmSocket, 0);
    if (!rcode) {
        func_02193710((int *)connection, 5, (int)g_021A4788);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    {
        unsigned int *p = (unsigned int *)&address;
        p[0] = 0;
        p[1] = 0;
    }
    address.family = 2;
    if (func_0217ED38((int)g_021A45D8) == 0xFFFFFFFF) {
        host = func_0215F650(g_021A45D8);
        if (host == 0) {
            func_02193710((int *)connection, 5, (int)g_021A47BC);
            func_02189D78((int *)connection, 3, 1);
            return 3;
        }
        address.addr = *(unsigned int *)host->addrList[0];
    } else {
        address.addr = func_0217ED38((int)g_021A45D8);
    }
    address.port = 0xcc74;

    rcode = func_0217EC08(iconnection->cmSocket, &address, sizeof(address));
    if (rcode == -1) {
        error = func_0217ED54(iconnection->cmSocket);
        if (error != -6 && error != -26 && error != -76) {
            func_02193710((int *)connection, 5, (int)g_021A47F0);
            func_02189D78((int *)connection, 3, 1);
            return 3;
        }
    }

    operation->state = 1;
    iconnection->connectState = 1;
    return 0;
}




/*
 * sdk:      gpiConnect (gpiconnect.o)
 *
 * The DWARF prototype lists 12 parameters, but the object reads newuser,
 * blocking, callback and param one word higher (sp+0x44..0x50): an unused
 * word parameter sits between cdkey and newuser, spelled here as firewall.
 */
int func_0218A624(void **connection, char *nick, char *uniquenick, char *email,
                  char *password, char *authtoken, char *partnerchallenge,
                  char *cdkey, int firewall, int newuser, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIConnectData *data;
    GPIOperation *operation;
    GPIConnection_0218A624 *iconnection = (GPIConnection_0218A624 *)*connection;
    int result;

    if (iconnection->connectState == 4) {
        int __result__ = func_021867E8(connection);
        if (__result__ != 0) return __result__;
    }
    if (iconnection->connectState != 0) {
        func_02193734((int *)connection, (int)g_021A4818);
        return 2;
    }

    iconnection->firewall = 1;
    func_0219327C(iconnection->nick, (int)nick, 31);
    func_0219327C(iconnection->uniquenick, (int)uniquenick, 21);
    func_0219327C(iconnection->email, (int)email, 51);
    func_0219327C(iconnection->password, (int)password, 31);
    func_0217F21C(iconnection->email);

    data = (GPIConnectData *)func_0217EAB0(sizeof(GPIConnectData));
    if (data == 0) {
        func_02193734((int *)connection, (int)g_021A482C);
        return 1;
    }
    func_020923B0(data, 0, sizeof(GPIConnectData));
    data->newuser = newuser;
    if (authtoken[0] && partnerchallenge[0]) {
        func_0219327C(data->authtoken, (int)authtoken, 256);
        func_0219327C(data->partnerchallenge, (int)partnerchallenge, 256);
    }
    if (cdkey)
        func_0219327C(data->cdkey, (int)cdkey, 65);

    {
        int __result__ = func_0218E114(connection, 0, data, &operation, blocking, callback, param);
        if (__result__ != 0) return __result__;
    }

    result = func_0218A238(connection, operation);
    if (result != 0) {
        operation->result = result;
        func_0218DD88(connection, operation);
        func_0218B760(connection, 0);
        return result;
    }

    if (operation->blocking) {
        int __result__ = func_02186E9C(connection, operation->id);
        if (__result__ != 0) return __result__;
    }
    return 0;
}




/*
 * sdk:      gpiSendLogin (gpiconnect.o)
 */
int func_0218A830(void **connection, GPIConnectData *data)
{
    GPIConnection_0218A830 *iconnection = (GPIConnection_0218A830 *)*connection;
    char buffer[512];
    char response[33];
    GPIProfile *profile;
    char *passphrase;
    char userBuffer[82];
    char partnerBuffer[11];
    char *user;

    func_0218A1D0(data->userChallenge, sizeof(data->userChallenge) - 1);

    if (data->partnerchallenge[0])
        passphrase = data->partnerchallenge;
    else
        passphrase = iconnection->password;
    func_021858A8((unsigned char *)passphrase, func_0209477C((const u8 *)passphrase), data->passwordHash);

    if (iconnection->partnerID != 0)
        func_02084F40(partnerBuffer, g_021A483C, iconnection->partnerID);
    else
        partnerBuffer[0] = '\0';

    if (data->authtoken[0]) {
        user = data->authtoken;
    } else if (iconnection->uniquenick[0]) {
        func_02084F40(userBuffer, g_021A4840, partnerBuffer, iconnection->uniquenick);
        user = userBuffer;
    } else {
        func_02084F40(userBuffer, g_021A4848, partnerBuffer, iconnection->nick, iconnection->email);
        user = userBuffer;
    }

    func_02084F40(buffer, g_021A4850, data->passwordHash, g_021A4860, user,
                  data->userChallenge, data->serverChallenge, data->passwordHash);
    func_021858A8((unsigned char *)buffer, func_0209477C((const u8 *)buffer), response);

    if (iconnection->infoCaching) {
        func_0218FF98(connection, iconnection->nick, iconnection->email, &profile);
        if (profile != 0) {
            iconnection->userid = profile->userId;
            iconnection->profileid = profile->profileId;
        }
    }

    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4894);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A489C);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), data->userChallenge);
    if (data->authtoken[0]) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48A8);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), data->authtoken);
    } else if (iconnection->uniquenick[0]) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);
    } else {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48C4);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48CC);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    }
    if (iconnection->userid != 0) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48D0);
        func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->userid);
    }
    if (iconnection->profileid != 0) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48DC);
        func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->profileid);
    }
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48F4);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), response);
    if (iconnection->firewall == 1)
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4900);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A490C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->peerPort);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021ACEFC);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A493C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), 0x3b);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A494C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->quietModeFlags);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
    return 0;
}




int func_0218AC4C(void **connection, GPIConnectData *data)
{
    GPIConnection_0218AC4C *iconnection = (GPIConnection_0218AC4C *)*connection;
    unsigned long i;
    char passwordenc[45];
    char cdkeyxor[65];
    char cdkeyenc[90];
    unsigned long cdkeylen;
    char aRand;

    func_02193748(iconnection->password, passwordenc);

    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4964);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4970);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4978);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4980);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), passwordenc);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021ACEFC);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);

    if (data->cdkey[0] != '\0') {
        cdkeylen = func_0209477C((const u8 *)data->cdkey);
        func_0217F790(0x79707367);
        for (i = 0; i < cdkeylen; i++) {
            aRand = (char)func_0217F7AC(0, 0xFF);
            cdkeyxor[i] = (char)(data->cdkey[i] ^ aRand);
        }
        cdkeyxor[i] = '\0';
        func_0217FA90(cdkeyxor, cdkeyenc, (int)cdkeylen, 1);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4990);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), cdkeyenc);
    }

    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
    return 0;
}



/*
 * sdk:      gpiProcessConnect (gpiconnect.o)
 *
 * notes: reconstructed from the vendor DWARF declarations and the GameSpy
 * gpiconnect.c gpiProcessConnect body.  This Black build numbers the states
 * GPI_CONNECTING=1, GPI_LOGIN=2, GPI_REQUESTING=3 (the \lc\2 handler runs the
 * proof exchange and is reached after a \nur\ login request).
 */
int func_0218AE9C(void **connection, GPIOperation *operation, char *input)
{
    char buffer[512];
    char check[33];
    char uniquenick[21];
    GPIConnectData *data;
    GPIConnection_0218AE9C *iconnection = (GPIConnection_0218AE9C *)*connection;
    GPICallback callback;
    GPIProfile_0218AE9C *profile;
    char userBuffer[82];
    char partnerBuffer[11];
    char *user;
    int __result__;

    if (func_0219329C((int *)connection, input, 0)) {
        if (iconnection->errorCode == 0x106 && iconnection->profileid) {
            func_0218FEF0(connection, iconnection->profileid);
            iconnection->userid = 0;
            iconnection->profileid = 0;
        } else if (iconnection->errorCode == 0x201) {
            if (func_02193418(input, g_021A499C, buffer, sizeof(buffer)))
                iconnection->profileid = func_020964E0((u32)buffer);
        }
        func_02193710((int *)connection, iconnection->errorCode, (int)iconnection->errorString);
        __result__ = 4;
        func_02189D78((int *)connection, __result__, 1);
        return __result__;
    }

    data = (GPIConnectData *)operation->data;

    switch (operation->state) {
    case 1:
        if (func_020949F4((const u8 *)input, (const u8 *)g_021A49A4, 5) != 0) {
            func_02193710((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        if (!func_02193418(input, g_021A489C, data->serverChallenge, sizeof(data->serverChallenge))) {
            func_02193710((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        if (data->newuser) {
            __result__ = func_0218AC4C(connection, data);
            if (__result__ != 0)
                return __result__;
            operation->state = 3;
        } else {
            __result__ = func_0218A830(connection, data);
            if (__result__ != 0)
                return __result__;
            operation->state = 2;
        }
        break;
    case 3:
        if (func_020949F4((const u8 *)input, (const u8 *)g_021A49DC, 5) != 0) {
            func_02193710((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        if (!func_02193418(input, g_021A48D0, buffer, sizeof(buffer))) {
            func_02193710((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->userid = func_020964E0((u32)buffer);
        if (!func_02193418(input, g_021A48DC, buffer, sizeof(buffer))) {
            func_02193710((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->profileid = func_020964E0((u32)buffer);
        __result__ = func_0218A830(connection, data);
        if (__result__ != 0)
            return __result__;
        operation->state = 2;
        break;
    case 2:
        if (func_020949F4((const u8 *)input, (const u8 *)g_021A4A14, 5) != 0) {
            func_02193710((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        if (!func_02193418(input, g_021A4A1C, buffer, sizeof(buffer))) {
            func_02193710((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->sessKey = func_020964E0((u32)buffer);
        if (!func_02193418(input, g_021A48D0, buffer, sizeof(buffer))) {
            func_02193710((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->userid = func_020964E0((u32)buffer);
        if (!func_02193418(input, g_021A48DC, buffer, sizeof(buffer))) {
            func_02193710((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->profileid = func_020964E0((u32)buffer);
        if (!func_02193418(input, g_021A48B4, uniquenick, sizeof(uniquenick)))
            uniquenick[0] = '\0';
        if (!func_02193418(input, g_021A4A28, iconnection->loginTicket, sizeof(iconnection->loginTicket)))
            iconnection->loginTicket[0] = '\0';

        if (iconnection->partnerID != 0)
            func_02084F40(partnerBuffer, g_021A483C, iconnection->partnerID);
        else
            partnerBuffer[0] = '\0';

        if (data->authtoken[0])
            user = data->authtoken;
        else if (iconnection->uniquenick[0]) {
            func_02084F40(userBuffer, g_021A4840, partnerBuffer, iconnection->uniquenick);
            user = userBuffer;
        } else {
            func_02084F40(userBuffer, g_021A4848, partnerBuffer, iconnection->nick, iconnection->email);
            user = userBuffer;
        }

        func_02084F40(buffer, g_021A4850, data->passwordHash, g_021A4860, user,
                      data->serverChallenge, data->userChallenge, data->passwordHash);
        func_021858A8((unsigned char *)buffer, func_0209477C((const u8 *)buffer), check);

        if (!func_02193418(input, g_021A4A30, buffer, sizeof(buffer))) {
            func_02193710((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }
        if (func_020923F0((const u8 *)check, (const u8 *)buffer, 32) != 0) {
            func_02193710((int *)connection, 0x108, (int)g_021A4A38);
            __result__ = 3;
            func_02189D78((int *)connection, __result__, 1);
            return __result__;
        }

        if (iconnection->infoCaching) {
            profile = func_0218FCD8(connection, iconnection->profileid);
            profile->profileId = iconnection->profileid;
            profile->userId = iconnection->userid;
        }

        iconnection->connectState = 3;

        callback = operation->callback;
        if (callback.callback != 0) {
            GPConnectResponseArg *arg;
            arg = (GPConnectResponseArg *)func_0217EAB0(sizeof(GPConnectResponseArg));
            if (arg == 0) {
                func_02193734((int *)connection, (int)g_021A482C);
                return 1;
            }
            func_020923B0(arg, 0, sizeof(GPConnectResponseArg));
            arg->profile = iconnection->profileid;
            arg->result = 0;
            func_0219327C(arg->uniquenick, (int)uniquenick, 21);
            __result__ = func_02189DFC(connection, callback, arg, operation, 0);
            if (__result__ != 0)
                return __result__;
        }

        func_0218E240(connection, (struct GPIOperation *)operation);
        break;
    default:
        break;
    }

    return 0;
}



/*
 * sdk:      gpiCheckConnect (gpiconnect.o)
 */
int func_0218B5A0(void **connection)
{
    GPIConnection_0218B5A0 *iconnection = (GPIConnection_0218B5A0 *)*connection;
    int state;
    int result;

    if ((result = func_02193488((int *)connection, iconnection->socket, &state)) != 0)
        return result;
    if (state == 4) {
        func_02193710((int *)connection, 0x107, (int)g_021A4A58);
        func_02189D78((int *)connection, 4, 1);
        return 4;
    }
    if (state == 0)
        return 0;
    iconnection->state = 2;
    return 0;
}



/*
 * sdk:      gpiDisconnectCleanupProfile (libdwcgsgp.TWL.HYB.a gpiconnect.o)
 */
int func_0218B618(GPIConnection_0218B618 **connection, GPIProfile_0218B618 *profile)
{
    GPIConnection_0218B618 *iconnection;

    iconnection = *connection;
    if (profile->buddyStatus) {
        profile->f28 = 1;
        func_0217EAE0(profile->buddyStatus->f8);
        profile->buddyStatus->f8 = 0;
        func_0217EAE0(profile->buddyStatus->fC);
        profile->buddyStatus->fC = 0;
        func_0217EAE0(profile->buddyStatus);
        profile->buddyStatus = 0;
    }
    if (profile->statusInfo) {
        profile->f28 = 1;
        func_0217EAE0(profile->statusInfo->f8);
        profile->statusInfo->f8 = 0;
        func_0217EAE0(profile->statusInfo->fC);
        profile->statusInfo->fC = 0;
        func_0217EAE0(profile->statusInfo->f10);
        profile->statusInfo->f10 = 0;
        func_0217EAE0(profile->statusInfo->f14);
        profile->statusInfo->f14 = 0;
        if (profile->statusInfo->f38) {
            func_021841B0(profile->statusInfo->f38);
            profile->statusInfo->f38 = 0;
        }
        func_0217EAE0(profile->statusInfo);
        profile->statusInfo = 0;
    }
    if (profile->f20)
        profile->f28 = 1;
    func_0217EAE0(profile->f14);
    profile->f14 = 0;
    func_0217EAE0(profile->f1C);
    profile->f1C = 0;
    profile->f18 = 0;
    if (profile->f10 == 0 || (iconnection->state == 1 && profile->f28 == 0)) {
        func_0218FF24((const int *)connection, profile);
        return 0;
    }
    return 1;
}



/*
 * sdk:      gpiDisconnect (gpiconnect.o)
 */
void func_0218B760(void **connection, int tellServer)
{
    GPIConnection_0218B760 *iconnection = (GPIConnection_0218B760 *)*connection;
    GPIPeer *peer;
    GPIPeer *delPeer;
    int connClosed;

    if (iconnection->connectState == 4)
        return;

    if (iconnection->connectState != 0) {
        if (tellServer && iconnection->connectState == 3) {
            func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4A80);
            func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->sessKey);
            func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
        }
        func_0218998C(connection, iconnection->cmSocket, &iconnection->outputBuffer, &connClosed, 1, g_021A4A94);
        if (iconnection->cmSocket != -1) {
            func_0217EB9C(iconnection->cmSocket, 2);
            func_0217EB2C(iconnection->cmSocket);
            iconnection->cmSocket = -1;
        }
        iconnection->connectState = 4;
        iconnection->userid = 0;
        iconnection->profileid = 0;
    }

    if (func_02180E48()) {
        func_02181748(iconnection->mHeader);
        if (func_02181828() && func_02181874())
            func_02181530();
    }

    func_0217EAE0(iconnection->socketBuffer.buffer);
    iconnection->socketBuffer.buffer = 0;
    func_0217EAE0(iconnection->inputBuffer);
    iconnection->inputBuffer = 0;
    func_0217EAE0(iconnection->outputBuffer.buffer);
    iconnection->outputBuffer.buffer = 0;
    func_0217EAE0(iconnection->updateproBuffer.buffer);
    iconnection->updateproBuffer.buffer = 0;
    func_0217EAE0(iconnection->updateuiBuffer.buffer);
    iconnection->updateuiBuffer.buffer = 0;

    while (iconnection->operationList)
        func_0218E240(connection, iconnection->operationList);
    iconnection->operationList = 0;

    for (peer = iconnection->peerList; peer; ) {
        delPeer = peer;
        peer = peer->pnext;
        func_0218EEC0(connection, delPeer);
    }
    iconnection->peerList = 0;

    while (!func_0218FFFC(connection, (int (*)(void **, void *, void *))func_0218B618, 0)) {
    }
}



/*
 * sdk:      gpiProcessRemoteAuthResponse (gpiconnect.o)
 */
int func_0218B914(void **connection, char *input)
{
    GPIConnection_0218B914 *iconnection;
    char buffer[512];

    iconnection = (GPIConnection_0218B914 *)*connection;
    if (func_0219329C((int *)connection, input, 1))
        return 4;
    if (!func_02193418(iconnection->f208, g_021A492C, buffer, 512)) {
        func_02193710((int *)connection, 1, (int)g_021A49AC);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }
    iconnection->f610 = func_020964E0((u32)buffer);
    if (!func_02193418(iconnection->f208, g_021A48E8, buffer, 512)) {
        func_02193710((int *)connection, 1, (int)g_021A49AC);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }
    iconnection->f1A4 = func_020964E0((u32)buffer);
    return 0;
}
