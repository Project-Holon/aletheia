/*
 * function: BOX2_SEQ_ResetActorAffine
 * address: 0x021EC94C
 * packet: pkt_ov170_021EC94C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ffix 0x0209C494 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAffineOrigin 0x0204B588 arm
 */
#include "../include/Obj04546.h"
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
struct Obj;
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
struct Pt;
extern void CLACT_SetActorAffineOrigin(struct Actor *actor, const struct Pt *src);
void BOX2_SEQ_ResetActorAffine(char *p)
{
    int pair[2];
    unsigned short shape[2];
    *(float *)(p + 8) = 4096.0f;
    p[7] = 0;
    CLACT_SetActorAffineMode(((struct Obj04546 *)p)->f0, 1);
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(((struct Obj04546 *)p)->f0, (struct Pair *)pair);
    shape[0] = 0;
    shape[1] = 8;
    CLACT_SetActorAffineOrigin(((struct Obj04546 *)p)->f0, (const struct Pt *)shape);
}
