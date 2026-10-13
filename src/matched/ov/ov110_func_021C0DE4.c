/*
 * function: PMS_SELECT_GRAPHIC_StartThumbDrag
 * address: 0x021C0DE4
 * packet: pkt_ov110_021C0DE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 */
#include "../include/Obj10284.h"
typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
int PMS_SELECT_GRAPHIC_StartThumbDrag(char *p) {
    unsigned x,y;
    if(!CLACT_GetActorDrawEnable(((struct Obj10284 *)p)->f8)) return 0;
    if(!TOUCHPANEL_GetPointTrg(&x,&y)) return 0;
    if(x>=240 && x<=247 && y<=159 && y>=8) {
        ((struct Obj10284 *)p)->f99=(((struct Obj10284 *)p)->f99&~1)|1;
        return 1;
    }
    return 0;
}
