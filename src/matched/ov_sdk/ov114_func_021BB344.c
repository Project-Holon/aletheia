/*
 * function: NHTTPi_RecvBufN
 * address:  0x021BB344
 * packet:   pkt_ov114_021BAED4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_RecvBufN (libnhttp.TWL.HYB.a nhttp_recvbuf.o)
 *
 * symbols:
 *   NHTTPi_isRecvBufFull             0x021bb2fc arm
 *   NHTTPi_SocRecv                   0x021b9f94 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPMutexInfo;
struct _NHTTPRes;

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

extern int NHTTPi_isRecvBufFull(struct _NHTTPRes *res_p, int pos);
extern int NHTTPi_SocRecv(struct _NHTTPMutexInfo *mutexInfo_p,
        struct _NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);

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
