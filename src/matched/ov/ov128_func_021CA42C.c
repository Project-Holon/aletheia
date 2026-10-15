/*
 * function: WF2DMAP_TOUCH_MakeScreen
 * address:  0x021CA42C
 * packet:   pkt_021CA42C
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14052.h"

typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned);

void WF2DMAP_TOUCH_MakeScreen(char *p)
{
    BMP_WIN_MakeScreen(((struct Obj14052 *)p)->fC);
    func_02041B6C(BMP_WIN_GetBgLayer(((struct Obj14052 *)p)->fC));
}
