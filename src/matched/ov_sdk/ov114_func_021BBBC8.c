/*
 * function: func_021BBBC8
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
 *   func_021BAFA0  0x021BAFA0  arm    ov114
 *   func_021BB12C  0x021BB12C  arm    ov114
 *   func_021BB0BC  0x021BB0BC  arm    ov114
 */

typedef struct {
    volatile int len;
} Res;

extern int func_021BAFA0(const Res *res, int pos, int limit, int *colon, int *rcsize);
extern int func_021BB12C(const Res *res, int pos, int limit, char *str, char extdeli);
extern int func_021BB0BC(const Res *res, int pos, int limit);

int func_021BBBC8(const Res *res_p, char *label_p, int *pos_p)
{
    int linetop;
    int nextlinetop;
    int labelend;
    int valuetop;
    int valueend;
    int return_code_size;

    return_code_size = 0;
    linetop = func_021BAFA0(res_p, 12, res_p->len, &labelend, &return_code_size);
    while (linetop > 0) {
        valueend = 0;
        nextlinetop = func_021BAFA0(res_p, linetop, res_p->len, &labelend, &return_code_size);
        if (labelend > 0 && func_021BB12C(res_p, linetop, labelend, label_p, 0) == 0) {
            if (labelend + 1 < res_p->len) {
                valueend = func_021BAFA0(res_p, labelend + 1, res_p->len, 0, &return_code_size);
                if (valueend <= 0) {
                    valueend = res_p->len;
                } else {
                    if (valueend < return_code_size)
                        return -1;
                    valueend = valueend - return_code_size;
                }
                valuetop = func_021BB0BC(res_p, labelend + 1, valueend);
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
