/*
 * function: BR_POKESEARCH_HitNext
 * address: 0x021F9048
 * packet: pkt_ov185_021F9048
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * Extent past 021F9088 contains three callback pointers and zero rodata.
 */
#include "../include/Obj24763.h"
extern void BR_UTIL_StartEffect(void *,int,int *);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int BR_POKESEARCH_HitNext(char *p,unsigned x,unsigned y)
{
    int inside=((unsigned)(x-0xb8)<=0x28)&((unsigned)(y-0x40)<=0x28);
    if(inside) {
        int pair[2];
        pair[0]=x;
        pair[1]=y;
        BR_UTIL_StartEffect(((struct Obj24763 *)p)->f3C,1,pair);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return inside;
}
