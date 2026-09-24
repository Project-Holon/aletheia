/*
 * function: func_021BA1D4
 * address:  0x021BA1D4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020270E0  0x020270E0  thumb
 *   func_021BA328  0x021BA328  thumb  ov217
 *
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020270E0();
extern u32 func_021BA328();
void func_021BA1D4(u32 a0)
{
    if (*(u32*)(((u8*)a0 + 132)) == 0) {
    if (func_020270E0(*(u32*)(((u8*)a0 + 132))) == 1) {
    *(u32*)(((u8*)a0 + 132)) = 1;
    func_021BA328(a0, 1);
    }
    }
}
