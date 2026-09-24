/*
 * function: func_021BEB40
 * address:  0x021BEB40
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

extern u32 func_02025A54();
extern u32 func_021BF594();
extern u32 func_021BF5BC();
u32 func_021BEB40(u32 a0)
{
    func_02025A54(*(u32*)(((u8*)a0) + 940), 0);
    func_021BF5BC(a0, 5);
    func_021BF5BC(a0, 6);
    return func_021BF594(a0, 2);
}

