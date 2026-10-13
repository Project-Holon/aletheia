/*
 * function: NHTTPi_getHeaderValue
 * address:  0x021BBBC8
 * packet:   pkt_ov114_021BBBC8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes: EXACT. `volatile int len` forces the per-iteration len reload (image reloads len for the valueend call after the compare); `const Res *res_p` (and on the callee prototypes) schedules the len load before the stack-argument store, matching the image. Levers: a-re-read-loop-bound-is-a-volatile-field and a-const-source-pointer-pulls-field-loads-up-next-to-the-call-result.
 *
 * sdk:      NHTTPi_getHeaderValue (libnhttp.TWL.HYB.a nhttp_response.o)
 *
 * symbols:
 *   NHTTPi_findNextLineHdrRecvBuf  0x021BAFA0  arm    ov114
 *   NHTTPi_compareTokenN_HdrRecvBuf  0x021BB12C  arm    ov114
 *   NHTTPi_skipSpaceHdrRecvBuf  0x021BB0BC  arm    ov114
 */

typedef struct {
    volatile int len;
} Res;

extern int NHTTPi_findNextLineHdrRecvBuf(const Res *res, int pos, int limit, int *colon, int *rcsize);
extern int NHTTPi_compareTokenN_HdrRecvBuf(const Res *res, int pos, int limit, char *str, char extdeli);
extern int NHTTPi_skipSpaceHdrRecvBuf(const Res *res, int pos, int limit);

int NHTTPi_getHeaderValue(const Res *res_p, char *label_p, int *pos_p)
{
    int linetop;
    int nextlinetop;
    int labelend;
    int valuetop;
    int valueend;
    int return_code_size;

    return_code_size = 0;
    linetop = NHTTPi_findNextLineHdrRecvBuf(res_p, 12, res_p->len, &labelend, &return_code_size);
    while (linetop > 0) {
        valueend = 0;
        nextlinetop = NHTTPi_findNextLineHdrRecvBuf(res_p, linetop, res_p->len, &labelend, &return_code_size);
        if (labelend > 0 && NHTTPi_compareTokenN_HdrRecvBuf(res_p, linetop, labelend, label_p, 0) == 0) {
            if (labelend + 1 < res_p->len) {
                valueend = NHTTPi_findNextLineHdrRecvBuf(res_p, labelend + 1, res_p->len, 0, &return_code_size);
                if (valueend <= 0) {
                    valueend = res_p->len;
                } else {
                    if (valueend < return_code_size)
                        return -1;
                    valueend = valueend - return_code_size;
                }
                valuetop = NHTTPi_skipSpaceHdrRecvBuf(res_p, labelend + 1, valueend);
                if (valuetop < 0)
                    valuetop = valueend;
                *pos_p = valuetop;
                return valueend - valuetop;
            }
            return valueend;
        }
        linetop = nextlinetop;
    }
    return -1;
}
