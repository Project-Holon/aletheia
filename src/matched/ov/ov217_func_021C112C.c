/*
 * function: func_021C112C
 * address:  0x021C112C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C124C  0x021C124C  thumb  ov217
 *   func_021C13E8  0x021C13E8  thumb  ov217
 *   func_021C14DC  0x021C14DC  thumb  ov217
 *   func_021C1D24  0x021C1D24  thumb  ov217
 *
 * When func_021C1D24() reports 1 and the +8 field is set, runs the
 * +0x3C update triplet.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C124C();
extern u32 func_021C13E8();
extern u32 func_021C14DC();
extern u32 func_021C1D24();
void func_021C112C(u32 a0)
{
    if (func_021C1D24() == 1) {
    if (*(u32*)(((u8*)a0) + 8) != 0) {
    func_021C14DC(a0);
    func_021C124C(a0);
    func_021C13E8(a0);
    }
    }
}
