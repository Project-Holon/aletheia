/*
 * function: func_0217A484
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02094B20  0x02094B20  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217A344  0x0217A344  arm  ov009
 *   func_020949F4  0x020949F4  arm
 *   g_021A25D4     0x021A25D4  data ov009
 *   g_021A26B4     0x021A26B4  data ov009
 *   g_021A26B8     0x021A26B8  data ov009
 *   g_021A26C4     0x021A26C4  data ov009
 *   g_021A2604     0x021A2604  data ov009
 *   g_021A26C8     0x021A26C8  data ov009
 *   g_021A26CC     0x021A26CC  data ov009
 *   g_021A26D0     0x021A26D0  data ov009
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

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern char *func_02094B20(const char *s, const char *find);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern int func_0217A344(DWCHttp *http, DWCHttpParseResult *result, char *label, char *value);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);

extern const char g_021A25D4[];
extern const char g_021A26B4[];
extern char g_021A26B8[];
extern const char g_021A26C4[];
extern const char g_021A2604[];
extern const char g_021A26C8[];
extern const char g_021A26CC[];
extern const char g_021A26D0[];

int func_0217A484(DWCHttp *http, int noparsebody)
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
    func_02082BCC(http->labelvalue, 0, sizeof(http->labelvalue));

    buffer = http->rep.buffer;
    httpbody_top = func_02094B20(buffer, g_021A25D4);
    if (httpbody_top == 0)
        return 0;
    httpbody_end = httpbody_top + 4 + func_0209477C((const u8 *)(httpbody_top + 4));

    p_char1 = func_02094B20(buffer, g_021A26B4);
    if (p_char1 == 0)
        return 0;
    temp = p_char1[4];
    p_char1[4] = 0;
    if (func_0217A344(http, &parse_result, g_021A26B8, p_char1 + 1) != 1) {
        p_char1[4] = temp;
        return 0;
    }
    p_char1[4] = temp;

    if (noparsebody == 1 || func_020949F4((const u8 *)(p_char1 + 1), (const u8 *)g_021A26C4, 3) != 0)
        return 1;

    index = func_02094B20(p_char1 + 5, g_021A2604);
    if (index == 0)
        return 0;
    index += 2;

    while (*index != '\r' && *(index + 1) != '\n') {
        p_char1 = func_02094B20(index, g_021A26C8);
        if (p_char1 == 0)
            break;
        p_char1_temp = *p_char1;
        value = p_char1 + 2;
        *p_char1 = 0;
        p_char2 = func_02094B20(value, g_021A2604);
        if (p_char2 == 0) {
            *p_char1 = p_char1_temp;
            break;
        }
        p_char2_temp = *p_char2;
        *p_char2 = 0;
        if (func_0217A344(http, &parse_result, index, value) != 1) {
            *p_char1 = p_char1_temp;
            *p_char2 = p_char2_temp;
            return 0;
        }
        index = value + func_0209477C((const u8 *)value) + 2;
        *p_char1 = p_char1_temp;
        *p_char2 = p_char2_temp;
    }

    index = httpbody_top + 4;
    while (index < httpbody_end) {
        buffer = func_02094B20(index, g_021A26CC);
        if (buffer == 0)
            break;
        p_char1_temp = *buffer;
        p_char1 = buffer + 1;
        *buffer = 0;
        p_char2 = func_02094B20(p_char1, g_021A26D0);
        if (p_char2 == 0)
            p_char2 = func_02094B20(p_char1, g_021A2604);
        if (p_char2 != 0) {
            p_char2_temp = *p_char2;
            *p_char2 = 0;
        }
        if (func_0217A344(http, &parse_result, index, p_char1) != 1) {
            *buffer = p_char1_temp;
            if (p_char2 != 0)
                *p_char2 = p_char2_temp;
            return 0;
        }
        index = p_char1 + func_0209477C((const u8 *)p_char1) + 1;
        *buffer = p_char1_temp;
        if (p_char2 != 0)
            *p_char2 = p_char2_temp;
    }
    return 1;
}
