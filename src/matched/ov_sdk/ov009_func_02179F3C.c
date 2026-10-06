/*
 * function: func_02179F3C
 * address:  0x02179F3C
 * packet:   pkt_ov009_02179F3C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_Add_PostBase64Item (libdwcauth.TWL.HYB.a dwc_http.o)
 *
 * symbols:
 *   func_02059B40  0x02059B40  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217A15C  0x0217A15C  arm  ov009
 *   func_02084F80  0x02084F80  arm
 *   g_021A2688     0x021A2688  data ov009
 *   g_021A268C     0x021A268C  data ov009
 */

typedef struct DWCHttpBuffer {
    char *buffer;
    char *write_index;
    char *buffer_tail;
    unsigned long length;
} DWCHttpBuffer;

typedef struct DWCHttp {
    char pad0[0x1a30];
    int num_postitem;
    DWCHttpBuffer req;
    DWCHttpBuffer rep;
} DWCHttp;

extern int func_02059B40(const char *src, unsigned long srclen, char *dst, unsigned long dstlen);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern int func_0217A15C(DWCHttp *http, DWCHttpBuffer *buf, int size);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);

extern const char g_021A2688[];
extern const char g_021A268C[];

int func_02179F3C(DWCHttp *http, char *label, char *data, unsigned long data_len)
{
    int result_len;
    int result_base64;
    int buf_remain;
    DWCHttpBuffer *temp_buffer;
    const char *format;

    temp_buffer = &http->req;
    if (http->num_postitem == 0)
        format = g_021A2688;
    else
        format = g_021A268C;

    http->num_postitem++;

    result_base64 = func_02059B40(data, data_len, 0, 0);
    result_len = result_base64 + (func_0209477C((const u8 *)format) - 2 + func_0209477C((const u8 *)label));
    buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    if (result_len > buf_remain) {
        if (!func_0217A15C(http, temp_buffer, result_len - buf_remain + 1))
            return 1;
        buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    }

    result_len = func_02084F80(temp_buffer->write_index, buf_remain, format, label);
    temp_buffer->write_index += result_len;

    result_len = func_02059B40(data, data_len, temp_buffer->write_index,
                               temp_buffer->buffer_tail - temp_buffer->write_index - 1);
    if (result_len < 0)
        return 1;
    temp_buffer->write_index += result_base64;
    *temp_buffer->write_index = 0;
    return 0;
}
