/*
 * function: SODATEYA_AddStep
 * address:  0x021C3378
 * packet:   pkt_ov021_021C3378
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Advances the timer; on completion stops it and closes the record.
 *
 * symbols:
 *   DAYCARE_AddSteps  0x0200BD48  thumb
 *   SODATEYA_UpdateStepCounter  0x021C385C  thumb  ov021
 *   DAYCARE_SetEggReady  0x0200BC10  thumb
 *   SODATEYA_SetEggFlag  0x021C33A4  thumb  ov021
 */

extern void DAYCARE_AddSteps(void *a, int b);
extern int SODATEYA_UpdateStepCounter(void **p);
struct Obj06851;
extern void DAYCARE_SetEggReady(struct Obj06851 *p);
extern void SODATEYA_SetEggFlag(void *a);

int SODATEYA_AddStep(void **p)
{
    DAYCARE_AddSteps(p[2], 1);
    if (SODATEYA_UpdateStepCounter(p) == 1) {
        DAYCARE_SetEggReady(p[2]);
        SODATEYA_SetEggFlag(p[1]);
        return 1;
    }
    return 0;
}
