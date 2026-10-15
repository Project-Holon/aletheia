/*
 * function: POKETRADE_PROC_RequestBoxRedraw
 * address: 0x021D8B38
 * packet: pkt_ov119_021D8B38
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_RedrawAndSyncGrid 0x021DB7AC thumb ov119
 */
#include "../include/Obj00001.h"
extern void POKETRADE_PROC_RedrawAndSyncGrid(char *,int,int);
void POKETRADE_PROC_RequestBoxRedraw(char *p)
{
    ((struct Obj00001 *)p)->f1080 += 1;
    ((struct Obj00001 *)p)->f1084 = 1;
    POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 0);
}
