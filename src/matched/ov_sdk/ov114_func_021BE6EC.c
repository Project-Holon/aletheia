/*
 * function: NHTTP_AddRequestHeaderField
 * address:  0x021BE6EC
 * packet:   pkt_ov114_021BE6EC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_AddRequestHeaderField (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_AddRequestHeaderField 0x021BAC38 arm ov114
 */

typedef struct {
    int f0;
    int f4;
} Req;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetBgnEndInfoP(void);
typedef unsigned int   u32;
extern int NHTTPi_AddRequestHeaderField(u32 *p, int a, int b, int c);

int NHTTP_AddRequestHeaderField(Req *req_p, char *label_p, char *value_p)
{
    void *bgnEndInfo_p;

    NHTTPi_GetSystemInfoP();
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    if (req_p == 0) {
        return -1;
    }
    if (req_p->f4 != 0) {
        return -1;
    }
    return -(NHTTPi_AddRequestHeaderField((u32 *)req_p, (int)bgnEndInfo_p, (int)label_p, (int)value_p) == 0);
}
