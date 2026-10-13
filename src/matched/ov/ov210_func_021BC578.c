/*
 * function: func_021BC578
 * address:  0x021BC578
 * packet:   pkt_ov210_021BC578
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void func_020434DC(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 a, u32 b);
extern void func_020403F4(u32 a);
extern void func_0203F9B4(void);

void func_021BC578(u32 a0)
{
    func_020434DC(15, 0);
    BG_SYS_SetSubPlaneVisible(15, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}
