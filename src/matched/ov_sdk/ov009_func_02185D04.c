/*
 * function: gpSendBuddyRequestA
 * address:  0x02185D04
 * packet:   pkt_ov009_02185D04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpSendBuddyRequestA (gp.o)
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm
 *   strzcpy  0x0219327C  arm
 *   gpiBuddyDeletedLocally  0x02189300  arm
 *   gpiAppendStringToBuffer  0x0218946C  arm
 *   gpiAppendIntToBuffer  0x0218949C  arm
 *   g_021A4024     0x021A4024  data
 *   g_021A4054     0x021A4054  data
 *   g_021A4064     0x021A4064  data
 *   g_021A4070     0x021A4070  data
 *   g_021A407C     0x021A407C  data
 *   g_021A408C     0x021A408C  data
 *   g_021A4098     0x021A4098  data
 */

typedef struct GPIConnection GPIConnection;

extern void gpiSetErrorString(int *p, int b);
extern void strzcpy(char *p, int b, int n);
extern int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern char g_021A4024[];
extern char g_021A4054[];
extern char g_021A4064[];
extern char g_021A4070[];
extern char g_021A407C[];
extern char g_021A408C[];
extern char g_021A4098[];

int gpSendBuddyRequestA(void **connection, int profile, char *reason)
{
    int i;
    char reasonFixed[1025];
    GPIConnection *iconnection;

    if (connection == 0 || *connection == 0) return 2;
    iconnection = (GPIConnection *)*connection;
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
