/*
 * function: GTSNEGO_MSG_SetIconYClamped
 * address: 0x021D7374
 * packet: pkt_ov120_021D7374
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   GTSNEGO_MSG_GetListRowYF 0x021D72E8 thumb ov120
 */
#include "../include/Obj10400.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Pt { s16 x,y; } Pt;
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int GTSNEGO_MSG_GetListRowYF(void *,int,int);
int GTSNEGO_MSG_SetIconYClamped(char *p,int y,int count) { Pt pt; int result; result=0; if(((struct Obj10400 *)p)->f140) { CLACT_GetActorSurfacePos(((struct Obj10400 *)p)->f140,(struct PtS *)&pt,1); pt.y=y; CLACT_AddActorSurfacePos(((struct Obj10400 *)p)->f140,(const struct Vec2 *)(&pt),1); result=GTSNEGO_MSG_GetListRowYF(p,y,count); } return result; }
