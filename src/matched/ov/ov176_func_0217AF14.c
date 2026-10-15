/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic
 * address:  0x0217AF14
 * packet:   pkt_0217AF14
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_Draw  0x021E5534  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateAnimation  0x021E5980  thumb  ov177
 */
#include "../include/Obj04561.h"

typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *p);
extern void WIFIBATTLEMATCH_VIEW_UpdateAnimation(int);

void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(int *p)
{
    if (((struct Obj04561 *)p)->f24) {
        WIFIBATTLEMATCH_GRAPHIC_Draw((u8 *)(((struct Obj04561 *)p)->f24));
        WIFIBATTLEMATCH_VIEW_UpdateAnimation(((struct Obj04561 *)p)->f20);
    }
}
