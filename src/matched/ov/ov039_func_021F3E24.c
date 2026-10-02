/*
 * function: func_021F3E24
 * address:  0x021F3E24
 * packet:   pkt_ov039_021F3E24
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3E24  0x021F3E24  thumb
 *   func_021F3E70  0x021F3E70  thumb
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

extern void *func_0201210C(void *a);
extern int func_02188D2C(u32 a);
extern u8 *func_021897BC(u32 a, int b);
extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern void *func_0200B3A4(u32 a, u32 b);
extern int func_020122C0(void *a, int b, void *cb, int c);
extern void func_021F3E70(void);

int func_021F3E24(void *a, u32 b)
{
    void *s;
    u8 *p;
    int r;

    s = func_0201210C((void *)a);
    func_02188D2C(s);
    p = func_021897BC(s, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(s))), 2);
    if (b >= 4) {
        return 0;
    }
    r = func_020122C0(a, 0, func_021F3E70, 0);
    p[5] = b;
    return r;
}
