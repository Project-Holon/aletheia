/*
 * function: NHTTPi_compareTokenN_HdrRecvBuf
 * address:  0x021BB12C
 * packet:   pkt_ov114_021BB12C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_compareTokenN_HdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 *
 * symbols:
 *   setupGetcharFromHdrRecvBuf 0x021BAED4 arm ov114
 *   getcharFromHdrRecvBuf 0x021BAF2C arm ov114
 */

typedef struct _Res Res;

#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))

extern void setupGetcharFromHdrRecvBuf(Res *res_p, int pos, void **hdrbuf_pp, int *blockpos_p);
extern char getcharFromHdrRecvBuf(Res *res_p, void **hdrbuf_pp, int *blockpos_p);

int NHTTPi_compareTokenN_HdrRecvBuf(Res *res_p, int pos, int limit, char *str_p, char extdeli)
{
    char c;
    void *hdrbuf_p;
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
