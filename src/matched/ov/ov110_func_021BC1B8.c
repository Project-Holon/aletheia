/*
 * function: PMSIV_EDIT_CreateCursors
 * address: 0x021BC1B8
 * packet: pkt_ov110_021BC1B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * lever: coordinate arguments are int; the callee stores low halfwords
 * without caller-side narrowing, including y+192.
 * symbols:
 *   PMSIV_EDIT_BoxOriginToSlotPos 0x021BC578 thumb ov110
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   PMSIV_EDIT_SetCursorPressed 0x021BC69C thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 */
#include "../include/Obj01393.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { int a,b,c; } Triple;
typedef struct { s16 x,y; } Pair;
extern void PMSIV_EDIT_BoxOriginToSlotPos(const s16 *a, s16 *b);
extern void PMS_INPUT_VIEW_GetUiRes(void *,Triple *,int,int);
extern void *PMS_INPUT_VIEW_CreateActor(void *,Triple *,int,int,int,int);
struct Obj;
extern void PMSIV_EDIT_SetCursorPressed(u8 *p, int flag);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorBgPriority(void *,int);
void PMSIV_EDIT_CreateCursors(u8 *p)
{
    Triple t;
    Pair pos;
    if (*(int *)&((struct Obj01393 *)p)->f44) PMSIV_EDIT_BoxOriginToSlotPos((const s16 *)(p+0x38),(s16 *)(&pos));
    else { pos.x=128; pos.y=24; }
    PMS_INPUT_VIEW_GetUiRes(((struct Obj01393 *)p)->f0,&t,1,0);
    ((struct Obj01393 *)p)->f18=PMS_INPUT_VIEW_CreateActor(((struct Obj01393 *)p)->f0,&t,pos.x,pos.y+192,0,2);
    CLACT_SetActorAnimSeq(((struct Obj01393 *)p)->f18,1);
    CLACT_SetActorBgPriority(((struct Obj01393 *)p)->f18,1);
    PMS_INPUT_VIEW_GetUiRes(((struct Obj01393 *)p)->f0,&t,0,0);
    ((struct Obj01393 *)p)->f14=PMS_INPUT_VIEW_CreateActor(((struct Obj01393 *)p)->f0,&t,pos.x,pos.y,0,1);
    PMSIV_EDIT_SetCursorPressed(p,1);
}
