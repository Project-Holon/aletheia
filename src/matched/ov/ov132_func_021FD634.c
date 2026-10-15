/*
 * function: STA_NET_AdvanceChunk
 * address: 0x021FD634
 * packet: pkt_ov132_021FD634
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj04521.h"
#include "../include/Obj05408.h"
#include "../include/Obj10567.h"
typedef unsigned char u8;
typedef unsigned int u32;
void STA_NET_AdvanceChunk(int a,int b,int c,char *p)
{
    char *q;
    char *s;
    u32 v;
    (((struct Obj05408 *)p)->f14C)++;
    ((struct Obj05408 *)p)->f154=0;
    q=*(char * *)&((struct Obj05408 *)p)->f140;
    if((u32)(((struct Obj05408 *)p)->f14C*0x3800)>=((struct Obj04521 *)q)->f2C) {
        s=*(char * *)&((struct Obj04521 *)q)->f10;
        ((struct Obj04521 *)q)->f14=s+0xc;
        q=*(char * *)&((struct Obj05408 *)p)->f140;
        ((struct Obj04521 *)q)->f18=*(char * *)&((struct Obj04521 *)q)->f10+0xc+((struct Obj10567 *)s)->f0;
        q=*(char * *)&((struct Obj05408 *)p)->f140;
        v=((struct Obj10567 *)s)->f4;
        ((struct Obj04521 *)q)->f1C=v+(*(u32 *)&((struct Obj04521 *)q)->f10+0xc+((struct Obj10567 *)s)->f0);
    }
}
