/*
 * function: BEACON_VIEW_RunRecordArrival
 * address: 0x021F26D8
 * packet: pkt_ov032_021F26D8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_VIEW_UpdateRecordArrival 0x021F02C4 thumb ov032
 */
#include "../include/Obj00007.h"
typedef unsigned char u8;
extern int BEACON_VIEW_UpdateRecordArrival(u8 *);
int BEACON_VIEW_RunRecordArrival(u8 *p)
{
    if (BEACON_VIEW_UpdateRecordArrival(p) == 0)
        return 1;
    ((struct Obj00007 *)p)->f6C = 0;
    return 2;
}
