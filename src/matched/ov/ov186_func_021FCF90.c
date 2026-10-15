/*
 * function: BR_UTIL_ScrollRows
 * address: 0x021FCF90
 * packet: pkt_ov186_021FCF90
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: scroll range update after BR_UTIL_BlitRows.
 */
#include "../include/Obj05503.h"
int BR_UTIL_ScrollRows(char *p,int change)
{
    if(((struct Obj05503 *)p)->f42!=0 && change==-1) {
        ((struct Obj05503 *)p)->f42+=(unsigned short)change;
        return 1;
    }
    if(((struct Obj05503 *)p)->f42+((struct Obj05503 *)p)->f44<((struct Obj05503 *)p)->f4 && change==1) {
        ((struct Obj05503 *)p)->f42+=(unsigned short)change;
        return 1;
    }
    return 0;
}
