/*
 * function: BTLV_EFFECT_TimerIsExpired
 * address:  0x021F8524
 * packet:   pkt_ov094_021F8524
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3: the work record at +0x1B0 of gBtlvEff and the argument. Labelled in wave D8.
 *
 * symbols:
 *   BTLV_TIMER_IsExpired  0x02209500  thumb ov094
 *   gBtlvEff     0x0220AF20  data ov094
 */

struct W;
extern char *gBtlvEff;
extern int BTLV_TIMER_IsExpired(struct W *w, int i);

int BTLV_EFFECT_TimerIsExpired(int i)
{
    return BTLV_TIMER_IsExpired(*(struct W **)(gBtlvEff + 0x1B0), i);
}
