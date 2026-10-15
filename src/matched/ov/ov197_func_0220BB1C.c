/*
 * function: B_BAG_MAIN_BuildOtherList
 * address: 0x0220BB1C
 * packet: pkt_ov197_0220BB1C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEM_GFX_IsFlagClear 0x0202F114 thumb
 *   ITEM_GFX_GetItemId 0x0202F138 thumb
 */
#include "../include/Obj05520.h"
#include "../include/Obj25011.h"
extern unsigned ITEM_GFX_IsFlagClear(const unsigned char *,unsigned);
extern unsigned short ITEM_GFX_GetItemId(unsigned);
void B_BAG_MAIN_BuildOtherList(char *p)
{
    unsigned i;
    for(i=0;i<46;i++) {
        if(ITEM_GFX_IsFlagClear(*(const unsigned char * *)&((struct Obj25011 *)(*(char * *)&((struct Obj05520 *)p)->f0))->f10,i)==1) {
            *(unsigned short *)(p+0x150+((struct Obj05520 *)p)->f535*4)=ITEM_GFX_GetItemId(i);
            *(unsigned short *)(p+0x152+((struct Obj05520 *)p)->f535*4)=1;
            (((struct Obj05520 *)p)->f535)++;
        }
    }
    ((struct Obj05520 *)p)->f539=(((struct Obj05520 *)p)->f535-1)/6;
}
