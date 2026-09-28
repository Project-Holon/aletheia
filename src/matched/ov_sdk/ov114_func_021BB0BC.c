/*
 * function: NHTTPi_skipSpaceHdrRecvBuf
 * address:  0x021BB0BC
 * packet:   pkt_ov114_021BAED4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_skipSpaceHdrRecvBuf (libnhttp.TWL.HYB.a nhttp_recvbuf.o)
 *
 * symbols:
 *   setupGetcharFromHdrRecvBuf       0x021baed4 arm
 *   getcharFromHdrRecvBuf            0x021baf2c arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPi_HDRBUFLIST {
    struct _NHTTPi_HDRBUFLIST *next_p;        /* 0x00 */
    char block[512];                          /* 0x04 */
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

extern void setupGetcharFromHdrRecvBuf(struct _NHTTPRes *res_p, int pos,
        struct _NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p);
extern char getcharFromHdrRecvBuf(struct _NHTTPRes *res_p,
        struct _NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p);

int NHTTPi_skipSpaceHdrRecvBuf(struct _NHTTPRes *res_p, int pos, int limit)
{
    struct _NHTTPi_HDRBUFLIST *hdrbuf_p;
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
