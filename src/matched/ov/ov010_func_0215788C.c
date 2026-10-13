/*
 * function: DELIVERY_BEACON_OnSessionStarted
 * address:  0x0215788C
 * packet:   pkt_ov010_0215788C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call thunk hidden in a .word run; witness for the
 * function pointer taken in DELIVERY_BEACON_Start.
 *
 * symbols:
 *   DELIVERY_BEACON_SetStepAtLine  0x021576C4  thumb  ov010
 *   DELIVERY_BEACON_StepStartScan  0x02157870  thumb  ov010
 */

extern void DELIVERY_BEACON_SetStepAtLine(char *p, int v, int line);
extern void DELIVERY_BEACON_StepStartScan(void *p);

void DELIVERY_BEACON_OnSessionStarted(void *p)
{
    DELIVERY_BEACON_SetStepAtLine(p, (int)DELIVERY_BEACON_StepStartScan, 0x1DD);
}
