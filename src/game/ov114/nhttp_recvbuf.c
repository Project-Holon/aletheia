/*
 * file:     nhttp_recvbuf.c
 * unit:     yes
 * function: setupGetcharFromHdrRecvBuf, getcharFromHdrRecvBuf, NHTTPi_findNextLineHdrRecvBuf, NHTTPi_skipSpaceHdrRecvBuf, NHTTPi_compareTokenN_HdrRecvBuf, NHTTPi_loadFromHdrRecvBuf, NHTTPi_isRecvBufFull, NHTTPi_RecvBuf, NHTTPi_RecvBufN
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
 *   setupGetcharFromHdrRecvBuf 0x021BAED4 arm ov114
 *   getcharFromHdrRecvBuf 0x021BAF2C arm ov114
 *   NHTTPi_memcpy 0x021BA100 arm ov114
 *   NHTTPi_SocRecv                   0x021b9f94 arm
 *   NHTTPi_isRecvBufFull             0x021bb2fc arm
 */
#include "nhttp_types.h"
#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))


extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);
extern int NHTTPi_SocRecv(NHTTPMutexInfo *mutexInfo_p,
        NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
int NHTTPi_isRecvBufFull(NHTTPRes *res_p, u32 pos);
int NHTTPi_findNextLineHdrRecvBuf(NHTTPRes *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p);
int NHTTPi_skipSpaceHdrRecvBuf(NHTTPRes *res_p, int pos, int limit);
int NHTTPi_compareTokenN_HdrRecvBuf(NHTTPRes *res_p, int pos, int limit, char *str_p, char extdeli);
int NHTTPi_loadFromHdrRecvBuf(NHTTPRes *res_p, char *dst_p, int pos, int len);
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


int NHTTPi_findNextLineHdrRecvBuf(NHTTPRes *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p)
{
    NHTTPi_HDRBUFLIST *hdrbuf_p;
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
        setupGetcharFromHdrRecvBuf(res_p, pos, &hdrbuf_p, &blockpos);
        for (; pos < limit; pos++) {
            c = getcharFromHdrRecvBuf(res_p, &hdrbuf_p, &blockpos);
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
int NHTTPi_compareTokenN_HdrRecvBuf(NHTTPRes *res_p, int pos, int limit, char *str_p, char extdeli)
{
    char c;
    NHTTPi_HDRBUFLIST *hdrbuf_p;
    int blockpos;

    if (pos < limit) {
        setupGetcharFromHdrRecvBuf(res_p, pos, &hdrbuf_p, &blockpos);
        c = getcharFromHdrRecvBuf(res_p, &hdrbuf_p, &blockpos);
        limit--;
        while (NHTTPi_TOLOWER(c) == NHTTPi_TOLOWER(*str_p)) {
            if (*str_p == 0 || *str_p == ' ' || *str_p == extdeli || pos == limit) {
                return 0;
            }
            c = getcharFromHdrRecvBuf(res_p, &hdrbuf_p, &blockpos);
            pos++;
            str_p++;
        }
    }
    return -1;
}


/*
 * sdk:      NHTTPi_loadFromHdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 */
int NHTTPi_loadFromHdrRecvBuf(NHTTPRes *res_p, char *dst_p, int pos, int len)
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
                NHTTPi_memcpy(dst_p, res_p->hdrBufFirst + pos, n);
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
                    NHTTPi_memcpy(dst_p, hdrbuf_p->block + pos, n);
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
 * 1 when the receive buffer length is <= pos (unsigned).
 */
int NHTTPi_isRecvBufFull(NHTTPRes *res_p, u32 pos)
{
    return res_p->recvBufLen <= pos;
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
