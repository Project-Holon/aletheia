/*
 * function: func_021C1A78
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
 *   func_0217D254                    0x0217d254 arm  ov009
 *   func_0215FC80                    0x0215fc80 arm  ov009
 *   g_021CE7B0                       0x021ce7b0 data
 *   g_021CE6C7                       0x021ce6c7 data
 *   g_021CEAE8                       0x021ceae8 data
 *   g_021CEBB0                       0x021cebb0 data
 *   g_021CEBFC                       0x021cebfc data
 *   g_021CEC58                       0x021cec58 data
 *   g_021CEC9C                       0x021cec9c data
 *   g_021CECD4                       0x021cecd4 data
 *   g_021CED20                       0x021ced20 data
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

extern void func_0217D254(int theCat, int theType, unsigned char theLevel,
                          const char *theTokenStr, ...);
extern int func_0215FC80(int s, void *con);
extern char g_021CE7B0[];       /* __FILE__ */
extern char g_021CE6C7[];       /* __FUNCTION__ */
extern char g_021CEAE8[];
extern char g_021CEBB0[];
extern char g_021CEBFC[];
extern char g_021CEC58[];
extern char g_021CEC9C[];
extern char g_021CECD4[];
extern char g_021CED20[];

int func_021C1A78(GHIConnection *connection, GHIEncryptor *theEncryptor)
{
    gsTwlSslInterface *sslInterface = theEncryptor->mInterface;

    func_0217D254(8, 4, 15, g_021CEAE8, g_021CE7B0, g_021CE6C7, 1100);

    if (sslInterface->connected == 0) {
        int result = func_0215FC80(connection->socket, sslInterface->con);
        if (result < 0) {
            switch (result) {
            case -28:
                func_0217D254(8, 4, 15, g_021CEBB0, g_021CE7B0, g_021CE6C7, 1113);
                break;
            case -33:
                func_0217D254(8, 4, 15, g_021CEBFC, g_021CE6C7, 1118);
                break;
            case -39:
                func_0217D254(8, 4, 15, g_021CEC58, g_021CE7B0, g_021CE6C7, 1124);
                break;
            case -42:
                func_0217D254(8, 4, 15, g_021CEC9C, g_021CE7B0, g_021CE6C7, 1129);
                break;
            default:
                func_0217D254(8, 4, 15, g_021CECD4, g_021CE7B0, g_021CE6C7, 1135, result);
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
    func_0217D254(8, 4, 15, g_021CED20, g_021CE7B0, g_021CE6C7, 1154);
    return 1;
}
