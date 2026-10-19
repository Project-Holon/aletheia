/*
 * function: ZUKAN_DETAIL_VOICE_RestoreBgm
 * address:  0x021C2BF4
 * packet:   pkt_021C2BF4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 *   (none)

 * Leaves state 2 and moves the object at +0xB8 to state 3.
 */
#include "../include/Obj00146.h"


extern int GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmPaused(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);

void ZUKAN_DETAIL_VOICE_RestoreBgm(void *unused, char *p, void *a2)
{
    if (((struct Obj00146 *)p)->fB8 == 2) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
    }
    GFL_USE_FadeInBgmFull(0x3c);
    ((struct Obj00146 *)p)->fB8 = 3;
}
