/*
 * function: ov021_func_021A10E0
 * address:  0x021A10E0
 * packet:   pkt_ov021_021A10E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
 *   func_021F2994  0x021F2994  thumb  ov029
 *   func_021F2848  0x021F2848  thumb  ov029
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EBC(u32);
extern u32 func_02009210(u32);
extern void func_02009200(u32, u32);
extern u32 func_0201214C(u32);
extern u32 func_02012204(u32);
extern void func_02012210(u32);
extern u32 func_021F2994(u32);
extern u32 func_021F2848(u32, u32);

u32 ov021_func_021A10E0(u32 *p, u32 x)
{
    u32 a, b;
    if (x != 0) {
        a = func_02188C80(p[5]);
        b = func_02009210(func_02012EBC(func_020120F4(a)));
        if (func_02012204(a) != 0) {
            if (func_0201214C(a) != 0) {
                func_02012210(a);
            } else if (func_021F2994(p[8]) != 0) {
                func_02009200(b, 0);
                func_02012210(a);
            }
        }
    }
    return func_021F2848(p[8], x);
}
