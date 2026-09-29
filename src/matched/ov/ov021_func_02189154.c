/*
 * function: func_02189154
 * address:  0x02189154
 * packet:   pkt_ov021_02189154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020140E0  0x020140E0  thumb
 *   func_02013DB8  0x02013DB8  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   data_021EE700  0x021EE700  data  a4
 *   data_021EE700b  0x021EE700  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 data_021EE700[];
extern u16 data_021EE700b[];
extern u32 func_020140E0(void *a);
extern u32 func_02013DB8(u32 a);
extern void func_02048F4C(void *a, u32 b, u32 c);
extern void func_0207DCF8(void *a);

void func_02189154(void *a, u32 b)
{
    u32 r = func_020140E0(a);

    if (r == 0xFF) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
        return;
    }
    if (func_02013DB8(b) != 0)
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    else
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
    func_02048F4C(data_021EE700, 0xF, r);
    data_021EE700b[7] = 0x4210;
    func_0207DCF8(data_021EE700);
}
