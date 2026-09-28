/*
 * function: func_021C1230
 * address:  0x021C1230
 * packet:   pkt_ov114_021C1230
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEncryptorGetRootCAList (libdwcgsghttp.TWL.HYB.a ghttpencryption.o)
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
 */

typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int pad8;
    int padC;
} GHTTPCertificateInfo;

extern int func_020948E0(const char *, const char *);
extern void func_0217D254(int, int, unsigned char, const char *, ...);
extern char *func_021C1020(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void func_0217EAE0(void *);
extern void *func_02184208(void *, int);
extern int func_021C121C(void *, void *);
extern void *g_021D3B40;
extern char g_021CE758[];
extern char g_021CE7B0[];
extern char g_021CE6F9[];
extern char g_021CE7C4[];
extern char g_021CE818[];

void *func_021C1230(char *url)
{
    GHTTPCertificateInfo certInfo;
    GHTTPCertificateInfo *certInfoToReturn;
    int pos;

    if (url == 0 || g_021D3B40 == 0 || func_020948E0(url, g_021CE758) == 0) {
        func_0217D254(8, 4, 1, g_021CE7C4, g_021CE7B0, g_021CE6F9, 0x312, url, g_021D3B40);
        return 0;
    }
    certInfo.serverUrl = func_021C1020(url);
    pos = func_021843E8(g_021D3B40, &certInfo, func_021C121C, 0, 1);
    func_0217EAE0(certInfo.serverUrl);
    if (pos == -1) {
        func_0217D254(8, 4, 1, g_021CE818, g_021CE7B0, g_021CE6F9, 0x323, url);
        return 0;
    }
    certInfoToReturn = func_02184208(g_021D3B40, pos);
    return certInfoToReturn->caList;
}
