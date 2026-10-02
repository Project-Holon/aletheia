/*
 * function: func_021BD61C
 * address:  0x021BD61C
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
 *   func_021BFB04  0x021BFB04  thumb  ov217
 *   func_021BFB24  0x021BFB24  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BFB04();
extern void func_021BFB24(u8 *a0);
u32 func_021BD61C(u32 a0)
{
    func_021BFB24((u8 *)a0);
    return func_021BFB04(a0);
}

