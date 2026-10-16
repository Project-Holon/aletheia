/*
 * function: MICTEST_StepWipeOut
 * address:  0x02183E60
 * packet:   pkt_02183E60
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
 *   MICTEST_StepFinish   0x02183EC0  thumb
 *   WIPE_SYS_Start   0x0202208C  thumb
 *   WIPE_SYS_EndCheck   0x020221A4  thumb
 *
 * Step a two-slot state machine: publish through WIPE_SYS_Start on state 0,
 *   poll WIPE_SYS_EndCheck on 1, install MICTEST_StepFinish on 2.
 */
#include "../include/Obj23818.h"


extern unsigned int MICTEST_GetOwner(unsigned int *p);
extern void MICTEST_SetStep(unsigned int *p, unsigned int v);
typedef unsigned int   u32;
extern void MICTEST_StepFinish(int *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);

void MICTEST_StepWipeOut(int a, int *state)
{
    int x = MICTEST_GetOwner((unsigned int *)a);
    switch (*state) {
    case 0:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((struct Obj23818 *)x)->f14C);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck())
            *state = 2;
        break;
    case 2:
        MICTEST_SetStep((unsigned int *)a, (unsigned int)MICTEST_StepFinish);
        break;
    }
}
