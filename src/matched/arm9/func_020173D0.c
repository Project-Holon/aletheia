/*
 * function: POKE_TOOL_InitSystem
 * address:  0x020173D0
 * packet:   pkt_020173D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gPersonalCache      0x02146270  data
 *   POKE_PERSONAL_OpenHandle  0x0201AD88  thumb
 */

#include "../include/G_Memo.h"

typedef unsigned int u32;

extern void POKE_PERSONAL_OpenHandle(u32 heap);
extern struct Memo gPersonalCache;
void POKE_TOOL_InitSystem(u32 heap)
{
    POKE_PERSONAL_OpenHandle(heap);
    *(unsigned short *)(((unsigned char *)&gPersonalCache) + 2) = 0x28b;
}
