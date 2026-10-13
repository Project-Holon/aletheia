/*
 * function: func_021BE49C
 * address:  0x021BE49C
 * packet:   pkt_021BE49C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14680.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);

void func_021BE49C(u8 *p)
{
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj14680 *)p)->f0));
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)(((struct Obj14680 *)p)->f0)));
}

