/*
 * function: func_021BE7D8
 * address:  0x021BE7D8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BEAEC  0x021BEAEC  thumb  ov217
 *   func_021BEEA4  0x021BEEA4  thumb  ov217
 *   func_021BF15C  0x021BF15C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021BEAEC(u8 *);
extern u32 func_021BEEA4();
extern u32 func_021BF15C();
u32 func_021BE7D8(u32 a0)
{
    func_021BEAEC((u8 *)a0);
    func_021BF15C(a0);
    return func_021BEEA4(a0);
}

