/*
 * function: EVENT_FIELD_PROCLINK_GetReturnPendingSlot
 * address: 0x0216202C
 * packet: pkt_ov010_0216202C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub 0x021622D8 thumb ov010
 */
#include "../include/Obj18949.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern int EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub(char *, void *);
int EVENT_FIELD_PROCLINK_GetReturnPendingSlot(char *p, void *out, u8 *index)
{
    *index = ((struct Obj18949 *)p)->f4;
    return EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub(p, out);
}
