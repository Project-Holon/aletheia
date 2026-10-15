/*
 * function: gpiConnect
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
 *   gpiReset  0x021867E8  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   strzcpy  0x0219327C  arm   ov009
 *   _strlwr  0x0217F21C  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   func_0218E114  0x0218E114  arm   ov009
 *   gpiStartConnect  0x0218A238  arm   ov009
 *   gpiFailedOpCallback  0x0218DD88  arm   ov009
 *   gpiDisconnect  0x0218B760  arm   ov009
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

extern int gpiReset(void **connection);
extern void gpiSetErrorString(int *p, int b);
extern void strzcpy(char *p, int b, int n);
extern char *_strlwr(char *string);
extern void *gsimalloc(unsigned long size);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int val, unsigned long len);
extern int func_0218E114(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int gpiStartConnect(void **connection, GPIOperation *operation);
extern int gpiFailedOpCallback(void **connection, const struct GPIOperation_s *operation);
extern void gpiDisconnect(void **connection, int tellServer);
extern int func_02186E9C(void **connection, int blockingOperationID);
extern char g_021A4818[];
extern char g_021A482C[];

int gpiConnect(void **connection, char *nick, char *uniquenick, char *email,
                  char *password, char *authtoken, char *partnerchallenge,
                  char *cdkey, int firewall, int newuser, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIConnectData *data;
    GPIOperation *operation;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int result;

    if (iconnection->connectState == 4) {
        int __result__ = gpiReset(connection);
        if (__result__ != 0) return __result__;
    }
    if (iconnection->connectState != 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4818);
        return 2;
    }

    iconnection->firewall = 1;
    strzcpy(iconnection->nick, (int)nick, 31);
    strzcpy(iconnection->uniquenick, (int)uniquenick, 21);
    strzcpy(iconnection->email, (int)email, 51);
    strzcpy(iconnection->password, (int)password, 31);
    _strlwr(iconnection->email);

    data = (GPIConnectData *)gsimalloc(sizeof(GPIConnectData));
    if (data == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A482C);
        return 1;
    }
    MSL_C_LIB_MemsetPtr(data, 0, sizeof(GPIConnectData));
    data->newuser = newuser;
    if (authtoken[0] && partnerchallenge[0]) {
        strzcpy(data->authtoken, (int)authtoken, 256);
        strzcpy(data->partnerchallenge, (int)partnerchallenge, 256);
    }
    if (cdkey)
        strzcpy(data->cdkey, (int)cdkey, 65);

    {
        int __result__ = func_0218E114(connection, 0, data, &operation, blocking, callback, param);
        if (__result__ != 0) return __result__;
    }

    result = gpiStartConnect(connection, operation);
    if (result != 0) {
        operation->result = result;
        gpiFailedOpCallback(connection, operation);
        gpiDisconnect(connection, 0);
        return result;
    }

    if (operation->blocking) {
        int __result__ = func_02186E9C(connection, operation->id);
        if (__result__ != 0) return __result__;
    }
    return 0;
}
