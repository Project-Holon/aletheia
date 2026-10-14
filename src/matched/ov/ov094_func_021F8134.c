/*
 * function: BTLV_EFFECT_GaugeStartExpGain
 * address: 0x021F8134
 * packet: pkt_ov094_021F8134
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_GAUGE_StartExpGain 0x02207B84 thumb ov094
 *   gBtlvEff 0x0220AF20 data a4
 */

#include "../include/G_0220AF20.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void BTLV_GAUGE_StartExpGain(void *, int, u32);
extern struct G_0220AF20 *gBtlvEff;
void BTLV_EFFECT_GaugeStartExpGain(int index, u32 amount)
{
    BTLV_GAUGE_StartExpGain(*(void **)(((u8 *)gBtlvEff) + 0x1a4), index, amount);
}
