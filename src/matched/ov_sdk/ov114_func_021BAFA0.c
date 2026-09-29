/*
 * function: func_021BAFA0
 * address:  0x021BAFA0
 * packet:   pkt_ov114_021BAFA0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_findNextLineHdrRecvBuf (libnhttp.TWL.HYB.a(nhttp_recvbuf.o))
 *
 * symbols:
 *   func_021BAED4 0x021BAED4 arm ov114
 *   func_021BAF2C 0x021BAF2C arm ov114
 */

typedef struct {
    char pad[0x34];
    void *hdrBufBlock_p;
} Res;

extern void func_021BAED4(Res *res_p, int pos, void *hdrbuf_pp, int *blockpos_p);
extern char func_021BAF2C(Res *res_p, void *hdrbuf_pp, int *blockpos_p);

int func_021BAFA0(Res *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p)
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
