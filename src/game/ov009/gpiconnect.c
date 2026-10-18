/*
 * file:     gpiconnect.c
 * unit:     yes
 * function: randomString, gpiStartConnect, gpiConnect, gpiSendLogin, gpiSendNewuser, gpiProcessConnect, gpiCheckConnect, gpiDisconnectCleanupProfile, gpiDisconnect, gpiProcessRemoteAuthResponse
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
 *   rand  0x02094694  arm
 *   g_021A4618     0x021A4618  data  ov009
 *   strncpy  0x02094860  arm
 *   gsUdpEngineIsInitialized  0x02180E48  arm   ov009
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   gsUdpEngineInitialize  0x02180E58  arm   ov009
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   gsUdpEngineGetLocalPort  0x0218158C  arm   ov009
 *   gsUdpEngineAddMsgHandler  0x021815C8  arm   ov009
 *   socket  0x0217EB18  arm   ov009
 *   SetSockBlocking  0x0217EE50  arm   ov009
 *   inet_addr  0x0217ED38  arm   ov009
 *   SOC_GetHostByName  0x0215F650  arm   ov009
 *   connect  0x0217EC08  arm   ov009
 *   GOAGetLastError  0x0217ED54  arm   ov009
 *   gpiPeerLeftCallback  0x0218F5F4  arm   ov009
 *   gpiPeerPingReplyCallback  0x0218F880  arm   ov009
 *   gpiPeerMessageCallback  0x0218F65C  arm   ov009
 *   gpiPeerAcceptedCallback  0x0218F7B8  arm   ov009
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
 *   gpiReset  0x021867E8  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   strzcpy  0x0219327C  arm   ov009
 *   _strlwr  0x0217F21C  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   gpiAddOperation  0x0218E114  arm   ov009
 *   gpiFailedOpCallback  0x0218DD88  arm   ov009
 *   gpiProcess  0x02186E9C  arm   ov009
 *   g_021A4818     0x021A4818  data
 *   g_021A482C     0x021A482C  data
 *   strlen  0x0209477C  arm
 *   GSMD5Digest  0x021858A8  arm   ov009
 *   OS_SPrintf  0x02084F40  arm
 *   gpiFindProfileByUser  0x0218FF98  arm   ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm   ov009
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
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   g_021A492C     0x021A492C  data
 *   g_021A493C     0x021A493C  data
 *   g_021A494C     0x021A494C  data
 *   g_021A4954     0x021A4954  data
 *   g_021A495C     0x021A495C  data
 *   gpiEncodeString  0x02193748  arm   ov009
 *   Util_RandSeed  0x0217F790  arm   ov009
 *   Util_RandInt  0x0217F7AC  arm   ov009
 *   B64Encode  0x0217FA90  arm   ov009
 *   g_021A4964     0x021A4964  data
 *   g_021A4970     0x021A4970  data
 *   g_021A4978     0x021A4978  data
 *   g_021A4980     0x021A4980  data
 *   g_021A4990     0x021A4990  data
 *   gpiCheckForError  0x0219329C  arm   ov009
 *   gpiRemoveProfileByID  0x0218FEF0  arm   ov009
 *   gpiValueForKey  0x02193418  arm   ov009
 *   atoi  0x020964E0  arm
 *   strncmp  0x020949F4  arm
 *   memcmp  0x020923F0  arm
 *   gpiProfileListAdd  0x0218FCD8  arm   ov009
 *   gpiAddCallback  0x02189DFC  arm   ov009
 *   gpiRemoveOperation  0x0218E240  arm   ov009
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
 *   gpiCheckSocketConnect  0x02193488  arm   ov009
 *   g_021A4A58     0x021A4A58  data  ov009
 *   gsifree  0x0217eae0  arm   ov009
 *   ArrayFree  0x021841b0  arm   ov009
 *   gpiRemoveProfile  0x0218ff24  arm   ov009
 *   gpiSendFromBuffer  0x0218998C  arm   ov009
 *   shutdown  0x0217EB9C  arm   ov009
 *   closesocket  0x0217EB2C  arm   ov009
 *   gsUdpEngineRemoveMsgHandler  0x02181748  arm   ov009
 *   gsUdpEngineNoMoreMsgHandlers  0x02181828  arm   ov009
 *   gsUdpEngineNoApp  0x02181874  arm   ov009
 *   gsUdpEngineShutdown  0x02181530  arm   ov009
 *   gpiDestroyPeer  0x0218EEC0  arm   ov009
 *   gpiProfileMap  0x0218FFFC  arm   ov009
 *   g_021A4A80     0x021A4A80  data
 *   g_021A4A94     0x021A4A94  data
 */
#include "gpi_types.h"

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

typedef struct GPIConnectData {
    char serverChallenge[128];
    char userChallenge[33];
    char passwordHash[33];
    char authtoken[256];
    char partnerchallenge[256];
    char cdkey[65];
    int newuser;
} GPIConnectData;

typedef struct GPConnectResponseArg {
    int result;
    int profile;
    char uniquenick[21];
} GPConnectResponseArg;

extern unsigned int rand();
extern u8 *strncpy(u8 *dest, const u8 *src, u32 n);
extern int gsUdpEngineIsInitialized(void);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int gsUdpEngineInitialize(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize, void (*theAppNetworkError)(int, void *), void (*theAppConnected)(unsigned int, unsigned short, int, int, void *), void (*theAppClosed)(unsigned int, unsigned short, int, void *), void (*theAppPing)(unsigned int, unsigned short, unsigned int, void *), void (*theAppReceive)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), int (*theAppUnownMsg)(unsigned int, unsigned short, unsigned char *, unsigned int, void *), void (*theAppConnectAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *), void *theAppUserData);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern unsigned short gsUdpEngineGetLocalPort(void);
extern int gsUdpEngineAddMsgHandler(char *theInitMsg, char *theHeader, void (*theMsgHandlerError)(int, void *), void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *), void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *), void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *), void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), void *theUserData);
extern int socket(int pf, int type, int protocol);
extern int SetSockBlocking(int sock, int isblocking);
extern int inet_addr(int a);
extern SOCHostEnt *SOC_GetHostByName(char *name);
extern int connect(int sock, void *addr, int len);
extern int GOAGetLastError(int sock);
extern void gpiPeerLeftCallback(void);
extern void gpiPeerPingReplyCallback(void);
extern void gpiPeerMessageCallback(unsigned int ip, unsigned short port, unsigned char *message, int messageLength, int unused, void *userData);
extern void gpiPeerAcceptedCallback(unsigned int ip, unsigned short port, int unused, int rejected, void *userData);
extern int gpiReset(void **connection);
extern void gpiSetErrorString(int *p, int b);
extern void strzcpy(char *p, int b, int n);
extern char *_strlwr(char *string);
extern void *gsimalloc(unsigned long size);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int val, unsigned long len);
extern int gpiAddOperation(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int gpiFailedOpCallback(void **connection, const struct GPIOperation *operation);
extern int gpiProcess(void **connection, int blockingOperationID);
extern int strlen(const u8 *s);
extern void GSMD5Digest(unsigned char *input, unsigned int len, char *output);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int gpiFindProfileByUser(void **connection, char *nick, char *email, GPIProfile **profile);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern void gpiEncodeString(const char *plaintext, char *encoded);
extern void Util_RandSeed(unsigned long seed);
extern unsigned int Util_RandInt(unsigned int min, unsigned int max);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);
extern int gpiCheckForError(int *connection, const char *input, int fatal);
extern void gpiRemoveProfileByID(void **connection, int profileid);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int atoi(u32 a0);
extern int strncmp(const u8 *s1, const u8 *s2, u32 n);
extern int memcmp(const u8 *a, const u8 *b, int n);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void gpiRemoveOperation(void **connection, struct GPIOperation *operation);
extern int gpiCheckSocketConnect(int *connection, int sock, int *state);
extern void gsifree(void *ptr);
extern void ArrayFree(void *array);
extern void gpiRemoveProfile(const int *p, void *profile);
extern int gpiSendFromBuffer(void **connection, int sock, GPIBuffer *outputBuffer, int *connClosed, int clipSentData, char *id);
extern int shutdown(int sock, int how);
extern int closesocket(int sock);
extern int gsUdpEngineRemoveMsgHandler(char *theHeader);
extern int gsUdpEngineNoMoreMsgHandlers(void);
extern int gsUdpEngineNoApp(void);
extern int gsUdpEngineShutdown(void);
extern void gpiDestroyPeer(void **connection, GPIPeer *peer);
extern int gpiProfileMap(void **connection, int (*func)(void **, void *, void *), void *data);
void randomString(char *buffer, int numChars);
int gpiStartConnect(void **connection, GPIOperation *operation);
int gpiConnect(void **connection, char *nick, char *uniquenick, char *email, char *password, char *authtoken, char *partnerchallenge, char *cdkey, int firewall, int newuser, int blocking, void (*callback)(void **, void *, void *), void *param);
int gpiSendLogin(void **connection, GPIConnectData *data);
int gpiSendNewuser(void **connection, GPIConnectData *data);
int gpiProcessConnect(void **connection, GPIOperation *operation, char *input);
int gpiCheckConnect(void **connection);
int gpiDisconnectCleanupProfile(GPIConnection **connection, GPIProfile *profile);
void gpiDisconnect(void **connection, int tellServer);
int gpiProcessRemoteAuthResponse(void **connection, char *input);
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
extern char gGsAvailabilityGameName[];
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
void randomString(char *buffer, int numChars)
{
    int i;

    for (i = 0; i < numChars; i++)
        buffer[i] = g_021A4618[rand() % 0x3E];
    buffer[i] = 0;
}




/*
 * sdk:      gpiStartConnect (gpiconnect.o)
 *
 * gpiPeerPingReplyCallback (gpiPeerPingReplyCallback) is its own 4-byte function since
 * 2026-09-29 (w4_nm: seeded start, catalog row, EXACT stub).
 * The port-retry loop sits under its own if (anError != 0): the object tests
 * the first gsUdpEngineInitialize result once and skips both the loop and the
 * failure test on success. The SOCSockAddrIn is zeroed with two word stores
 * through a pointer to the local (w2 ghiDoConnecting spelling).
 */
int gpiStartConnect(void **connection, GPIOperation *operation)
{
    SOCSockAddrIn address;
    int rcode;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    SOCHostEnt *host;
    int anError;
    unsigned short peerPort;
    int error;

    strncpy((u8 *)iconnection->mHeader, (const u8 *)g_021A4658, 16);

    if (!gsUdpEngineIsInitialized()) {
        peerPort = 6500;
        gsDebugFormat(1, 0, 8, g_021A4664);
        anError = gsUdpEngineInitialize(peerPort, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        if (anError != 0) {
            while (anError != 0 && peerPort < 6500 + 100) {
                gsDebugFormat(1, 0, 16, g_021A467C, peerPort);
                peerPort++;
                anError = gsUdpEngineInitialize(peerPort, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            }
            if (anError != 0) {
                gsDebugFormat(1, 0, 1, g_021A46A0);
                gpiSetError((int *)connection, 8, (int)g_021A46D4);
                gpiCallErrorCallback((int *)connection, 3, 1);
                return 3;
            }
        }
        if (iconnection->firewall == 0)
            iconnection->peerPort = peerPort;
    } else {
        gsDebugFormat(1, 0, 8, g_021A46FC);
        iconnection->peerPort = gsUdpEngineGetLocalPort();
    }

    anError = gsUdpEngineAddMsgHandler(iconnection->mHeader, iconnection->mHeader, 0,
                            (void *)gpiPeerAcceptedCallback, (void *)gpiPeerLeftCallback,
                            (void *)gpiPeerPingReplyCallback, (void *)gpiPeerMessageCallback, connection);
    if (anError != 0) {
        gpiSetError((int *)connection, 8, (int)g_021A4734);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }

    if (iconnection->firewall)
        iconnection->peerPort = 0;

    iconnection->cmSocket = socket(2, 1, 0);
    if (iconnection->cmSocket == -1) {
        gpiSetError((int *)connection, 5, (int)g_021A4760);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }

    rcode = SetSockBlocking(iconnection->cmSocket, 0);
    if (!rcode) {
        gpiSetError((int *)connection, 5, (int)g_021A4788);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }

    {
        unsigned int *p = (unsigned int *)&address;
        p[0] = 0;
        p[1] = 0;
    }
    address.family = 2;
    if (inet_addr((int)g_021A45D8) == 0xFFFFFFFF) {
        host = SOC_GetHostByName(g_021A45D8);
        if (host == 0) {
            gpiSetError((int *)connection, 5, (int)g_021A47BC);
            gpiCallErrorCallback((int *)connection, 3, 1);
            return 3;
        }
        address.addr = *(unsigned int *)host->addrList[0];
    } else {
        address.addr = inet_addr((int)g_021A45D8);
    }
    address.port = 0xcc74;

    rcode = connect(iconnection->cmSocket, &address, sizeof(address));
    if (rcode == -1) {
        error = GOAGetLastError(iconnection->cmSocket);
        if (error != -6 && error != -26 && error != -76) {
            gpiSetError((int *)connection, 5, (int)g_021A47F0);
            gpiCallErrorCallback((int *)connection, 3, 1);
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
int gpiConnect(void **connection, char *nick, char *uniquenick, char *email,
                  char *password, char *authtoken, char *partnerchallenge,
                  char *cdkey, int firewall, int newuser, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIConnectData *data;
    GPIOperation *operation;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int result;

    if (iconnection->connectState == 4) {
        int __result__ = gpiReset(connection);
        if (__result__ != 0) return __result__;
    }
    if (iconnection->connectState != 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4818);
        return 2;
    }

    iconnection->firewall = 1;
    strzcpy(iconnection->nick, (int)nick, 31);
    strzcpy(iconnection->uniquenick, (int)uniquenick, 21);
    strzcpy(iconnection->email, (int)email, 51);
    strzcpy(iconnection->password, (int)password, 31);
    _strlwr(iconnection->email);

    data = (GPIConnectData *)gsimalloc(sizeof(GPIConnectData));
    if (data == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A482C);
        return 1;
    }
    MSL_C_LIB_MemsetPtr(data, 0, sizeof(GPIConnectData));
    data->newuser = newuser;
    if (authtoken[0] && partnerchallenge[0]) {
        strzcpy(data->authtoken, (int)authtoken, 256);
        strzcpy(data->partnerchallenge, (int)partnerchallenge, 256);
    }
    if (cdkey)
        strzcpy(data->cdkey, (int)cdkey, 65);

    {
        int __result__ = gpiAddOperation(connection, 0, data, &operation, blocking, callback, param);
        if (__result__ != 0) return __result__;
    }

    result = gpiStartConnect(connection, operation);
    if (result != 0) {
        operation->result = result;
        gpiFailedOpCallback(connection, operation);
        gpiDisconnect(connection, 0);
        return result;
    }

    if (operation->blocking) {
        int __result__ = gpiProcess(connection, operation->id);
        if (__result__ != 0) return __result__;
    }
    return 0;
}




/*
 * sdk:      gpiSendLogin (gpiconnect.o)
 */
int gpiSendLogin(void **connection, GPIConnectData *data)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char buffer[512];
    char response[33];
    GPIProfile *profile;
    char *passphrase;
    char userBuffer[82];
    char partnerBuffer[11];
    char *user;

    randomString(data->userChallenge, sizeof(data->userChallenge) - 1);

    if (data->partnerchallenge[0])
        passphrase = data->partnerchallenge;
    else
        passphrase = iconnection->password;
    GSMD5Digest((unsigned char *)passphrase, strlen((const u8 *)passphrase), data->passwordHash);

    if (iconnection->partnerID != 0)
        OS_SPrintf(partnerBuffer, g_021A483C, iconnection->partnerID);
    else
        partnerBuffer[0] = '\0';

    if (data->authtoken[0]) {
        user = data->authtoken;
    } else if (iconnection->uniquenick[0]) {
        OS_SPrintf(userBuffer, g_021A4840, partnerBuffer, iconnection->uniquenick);
        user = userBuffer;
    } else {
        OS_SPrintf(userBuffer, g_021A4848, partnerBuffer, iconnection->nick, iconnection->email);
        user = userBuffer;
    }

    OS_SPrintf(buffer, g_021A4850, data->passwordHash, g_021A4860, user,
                  data->userChallenge, data->serverChallenge, data->passwordHash);
    GSMD5Digest((unsigned char *)buffer, strlen((const u8 *)buffer), response);

    if (iconnection->infoCaching) {
        gpiFindProfileByUser(connection, iconnection->nick, iconnection->email, &profile);
        if (profile != 0) {
            iconnection->userid = profile->userId;
            iconnection->profileid = profile->profileId;
        }
    }

    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4894);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A489C);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), data->userChallenge);
    if (data->authtoken[0]) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48A8);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), data->authtoken);
    } else if (iconnection->uniquenick[0]) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);
    } else {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48C4);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48CC);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    }
    if (iconnection->userid != 0) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48D0);
        gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->userid);
    }
    if (iconnection->profileid != 0) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48DC);
        gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->profileid);
    }
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48F4);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), response);
    if (iconnection->firewall == 1)
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4900);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A490C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->peerPort);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGsAvailabilityGameName);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A493C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), 0x3b);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A494C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->quietModeFlags);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
    return 0;
}




int gpiSendNewuser(void **connection, GPIConnectData *data)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    unsigned long i;
    char passwordenc[45];
    char cdkeyxor[65];
    char cdkeyenc[90];
    unsigned long cdkeylen;
    char aRand;

    gpiEncodeString(iconnection->password, passwordenc);

    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4964);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4970);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4978);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4980);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), passwordenc);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGsAvailabilityGameName);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);

    if (data->cdkey[0] != '\0') {
        cdkeylen = strlen((const u8 *)data->cdkey);
        Util_RandSeed(0x79707367);
        for (i = 0; i < cdkeylen; i++) {
            aRand = (char)Util_RandInt(0, 0xFF);
            cdkeyxor[i] = (char)(data->cdkey[i] ^ aRand);
        }
        cdkeyxor[i] = '\0';
        B64Encode(cdkeyxor, cdkeyenc, (int)cdkeylen, 1);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4990);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), cdkeyenc);
    }

    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
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
int gpiProcessConnect(void **connection, GPIOperation *operation, char *input)
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
            gpiRemoveProfileByID(connection, iconnection->profileid);
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
        if (memcmp((const u8 *)check, (const u8 *)buffer, 32) != 0) {
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



/*
 * sdk:      gpiCheckConnect (gpiconnect.o)
 */
int gpiCheckConnect(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int state;
    int result;

    if ((result = gpiCheckSocketConnect((int *)connection, iconnection->cmSocket, &state)) != 0)
        return result;
    if (state == 4) {
        gpiSetError((int *)connection, 0x107, (int)g_021A4A58);
        gpiCallErrorCallback((int *)connection, 4, 1);
        return 4;
    }
    if (state == 0)
        return 0;
    iconnection->connectState = 2;
    return 0;
}



/*
 * sdk:      gpiDisconnectCleanupProfile (libdwcgsgp.TWL.HYB.a gpiconnect.o)
 */
int gpiDisconnectCleanupProfile(GPIConnection **connection, GPIProfile *profile)
{
    GPIConnection *iconnection;

    iconnection = *connection;
    if (profile->buddyStatus) {
        profile->buddyOrBlockCache = 1;
        gsifree(profile->buddyStatus->statusString);
        profile->buddyStatus->statusString = 0;
        gsifree(profile->buddyStatus->locationString);
        profile->buddyStatus->locationString = 0;
        gsifree(profile->buddyStatus);
        profile->buddyStatus = 0;
    }
    if (profile->buddyStatusInfo) {
        profile->buddyOrBlockCache = 1;
        gsifree(profile->buddyStatusInfo->richStatus);
        profile->buddyStatusInfo->richStatus = 0;
        gsifree(profile->buddyStatusInfo->gameType);
        profile->buddyStatusInfo->gameType = 0;
        gsifree(profile->buddyStatusInfo->gameVariant);
        profile->buddyStatusInfo->gameVariant = 0;
        gsifree(profile->buddyStatusInfo->gameMapName);
        profile->buddyStatusInfo->gameMapName = 0;
        if (profile->buddyStatusInfo->extendedInfoKeys) {
            ArrayFree(profile->buddyStatusInfo->extendedInfoKeys);
            profile->buddyStatusInfo->extendedInfoKeys = 0;
        }
        gsifree(profile->buddyStatusInfo);
        profile->buddyStatusInfo = 0;
    }
    if (profile->blocked)
        profile->buddyOrBlockCache = 1;
    gsifree(profile->authSig);
    profile->authSig = 0;
    gsifree(profile->peerSig);
    profile->peerSig = 0;
    profile->requestCount = 0;
    if (profile->cache == 0 || (iconnection->infoCachingBuddyAndBlockOnly == 1 && profile->buddyOrBlockCache == 0)) {
        gpiRemoveProfile((const int *)connection, profile);
        return 0;
    }
    return 1;
}



/*
 * sdk:      gpiDisconnect (gpiconnect.o)
 */
void gpiDisconnect(void **connection, int tellServer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *peer;
    GPIPeer *delPeer;
    int connClosed;

    if (iconnection->connectState == 4)
        return;

    if (iconnection->connectState != 0) {
        if (tellServer && iconnection->connectState == 3) {
            gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4A80);
            gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->sessKey);
            gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
        }
        gpiSendFromBuffer(connection, iconnection->cmSocket, &iconnection->outputBuffer, &connClosed, 1, g_021A4A94);
        if (iconnection->cmSocket != -1) {
            shutdown(iconnection->cmSocket, 2);
            closesocket(iconnection->cmSocket);
            iconnection->cmSocket = -1;
        }
        iconnection->connectState = 4;
        iconnection->userid = 0;
        iconnection->profileid = 0;
    }

    if (gsUdpEngineIsInitialized()) {
        gsUdpEngineRemoveMsgHandler(iconnection->mHeader);
        if (gsUdpEngineNoMoreMsgHandlers() && gsUdpEngineNoApp())
            gsUdpEngineShutdown();
    }

    gsifree(iconnection->socketBuffer.buffer);
    iconnection->socketBuffer.buffer = 0;
    gsifree(iconnection->inputBuffer);
    iconnection->inputBuffer = 0;
    gsifree(iconnection->outputBuffer.buffer);
    iconnection->outputBuffer.buffer = 0;
    gsifree(iconnection->updateproBuffer.buffer);
    iconnection->updateproBuffer.buffer = 0;
    gsifree(iconnection->updateuiBuffer.buffer);
    iconnection->updateuiBuffer.buffer = 0;

    while (iconnection->operationList)
        gpiRemoveOperation(connection, iconnection->operationList);
    iconnection->operationList = 0;

    for (peer = iconnection->peerList; peer; ) {
        delPeer = peer;
        peer = peer->pnext;
        gpiDestroyPeer(connection, delPeer);
    }
    iconnection->peerList = 0;

    while (!gpiProfileMap(connection, (int (*)(void **, void *, void *))gpiDisconnectCleanupProfile, 0)) {
    }
}



/*
 * sdk:      gpiProcessRemoteAuthResponse (gpiconnect.o)
 */
int gpiProcessRemoteAuthResponse(void **connection, char *input)
{
    GPIConnection *iconnection;
    char buffer[512];

    iconnection = (GPIConnection *)*connection;
    if (gpiCheckForError((int *)connection, input, 1))
        return 4;
    if (!gpiValueForKey(iconnection->inputBuffer, g_021A492C, buffer, 512)) {
        gpiSetError((int *)connection, 1, (int)g_021A49AC);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    iconnection->namespaceID = atoi((u32)buffer);
    if (!gpiValueForKey(iconnection->inputBuffer, g_021A48E8, buffer, 512)) {
        gpiSetError((int *)connection, 1, (int)g_021A49AC);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    iconnection->partnerID = atoi((u32)buffer);
    return 0;
}
