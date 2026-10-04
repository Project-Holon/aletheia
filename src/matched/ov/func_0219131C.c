/*
 * function: func_0219131C
 * address:  0x0219131C
 * packet:   pkt_0219131C
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
 *   func_02045808  0x02045808  arm
 *   func_0219492C  0x0219492C  thumb  ov021
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02045808(u32, u32, u32, u32);
extern u32 func_02082BCC(u32, u32, u32);
extern void func_021927E8(u32 *p);
extern void func_0219492C(u8 *p, int i);

int func_0219131C(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(a) + 4) != 0) {
    func_02045808(*(u32 *)((u8 *)(a) + 4), b, c, d);
}
func_0219492C((u8 *)(*(u32 *)((u8 *)(a) + 8)), *(u8 *)((u8 *)(a) + 1));
func_021927E8((u32 *)(a + 12));
return func_02082BCC(a, 0, 52);
}

