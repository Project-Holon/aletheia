/*
 * function: DWC_Http_Add_PostBase64Item
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
 *   DWC_Base64Encode  0x02059B40  arm
 *   strlen  0x0209477C  arm
 *   DWCi_Http_ReallocBuffer  0x0217A15C  arm  ov009
 *   OS_SNPrintf  0x02084F80  arm
 *   gDwcHttpParamFmt     0x021A2688  data ov009
 *   gDwcHttpParamAmpFmt     0x021A268C  data ov009
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

extern int DWC_Base64Encode(const char *src, unsigned long srclen, char *dst, unsigned long dstlen);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int DWCi_Http_ReallocBuffer(DWCHttp *http, DWCHttpBuffer *buf, int size);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

extern const char gDwcHttpParamFmt[];
extern const char gDwcHttpParamAmpFmt[];

int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len)
{
    int result_len;
    int result_base64;
    int buf_remain;
    DWCHttpBuffer *temp_buffer;
    const char *format;

    temp_buffer = &http->req;
    if (http->num_postitem == 0)
        format = gDwcHttpParamFmt;
    else
        format = gDwcHttpParamAmpFmt;

    http->num_postitem++;

    result_base64 = DWC_Base64Encode(data, data_len, 0, 0);
    result_len = result_base64 + (strlen((const u8 *)format) - 2 + strlen((const u8 *)label));
    buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    if (result_len > buf_remain) {
        if (!DWCi_Http_ReallocBuffer(http, temp_buffer, result_len - buf_remain + 1))
            return 1;
        buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    }

    result_len = OS_SNPrintf(temp_buffer->write_index, buf_remain, format, label);
    temp_buffer->write_index += result_len;

    result_len = DWC_Base64Encode(data, data_len, temp_buffer->write_index,
                               temp_buffer->buffer_tail - temp_buffer->write_index - 1);
    if (result_len < 0)
        return 1;
    temp_buffer->write_index += result_base64;
    *temp_buffer->write_index = 0;
    return 0;
}
