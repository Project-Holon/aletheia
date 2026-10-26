/*
 * file:     nhttp_response.c
 * unit:     yes
 * function: NHTTPi_DestroyResponse, NHTTPi_getHeaderValue, NHTTP_GetResponseHeaderField, NHTTPi_GetResponseHeaderAll, NHTTPi_InitThreadInfo
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
 * Tail-call thunk to the unnamed ARM setter at 0x021BBEAC.
 *
 * symbols:
 *   NHTTPi_free                     0x021ba850 arm
 *   NHTTPi_Response2Connection      0x021bebf0 arm
 *   NHTTPi_findNextLineHdrRecvBuf  0x021BAFA0  arm    ov114
 *   NHTTPi_compareTokenN_HdrRecvBuf  0x021BB12C  arm    ov114
 *   NHTTPi_skipSpaceHdrRecvBuf  0x021BB0BC  arm    ov114
 *   NHTTPi_free 0x021BA850 arm ov114
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_loadFromHdrRecvBuf 0x021BB210 arm ov114
 *   NHTTPi_strcmp 0x021BA130 arm ov114
 *   sNHTTPStatusCodeLabel 0x021CE414 data
 *   NHTTPi_SetError 0x021BA874 arm ov114
 *   NHTTPi_IsCreateCommThreadMessageQueueOff  0x021BBEAC  arm  ov114
 */
#include "nhttp_recvbuf.h"
#include "nhttp_types.h"

#include "nhttp_bgnend.h"
#include "d_nhttp_common.h"
#include "nhttp_stdlib_ntr.h"
#include "nhttp_thread.h"
void NHTTPi_DestroyResponse(NHTTPMutexInfo *mutexInfo_p, NHTTPRes *res_p);
int NHTTPi_getHeaderValue(const NHTTPRes *res_p, char *label_p, int *pos_p);
int NHTTP_GetResponseHeaderField(NHTTPRes *res_p, char *label_p, char **value_pp);
int NHTTPi_GetResponseHeaderAll(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPRes *res_p, char **value_pp);
void NHTTPi_InitThreadInfo(NHTTPThreadInfo *threadInfo_p);
extern char sNHTTPStatusCodeLabel[];



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
int NHTTPi_getHeaderValue(const NHTTPRes *res_p, char *label_p, int *pos_p)
{
    int linetop;
    int nextlinetop;
    int labelend;
    int valuetop;
    int valueend;
    int return_code_size;

    return_code_size = 0;
    linetop = NHTTPi_findNextLineHdrRecvBuf(res_p, 12, res_p->headerLen, &labelend, &return_code_size);
    while (linetop > 0) {
        valueend = 0;
        nextlinetop = NHTTPi_findNextLineHdrRecvBuf(res_p, linetop, res_p->headerLen, &labelend, &return_code_size);
        if (labelend > 0 && NHTTPi_compareTokenN_HdrRecvBuf(res_p, linetop, labelend, label_p, 0) == 0) {
            if (labelend + 1 < res_p->headerLen) {
                valueend = NHTTPi_findNextLineHdrRecvBuf(res_p, labelend + 1, res_p->headerLen, 0, &return_code_size);
                if (valueend <= 0) {
                    valueend = res_p->headerLen;
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



int NHTTP_GetResponseHeaderField(NHTTPRes *res_p, char *label_p, char **value_pp)
{
    int pos;
    int size;

    if (res_p->isHeaderParse == 0) {
        return -1;
    }
    if (res_p->foundHeader_p) {
        NHTTPi_free(res_p->foundHeader_p);
        res_p->foundHeader_p = 0;
    }
    size = NHTTPi_getHeaderValue(res_p, label_p, (int *)&pos);
    if (size >= 0) {
        res_p->foundHeader_p = NHTTPi_alloc(size + 1, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[size] = 0;
        NHTTPi_loadFromHdrRecvBuf(res_p, res_p->foundHeader_p, pos, size);
        *value_pp = res_p->foundHeader_p;
        return size;
    }
    if (NHTTPi_strcmp(sNHTTPStatusCodeLabel, label_p) == 0) {
        res_p->foundHeader_p = NHTTPi_alloc(4, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[3] = 0;
        size = 3;
        NHTTPi_loadFromHdrRecvBuf(res_p, res_p->foundHeader_p, 9, size);
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
int NHTTPi_GetResponseHeaderAll(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPRes *res_p, char **value_pp)
{
    if (res_p->isHeaderParse == 0 || res_p->headerLen == 0) {
        return -1;
    }
    if (res_p->headerLen < 0x400) {
        *value_pp = res_p->hdrBufFirst;
    } else {
        if (res_p->allHeader_p == 0) {
            res_p->allHeader_p = NHTTPi_alloc(res_p->headerLen, 4);
            if (res_p->allHeader_p == 0) {
                NHTTPi_SetError(bgnEndInfo_p, 1);
                return -1;
            }
            NHTTPi_loadFromHdrRecvBuf(res_p, res_p->allHeader_p, 0, res_p->headerLen);
        }
        *value_pp = res_p->allHeader_p;
    }
    return res_p->headerLen;
}


void NHTTPi_InitThreadInfo(NHTTPThreadInfo *threadInfo_p)
{
    NHTTPi_IsCreateCommThreadMessageQueueOff(threadInfo_p);
}
