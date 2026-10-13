/*
 * function: func_021E0C04
 * address: 0x021E0C04
 * packet: pkt_ov183_021E0C04
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller evidence: 0204B294 leaves its forwarded return word live in r0; consumed by store and 0204B688 here.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj00143.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef short s16;
struct Params {s16 x,y,a,b,z;u8 mode,flag;};
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
struct Actor;
struct Vec2;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021E0C04(char *p) {
    struct Params pos;
    u32 manager=*(u32 *)&((struct Obj00143 *)p)->f25C;
    pos.a=0;pos.b=0;pos.z=0;pos.mode=10;pos.flag=0;
    *(u32 *)&((struct Obj00143 *)p)->f1E8=(u32)CLACT_CreateActor((void *)manager,((struct Obj00143 *)p)->f270,((struct Obj00143 *)p)->f264,((struct Obj00143 *)p)->f288,&pos.a,1,((struct Obj00143 *)p)->f34C);
    CLACT_SetActorObjMode(((struct Obj00143 *)p)->f1E8,1);
    pos.z=1;
    *(u32 *)&((struct Obj00143 *)p)->f204=(u32)CLACT_CreateActor((void *)manager,((struct Obj00143 *)p)->f270,((struct Obj00143 *)p)->f264,((struct Obj00143 *)p)->f288,&pos.a,1,((struct Obj00143 *)p)->f34C);
    CLACT_SetActorObjMode(((struct Obj00143 *)p)->f204,1);
    pos.x=((struct Obj00143 *)p)->f2F2;pos.y=((struct Obj00143 *)p)->f2F0+16;
    CLACT_AddActorSurfacePos(((struct Obj00143 *)p)->f1E8,(const struct Vec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(((struct Obj00143 *)p)->f1E8,0);
    pos.x=((struct Obj00143 *)p)->f2F6;pos.y=((struct Obj00143 *)p)->f2F4+16;
    CLACT_AddActorSurfacePos(((struct Obj00143 *)p)->f204,(const struct Vec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(((struct Obj00143 *)p)->f204,1);
}
