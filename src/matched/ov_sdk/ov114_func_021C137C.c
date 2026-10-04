/*
 * function: func_021C137C
 * address:  0x021C137C
 * packet:   pkt_ov114_021C137C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEncryptorSetTwlRootCA (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
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
 *   func_021C135C  0x021C135C  arm   ov114
 *   func_021C121C  0x021C121C  arm   ov114
 *   g_021CE758     0x021CE758  data
 *   g_021CE7B0     0x021CE7B0  data
 *   g_021CE6E0     0x021CE6E0  data
 *   g_021CE75C     0x021CE75C  data
 *   g_021D3B40     0x021D3B40  data
 *   g_021CE858     0x021CE858  data
 */

typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int pad8;
    int refCount;
} GHTTPCertificateInfo;

extern int func_020948E0(const char *, const char *);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void *func_02184144(int, int, void (*)(void *));
extern char *func_021C1020(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void func_021842D0(void *, void *, int (*)(void *, void *));
extern void func_0217EAE0(void *);
extern void *func_02184208(void *, int);
extern void func_021C135C(void *);
extern int func_021C121C(void *, void *);
extern void *g_021D3B40;
extern char g_021CE758[];
extern char g_021CE7B0[];
extern char g_021CE6E0[];
extern char g_021CE75C[];
extern char g_021CE858[];

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
        g_021D3B40 = func_02184144(0x10, 1, func_021C135C);
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
