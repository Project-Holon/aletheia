/*
 * function: POKETRADE_2D_DeleteSummaryIcons
 * address: 0x021E625C
 * packet: pkt_ov119_021E625C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 */
#include "../include/Obj13925.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);

void POKETRADE_2D_DeleteSummaryIcons(void *p)
{
    char *q = (char *)p + 0x98c;
    int i;
    for (i = 0; i < 8; i++) {
        if (*(int *)(q + i * 4 + 0x14)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(q + i * 4 + 0x14)));
            *(int *)(q + i * 4 + 0x14) = 0;
        }
    }
    if (((struct Obj13925 *)q)->f10) {
        UI_SCENE_FreeActorGfx((unsigned int *)q);
        ((struct Obj13925 *)q)->f10 = 0;
    }
}
