/*
 * function: MICTEST_StepWaitAnim
 * address:  0x02183E18
 * packet:   pkt_02183E18
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MICTEST_GetOwner   0x02183D3C  thumb
 *   MICTEST_SetStep   0x02183D34  thumb
 *   MICTEST_StepWipeOut   0x02183E60  thumb
 *   CLACT_SetActorAnimSeq   0x0204B878  arm
 *   CLACT_IsActorAnimActive   0x0204B98C  arm
 *
 * Three-state step over the object at *(x+0xC): start on 0, poll on 1,
 *   install 0x2183E60 on 2.
 */
#include "../include/Obj14259.h"


typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern unsigned int MICTEST_GetOwner(unsigned int *p);
extern void MICTEST_SetStep(unsigned int *p, unsigned int v);
extern void MICTEST_StepWipeOut(int a, int *state);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

void MICTEST_StepWaitAnim(int a, int *state)
{
    int x = MICTEST_GetOwner((unsigned int *)a);
    switch (*state) {
    case 0:
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj14259 *)x)->fC), 1);
        *state = 1;
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct Actor *)(((struct Obj14259 *)x)->fC)) == 0)
            *state = 2;
        break;
    case 2:
        MICTEST_SetStep((unsigned int *)a, (unsigned int)MICTEST_StepWipeOut);
        break;
    }
}
