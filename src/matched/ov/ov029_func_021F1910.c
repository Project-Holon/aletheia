/*
 * function: func_021F1910
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
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 */
#include "../include/Obj00811.h"

extern void CLACT_SetActorAnimIndex(int, int);
typedef unsigned int   u32;
struct Actor;
extern void func_0204B954(struct Actor *a, u32 v);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);

void func_021F1910(char *p, int on)
{
    if (on) {
        CLACT_SetActorAnimIndex(((struct Obj00811 *)p)->f150, 0);
        func_0204B954((struct Actor *)(((struct Obj00811 *)p)->f150), 0x2000);
        func_0204B92C((struct Obj *)((struct Obj00811 *)p)->f150, 1);
    } else {
        func_0204B92C((struct Obj *)((struct Obj00811 *)p)->f150, 0);
        CLACT_SetActorAnimIndex(((struct Obj00811 *)p)->f150, 1);
    }
}
