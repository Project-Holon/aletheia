/*
 * function: EVENT_FIELD_PROCLINK_SetReturnResultSlot
 * address: 0x02162278
 * packet: pkt_ov010_02162278
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj07292.h"
typedef unsigned short u16;
void EVENT_FIELD_PROCLINK_SetReturnResultSlot(char *p, int index, u16 a, u16 b)
{
    *(int *)(p + 0x30 + index * 8) = index;
    *(u16 *)(p + 0x34 + index * 8) = a;
    *(u16 *)(p + 0x36 + index * 8) = b;
    ((struct Obj07292 *)p)->f2 = (u16)(((struct Obj07292 *)p)->f2 | (1 << (index + 5)));
}
