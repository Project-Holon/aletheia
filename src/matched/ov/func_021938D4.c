/*
 * function: func_021938D4
 * address:  0x021938D4
 * packet:   pkt_021938D4
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
 *   func_02193C80  0x02193C80  thumb  ov021
 *   func_0216D974  0x0216D974  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern void func_0216D974(unsigned int *p, unsigned int v);
struct X;
extern void func_02193C80(struct X *x);

int func_021938D4(u32 a, u32 b, u32 c, u32 d)
{
func_02193C80((struct X *)a);
if (*(u32 *)((u8 *)(a) + ((5 << 6))) != 0) {
    func_0216D974((unsigned int *)(*(u32 *)((u8 *)(a) + ((5 << 6)))), 1);
}
return func_020307B0(a);
}

