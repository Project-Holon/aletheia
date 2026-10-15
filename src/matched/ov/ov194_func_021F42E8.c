/*
 * function: NAMEIN_GRAPHIC_UpdateIconTouch
 * address: 0x021F42E8
 * packet: pkt_ov194_021F42E8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   NAMEIN_GRAPHIC_IsPointInRect 0x021F4450 thumb ov194
 *   NAMEIN_GRAPHIC_StartIconAnim 0x021F4394 thumb ov194
 *   NAMEIN_GRAPHIC_StepIconAnim 0x021F43A0 thumb ov194
 */
#include "../include/Obj01576.h"
typedef struct {short x,y;} Vec2;
struct Actor; struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern unsigned TOUCHPANEL_GetPointTrg(unsigned *,unsigned *);
extern int NAMEIN_GRAPHIC_IsPointInRect(int *,int *);
extern void NAMEIN_GRAPHIC_StartIconAnim(unsigned char *p);
extern int NAMEIN_GRAPHIC_StepIconAnim(char *);
void NAMEIN_GRAPHIC_UpdateIconTouch(char *p) {
    int rect[4];
    unsigned x,y;
    Vec2 pos;
    int point[2];
    switch (((struct Obj01576 *)p)->f18) {
    case 0:
        CLACT_GetActorSurfacePos((struct Actor *)((struct Obj01576 *)p)->f0,(struct PtS *)&pos,0);
        ((struct Obj01576 *)p)->f14=0;
        if (TOUCHPANEL_GetPointTrg(&x,&y)) {
            rect[0]=pos.x-16; rect[1]=pos.y-16;
            rect[2]=pos.x+16; rect[3]=pos.y+16;
            point[0]=x; point[1]=y;
            if (NAMEIN_GRAPHIC_IsPointInRect(rect,point)) {
                NAMEIN_GRAPHIC_StartIconAnim((unsigned char *)p);
                ((struct Obj01576 *)p)->f18=1;
            }
        }
        break;
    case 1:
        if (NAMEIN_GRAPHIC_StepIconAnim(p)) {((struct Obj01576 *)p)->f14=1; ((struct Obj01576 *)p)->f18=0;}
        break;
    }
}
