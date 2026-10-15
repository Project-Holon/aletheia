/*
 * file:     gp.c
 * unit:     yes
 * function: func_021858FC, gpDestroy, func_02185948, func_0218597C, gpConnectPreAuthenticatedA, func_02185ACC, gpProfileSearchA, gpGetInfo, func_02185CB4, gpSendBuddyRequestA, func_02185E94, gpDenyBuddyRequest, func_02185FA4, gpGetBuddyStatus, gpGetBuddyIndex, func_021861A8, func_02186220, gpSetStatusA, gpSendBuddyMessageA, gpGetReversBuddiesList, func_02186618
 * address:  0x021858FC
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
 *   gpiInitialize   0x02186664  arm
 *   __GSIACResult   0x021ACEF8  data
 *   gpiDestroy  0x02186788  arm  ov009
 *   gpiProcess  0x02186E9C  arm
 *   gpiSetErrorString  0x02193734  arm
 *   g_021A4000         0x021A4000  data
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiConnect  0x0218A624  arm   ov009
 *   g_021A4010     0x021A4010  data
 *   g_021A4020     0x021A4020  data
 *   gpiDisconnect  0x0218B760  arm
 *   gpiReset       0x021867E8  arm
 *   gpiProfileSearch  0x021906E0  arm   ov009
 *   gpiGetInfo  0x0218D4A4  arm   ov009
 *   g_021A4024     0x021A4024  data  ov009
 *   gpiSetInfoi        0x0218CC48  arm
 *   strzcpy  0x0219327C  arm
 *   gpiBuddyDeletedLocally  0x02189300  arm
 *   gpiAppendStringToBuffer  0x0218946C  arm
 *   gpiAppendIntToBuffer  0x0218949C  arm
 *   g_021A4054     0x021A4054  data
 *   g_021A4064     0x021A4064  data
 *   g_021A4070     0x021A4070  data
 *   g_021A407C     0x021A407C  data
 *   g_021A408C     0x021A408C  data
 *   g_021A4098     0x021A4098  data
 *   gpiAuthBuddyRequest  0x02188FD8  arm
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   gsifree  0x0217EAE0  arm   ov009
 *   gpiCanFreeProfile  0x02190140  arm   ov009
 *   gpiRemoveProfile  0x0218FF24  arm   ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   func_0219008C  0x0219008C  arm   ov009
 *   g_021A40A0     0x021A40A0  data
 *   g_021A40B0     0x021A40B0  data
 *   gpiGetProfile  0x0218FD9C  arm
 *   gpiDeleteBuddy     0x021890E0  arm
 *   strcmp  0x020948E0  arm
 *   g_021A40C0     0x021A40C0  data
 *   g_021A40D8     0x021A40D8  data
 *   g_021A40F0     0x021A40F0  data
 *   g_021A40FC     0x021A40FC  data
 *   g_021A410C     0x021A410C  data
 *   gpiSendBuddyMessage  0x021889A0  arm   ov009
 *   g_021A4118     0x021A4118  data  ov009
 *   gpiOthersBuddyList  0x021908B0  arm   ov009
 */
typedef struct GPIConnection_02185948 GPIConnection_02185948;

typedef struct GPIConnection_0218597C GPIConnection_0218597C;

typedef struct GPIConnection_021859C0 {
    char pad0[0x108];
    int f108;
} GPIConnection_021859C0;

typedef struct GPConnectResponseArg {
    int a[8];
} GPConnectResponseArg;

typedef struct GPIConnection_02185ACC GPIConnection_02185ACC;

typedef struct GPIConnection_02185B10 {
    unsigned char pad0[0x108];
    int f108;
} GPIConnection_02185B10;

typedef struct GPProfileSearchResponseArg {
    int a;
    int b;
    int c;
    int d;
} GPProfileSearchResponseArg;

typedef void (*GPCallback)(void **, void *, void *);

typedef struct GPIConnection_02185BD8 {
    unsigned char pad0[0x108];
    int f108;
    unsigned char pad1[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection_02185BD8;

typedef struct GPGetInfoResponseArg {
    unsigned int w[0x81];
} GPGetInfoResponseArg;

typedef struct GPIConnection_02185CB4 GPIConnection_02185CB4;

typedef struct GPIConnection_02185D04 GPIConnection_02185D04;

typedef struct GPIConnection_02185E94 GPIConnection_02185E94;

typedef struct GPIProfile_021858FC {
    unsigned char pad0[0x14];
    void *f14;
    int f18;
} GPIProfile_021858FC;

typedef struct GPIConnection_02185EE4 {
    unsigned char pad0[0x100];
    int f100;
    unsigned char pad1[0x108 - 0x104];
    int f108;
    unsigned char pad2[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection_02185EE4;

typedef struct GPIConnection_02185FA4 GPIConnection_02185FA4;

typedef struct GPIBuddyStatus {
    int f0;
    int status;
    char *statusString;
    char *locationString;
    int ip;
    unsigned short port;
    int quietModeFlags;
} GPIBuddyStatus;

typedef struct GPIProfile_02185FD4 {
    int f0;
    int f4;
    GPIBuddyStatus *buddyStatus;
} GPIProfile_02185FD4;

typedef struct GPBuddyStatus {
    int profile;
    int status;
    char statusString[256];
    char locationString[256];
    int ip;
    int port;
    int quietModeFlags;
} GPBuddyStatus;

typedef struct GPIConnection_02185FD4 {
    char pad0[0x108];
    int f108;
    char pad1[0x5d0 - 0x10c];
    int numBuddies;
} GPIConnection_02185FD4;

typedef struct GPIProfile_02186108 {
    int f0;
    int f4;
    int *f8;
    int *fC;
} GPIProfile_02186108;

typedef struct GPIConnection_02186108 {
    unsigned char pad[0x108];
    int f108;
} GPIConnection_02186108;

typedef struct GPIConnection_021861A8 GPIConnection_021861A8;

typedef struct GPIProfile_021861A8 GPIProfile_021861A8;

typedef struct GPIConnection_02186220 GPIConnection_02186220;

typedef struct GPIBuffer GPIBuffer;

typedef struct GPIConnection_0218627C {
    char pad000[0x108];
    int f108;                      /* 0x108 */
    char pad10C[0x8C];
    int sessKey;                   /* 0x198 */
    char pad19C[0x58];
    int connectState;              /* 0x1F4 */
    char pad1F8[0x18];
    char outputBuffer[16];         /* 0x210 */
    char pad220[0x1C];
    int lastStatus;                /* 0x23C */
    char pad240[0x178];
    char lastStatusString[256];    /* 0x3B8 */
    char lastLocationString[256];  /* 0x4B8 */
} GPIConnection_0218627C;

typedef void *GPConnection;

typedef struct GPIConnection_021864CC {
    unsigned char pad0[0x108];
    int f108;
    unsigned char pad1[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection_021864CC;

typedef struct GPIConnection_02186564 {
    unsigned char pad0[0x108];
    int f108;
    unsigned char pad1[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection_02186564;

typedef struct GPGetReverseBuddiesListResponseArg {
    int a;
    int b;
    int c;
} GPGetReverseBuddiesListResponseArg;

typedef struct GPIConnection_02186618 GPIConnection_02186618;

extern int gpiInitialize(void **connection, int productID, int namespaceID, int partnerID);
extern void gpiDestroy(void **connection);
extern int gpiProcess(void **connection, int blockingOperationID);
extern void gpiSetErrorString(int *p, int b);
extern int gpiConnect(void **connection, char *nick, char *uniquenick, char *email, char *password, char *authtoken, char *partnerchallenge, char *cdkey, int firewall, int newuser, int blocking, void (*callback)(void **, void *, void *), void *param);
extern void gpiDisconnect(void **connection, int tellServer);
extern int gpiReset(void **connection);
extern int gpiProfileSearch(int *connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int skip, int blocking, int callback, int param);
extern int gpiGetInfo(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int gpiSetInfoi(void **connection, int info, int value);
extern void strzcpy(char *p, int b, int n);
extern int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern int gpiAuthBuddyRequest(void **connection, int profile);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile_021858FC **pProfile);
extern void gsifree(void *ptr);
extern int gpiCanFreeProfile(char *p);
extern void gpiRemoveProfile(const int *p, void *profile);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int val, unsigned long len);
extern GPIProfile_02185FD4 *func_0219008C(void **connection, int buddyIndex);
extern int gpiGetProfile(void **connection, int profileid, GPIProfile_021861A8 **pProfile);
extern int gpiDeleteBuddy(void **connection, int profile, int sendServerRequest);
extern int strcmp(const char *a, const char *b);
extern int gpiSendBuddyMessage(void **connection, int profileid, int type, char *message,
                         int sendOption, void *peerOp);
extern int gpiOthersBuddyList(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param);
int gpInitialize(void **connection, int productID, int namespaceID, int partnerID);
void gpDestroy(int **p);
int gpProcess(void **connection);
int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param);
int gpConnectPreAuthenticatedA(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, void (*callback)(void **, void *, void *), void *param);
void gpDisconnect(void **connection);
int gpProfileSearchA(void **connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int blocking, GPCallback callback, void *param);
int gpGetInfo(void **connection, int profile, int checkCache, int blocking, GPCallback callback, void *param);
int gpSetInfosA(void **connection, int info, int value);
int gpSendBuddyRequestA(void **connection, int profile, char *reason);
int gpAuthBuddyRequest(void **connection, int profile);
int gpDenyBuddyRequest(void **connection, int profile);
int gpGetNumBuddies(void **connection, int *numBuddies);
int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
int gpGetBuddyIndex(void **connection, int profile, int *index);
int gpIsBuddy(void **connection, int profile);
int gpDeleteBuddy(void **connection, int profile);
int gpSetStatusA(GPConnection *connection, int status, const char *statusString, const char *locationString);
int gpSendBuddyMessageA(void **connection, int profile, char *message);
int gpGetReversBuddiesList(void **connection, int *targets, int numOfTargets, int blocking, GPCallback callback, void *param);
int gpGetLoginTicket(void **connection, char *loginTicket);
extern int __GSIACResult;
extern char g_021A4000[];
extern char g_021A4010[];
extern char g_021A4020[];
extern char g_021A4024[];
extern char g_021A4054[];
extern char g_021A4064[];
extern char g_021A4070[];
extern char g_021A407C[];
extern char g_021A408C[];
extern char g_021A4098[];
extern char g_021A40A0[];
extern char g_021A40B0[];
extern char g_021A40C0[];
extern char g_021A40D8[];
extern char g_021A40F0[];
extern char g_021A40FC[];
extern char g_021A410C[];
extern char g_021A4118[];





int gpInitialize(void **connection, int productID, int namespaceID, int partnerID)
{
    if (__GSIACResult != 1)
        return 2;
    if (connection == 0)
        return 2;
    return gpiInitialize(connection, productID, namespaceID, partnerID);
}





/*
 * Calls the release helper when the pointer and its block are both there.
 */
void gpDestroy(int **p)
{
    if (p && *p) {
        gpiDestroy((void **)p);
    }
}





int gpProcess(void **connection)
{
    GPIConnection_02185948 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185948 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    return gpiProcess(connection, 0);
}





int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param)
{
    GPIConnection_0218597C *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_0218597C *)*connection;
    if ((unsigned int)func < 9) {
        *(void **)((char *)iconnection + func * 8 + 0x1a8) = (void *)callback;
        *(void **)((char *)iconnection + func * 8 + 0x1ac) = param;
        return 0;
    }
    gpiSetErrorString((int *)connection, (int)g_021A4000);
    return 2;
}





/*
 * sdk:      gpConnectPreAuthenticatedA (libdwcgsgp.TWL.HYB.a gp.o)
 */
int gpConnectPreAuthenticatedA(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, void (*callback)(void **, void *, void *), void *param)
{
    GPIConnection_021859C0 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_021859C0 *)*connection;
    if (!authtoken || !authtoken[0])
        return 2;
    if (!partnerchallenge || !partnerchallenge[0])
        return 2;
    if (!callback) {
        gpiSetErrorString((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPConnectResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    return gpiConnect(connection, g_021A4020, g_021A4020, g_021A4020, g_021A4020, authtoken, partnerchallenge, 0, firewall, 0, blocking, callback, param);
}





void gpDisconnect(void **connection)
{
    GPIConnection_02185ACC *iconnection;
    int oldState;

    if (!connection || !*connection)
        return;
    iconnection = (GPIConnection_02185ACC *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return;
    oldState = *(int *)((char *)iconnection + 0x1f4);
    gpiDisconnect(connection, 1);
    gpiReset(connection);
    if (oldState == 3)
        *(int *)((char *)iconnection + 0x1f4) = 4;
}





/*
 * sdk:      gpProfileSearchA (gp.o)
 */
int gpProfileSearchA(void **connection, char *nick, char *uniquenick, char *email,
                  char *firstname, char *lastname, int icquin, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection_02185B10 *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection_02185B10 *)*connection) == 0)
        return 2;
    if (callback == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPProfileSearchResponseArg arg = {0};
        arg.c = 0x601;
        callback(connection, &arg, param);
        return 0;
    }
    return gpiProfileSearch((int *)connection, nick, uniquenick, email, firstname, lastname, icquin, 0,
                         blocking, (int)callback, (int)param);
}





/*
 * sdk:      gpGetInfo (gp.o)
 */
int gpGetInfo(void **connection, int profile, int checkCache, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection_02185BD8 *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection_02185BD8 *)*connection) == 0 || profile == 0)
        return 2;
    if (callback == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPGetInfoResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    if (iconnection->f1F4 == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    return gpiGetInfo(connection, profile, checkCache, blocking, callback, param);
}





int gpSetInfosA(void **connection, int info, int value)
{
    GPIConnection_02185CB4 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185CB4 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    return gpiSetInfoi(connection, info, value);
}





/*
 * sdk:      gpSendBuddyRequestA (gp.o)
 */
int gpSendBuddyRequestA(void **connection, int profile, char *reason)
{
    int i;
    char reasonFixed[1025];
    GPIConnection_02185D04 *iconnection;

    if (connection == 0 || *connection == 0) return 2;
    iconnection = (GPIConnection_02185D04 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0) return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (reason == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4054);
        return 2;
    }
    strzcpy(reasonFixed, (int)reason, 1025);
    for (i = 0; reasonFixed[i] != 0; i++) {
        if (reasonFixed[i] == '\\') reasonFixed[i] = '/';
    }
    gpiBuddyDeletedLocally(connection, profile, 0);
    gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), g_021A4064);
    gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), g_021A4070);
    gpiAppendIntToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), *(int *)((char *)iconnection + 0x198));
    gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), g_021A407C);
    gpiAppendIntToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), profile);
    gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), g_021A408C);
    gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), reasonFixed);
    gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x210), g_021A4098);
    return 0;
}





int gpAuthBuddyRequest(void **connection, int profile)
{
    GPIConnection_02185E94 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185E94 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    return gpiAuthBuddyRequest(connection, profile);
}





/*
 * sdk:      gpDenyBuddyRequest (gp.o)
 */
int gpDenyBuddyRequest(void **connection, int profile)
{
    GPIProfile_021858FC *pProfile;
    GPIConnection_02185EE4 *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection_02185EE4 *)*connection) == 0)
        return 2;
    if (iconnection->f108 != 0)
        return 0;
    if (iconnection->f1F4 == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (!func_0218FD9C(connection, profile, &pProfile))
        return 0;
    pProfile->f18--;
    if (iconnection->f100 == 0 && pProfile->f18 <= 0) {
        gsifree(pProfile->f14);
        pProfile->f14 = 0;
        if (gpiCanFreeProfile((char *)pProfile))
            gpiRemoveProfile((const int *)connection, pProfile);
    }
    return 0;
}




int gpGetNumBuddies(void **connection, int *numBuddies)
{
    GPIConnection_02185FA4 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185FA4 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0) {
        *numBuddies = 0;
        return 0;
    }
    *numBuddies = *(int *)((char *)iconnection + 0x5d0);
    return 0;
}




/*
 * sdk:      gpGetBuddyStatus (libdwcgsgp.TWL.HYB.a gp.o)
 */
int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status)
{
    GPIConnection_02185FD4 *iconnection;
    GPIProfile_02185FD4 *profile;
    int num;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185FD4 *)*connection;
    if (iconnection->f108 != 0) {
        MSL_C_LIB_MemsetPtr(status, 0, sizeof(GPBuddyStatus));
        return 0;
    }
    if (status == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A40A0);
        return 2;
    }
    num = iconnection->numBuddies;
    if (index < 0 || index >= num) {
        gpiSetErrorString((int *)connection, (int)g_021A40B0);
        return 2;
    }
    profile = func_0219008C(connection, index);
    if (profile == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A40B0);
        return 2;
    }
    status->profile = profile->f0;
    status->status = profile->buddyStatus->status;
    if (profile->buddyStatus->statusString == 0)
        status->statusString[0] = 0;
    else
        strzcpy(status->statusString, (int)profile->buddyStatus->statusString, 256);
    if (profile->buddyStatus->locationString == 0)
        status->locationString[0] = 0;
    else
        strzcpy(status->locationString, (int)profile->buddyStatus->locationString, 256);
    status->ip = profile->buddyStatus->ip;
    status->port = profile->buddyStatus->port;
    status->quietModeFlags = profile->buddyStatus->quietModeFlags;
    return 0;
}




/*
 * sdk:      gpGetBuddyIndex (gp.o)
 */
int gpGetBuddyIndex(void **connection, int profile, int *index)
{
    GPIProfile_02186108 *pProfile;

    if (connection == 0 || *connection == 0)
        return 2;
    if (((GPIConnection_02186108 *)*connection)->f108 != 0) {
        *index = 0;
        return 0;
    }
    if (func_0218FD9C(connection, profile, (GPIProfile_021858FC * *)&pProfile) && pProfile->f8 != 0)
        *index = *pProfile->f8;
    else if (func_0218FD9C(connection, profile, (GPIProfile_021858FC * *)&pProfile) && pProfile->fC != 0)
        *index = *pProfile->fC;
    else
        *index = -1;
    return 0;
}



int gpIsBuddy(void **connection, int profile)
{
    GPIConnection_021861A8 *iconnection;
    GPIProfile_021861A8 *pProfile;

    if (!connection || !*connection)
        return 0;
    iconnection = (GPIConnection_021861A8 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (gpiGetProfile(connection, profile, &pProfile) && *(int *)((char *)pProfile + 8) != 0)
        return 1;
    if (gpiGetProfile(connection, profile, &pProfile) && *(int *)((char *)pProfile + 0xc) != 0)
        return 1;
    return 0;
}



int gpDeleteBuddy(void **connection, int profile)
{
    GPIConnection_02186220 *iconnection;
    int __result__;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02186220 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    __result__ = gpiDeleteBuddy(connection, profile, 1);
    if (__result__ == 0)
        return 0;
    return __result__;
}



/*
 * sdk:      gpSetStatusA (libdwcgsgp.TWL.HYB.a gp.o)
 */
int gpSetStatusA(GPConnection *connection, int status, const char *statusString, const char *locationString)
{
    char statusStringFixed[256];
    char locationStringFixed[256];
    GPIConnection_0218627C *iconnection;
    int i;

    if (connection == 0 || (iconnection = (GPIConnection_0218627C *)*connection) == 0)
        return 2;
    if (iconnection->f108 != 0)
        return 0;
    if (iconnection->connectState == 4)
    {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (statusString == 0)
    {
        gpiSetErrorString((int *)connection, (int)g_021A40C0);
        return 2;
    }
    if (locationString == 0)
    {
        gpiSetErrorString((int *)connection, (int)g_021A40D8);
        return 2;
    }

    strzcpy(statusStringFixed, (int)statusString, sizeof(statusStringFixed));
    for (i = 0; statusStringFixed[i]; i++)
        if (statusStringFixed[i] == '\\')
            statusStringFixed[i] = '/';
    strzcpy(locationStringFixed, (int)locationString, sizeof(locationStringFixed));
    for (i = 0; locationStringFixed[i]; i++)
        if (locationStringFixed[i] == '\\')
            locationStringFixed[i] = '/';

    if (status == iconnection->lastStatus
        && strcmp(statusStringFixed, iconnection->lastStatusString) == 0
        && strcmp(locationStringFixed, iconnection->lastLocationString) == 0)
        return 0;

    iconnection->lastStatus = status;
    strzcpy(iconnection->lastStatusString, (int)statusStringFixed, sizeof(iconnection->lastStatusString));
    strzcpy(iconnection->lastLocationString, (int)locationStringFixed, sizeof(iconnection->lastLocationString));

    gpiAppendStringToBuffer((int *)connection, (int *)iconnection->outputBuffer, g_021A40F0);
    gpiAppendIntToBuffer((int *)connection, (int *)iconnection->outputBuffer, status);
    gpiAppendStringToBuffer((int *)connection, (int *)iconnection->outputBuffer, g_021A4070);
    gpiAppendIntToBuffer((int *)connection, (int *)iconnection->outputBuffer, iconnection->sessKey);
    gpiAppendStringToBuffer((int *)connection, (int *)iconnection->outputBuffer, g_021A40FC);
    gpiAppendStringToBuffer((int *)connection, (int *)iconnection->outputBuffer, statusStringFixed);
    gpiAppendStringToBuffer((int *)connection, (int *)iconnection->outputBuffer, g_021A410C);
    gpiAppendStringToBuffer((int *)connection, (int *)iconnection->outputBuffer, locationStringFixed);
    gpiAppendStringToBuffer((int *)connection, (int *)iconnection->outputBuffer, g_021A4098);
    return 0;
}



/*
 * sdk:      gpSendBuddyMessageA (gp.o)
 */
int gpSendBuddyMessageA(void **connection, int profile, char *message)
{
    GPIConnection_021864CC *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection_021864CC *)*connection) == 0)
        return 2;
    if (iconnection->f108 != 0)
        return 0;
    if (iconnection->f1F4 == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (message == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4118);
        return 2;
    }
    return gpiSendBuddyMessage(connection, profile, 1, message, 0, 0);
}



int gpGetReversBuddiesList(void **connection, int *targets, int numOfTargets, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection_02186564 *iconnection;

    if (connection == 0 || *connection == 0)
        return 2;
    if (callback == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4010);
        return 2;
    }
    iconnection = (GPIConnection_02186564 *)*connection;
    if (iconnection->f1F4 == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPGetReverseBuddiesListResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    return gpiOthersBuddyList(connection, targets, numOfTargets, blocking, callback, param);
}



int gpGetLoginTicket(void **connection, char *loginTicket)
{
    GPIConnection_02186618 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02186618 *)*connection;
    __memcpy(loginTicket, (char *)iconnection + 0x614, 25);
    return 0;
}
