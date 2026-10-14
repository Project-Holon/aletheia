/*
 * function: ZUKAN_DETAIL_GRAPHIC_Init3dSystem
 * address:  0x021BCF58
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera 0x021BD0AC  thumb  ov208
 *
 * Lazy setup: sets the flag at +0x10 and initialises the sub-object at +8.
 * The second argument is only forwarded to ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera, which is why the
 * compiler parks the flag temp in r2 rather than r1.
 */
#include "../include/Obj04613.h"

extern void ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera(char *, int);

void ZUKAN_DETAIL_GRAPHIC_Init3dSystem(char *p, int x)
{
    if (((struct Obj04613 *)p)->f10 == 0) {
        ((struct Obj04613 *)p)->f10 = 1;
        ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera(p + 8, x);
    }
}
