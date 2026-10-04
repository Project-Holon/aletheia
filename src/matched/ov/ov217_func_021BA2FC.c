/*
 * function: func_021BA2FC
 * address:  0x021BA2FC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BA3E8  0x021BA3E8  thumb  ov217
 *   func_021C1038  0x021C1038  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BA3E8();
extern void func_021C1038(u8 *p, u8 palette);
u32 func_021BA2FC(u32 a0)
{
    func_021C1038((u8 *)(*(u32*)(((u8*)a0) + 84)), 15);
    func_021BA3E8(a0, 3);
    return func_021BA3E8(a0, 4);
}

