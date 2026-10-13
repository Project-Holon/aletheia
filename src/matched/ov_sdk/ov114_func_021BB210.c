/*
 * function: NHTTPi_loadFromHdrRecvBuf
 * address:  0x021BB210
 * packet:   pkt_ov114_021BB210
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_loadFromHdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 *
 * symbols:
 *   NHTTPi_memcpy 0x021BA100 arm ov114
 */

typedef struct HdrBuf {
    struct HdrBuf *next;
    char buf[0x200];
} HdrBuf;

typedef struct {
    int headerLen;
    char pad[0x30];
    HdrBuf *hdrBufBlock_p;
    char hdrBuf[0x400];
} Res;

extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);

int NHTTPi_loadFromHdrRecvBuf(Res *res_p, char *dst_p, int pos, int len)
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
                NHTTPi_memcpy(dst_p, res_p->hdrBuf + pos, n);
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
                    NHTTPi_memcpy(dst_p, hdrbuf_p->buf + pos, n);
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
