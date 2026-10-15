/*
 * function: ghiEncryptorGetRootCAList
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
 *   strcmp  0x020948e0  arm
 *   func_0217D254  0x0217d254  arm   ov009
 *   ghiGetServerAddressFromUrl  0x021c1020  arm   ov114
 *   func_021843E8  0x021843e8  arm   ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   ghiCompareCertUrl  0x021c121c  arm   ov114
 *   gGhttpRootCaTable     0x021d3b40  data  ov114
 *   sGhttpEmptyString     0x021ce758  data  ov114
 *   sGhttpEncryptionFileName     0x021ce7b0  data
 *   sFuncNameGhiEncryptorGetRootCAList     0x021ce6f9  data  ov114
 *   sGhttpSslNullPointerOrEmpty2     0x021ce7c4  data  ov114
 *   sGhttpSslCouldNotFindUrl     0x021ce818  data
 */

typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int pad8;
    int padC;
} GHTTPCertificateInfo;

extern int strcmp(const char *, const char *);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern char *ghiGetServerAddressFromUrl(char *);
extern int func_021843E8(void *, void *, int (*)(void *, void *), int, int);
extern void func_0217EAE0(void *);
extern void *func_02184208(void *, int);
extern int ghiCompareCertUrl(void *, void *);
extern void *gGhttpRootCaTable;
extern char sGhttpEmptyString[];
extern char sGhttpEncryptionFileName[];
extern char sFuncNameGhiEncryptorGetRootCAList[];
extern char sGhttpSslNullPointerOrEmpty2[];
extern char sGhttpSslCouldNotFindUrl[];

void *ghiEncryptorGetRootCAList(char *url)
{
    GHTTPCertificateInfo certInfo;
    GHTTPCertificateInfo *certInfoToReturn;
    int pos;

    if (url == 0 || gGhttpRootCaTable == 0 || strcmp(url, sGhttpEmptyString) == 0) {
        func_0217D254(8, (char *)4, 1, sGhttpSslNullPointerOrEmpty2, sGhttpEncryptionFileName, sFuncNameGhiEncryptorGetRootCAList, 0x312, url, gGhttpRootCaTable);
        return 0;
    }
    certInfo.serverUrl = ghiGetServerAddressFromUrl(url);
    pos = func_021843E8(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl, 0, 1);
    func_0217EAE0(certInfo.serverUrl);
    if (pos == -1) {
        func_0217D254(8, (char *)4, 1, sGhttpSslCouldNotFindUrl, sGhttpEncryptionFileName, sFuncNameGhiEncryptorGetRootCAList, 0x323, url);
        return 0;
    }
    certInfoToReturn = func_02184208(gGhttpRootCaTable, pos);
    return certInfoToReturn->caList;
}
