/*
 * function: func_021B9600
 * address:  0x021B9600
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
 *   func_021B9884  0x021B9884  thumb  ov217
 *   func_021B98A8  0x021B98A8  thumb  ov217
 *   func_021B990C  0x021B990C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020315D4();
extern u32 func_021B9884();
extern u32 func_021B98A8();
extern u32 func_021B990C();
u32 func_021B9600(u32 a0, u32 a1, u32 a2, u32 a3)
{
    func_021B98A8(a3);
    func_021B9884(a3);
    func_021B990C();
    func_020315D4(a0);
    return 1;
}

