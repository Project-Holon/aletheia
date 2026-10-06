/*
 * function: func_021EF0F4
 * address: 0x021EF0F4
 * packet: pkt_ov107_021EF0F4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 0204B294 own legacy void corrected to live pointer return proved by its 0204CFDC forwarding target; owner sources untouched.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   func_020413B0 0x020413B0 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 */
#include "../include/Obj00057.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct Placement { u16 x,y,z;u8 f6,f7; };
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_020409B4(u32);
extern void func_02049238(void *);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void func_0204B3DC(struct Obj *,u32);
extern u32 func_020275E4(void),func_02027614(void),func_02027618(void),func_02027624(void),func_02027628(void),func_0202762C(void),func_0202761C(u32),func_02027620(u32);
void func_021EF0F4(u8 *p) {
 void *archive;
 u32 first;
 struct Placement placement;
 if(!p[0x28]) {
 archive=func_020490F4(139,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),1,4,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),5,7,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),9,7,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),4,3,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),8,3,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),2,0,288,288,128,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),6,2,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),10,2,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),3,0,416,416,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),7,0,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),11,0,0,0,0,((struct Obj00057 *)p)->f0);
 func_020409B4(2);func_02049238(archive);
 } else {
 archive=func_020490F4(34,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),6,4,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),15,7,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),31,7,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),6,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),15,3,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),31,3,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049238(archive);
 archive=func_020490F4(139,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),2,4,288,288,128,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),6,5,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),10,5,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),3,4,416,416,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),7,4,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),11,4,0,0,0,((struct Obj00057 *)p)->f0);
 func_020409B4(5);func_02040588(5,0);func_02040588(4,0);func_02049238(archive);
 }
 archive=func_020490F4(func_020275E4(),((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),func_02027624(),4,256,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),func_02027628(),6,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),func_0202762C(),6,0,0,0,((struct Obj00057 *)p)->f0);
 func_020413B0(6,0,21,32,3,8);func_020409B4(6);
 *(int *)&((struct Obj00057 *)p)->f70=func_0204AC18((void *)((u32)archive),func_02027614(),1,0,0,3,((struct Obj00057 *)p)->f0);
 *(int *)&((struct Obj00057 *)p)->f74=func_0204A6C8((void *)((u32)archive),func_02027618(),0,1,((struct Obj00057 *)p)->f0);
 first=func_0202761C(2);
 *(int *)&((struct Obj00057 *)p)->f78=func_0204AF28((void *)((u32)archive),first,func_02027620(2),((struct Obj00057 *)p)->f0);
 func_02049238(archive);
 placement.x=232;placement.y=168;placement.z=1;placement.f7=0;placement.f6=0;
 *(struct Obj * *)&((struct Obj00057 *)p)->f7C=func_0204B294((void *)*(u32 *)&((struct Obj00057 *)p)->f6C,((struct Obj00057 *)p)->f74,((struct Obj00057 *)p)->f70,((struct Obj00057 *)p)->f78,&placement,1,((struct Obj00057 *)p)->f0);
 if(!p[0x28]) {func_0204B3DC(*(struct Obj * *)&((struct Obj00057 *)p)->f7C,1);return;}
 else {func_0204B3DC(*(struct Obj * *)&((struct Obj00057 *)p)->f7C,0);return;}
}
