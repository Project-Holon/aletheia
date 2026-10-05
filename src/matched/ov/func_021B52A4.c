/*
 * function: func_021B52A4
 * address:  0x021B52A4
 * packet:   pkt_021B52A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02159168(u32);
extern u32 func_02188C5C(u8 *p);
extern u32 func_02188CFC(u8 *p);
extern void func_0218F05C(unsigned char *a);
extern int func_0218F0F8(u8 *a);
extern u32 func_0218F878(u32, u32, u32, u32);
extern u32 func_021BB260(u32, u32);

int func_021B52A4(u32 a, u32 b, u32 c, u32 d)
{
func_0218F878(b, b, c, d);
if (func_0218F0F8((u8 *)b) != 0) {
    func_0218F05C((unsigned char *)b);
}
if (func_02188CFC((u8 *)a) == 1) {
    func_021BB260(func_02188C5C((u8 *)a), 1);
}
return func_02159168(0);
}

