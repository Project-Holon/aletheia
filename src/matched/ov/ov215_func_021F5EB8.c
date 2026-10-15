/*
 * function: EGG_DEMO_MAIN_StartFadeOutBgm
 * address:  0x021F5EB8
 * packet:   pkt_021F5EB8
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */
#include "../include/Obj25739.h"

typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);

int EGG_DEMO_MAIN_StartFadeOutBgm(int a, char *b)
{
    GFL_USE_FadeOutBgm(0x1e);
    ((struct Obj25739 *)b)->f18 = 1;
    return 1;
}