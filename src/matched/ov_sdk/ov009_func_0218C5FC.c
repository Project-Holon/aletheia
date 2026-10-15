/*
 * function: gpiAddLocalInfo
 * address:  0x0218C5FC
 * packet:   pkt_ov009_0218C5FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiAddLocalInfo (libdwcgsgp.TWL.HYB.a(gpiinfo.o))
 *
 * symbols:
 *   gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm  ov009
 *   g_021A4BF4  0x021A4BF4  data
 *   g_021A4C0C  0x021A4C0C  data
 *   g_021A4C18  0x021A4C18  data
 *   g_021A4C20  0x021A4C20  data
 */

struct GPIConnection {
    char pad0[0x198];
    int profileid;
    char pad1[8];
    int sessionKey;
    char pad2[0x43c];
    char *nick;
    char pad3[4];
    int nickPending;
    char pad4[4];
    char *email;
    char pad5[4];
    int emailPending;
};

extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern char g_021A4BF4[];
extern char g_021A4C0C[];
extern char g_021A4C18[];
extern char g_021A4C20[];

int gpiAddLocalInfo(void **connection, void *buffer)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (iconnection->nickPending > 0) {
        gpiAppendStringToBuffer((int *)connection, buffer, g_021A4BF4);
        gpiAppendIntToBuffer((int *)connection, buffer, iconnection->profileid);
        gpiAppendStringToBuffer((int *)connection, buffer, iconnection->nick);
        gpiAppendStringToBuffer((int *)connection, buffer, g_021A4C0C);
        gpiAppendIntToBuffer((int *)connection, buffer, iconnection->sessionKey);
        gpiAppendStringToBuffer((int *)connection, buffer, g_021A4C18);
        iconnection->nickPending = 0;
    }
    if (iconnection->emailPending > 0) {
        gpiAppendStringToBuffer((int *)connection, buffer, g_021A4C20);
        gpiAppendIntToBuffer((int *)connection, buffer, iconnection->profileid);
        gpiAppendStringToBuffer((int *)connection, buffer, iconnection->email);
        gpiAppendStringToBuffer((int *)connection, buffer, g_021A4C18);
        iconnection->emailPending = 0;
    }
    return 0;
}
