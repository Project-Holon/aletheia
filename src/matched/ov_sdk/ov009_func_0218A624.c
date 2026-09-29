/*
 * function: func_0218A624
 * address:  0x0218A624
 * packet:   pkt_ov009_0218A624
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiConnect (gpiconnect.o)
 *
 * symbols:
 *   func_021867E8  0x021867E8  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_0219327C  0x0219327C  arm   ov009
 *   func_0217F21C  0x0217F21C  arm   ov009
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_020923B0  0x020923B0  arm
 *   func_0218E114  0x0218E114  arm   ov009
 *   func_0218A238  0x0218A238  arm   ov009
 *   func_0218DD88  0x0218DD88  arm   ov009
 *   func_0218B760  0x0218B760  arm   ov009
 *   func_02186E9C  0x02186E9C  arm   ov009
 *   g_021A4818     0x021A4818  data
 *   g_021A482C     0x021A482C  data
 *
 * The DWARF prototype lists 12 parameters, but the object reads newuser,
 * blocking, callback and param one word higher (sp+0x44..0x50): an unused
 * word parameter sits between cdkey and newuser, spelled here as firewall.
 */

typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    GPICallback callback;
    int state;
    int id;
    int result;
    struct GPIOperation_s *pnext;
} GPIOperation;

typedef struct GPIConnectData {
    char pad0[0xc2];
    char authtoken[256];
    char partnerchallenge[256];
    char cdkey[65];
    int newuser;
} GPIConnectData;

typedef struct GPIConnection {
    char pad0[0x10c];
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    char pad198[0x1f4 - 0x198];
    int connectState;
} GPIConnection;

extern int func_021867E8(void **connection);
extern void func_02193734(void **connection, char *errorString);
extern void func_0219327C(char *dest, char *src, unsigned long len);
extern char *func_0217F21C(char *string);
extern void *func_0217EAB0(unsigned long size);
extern void *func_020923B0(void *dst, int val, unsigned long len);
extern int func_0218E114(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int func_0218A238(void **connection, GPIOperation *operation);
extern int func_0218DD88(void **connection, GPIOperation *operation);
extern void func_0218B760(void **connection, int tellServer);
extern int func_02186E9C(void **connection, int blockingOperationID);
extern char g_021A4818[];
extern char g_021A482C[];

int func_0218A624(void **connection, char *nick, char *uniquenick, char *email,
                  char *password, char *authtoken, char *partnerchallenge,
                  char *cdkey, int firewall, int newuser, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIConnectData *data;
    GPIOperation *operation;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int result;

    if (iconnection->connectState == 4) {
        int __result__ = func_021867E8(connection);
        if (__result__ != 0) return __result__;
    }
    if (iconnection->connectState != 0) {
        func_02193734(connection, g_021A4818);
        return 2;
    }

    iconnection->firewall = 1;
    func_0219327C(iconnection->nick, nick, 31);
    func_0219327C(iconnection->uniquenick, uniquenick, 21);
    func_0219327C(iconnection->email, email, 51);
    func_0219327C(iconnection->password, password, 31);
    func_0217F21C(iconnection->email);

    data = (GPIConnectData *)func_0217EAB0(sizeof(GPIConnectData));
    if (data == 0) {
        func_02193734(connection, g_021A482C);
        return 1;
    }
    func_020923B0(data, 0, sizeof(GPIConnectData));
    data->newuser = newuser;
    if (authtoken[0] && partnerchallenge[0]) {
        func_0219327C(data->authtoken, authtoken, 256);
        func_0219327C(data->partnerchallenge, partnerchallenge, 256);
    }
    if (cdkey)
        func_0219327C(data->cdkey, cdkey, 65);

    {
        int __result__ = func_0218E114(connection, 0, data, &operation, blocking, callback, param);
        if (__result__ != 0) return __result__;
    }

    result = func_0218A238(connection, operation);
    if (result != 0) {
        operation->result = result;
        func_0218DD88(connection, operation);
        func_0218B760(connection, 0);
        return result;
    }

    if (operation->blocking) {
        int __result__ = func_02186E9C(connection, operation->id);
        if (__result__ != 0) return __result__;
    }
    return 0;
}
