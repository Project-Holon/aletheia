/*
 * function: BSUBWAY_RECORD_LIST_UpdateArrowVisibility
 * address:  0x021BA384
 * packet:   pkt_ov069_021BA384
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj03659.h"

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void BSUBWAY_RECORD_LIST_UpdateArrowVisibility(char *o, int i, int n)
{
    if (n == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f12C, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f130, 0);
    } else if (i == 0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f12C, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f130, 1);
    } else if (i != 0 && i < n - 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f12C, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f130, 1);
    } else if (i == n - 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f12C, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03659 *)o)->f130, 0);
    }
}
