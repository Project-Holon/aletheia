/*
 * function: SHINKA_DEMO_ClearPartyValue
 * address:  0x02205844
 * packet:   pkt_02205844
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 */
#include "../include/Obj24950.h"

typedef unsigned int   u32;
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);

void SHINKA_DEMO_ClearPartyValue(int a, char *b)
{
    POKE_TOOL_SetPartyValue((void *)(((struct Obj24950 *)b)->f10), 6, 0);
}
