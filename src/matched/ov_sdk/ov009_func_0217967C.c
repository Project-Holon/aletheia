/*
 * function: func_0217967C
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
 *   func_02179E60  0x02179E60  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_0209477C  0x0209477C  arm
 *   func_02084F80  0x02084F80  arm
 *   g_021A25C0     0x021A25C0  data
 *   g_021A25CC     0x021A25CC  data
 *   g_021A25D4     0x021A25D4  data
 *   g_021A25DC     0x021A25DC  data
 *   g_021A25E0     0x021A25E0  data
 */

extern char g_021A25C0[];
extern char g_021A25CC[];
extern char g_021A25D4[];
extern char g_021A25DC[];
extern char g_021A25E0[];
extern int func_02179E60(char *http, char *label, char *data);
typedef unsigned char  u8;
extern u8 *func_02094B20(const u8 *s1, const u8 *s2);
extern int func_0209477C(const u8 *s);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);

int func_0217967C(char *http)
{
    char str_contentlen[8];
    int contentlen;

    if (func_02179E60(http, g_021A25C0, g_021A25CC)) {
        return 1;
    }
    contentlen = func_0209477C(func_02094B20((const u8 *)(*(char **)(http + 0x1a34)), (const u8 *)g_021A25D4) + 4);
    if (contentlen != 0) {
        func_02084F80(str_contentlen, 7, g_021A25DC, contentlen);
        if (func_02179E60(http, g_021A25E0, str_contentlen)) {
            return 1;
        }
    }
    return 0;
}
