/*
 * function: EVENT_FIELD_PROCLINK_GetReturnSlot
 * address: 0x02162254
 * packet: pkt_ov010_02162254
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj18954.h"
typedef unsigned short u16;
extern void MI_CpuCopy8(void *, void *, unsigned);
int EVENT_FIELD_PROCLINK_GetReturnSlot(char *p, u16 index, u16 *out)
{
    int result = 0;
    if (((struct Obj18954 *)p)->f2 & (1 << index)) {
        MI_CpuCopy8(p + 8 + index * 8, out, 8);
        result = 1;
    }
    return result;
}
