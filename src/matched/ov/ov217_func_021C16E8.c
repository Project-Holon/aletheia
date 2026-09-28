/*
 * function: func_021C16E8
 * address:  0x021C16E8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C16FC  0x021C16FC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C0E54();
extern void func_021C16FC();
void func_021C16E8(u32 a0)
{
    func_021C16FC(a0 + 0 + 0, func_021C0E54(*(u32*)(((u8*)a0 + 0) + 12)) + 0);
}

