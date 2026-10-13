/*
 * function: ghiEncryptorSslInitFunc
 * address:  0x021C1920
 * packet:   pkt_ov114_021C1920
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEncryptorSslInitFunc (libdwcgsghttp.TWL.HYB.a ghttpencryption.o)
 *
 * symbols:
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   ghiTwlSSLInit  0x021c1804  arm   ov114
 *   sGhttpEncryptionFileName     0x021ce7b0  data
 *   sFuncNameGhiEncryptorSslInitFunc     0x021ce696  data
 *   sGhttpEncryptionLocationFormat     0x021ceae8  data
 *   sGhttpFailedToAllocateSslInterface     0x021ceaf8  data
 *   sGhttpGamespySslTwlCertificateIs     0x021ceb40  data
 *   sGhttpGamespySslTwlEngineInitialized     0x021ceb7c  data
 */

typedef struct GHIConnection {
    char pad0[0x14];
    char *url;
} GHIConnection;

typedef struct GsTwlSslInterface {
    void *sslCon;
    int field4;
} GsTwlSslInterface;

typedef struct GHIEncryptor {
    GsTwlSslInterface *engine;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
} GHIEncryptor;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void *func_0217EAB0(unsigned long);
struct CPSSslConnection;
extern struct CPSSslConnection *ghiTwlSSLInit(char *url);
extern char sGhttpEncryptionFileName[];
extern char sFuncNameGhiEncryptorSslInitFunc[];
extern char sGhttpEncryptionLocationFormat[];
extern char sGhttpFailedToAllocateSslInterface[];
extern char sGhttpGamespySslTwlCertificateIs[];
extern char sGhttpGamespySslTwlEngineInitialized[];

int ghiEncryptorSslInitFunc(GHIConnection *connection, GHIEncryptor *theEncryptor)
{
    GsTwlSslInterface *sslInterface;

    func_0217D254(8, (char *)4, 0xf, sGhttpEncryptionLocationFormat, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x417);
    theEncryptor->engine = func_0217EAB0(8);
    if (theEncryptor->engine == 0) {
        func_0217D254(8, (char *)2, 2, sGhttpFailedToAllocateSslInterface, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x425, 8);
        return 3;
    }
    {
        char *p = (char *)theEncryptor->engine;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
    }
    sslInterface = theEncryptor->engine;
    sslInterface->sslCon = ghiTwlSSLInit(connection->url);
    sslInterface->field4 = 0;
    if (sslInterface->sslCon == 0) {
        func_0217D254(8, (char *)4, 0xf, sGhttpGamespySslTwlCertificateIs, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x431);
        return 3;
    }
    theEncryptor->field8 = 1;
    theEncryptor->fieldC = 0;
    theEncryptor->field10 = 0;
    theEncryptor->field14 = 0;
    theEncryptor->field18 = 1;
    theEncryptor->field1C = 1;
    func_0217D254(8, (char *)4, 0xf, sGhttpGamespySslTwlEngineInitialized, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x43d);
    return 1;
}
