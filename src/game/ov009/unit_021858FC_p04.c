/*
 * file:     unit_021858FC_p04.c
 * unit:     yes
 * function: func_021861A8, func_02186220, func_0218627C, func_021864CC, func_02186564, func_02186618
 * address:  0x021861A8
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
 *   gpiGetProfile  0x0218FD9C  arm
 *   gpiSetErrorString  0x02193734  arm
 *   gpiDeleteBuddy     0x021890E0  arm
 *   g_021A4024         0x021A4024  data
 *   func_02193734  0x02193734  arm  ov009
 *   func_0219327C  0x0219327C  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_0218949C  0x0218949C  arm  ov009
 *   g_021A40C0     0x021A40C0  data
 *   g_021A40D8     0x021A40D8  data
 *   g_021A40F0     0x021A40F0  data
 *   g_021A4070     0x021A4070  data
 *   g_021A40FC     0x021A40FC  data
 *   g_021A410C     0x021A410C  data
 *   g_021A4098     0x021A4098  data
 *   func_021889A0  0x021889A0  arm   ov009
 *   g_021A4118     0x021A4118  data  ov009
 *   func_021908B0  0x021908B0  arm   ov009
 *   g_021A4010     0x021A4010  data  ov009
 */
typedef struct GPIConnection_021861A8 GPIConnection_021861A8;

typedef struct GPIProfile GPIProfile;

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

typedef void (*GPCallback)(void **, void *, void *);

typedef struct GPIConnection_02186618 GPIConnection_02186618;

extern int gpiGetProfile(void **connection, int profileid, GPIProfile **pProfile);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiDeleteBuddy(void **connection, int profile, int sendServerRequest);
extern void func_02193734(int *p, int b);
extern void func_0219327C(char *p, int b, int n);
extern int func_020948E0(const char *a, const char *b);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern int func_021889A0(void **connection, int profileid, int type, char *message,
                         int sendOption, void *peerOp);
extern int func_021908B0(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param);
int gpIsBuddy(void **connection, int profile);
int gpDeleteBuddy(void **connection, int profile);
int func_0218627C(GPConnection *connection, int status, const char *statusString, const char *locationString);
int func_021864CC(void **connection, int profile, char *message);
int func_02186564(void **connection, int *targets, int numOfTargets, int blocking, GPCallback callback, void *param);
int gpGetLoginTicket(void **connection, char *loginTicket);
extern char g_021A4024[];
extern char g_021A40C0[];
extern char g_021A40D8[];
extern char g_021A40F0[];
extern char g_021A4070[];
extern char g_021A40FC[];
extern char g_021A410C[];
extern char g_021A4098[];
extern char g_021A4118[];
extern char g_021A4010[];


int gpIsBuddy(void **connection, int profile)
{
    GPIConnection_021861A8 *iconnection;
    GPIProfile *pProfile;

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
        gpiSetErrorString(connection, g_021A4024);
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
int func_0218627C(GPConnection *connection, int status, const char *statusString, const char *locationString)
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
        func_02193734((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (statusString == 0)
    {
        func_02193734((int *)connection, (int)g_021A40C0);
        return 2;
    }
    if (locationString == 0)
    {
        func_02193734((int *)connection, (int)g_021A40D8);
        return 2;
    }

    func_0219327C(statusStringFixed, (int)statusString, sizeof(statusStringFixed));
    for (i = 0; statusStringFixed[i]; i++)
        if (statusStringFixed[i] == '\\')
            statusStringFixed[i] = '/';
    func_0219327C(locationStringFixed, (int)locationString, sizeof(locationStringFixed));
    for (i = 0; locationStringFixed[i]; i++)
        if (locationStringFixed[i] == '\\')
            locationStringFixed[i] = '/';

    if (status == iconnection->lastStatus
        && func_020948E0(statusStringFixed, iconnection->lastStatusString) == 0
        && func_020948E0(locationStringFixed, iconnection->lastLocationString) == 0)
        return 0;

    iconnection->lastStatus = status;
    func_0219327C(iconnection->lastStatusString, (int)statusStringFixed, sizeof(iconnection->lastStatusString));
    func_0219327C(iconnection->lastLocationString, (int)locationStringFixed, sizeof(iconnection->lastLocationString));

    func_0218946C((int *)connection, (int *)iconnection->outputBuffer, g_021A40F0);
    func_0218949C((int *)connection, (int *)iconnection->outputBuffer, status);
    func_0218946C((int *)connection, (int *)iconnection->outputBuffer, g_021A4070);
    func_0218949C((int *)connection, (int *)iconnection->outputBuffer, iconnection->sessKey);
    func_0218946C((int *)connection, (int *)iconnection->outputBuffer, g_021A40FC);
    func_0218946C((int *)connection, (int *)iconnection->outputBuffer, statusStringFixed);
    func_0218946C((int *)connection, (int *)iconnection->outputBuffer, g_021A410C);
    func_0218946C((int *)connection, (int *)iconnection->outputBuffer, locationStringFixed);
    func_0218946C((int *)connection, (int *)iconnection->outputBuffer, g_021A4098);
    return 0;
}


/*
 * sdk:      gpSendBuddyMessageA (gp.o)
 */
int func_021864CC(void **connection, int profile, char *message)
{
    GPIConnection_021864CC *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection_021864CC *)*connection) == 0)
        return 2;
    if (iconnection->f108 != 0)
        return 0;
    if (iconnection->f1F4 == 4) {
        func_02193734((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (message == 0) {
        func_02193734((int *)connection, (int)g_021A4118);
        return 2;
    }
    return func_021889A0(connection, profile, 1, message, 0, 0);
}


int func_02186564(void **connection, int *targets, int numOfTargets, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection_02186564 *iconnection;

    if (connection == 0 || *connection == 0)
        return 2;
    if (callback == 0) {
        func_02193734((int *)connection, (int)g_021A4010);
        return 2;
    }
    iconnection = (GPIConnection_02186564 *)*connection;
    if (iconnection->f1F4 == 4) {
        func_02193734((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPGetReverseBuddiesListResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    return func_021908B0(connection, targets, numOfTargets, blocking, callback, param);
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
