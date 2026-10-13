/*
 * function: P_STA_SKILL_CreateSlotObjects
 * address: 0x021DB700
 * packet: pkt_ov131_021DB700
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: assign p[0] before pos.x to schedule its store before the stack address.
 * symbols:
 *   P_STA_SKILL_SlotTilePos 0x021DC2B8 data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj00344.h"
#include "../include/Obj03286.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;
extern const u8 P_STA_SKILL_SlotTilePos[][2];
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void P_STA_SKILL_CreateSlotObjects(u8 *a,void *b,u8 *p,u8 i) {
    ObjPos pos;
    ((struct Obj03286 *)p)->f4=0;
    p[0]=i;
    pos.x=P_STA_SKILL_SlotTilePos[i][0]*8;
    pos.y=P_STA_SKILL_SlotTilePos[i][1]*8;
    pos.priority=10;
    pos.flags=0;
    pos.z=p[0];
    ((struct Obj03286 *)p)->f8=func_0204B294(((struct Obj00344 *)a)->f174,(unsigned int)((struct Obj00344 *)a)->fE8,(unsigned int)((struct Obj00344 *)a)->fB0,(unsigned int)((struct Obj00344 *)a)->f118,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj03286 *)p)->f8,0);
    pos.x=P_STA_SKILL_SlotTilePos[p[0]][0]*8+26;
    pos.y=P_STA_SKILL_SlotTilePos[p[0]][1]*8+9;
    pos.priority=8;
    pos.flags=0;
    pos.z=0;
    ((struct Obj03286 *)p)->fC=func_0204B294(((struct Obj00344 *)a)->f174,(unsigned int)((struct Obj00344 *)a)->f130,(unsigned int)((struct Obj00344 *)a)->fA4,(unsigned int)((struct Obj00344 *)a)->f10C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj03286 *)p)->fC,0);
}
