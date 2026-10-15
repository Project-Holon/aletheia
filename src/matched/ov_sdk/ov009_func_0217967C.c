/*
 * function: DWC_Http_FinishHeader
 * address:  0x0217967C
 * packet:   pkt_ov009_0217967C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_FinishHeader (dwc_http.o)
 *
 * symbols:
 *   DWC_Http_Add_HeaderItem  0x02179E60  arm  ov009
 *   strstr  0x02094B20  arm
 *   strlen  0x0209477C  arm
 *   OS_SNPrintf  0x02084F80  arm
 *   gDwcHttpHeaderConnection     0x021A25C0  data
 *   gDwcHttpHeaderConnectionClose     0x021A25CC  data
 *   gDwcHttpHeaderTerminator     0x021A25D4  data
 *   gDwcHttpContentLengthFmt     0x021A25DC  data
 *   gDwcHttpHeaderContentLength     0x021A25E0  data
 */

extern char gDwcHttpHeaderConnection[];
extern char gDwcHttpHeaderConnectionClose[];
extern char gDwcHttpHeaderTerminator[];
extern char gDwcHttpContentLengthFmt[];
extern char gDwcHttpHeaderContentLength[];
extern int DWC_Http_Add_HeaderItem(char *http, char *label, char *data);
typedef unsigned char  u8;
extern u8 *strstr(const u8 *s1, const u8 *s2);
extern int strlen(const u8 *s);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

int DWC_Http_FinishHeader(char *http)
{
    char str_contentlen[8];
    int contentlen;

    if (DWC_Http_Add_HeaderItem(http, gDwcHttpHeaderConnection, gDwcHttpHeaderConnectionClose)) {
        return 1;
    }
    contentlen = strlen(strstr((const u8 *)(*(char **)(http + 0x1a34)), (const u8 *)gDwcHttpHeaderTerminator) + 4);
    if (contentlen != 0) {
        OS_SNPrintf(str_contentlen, 7, gDwcHttpContentLengthFmt, contentlen);
        if (DWC_Http_Add_HeaderItem(http, gDwcHttpHeaderContentLength, str_contentlen)) {
            return 1;
        }
    }
    return 0;
}
