/*
 * function: func_0218AC4C
 * address:  0x0218AC4C
 * packet:   pkt_ov009_0218AC4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendNewuser (gpiconnect.o)
 *
 * symbols:
 *   func_02193748  0x02193748  arm   ov009
 *   func_0218946C  0x0218946C  arm   ov009
 *   func_0218949C  0x0218949C  arm   ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0217F790  0x0217F790  arm   ov009
 *   func_0217F7AC  0x0217F7AC  arm   ov009
 *   func_0217FA90  0x0217FA90  arm   ov009
 *   g_021A4964     0x021A4964  data
 *   g_021A4970     0x021A4970  data
 *   g_021A4978     0x021A4978  data
 *   g_021A4980     0x021A4980  data
 *   g_021A4914     0x021A4914  data
 *   g_021A4920     0x021A4920  data
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   g_021A492C     0x021A492C  data
 *   g_021A48B4     0x021A48B4  data
 *   g_021A4990     0x021A4990  data
 *   g_021A48E8     0x021A48E8  data
 *   g_021A4954     0x021A4954  data
 *   g_021A495C     0x021A495C  data
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIConnectData {
    char pad0[0x2c2];
    char cdkey[65];
} GPIConnectData;

typedef struct GPIConnection {
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
} GPIConnection;

extern void func_02193748(const char *plaintext, char *encoded);
typedef unsigned char  u8;
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern int func_0209477C(const u8 *s);
extern void func_0217F790(unsigned long seed);
extern unsigned int func_0217F7AC(unsigned int min, unsigned int max);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
extern char g_021A4964[];
extern char g_021A4970[];
extern char g_021A4978[];
extern char g_021A4980[];
extern char g_021A4914[];
extern char g_021A4920[];
extern char gGsAvailabilityGameName[];
extern char g_021A492C[];
extern char g_021A48B4[];
extern char g_021A4990[];
extern char g_021A48E8[];
extern char g_021A4954[];
extern char g_021A495C[];

int func_0218AC4C(void **connection, GPIConnectData *data)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
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
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), gGsAvailabilityGameName);
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
