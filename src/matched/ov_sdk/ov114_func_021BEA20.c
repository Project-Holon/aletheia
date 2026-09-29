/*
 * function: func_021BEA20
 * address:  0x021BEA20
 * packet:   pkt_ov114_021BEA20
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_GetStaticResource (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 *
 * symbols:
 *   func_021B9B4C 0x021B9B4C arm ov114
 *   g_021CF984 0x021CF984 data
 *   g_021CF98C 0x021CF98C data
 */

typedef struct {
    int unique;
    int mutex[6];
    int f1c;
    int f20;
} Res;

extern int g_021CF984[];
extern Res g_021CF98C;

extern void func_021B9B4C(int *mutex_p);

Res *func_021BEA20(void)
{
    Res *r = &g_021CF98C;
    if (g_021CF984[2] == 0) {
        func_021B9B4C(&r->mutex[0]);
        r->f20 = 0;
        r->f1c = 0;
        r->unique = 1;
    }
    return r;
}
