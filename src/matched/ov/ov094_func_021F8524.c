/*
 * function: func_021F8524
 * address:  0x021F8524
 * packet:   pkt_ov094_021F8524
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3: the work record at +0x1B0 of d_0220AF20 and the argument. Labelled in wave D8.
 *
 * symbols:
 *   BTLV_TIMER_IsExpired  0x02209500  thumb ov094
 *   d_0220AF20     0x0220AF20  data ov094
 */

struct W;
extern char *d_0220AF20;
extern int BTLV_TIMER_IsExpired(struct W *w, int i);

int func_021F8524(int i)
{
    return BTLV_TIMER_IsExpired(*(struct W **)(d_0220AF20 + 0x1B0), i);
}
