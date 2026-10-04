/*
 * function: func_02185D04
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
 *   func_02193734  0x02193734  arm
 *   func_0219327C  0x0219327C  arm
 *   func_02189300  0x02189300  arm
 *   func_0218946C  0x0218946C  arm
 *   func_0218949C  0x0218949C  arm
 *   g_021A4024     0x021A4024  data
 *   g_021A4054     0x021A4054  data
 *   g_021A4064     0x021A4064  data
 *   g_021A4070     0x021A4070  data
 *   g_021A407C     0x021A407C  data
 *   g_021A408C     0x021A408C  data
 *   g_021A4098     0x021A4098  data
 */

typedef struct GPIConnection GPIConnection;

extern void func_02193734(int *p, int b);
extern void func_0219327C(char *p, int b, int n);
extern int func_02189300(void **connection, int id, int isDeleted);
extern int func_0218946C(void **connection, void *outputBuffer, char *buffer);
extern int func_0218949C(void **connection, void *outputBuffer, int num);
extern char g_021A4024[];
extern char g_021A4054[];
extern char g_021A4064[];
extern char g_021A4070[];
extern char g_021A407C[];
extern char g_021A408C[];
extern char g_021A4098[];

int func_02185D04(void **connection, int profile, char *reason)
{
    int i;
    char reasonFixed[1025];
    GPIConnection *iconnection;

    if (connection == 0 || *connection == 0) return 2;
    iconnection = (GPIConnection *)*connection;
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
    func_0218946C(connection, (char *)iconnection + 0x210, g_021A4064);
    func_0218946C(connection, (char *)iconnection + 0x210, g_021A4070);
    func_0218949C(connection, (char *)iconnection + 0x210, *(int *)((char *)iconnection + 0x198));
    func_0218946C(connection, (char *)iconnection + 0x210, g_021A407C);
    func_0218949C(connection, (char *)iconnection + 0x210, profile);
    func_0218946C(connection, (char *)iconnection + 0x210, g_021A408C);
    func_0218946C(connection, (char *)iconnection + 0x210, reasonFixed);
    func_0218946C(connection, (char *)iconnection + 0x210, g_021A4098);
    return 0;
}
