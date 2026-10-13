/*
 * function: P_STA_SKILL_CreateObjects
 * address: 0x021D9A4C
 * packet: pkt_ov131_021D9A4C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D9BD2 follow the 390-byte body.
 * proof: i is byte-wrapped; i*24 <=6120, every descriptor byte initialized.
 * No bound smaller than the ldrb domain is assumed for p[43].
 * prototype: 0204B294 leaves 0204CFDC's pointer result live at 0204B318;
 * this caller stores r0 after every call. Keep all seven own-body inputs.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   P_STA_SKILL_CreateSlotObjects 0x021DB700 thumb ov131
 */
#include "../include/Obj00344.h"
#include "../include/Obj01939.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void P_STA_SKILL_CreateSlotObjects(u8 *,void *,u8 *,u8);
void P_STA_SKILL_CreateObjects(u8 *a,u8 *p)
{
    ObjPos pos;
    u8 i;
    pos.x=159;
    pos.y=52;
    pos.priority=10;
    pos.flags=1;
    i=0;
    pos.z=0;
    *(u32 *)&((struct Obj01939 *)p)->f90=(u32)CLACT_CreateActor((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fE4,((struct Obj00344 *)a)->fAC,((struct Obj00344 *)a)->f114,&pos,1,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f90,0);
    pos.x=172;
    pos.y=56;
    *(u32 *)&((struct Obj01939 *)p)->f94=(u32)CLACT_CreateActor((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fD8,((struct Obj00344 *)a)->fA8,*(u32 *)&((struct Obj00344 *)a)->f10C,&pos,1,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f94,0);
    pos.flags=0;
    *(u32 *)&((struct Obj01939 *)p)->f98=(u32)CLACT_CreateActor((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f98,0);
    pos.z=5;
    pos.priority=8;
    *(u32 *)&((struct Obj01939 *)p)->f9C=(u32)CLACT_CreateActor((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f9C,0);
    func_0204B92C(((struct Obj01939 *)p)->f9C,1);
    pos.z=2;
    pos.priority=4;
    pos.flags=0;
    *(u32 *)&((struct Obj01939 *)p)->fA0=(u32)CLACT_CreateActor((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->fA0,0);
    func_0204B92C(((struct Obj01939 *)p)->fA0,1);
    for(;i<p[0x2b];i++) P_STA_SKILL_CreateSlotObjects(a,p,(p+0xb0)+i*24,i);
}
