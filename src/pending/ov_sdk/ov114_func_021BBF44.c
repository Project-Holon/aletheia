/*
 * function: func_021BBF44
 * address:  0x021BBF44
 * packet:   pkt_ov114_021BBF44
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH (near miss: 74 B; frame: image spills srclen to a fresh [sp+4] slot, ours to the incoming home slot, and r4/r5 swap)
 *
 * sdk:      NHTTPi_SaveBuf (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   DWCi_Ndi_memcpy  0x021BA100  arm  ov114
 *   func_021BA020    0x021BA020  arm  ov114
 */

typedef struct {
    int cancel;
} Req;

extern void DWCi_Ndi_memcpy(void *dst_p, void *src_p, int size);
extern int func_021BA020(Req *req_p, int socket, char *buf_p, int len, int flags);

int func_021BBF44(Req *req_p, char *commBuf_p, int socket, int *bufwp_p, char *src_p, int srclen)
{
    int n;
    int len;
    int sendbyte;

    len = srclen;
    if (srclen > 0) while (len > 0) {
        if (req_p->cancel != 0)
            return -1;
        n = 0x4000 - *bufwp_p;
        if (len <= n)
            n = len;
        DWCi_Ndi_memcpy(commBuf_p + *bufwp_p, src_p, n);
        src_p += n;
        *bufwp_p += n;
        len -= n;
        if (*bufwp_p == 0x4000) {
            sendbyte = func_021BA020(req_p, socket, commBuf_p, 0x4000, 0);
            if (sendbyte <= 0)
                return sendbyte;
            *bufwp_p -= sendbyte;
        }
    }
    return srclen;
}
