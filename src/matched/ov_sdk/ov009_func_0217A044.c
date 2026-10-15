/*
 * function: DWC_Http_Add_Body
 * address:  0x0217A044
 * packet:   pkt_ov009_0217A044
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_Add_Body (dwc_http.o)
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   DWCi_Http_ReallocBuffer  0x0217A15C  arm  ov009
 *   OS_SNPrintf  0x02084F80  arm
 *   g_021A2694     0x021A2694  data
 */

typedef struct {
    int unk0;
    char *cur;
    char *end;
} Buf;
extern char g_021A2694[];
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int DWCi_Http_ReallocBuffer(char *http, Buf *buf, int size);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

int DWC_Http_Add_Body(char *http, char *data)
{
    int result_len;
    int buf_remain;
    int temp;
    Buf *temp_buffer;

    temp_buffer = (Buf *)(http + 0x1a34);
    result_len = strlen((const u8 *)data);
    buf_remain = temp_buffer->end - temp_buffer->cur;
    if (result_len > buf_remain) {
        if (DWCi_Http_ReallocBuffer(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
        buf_remain = temp_buffer->end - temp_buffer->cur;
    }
    temp = OS_SNPrintf(temp_buffer->cur, buf_remain, g_021A2694, data);
    if (temp != result_len) {
        return 1;
    }
    temp_buffer->cur += temp;
    return 0;
}
