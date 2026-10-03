/*
 * function: ov021_func_021A0FE8
 * address:  0x021A0FE8
 * packet:   pkt_ov021_021A0FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02009208  0x02009208  thumb
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F279C  0x021F279C  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern unsigned char abs_id_1d[];
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EBC(u32);
extern u32 func_02009210(u32);
extern u32 func_02009208(u32);
extern void func_02009200(u32, u32);
extern u32 func_0201214C(u32);
extern u32 func_02012204(u32);
extern void func_02012210(u32);
extern int func_02034AC4(int);
extern u32 func_021F279C(u32, u32 *, u32, u32);

void ov021_func_021A0FE8(u32 *p)
{
    u32 a, b, c, d;
    a = func_02188C80(p[5]);
    b = func_02009210(func_02012EBC(func_020120F4(a)));
    func_02034AC4((int)abs_id_1d);
    c = func_02009208(b);
    d = func_0201214C(a);
    p[8] = func_021F279C(b, p, a, d == 1 && c == 0);
    func_02009200(b, d);
    if (func_02012204(a) != 0)
        func_02012210(a);
}
