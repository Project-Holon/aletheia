/*
 * function: C_GEAR_StartFadeFx
 * address: 0x021F2E68
 * packet: pkt_ov029_021F2E68
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAutoAnimSpeed 0x0204B954 arm
 */
#include "../include/Obj06131.h"
typedef unsigned int u32;
struct Actor;
struct Obj;
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
void C_GEAR_StartFadeFx(char *p, int value)
{
    CLACT_RestartActorAnim(*(struct Actor * *)&((struct Obj06131 *)p)->f8);
    func_0204B92C(*(struct Obj * *)&((struct Obj06131 *)p)->f8, 1);
    CLACT_SetActorAutoAnimSpeed(*(struct Actor * *)&((struct Obj06131 *)p)->f8, 0x2000);
    ((struct Obj06131 *)p)->f0 = 1;
    ((struct Obj06131 *)p)->f4 = value;
}
