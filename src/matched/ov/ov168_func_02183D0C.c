/*
 * function: MICTEST_InitStepMachine
 * address:  0x02183D0C
 * packet:   pkt_02183D0C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MICTEST_SetStep  0x02183D34  thumb  ov168
 */
#include "../include/Obj14257.h"

extern void MICTEST_SetStep(unsigned int *p, unsigned int v);

void MICTEST_InitStepMachine(int *p, int a, int b)
{
    *p = a;
    ((struct Obj14257 *)p)->fC = 0;
    MICTEST_SetStep((unsigned int *)p, b);
}
