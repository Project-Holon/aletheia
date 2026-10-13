/*
 * function: func_021BE790
 * address:  0x021BE790
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
 *   func_021BEA8C  0x021BEA8C  thumb  ov217
 *   func_021BEEA4  0x021BEEA4  thumb  ov217
 *   func_021BF15C  0x021BF15C  thumb  ov217
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 GFL_USE_PlaySeDefaultVolume();
extern void func_021BEA8C(u8 *p, int step);
extern void func_021BEEA4(char *p);
extern void func_021BF15C(char *p);
u32 func_021BE790(u32 a0)
{
    func_021BEA8C((u8 *)a0, 1);
    func_021BF15C((char *)a0);
    func_021BEEA4((char *)a0);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

