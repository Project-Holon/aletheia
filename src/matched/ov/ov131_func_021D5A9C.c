/*
 * function: P_STATUS_SetInputEnable
 * address: 0x021D5A9C
 * packet: pkt_ov131_021D5A9C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   P_STATUS_CanUseButtons 0x021D62E4 thumb ov131
 */
#include "../include/Obj00136.h"
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern int P_STATUS_CanUseButtons(char *p);
void P_STATUS_SetInputEnable(char *p,int a)
{
    *(int *)&((struct Obj00136 *)p)->f44=a;
    if(a==0){
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f178,0);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f17C,0);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f180,0);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f184,0);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f188,0);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f18C,0);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f190,0);
    }else{
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f178,1);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f17C,1);
        if(((struct Obj00136 *)p)->f40==1) CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f180,1);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f188,1);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f18C,1);
        if(P_STATUS_CanUseButtons(p)==1){
            CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f184,1);
            CLACT_SetActorDrawEnable(((struct Obj00136 *)p)->f190,1);
        }
    }
}
