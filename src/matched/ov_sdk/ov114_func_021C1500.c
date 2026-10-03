/*
 * function: func_021C1500
 * address:  0x021C1500
 * packet:   pkt_ov114_021C1500
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEncryptorCleanupTwlRootCA (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_021C1020  0x021C1020  arm   ov114
 *   func_021843E8  0x021843E8  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   func_0218437C  0x0218437C  arm   ov009
 *   func_02184200  0x02184200  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   func_021C121C  0x021C121C  arm   ov114
 *   g_021D3B40     0x021D3B40  data
 *   g_021CE758     0x021CE758  data
 *   g_021CE7B0     0x021CE7B0  data
 *   g_021CE72E     0x021CE72E  data
 *   g_021CE8A4     0x021CE8A4  data
 *   g_021CE818     0x021CE818  data
 */

typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int pad8;
    int refCount;
} GHTTPCertificateInfo;

extern int func_020948E0(const char *, const char *);
extern void func_0217D254(int, int, unsigned char, const char *, ...);
extern char *func_021C1020(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void *func_02184208(void *, int);
extern void func_0218437C(void *, int);
extern int func_02184200(const int *p);
extern void func_021841B0(void *);
extern void func_0217EAE0(void *);
extern int func_021C121C(void *, void *);
extern void *g_021D3B40;
extern char g_021CE758[];
extern char g_021CE7B0[];
extern char g_021CE72E[];
extern char g_021CE8A4[];
extern char g_021CE818[];

int func_021C1500(char *url)
{
    int result;
    GHTTPCertificateInfo certInfo;
    int pos;
    GHTTPCertificateInfo *certInfoToUpdate;

    result = 1;
    if (url == 0 || g_021D3B40 == 0 || func_020948E0(url, g_021CE758) == 0) {
        func_0217D254(8, 4, 1, g_021CE8A4, g_021CE7B0, g_021CE72E, 0x37b, url, g_021D3B40);
        return 0;
    }
    certInfo.serverUrl = func_021C1020(url);
    pos = func_021843E8(g_021D3B40, &certInfo, func_021C121C, 0, 1);
    if (pos == -1) {
        func_0217D254(8, 4, 1, g_021CE818, g_021CE7B0, g_021CE72E, 0x38a, url);
        result = 0;
    } else {
        certInfoToUpdate = func_02184208(g_021D3B40, pos);
        certInfoToUpdate->refCount--;
        if (certInfoToUpdate->refCount <= 0) {
            func_0218437C(g_021D3B40, pos);
            if (func_02184200(g_021D3B40) == 0) {
                func_021841B0(g_021D3B40);
                g_021D3B40 = 0;
            }
        }
    }
    func_0217EAE0(certInfo.serverUrl);
    return result;
}
