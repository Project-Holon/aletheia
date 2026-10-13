/*
 * function: P_STA_SUB_CreateObjects
 * address: 0x021D6810
 * packet: pkt_ov131_021D6810
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021DC158 0x021DC158 data a1
 *   d_021DC160 0x021DC160 data a1
 */
#include "../include/Obj00993.h"
#include "../include/Obj05386.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern const u8 d_021DC158[];
extern const u8 d_021DC160[];
void P_STA_SUB_CreateObjects(u8 *a,u8 *p) {
    ObjPos pos[4];
    u8 i;
    u32 *e;
    pos[3].x=168;
    pos[3].y=8;
    pos[3].priority=10;
    pos[3].flags=1;
    pos[3].z=0;
    ((struct Obj05386 *)p)->f20=(u32)CLACT_CreateActor((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fD0,((struct Obj00993 *)a)->f9C,((struct Obj00993 *)a)->f104,&pos[3],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f20,0);
    pos[2].y=128;
    pos[2].priority=10;
    pos[2].flags=1;
    for(i=0;i<8;i++) {
        pos[2].x=d_021DC158[i];
        pos[2].z=d_021DC160[i];
        e=(u32 *)(p+i*4);
        e[9]=(u32)CLACT_CreateActor((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fD4,((struct Obj00993 *)a)->fA0,((struct Obj00993 *)a)->f108,&pos[2],0,((struct Obj00993 *)a)->f0);
        func_0204B3DC((struct Obj *)e[9],1);
    }
    pos[1].x=236;
    pos[1].y=26;
    pos[1].priority=10;
    pos[1].flags=1;
    pos[1].z=0;
    ((struct Obj05386 *)p)->f44=(u32)CLACT_CreateActor((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fF0,((struct Obj00993 *)a)->fBC,((struct Obj00993 *)a)->f120,&pos[1],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f44,0);
    pos[0].x=241;
    pos[0].y=31;
    pos[0].priority=10;
    pos[0].flags=1;
    pos[0].z=0;
    ((struct Obj05386 *)p)->f48=(u32)CLACT_CreateActor((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fF4,((struct Obj00993 *)a)->fC0,((struct Obj00993 *)a)->f124,&pos[0],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f48,0);
}
