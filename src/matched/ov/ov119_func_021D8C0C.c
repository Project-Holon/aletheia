/*
 * function: func_021D8C0C
 * address: 0x021D8C0C
 * packet: pkt_ov119_021D8C0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj06422.h"
typedef signed short s16;
extern unsigned int TOUCHPANEL_GetPointCont(unsigned int *outA, unsigned int *outB);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021D8C0C(void *p) {
 int x,y; s16 pos[2];
 if(((struct Obj06422 *)p)->fF60!=0) {
 if(TOUCHPANEL_GetPointCont((unsigned int *)(&x),(unsigned int *)(&y))!=0) {
 CLACT_GetActorSurfacePos((struct Actor *)((struct Obj06422 *)p)->fF60,(struct PtS *)((char *)p+0xf6c),1);
 pos[0]=x+((struct Obj06422 *)p)->fF68;
 pos[1]=y+((struct Obj06422 *)p)->fF6A;
 if(pos[1]>150) pos[1]=150;
 CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj06422 *)p)->fF60),(const struct Vec2 *)pos,1);
 }
 }
}
