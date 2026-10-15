/*
 * function: STA_NET_GetChunkPtr
 * address: 0x021FD68C
 * packet: pkt_ov132_021FD68C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj14132.h"
#include "../include/Obj23289.h"
typedef unsigned char u8;
void *STA_NET_GetChunkPtr(int a,char *p)
{
    char *q;
    q=*(char * *)&((struct Obj14132 *)p)->f140;
    return *(char * *)&((struct Obj23289 *)q)->f10+((struct Obj14132 *)p)->f14C*0x3800;
}
