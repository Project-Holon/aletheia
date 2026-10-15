/*
 * function: gpSetStatusA
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
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   strzcpy  0x0219327C  arm  ov009
 *   strcmp  0x020948E0  arm
 *   gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm  ov009
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

extern void gpiSetErrorString(int *p, int b);
extern void strzcpy(char *p, int b, int n);
extern int strcmp(const char *a, const char *b);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern char g_021A4024[];
extern char g_021A40C0[];
extern char g_021A40D8[];
extern char g_021A40F0[];
extern char g_021A4070[];
extern char g_021A40FC[];
extern char g_021A410C[];
extern char g_021A4098[];

int gpSetStatusA(GPConnection *connection, int status, const char *statusString, const char *locationString)
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
