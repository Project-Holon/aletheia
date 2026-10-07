/*
 * file:     ghttpEncryption_p04.c
 * unit:     yes
 * function: func_021C1804, func_021C1920, func_021C1A78, func_021C1C78
 * address:  0x021C1804
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C1230  0x021c1230  arm   ov114
 *   func_02088168  0x02088168  arm
 *   func_02162248  0x02162248  arm   ov009
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   func_020923B0  0x020923b0  arm
 *   func_0217D254  0x0217d254  arm   ov009
 *   g_021D3B44     0x021d3b44  data  ov114
 *   func_021C1668  0x021c1668  arm   ov114
 *   g_021CE7B0     0x021ce7b0  data
 *   g_021CE678     0x021ce678  data  ov114
 *   g_021CEA74     0x021cea74  data  ov114
 *   g_021CEAB4     0x021ceab4  data  ov114
 *   g_021CE696     0x021ce696  data
 *   g_021CEAE8     0x021ceae8  data
 *   g_021CEAF8     0x021ceaf8  data
 *   g_021CEB40     0x021ceb40  data
 *   g_021CEB7C     0x021ceb7c  data
 *   func_0215FC80                    0x0215fc80 arm  ov009
 *   g_021CE6C7                       0x021ce6c7 data
 *   g_021CEBB0                       0x021cebb0 data
 *   g_021CEBFC                       0x021cebfc data
 *   g_021CEC58                       0x021cec58 data
 *   g_021CEC9C                       0x021cec9c data
 *   g_021CECD4                       0x021cecd4 data
 *   g_021CED20                       0x021ced20 data
 */
struct CPSSslConnection;
typedef struct GHTTPTwlCaList {
    void *certs;
    int count;
} GHTTPTwlCaList;

typedef struct CPSSslConnection {
    char pad0[0x800];
    int f800;
    char pad1[0x810 - 0x804];
    int (*f810)(int, void *, int);
    void *f814;
    int f818;
    char pad2[0x830 - 0x81c];
} CPSSslConnection;

typedef struct GHIConnection_021C1920 {
    char pad0[0x14];
    char *url;
} GHIConnection_021C1920;

typedef struct GsTwlSslInterface {
    void *sslCon;
    int field4;
} GsTwlSslInterface;

typedef struct GHIEncryptor_021C1920 {
    GsTwlSslInterface *engine;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
} GHIEncryptor_021C1920;

typedef struct gsTwlSslInterface {
    void *con;                  /* +0x00 struct _CPSSslConnection * */
    int connected;              /* +0x04 */
} gsTwlSslInterface;

typedef struct GHIEncryptor_021C1A78 {
    gsTwlSslInterface *mInterface; /* +0x00 */
    char pad4[0xc - 0x4];
    int mInitialized;           /* +0x0c */
    int mSessionStarted;        /* +0x10 */
} GHIEncryptor_021C1A78;

typedef struct GHIConnection_021C1A78 {
    char pad0[0x40];
    int result;                 /* +0x040 */
    char pad44[0x50 - 0x44];
    int socket;                 /* +0x050 */
    int socketError;            /* +0x054 */
    char pad58[0x124 - 0x58];
    int completed;              /* +0x124 */
} GHIConnection_021C1A78;

typedef unsigned char u8;

typedef unsigned int u32;

extern void *func_021C1230(char *url);
extern void func_02088168(unsigned long *);
extern void func_02162248(void *, unsigned long);
extern void *func_0217EAB0(unsigned long);
extern void *func_020923B0(void *, int, unsigned long);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021C1668(int result, struct CPSSslConnection *con, int level);
extern int func_0215FC80(int s, void *con);
CPSSslConnection *func_021C1804(char *url);
int func_021C1920(GHIConnection_021C1920 *connection, GHIEncryptor_021C1920 *theEncryptor);
int func_021C1A78(GHIConnection_021C1A78 *connection, GHIEncryptor_021C1A78 *theEncryptor);
int func_021C1C78(void *a0, void *a1, char *a2, int a3, int *a4);
extern unsigned long g_021D3B44[8];
extern char g_021CE7B0[];
extern char g_021CE678[];
extern char g_021CEA74[];
extern char g_021CEAB4[];
extern char g_021CE696[];
extern char g_021CEAE8[];
extern char g_021CEAF8[];
extern char g_021CEB40[];
extern char g_021CEB7C[];
extern char g_021CE6C7[];       /* __FUNCTION__ */
extern char g_021CEBB0[];
extern char g_021CEBFC[];
extern char g_021CEC58[];
extern char g_021CEC9C[];
extern char g_021CECD4[];
extern char g_021CED20[];


/*
 * sdk:      ghiTwlSSLInit (libdwcgsghttp.TWL.HYB.a ghttpencryption.o)
 */
CPSSslConnection *func_021C1804(char *url)
{
    GHTTPTwlCaList *rootCaList;
    CPSSslConnection *sslCon = 0;

    rootCaList = func_021C1230(url);
    if (rootCaList != 0) {
        if (rootCaList->certs != 0 && rootCaList->count > 0) {
            func_02088168(g_021D3B44);
            func_02162248(g_021D3B44, 0x20);
            sslCon = func_0217EAB0(0x830);
            if (sslCon != 0) {
                func_020923B0(sslCon, 0, 0x830);
                sslCon->f800 = 0;
                sslCon->f814 = rootCaList->certs;
                sslCon->f818 = rootCaList->count;
                sslCon->f810 = (int (*)(int,  void *, int))func_021C1668;
            } else {
                func_0217D254(8, (char *)2, 2, g_021CEA74, g_021CE7B0, g_021CE678, 0x3fc);
            }
        } else {
            func_0217D254(8, (char *)2, 2, g_021CEAB4, g_021CE7B0, g_021CE678, 0x403);
        }
    } else {
        func_0217D254(8, (char *)2, 2, g_021CEAB4, g_021CE7B0, g_021CE678, 0x40a);
    }
    return sslCon;
}


int func_021C1920(GHIConnection_021C1920 *connection, GHIEncryptor_021C1920 *theEncryptor)
{
    GsTwlSslInterface *sslInterface;

    func_0217D254(8, (char *)4, 0xf, g_021CEAE8, g_021CE7B0, g_021CE696, 0x417);
    theEncryptor->engine = func_0217EAB0(8);
    if (theEncryptor->engine == 0) {
        func_0217D254(8, (char *)2, 2, g_021CEAF8, g_021CE7B0, g_021CE696, 0x425, 8);
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
    sslInterface->sslCon = func_021C1804(connection->url);
    sslInterface->field4 = 0;
    if (sslInterface->sslCon == 0) {
        func_0217D254(8, (char *)4, 0xf, g_021CEB40, g_021CE7B0, g_021CE696, 0x431);
        return 3;
    }
    theEncryptor->field8 = 1;
    theEncryptor->fieldC = 0;
    theEncryptor->field10 = 0;
    theEncryptor->field14 = 0;
    theEncryptor->field18 = 1;
    theEncryptor->field1C = 1;
    func_0217D254(8, (char *)4, 0xf, g_021CEB7C, g_021CE7B0, g_021CE696, 0x43d);
    return 1;
}


/*
 * sdk:      ghiEncryptorSslStartFunc (ghttpencryption.o)
 */
int func_021C1A78(GHIConnection_021C1A78 *connection, GHIEncryptor_021C1A78 *theEncryptor)
{
    gsTwlSslInterface *sslInterface = theEncryptor->mInterface;

    func_0217D254(8, (char *)4, 15, g_021CEAE8, g_021CE7B0, g_021CE6C7, 1100);

    if (sslInterface->connected == 0) {
        int result = func_0215FC80(connection->socket, sslInterface->con);
        if (result < 0) {
            switch (result) {
            case -28:
                func_0217D254(8, (char *)4, 15, g_021CEBB0, g_021CE7B0, g_021CE6C7, 1113);
                break;
            case -33:
                func_0217D254(8, (char *)4, 15, g_021CEBFC, g_021CE6C7, 1118);
                break;
            case -39:
                func_0217D254(8, (char *)4, 15, g_021CEC58, g_021CE7B0, g_021CE6C7, 1124);
                break;
            case -42:
                func_0217D254(8, (char *)4, 15, g_021CEC9C, g_021CE7B0, g_021CE6C7, 1129);
                break;
            default:
                func_0217D254(8, (char *)4, 15, g_021CECD4, g_021CE7B0, g_021CE6C7, 1135, result);
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
    func_0217D254(8, (char *)4, 15, g_021CED20, g_021CE7B0, g_021CE6C7, 1154);
    return 1;
}

/*
 * Constant predicate: always 1.
 */
int func_021C1C78(void *a0, void *a1, char *a2, int a3, int *a4)
{
    return 1;
}
