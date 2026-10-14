/*
 * function: POKETRADE_SAVE_DeleteStatusIconActor
 * address: 0x021E0E4C
 * packet: pkt_ov119_021E0E4C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 */
#include "../include/Obj08064.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
void POKETRADE_SAVE_DeleteStatusIconActor(char *p)
{
    if (((struct Obj08064 *)p)->f10) {
        CLACT_DeleteActor(((struct Obj08064 *)p)->f10);
        *(int *)&((struct Obj08064 *)p)->f10 = 0;
        UI_SCENE_FreeActorGfx((unsigned int *)p);
    }
}
