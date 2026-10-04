/*
 * function: ov021_func_021A1050
 * address:  0x021A1050
 * packet:   pkt_ov021_021A1050
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
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F27D8  0x021F27D8  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern unsigned char abs_id_1d[];
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EBC(u32);
extern u32 func_02009210(u32);
extern void func_02009200(u32, u32);
struct Ctx;
extern u32 func_0201214C(const struct Ctx *p);
extern u32 func_02012204(u32);
extern void func_02012210(u32);
extern int func_02034AC4(int);
extern u32 func_021F27D8(u32, u32 *, u32, u32, u32, u32);

void ov021_func_021A1050(u32 *p)
{
    u32 a, b, c, d;
    a = func_02188C80(p[5]);
    b = func_02012EBC(func_020120F4(a));
    func_02034AC4((int)abs_id_1d);
    c = func_0201214C((const struct Ctx *)a);
    d = func_02009210(b);
    p[8] = func_021F27D8(d, p, func_02188C80(p[5]), p[6], p[7], c);
    func_02009200(d, c);
    if (func_02012204(a) != 0)
        func_02012210(a);
    p[0] = 0;
    p[1] = 0;
}
