/*
 * function: OEKAKI_StepEnterDraw
 * address: 0x021853F0
 * packet: pkt_ov023_021853F0
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword store at 0x021853F8 to 0x04000050.
 * symbols:
 *   OEKAKI_HostOpenGroupLimited 0x02186304 thumb ov023
 *   OEKAKI_SetNextScene 0x02186444 thumb ov023
 *   OEKAKI_ApplyRemoteStrokes 0x02185354 thumb ov023
 */
#include "../include/Obj20348.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void OEKAKI_HostOpenGroupLimited(char *p, int a);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_ApplyRemoteStrokes(char *p);
int OEKAKI_StepEnterDraw(char *p, int result)
{
    *(volatile u16 *)0x04000050 = 0;
    OEKAKI_HostOpenGroupLimited(p, 1);
    OEKAKI_SetNextScene(p, 4);
    OEKAKI_ApplyRemoteStrokes(p);
    ((struct Obj20348 *)p)->f9E7C = 0;
    return result;
}
