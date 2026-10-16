/*
 * function: MICTEST_RunStepMachine
 * address:  0x02183D1C
 * packet:   pkt_02183D1C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MICTEST_IsStepDone  0x02183D40  thumb  ov168
 */

typedef void (*fn_02183D1C)(int *, int *);

extern int MICTEST_IsStepDone(unsigned int *p);

void MICTEST_RunStepMachine(int *p)
{
    if (MICTEST_IsStepDone((unsigned int *)p) == 0)
        ((fn_02183D1C)(*(void **)((char *)p + 4)))(p, (int *)((char *)p + 8));
}
