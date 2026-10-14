/*
 * function: BTLV_EFFECT_TimerSetVisible
 * address:  0x021F8504
 * packet:   pkt_ov094_021F8504
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094  a4
 *   BTLV_TIMER_SetVisible  0x022094BC  thumb  ov094
 */
typedef unsigned int u32;

extern char *gBtlvEff;
typedef unsigned char  u8;
extern void BTLV_TIMER_SetVisible(u8 *p, int i, int a, int b);

void BTLV_EFFECT_TimerSetVisible(u32 a, u32 b, u32 c)
{
    BTLV_TIMER_SetVisible((u8 *)(*(u32 *)(gBtlvEff + 0x1B0)), a, b, c);
}
