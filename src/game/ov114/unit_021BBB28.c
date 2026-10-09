/*
 * file:     unit_021BBB28.c
 * unit:     yes
 * function: func_021BBB28, func_021BBBC8, func_021BBCF0, func_021BBDFC
 * address:  0x021BBB28
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NHTTPi_free                     0x021ba850 arm
 *   NHTTPi_Response2Connection      0x021bebf0 arm
 *   func_021BAFA0  0x021BAFA0  arm    ov114
 *   func_021BB12C  0x021BB12C  arm    ov114
 *   func_021BB0BC  0x021BB0BC  arm    ov114
 *   func_021BA850 0x021BA850 arm ov114
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BB210 0x021BB210 arm ov114
 *   func_021BA130 0x021BA130 arm ov114
 *   g_021CE414 0x021CE414 data
 *   func_021BA874 0x021BA874 arm ov114
 */
#include "nhttp_types.h"


extern void NHTTPi_free(void *);
extern NHTTPConnection *NHTTPi_Response2Connection(NHTTPMutexInfo *, NHTTPRes *);
extern int func_021BAFA0(const NHTTPRes *res, int pos, int limit, int *colon, int *rcsize);
extern int func_021BB12C(const NHTTPRes *res, int pos, int limit, char *str, char extdeli);
extern int func_021BB0BC(const NHTTPRes *res, int pos, int limit);
extern void func_021BA850(int a);
extern int func_021BA820(int a, int b);
extern int func_021BB210(NHTTPRes *res_p, char *buf, int pos, int size);
extern int func_021BA130(char *a, char *b);
extern void func_021BA874(u8 *p, int v);
void NHTTPi_DestroyResponse(NHTTPMutexInfo *mutexInfo_p, NHTTPRes *res_p);
int func_021BBBC8(const NHTTPRes *res_p, char *label_p, int *pos_p);
int func_021BBCF0(NHTTPRes *res_p, char *label_p, char **value_pp);
int func_021BBDFC(void *bgnEndInfo_p, NHTTPRes *res_p, char **value_pp);
extern char g_021CE414[];


void NHTTPi_DestroyResponse(NHTTPMutexInfo *mutexInfo_p, NHTTPRes *res_p)
{
    NHTTPi_HDRBUFLIST *list_p = res_p->hdrBufBlock_p;
    NHTTPConnection *connection_p;

    while (list_p != 0) {
        NHTTPi_HDRBUFLIST *next = list_p->next_p;
        NHTTPi_free(list_p);
        list_p = next;
        res_p->hdrBufBlock_p = list_p;
    }
    if (res_p->allHeader_p != 0)
        NHTTPi_free(res_p->allHeader_p);
    if (res_p->foundHeader_p != 0)
        NHTTPi_free(res_p->foundHeader_p);
    if (res_p->freeBuf != 0) {
        res_p->freeBuf(res_p->recvBuf_p, (void *)NHTTPi_free, res_p->param_p);
        res_p->recvBuf_p = 0;
        res_p->recvBufLen = 0;
    }
    connection_p = NHTTPi_Response2Connection(mutexInfo_p, res_p);
    if (connection_p != 0)
        connection_p->res_p = 0;
    NHTTPi_free(res_p);
}


/*
 * notes: EXACT. `volatile int len` forces the per-iteration len reload (image reloads len for the valueend call after the compare); `const NHTTPRes *res_p` (and on the callee prototypes) schedules the len load before the stack-argument store, matching the image. Levers: a-re-read-loop-bound-is-a-volatile-field and a-const-source-pointer-pulls-field-loads-up-next-to-the-call-result.
 *
 * sdk:      NHTTPi_getHeaderValue (libnhttp.TWL.HYB.a nhttp_response.o)
 */
int func_021BBBC8(const NHTTPRes *res_p, char *label_p, int *pos_p)
{
    int linetop;
    int nextlinetop;
    int labelend;
    int valuetop;
    int valueend;
    int return_code_size;

    return_code_size = 0;
    linetop = func_021BAFA0((const NHTTPRes *)res_p, 12, res_p->headerLen, &labelend, &return_code_size);
    while (linetop > 0) {
        valueend = 0;
        nextlinetop = func_021BAFA0((const NHTTPRes *)res_p, linetop, res_p->headerLen, &labelend, &return_code_size);
        if (labelend > 0 && func_021BB12C((const NHTTPRes *)res_p, linetop, labelend, label_p, 0) == 0) {
            if (labelend + 1 < res_p->headerLen) {
                valueend = func_021BAFA0((const NHTTPRes *)res_p, labelend + 1, res_p->headerLen, 0, &return_code_size);
                if (valueend <= 0) {
                    valueend = res_p->headerLen;
                } else {
                    if (valueend < return_code_size)
                        return -1;
                    valueend = valueend - return_code_size;
                }
                valuetop = func_021BB0BC((const NHTTPRes *)res_p, labelend + 1, valueend);
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


int func_021BBCF0(NHTTPRes *res_p, char *label_p, char **value_pp)
{
    int pos;
    int size;

    if (res_p->isHeaderParse == 0) {
        return -1;
    }
    if (res_p->foundHeader_p) {
        func_021BA850((int)res_p->foundHeader_p);
        res_p->foundHeader_p = 0;
    }
    size = func_021BBBC8((const NHTTPRes *)res_p, label_p, &pos);
    if (size >= 0) {
        res_p->foundHeader_p = (char *)func_021BA820(size + 1, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[size] = 0;
        func_021BB210((NHTTPRes *)res_p, res_p->foundHeader_p, pos, size);
        *value_pp = res_p->foundHeader_p;
        return size;
    }
    if (func_021BA130(g_021CE414, label_p) == 0) {
        res_p->foundHeader_p = (char *)func_021BA820(4, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[3] = 0;
        size = 3;
        func_021BB210((NHTTPRes *)res_p, res_p->foundHeader_p, 9, size);
        *value_pp = res_p->foundHeader_p;
        return size;
    }
    return -1;
}


/*
 * sdk:      NHTTPi_GetResponseHeaderAll (libnhttp.TWL.HYB.a(nhttp_response.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
int func_021BBDFC(void *bgnEndInfo_p, NHTTPRes *res_p, char **value_pp)
{
    if (res_p->isHeaderParse == 0 || res_p->headerLen == 0) {
        return -1;
    }
    if (res_p->headerLen < 0x400) {
        *value_pp = res_p->hdrBufFirst;
    } else {
        if (res_p->allHeader_p == 0) {
            res_p->allHeader_p = (char *)func_021BA820(res_p->headerLen, 4);
            if (res_p->allHeader_p == 0) {
                func_021BA874(bgnEndInfo_p, 1);
                return -1;
            }
            func_021BB210((NHTTPRes *)res_p, res_p->allHeader_p, 0, res_p->headerLen);
        }
        *value_pp = res_p->allHeader_p;
    }
    return res_p->headerLen;
}
