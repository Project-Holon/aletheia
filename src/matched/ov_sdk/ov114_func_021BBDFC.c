/*
 * function: NHTTPi_GetResponseHeaderAll
 * address:  0x021BBDFC
 * packet:   pkt_ov114_021BBDFC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_GetResponseHeaderAll (libnhttp.TWL.HYB.a(nhttp_response.o))
 *
 * symbols:
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_SetError 0x021BA874 arm ov114
 *   NHTTPi_loadFromHdrRecvBuf 0x021BB210 arm ov114
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

typedef struct {
    volatile int headerLen;
    char pad0[0x10];
    int isHeaderParse;
    char pad1[0x8];
    char *allHeader_p;
    char pad2[0x14];
    char hdrBuf[0x400];
} Res;

extern int NHTTPi_alloc(int a, int b);
typedef unsigned char  u8;
extern void NHTTPi_SetError(u8 *p, int v);
extern int NHTTPi_loadFromHdrRecvBuf(Res *res_p, char *dst_p, int pos, int len);

int NHTTPi_GetResponseHeaderAll(void *bgnEndInfo_p, Res *res_p, char **value_pp)
{
    if (res_p->isHeaderParse == 0 || res_p->headerLen == 0) {
        return -1;
    }
    if (res_p->headerLen < 0x400) {
        *value_pp = res_p->hdrBuf;
    } else {
        if (res_p->allHeader_p == 0) {
            res_p->allHeader_p = (char *)NHTTPi_alloc(res_p->headerLen, 4);
            if (res_p->allHeader_p == 0) {
                NHTTPi_SetError(bgnEndInfo_p, 1);
                return -1;
            }
            NHTTPi_loadFromHdrRecvBuf(res_p, res_p->allHeader_p, 0, res_p->headerLen);
        }
        *value_pp = res_p->allHeader_p;
    }
    return res_p->headerLen;
}
