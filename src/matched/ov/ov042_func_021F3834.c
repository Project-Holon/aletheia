/*
 * function: func_021F3834
 * address:  0x021F3834
 * packet:   pkt_ov042_021F3834
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3834  0x021F3834  thumb
 *   func_021F38D4  0x021F38D4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
struct Big;
struct Desc;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_0200B3A4(u32 a, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F38D4(void *a, int *st);

int func_021F3834(void *a, u32 b, u32 c)
{
    void *s;
    u8 *p;
    int r;

    s = func_0201210C((void *)a);
    func_02188D2C(s);
    p = (u8 *)func_021897BC(s, 1);
    func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80(s))), 4);
    if (b >= 9) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, func_021F38D4, 0);
    if (r != 0) {
        p[0] = b;
        p[2] = c;
    }
    return r;
}
