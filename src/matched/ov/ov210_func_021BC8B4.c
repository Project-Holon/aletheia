/*
 * function: func_021BC8B4
 * address:  0x021BC8B4
 * packet:   pkt_ov210_021BC8B4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void func_0207D63C(u32 reg, u32 a, u32 b, u32 c, u32 d);

void func_021BC8B4(int mode)
{
    if (mode == 1) {
        func_0207D63C(0x04000050, 8, 4, 16, 6);
        func_0207D63C(0x04001050, 2, 6, 6, 10);
        return;
    }
    *(volatile u16 *)0x04001050 = 0;
}
