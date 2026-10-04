/*
 * function: func_0218CA4C
 * address:  0x0218CA4C
 * packet:   pkt_0218CA4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021C0674  0x021C0674  thumb  ov021
 *   func_0218D05C  0x0218D05C  thumb  ov021
 *   func_021938D4  0x021938D4  thumb  ov021
 *   func_0218B7F8  0x0218B7F8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern void func_0218B7F8(char *p);
extern void func_0218D05C(char *p);
extern u32 func_021938D4(u32);
extern u32 func_021C0674(u32, u32, u32, u32);

int func_0218CA4C(u32 a, u32 b, u32 c, u32 d)
{
func_021C0674(*(u32 *)((u8 *)(a) + 112), b, c, d);
func_0218D05C((char *)a);
func_021938D4(*(u32 *)((u8 *)(a) + 108));
if (*(u32 *)((u8 *)(a) + 100) != 0) {
    func_0218B7F8((char *)(*(u32 *)((u8 *)(a) + 100)));
    *(u32 *)((u8 *)(a) + 100) = 0;
}
return func_020307B0(a);
}

