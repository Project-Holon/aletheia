/*
 * function: gpiSendServerBuddyMessage
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
 *   strzcpy  0x0219327C  arm   ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm   ov009
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

extern void strzcpy(char *p, int b, int n);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern char g_021A4278[];
extern char g_021A424C[];
extern char g_021A4464[];
extern char g_021A42CC[];
extern char g_021A4270[];

int gpiSendServerBuddyMessage(void **connection, int profileid, int type, char *message)
{
    GPIConnection *iconnection;
    char buffer[3501];

    iconnection = (GPIConnection *)*connection;
    strzcpy(buffer, (int)message, 3501);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4278);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), type);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A424C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->f198);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4464);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), profileid);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A42CC);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), buffer);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4270);
    return 0;
}
