/*
 * function: func_021F3A88
 * address:  0x021F3A88
 * packet:   pkt_ov046_021F3A88
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3BFC  0x021F3BFC  thumb  ov046
 */

typedef unsigned int u32;
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(void *, int);
extern int *func_021897BC(char *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3BFC(u32 a, int *b);

void func_021F3A88(void *a, int b, int c)
{
    void *x = func_0201210C(a);
    int p;
    int *q;

    p = (int)func_0200B3A4(func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[1] = c;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3BFC, 0);
}
