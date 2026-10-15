/*
 * function: DWCi_Http_WriteBasicHeader
 * address:  0x02179DA0
 * packet:   pkt_ov009_02179DA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_WriteBasicHeader (dwc_http.o)
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   func_0217A0D4  0x0217A0D4  arm  ov009
 *   OS_SNPrintf  0x02084F80  arm
 *   g_021A2608     0x021A2608  data
 *   g_021A265C     0x021A265C  data
 */

typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;
extern char g_021A2608[];
extern char g_021A265C[];
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int func_0217A0D4(char *http, Buf *buf, unsigned long size);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

int DWCi_Http_WriteBasicHeader(char *http)
{
    char *format;
    Buf *req;
    int result_len;

    req = (Buf *)(http + 0x1a34);
    if (*(int *)(http + 0x1008) == 0) {
        format = g_021A2608;
    } else {
        format = g_021A265C;
    }
    result_len = strlen((const u8 *)(*(char **)(http + 0x1124))) +
                 (strlen((const u8 *)format) - 4 + strlen((const u8 *)(*(char **)(http + 0x1128))));
    if (func_0217A0D4(http, (Buf *)(http + 0x1a34), result_len + 0x400) != 1) {
        return 1;
    }
    result_len = OS_SNPrintf(req->cur, req->cap, format, *(char **)(http + 0x1128), *(char **)(http + 0x1124));
    req->cur += result_len;
    return 0;
}
