/*
 * function: BEACON_VIEW_ShowActivePower
 * address: 0x021F1A08
 * packet: pkt_ov032_021F1A08
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_VIEW_StartPowerAnim 0x021F1A28 thumb ov032
 */
#include "../include/Obj20433.h"

typedef unsigned char u8;
extern void BEACON_VIEW_StartPowerAnim(char *p, int b, u8 c, int *r);
void BEACON_VIEW_ShowActivePower(char *p)
{
    BEACON_VIEW_StartPowerAnim(p, ((struct Obj20433 *)p)->f28, 0, (int *)(p + 0xa8));
}
