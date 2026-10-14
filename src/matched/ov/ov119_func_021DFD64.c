/*
 * function: POKETRADE_SAVE_PopBgm
 * address:  0x021DFD64
 * packet:   pkt_ov119_021DFD64
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 */
#include "../include/Obj22749.h"

typedef unsigned char u8;

extern int GFL_USE_PopBgm(void);

void POKETRADE_SAVE_PopBgm(void *p)
{
    u8 *b = p;

    GFL_USE_PopBgm();
    ((struct Obj22749 *)b)->f11F8 -= 1;
}
