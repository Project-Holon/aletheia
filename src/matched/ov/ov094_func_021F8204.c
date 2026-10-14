/*
 * function: BTLV_EFFECT_GaugeIsSlotOccupied
 * address: 0x021F8204
 * packet: pkt_ov094_021F8204
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_GAUGE_IsSlotOccupied 0x02207D60 thumb ov094
 *   gBtlvEff 0x0220AF20 data a4
 */

#include "../include/G_0220AF20.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern int BTLV_GAUGE_IsSlotOccupied(u8 *, int);
extern struct G_0220AF20 *gBtlvEff;
int BTLV_EFFECT_GaugeIsSlotOccupied(int index)
{
    return BTLV_GAUGE_IsSlotOccupied(*(u8 **)(((u8 *)gBtlvEff) + 0x1a4), index);
}
