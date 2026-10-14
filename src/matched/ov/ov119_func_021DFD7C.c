/*
 * function: POKETRADE_SAVE_PopBgmFadeIn24
 * address:  0x021DFD7C
 * packet:   pkt_ov119_021DFD7C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 */
#include "../include/Obj22750.h"

typedef unsigned char u8;

extern int GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);

void POKETRADE_SAVE_PopBgmFadeIn24(void *p)
{
    u8 *b = p;

    GFL_USE_PopBgm();
    ((struct Obj22750 *)b)->f11F8 -= 1;
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(0x18);
}
