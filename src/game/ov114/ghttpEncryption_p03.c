/*
 * file:     ghttpEncryption_p03.c
 * unit:     yes
 * function: func_021C135C, func_021C137C, func_021C1500, func_021C1668
 * address:  0x021C135C
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
 *   func_020948E0  0x020948E0  arm
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_02184144  0x02184144  arm   ov009
 *   func_021C1020  0x021C1020  arm   ov114
 *   func_021843E8  0x021843E8  arm   ov009
 *   func_021842D0  0x021842D0  arm   ov009
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   func_021C121C  0x021C121C  arm   ov114
 *   g_021CE758     0x021CE758  data
 *   g_021CE7B0     0x021CE7B0  data
 *   g_021CE6E0     0x021CE6E0  data
 *   g_021CE75C     0x021CE75C  data
 *   g_021D3B40     0x021D3B40  data
 *   g_021CE858     0x021CE858  data
 *   func_0218437C  0x0218437C  arm   ov009
 *   func_02184200  0x02184200  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   g_021CE72E     0x021CE72E  data
 *   g_021CE8A4     0x021CE8A4  data
 *   g_021CE818     0x021CE818  data
 *   g_021CE686                       0x021ce686 data
 *   g_021CE8F8                       0x021ce8f8 data
 *   g_021CE920                       0x021ce920 data
 *   g_021CE93C                       0x021ce93c data
 *   g_021CE970                       0x021ce970 data
 *   g_021CE9AC                       0x021ce9ac data
 *   g_021CE9E4                       0x021ce9e4 data
 *   g_021CEA14                       0x021cea14 data
 *   g_021CEA44                       0x021cea44 data
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int pad8;
    int refCount;
} GHTTPCertificateInfo;

typedef struct CPSSslConnection {
    char pad0[0x5b0];
    char subject[0x100];        /* +0x5b0 */
    char issuer[0x100];         /* +0x6b0 */
    char name[0x100];           /* +0x7b0 */
} CPSSslConnection;

extern void func_0217EAE0(void *);
extern int func_020948E0(const char *, const char *);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void *func_02184144(int, int, void (*)(void *));
extern char *func_021C1020(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void func_021842D0(void *, void *, int (*)(void *, void *));
extern void *func_02184208(void *, int);
extern int func_021C121C(void *, void *);
extern void func_0218437C(int a, int b);
extern int func_02184200(const int *p);
extern void func_021841B0(void *);
void func_021C135C(u8 *p);
int func_021C137C(char *url, void *theRootCAList);
int func_021C1500(char *url);
int func_021C1668(int result, CPSSslConnection *con, int level);
extern void *g_021D3B40;
extern char g_021CE758[];
extern char g_021CE7B0[];
extern char g_021CE6E0[];
extern char g_021CE75C[];
extern char g_021CE858[];
extern char g_021CE72E[];
extern char g_021CE8A4[];
extern char g_021CE818[];
extern char g_021CE686[];       /* __FUNCTION__ */
extern char g_021CE8F8[];
extern char g_021CE920[];
extern char g_021CE93C[];
extern char g_021CE970[];
extern char g_021CE9AC[];
extern char g_021CE9E4[];
extern char g_021CEA14[];
extern char g_021CEA44[];


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
    GHTTPCertificateInfo certInfo;
    int pos;
    GHTTPCertificateInfo *certInfoToUpdate;

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
    GHTTPCertificateInfo certInfo;
    int pos;
    GHTTPCertificateInfo *certInfoToUpdate;

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
