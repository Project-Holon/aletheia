/*
 * function: ZUKAN_DETAIL_VOICE_UpdateBgmFade
 * address:  0x021C2C1C
 * packet:   pkt_021C2BF4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   (none)

 * Moves the object at +0xB8 from state 1 to state 2.
 */
#include "../include/Obj00146.h"


extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);

void ZUKAN_DETAIL_VOICE_UpdateBgmFade(int unused, char *p, int a2)
{
    if (((struct Obj00146 *)p)->fB8 == 1) {
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            ((struct Obj00146 *)p)->fB8 = 2;
        }
    }
}
