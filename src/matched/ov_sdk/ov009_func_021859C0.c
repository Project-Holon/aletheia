/*
 * function: gpConnectPreAuthenticatedA
 * address:  0x021859C0
 * packet:   pkt_ov009_021859C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpConnectPreAuthenticatedA (libdwcgsgp.TWL.HYB.a gp.o)
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiConnect  0x0218A624  arm   ov009
 *   g_021A4010     0x021A4010  data
 *   g_021A4020     0x021A4020  data
 */

typedef struct GPIConnection {
    char pad0[0x108];
    int f108;
} GPIConnection;

typedef struct GPConnectResponseArg {
    int a[8];
} GPConnectResponseArg;

extern void gpiSetErrorString(int *p, int b);
extern int gpiConnect(void **connection, char *nick, char *uniquenick, char *email, char *password, char *authtoken, char *partnerchallenge, char *cdkey, int firewall, int newuser, int blocking, void (*callback)(void **, void *, void *), void *param);
extern char g_021A4010[];
extern char g_021A4020[];

int gpConnectPreAuthenticatedA(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, void (*callback)(void **, void *, void *), void *param)
{
    GPIConnection *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if (!authtoken || !authtoken[0])
        return 2;
    if (!partnerchallenge || !partnerchallenge[0])
        return 2;
    if (!callback) {
        gpiSetErrorString((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPConnectResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    return gpiConnect(connection, g_021A4020, g_021A4020, g_021A4020, g_021A4020, authtoken, partnerchallenge, 0, firewall, 0, blocking, callback, param);
}
