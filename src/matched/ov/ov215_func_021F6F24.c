/*
 * function: func_021F6F24
 * address: 0x021F6F24
 * packet: pkt_ov215_021F6F24
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword at 021F6F62 is alignment padding.
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 */
#include "../include/Obj06708.h"
#include "../include/Obj14714.h"
struct Arg;
extern unsigned func_02048A18(unsigned char *,int);
extern void func_02047A60(void *,struct Arg *);
void func_021F6F24(char *p)
{
    unsigned short i;
    for(i=0;i<((struct Obj06708 *)p)->f50;i++) {
        char *entry=*(char * *)&((struct Obj06708 *)p)->f54+i*0x44;
        if(((struct Obj14714 *)entry)->f40)
            func_02047A60((void *)func_02048A18(*(unsigned char * *)&((struct Obj06708 *)p)->f48,((struct Obj14714 *)entry)->f0),(struct Arg *)(entry+4));
    }
}
