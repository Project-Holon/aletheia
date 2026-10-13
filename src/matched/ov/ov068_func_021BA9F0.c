/*
 * function: OPTION_MENU_RedrawList
 * address:  0x021BA9F0
 * packet:   pkt_ov068_021BA9F0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub after OPTION_MENU_GetListSettings: redraws through
 * OPTION_MENU_DrawList with the stored +0x54 flag.  OPTION_MENU_StateMain passes a second
 * argument (0 or 1) in r1 that this body never reads.
 *
 * symbols:
 *   OPTION_MENU_DrawList  0x021BAA0C  thumb  ov068
 */
#include "../include/Obj00103.h"

typedef unsigned char u8;

extern void OPTION_MENU_DrawList(u8 *p, int flag);

void OPTION_MENU_RedrawList(u8 *p, int unused)
{
    OPTION_MENU_DrawList(p, ((struct Obj00103 *)p)->f54);
}
