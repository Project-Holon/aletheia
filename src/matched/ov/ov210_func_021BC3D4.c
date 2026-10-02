/*
 * function: func_021BC3D4
 * address:  0x021BC3D4
 * packet:   pkt_ov210_021BC3D4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021C0754  0x021C0754  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u8 d_021C0754[];
extern void func_0204335C(u32 a);
extern void func_020433E0(void *a);

void func_021BC3D4(void)
{
    func_0204335C(0);
    func_020433E0(d_021C0754);
}
