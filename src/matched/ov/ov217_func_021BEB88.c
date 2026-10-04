/*
 * function: func_021BEB88
 * address:  0x021BEB88
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
 *   func_021BF5BC  0x021BF5BC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02025A54(u8 *g, u32 a);
extern u32 func_021BF5BC();
u32 func_021BEB88(u32 a0)
{
    func_02025A54((u8 *)(*(u32*)(((u8*)a0) + 940)), 1);
    return func_021BF5BC(a0, 3);
}

