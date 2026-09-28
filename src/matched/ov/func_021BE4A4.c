/*
 * function: func_021BE4A4
 * address:  0x021BE4A4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE4CC  0x021BE4CC  thumb  ov217
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *
 * When the +0x3DC guard word is set and the +0x1c handle is idle, hand it
 * to func_021BE4CC with the value func_021C0E54() reports.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BE4CC();
extern u32 func_021C0E54();
extern u32 func_021C0E64();
void func_021BE4A4(u32 a0)
{
    if (*(u32*)(((u8*)a0) + 988) != 0) {
    if (func_021C0E64(*(u32*)(((u8*)a0) + 28)) == 0) {
    func_021BE4CC(a0, func_021C0E54(*(u32*)(((u8*)a0) + 28)));
    }
    }
}
