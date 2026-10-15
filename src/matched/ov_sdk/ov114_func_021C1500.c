/*
 * function: ghiEncryptorCleanupTwlRootCA
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
 *   strcmp  0x020948E0  arm
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   ghiGetServerAddressFromUrl  0x021C1020  arm   ov114
 *   func_021843E8  0x021843E8  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   ArrayDeleteAt  0x0218437C  arm   ov009
 *   ArrayLength  0x02184200  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   gsifree  0x0217EAE0  arm   ov009
 *   ghiCompareCertUrl  0x021C121C  arm   ov114
 *   gGhttpRootCaTable     0x021D3B40  data
 *   sGhttpEmptyString     0x021CE758  data
 *   sGhttpEncryptionFileName     0x021CE7B0  data
 *   sFuncNameGhiEncryptorCleanupTwlRootCA     0x021CE72E  data
 *   sGhttpSslNullPointerOrEmpty3     0x021CE8A4  data
 *   sGhttpSslCouldNotFindUrl     0x021CE818  data
 */

typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int pad8;
    int refCount;
} GHTTPCertificateInfo;

extern int strcmp(const char *, const char *);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern char *ghiGetServerAddressFromUrl(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void *func_02184208(void *, int);
extern void ArrayDeleteAt(int a, int b);
extern int ArrayLength(const int *p);
extern void func_021841B0(void *);
extern void gsifree(void *);
extern int ghiCompareCertUrl(void *, void *);
extern void *gGhttpRootCaTable;
extern char sGhttpEmptyString[];
extern char sGhttpEncryptionFileName[];
extern char sFuncNameGhiEncryptorCleanupTwlRootCA[];
extern char sGhttpSslNullPointerOrEmpty3[];
extern char sGhttpSslCouldNotFindUrl[];

int ghiEncryptorCleanupTwlRootCA(char *url)
{
    int result;
    GHTTPCertificateInfo certInfo;
    int pos;
    GHTTPCertificateInfo *certInfoToUpdate;

    result = 1;
    if (url == 0 || gGhttpRootCaTable == 0 || strcmp(url, sGhttpEmptyString) == 0) {
        gsDebugFormat(8, (char *)4, 1, sGhttpSslNullPointerOrEmpty3, sGhttpEncryptionFileName, sFuncNameGhiEncryptorCleanupTwlRootCA, 0x37b, url, gGhttpRootCaTable);
        return 0;
    }
    certInfo.serverUrl = ghiGetServerAddressFromUrl(url);
    pos = func_021843E8(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl, 0, 1);
    if (pos == -1) {
        gsDebugFormat(8, (char *)4, 1, sGhttpSslCouldNotFindUrl, sGhttpEncryptionFileName, sFuncNameGhiEncryptorCleanupTwlRootCA, 0x38a, url);
        result = 0;
    } else {
        certInfoToUpdate = func_02184208(gGhttpRootCaTable, pos);
        certInfoToUpdate->refCount--;
        if (certInfoToUpdate->refCount <= 0) {
            ArrayDeleteAt((int)gGhttpRootCaTable, pos);
            if (ArrayLength(gGhttpRootCaTable) == 0) {
                func_021841B0(gGhttpRootCaTable);
                gGhttpRootCaTable = 0;
            }
        }
    }
    gsifree(certInfo.serverUrl);
    return result;
}
