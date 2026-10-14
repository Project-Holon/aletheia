/*
 * function: DENDOU_VIEW_PresentWindow
 * address:  0x021DD94C
 * packet:   pkt_021DD94C
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj14291.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void DENDOU_VIEW_PresentWindow(int *p)
{
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj14291 *)p)->f0));
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)(((struct Obj14291 *)p)->f0)));
}
