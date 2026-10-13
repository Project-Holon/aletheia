/*
 * function: OEKAKI_QueueCommand
 * address: 0x02186860
 * packet: pkt_ov023_02186860
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj01674.h"
void OEKAKI_QueueCommand(char *p, int x, int y)
{
    if (((struct Obj01674 *)p)->f9270 == 0) {
        ((struct Obj01674 *)p)->f9270 = x;
        ((struct Obj01674 *)p)->f9274 = y;
    }
}
