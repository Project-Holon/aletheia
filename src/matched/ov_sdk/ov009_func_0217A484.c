/*
 * function: DWC_Http_ParseResult
 * address:  0x0217A484
 * packet:   pkt_ov009_0217A484
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_ParseResult (libdwcauth.TWL.HYB.a dwc_http.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   strstr  0x02094B20  arm
 *   strlen  0x0209477C  arm
 *   DWCi_Http_AddResult  0x0217A344  arm  ov009
 *   strncmp  0x020949F4  arm
 *   gDwcHttpHeaderTerminator     0x021A25D4  data ov009
 *   gDwcHttpSpace     0x021A26B4  data ov009
 *   gDwcHttpLabelHttpResult     0x021A26B8  data ov009
 *   gDwcHttpStatusOk     0x021A26C4  data ov009
 *   gDwcHttpCrLf     0x021A2604  data ov009
 *   gDwcHttpColonSpace     0x021A26C8  data ov009
 *   gDwcHttpEquals     0x021A26CC  data ov009
 *   gDwcHttpAmpersand     0x021A26D0  data ov009
 */

typedef struct DWCHttpBuffer {
    char *buffer;
    char *write_index;
    char *buffer_tail;
    unsigned long length;
} DWCHttpBuffer;

typedef struct DWCHttpLabelValue {
    char *label;
    char *value;
} DWCHttpLabelValue;

typedef struct DWCHttpParseResult {
    DWCHttpLabelValue *entry;
    int len;
    int index;
} DWCHttpParseResult;

typedef struct DWCHttp {
    char pad0[0x1a30];
    int num_postitem;
    DWCHttpBuffer req;
    DWCHttpBuffer rep;
    char content_len_mutex[0x18];
    int content_len;
    int receivedbody_len;
    DWCHttpLabelValue labelvalue[32];
} DWCHttp;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned char *strstr(const unsigned char *s1, const unsigned char *s2);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int DWCi_Http_AddResult(DWCHttp *http, DWCHttpParseResult *result, char *label, char *value);
extern int strncmp(const u8 *s1, const u8 *s2, u32 n);

extern const char gDwcHttpHeaderTerminator[];
extern const char gDwcHttpSpace[];
extern char gDwcHttpLabelHttpResult[];
extern const char gDwcHttpStatusOk[];
extern const char gDwcHttpCrLf[];
extern const char gDwcHttpColonSpace[];
extern const char gDwcHttpEquals[];
extern const char gDwcHttpAmpersand[];

int DWC_Http_ParseResult(DWCHttp *http, int noparsebody)
{
    char *buffer;
    char *p_char1;
    char *p_char2;
    char p_char1_temp;
    char p_char2_temp;
    char *httpbody_top;
    char *httpbody_end;
    char *index;
    char *value;
    char temp;
    DWCHttpParseResult parse_result;

    parse_result.entry = http->labelvalue;
    parse_result.len = 32;
    parse_result.index = 0;
    MI_CpuFill8(http->labelvalue, 0, sizeof(http->labelvalue));

    buffer = http->rep.buffer;
    httpbody_top = (char *)strstr((const unsigned char *)buffer, (const unsigned char *)gDwcHttpHeaderTerminator);
    if (httpbody_top == 0)
        return 0;
    httpbody_end = httpbody_top + 4 + strlen((const u8 *)(httpbody_top + 4));

    p_char1 = (char *)strstr((const unsigned char *)buffer, (const unsigned char *)gDwcHttpSpace);
    if (p_char1 == 0)
        return 0;
    temp = p_char1[4];
    p_char1[4] = 0;
    if (DWCi_Http_AddResult(http, &parse_result, gDwcHttpLabelHttpResult, p_char1 + 1) != 1) {
        p_char1[4] = temp;
        return 0;
    }
    p_char1[4] = temp;

    if (noparsebody == 1 || strncmp((const u8 *)(p_char1 + 1), (const u8 *)gDwcHttpStatusOk, 3) != 0)
        return 1;

    index = (char *)strstr((const unsigned char *)(p_char1 + 5), (const unsigned char *)gDwcHttpCrLf);
    if (index == 0)
        return 0;
    index += 2;

    while (*index != '\r' && *(index + 1) != '\n') {
        p_char1 = (char *)strstr((const unsigned char *)index, (const unsigned char *)gDwcHttpColonSpace);
        if (p_char1 == 0)
            break;
        p_char1_temp = *p_char1;
        value = p_char1 + 2;
        *p_char1 = 0;
        p_char2 = (char *)strstr((const unsigned char *)value, (const unsigned char *)gDwcHttpCrLf);
        if (p_char2 == 0) {
            *p_char1 = p_char1_temp;
            break;
        }
        p_char2_temp = *p_char2;
        *p_char2 = 0;
        if (DWCi_Http_AddResult(http, &parse_result, index, value) != 1) {
            *p_char1 = p_char1_temp;
            *p_char2 = p_char2_temp;
            return 0;
        }
        index = value + strlen((const u8 *)value) + 2;
        *p_char1 = p_char1_temp;
        *p_char2 = p_char2_temp;
    }

    index = httpbody_top + 4;
    while (index < httpbody_end) {
        buffer = (char *)strstr((const unsigned char *)index, (const unsigned char *)gDwcHttpEquals);
        if (buffer == 0)
            break;
        p_char1_temp = *buffer;
        p_char1 = buffer + 1;
        *buffer = 0;
        p_char2 = (char *)strstr((const unsigned char *)p_char1, (const unsigned char *)gDwcHttpAmpersand);
        if (p_char2 == 0)
            p_char2 = (char *)strstr((const unsigned char *)p_char1, (const unsigned char *)gDwcHttpCrLf);
        if (p_char2 != 0) {
            p_char2_temp = *p_char2;
            *p_char2 = 0;
        }
        if (DWCi_Http_AddResult(http, &parse_result, index, p_char1) != 1) {
            *buffer = p_char1_temp;
            if (p_char2 != 0)
                *p_char2 = p_char2_temp;
            return 0;
        }
        index = p_char1 + strlen((const u8 *)p_char1) + 1;
        *buffer = p_char1_temp;
        if (p_char2 != 0)
            *p_char2 = p_char2_temp;
    }
    return 1;
}
