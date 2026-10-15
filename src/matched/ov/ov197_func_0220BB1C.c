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
 *   func_0202F114 0x0202F114 thumb
 *   func_0202F138 0x0202F138 thumb
 */
#include "../include/Obj05520.h"
#include "../include/Obj25011.h"
extern unsigned func_0202F114(const unsigned char *,unsigned);
extern unsigned short func_0202F138(unsigned);
void B_BAG_MAIN_BuildOtherList(char *p)
{
    unsigned i;
    for(i=0;i<46;i++) {
        if(func_0202F114(*(const unsigned char * *)&((struct Obj25011 *)(*(char * *)&((struct Obj05520 *)p)->f0))->f10,i)==1) {
            *(unsigned short *)(p+0x150+((struct Obj05520 *)p)->f535*4)=func_0202F138(i);
            *(unsigned short *)(p+0x152+((struct Obj05520 *)p)->f535*4)=1;
            (((struct Obj05520 *)p)->f535)++;
        }
    }
    ((struct Obj05520 *)p)->f539=(((struct Obj05520 *)p)->f535-1)/6;
}
