/*
 * function: B_BAG_MAIN_InitFrames
 * address: 0x0220BBE4
 * packet: pkt_ov197_0220BBE4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   func_020490F4 0x020490F4 arm
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetClipArea 0x0202CFEC thumb
 *   BGWINFRM_SetFrameDataArcHandle 0x0202CB18 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   d_0220DB44 0x0220DB44 data a4
 */
#include "../include/Obj01176.h"
#include "../include/Obj25012.h"
#include "../include/Obj25013.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct {u16 member;u8 w,h;} Config;
extern const Config d_0220DB44[14];
struct WinMgr;
extern struct WinMgr *BGWINFRM_Create(u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
struct Obj;
extern void BGWINFRM_SetClipArea(struct Obj *o, u32 i, u8 a, u8 b, s8 c, s8 d);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr,u32,void *,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr,u32,s8,s8);
void B_BAG_MAIN_InitFrames(char *p)
{
    void *arc;
    unsigned i;
    ((struct Obj01176 *)p)->f520=BGWINFRM_Create(2,14,((struct Obj25012 *)(*(char * *)&((struct Obj01176 *)p)->f0))->fC);
    arc=func_020490F4(99,(u16)((((struct Obj25013 *)(*(char * *)&((struct Obj01176 *)p)->f0))->fC&0x7FFF)|0x8000));
    for(i=0;i<14;i++){
        BGWINFRM_AddFrame(((struct Obj01176 *)p)->f520,i,6,d_0220DB44[i].w,d_0220DB44[i].h);
        BGWINFRM_SetClipArea(((struct Obj01176 *)p)->f520,i,0,64,0,64);
        BGWINFRM_SetFrameDataArcHandle(((struct Obj01176 *)p)->f520,i,arc,d_0220DB44[i].member,1);
    }
    ARC_TOOL_DeleteHandle(arc);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,0,0,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,1,0,10);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,2,16,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,3,16,10);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,4,32,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,5,48,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,6,32,7);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,7,48,7);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,8,32,13);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,9,48,13);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,11,32,19);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,12,37,19);
}
