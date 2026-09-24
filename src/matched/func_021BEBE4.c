/*
 * function: func_021BEBE4
 * address:  0x021BEBE4
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
 *   func_021BF594  0x021BF594  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02025A54();
extern u32 func_021BF594();
u32 func_021BEBE4(u32 a0)
{
    func_02025A54(*(u32*)(((u8*)a0) + 940), 1);
    return func_021BF594(a0, 5);
}

