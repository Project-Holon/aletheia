/*
 * function: DWC_Http_Add_HeaderItem
 * address:  0x02179E60
 * packet:   pkt_ov009_02179E60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_Add_HeaderItem (dwc_http.o)
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   DWCi_Http_ReallocBuffer  0x0217A15C  arm  ov009
 *   strstr  0x02094B20  arm
 *   memmove  0x02092364  arm
 *   OS_SNPrintf  0x02084F80  arm
 *   gDwcHttpHeaderFmt     0x021A267C  data
 *   gDwcHttpHeaderTerminator     0x021A25D4  data
 */

typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;
extern char gDwcHttpHeaderFmt[];
extern char gDwcHttpHeaderTerminator[];
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int DWCi_Http_ReallocBuffer(char *http, Buf *buf, int size);
extern char *strstr(const char *s, const char *sub);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

int DWC_Http_Add_HeaderItem(char *http, char *label, char *data)
{
    Buf *temp_buffer;
    int buf_remain;
    int result_len;
    char temp;
    char *temp_index;

    temp_buffer = (Buf *)(http + 0x1a34);
    result_len = strlen((const u8 *)data) +
                 (strlen((const u8 *)gDwcHttpHeaderFmt) - 4 + strlen((const u8 *)label));
    buf_remain = temp_buffer->end - temp_buffer->cur;
    if (result_len + 1 > buf_remain) {
        if (DWCi_Http_ReallocBuffer(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
    }
    temp_index = strstr(temp_buffer->base, gDwcHttpHeaderTerminator) + 2;
    temp = *temp_index;
    memmove(temp_index + result_len, temp_index, strlen((const u8 *)temp_index) + 1);
    temp_index[OS_SNPrintf(temp_index, result_len + 1, gDwcHttpHeaderFmt, label, data)] = temp;
    temp_buffer->cur += result_len;
    return 0;
}
