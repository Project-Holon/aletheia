/*
 * function: ov021_func_021A0EE4
 * address:  0x021A0EE4
 * packet:   pkt_ov021_021A0EE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_02013D00  0x02013D00  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_02188C80(u32);
extern u32 func_02188C9C(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EBC(u32);
extern u32 func_02009210(void);
extern u32 func_020090E0(void);
extern u32 func_02013D20(void);
extern u32 func_02013D00(u32);

u32 ov021_func_021A0EE4(u32 *p, u32 x)
{
    u32 a, b;
    if (x == 0) {
        a = func_020120F4(func_02188C80(p[5]));
        b = func_02188C9C(p[5]);
        if (func_02013D20() != 0 || func_02013D00(b) != 0)
            return 5;
        func_02012EBC(a);
        func_02009210();
        if (func_020090E0() == 0)
            return 5;
    }
    return x;
}
