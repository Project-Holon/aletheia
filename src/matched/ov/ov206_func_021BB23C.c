/*
 * function: func_021BB23C
 * address: 0x021BB23C
 * packet: pkt_ov206_021BB23C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   CLACT_SetActorFlip 0x0204B604 arm
 */
#include "../include/Obj00790.h"
typedef struct { short x,y,z,w; } Pos;
extern void MI_CpuFill8(void *,int,int);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
typedef unsigned int   u32;
struct Actor;
struct Node;
struct Personal;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);
void func_021BB23C(char *p,int x,int y,int index)
{
    int flag=0;
    Pos pos;
    if (((struct Obj00790 *)p)->f1C) flag=1;
    MI_CpuFill8(&pos,0,8);
    pos.x=x;
    pos.y=y;
    *(int *)(p+0xac+index*4)=(int)CLACT_CreateActor((void *)((struct Obj00790 *)p)->f24,*(int *)(p+0x94+index*4),*(int *)(p+0x9c+index*4),*(int *)(p+0xa4+index*4),&pos,flag,((struct Obj00790 *)p)->f0);
    CLACT_SetActorDrawPriority((struct Node *)(*(int *)(p+0xac+index*4)),0);
    if(((struct Obj00790 *)p)->f18==2) CLACT_SetActorObjMode((struct Actor *)(*(int *)(p+0xac+index*4)),1);
    if(POKE_PERSONAL_GetParam((const struct Personal *)(((struct Obj00790 *)p)->f26C),34)==0) CLACT_SetActorFlip((struct Actor *)(*(int *)(p+0xac+index*4)),1,1);
}
