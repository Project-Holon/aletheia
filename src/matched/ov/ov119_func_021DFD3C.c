/*
 * function: POKETRADE_SAVE_PopBgmFadeIn60
 * address:  0x021DFD3C
 * packet:   pkt_ov119_021DFD3C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *
 * Decrement the +0x11f8 guard byte (both its condition and the store use
 * that same pool word) and pulse the 0x3c delay. Non-SDK dep of
 * POKETRADE_SAVE_ResetClactAndBeginEvent's case-5/6 arms.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00906.h"

typedef unsigned char u8;

extern int GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmPaused(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);

void POKETRADE_SAVE_PopBgmFadeIn60(void *p)
{
    u8 *b = p;

    if (((struct Obj00906 *)b)->f11F8 != 0) {
        GFL_USE_PopBgm();
        ((struct Obj00906 *)b)->f11F8 -= 1;
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}
