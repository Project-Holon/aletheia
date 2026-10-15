/*
 * function: COMM_BTL_DEMO_MAIN_UpdateNetKind
 * address: 0x021BA514
 * packet: pkt_ov213_021BA514
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetGameKind 0x0203D5D4 arm
 *   COMM_BTL_DEMO_MAIN_SetActorAnimKind 0x021BA4BC thumb ov213
 * prototype: caller loads r0 net object before D5D4; retained visible input despite callee's void parameter list.
 */
#include "../include/Obj03939.h"
#include "../include/Obj25704.h"
#include "../include/Obj25705.h"
#include "../include/Obj25706.h"
#include "../include/Obj25707.h"
#include "../include/Obj25708.h"
typedef unsigned int   u32;
extern u32 GFL_NET_GetGameKind(void);
extern void COMM_BTL_DEMO_MAIN_SetActorAnimKind(void *,int,int);
void COMM_BTL_DEMO_MAIN_UpdateNetKind(char *p)
{
    if(((struct Obj25704 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54) {
        switch((int)GFL_NET_GetGameKind()) {
        case 37:case 12:case 31:COMM_BTL_DEMO_MAIN_SetActorAnimKind(((struct Obj25706 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,37,((struct Obj03939 *)p)->f49CC);break;
        case 10:COMM_BTL_DEMO_MAIN_SetActorAnimKind(((struct Obj25707 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,17,((struct Obj03939 *)p)->f49CC);break;
        case 20:case 21:case 23:case 24:case 25:case 26:
            COMM_BTL_DEMO_MAIN_SetActorAnimKind(((struct Obj25708 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,13,((struct Obj03939 *)p)->f49CC);break;
        }
    }
}
