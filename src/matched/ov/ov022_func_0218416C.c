/*
 * function: UNION_APP_SetReady
 * address: 0x0218416C
 * packet: pkt_ov022_0218416C
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent followers 0x02184174, 0x0218417C and 0x02184180 are matched separately.
 */
#include "../include/Obj20328.h"
typedef unsigned int u32;
void UNION_APP_SetReady(char *p)
{
    ((struct Obj20328 *)p)->f14 = 1;
}
