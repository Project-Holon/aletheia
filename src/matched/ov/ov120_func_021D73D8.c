/*
 * function: func_021D73D8
 * address: 0x021D73D8
 * packet: pkt_ov120_021D73D8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   func_021D73B0 0x021D73B0 thumb ov120
 */
#include "../include/Obj00625.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x,y,z; u8 a,b; } Record;
typedef struct Callback { u16 n; u8 *p; void (*f)(u8 *); } Callback;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
struct Actor;
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void func_021D73B0(char *p);
void func_021D73D8(u8 *p)
{
    Callback c;
    Record r;
    r.x=128; r.y=52; r.z=27; r.a=2; r.b=1;
    ((struct Obj00625 *)p)->f12C=CLACT_CreateActor((void *)((struct Obj00625 *)p)->f10,((struct Obj00625 *)p)->f2C,((struct Obj00625 *)p)->f1C,((struct Obj00625 *)p)->f78,&r,0,((struct Obj00625 *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct Obj00625 *)p)->f12C,1);
    CLACT_SetActorDrawEnable(((struct Obj00625 *)p)->f12C,1);
    r.z=11; r.a=1;
    ((struct Obj00625 *)p)->f130=CLACT_CreateActor((void *)((struct Obj00625 *)p)->f10,((struct Obj00625 *)p)->f2C,((struct Obj00625 *)p)->f1C,((struct Obj00625 *)p)->f78,&r,0,((struct Obj00625 *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct Obj00625 *)p)->f130,1);
    CLACT_SetActorDrawEnable(((struct Obj00625 *)p)->f130,1);
    c.n=0; c.p=p; c.f=(void (*)(u8 *))func_021D73B0;
    CLACT_ApplyActorAnimCommand(((struct Obj00625 *)p)->f130,(const struct Cmd *)(&c));
    BG_SYS_SetMainVisiblePlanes(31);
}
