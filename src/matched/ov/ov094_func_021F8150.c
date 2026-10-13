/*
 * function: func_021F8150
 * address: 0x021F8150
 * packet: pkt_ov094_021F8150
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_GAUGE_RefreshForLevelUp 0x02207BAC thumb ov094
 *   d_0220AF20 0x0220AF20 data a4
 */

#include "../include/G_0220AF20.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void BTLV_GAUGE_RefreshForLevelUp(void *, void *, int);
extern struct G_0220AF20 *d_0220AF20;
void func_021F8150(int index, void *obj)
{
    BTLV_GAUGE_RefreshForLevelUp(*(void **)(((u8 *)d_0220AF20) + 0x1a4), obj, index);
}
