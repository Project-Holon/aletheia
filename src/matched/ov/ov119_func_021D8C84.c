/*
 * function: POKETRADE_PROC_ShowDragIcon
 * address: 0x021D8C84
 * packet: pkt_ov119_021D8C84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_PROC_ClearDragIcon 0x021D8C6C thumb ov119
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
struct Node;
struct Obj;
struct Vec2;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void POKETRADE_PROC_ClearDragIcon(void *);
extern void MI_CpuFill8(void *,int,int);
void POKETRADE_PROC_ShowDragIcon(void *p) {
 if(((struct Obj00001 *)p)->fF60!=0) {
 CLACT_SetActorDrawPriority((struct Node *)(((struct Obj00001 *)p)->fF60),16);
 CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00001 *)p)->fF60),(const struct Vec2 *)((char *)p+0xf64),1);
 CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00001 *)p)->fF60,1);
 ((struct Obj00001 *)p)->fF7C=-1;
 ((struct Obj00001 *)p)->fF80=-1;
 POKETRADE_PROC_ClearDragIcon(p); MI_CpuFill8((char *)p+4,0,2);
 }
}
