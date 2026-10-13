/*
 * function: func_021BCAC0
 * address:  0x021BCAC0
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
 *   func_021BCAC0  0x021BCAC0  thumb  ov217
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020403F4();
extern void BMP_WIN_Exit(void);
u32 func_021BCAC0(u8 *a0)
{
    BMP_WIN_Exit();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(0);
    func_020403F4(7);
    return func_020403F4(6);
}

