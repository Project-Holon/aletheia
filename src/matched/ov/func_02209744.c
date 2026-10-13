/*
 * function: BTLV_TIMER_TickTask
 * address:  0x02209744
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_TIMER_TickTask   0x02209744  thumb
 *   BTLV_TIMER_Redraw 0x02209540 thumb ov094

 *
 * lane O10 candidate
 */

struct Timer;
extern void BTLV_TIMER_Redraw(struct Timer *p, int idx);

void BTLV_TIMER_TickTask(int unused, int x)
{
    BTLV_TIMER_Redraw((struct Timer *)x, 0);
    BTLV_TIMER_Redraw((struct Timer *)x, 1);
}

