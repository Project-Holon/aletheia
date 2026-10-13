/*
 * function: PMSIV_WORDWIN_SetVisible
 * address: 0x021BFC20
 * packet: pkt_ov110_021BFC20
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   PMS_INPUT_GetListItemCount 0x021BF734 thumb ov110
 */
#include "../include/Obj04452.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern unsigned PMS_INPUT_GetListItemCount(u8 *);
void PMSIV_WORDWIN_SetVisible(u8 *p, unsigned visible) {
    if (visible) {
        if (**(unsigned * *)&((struct Obj04452 *)p)->f9C==0) CLACT_SetActorDrawEnable(((struct Obj04452 *)p)->f14,1);
        else CLACT_SetActorDrawEnable(((struct Obj04452 *)p)->f14,0);
        CLACT_SetActorDrawEnable(((struct Obj04452 *)p)->f1C, PMS_INPUT_GetListItemCount(*(u8 * *)&((struct Obj04452 *)p)->f4)>14 ? 1 : 0);
    } else {
        CLACT_SetActorDrawEnable(((struct Obj04452 *)p)->f14,visible);
        CLACT_SetActorDrawEnable(((struct Obj04452 *)p)->f1C,0);
    }
}
