/*
 * function: func_021BE6EC
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
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BAC38 0x021BAC38 arm ov114
 */

typedef struct {
    int f0;
    int f4;
} Req;

extern void *func_021BEF08(void);
extern void *func_021BEF3C(void);
extern int func_021BAC38(Req *req_p, void *bgnEndInfo_p, char *label_p, char *value_p);

int func_021BE6EC(Req *req_p, char *label_p, char *value_p)
{
    void *bgnEndInfo_p;

    func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    if (req_p == 0) {
        return -1;
    }
    if (req_p->f4 != 0) {
        return -1;
    }
    return -(func_021BAC38(req_p, bgnEndInfo_p, label_p, value_p) == 0);
}
