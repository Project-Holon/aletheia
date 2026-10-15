/*
 * function: BOX2_SEQ_GrowActor
 * address: 0x021EC9D8
 * packet: pkt_ov170_021EC9D8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 */
#include "../include/Obj04547.h"
struct Obj;
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
int BOX2_SEQ_GrowActor(char *p)
{
    int pair[2];
    ((struct Obj04547 *)p)->f7 -= 2;
    *(float *)(p + 8) += 102.0f;
    *(float *)(p + 8) += 102.0f;
    if ((unsigned char)p[7] == 0)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(((struct Obj04547 *)p)->f0, (struct Pair *)pair);
    return 1;
}
