/*
 * function: func_021BA158
 * address:  0x021BA158
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA180  0x021BA180  thumb  ov217
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *
 * When the +0x80 guard word is set and the +0x14 handle is idle, hand it
 * to func_021BA180 with the value func_021C0E54() reports.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BA180();
extern u32 func_021C0E54();
extern u32 func_021C0E64();
void func_021BA158(u32 a0)
{
    if (*(u32*)(((u8*)a0 + 128)) != 0) {
    if (func_021C0E64(*(u32*)(((u8*)a0) + 20)) == 0) {
    func_021BA180(a0, func_021C0E54(*(u32*)(((u8*)a0) + 20)));
    }
    }
}
