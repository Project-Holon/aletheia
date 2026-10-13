/*
 * function: EVENT_FIELD_PROCLINK_GetReturnResultSlotSub
 * address: 0x021622AC
 * packet: pkt_ov010_021622AC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj18955.h"
typedef unsigned short u16;
extern void MI_CpuCopy8(void *, void *, unsigned);
int EVENT_FIELD_PROCLINK_GetReturnResultSlotSub(char *p, int index, void *out)
{
    int result = 0;
    if (((struct Obj18955 *)p)->f2 & (1 << (index + 5))) {
        MI_CpuCopy8(p + 0x30 + index * 8, out, 8);
        result = 1;
    }
    return result;
}
