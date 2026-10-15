/*
 * function: NAMEIN_GRAPHIC_CreateActors
 * address: 0x021F1888
 * packet: pkt_ov194_021F1888
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Associate each indexed object address as p+index*4+12, preventing a hoisted p+12 spill in the final loop.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj01772.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPalette(void *,unsigned,unsigned,unsigned,u16);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void MI_CpuFill8(void *,int,int);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned);
void NAMEIN_GRAPHIC_CreateActors(char *p,unsigned owner,u16 heap)
{
    short pos[4];
    void *handle;
    int i;
    int zero;
    handle=func_020490F4(118,heap);
    *(int *)&((struct Obj01772 *)p)->f0=CLACT_RegisterPalette(handle,9,0,0,heap);
    *(int *)&((struct Obj01772 *)p)->f8=CLACT_RegisterCellAnim(handle,7,6,heap);
    *(int *)&((struct Obj01772 *)p)->f4=CLACT_RegisterCharacter(handle,8,0,0,heap);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(pos,0,8);
    pos[2]=0;
    zero=0;
    for(i=0;i<16;i++)
        *(void **)(p+i*4+12)=CLACT_CreateActor((void *)owner,((struct Obj01772 *)p)->f4,((struct Obj01772 *)p)->f0,((struct Obj01772 *)p)->f8,pos,zero,heap);
    pos[2]=1;
    ((struct Obj01772 *)p)->f50=CLACT_CreateActor((void *)owner,((struct Obj01772 *)p)->f4,((struct Obj01772 *)p)->f0,((struct Obj01772 *)p)->f8,pos,zero,heap);
    CLACT_SetActorDrawEnable(((struct Obj01772 *)p)->f50,zero);
    for(i=18;i<20;i++) {
        pos[0]=-32;
        pos[1]=-32;
        pos[2]=i-15;
        *(void **)(p+i*4+12)=CLACT_CreateActor((void *)owner,((struct Obj01772 *)p)->f4,((struct Obj01772 *)p)->f0,((struct Obj01772 *)p)->f8,pos,0,heap);
        CLACT_SetActorAutoAnim(*(void **)(p+i*4+12),1);
        CLACT_SetActorDrawEnable(*(void **)(p+i*4+12),0);
    }
}
