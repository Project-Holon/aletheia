/*
 * file:     unit_0218A1D0_p02.c
 * unit:     yes
 * function: func_0218A624, func_0218A830, func_0218AC4C
 * address:  0x0218A624
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_0218A1D0  0x0218A1D0  arm   ov009
 *   func_0209477C  0x0209477C  arm
 *   func_021858A8  0x021858A8  arm   ov009
 *   func_02084F40  0x02084F40  arm
 *   func_0218FF98  0x0218FF98  arm   ov009
 *   func_0218946C  0x0218946C  arm   ov009
 *   func_0218949C  0x0218949C  arm   ov009
 *   g_021A483C     0x021A483C  data
 *   g_021A4840     0x021A4840  data
 *   g_021A4848     0x021A4848  data
 *   g_021A4850     0x021A4850  data
 *   g_021A4860     0x021A4860  data
 *   g_021A4894     0x021A4894  data
 *   g_021A489C     0x021A489C  data
 *   g_021A48A8     0x021A48A8  data
 *   g_021A48B4     0x021A48B4  data
 *   g_021A48C4     0x021A48C4  data
 *   g_021A48CC     0x021A48CC  data
 *   g_021A48D0     0x021A48D0  data
 *   g_021A48DC     0x021A48DC  data
 *   g_021A48E8     0x021A48E8  data
 *   g_021A48F4     0x021A48F4  data
 *   g_021A4900     0x021A4900  data
 *   g_021A490C     0x021A490C  data
 *   g_021A4914     0x021A4914  data
 *   g_021A4920     0x021A4920  data
 *   g_021ACEFC     0x021ACEFC  data
 *   g_021A492C     0x021A492C  data
 *   g_021A493C     0x021A493C  data
 *   g_021A494C     0x021A494C  data
 *   g_021A4954     0x021A4954  data
 *   g_021A495C     0x021A495C  data
 *   func_02193748  0x02193748  arm   ov009
 *   func_0217F790  0x0217F790  arm   ov009
 *   func_0217F7AC  0x0217F7AC  arm   ov009
 *   func_0217FA90  0x0217FA90  arm   ov009
 *   g_021A4964     0x021A4964  data
 *   g_021A4970     0x021A4970  data
 *   g_021A4978     0x021A4978  data
 *   g_021A4980     0x021A4980  data
 *   g_021A4990     0x021A4990  data
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

typedef struct GPIConnectData_0218A624 {
    char pad0[0xc2];
    char authtoken[256];
    char partnerchallenge[256];
    char cdkey[65];
    int newuser;
} GPIConnectData_0218A624;

typedef struct GPIConnection_0218A624 {
    char pad0[0x10c];
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    char pad198[0x1f4 - 0x198];
    int connectState;
} GPIConnection_0218A624;

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIConnectData_0218A830 {
    char serverChallenge[128];
    char userChallenge[33];
    char passwordHash[33];
    char authtoken[256];
    char partnerchallenge[256];
    char cdkey[65];
} GPIConnectData_0218A830;

typedef struct GPIProfile {
    int profileId;
    int userId;
} GPIProfile;

typedef struct GPIConnection_0218A830 {
    char pad0[0x100];
    int infoCaching;
    char pad104[0x10c - 0x104];
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    int sessKey;
    int userid;
    int profileid;
    int partnerID;
    char pad1a8[0x210 - 0x1a8];
    GPIBuffer outputBuffer;
    char pad220[0x230 - 0x220];
    unsigned short peerPort;
    char pad232[0x60c - 0x232];
    int productID;
    int namespaceID;
    char pad614[0x630 - 0x614];
    int quietModeFlags;
} GPIConnection_0218A830;

typedef unsigned char  u8;

typedef struct GPIConnectData_0218AC4C {
    char pad0[0x2c2];
    char cdkey[65];
} GPIConnectData_0218AC4C;

typedef struct GPIConnection_0218AC4C {
    char pad0[0x110];
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    int sessKey;
    int userid;
    int profileid;
    int partnerID;
    char pad1a8[0x210 - 0x1a8];
    GPIBuffer outputBuffer;
    char pad220[0x60c - 0x220];
    int productID;
    int namespaceID;
} GPIConnection_0218AC4C;

extern int func_021867E8(void **connection);
extern void func_02193734(int *p, int b);
extern void func_0219327C(char *p, int b, int n);
extern char *func_0217F21C(char *string);
extern void *func_0217EAB0(unsigned long size);
extern void *func_020923B0(void *dst, int val, unsigned long len);
extern int func_0218E114(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int func_0218A238(void **connection, GPIOperation *operation);
extern int func_0218DD88(void **connection, const struct GPIOperation_s *operation);
extern void func_0218B760(void **connection, int tellServer);
extern int func_02186E9C(void **connection, int blockingOperationID);
extern void func_0218A1D0(char *buffer, int numChars);
extern int func_0209477C(const u8 *s);
extern void func_021858A8(unsigned char *input, unsigned int len, char *output);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern int func_0218FF98(void **connection, char *nick, char *email, GPIProfile **profile);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern void func_02193748(const char *plaintext, char *encoded);
extern void func_0217F790(unsigned long seed);
extern unsigned int func_0217F7AC(unsigned int min, unsigned int max);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
int func_0218A624(void **connection, char *nick, char *uniquenick, char *email, char *password, char *authtoken, char *partnerchallenge, char *cdkey, int firewall, int newuser, int blocking, void (*callback)(void **, void *, void *), void *param);
int func_0218A830(void **connection, GPIConnectData_0218A830 *data);
int func_0218AC4C(void **connection, GPIConnectData_0218AC4C *data);
extern char g_021A4818[];
extern char g_021A482C[];
extern char g_021A483C[];
extern char g_021A4840[];
extern char g_021A4848[];
extern char g_021A4850[];
extern char g_021A4860[];
extern char g_021A4894[];
extern char g_021A489C[];
extern char g_021A48A8[];
extern char g_021A48B4[];
extern char g_021A48C4[];
extern char g_021A48CC[];
extern char g_021A48D0[];
extern char g_021A48DC[];
extern char g_021A48E8[];
extern char g_021A48F4[];
extern char g_021A4900[];
extern char g_021A490C[];
extern char g_021A4914[];
extern char g_021A4920[];
extern char g_021ACEFC[];
extern char g_021A492C[];
extern char g_021A493C[];
extern char g_021A494C[];
extern char g_021A4954[];
extern char g_021A495C[];
extern char g_021A4964[];
extern char g_021A4970[];
extern char g_021A4978[];
extern char g_021A4980[];
extern char g_021A4990[];


/*
 * sdk:      gpiConnect (gpiconnect.o)
 *
 * The DWARF prototype lists 12 parameters, but the object reads newuser,
 * blocking, callback and param one word higher (sp+0x44..0x50): an unused
 * word parameter sits between cdkey and newuser, spelled here as firewall.
 */
int func_0218A624(void **connection, char *nick, char *uniquenick, char *email,
                  char *password, char *authtoken, char *partnerchallenge,
                  char *cdkey, int firewall, int newuser, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIConnectData_0218A624 *data;
    GPIOperation *operation;
    GPIConnection_0218A624 *iconnection = (GPIConnection_0218A624 *)*connection;
    int result;

    if (iconnection->connectState == 4) {
        int __result__ = func_021867E8(connection);
        if (__result__ != 0) return __result__;
    }
    if (iconnection->connectState != 0) {
        func_02193734((int *)connection, (int)g_021A4818);
        return 2;
    }

    iconnection->firewall = 1;
    func_0219327C(iconnection->nick, (int)nick, 31);
    func_0219327C(iconnection->uniquenick, (int)uniquenick, 21);
    func_0219327C(iconnection->email, (int)email, 51);
    func_0219327C(iconnection->password, (int)password, 31);
    func_0217F21C(iconnection->email);

    data = (GPIConnectData_0218A624 *)func_0217EAB0(sizeof(GPIConnectData_0218A624));
    if (data == 0) {
        func_02193734((int *)connection, (int)g_021A482C);
        return 1;
    }
    func_020923B0(data, 0, sizeof(GPIConnectData_0218A624));
    data->newuser = newuser;
    if (authtoken[0] && partnerchallenge[0]) {
        func_0219327C(data->authtoken, (int)authtoken, 256);
        func_0219327C(data->partnerchallenge, (int)partnerchallenge, 256);
    }
    if (cdkey)
        func_0219327C(data->cdkey, (int)cdkey, 65);

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


/*
 * sdk:      gpiSendLogin (gpiconnect.o)
 */
int func_0218A830(void **connection, GPIConnectData_0218A830 *data)
{
    GPIConnection_0218A830 *iconnection = (GPIConnection_0218A830 *)*connection;
    char buffer[512];
    char response[33];
    GPIProfile *profile;
    char *passphrase;
    char userBuffer[82];
    char partnerBuffer[11];
    char *user;

    func_0218A1D0(data->userChallenge, sizeof(data->userChallenge) - 1);

    if (data->partnerchallenge[0])
        passphrase = data->partnerchallenge;
    else
        passphrase = iconnection->password;
    func_021858A8((unsigned char *)passphrase, func_0209477C((const u8 *)passphrase), data->passwordHash);

    if (iconnection->partnerID != 0)
        func_02084F40(partnerBuffer, g_021A483C, iconnection->partnerID);
    else
        partnerBuffer[0] = '\0';

    if (data->authtoken[0]) {
        user = data->authtoken;
    } else if (iconnection->uniquenick[0]) {
        func_02084F40(userBuffer, g_021A4840, partnerBuffer, iconnection->uniquenick);
        user = userBuffer;
    } else {
        func_02084F40(userBuffer, g_021A4848, partnerBuffer, iconnection->nick, iconnection->email);
        user = userBuffer;
    }

    func_02084F40(buffer, g_021A4850, data->passwordHash, g_021A4860, user,
                  data->userChallenge, data->serverChallenge, data->passwordHash);
    func_021858A8((unsigned char *)buffer, func_0209477C((const u8 *)buffer), response);

    if (iconnection->infoCaching) {
        func_0218FF98(connection, iconnection->nick, iconnection->email, &profile);
        if (profile != 0) {
            iconnection->userid = profile->userId;
            iconnection->profileid = profile->profileId;
        }
    }

    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4894);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A489C);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), data->userChallenge);
    if (data->authtoken[0]) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48A8);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), data->authtoken);
    } else if (iconnection->uniquenick[0]) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);
    } else {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48C4);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48CC);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    }
    if (iconnection->userid != 0) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48D0);
        func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->userid);
    }
    if (iconnection->profileid != 0) {
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48DC);
        func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->profileid);
    }
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48F4);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), response);
    if (iconnection->firewall == 1)
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4900);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A490C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->peerPort);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021ACEFC);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A493C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), 0x3b);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A494C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->quietModeFlags);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
    return 0;
}


int func_0218AC4C(void **connection, GPIConnectData_0218AC4C *data)
{
    GPIConnection_0218AC4C *iconnection = (GPIConnection_0218AC4C *)*connection;
    unsigned long i;
    char passwordenc[45];
    char cdkeyxor[65];
    char cdkeyenc[90];
    unsigned long cdkeylen;
    char aRand;

    func_02193748(iconnection->password, passwordenc);

    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4964);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4970);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4978);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4980);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), passwordenc);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021ACEFC);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);

    if (data->cdkey[0] != '\0') {
        cdkeylen = func_0209477C((const u8 *)data->cdkey);
        func_0217F790(0x79707367);
        for (i = 0; i < cdkeylen; i++) {
            aRand = (char)func_0217F7AC(0, 0xFF);
            cdkeyxor[i] = (char)(data->cdkey[i] ^ aRand);
        }
        cdkeyxor[i] = '\0';
        func_0217FA90(cdkeyxor, cdkeyenc, (int)cdkeylen, 1);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4990);
        func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), cdkeyenc);
    }

    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
    return 0;
}
