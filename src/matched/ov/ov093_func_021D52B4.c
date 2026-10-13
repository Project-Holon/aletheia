/*
 * function: BTL_POKEPARAM_LoadStats
 * address:  0x021D52B4
 * packet:   pkt_ov093_021D52B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 */
#include "../include/Obj03696.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 POKE_TOOL_GetPartyValue(void *h, u32 k, u32 z);
extern u8 POKE_TOOL_GetGender(void *h);

void BTL_POKEPARAM_LoadStats(u8 *p, void *h, u32 flag)
{
    if (flag) {
        p[0xf8] = POKE_TOOL_GetPartyValue(h, 0xae, 0);
        p[0xf9] = POKE_TOOL_GetPartyValue(h, 0xaf, 0);
    }
    p[0xfa] = POKE_TOOL_GetGender(h);
    ((struct Obj03696 *)p)->fEE = POKE_TOOL_GetPartyValue(h, 0xa2, 0);
    ((struct Obj03696 *)p)->fF0 = POKE_TOOL_GetPartyValue(h, 0xa3, 0);
    ((struct Obj03696 *)p)->fF2 = POKE_TOOL_GetPartyValue(h, 0xa5, 0);
    ((struct Obj03696 *)p)->fF4 = POKE_TOOL_GetPartyValue(h, 0xa6, 0);
    ((struct Obj03696 *)p)->fF6 = POKE_TOOL_GetPartyValue(h, 0xa4, 0);
}
