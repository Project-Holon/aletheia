/*
 * function: func_021F823C
 * address:  0x021F823C
 * packet:   pkt_ov094_021F823C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   BTLV_B_GAUGE_CreatePartyBallBar  0x02208DAC  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern char *d_0220AF20;
extern u32 BTLV_B_GAUGE_CreatePartyBallBar(u32 *p, u32 v);

void func_021F823C(u32 *p)
{
    u32 r = BTLV_B_GAUGE_CreatePartyBallBar(p, *(u16 *)(d_0220AF20 + 0x1F0));

    *(u32 *)(d_0220AF20 + p[0] * 4 + 0x1A8) = r;
}
