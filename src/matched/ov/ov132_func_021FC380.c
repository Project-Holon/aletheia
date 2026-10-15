/*
 * function: SCRIPT_COMMAND_CmdCharFollowActor
 * address: 0x021FC380
 * packet: pkt_ov132_021FC380
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   SCRIPT_COMMAND_GetActorMask 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetCharSlot 0x021F9DDC thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACTING_GetBoard 0x021F9DF4 thumb ov132
 *   STA_ACT_LIGHT_ElemOpA 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 *   func_02030734 0x02030734 arm
 *   STA_ACT_SCRIPT_AddTask 0x021FADA0 thumb ov132
 *   SCRIPT_COMMAND_TaskCharFollow 0x021FC490 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
#include "../include/Obj02487.h"
#include "../include/Obj04519.h"
#include "../include/Obj04520.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int SCRIPT_COMMAND_GetActorMask(char *,int);
extern void *STA_ACTING_GetCharSystem(void *);
extern void *STA_ACTING_GetCharSlot(void *,u8);
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void *STA_ACTING_GetBoard(void *p);
extern void STA_ACT_LIGHT_ElemOpA(void *unused, u32 *p, u32 *q);
extern void STA_ACT_LIGHT_CopyElemA(void *unused, u32 *p, const u32 *q);
extern void VEC_Add(const Vec *,const Vec *,Vec *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *STA_ACT_SCRIPT_AddTask(char *,u32,u32,u32);
extern void SCRIPT_COMMAND_TaskCharFollow(int,char *);
extern const char d_021FDD00[];
int SCRIPT_COMMAND_CmdCharFollowActor(int unused,char *p)
{
 char *owner,*q;
 Vec pos,delta;
 u16 duration;
 u32 f,e,d,b,c,a;
 void *ctx,*target,*scene,*obj;
 u8 i;
 owner=*(char * *)&((struct Obj04519 *)p)->f0;
 a=VM_GetU32(((struct Obj04519 *)p)->f4);
 b=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct Obj04519 *)p)->f4));
 c=VM_GetU32(((struct Obj04519 *)p)->f4);
 d=VM_GetU32(((struct Obj04519 *)p)->f4);
 e=VM_GetU32(((struct Obj04519 *)p)->f4);
 f=VM_GetU32(((struct Obj04519 *)p)->f4);
 ctx=STA_ACTING_GetCharSystem(((struct Obj04520 *)owner)->f34);
 target=STA_ACTING_GetCharSlot(((struct Obj04520 *)owner)->f34,a);
 scene=STA_ACTING_GetActorSystem(((struct Obj04520 *)owner)->f34);
 duration=c;
 for(i=0;i<4;i++) {
  obj=STA_ACTING_GetActor(((struct Obj04520 *)owner)->f34,i);
  if(b&(1<<i)) {
   if(c==0) {
    STA_ACT_LIGHT_ElemOpA(scene,obj,(u32 *)(&pos));
    delta.x=d;delta.y=e;delta.z=f;
    VEC_Add(&pos,&delta,&pos);
    STA_ACT_LIGHT_CopyElemA(ctx,target,(const u32 *)(&pos));
   } else {
    STA_ACTING_GetBoard(((struct Obj04520 *)owner)->f34);
    q=func_02030734(((struct Obj04520 *)owner)->f0,0x30,0,d_021FDD00,0x74D);
    *(char * *)&((struct Obj02487 *)q)->f28=owner;
    ((struct Obj02487 *)q)->f0=i;
    ((struct Obj02487 *)q)->f4=target;
    ((struct Obj02487 *)q)->f8=((struct Obj04520 *)owner)->f34;
    ((struct Obj02487 *)q)->fC=obj;
    ((struct Obj02487 *)q)->f1E=0;
    ((struct Obj02487 *)q)->f10=d;((struct Obj02487 *)q)->f14=e;((struct Obj02487 *)q)->f18=f;
    ((struct Obj02487 *)q)->f1C=duration;
    ((struct Obj02487 *)q)->f2C=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskCharFollow,(u32)q,7);
   }
  }
 }
 return 0;
}
