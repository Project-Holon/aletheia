/*
 * function: func_021D8B98
 * address: 0x021D8B98
 * packet: pkt_ov129_021D8B98
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj10499.h"

extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned WIPE_SYS_EndCheck(void);
int func_021D8B98(char *p)  {
    switch(((struct Obj10499 *)p)->f234)  {
        case 0: WIPE_SYS_Start(0,0,0,0,6,1,50);
        ((struct Obj10499 *)p)->f234+=1;
        break;
        case 1: if(WIPE_SYS_EndCheck()==1) ((struct Obj10499 *)p)->f234+=1;
        break;
        default: return 1;
    }
    return 0;
}
