/*
 * function: ghiEncryptorSslStartFunc
 * address:  0x021C1A78
 * packet:   pkt_ov114_021C1A78
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEncryptorSslStartFunc (ghttpencryption.o)
 *
 * symbols:
 *   gsDebugFormat                    0x0217d254 arm  ov009
 *   SOCL_EnableSsl                    0x0215fc80 arm  ov009
 *   sGhttpEncryptionFileName                       0x021ce7b0 data
 *   sFuncNameGhiEncryptorSslStartFunc                       0x021ce6c7 data
 *   sGhttpEncryptionLocationFormat                       0x021ceae8 data
 *   sGhttpGamespySslTwlInvalidProcessing                       0x021cebb0 data
 *   sGhttpGamespySslTwlCannotCreate                       0x021cebfc data
 *   sGhttpGamespySslTwlSocketLibrary                       0x021cec58 data
 *   sGhttpGamespySslTwlInsufficientResources                       0x021cec9c data
 *   sGhttpGamespySslTwlSocEnablessl                       0x021cecd4 data
 *   sGhttpReturnSuccess                       0x021ced20 data
 */

typedef struct gsTwlSslInterface {
    void *con;                  /* +0x00 struct _CPSSslConnection * */
    int connected;              /* +0x04 */
} gsTwlSslInterface;

typedef struct GHIEncryptor {
    gsTwlSslInterface *mInterface; /* +0x00 */
    char pad4[0xc - 0x4];
    int mInitialized;           /* +0x0c */
    int mSessionStarted;        /* +0x10 */
} GHIEncryptor;

typedef struct GHIConnection {
    char pad0[0x40];
    int result;                 /* +0x040 */
    char pad44[0x50 - 0x44];
    int socket;                 /* +0x050 */
    int socketError;            /* +0x054 */
    char pad58[0x124 - 0x58];
    int completed;              /* +0x124 */
} GHIConnection;

extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int SOCL_EnableSsl(int s, void *con);
extern char sGhttpEncryptionFileName[];       /* __FILE__ */
extern char sFuncNameGhiEncryptorSslStartFunc[];       /* __FUNCTION__ */
extern char sGhttpEncryptionLocationFormat[];
extern char sGhttpGamespySslTwlInvalidProcessing[];
extern char sGhttpGamespySslTwlCannotCreate[];
extern char sGhttpGamespySslTwlSocketLibrary[];
extern char sGhttpGamespySslTwlInsufficientResources[];
extern char sGhttpGamespySslTwlSocEnablessl[];
extern char sGhttpReturnSuccess[];

int ghiEncryptorSslStartFunc(GHIConnection *connection, GHIEncryptor *theEncryptor)
{
    gsTwlSslInterface *sslInterface = theEncryptor->mInterface;

    gsDebugFormat(8, (char *)4, 15, sGhttpEncryptionLocationFormat, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1100);

    if (sslInterface->connected == 0) {
        int result = SOCL_EnableSsl(connection->socket, sslInterface->con);
        if (result < 0) {
            switch (result) {
            case -28:
                gsDebugFormat(8, (char *)4, 15, sGhttpGamespySslTwlInvalidProcessing, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1113);
                break;
            case -33:
                gsDebugFormat(8, (char *)4, 15, sGhttpGamespySslTwlCannotCreate, sFuncNameGhiEncryptorSslStartFunc, 1118);
                break;
            case -39:
                gsDebugFormat(8, (char *)4, 15, sGhttpGamespySslTwlSocketLibrary, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1124);
                break;
            case -42:
                gsDebugFormat(8, (char *)4, 15, sGhttpGamespySslTwlInsufficientResources, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1129);
                break;
            default:
                gsDebugFormat(8, (char *)4, 15, sGhttpGamespySslTwlSocEnablessl, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1135, result);
                break;
            }
            connection->completed = 1;
            connection->result = 6;
            connection->socketError = result;
            return 3;
        }
        sslInterface->connected = 1;
    }

    theEncryptor->mInitialized = 1;
    theEncryptor->mSessionStarted = 1;
    gsDebugFormat(8, (char *)4, 15, sGhttpReturnSuccess, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1154);
    return 1;
}
