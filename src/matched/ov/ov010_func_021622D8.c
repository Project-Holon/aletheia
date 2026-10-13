/*
 * function: EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub
 * address: 0x021622D8
 * packet: pkt_ov010_021622D8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj18956.h"
typedef unsigned short u16;
extern void MI_CpuCopy8(void *, void *, unsigned);
int EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub(char *p, void *out)
{
    int result = 0;
    if (((struct Obj18956 *)p)->f2 & 16) {
        MI_CpuCopy8(p + 0x28, out, 8);
        result = 1;
    }
    return result;
}
