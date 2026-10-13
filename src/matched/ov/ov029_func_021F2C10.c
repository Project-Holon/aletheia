/*
 * function: C_GEAR_StepIconAnim
 * address:  0x021F2C10
 * packet:   pkt_ov029_021F2C10
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 */
#include "../include/Obj06130.h"

struct Obj;
extern void func_0204B92C(struct Obj *a, unsigned int b);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

int C_GEAR_StepIconAnim(char *p)
{
    switch (((struct Obj06130 *)p)->f455) {
    case 0:
        func_0204B92C((struct Obj *)*(int *)(p + ((struct Obj06130 *)p)->f416 * 4 + 0x12c), 1);
        CLACT_SetActorAutoAnimSpeed((struct Actor *)(*(int *)(p + ((struct Obj06130 *)p)->f416 * 4 + 0x12c)), 1 << 13);
        ((struct Obj06130 *)p)->f455 += 1;
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct Actor *)(*(int *)(p + ((struct Obj06130 *)p)->f416 * 4 + 0x12c))) == 0)
            return 1;
        break;
    }
    return 0;
}
