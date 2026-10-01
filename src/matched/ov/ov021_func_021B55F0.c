/*
 * function: func_021B55F0
 * address:  0x021B55F0
 * packet:   pkt_ov021_021B55F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 */

typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;

extern u32 func_020124E4(u32);
extern u32 func_0201210C(u32);
extern u32 func_02188C58(u32);
extern u32 func_0218FE50(u32);

int func_021B55F0(u32 a)
{
    u32 x = func_0218FE50(func_02188C58(func_0201210C(func_020124E4(a))));

    return x != 0 ? B_FALSE : B_TRUE;
}
