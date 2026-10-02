/*
 * function: func_021F3B18
 * address:  0x021F3B18
 * packet:   pkt_ov046_021F3B18
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
 *   func_021F3D40  0x021F3D40  thumb  ov046
 */

typedef unsigned int u32;
extern u32 func_0201210C(void *);
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EC4(u32);
extern int func_0200B3A4(u32, u32);
extern int *func_021897BC(u32, int);
extern void *func_020122C0(void *, int, void (*)(void), int);
extern void func_021F3D40(void);

void func_021F3B18(void *a, int b)
{
    u32 x = func_0201210C(a);
    int p;
    int *q;

    p = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3D40, 0);
}
