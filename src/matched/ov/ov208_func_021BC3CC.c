/*
 * function: ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies
 * address: 0x021BC3CC
 * packet: pkt_ov208_021BC3CC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 */
#include "../include/Obj01178.h"
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Blk37;
extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(char *p)
{
    unsigned short old=**(unsigned short * *)&((struct Obj01178 *)p)->f20;
    void *owner=ZUKAN_SAVE_GetFromGameData((void *)(*(int *)&((struct Obj01178 *)p)->f0));
    do {
        ++**(unsigned short * *)&((struct Obj01178 *)p)->f20;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20>=((struct Obj01178 *)p)->f1C)
            **(unsigned short * *)&((struct Obj01178 *)p)->f20=0;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20==old)break;
    }while(ZUKAN_SAVE_IsSeen(owner,(*(unsigned short **)(p+0x18))[**(unsigned short * *)&((struct Obj01178 *)p)->f20])==0);
}
