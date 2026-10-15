/*
 * function: POKETRADE_2D_CreateFontResource
 * address:  0x021E3FE4
 * packet:   pkt_ov119_021E3FE4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb
 */
#include "../include/Obj13916.h"

extern void *BMP_MENUWORK_LoadFrameGfx(void *, unsigned, unsigned, unsigned);

void POKETRADE_2D_CreateFontResource(char *p)
{
    ((struct Obj13916 *)p)->f644 = BMP_MENUWORK_LoadFrameGfx((void *)6, 15, 0, ((struct Obj13916 *)p)->f5F4);
}
