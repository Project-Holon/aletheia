/*
 * function: func_02179E60
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
 *   func_0209477C  0x0209477C  arm
 *   func_0217A15C  0x0217A15C  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_02092364  0x02092364  arm
 *   OS_SNPrintf  0x02084F80  arm
 *   g_021A267C     0x021A267C  data
 *   g_021A25D4     0x021A25D4  data
 */

typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;
extern char g_021A267C[];
extern char g_021A25D4[];
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern int func_0217A15C(char *http, Buf *buf, int size);
extern char *func_02094B20(const char *s, const char *sub);
extern void *func_02092364(void *dst, const void *src, unsigned long n);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

int func_02179E60(char *http, char *label, char *data)
{
    Buf *temp_buffer;
    int buf_remain;
    int result_len;
    char temp;
    char *temp_index;

    temp_buffer = (Buf *)(http + 0x1a34);
    result_len = func_0209477C((const u8 *)data) +
                 (func_0209477C((const u8 *)g_021A267C) - 4 + func_0209477C((const u8 *)label));
    buf_remain = temp_buffer->end - temp_buffer->cur;
    if (result_len + 1 > buf_remain) {
        if (func_0217A15C(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
    }
    temp_index = func_02094B20(temp_buffer->base, g_021A25D4) + 2;
    temp = *temp_index;
    func_02092364(temp_index + result_len, temp_index, func_0209477C((const u8 *)temp_index) + 1);
    temp_index[OS_SNPrintf(temp_index, result_len + 1, g_021A267C, label, data)] = temp;
    temp_buffer->cur += result_len;
    return 0;
}
