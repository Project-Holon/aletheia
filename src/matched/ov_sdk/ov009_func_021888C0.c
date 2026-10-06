/*
 * function: func_021888C0
 * address:  0x021888C0
 * packet:   pkt_ov009_021888C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendServerBuddyMessage (gpibuddy.o)
 *
 * symbols:
 *   func_0219327C  0x0219327C  arm   ov009
 *   func_0218946C  0x0218946C  arm   ov009
 *   func_0218949C  0x0218949C  arm   ov009
 *   g_021A4278     0x021A4278  data  ov009
 *   g_021A424C     0x021A424C  data  ov009
 *   g_021A4464     0x021A4464  data  ov009
 *   g_021A42CC     0x021A42CC  data  ov009
 *   g_021A4270     0x021A4270  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad0[0x198];
    int f198;
    unsigned char pad1[0x210 - 0x19C];
    unsigned char outputBuffer[0x10];
} GPIConnection;

extern void func_0219327C(char *p, int b, int n);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern char g_021A4278[];
extern char g_021A424C[];
extern char g_021A4464[];
extern char g_021A42CC[];
extern char g_021A4270[];

int func_021888C0(void **connection, int profileid, int type, char *message)
{
    GPIConnection *iconnection;
    char buffer[3501];

    iconnection = (GPIConnection *)*connection;
    func_0219327C(buffer, (int)message, 3501);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4278);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), type);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A424C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->f198);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4464);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), profileid);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A42CC);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), buffer);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4270);
    return 0;
}
