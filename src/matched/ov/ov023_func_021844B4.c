/*
 * function: OEKAKI_RecvCanvasDone
 * address: 0x021844B4
 * packet: pkt_ov023_021844B4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   OEKAKI_HandleEvent 0x02185AB0 thumb ov023
 */
#include "../include/Obj20341.h"
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void OEKAKI_HandleEvent(char *p, int msg, int arg);
void OEKAKI_RecvCanvasDone(int a, int b, int c, char *p)
{
    ((struct Obj20341 *)p)->f928A = 1;
    if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
        OEKAKI_HandleEvent(p, 0x12, 0);
}
