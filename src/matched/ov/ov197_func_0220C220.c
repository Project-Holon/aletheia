/*
 * function: func_0220C220
 * address: 0x0220C220
 * packet: pkt_ov197_0220C220
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02020F08 0x02020F08 thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   func_02049B40 0x02049B40 arm
 */
#include "../include/Obj01075.h"
#include "../include/Obj10833.h"
extern unsigned func_02020F08(void);
extern unsigned FILE_UTIL_Get(unsigned,unsigned);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
void func_0220C220(char *p,unsigned item,unsigned slot)
{
    char *q=*(char * *)&((struct Obj01075 *)p)->f0;
    unsigned archive;
    if(((struct Obj10833 *)q)->f8==1) {
        archive=func_02020F08();
        func_02049B40(archive,FILE_UTIL_Get(item,4),5,slot*32,32,((struct Obj10833 *)q)->fC);
    } else {
        archive=func_02020F08();
        func_02049B40(archive,FILE_UTIL_Get(item,2),5,slot*32,32,((struct Obj10833 *)q)->fC);
    }
}
