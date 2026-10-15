/*
 * function: DUP_FITTING_UpdatePose
 * address: 0x021B98A0
 * packet: pkt_ov133_021B98A0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_StepPoseRotate 0x021B9990 thumb ov133
 *   DUP_FITTING_StepPoseHold 0x021B9A88 thumb ov133
 *   DUP_FITTING_StepPoseSlide 0x021B9AC0 thumb ov133
 *   DUP_FITTING_ExitPoseMode 0x021B987C thumb ov133
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   DUP_FITTING_UpdateIdle 0x021B75E0 thumb ov133
 *   a1 0x021BA558 data a4
 *   b1 0x021BA560 data a4
 *   a2 0x021BA550 data a4
 *   b2 0x021BA548 data a4
 */
#include "../include/Obj00228.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct {int x,y;} Pair;
typedef struct {s16 x,y;} Pos;
extern const Pair a1,b1,a2,b2;
extern void DUP_FITTING_StepPoseRotate(u8 *,u16,int,u16);
extern void DUP_FITTING_StepPoseHold(unsigned char *p, unsigned int limit);
extern void DUP_FITTING_StepPoseSlide(u8 *,int *,int *,u16);
extern void DUP_FITTING_ExitPoseMode(u8 *);
extern void DUP_FITTING_UpdateIdle(u8 *);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void DUP_FITTING_UpdatePose(u8 *p)
{
    Pair firstA,firstB,secondA,secondB;
    Pos pos;
    switch(p[0x1846]) {
    case 0: break;
    case 1: DUP_FITTING_StepPoseRotate(p,p[0x1847]*4681,p[0x1847]*4681,p[0x1847]*15); break;
    case 2: DUP_FITTING_StepPoseHold(p,30); break;
    case 3: DUP_FITTING_StepPoseRotate(p,-(u16)(p[0x1847]*4681),-(p[0x1847]*4681),p[0x1847]*15); break;
    case 4: DUP_FITTING_StepPoseHold(p,30); break;
    case 5: firstA=a1; firstB=b1; DUP_FITTING_StepPoseSlide(p,&firstA.x,&firstB.x,60); break;
    case 6: DUP_FITTING_StepPoseHold(p,30); break;
    case 7: secondA=a2; secondB=b2; DUP_FITTING_StepPoseSlide(p,&secondA.x,&secondB.x,60); break;
    case 8: DUP_FITTING_StepPoseHold(p,30); break;
    case 9: DUP_FITTING_ExitPoseMode(p); return;
    }
    pos.x=((struct Obj00228 *)p)->f1C; pos.y=((struct Obj00228 *)p)->f20;
    CLACT_AddActorSurfacePos(((struct Obj00228 *)p)->f1854,(const struct Vec2 *)(&pos),0);
    DUP_FITTING_UpdateIdle(p);
}
