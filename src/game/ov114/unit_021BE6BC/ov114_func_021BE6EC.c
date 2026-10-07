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

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern void *func_021BEF3C(void);
typedef unsigned int   u32;
extern int func_021BAC38(u32 *p, int a, int b, int c);

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
    return -(func_021BAC38((u32 *)req_p, (int)bgnEndInfo_p, (int)label_p, (int)value_p) == 0);
}
