/*
 * function: func_021B98A8
 * address:  0x021B98A8
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
 *   func_021C0DDC  0x021C0DDC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C0DDC();
u32 func_021B98A8(u32 a0)
{
    func_021C0DDC(*(u32*)(((u8*)a0) + 28));
    *(u32*)(((u8*)a0) + 28) = 0;
    return 0;
}

