/*
 * file:     ghttpEncryption_p02.c
 * unit:     yes
 * function: func_021C121C, func_021C1230, func_021C135C, func_021C137C, func_021C1500, func_021C1668, func_021C1804, func_021C1920, func_021C1A78, func_021C1C78, func_021C1C80, func_021C1C88, func_021C1C90, func_021C1C98
 * address:  0x021C121C
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
 *   func_020948E0  0x020948e0  arm
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_021C1020  0x021c1020  arm   ov114
 *   func_021843E8  0x021843e8  arm   ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   func_021C121C  0x021c121c  arm   ov114
 *   g_021D3B40     0x021d3b40  data  ov114
 *   g_021CE758     0x021ce758  data  ov114
 *   g_021CE7B0     0x021ce7b0  data
 *   g_021CE6F9     0x021ce6f9  data  ov114
 *   g_021CE7C4     0x021ce7c4  data  ov114
 *   g_021CE818     0x021ce818  data
 *   func_02184144  0x02184144  arm   ov009
 *   func_021842D0  0x021842D0  arm   ov009
 *   g_021CE6E0     0x021CE6E0  data
 *   g_021CE75C     0x021CE75C  data
 *   g_021CE858     0x021CE858  data
 *   func_0218437C  0x0218437C  arm   ov009
 *   func_02184200  0x02184200  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   g_021CE72E     0x021CE72E  data
 *   g_021CE8A4     0x021CE8A4  data
 *   g_021CE686                       0x021ce686 data
 *   g_021CE8F8                       0x021ce8f8 data
 *   g_021CE920                       0x021ce920 data
 *   g_021CE93C                       0x021ce93c data
 *   g_021CE970                       0x021ce970 data
 *   g_021CE9AC                       0x021ce9ac data
 *   g_021CE9E4                       0x021ce9e4 data
 *   g_021CEA14                       0x021cea14 data
 *   g_021CEA44                       0x021cea44 data
 *   func_02088168  0x02088168  arm
 *   func_02162248  0x02162248  arm   ov009
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   func_020923B0  0x020923b0  arm
 *   g_021D3B44     0x021d3b44  data  ov114
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
 *   d_021CE713    0x021CE713  data  a1
 *   d_021CED3C    0x021CED3C  data  a4
 */
struct CPSSslConnection;
typedef struct GHTTPCertificateInfo_021C121C {
    char *serverUrl;
    void *caList;
    int pad8;
    int padC;
} GHTTPCertificateInfo_021C121C;

typedef struct GHTTPCertificateInfo_021C135C {
    char *serverUrl;
    void *caList;
    int pad8;
    int refCount;
} GHTTPCertificateInfo_021C135C;

typedef struct CPSSslConnection {
    char pad0[0x5b0];
    char subject[0x100];        /* +0x5b0 */
    char issuer[0x100];         /* +0x6b0 */
    char name[0x50];            /* +0x7b0 */
    int f800;
    char pad1[0x810 - 0x804];
    int (*f810)(int, void *, int);
    void *f814;
    int f818;
    char pad2[0x830 - 0x81c];
} CPSSslConnection;

typedef struct GHTTPTwlCaList {
    void *certs;
    int count;
} GHTTPTwlCaList;

#include "ghttp_types.h"


extern int func_020948E0(const char *s1, const char *s2);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern char *func_021C1020(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void func_0217EAE0(void *);
extern void *func_02184208(void *, int);
extern int func_021C121C(void *, void *);
extern void *func_02184144(int, int, void (*)(void *));
extern void func_021842D0(void *, void *, int (*)(void *, void *));
extern void func_0218437C(int a, int b);
extern int func_02184200(const int *p);
extern void func_021841B0(void *);
extern void func_02088168(unsigned long *);
extern void func_02162248(void *, unsigned long);
extern void *func_0217EAB0(unsigned long);
extern void *func_020923B0(void *, int, unsigned long);
extern int func_0215FC80(int s, void *con);
int CaseInsensitiveCompare(const char **a, const char **b);
void *func_021C1230(char *url);
void func_021C135C(u8 *p);
int func_021C137C(char *url, void *theRootCAList);
int func_021C1500(char *url);
int func_021C1668(int result, CPSSslConnection *con, int level);
CPSSslConnection *func_021C1804(char *url);
int func_021C1920(GHIConnection *connection, GHIEncryptor *theEncryptor);
int func_021C1A78(GHIConnection *connection, GHIEncryptor *theEncryptor);
int func_021C1C78(void *a0, void *a1, char *a2, int a3, int *a4);
int func_021C1C80(void *connection, void *encryptor, char *buffer, int *bufferLen);
int func_021C1C88(void);
int func_021C1C90(void);
int func_021C1C98(int unused, unsigned int *p);
extern void *g_021D3B40;
extern char g_021CE758[];
extern char g_021CE7B0[];
extern char g_021CE6F9[];
extern char g_021CE7C4[];
extern char g_021CE818[];
extern char g_021CE6E0[];
extern char g_021CE75C[];
extern char g_021CE858[];
extern char g_021CE72E[];
extern char g_021CE8A4[];
extern char g_021CE686[];       /* __FUNCTION__ */
extern char g_021CE8F8[];
extern char g_021CE920[];
extern char g_021CE93C[];
extern char g_021CE970[];
extern char g_021CE9AC[];
extern char g_021CE9E4[];
extern char g_021CEA14[];
extern char g_021CEA44[];
extern unsigned long g_021D3B44[8];
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
extern char d_021CE713[];
extern char d_021CED3C[];


int CaseInsensitiveCompare(const char **a, const char **b)
{
    return func_020948E0(*a, *b);
}


/*
 * sdk:      ghiEncryptorGetRootCAList (libdwcgsghttp.TWL.HYB.a ghttpencryption.o)
 */
void *func_021C1230(char *url)
{
    GHTTPCertificateInfo_021C121C certInfo;
    GHTTPCertificateInfo_021C121C *certInfoToReturn;
    int pos;

    if (url == 0 || g_021D3B40 == 0 || func_020948E0(url, g_021CE758) == 0) {
        func_0217D254(8, (char *)4, 1, g_021CE7C4, g_021CE7B0, g_021CE6F9, 0x312, url, g_021D3B40);
        return 0;
    }
    certInfo.serverUrl = func_021C1020(url);
    pos = func_021843E8(g_021D3B40, &certInfo, func_021C121C, 0, 1);
    func_0217EAE0(certInfo.serverUrl);
    if (pos == -1) {
        func_0217D254(8, (char *)4, 1, g_021CE818, g_021CE7B0, g_021CE6F9, 0x323, url);
        return 0;
    }
    certInfoToReturn = func_02184208(g_021D3B40, pos);
    return certInfoToReturn->caList;
}


/*
 * Releases the handle at +0x00 and empties the +0x00/+0x04 pair.
 */
void func_021C135C(u8 *p)
{
    void *q = *(void **)p;

    *(u32 *)(p + 4) = 0;
    func_0217EAE0(q);
    *(u32 *)p = 0;
}


/*
 * sdk:      ghiEncryptorSetTwlRootCA (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 */
int func_021C137C(char *url, void *theRootCAList)
{
    GHTTPCertificateInfo_021C135C certInfo;
    int pos;
    GHTTPCertificateInfo_021C135C *certInfoToUpdate;

    if (url == 0 || theRootCAList == 0 || func_020948E0(url, g_021CE758) == 0) {
        func_0217D254(8, (char *)4, 1, g_021CE75C, g_021CE7B0, g_021CE6E0, 0x345, url, theRootCAList);
        return 0;
    }
    if (g_021D3B40 == 0) {
        g_021D3B40 = func_02184144(0x10, 1, (void (*)(void *))func_021C135C);
        if (g_021D3B40 == 0) {
            func_0217D254(8, (char *)2, 1, g_021CE858, g_021CE7B0, g_021CE6E0, 0x354);
            return 0;
        }
    }
    certInfo.serverUrl = func_021C1020(url);
    certInfo.caList = theRootCAList;
    certInfo.refCount = 1;
    pos = func_021843E8(g_021D3B40, &certInfo, func_021C121C, 0, 1);
    if (pos == -1) {
        func_021842D0(g_021D3B40, &certInfo, func_021C121C);
    } else {
        func_0217EAE0(certInfo.serverUrl);
        certInfoToUpdate = func_02184208(g_021D3B40, pos);
        certInfoToUpdate->refCount++;
    }
    return 1;
}


/*
 * sdk:      ghiEncryptorCleanupTwlRootCA (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 */
int func_021C1500(char *url)
{
    int result;
    GHTTPCertificateInfo_021C135C certInfo;
    int pos;
    GHTTPCertificateInfo_021C135C *certInfoToUpdate;

    result = 1;
    if (url == 0 || g_021D3B40 == 0 || func_020948E0(url, g_021CE758) == 0) {
        func_0217D254(8, (char *)4, 1, g_021CE8A4, g_021CE7B0, g_021CE72E, 0x37b, url, g_021D3B40);
        return 0;
    }
    certInfo.serverUrl = func_021C1020(url);
    pos = func_021843E8(g_021D3B40, &certInfo, func_021C121C, 0, 1);
    if (pos == -1) {
        func_0217D254(8, (char *)4, 1, g_021CE818, g_021CE7B0, g_021CE72E, 0x38a, url);
        result = 0;
    } else {
        certInfoToUpdate = func_02184208(g_021D3B40, pos);
        certInfoToUpdate->refCount--;
        if (certInfoToUpdate->refCount <= 0) {
            func_0218437C((int)g_021D3B40, pos);
            if (func_02184200(g_021D3B40) == 0) {
                func_021841B0(g_021D3B40);
                g_021D3B40 = 0;
            }
        }
    }
    func_0217EAE0(certInfo.serverUrl);
    return result;
}


/*
 * sdk:      SslAuthCallback (ghttpencryption.o, static)
 */
int func_021C1668(int result, CPSSslConnection *con, int level)
{
    func_0217D254(8, (char *)4, 8, g_021CE8F8, g_021CE7B0, g_021CE686, 938);
    func_0217D254(8, (char *)4, 8, g_021CE920, level, con->issuer, con->name, con->subject);

    if (result & 0x8000) {
        func_0217D254(8, (char *)4, 2, g_021CE93C, g_021CE7B0, g_021CE686, 946);
        result &= ~0x8000;
    }
    if (result & 0x4000) {
        func_0217D254(8, (char *)4, 2, g_021CE970, g_021CE7B0, g_021CE686, 954);
        result &= ~0x4000;
    }

    switch (result & 0xff) {
    case 0:
        break;
    case 1:
        func_0217D254(8, (char *)4, 2, g_021CE9AC, g_021CE7B0, g_021CE686, 963);
        break;
    case 2:
        func_0217D254(8, (char *)4, 2, g_021CE9E4, g_021CE7B0, g_021CE686, 969);
        break;
    case 3:
        func_0217D254(8, (char *)4, 2, g_021CEA14, g_021CE7B0, g_021CE686, 975);
        break;
    case 4:
        func_0217D254(8, (char *)4, 2, g_021CEA44, g_021CE7B0, g_021CE686, 981);
        break;
    }
    return result;
}


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


int func_021C1920(GHIConnection *connection, GHIEncryptor *theEncryptor)
{
    GsTwlSslInterface *sslInterface;

    func_0217D254(8, (char *)4, 0xf, g_021CEAE8, g_021CE7B0, g_021CE696, 0x417);
    theEncryptor->mInterface = func_0217EAB0(8);
    if (theEncryptor->mInterface == 0) {
        func_0217D254(8, (char *)2, 2, g_021CEAF8, g_021CE7B0, g_021CE696, 0x425, 8);
        return 3;
    }
    {
        char *p = (char *)theEncryptor->mInterface;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
    }
    sslInterface = theEncryptor->mInterface;
    sslInterface->con = func_021C1804(connection->URL);
    sslInterface->connected = 0;
    if (sslInterface->con == 0) {
        func_0217D254(8, (char *)4, 0xf, g_021CEB40, g_021CE7B0, g_021CE696, 0x431);
        return 3;
    }
    theEncryptor->field_08 = 1;
    theEncryptor->initialized = 0;
    theEncryptor->sessionEstablished = 0;
    theEncryptor->encryptOnBuffer = 0;
    theEncryptor->encryptOnSend = 1;
    theEncryptor->handshaking = 1;
    func_0217D254(8, (char *)4, 0xf, g_021CEB7C, g_021CE7B0, g_021CE696, 0x43d);
    return 1;
}


/*
 * sdk:      ghiEncryptorSslStartFunc (ghttpencryption.o)
 */
int func_021C1A78(GHIConnection *connection, GHIEncryptor *theEncryptor)
{
    GsTwlSslInterface *sslInterface = theEncryptor->mInterface;

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

    theEncryptor->initialized = 1;
    theEncryptor->sessionEstablished = 1;
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


int func_021C1C80(void *connection, void *encryptor, char *buffer, int *bufferLen)
{
    return 1;
}


int func_021C1C88(void)
{
    return 3;
}


/*
 * sdk:      ghiEncryptorSslDecryptFunc (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 *
 * notes:    `mov r0, #3; bx lr`; ghttpSetRequestEncryptionEngine's relocation at
 *           +0xE4 (ABS32 ghiEncryptorSslDecryptFunc) is the pool word at
 *           0x021C1180.  Byte-identical to 0x021C1C88: the name comes from that
 *           relocation.  Seeded in layout/function_starts.txt.
 */
int func_021C1C90(void)
{
    return 3;
}


int func_021C1C98(int unused, unsigned int *p)
{
    func_0217D254(8, (char *)4, 0xf, d_021CED3C, g_021CE7B0, d_021CE713, 0x4d5);
    if (p != 0) {
        unsigned int *q = (unsigned int *)p[0];
        if (q != 0) {
            if (q[0] != 0)
                func_0217EAE0((void *)q[0]);
            func_0217EAE0(q);
            p[0] = 0;
        }
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
    }
    return 1;
}
