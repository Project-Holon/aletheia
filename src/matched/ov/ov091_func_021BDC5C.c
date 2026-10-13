/*
 * function: PLIST_DEMO_CheckGiratinaToAltered
 * address:  0x021BDC5C
 * packet:   pkt_ov091_021BDC5C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */
#include "../include/Obj00009.h"

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int PLIST_DEMO_CheckGiratinaToAltered(char *p)
{
    int r = 0;
    if (POKE_TOOL_GetPartyValue(((struct Obj00009 *)p)->f38, 6, 0) == 0x70)
        return 0;
    if (POKE_TOOL_GetPartyValue(((struct Obj00009 *)p)->f38, 5, r) != 0x1E7)
        return 0;
    if (POKE_TOOL_GetPartyValue(((struct Obj00009 *)p)->f38, 0x6F, r) == 1)
        r = 1;
    return r;
}
