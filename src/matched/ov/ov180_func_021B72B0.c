/*
 * function: HALL_OF_FAME_ApplyJitterStep
 * address: 0x021B72B0
 * packet: pkt_ov180_021B72B0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HALL_OF_FAME_MoveActorBy 0x021B73E4 thumb ov180
 */
#include "../include/Obj03876.h"
extern void HALL_OF_FAME_MoveActorBy(char *,int,short,short);
int HALL_OF_FAME_ApplyJitterStep(char *p,int i) {
    if(((struct Obj03876 *)p)->f915F==8) {
        HALL_OF_FAME_MoveActorBy(p,i,((struct Obj03876 *)p)->f9160,((struct Obj03876 *)p)->f9162);
        return 0;
    }
    HALL_OF_FAME_MoveActorBy(p,i,((struct Obj03876 *)p)->f9160+*(short *)(p+0x9164+((struct Obj03876 *)p)->f915F*2),((struct Obj03876 *)p)->f9162+*(short *)(p+0x9174+((struct Obj03876 *)p)->f915F*2));
    (((struct Obj03876 *)p)->f915F)++;
    return 1;
}
