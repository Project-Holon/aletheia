/*
 * file:     unit_021BAED4_p02.c
 * unit:     yes
 * function: func_021BB12C, func_021BB210, func_021BB2FC, func_021BB310, func_021BB344
 * address:  0x021BB12C
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
#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))
struct _NHTTPMutexInfo;
struct _NHTTPRes;
typedef struct _Res Res_021BB12C;

typedef struct HdrBuf {
    struct HdrBuf *next;
    char buf[0x200];
} HdrBuf;

typedef struct {
    int headerLen;
    char pad[0x30];
    HdrBuf *hdrBufBlock_p;
    char hdrBuf[0x400];
} Res_021BB210;

typedef unsigned char u8;

typedef unsigned int u32;

struct _NHTTPReq {
    int field_00[11];                         /* 0x00 */
    struct _NHTTPRes *res_p;                  /* 0x2c */
};

struct _NHTTPRes {
    int headerLen;                            /* 0x00 */
    int bodyLen;                              /* 0x04 */
    int totalBodyLen;                         /* 0x08 */
    int contentLength;                        /* 0x0c */
    int isSuccess;                            /* 0x10 */
    int isHeaderParse;                        /* 0x14 */
    int httpStatus;                           /* 0x18 */
    unsigned long recvBufLen;                 /* 0x1c */
    char *allHeader_p;                        /* 0x20 */
    char *foundHeader_p;                      /* 0x24 */
    char *recvBuf_p;                          /* 0x28 */
    void *bufFull;                            /* 0x2c */
    void *freeBuf;                            /* 0x30 */
    void *hdrBufBlock_p;                      /* 0x34 */
    char hdrBufFirst[1024];                   /* 0x38 */
    void *param_p;                            /* 0x438 */
};

extern void func_021BAED4(Res_021BB12C *res_p, int pos, void **hdrbuf_pp, int *blockpos_p);
extern char func_021BAF2C(Res_021BB12C *res_p, void **hdrbuf_pp, int *blockpos_p);
extern void func_021BA100(void *dst_p, void *src_p, int size);
extern int NHTTPi_SocRecv(struct _NHTTPMutexInfo *mutexInfo_p,
        struct _NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int NHTTPi_isRecvBufFull(struct _NHTTPRes *res_p, int pos);
int func_021BB12C(Res_021BB12C *res_p, int pos, int limit, char *str_p, char extdeli);
int func_021BB210(Res_021BB210 *res_p, char *dst_p, int pos, int len);
int func_021BB2FC(u8 *p, u32 v);
int NHTTPi_RecvBuf(struct _NHTTPMutexInfo *mutexInfo_p, struct _NHTTPReq *req_p, int socket, int pos, int flags);
int NHTTPi_RecvBufN(struct _NHTTPMutexInfo *mutexInfo_p, struct _NHTTPReq *req_p, int socket, int pos, int len, int flags);


/*
 * sdk:      NHTTPi_compareTokenN_HdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 */
int func_021BB12C(Res_021BB12C *res_p, int pos, int limit, char *str_p, char extdeli)
{
    char c;
    void *hdrbuf_p;
    int blockpos;

    if (pos < limit) {
        func_021BAED4(res_p, pos, &hdrbuf_p, &blockpos);
        c = func_021BAF2C(res_p, &hdrbuf_p, &blockpos);
        limit--;
        while (NHTTPi_TOLOWER(c) == NHTTPi_TOLOWER(*str_p)) {
            if (*str_p == 0 || *str_p == ' ' || *str_p == extdeli || pos == limit) {
                return 0;
            }
            c = func_021BAF2C(res_p, &hdrbuf_p, &blockpos);
            pos++;
            str_p++;
        }
    }
    return -1;
}


/*
 * sdk:      NHTTPi_loadFromHdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 */
int func_021BB210(Res_021BB210 *res_p, char *dst_p, int pos, int len)
{
    HdrBuf *hdrbuf_p;
    int blockidx;
    int n;

    if (pos + len <= res_p->headerLen) {
        if (len != 0) {
            if (pos < 0x400) {
                n = 0x400 - pos;
                if (len <= n) {
                    n = len;
                }
                func_021BA100(dst_p, res_p->hdrBuf + pos, n);
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
                    hdrbuf_p = hdrbuf_p->next;
                }
                while (len != 0) {
                    n = 0x200 - pos;
                    if (len <= n) {
                        n = len;
                    }
                    func_021BA100(dst_p, hdrbuf_p->buf + pos, n);
                    pos = (pos + n) & 0x1ff;
                    len -= n;
                    dst_p += n;
                    hdrbuf_p = hdrbuf_p->next;
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


int NHTTPi_RecvBuf(struct _NHTTPMutexInfo *mutexInfo_p, struct _NHTTPReq *req_p,
        int socket, int pos, int flags)
{
    struct _NHTTPRes *res_p = req_p->res_p;

    return NHTTPi_SocRecv(mutexInfo_p, req_p, socket, res_p->recvBuf_p + pos,
            res_p->recvBufLen - pos, flags);
}


int NHTTPi_RecvBufN(struct _NHTTPMutexInfo *mutexInfo_p, struct _NHTTPReq *req_p,
        int socket, int pos, int len, int flags)
{
    struct _NHTTPRes *res_p = req_p->res_p;
    int len2;

    if (NHTTPi_isRecvBufFull(res_p, pos))
        return -1003;
    len2 = (int)(res_p->recvBufLen - pos);
    if (len <= len2)
        len2 = len;
    return NHTTPi_SocRecv(mutexInfo_p, req_p, socket, res_p->recvBuf_p + pos,
            len2, flags);
}
