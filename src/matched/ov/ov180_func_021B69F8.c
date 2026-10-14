/*
 * function: HALL_OF_FAME_StartMonAnimCallback
 * address:  0x021B69F8
 * packet:   pkt_ov180_021B69F8
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05: the callee MCSS_SetAnimCallback takes four arguments; the caller passes a literal 0 as the fourth, which also feeds the store, so the call is a real bl.
 *
 * symbols:
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   HALL_OF_FAME_OnMonAnimDone  0x021B69E8  thumb  ov180
 */

extern void MCSS_SetAnimCallback(int, void *, void *, int);
extern void HALL_OF_FAME_OnMonAnimDone(int *p);

void HALL_OF_FAME_StartMonAnimCallback(char *p)
{
    *(int *)(p + 0x24) = 0;
    MCSS_SetAnimCallback(*(int *)(p + 0x1c), p, (void *)HALL_OF_FAME_OnMonAnimDone, 0);
}
