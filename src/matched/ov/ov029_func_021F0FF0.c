/*
 * function: C_GEAR_StopFade
 * address: 0x021F0FF0
 * packet: pkt_ov029_021F0FF0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: followed by existing C_GEAR_GetFadeRequestBits.c.
 * symbols:
 *   PALANM_ForceStopFade 0x02021B18 thumb
 */
#include "../include/Obj20390.h"
struct Obj02021B18;
extern void PALANM_ForceStopFade(struct Obj02021B18 *o);
void C_GEAR_StopFade(char *p)
{
    PALANM_ForceStopFade(((struct Obj20390 *)p)->f210);
}
