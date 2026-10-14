/*
 * function: POKETRADE_2D_DeleteMarkingIcon
 * address: 0x021E5EF8
 * packet: pkt_ov119_021E5EF8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 */
#include "../include/Obj10382.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);

void POKETRADE_2D_DeleteMarkingIcon(void *p)
{
    if (((struct Obj10382 *)p)->f10) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj10382 *)p)->f10));
        UI_SCENE_FreeActorGfx(p);
        ((struct Obj10382 *)p)->f10 = 0;
    }
}
