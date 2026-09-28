/*
 * function: setupGetcharFromHdrRecvBuf
 * address:  0x021BAED4
 * packet:   pkt_ov114_021BAED4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * sdk:      setupGetcharFromHdrRecvBuf (libnhttp.TWL.HYB.a nhttp_recvbuf.o)
 *
 * symbols:
 *   (none)
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPi_HDRBUFLIST {
    struct _NHTTPi_HDRBUFLIST *next_p;   /* 0x00 */
    char block[512];                     /* 0x04 */
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
    struct _NHTTPi_HDRBUFLIST *hdrBufBlock_p; /* 0x34 */
    char hdrBufFirst[1024];                   /* 0x38 */
    void *param_p;                            /* 0x438 */
};

static void setupGetcharFromHdrRecvBuf(struct _NHTTPRes *res_p, int pos,
        struct _NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p)
{
    struct _NHTTPi_HDRBUFLIST *a_hdrbuf_p;
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
