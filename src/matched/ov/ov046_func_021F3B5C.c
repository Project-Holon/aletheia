/*
 * function: func_021F3B5C
 * address:  0x021F3B5C
 * packet:   pkt_ov046_021F3B5C
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The negation is a multiply by 0xffffffff (see the idiom on
 * multiplying by minus one), and the +12 base is a separate local that
 * is formed after the func_020122C0 call.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3EFC  0x021F3EFC  thumb  ov046
 */

typedef unsigned int u32;
extern u32 func_0201210C(void *);
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EC4(u32);
extern int func_0200B3A4(u32, u32);
extern int *func_021897BC(u32, int);
extern u32 func_02188CB4(u32);
extern void func_021A3038(u32, int *);
extern void *func_020122C0(void *, int, void (*)(void), int);
extern void func_021F3EFC(void);

void *func_021F3B5C(void *a, int b)
{
    u32 x = func_0201210C(a);
    char *q;
    int *w;
    void *r;
    int v[3];

    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(x))), 10);
    q = (char *)func_021897BC(x, 1);
    r = func_020122C0(a, 0, func_021F3EFC, 0);
    w = (int *)(q + 12);
    ((unsigned char *)w)[3] = 0;
    w[1] = 0x2000;
    func_021A3038(func_02188CB4(x), v);
    w[2] = v[1];
    if (b == 2)
        w[1] = w[1] * 0xffffffff;
    return r;
}
