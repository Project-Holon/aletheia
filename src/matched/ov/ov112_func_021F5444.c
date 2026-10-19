/*
 * function: MUSICAL_MCSS_SetRenderAnimVramBase
 * address: 0x021F5444
 * packet: pkt_ov112_021F5444
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_SetAnimVramBase 0x021F6230 thumb ov112
 */
#include "../include/Obj22542.h"
typedef unsigned char u8;
extern void MUSICAL_MCSS_SetAnimVramBase(u8 *, int);
void MUSICAL_MCSS_SetRenderAnimVramBase(u8 *p, int a)
{
    MUSICAL_MCSS_SetAnimVramBase(*(u8 * *)&((struct Obj22542 *)p)->f4, a);
}
