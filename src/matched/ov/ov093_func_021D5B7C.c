/*
 * function: BTL_POKEPARAM_IsAbleToBattle
 * address: 0x021D5B7C
 * packet: pkt_ov093_021D5B7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: follower 021D5BA4 is already filed in pkt_021D5BA4.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 */
#include "../include/Obj00041.h"
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern int BTL_POKEPARAM_IsFainted(void *);
int BTL_POKEPARAM_IsAbleToBattle(void *m)
{
    int ok;
    ok = 0;
    if (POKE_TOOL_GetPartyValue(((struct Obj00041 *)m)->f0, 0x4c, 0)) return ok;
    if (BTL_POKEPARAM_IsFainted(m) == 0) ok = 1;
    return ok;
}
