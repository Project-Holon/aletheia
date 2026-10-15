/*
 * function: MUSICAL_MCSS_SetRenderAnim
 * address: 0x021F53CC
 * packet: pkt_ov112_021F53CC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_SetMCAnim 0x021F62B0 thumb ov112
 */
#include "../include/Obj22540.h"
typedef unsigned int u32;
extern void MUSICAL_MCSS_SetMCAnim(char *, u32);
void MUSICAL_MCSS_SetRenderAnim(int a, u32 n)
{
    MUSICAL_MCSS_SetMCAnim(*(char * *)&((struct Obj22540 *)a)->f8, n);
}
