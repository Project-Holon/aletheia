/*
 * file:     unit_021858FC_p01.c
 * unit:     yes
 * function: func_021858FC, func_0218592C, func_02185948, func_0218597C, func_021859C0, func_02185ACC, func_02185B10, func_02185BD8, func_02185CB4, func_02185D04
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
 *   func_02186788  0x02186788  arm  ov009
 *   gpiProcess  0x02186E9C  arm
 *   gpiSetErrorString  0x02193734  arm
 *   g_021A4000         0x021A4000  data
 *   func_02193734  0x02193734  arm   ov009
 *   func_0218A624  0x0218A624  arm   ov009
 *   g_021A4010     0x021A4010  data
 *   g_021A4020     0x021A4020  data
 *   gpiDisconnect  0x0218B760  arm
 *   gpiReset       0x021867E8  arm
 *   func_021906E0  0x021906E0  arm   ov009
 *   func_0218D4A4  0x0218D4A4  arm   ov009
 *   g_021A4024     0x021A4024  data  ov009
 *   gpiSetInfoi        0x0218CC48  arm
 *   func_0219327C  0x0219327C  arm
 *   func_02189300  0x02189300  arm
 *   func_0218946C  0x0218946C  arm
 *   func_0218949C  0x0218949C  arm
 *   g_021A4054     0x021A4054  data
 *   g_021A4064     0x021A4064  data
 *   g_021A4070     0x021A4070  data
 *   g_021A407C     0x021A407C  data
 *   g_021A408C     0x021A408C  data
 *   g_021A4098     0x021A4098  data
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

extern int gpiInitialize(void **connection, int productID, int namespaceID, int partnerID);
extern void func_02186788(void **connection);
extern int gpiProcess(void **connection, int blockingOperationID);
extern void gpiSetErrorString(void **connection, char *errorString);
extern void func_02193734(int *p, int b);
extern int func_0218A624(void **connection, char *nick, char *uniquenick, char *email, char *password, char *authtoken, char *partnerchallenge, char *cdkey, int firewall, int newuser, int blocking, void (*callback)(void **, void *, void *), void *param);
extern void gpiDisconnect(void **connection, int tellServer);
extern int gpiReset(void **connection);
extern int func_021906E0(int *connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int skip, int blocking, int callback, int param);
extern int func_0218D4A4(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int gpiSetInfoi(void **connection, int info, int value);
extern void func_0219327C(char *p, int b, int n);
extern int func_02189300(void **connection, int id, int isDeleted);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
int gpInitialize(void **connection, int productID, int namespaceID, int partnerID);
void func_0218592C(int **p);
int gpProcess(void **connection);
int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param);
int func_021859C0(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, void (*callback)(void **, void *, void *), void *param);
void gpDisconnect(void **connection);
int func_02185B10(void **connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int blocking, GPCallback callback, void *param);
int func_02185BD8(void **connection, int profile, int checkCache, int blocking, GPCallback callback, void *param);
int gpSetInfoi(void **connection, int info, int value);
int func_02185D04(void **connection, int profile, char *reason);
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
void func_0218592C(int **p)
{
    if (p && *p) {
        func_02186788((void **)p);
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
    gpiSetErrorString(connection, g_021A4000);
    return 2;
}


/*
 * sdk:      gpConnectPreAuthenticatedA (libdwcgsgp.TWL.HYB.a gp.o)
 */
int func_021859C0(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, void (*callback)(void **, void *, void *), void *param)
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
        func_02193734((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPConnectResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    return func_0218A624(connection, g_021A4020, g_021A4020, g_021A4020, g_021A4020, authtoken, partnerchallenge, 0, firewall, 0, blocking, callback, param);
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
int func_02185B10(void **connection, char *nick, char *uniquenick, char *email,
                  char *firstname, char *lastname, int icquin, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection_02185B10 *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection_02185B10 *)*connection) == 0)
        return 2;
    if (callback == 0) {
        func_02193734((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPProfileSearchResponseArg arg = {0};
        arg.c = 0x601;
        callback(connection, &arg, param);
        return 0;
    }
    return func_021906E0((int *)connection, nick, uniquenick, email, firstname, lastname, icquin, 0,
                         blocking, (int)callback, (int)param);
}


/*
 * sdk:      gpGetInfo (gp.o)
 */
int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection_02185BD8 *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection_02185BD8 *)*connection) == 0 || profile == 0)
        return 2;
    if (callback == 0) {
        func_02193734((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPGetInfoResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    if (iconnection->f1F4 == 4) {
        func_02193734((int *)connection, (int)g_021A4024);
        return 2;
    }
    return func_0218D4A4(connection, profile, checkCache, blocking, callback, param);
}


int gpSetInfoi(void **connection, int info, int value)
{
    GPIConnection_02185CB4 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185CB4 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString(connection, g_021A4024);
        return 2;
    }
    return gpiSetInfoi(connection, info, value);
}


/*
 * sdk:      gpSendBuddyRequestA (gp.o)
 */
int func_02185D04(void **connection, int profile, char *reason)
{
    int i;
    char reasonFixed[1025];
    GPIConnection_02185D04 *iconnection;

    if (connection == 0 || *connection == 0) return 2;
    iconnection = (GPIConnection_02185D04 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0) return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        func_02193734((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (reason == 0) {
        func_02193734((int *)connection, (int)g_021A4054);
        return 2;
    }
    func_0219327C(reasonFixed, (int)reason, 1025);
    for (i = 0; reasonFixed[i] != 0; i++) {
        if (reasonFixed[i] == '\\') reasonFixed[i] = '/';
    }
    func_02189300(connection, profile, 0);
    func_0218946C((int *)connection, (int *)((char *)iconnection + 0x210), g_021A4064);
    func_0218946C((int *)connection, (int *)((char *)iconnection + 0x210), g_021A4070);
    func_0218949C((int *)connection, (int *)((char *)iconnection + 0x210), *(int *)((char *)iconnection + 0x198));
    func_0218946C((int *)connection, (int *)((char *)iconnection + 0x210), g_021A407C);
    func_0218949C((int *)connection, (int *)((char *)iconnection + 0x210), profile);
    func_0218946C((int *)connection, (int *)((char *)iconnection + 0x210), g_021A408C);
    func_0218946C((int *)connection, (int *)((char *)iconnection + 0x210), reasonFixed);
    func_0218946C((int *)connection, (int *)((char *)iconnection + 0x210), g_021A4098);
    return 0;
}
