/*
 * function: BR_PROC_SYS_GetSlotId
 * address: 0x021F9B9C
 * packet: pkt_ov186_021F9B9C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker of ov183 021DB2E0; parent cleared ownership.
 */
#include "../include/Obj24810.h"
unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p)
{
    return p->f10;
}
