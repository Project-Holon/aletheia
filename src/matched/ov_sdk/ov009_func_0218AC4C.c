/*
 * function: gpiSendNewuser
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
 *   gpiEncodeString  0x02193748  arm   ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm   ov009
 *   strlen  0x0209477C  arm
 *   Util_RandSeed  0x0217F790  arm   ov009
 *   Util_RandInt  0x0217F7AC  arm   ov009
 *   B64Encode  0x0217FA90  arm   ov009
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

extern void gpiEncodeString(const char *plaintext, char *encoded);
typedef unsigned char  u8;
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern int strlen(const u8 *s);
extern void Util_RandSeed(unsigned long seed);
extern unsigned int Util_RandInt(unsigned int min, unsigned int max);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);
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

int gpiSendNewuser(void **connection, GPIConnectData *data)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    unsigned long i;
    char passwordenc[45];
    char cdkeyxor[65];
    char cdkeyenc[90];
    unsigned long cdkeylen;
    char aRand;

    gpiEncodeString(iconnection->password, passwordenc);

    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4964);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4970);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4978);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4980);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), passwordenc);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGsAvailabilityGameName);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);

    if (data->cdkey[0] != '\0') {
        cdkeylen = strlen((const u8 *)data->cdkey);
        Util_RandSeed(0x79707367);
        for (i = 0; i < cdkeylen; i++) {
            aRand = (char)Util_RandInt(0, 0xFF);
            cdkeyxor[i] = (char)(data->cdkey[i] ^ aRand);
        }
        cdkeyxor[i] = '\0';
        B64Encode(cdkeyxor, cdkeyenc, (int)cdkeylen, 1);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4990);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), cdkeyenc);
    }

    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
    return 0;
}
