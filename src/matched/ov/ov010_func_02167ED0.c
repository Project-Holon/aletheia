/*
 * function: BSUBWAY_COMM_RecvWord7
 * address: 0x02167ED0
 * packet: pkt_ov010_02167ED0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj12377.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void BSUBWAY_COMM_RecvWord7(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != GFL_NET_SYSTEM_GetCurrentAid())
        ((struct Obj12377 *)p)->f728 = *c;
}
