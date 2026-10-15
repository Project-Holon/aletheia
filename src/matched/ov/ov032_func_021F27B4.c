/*
 * function: BEACON_VIEW_RunPowerAnimStart
 * address: 0x021F27B4
 * packet: pkt_ov032_021F27B4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: extent follower 0x021F27CC is already filed separately.
 * symbols:
 *   BEACON_VIEW_UpdatePowerAnimStart 0x021F03EC thumb ov032
 */
#include "../include/Obj00007.h"
typedef unsigned char u8;
extern int BEACON_VIEW_UpdatePowerAnimStart(u8 *);
int BEACON_VIEW_RunPowerAnimStart(u8 *p)
{
    if (BEACON_VIEW_UpdatePowerAnimStart(p) == 0)
        return 4;
    ((struct Obj00007 *)p)->f6C = 0;
    return 0;
}
