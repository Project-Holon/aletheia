/*
 * function: UN_SELECT_SetActorY
 * address: 0x021BA6BC
 * packet: pkt_ov218_021BA6BC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj03959.h"
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct Actor;struct Obj;typedef struct PtS{s16 x,y;} PtS;extern void CLACT_GetActorSurfacePos(struct Actor *,PtS *,u32);extern void CLACT_AddActorSurfacePos(struct Obj *,const PtS *,u32);
void UN_SELECT_SetActorY(char *p,int y){PtS pos;void *o=((struct Obj03959 *)p)->f240;CLACT_GetActorSurfacePos(o,&pos,65535);pos.y=y;CLACT_AddActorSurfacePos(o,&pos,65535);}
