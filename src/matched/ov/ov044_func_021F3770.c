/*
 * function: func_021F3770
 * address:  0x021F3770
 * packet:   pkt_ov044_021F3770
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F37F0  0x021F37F0  thumb
 */

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern int *func_021897BC(char *p, int idx);
extern int func_02188D2C(int *p);
extern void  func_021BE700(void *p, int i, int j, int k, int flag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F37F0(void *a, int *b);

void func_021F3770(void *a0, int a1)
{
    void *r6;
    int *r4;
    void *x;
    int d;

    r6 = func_0201210C(a0);
    r4 = func_021897BC(r6, 1);
    r4[4] = a1;
    if (a1) {
        r4[0] = 0;
        r4[1] = -0x50000;
    } else {
        r4[0] = -0x50000;
        r4[1] = 0;
        x = (void *)func_02188D2C(r6);
        func_021BE700(x, 0, 0, 0, 1);
        func_021BE700(x, 0, 0, 1, 0);
    }
    d = r4[1] - r4[0];
    if (d < 0) {
        d = -0x2000;
    } else {
        d = 0x2000;
    }
    r4[2] = d;
    func_020122C0(a0, 0, func_021F37F0, 0);
}
