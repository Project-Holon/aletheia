/*
 * function: func_0218627C
 * address:  0x0218627C
 * packet:   pkt_ov009_0218627C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpSetStatusA (libdwcgsgp.TWL.HYB.a gp.o)
 *
 * symbols:
 *   func_02193734  0x02193734  arm  ov009
 *   func_0219327C  0x0219327C  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_0218949C  0x0218949C  arm  ov009
 *   g_021A4024     0x021A4024  data
 *   g_021A40C0     0x021A40C0  data
 *   g_021A40D8     0x021A40D8  data
 *   g_021A40F0     0x021A40F0  data
 *   g_021A4070     0x021A4070  data
 *   g_021A40FC     0x021A40FC  data
 *   g_021A410C     0x021A410C  data
 *   g_021A4098     0x021A4098  data
 */

typedef struct GPIBuffer GPIBuffer;

typedef struct GPIConnection {
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
} GPIConnection;

typedef void *GPConnection;

extern void func_02193734(GPConnection *connection, const char *errorString);
extern void func_0219327C(char *dest, const char *src, unsigned long len);
extern int func_020948E0(const char *a, const char *b);
extern int func_0218946C(GPConnection *connection, void *outputBuffer, const char *buffer);
extern int func_0218949C(GPConnection *connection, void *outputBuffer, int num);
extern char g_021A4024[];
extern char g_021A40C0[];
extern char g_021A40D8[];
extern char g_021A40F0[];
extern char g_021A4070[];
extern char g_021A40FC[];
extern char g_021A410C[];
extern char g_021A4098[];

int func_0218627C(GPConnection *connection, int status, const char *statusString, const char *locationString)
{
    char statusStringFixed[256];
    char locationStringFixed[256];
    GPIConnection *iconnection;
    int i;

    if (connection == 0 || (iconnection = (GPIConnection *)*connection) == 0)
        return 2;
    if (iconnection->f108 != 0)
        return 0;
    if (iconnection->connectState == 4)
    {
        func_02193734(connection, g_021A4024);
        return 2;
    }
    if (statusString == 0)
    {
        func_02193734(connection, g_021A40C0);
        return 2;
    }
    if (locationString == 0)
    {
        func_02193734(connection, g_021A40D8);
        return 2;
    }

    func_0219327C(statusStringFixed, statusString, sizeof(statusStringFixed));
    for (i = 0; statusStringFixed[i]; i++)
        if (statusStringFixed[i] == '\\')
            statusStringFixed[i] = '/';
    func_0219327C(locationStringFixed, locationString, sizeof(locationStringFixed));
    for (i = 0; locationStringFixed[i]; i++)
        if (locationStringFixed[i] == '\\')
            locationStringFixed[i] = '/';

    if (status == iconnection->lastStatus
        && func_020948E0(statusStringFixed, iconnection->lastStatusString) == 0
        && func_020948E0(locationStringFixed, iconnection->lastLocationString) == 0)
        return 0;

    iconnection->lastStatus = status;
    func_0219327C(iconnection->lastStatusString, statusStringFixed, sizeof(iconnection->lastStatusString));
    func_0219327C(iconnection->lastLocationString, locationStringFixed, sizeof(iconnection->lastLocationString));

    func_0218946C(connection, iconnection->outputBuffer, g_021A40F0);
    func_0218949C(connection, iconnection->outputBuffer, status);
    func_0218946C(connection, iconnection->outputBuffer, g_021A4070);
    func_0218949C(connection, iconnection->outputBuffer, iconnection->sessKey);
    func_0218946C(connection, iconnection->outputBuffer, g_021A40FC);
    func_0218946C(connection, iconnection->outputBuffer, statusStringFixed);
    func_0218946C(connection, iconnection->outputBuffer, g_021A410C);
    func_0218946C(connection, iconnection->outputBuffer, locationStringFixed);
    func_0218946C(connection, iconnection->outputBuffer, g_021A4098);
    return 0;
}
