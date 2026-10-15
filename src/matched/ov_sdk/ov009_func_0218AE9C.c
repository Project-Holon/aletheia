/*
 * function: gpiProcessConnect
 * address:  0x0218AE9C
 * packet:   pkt_ov009_0218AE9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessConnect (gpiconnect.o)
 *
 * notes: reconstructed from the vendor DWARF declarations and the GameSpy
 * gpiconnect.c gpiProcessConnect body.  This Black build numbers the states
 * GPI_CONNECTING=1, GPI_LOGIN=2, GPI_REQUESTING=3 (the \lc\2 handler runs the
 * proof exchange and is reached after a \nur\ login request).
 *
 * symbols:
 *   gpiCheckForError  0x0219329C  arm   ov009
 *   func_0218FEF0  0x0218FEF0  arm   ov009
 *   gpiValueForKey  0x02193418  arm   ov009
 *   atoi  0x020964E0  arm
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   strncmp  0x020949F4  arm
 *   gpiSendNewuser  0x0218AC4C  arm   ov009
 *   gpiSendLogin  0x0218A830  arm   ov009
 *   OS_SPrintf  0x02084F40  arm
 *   strlen  0x0209477C  arm
 *   GSMD5Digest  0x021858A8  arm   ov009
 *   func_020923F0  0x020923F0  arm
 *   gpiProfileListAdd  0x0218FCD8  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   strzcpy  0x0219327C  arm   ov009
 *   gpiAddCallback  0x02189DFC  arm   ov009
 *   gpiRemoveOperation  0x0218E240  arm   ov009
 *   g_021A499C     0x021A499C  data
 *   g_021A49A4     0x021A49A4  data
 *   g_021A49AC     0x021A49AC  data
 *   g_021A489C     0x021A489C  data
 *   g_021A49DC     0x021A49DC  data
 *   g_021A48D0     0x021A48D0  data
 *   g_021A49E4     0x021A49E4  data
 *   g_021A48DC     0x021A48DC  data
 *   g_021A4A14     0x021A4A14  data
 *   g_021A4A1C     0x021A4A1C  data
 *   g_021A48B4     0x021A48B4  data
 *   g_021A4A28     0x021A4A28  data
 *   g_021A483C     0x021A483C  data
 *   g_021A4840     0x021A4840  data
 *   g_021A4848     0x021A4848  data
 *   g_021A4850     0x021A4850  data
 *   g_021A4860     0x021A4860  data
 *   g_021A4A30     0x021A4A30  data
 *   g_021A4A38     0x021A4A38  data
 *   g_021A482C     0x021A482C  data
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIConnectData {
    char serverChallenge[128];
    char userChallenge[33];
    char passwordHash[33];
    char authtoken[256];
    char partnerchallenge[256];
    char cdkey[65];
    int newuser;
} GPIConnectData;

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
} GPIOperation_s;

typedef struct GPIProfile {
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
} GPIProfile;

typedef struct GPConnectResponseArg {
    int result;
    int profile;
    char uniquenick[21];
} GPConnectResponseArg;

typedef struct GPIConnection {
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
    GPIOperation_s *operationList;
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
} GPIConnection;

typedef unsigned char  u8;
struct GPIOperation;
extern int gpiCheckForError(int *connection, const char *input, int fatal);
extern void func_0218FEF0(void **connection, int profileid);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern int strncmp(const u8 *s1, const u8 *s2, u32 n);
extern int gpiSendNewuser(void **connection, GPIConnectData *data);
extern int gpiSendLogin(void **connection, GPIConnectData *data);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int strlen(const u8 *s);
extern void GSMD5Digest(unsigned char *input, unsigned int len, char *output);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(int *p, int b);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int c, unsigned long n);
extern void strzcpy(char *p, int b, int n);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation_s *operation, int type);
extern void gpiRemoveOperation(void **connection, struct GPIOperation *operation);
extern char g_021A499C[];
extern char g_021A49A4[];
extern char g_021A49AC[];
extern char g_021A489C[];
extern char g_021A49DC[];
extern char g_021A48D0[];
extern char g_021A49E4[];
extern char g_021A48DC[];
extern char g_021A4A14[];
extern char g_021A4A1C[];
extern char g_021A48B4[];
extern char g_021A4A28[];
extern char g_021A483C[];
extern char g_021A4840[];
extern char g_021A4848[];
extern char g_021A4850[];
extern char g_021A4860[];
extern char g_021A4A30[];
extern char g_021A4A38[];
extern char g_021A482C[];

int gpiProcessConnect(void **connection, GPIOperation_s *operation, char *input)
{
    char buffer[512];
    char check[33];
    char uniquenick[21];
    GPIConnectData *data;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPICallback callback;
    GPIProfile *profile;
    char userBuffer[82];
    char partnerBuffer[11];
    char *user;
    int __result__;

    if (gpiCheckForError((int *)connection, input, 0)) {
        if (iconnection->errorCode == 0x106 && iconnection->profileid) {
            func_0218FEF0(connection, iconnection->profileid);
            iconnection->userid = 0;
            iconnection->profileid = 0;
        } else if (iconnection->errorCode == 0x201) {
            if (gpiValueForKey(input, g_021A499C, buffer, sizeof(buffer)))
                iconnection->profileid = atoi((u32)buffer);
        }
        gpiSetError((int *)connection, iconnection->errorCode, (int)iconnection->errorString);
        __result__ = 4;
        gpiCallErrorCallback((int *)connection, __result__, 1);
        return __result__;
    }

    data = (GPIConnectData *)operation->data;

    switch (operation->state) {
    case 1:
        if (strncmp((const u8 *)input, (const u8 *)g_021A49A4, 5) != 0) {
            gpiSetError((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        if (!gpiValueForKey(input, g_021A489C, data->serverChallenge, sizeof(data->serverChallenge))) {
            gpiSetError((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        if (data->newuser) {
            __result__ = gpiSendNewuser(connection, data);
            if (__result__ != 0)
                return __result__;
            operation->state = 3;
        } else {
            __result__ = gpiSendLogin(connection, data);
            if (__result__ != 0)
                return __result__;
            operation->state = 2;
        }
        break;
    case 3:
        if (strncmp((const u8 *)input, (const u8 *)g_021A49DC, 5) != 0) {
            gpiSetError((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        if (!gpiValueForKey(input, g_021A48D0, buffer, sizeof(buffer))) {
            gpiSetError((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->userid = atoi((u32)buffer);
        if (!gpiValueForKey(input, g_021A48DC, buffer, sizeof(buffer))) {
            gpiSetError((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->profileid = atoi((u32)buffer);
        __result__ = gpiSendLogin(connection, data);
        if (__result__ != 0)
            return __result__;
        operation->state = 2;
        break;
    case 2:
        if (strncmp((const u8 *)input, (const u8 *)g_021A4A14, 5) != 0) {
            gpiSetError((int *)connection, 1, (int)g_021A49AC);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        if (!gpiValueForKey(input, g_021A4A1C, buffer, sizeof(buffer))) {
            gpiSetError((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->sessKey = atoi((u32)buffer);
        if (!gpiValueForKey(input, g_021A48D0, buffer, sizeof(buffer))) {
            gpiSetError((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->userid = atoi((u32)buffer);
        if (!gpiValueForKey(input, g_021A48DC, buffer, sizeof(buffer))) {
            gpiSetError((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        iconnection->profileid = atoi((u32)buffer);
        if (!gpiValueForKey(input, g_021A48B4, uniquenick, sizeof(uniquenick)))
            uniquenick[0] = '\0';
        if (!gpiValueForKey(input, g_021A4A28, iconnection->loginTicket, sizeof(iconnection->loginTicket)))
            iconnection->loginTicket[0] = '\0';

        if (iconnection->partnerID != 0)
            OS_SPrintf(partnerBuffer, g_021A483C, iconnection->partnerID);
        else
            partnerBuffer[0] = '\0';

        if (data->authtoken[0])
            user = data->authtoken;
        else if (iconnection->uniquenick[0]) {
            OS_SPrintf(userBuffer, g_021A4840, partnerBuffer, iconnection->uniquenick);
            user = userBuffer;
        } else {
            OS_SPrintf(userBuffer, g_021A4848, partnerBuffer, iconnection->nick, iconnection->email);
            user = userBuffer;
        }

        OS_SPrintf(buffer, g_021A4850, data->passwordHash, g_021A4860, user,
                      data->serverChallenge, data->userChallenge, data->passwordHash);
        GSMD5Digest((unsigned char *)buffer, strlen((const u8 *)buffer), check);

        if (!gpiValueForKey(input, g_021A4A30, buffer, sizeof(buffer))) {
            gpiSetError((int *)connection, 1, (int)g_021A49E4);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }
        if (func_020923F0((const u8 *)check, (const u8 *)buffer, 32) != 0) {
            gpiSetError((int *)connection, 0x108, (int)g_021A4A38);
            __result__ = 3;
            gpiCallErrorCallback((int *)connection, __result__, 1);
            return __result__;
        }

        if (iconnection->infoCaching) {
            profile = gpiProfileListAdd(connection, iconnection->profileid);
            profile->profileId = iconnection->profileid;
            profile->userId = iconnection->userid;
        }

        iconnection->connectState = 3;

        callback = operation->callback;
        if (callback.callback != 0) {
            GPConnectResponseArg *arg;
            arg = (GPConnectResponseArg *)gsimalloc(sizeof(GPConnectResponseArg));
            if (arg == 0) {
                gpiSetErrorString((int *)connection, (int)g_021A482C);
                return 1;
            }
            MSL_C_LIB_MemsetPtr(arg, 0, sizeof(GPConnectResponseArg));
            arg->profile = iconnection->profileid;
            arg->result = 0;
            strzcpy(arg->uniquenick, (int)uniquenick, 21);
            __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
            if (__result__ != 0)
                return __result__;
        }

        gpiRemoveOperation(connection, (struct GPIOperation *)operation);
        break;
    default:
        break;
    }

    return 0;
}
