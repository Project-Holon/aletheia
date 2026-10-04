/*
 * function: func_021BCB48
 * address:  0x021BCB48
 * packet:   pkt_ov021_021BCB48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0215841C  0x0215841C  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_02013D5C  0x02013D5C  thumb
 */

struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
extern int func_02158344(int a);
extern int func_02012B38(int a);
extern int func_02012B58(int a);
extern int func_0215841C(int a);
extern int func_0201444C(int a);
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);

int func_021BCB48(int *p, int b)
{
    int r4, r6, t;

    r4 = func_02158344((int)func_02012138((const struct Ctx *)p[0]));
    t = func_02012B38(p[1]);
    r6 = func_02012B58(p[1]);
    if (r4 != 0) {
        r4 = func_0215841C(p[1]);
        if (func_0201444C(t) == 1) {
            return 1;
        }
        if (func_02013D5C(b) != 0 && r6 != r4) {
            return 1;
        }
    }
    return 0;
}
