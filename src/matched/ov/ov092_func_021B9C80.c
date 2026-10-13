/*
 * function: EVENT_BATTLE_RETURN_GetBurmyForm
 * address: 0x021B9C80
 * packet: pkt_ov092_021B9C80
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: named record pointer schedules base-plus-index before the second index load.
 * symbols:
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_020307B0 0x020307B0 arm
 * Prototype width: incoming heap value forwarded without truncation; widen legacy u16.
 */
#include "../include/Obj13264.h"
typedef unsigned int u32;
typedef unsigned char u8;
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
u32 EVENT_BATTLE_RETURN_GetBurmyForm(u32 p, u32 heap)
{
    void *data;
    u32 result;
    u8 *record;
    data = ARC_TOOL_LoadMember(0x98, 0, heap);
    record = (u8 *)data + ((struct Obj13264 *)p)->f0 * 0x24;
    result = *(record + ((struct Obj13264 *)p)->f4 + 0x13);
    func_020307B0(data);
    return result;
}
