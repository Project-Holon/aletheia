/*
 * function: PLIST_DEMO_CanUseGracidea
 * address:  0x021BDCC0
 * packet:   pkt_ov091_021BDCC0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   TIMEZONE_GetZoneLightLevel  0x02011400  thumb
 *   GF_STANDARD_GetCachedTime  0x0203F4CC  arm
 */
#include "../include/Obj00009.h"
#include "../include/Obj20929.h"
#include "../include/Obj20930.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_GetStatusCondition(void *p);
extern u8 TIMEZONE_GetZoneLightLevel(int row, int col);
struct RtcTime;
extern void GF_STANDARD_GetCachedTime(struct RtcTime *time);

int PLIST_DEMO_CanUseGracidea(char *p, u32 a1)
{
    u32 t[3];
    u32 lo, hi;
    int r = 0;
    if (POKE_TOOL_GetPartyValue(((struct Obj00009 *)p)->f38, 5, 0) != 0x1EC)
        return r;
    if (POKE_TOOL_GetPartyValue(((struct Obj00009 *)p)->f38, 0x6F, r) != 0)
        return r;
    if (POKE_TOOL_GetPartyValue(((struct Obj00009 *)p)->f38, 0x6D, r) != 1)
        return r;
    if (POKE_TOOL_GetStatusCondition(((struct Obj00009 *)p)->f38) & 0x20)
        return r;
    lo = TIMEZONE_GetZoneLightLevel(((struct Obj20929 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f5F, r);
    hi = TIMEZONE_GetZoneLightLevel(((struct Obj20930 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f5F, 3);
    GF_STANDARD_GetCachedTime((struct RtcTime *)t);
    if (t[0] < lo || t[0] >= hi)
        return 0;
    return 1;
}
