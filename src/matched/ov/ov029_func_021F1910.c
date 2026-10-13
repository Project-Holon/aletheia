/*
 * function: C_GEAR_SetPaintModeIcon
 * address:  0x021F1910
 * packet:   pkt_ov029_021F1910
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 */
#include "../include/Obj00811.h"

extern void CLACT_SetActorAnimIndex(int, int);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);

void C_GEAR_SetPaintModeIcon(char *p, int on)
{
    if (on) {
        CLACT_SetActorAnimIndex(((struct Obj00811 *)p)->f150, 0);
        CLACT_SetActorAutoAnimSpeed((struct Actor *)(((struct Obj00811 *)p)->f150), 0x2000);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00811 *)p)->f150, 1);
    } else {
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00811 *)p)->f150, 0);
        CLACT_SetActorAnimIndex(((struct Obj00811 *)p)->f150, 1);
    }
}
