/*
 * function: BR_POKESEARCH_CreateSidebar
 * address:  0x021F8D18
 * packet:   pkt_021F8D18
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BR_SIDEBAR_SetVisibleBySpace   0x021FEEC0  thumb
 *   BR_RES_ApplyBgSet   0x021FBDA4  thumb
 *   BR_RES_ReleaseUiPalette   0x021FC1F8  thumb
 *   WORLDTRADE_DETAIL_StateStartWipeOut   0x021FC610  thumb  ov135
 *   MUSICAL_SHOT_SYS_CreateScene   0x021F3AF0  thumb
 *
 * Build the p+0x14 handle once: flush the three sub-resources and start
 *   0x21F3AF0 on the indexed table entry.
 */
#include "../include/Obj06622.h"


extern void BR_SIDEBAR_SetVisibleBySpace(int, int, int);
extern void BR_RES_ApplyBgSet(int, int);
extern void BR_RES_ReleaseUiPalette(int, int);
typedef unsigned char  u8;
extern int WORLDTRADE_DETAIL_StateStartWipeOut(u8 *p, int a1);
extern int MUSICAL_SHOT_SYS_CreateScene(int, int);

void BR_POKESEARCH_CreateSidebar(char *a, int *r4)
{
    if (((struct Obj06622 *)a)->f14 == 0) {
        BR_SIDEBAR_SetVisibleBySpace(r4[1], 0, 0);
        BR_RES_ApplyBgSet(r4[3], 0);
        BR_RES_ReleaseUiPalette(r4[3], 0);
        WORLDTRADE_DETAIL_StateStartWipeOut((u8 *)r4[2], ((struct Obj06622 *)a)->f30);
        ((struct Obj06622 *)a)->f14 = MUSICAL_SHOT_SYS_CreateScene(
            *(int *)(a + 0x40 + ((struct Obj06622 *)a)->fC * 4) + 0x80,
            ((struct Obj06622 *)a)->f30);
    }
}
