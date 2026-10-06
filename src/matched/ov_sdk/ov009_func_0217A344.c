/*
 * function: func_0217A344
 * address:  0x0217A344
 * packet:   pkt_ov009_0217A344
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_AddResult (libdwcauth.TWL.HYB.a dwc_http.o)
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_02094798  0x02094798  arm
 */

typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct DWCHttp {
    unsigned char stack[0x1000];
    unsigned char initflag;
    DWCHttpParam param;
} DWCHttp;

typedef struct DWCHttpLabelValue {
    char *label;
    char *value;
} DWCHttpLabelValue;

typedef struct DWCHttpParseResult {
    DWCHttpLabelValue *entry;
    int len;
    int index;
} DWCHttpParseResult;

typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern char *func_02094798(char *dst, const char *src);

int func_0217A344(DWCHttp *http, DWCHttpParseResult *result, char *label, char *value)
{
    void *(*alloc)(unsigned long, long) = http->param.alloc;
    void (*free)(unsigned long, void *, long) = http->param.free;

    if (result->index > result->len)
        return 0;

    result->entry[result->index].label = alloc(0, func_0209477C((const u8 *)label) + 1);
    if (result->entry[result->index].label != 0) {
        result->entry[result->index].value = alloc(0, func_0209477C((const u8 *)value) + 1);
        if (result->entry[result->index].value != 0) {
            func_02094798(result->entry[result->index].label, label);
            func_02094798(result->entry[result->index].value, value);
            result->index++;
            return 1;
        }
    }

    if (result->entry[result->index].label != 0) {
        free(0, result->entry[result->index].label, 0);
        result->entry[result->index].label = 0;
    }
    if (result->entry[result->index].value != 0) {
        free(0, result->entry[result->index].value, 0);
        result->entry[result->index].value = 0;
    }
    return 0;
}
