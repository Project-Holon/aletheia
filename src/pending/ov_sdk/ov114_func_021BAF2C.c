/*
 * function: getcharFromHdrRecvBuf
 * address:  0x021BAF2C
 * packet:   pkt_ov114_021BAED4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      getcharFromHdrRecvBuf (libnhttp.TWL.HYB.a nhttp_recvbuf.o)
 *
 * blocker:  2 instruction-scheduling swaps (4 concrete bytes), same size:
 *           p+0x14 wants add r0,r0,r3 before strlt r1,[r2]; and p+0x2c wants
 *           ldr r0,[r0,#0x34] before str r3,[r2].  All source orderings tried
 *           (post-inc, split temp, pointer base, ternary) reschedule identically.
 *           No witnesses/relocs involved; pure mwcc scheduler residue.
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

static char getcharFromHdrRecvBuf(struct _NHTTPRes *res_p,
        struct _NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p)
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
