/*
 * function: func_0218C5FC
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
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_0218949C  0x0218949C  arm  ov009
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

extern int func_0218946C(void **connection, void *outputBuffer, char *buffer);
extern int func_0218949C(void **connection, void *outputBuffer, int num);
extern char g_021A4BF4[];
extern char g_021A4C0C[];
extern char g_021A4C18[];
extern char g_021A4C20[];

int func_0218C5FC(void **connection, void *buffer)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (iconnection->nickPending > 0) {
        func_0218946C(connection, buffer, g_021A4BF4);
        func_0218949C(connection, buffer, iconnection->profileid);
        func_0218946C(connection, buffer, iconnection->nick);
        func_0218946C(connection, buffer, g_021A4C0C);
        func_0218949C(connection, buffer, iconnection->sessionKey);
        func_0218946C(connection, buffer, g_021A4C18);
        iconnection->nickPending = 0;
    }
    if (iconnection->emailPending > 0) {
        func_0218946C(connection, buffer, g_021A4C20);
        func_0218949C(connection, buffer, iconnection->profileid);
        func_0218946C(connection, buffer, iconnection->email);
        func_0218946C(connection, buffer, g_021A4C18);
        iconnection->emailPending = 0;
    }
    return 0;
}
