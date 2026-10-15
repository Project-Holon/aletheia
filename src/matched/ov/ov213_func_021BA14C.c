/*
 * function: COMM_BTL_DEMO_MAIN_UpdateRowDelay
 * address: 0x021BA14C
 * packet: pkt_ov213_021BA14C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_UpdateActorRow 0x021BA034 thumb ov213
 */
#include "../include/Obj00443.h"
typedef unsigned int   u32;
struct C;
extern void COMM_BTL_DEMO_MAIN_UpdateActorRow(struct C *p, u32 time);
void COMM_BTL_DEMO_MAIN_UpdateRowDelay(char *p,unsigned limit)
{
    if(((struct Obj00443 *)p)->f28) {
        switch(((struct Obj00443 *)p)->f8) {
        case 0:break;
        case 1:limit=12;break;
        case 3:
            if(((struct Obj00443 *)p)->f9==0 || ((struct Obj00443 *)p)->f9==2) limit=15;
            else if(((struct Obj00443 *)p)->f9==1 || ((struct Obj00443 *)p)->f9==3) limit=19;
            break;
        case 2:limit=8;break;
        case 4:
            if(((struct Obj00443 *)p)->f9==0 || ((struct Obj00443 *)p)->f9==2) limit=11;
            else if(((struct Obj00443 *)p)->f9==1 || ((struct Obj00443 *)p)->f9==3) limit=15;
            break;
        }
        if(((struct Obj00443 *)p)->f24>=limit) COMM_BTL_DEMO_MAIN_UpdateActorRow((struct C *)p,limit);
        (((struct Obj00443 *)p)->f24)++;
    }
}
