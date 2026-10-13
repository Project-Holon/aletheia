/*
 * function: func_021D9BEC
 * address: 0x021D9BEC
 * packet: pkt_ov129_021D9BEC
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero alignment padding.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   func_021D9E60 0x021D9E60 thumb ov129
 *   func_021D9E98 0x021D9E98 thumb ov129
 *   func_021D9E48 0x021D9E48 thumb ov129
 */
#include "../include/Obj00501.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 x,y,frame; u8 speed,flag; } Params;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_021D9E60(u8 *p, int n);
extern void func_021D9E98(char *,int);
extern void func_021D9E48(char *,int,int);
void func_021D9BEC(char *p)
{
    Params s;
    int h=((struct Obj00501 *)p)->f25C;
    s.x=0; s.y=0; s.frame=0; s.speed=0; s.flag=0;
    ((struct Obj00501 *)p)->f194=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1B0=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1CC=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    func_021D9E60((u8 *)p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f194),0);
    func_0204B92C((struct Obj *)((struct Obj00501 *)p)->f194,1);
    ((struct Obj00501 *)p)->f1B8=0; ((struct Obj00501 *)p)->f1BA=0;
    ((struct Obj00501 *)p)->f1A4=1;
    func_021D9E98(p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f1B0),((struct Obj00501 *)p)->f1A4);
    func_0204B92C((struct Obj *)((struct Obj00501 *)p)->f1B0,1);
    func_0204B688((struct Actor *)(((struct Obj00501 *)p)->f1B0),1);
    ((struct Obj00501 *)p)->f1D4=0; ((struct Obj00501 *)p)->f1D6=0;
    ((struct Obj00501 *)p)->f1C0=1;
    func_021D9E98(p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f1CC),((struct Obj00501 *)p)->f1C0);
    func_0204B688((struct Actor *)(((struct Obj00501 *)p)->f1CC),1);
    func_0204B92C((struct Obj *)((struct Obj00501 *)p)->f1CC,1);
    func_021D9E48(p,1,0);
    func_021D9E48(p,2,0);
}
