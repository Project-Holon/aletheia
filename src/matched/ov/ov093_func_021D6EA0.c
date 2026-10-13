/*
 * function: BTL_EVENT_ReleaseClientHandle
 * address: 0x021D6EA0
 * packet: pkt_ov093_021D6EA0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 */
#include "../include/Obj00041.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void POKE_TOOL_RecalcParam(void *);
void BTL_EVENT_ReleaseClientHandle(void *p)
{
    POKE_TOOL_RecalcParam(((struct Obj00041 *)p)->f0);
}
