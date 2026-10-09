/*
 * file:     unit_021BAED4.c
 * unit:     yes
 * function: func_021BAED4, func_021BAF2C, func_021BAFA0, func_021BB0BC, func_021BB12C, func_021BB210, func_021BB2FC, func_021BB310, func_021BB344
 * address:  0x021BAED4
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
 *   func_021BAED4 0x021BAED4 arm ov114
 *   func_021BAF2C 0x021BAF2C arm ov114
 *   func_021BA100 0x021BA100 arm ov114
 *   NHTTPi_SocRecv                   0x021b9f94 arm
 *   NHTTPi_isRecvBufFull             0x021bb2fc arm
 */
#include "nhttp_types.h"
#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))


typedef struct _Res Res_021BB12C;


extern void func_021BAED4(NHTTPRes *res_p, int pos, void *hdrbuf_pp, int *blockpos_p);
extern char func_021BAF2C(NHTTPRes *res_p, void *hdrbuf_pp, int *blockpos_p);
extern void func_021BA100(void *dst_p, void *src_p, int size);
extern int NHTTPi_SocRecv(NHTTPMutexInfo *mutexInfo_p,
        NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int NHTTPi_isRecvBufFull(NHTTPRes *res_p, int pos);
int func_021BAFA0(NHTTPRes *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p);
int NHTTPi_skipSpaceHdrRecvBuf(NHTTPRes *res_p, int pos, int limit);
int func_021BB12C(Res_021BB12C *res_p, int pos, int limit, char *str_p, char extdeli);
int func_021BB210(NHTTPRes *res_p, char *dst_p, int pos, int len);
int func_021BB2FC(u8 *p, u32 v);
int NHTTPi_RecvBuf(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, int pos, int flags);
int NHTTPi_RecvBufN(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, int pos, int len, int flags);


static void setupGetcharFromHdrRecvBuf(NHTTPRes *res_p, int pos,
        NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p)
{
    NHTTPi_HDRBUFLIST *a_hdrbuf_p;
    int blockidx;

    if (pos < 0x400) {
        *hdrbuf_pp = 0;
        *blockpos_p = pos;
        return;
    }
    blockidx = (pos - 0x400) >> 9;
    a_hdrbuf_p = res_p->hdrBufBlock_p;
    while (blockidx-- != 0) {
        a_hdrbuf_p = a_hdrbuf_p->next_p;
    }
    *hdrbuf_pp = a_hdrbuf_p;
    *blockpos_p = (pos - 0x400) & 0x1ff;
}


static char getcharFromHdrRecvBuf(const NHTTPRes *res_p,
        NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p)
{
    if (*hdrbuf_pp == 0) {
        if (*blockpos_p < 0x400)
            return res_p->hdrBufFirst[(*blockpos_p)++];
        *blockpos_p = 0;
        *hdrbuf_pp = res_p->hdrBufBlock_p;
    } else {
        if (*blockpos_p == 0x200) {
            *blockpos_p = 0;
            *hdrbuf_pp = (*hdrbuf_pp)->next_p;
        }
    }
    return (*hdrbuf_pp)->block[(*blockpos_p)++];
}


int func_021BAFA0(NHTTPRes *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p)
{
    void *hdrbuf_p;
    int blockpos;
    int findCR;
    int return_pos;
    char c;

    if (colon_pos_p) {
        *colon_pos_p = -1;
    }
    if (pos < limit) {
        return_pos = -1;
        findCR = 0;
        func_021BAED4(res_p, pos, &hdrbuf_p, &blockpos);
        for (; pos < limit; pos++) {
            c = func_021BAF2C(res_p, &hdrbuf_p, &blockpos);
            if (c == ':') {
                if (colon_pos_p && *colon_pos_p < 0) {
                    *colon_pos_p = pos;
                }
            }
            if (findCR) {
                if (c == '\n') {
                    return_pos = 0;
                    if (pos != limit - 1) {
                        return_pos = pos + 1;
                    }
                    if (return_code_size_p) {
                        *return_code_size_p = 2;
                    }
                }
                return return_pos;
            }
            if (c == '\r') {
                return_pos = 0;
                if (pos != limit - 1) {
                    return_pos = pos + 1;
                }
                findCR = 1;
                if (return_code_size_p) {
                    *return_code_size_p = findCR;
                }
            }
            if (c == '\n') {
                if (pos == limit - 1) {
                    return_pos = 0;
                } else {
                    return_pos = pos + 1;
                }
                if (return_code_size_p) {
                    *return_code_size_p = 1;
                }
                return return_pos;
            }
        }
    }
    return -1;
}


int NHTTPi_skipSpaceHdrRecvBuf(NHTTPRes *res_p, int pos, int limit)
{
    NHTTPi_HDRBUFLIST *hdrbuf_p;
    int blockpos;

    if (pos < limit) {
        setupGetcharFromHdrRecvBuf(res_p, pos, &hdrbuf_p, &blockpos);
        while (pos < limit) {
            if (getcharFromHdrRecvBuf(res_p, &hdrbuf_p, &blockpos) != ' ')
                return pos;
            pos++;
        }
    }
    return -1;
}


/*
 * sdk:      NHTTPi_compareTokenN_HdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 */
int func_021BB12C(Res_021BB12C *res_p, int pos, int limit, char *str_p, char extdeli)
{
    char c;
    void *hdrbuf_p;
    int blockpos;

    if (pos < limit) {
        func_021BAED4((NHTTPRes *)res_p, pos, &hdrbuf_p, &blockpos);
        c = func_021BAF2C((NHTTPRes *)res_p, &hdrbuf_p, &blockpos);
        limit--;
        while (NHTTPi_TOLOWER(c) == NHTTPi_TOLOWER(*str_p)) {
            if (*str_p == 0 || *str_p == ' ' || *str_p == extdeli || pos == limit) {
                return 0;
            }
            c = func_021BAF2C((NHTTPRes *)res_p, &hdrbuf_p, &blockpos);
            pos++;
            str_p++;
        }
    }
    return -1;
}


/*
 * sdk:      NHTTPi_loadFromHdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 */
int func_021BB210(NHTTPRes *res_p, char *dst_p, int pos, int len)
{
    NHTTPi_HDRBUFLIST *hdrbuf_p;
    int blockidx;
    int n;

    if (pos + len <= res_p->headerLen) {
        if (len != 0) {
            if (pos < 0x400) {
                n = 0x400 - pos;
                if (len <= n) {
                    n = len;
                }
                func_021BA100(dst_p, res_p->hdrBufFirst + pos, n);
                pos += n;
                len -= n;
                dst_p += n;
            }
            if (len != 0) {
                pos -= 0x400;
                blockidx = pos >> 9;
                pos &= 0x1ff;
                hdrbuf_p = res_p->hdrBufBlock_p;
                while (blockidx-- != 0) {
                    hdrbuf_p = hdrbuf_p->next_p;
                }
                while (len != 0) {
                    n = 0x200 - pos;
                    if (len <= n) {
                        n = len;
                    }
                    func_021BA100(dst_p, hdrbuf_p->block + pos, n);
                    pos = (pos + n) & 0x1ff;
                    len -= n;
                    dst_p += n;
                    hdrbuf_p = hdrbuf_p->next_p;
                }
            }
        }
        return 1;
    }
    return 0;
}


/*
 * 1 when field +0x1c is <= v (unsigned).
 */
int func_021BB2FC(u8 *p, u32 v)
{
    return *(u32 *)(p + 0x1c) <= v;
}


int NHTTPi_RecvBuf(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p,
        int socket, int pos, int flags)
{
    NHTTPRes *res_p = req_p->res_p;

    return NHTTPi_SocRecv(mutexInfo_p, req_p, socket, res_p->recvBuf_p + pos,
            res_p->recvBufLen - pos, flags);
}


int NHTTPi_RecvBufN(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p,
        int socket, int pos, int len, int flags)
{
    NHTTPRes *res_p = req_p->res_p;
    int len2;

    if (NHTTPi_isRecvBufFull(res_p, pos))
        return -1003;
    len2 = (int)(res_p->recvBufLen - pos);
    if (len <= len2)
        len2 = len;
    return NHTTPi_SocRecv(mutexInfo_p, req_p, socket, res_p->recvBuf_p + pos,
            len2, flags);
}
