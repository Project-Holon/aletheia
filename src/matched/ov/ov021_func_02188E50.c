/*
 * function: func_02188E50
 * address:  0x02188E50
 * packet:   pkt_ov021_02188E50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 *   func_0207DD24  0x0207DD24  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   func_02046BE0  0x02046BE0  arm
 *   data_021D3640  0x021D3640  data  a4
 *   data_021D35E4  0x021D35E4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 data_021D3640[];
extern u8 data_021D35E4[];
extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(void *a);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_0207DCF8(void *a);
extern void func_02046BE0(u32 a, u32 b);

void func_02188E50(void)
{
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xFFFFCFFD;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x10;
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFFB;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 8;
    func_0207DC44(0, 0, 5, 0xE00);
    *(volatile u32 *)0x04000358 = 0x7FFF;
    func_0207DD10(data_021D3640);
    func_0207DD24(0, 0x1F, 0x7FFF, 0, 0);
    func_0207DCF8(data_021D35E4);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u32 *)0x04000580 = 0xBFFF0000;
    func_02046BE0(1, 0);
}
