/*
 * function: BTLV_EFFECT_TimerStart
 * address:  0x021F84E8
 * packet:   pkt_ov094_021F84E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_TIMER_Start with the handle at 0x1b0 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_TIMER_Start 0x02209318 thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_TIMER_Start(void *, int, int);

void BTLV_EFFECT_TimerStart(int a, int b)
{
    BTLV_TIMER_Start(*(void **)(gBtlvEff + 0x1b0), a, b);
}
