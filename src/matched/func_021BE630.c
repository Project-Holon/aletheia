/*
 * function: func_021BE630
 * address:  0x021BE630
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE930  0x021BE930  thumb  ov217
 *   func_021BE934  0x021BE934  thumb  ov217
 *   func_021BE9B8  0x021BE9B8  thumb  ov217
 *   func_021BEFF8  0x021BEFF8  thumb  ov217
 *   func_021BF3D8  0x021BF3D8  thumb  ov217
 *   func_021BF4AC  0x021BF4AC  thumb  ov217
 *   func_021BF810  0x021BF810  thumb  ov217
 *
 * Sub-state step for a1 in {1,2}, gated on the +0x3C8 handle being busy;
 * otherwise the fixed call list runs unconditionally.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BE930();
extern u32 func_021BE9B8();
extern u32 func_021BE934();
extern u32 func_021BEFF8();
extern u32 func_021BF3D8();
extern u32 func_021BF4AC();
extern u32 func_021BF810();
void func_021BE630(u8 *a0, u32 a1)
{
    if ((u32)(a1 - 1) <= 1) {
    if (*(u32*)(a0 + 968) == 0) {
    return;
    }
    if (func_021BF810(a0, *(u32*)(a0 + 968)) == 0) {
    return;
    }
    }
    func_021BE9B8(a0);
    func_021BE930(a0, a1);
    func_021BE934(a0);
    func_021BF3D8(a0);
    func_021BF4AC(a0);
    func_021BEFF8(a0);
}
