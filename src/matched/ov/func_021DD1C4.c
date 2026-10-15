/*
 * function: BOX2_MAIN_SelectBox
 * address:  0x021DD1C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_WrapOffset  0x021DEB14  thumb  ov170
 *   BOX2_UI_HideSlotIcon  0x021EDECC  thumb  ov170
 *   BOX2_UI_SetMiniIconVisible  0x021EE008  thumb  ov170
 *
 * Fold the signed delta into p[0x19] through the wrap helper,
 *   then refresh and re-key the queue.
 */
#include "../include/Obj00000.h"


extern unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);
extern void BOX2_UI_HideSlotIcon(unsigned char *p, int d);
extern void BOX2_UI_SetMiniIconVisible(char *, int, int);
void BOX2_MAIN_SelectBox(char *p, int a)
{
    ((struct Obj00000 *)p)->f19 = BOX2_MAIN_WrapOffset((unsigned char *)p, (signed char)a);
    BOX2_UI_HideSlotIcon((unsigned char *)p, a);
    BOX2_UI_SetMiniIconVisible(p, 0, 0);
}
