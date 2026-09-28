/*
 * function: func_021C1610
 * address:  0x021C1610
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *   func_021C16E8  0x021C16E8  thumb  ov217
 *
 * When the +0x0c handle is idle, runs func_021C16E8().
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C0E64();
extern u32 func_021C16E8();
void func_021C1610(u32 a0)
{
    if (func_021C0E64(*(u32*)(((u8*)a0) + 12)) == 0) {
    func_021C16E8(a0);
    }
}
