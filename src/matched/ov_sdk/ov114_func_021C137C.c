/*
 * function: ghiEncryptorSetTwlRootCA
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
 *   strcmp  0x020948E0  arm
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_02184144  0x02184144  arm   ov009
 *   ghiGetServerAddressFromUrl  0x021C1020  arm   ov114
 *   func_021843E8  0x021843E8  arm   ov009
 *   func_021842D0  0x021842D0  arm   ov009
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   ghiFreeCertificateInfo  0x021C135C  arm   ov114
 *   ghiCompareCertUrl  0x021C121C  arm   ov114
 *   sGhttpEmptyString     0x021CE758  data
 *   sGhttpEncryptionFileName     0x021CE7B0  data
 *   sFuncNameGhiEncryptorSetTwlRootCA     0x021CE6E0  data
 *   sGhttpSslNullPointerOrEmpty     0x021CE75C  data
 *   gGhttpRootCaTable     0x021D3B40  data
 *   sGhttpSslOutOfMemoryCannot     0x021CE858  data
 */

typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int pad8;
    int refCount;
} GHTTPCertificateInfo;

extern int strcmp(const char *, const char *);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void *func_02184144(int, int, void (*)(void *));
extern char *ghiGetServerAddressFromUrl(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void func_021842D0(void *, void *, int (*)(void *, void *));
extern void func_0217EAE0(void *);
extern void *func_02184208(void *, int);
typedef unsigned char  u8;
extern void ghiFreeCertificateInfo(u8 *p);
extern int ghiCompareCertUrl(void *, void *);
extern void *gGhttpRootCaTable;
extern char sGhttpEmptyString[];
extern char sGhttpEncryptionFileName[];
extern char sFuncNameGhiEncryptorSetTwlRootCA[];
extern char sGhttpSslNullPointerOrEmpty[];
extern char sGhttpSslOutOfMemoryCannot[];

int ghiEncryptorSetTwlRootCA(char *url, void *theRootCAList)
{
    GHTTPCertificateInfo certInfo;
    int pos;
    GHTTPCertificateInfo *certInfoToUpdate;

    if (url == 0 || theRootCAList == 0 || strcmp(url, sGhttpEmptyString) == 0) {
        func_0217D254(8, (char *)4, 1, sGhttpSslNullPointerOrEmpty, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSetTwlRootCA, 0x345, url, theRootCAList);
        return 0;
    }
    if (gGhttpRootCaTable == 0) {
        gGhttpRootCaTable = func_02184144(0x10, 1, (void (*)(void *))ghiFreeCertificateInfo);
        if (gGhttpRootCaTable == 0) {
            func_0217D254(8, (char *)2, 1, sGhttpSslOutOfMemoryCannot, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSetTwlRootCA, 0x354);
            return 0;
        }
    }
    certInfo.serverUrl = ghiGetServerAddressFromUrl(url);
    certInfo.caList = theRootCAList;
    certInfo.refCount = 1;
    pos = func_021843E8(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl, 0, 1);
    if (pos == -1) {
        func_021842D0(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl);
    } else {
        func_0217EAE0(certInfo.serverUrl);
        certInfoToUpdate = func_02184208(gGhttpRootCaTable, pos);
        certInfoToUpdate->refCount++;
    }
    return 1;
}
