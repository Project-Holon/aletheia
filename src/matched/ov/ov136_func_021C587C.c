/*
 * function: func_021C587C
 * address: 0x021C587C
 * packet: pkt_ov136_021C587C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetFrameDataArc 0x0202CAE4 thumb
 *   BGWINFRM_GetFrameBuffer 0x0202CF84 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 */
#include "../include/Obj04533.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void MI_CpuCopy8(void *,void *,u32);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
void func_021C587C(u8 *p)
{
    u32 i;
    void *first;
    **(void ** *)&((struct Obj04533 *)p)->f8 = BGWINFRM_Create(2,11,102);
    for(i=0;i<10;i++) BGWINFRM_AddFrame(**(void ** *)&((struct Obj04533 *)p)->f8,i,2,14,4);
    BGWINFRM_AddFrame(**(void ** *)&((struct Obj04533 *)p)->f8,10,1,14,4);
    BGWINFRM_SetFrameDataArc(**(void ** *)&((struct Obj04533 *)p)->f8,0,155,40,1);
    first = (void *)BGWINFRM_GetFrameBuffer(**(void ** *)&((struct Obj04533 *)p)->f8,0);
    for(i=1;i<=10;i++) MI_CpuCopy8(first,(void *)BGWINFRM_GetFrameBuffer(**(void ** *)&((struct Obj04533 *)p)->f8,i),112);
    for(i=0;i<10;i++) BGWINFRM_PutFrame(**(void ** *)&((struct Obj04533 *)p)->f8,i,(i%2)*16+1,(i/2)*4);
}
