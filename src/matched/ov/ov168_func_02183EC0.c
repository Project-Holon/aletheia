/*
 * function: MICTEST_StepFinish
 * address:  0x02183EC0
 * packet:   pkt_02183EC0
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MICTEST_GetOwner  0x02183D3C  thumb  ov168
 *   MICTEST_DeleteSpriteTasks  0x02184818  thumb  ov168
 *   MICTEST_MarkStepDone  0x02183D44  thumb  ov168
 */

extern unsigned int MICTEST_GetOwner(unsigned int *p);
extern void MICTEST_DeleteSpriteTasks(char *p);
extern void MICTEST_MarkStepDone(unsigned int *p);

void MICTEST_StepFinish(int *p)
{
    MICTEST_DeleteSpriteTasks((char *)MICTEST_GetOwner((unsigned int *)((int)p)));
    MICTEST_MarkStepDone((unsigned int *)p);
}
