/*
 * function: Wf2dmapFriend_Create
 * address: 0x021C6180
 * packet: pkt_ov128_021C6180
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   id127 0x0000007F data
 *   id67 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   Wf2dmapFriend_InitText 0x021C63EC thumb ov128
 *   Wf2dmapFriend_InitGfx 0x021C658C thumb ov128
 *   func_020056A0 0x020056A0 thumb
 *   Wf2dmapFriend_Proc 0x021C6354 thumb ov128
 */
#include "../include/Obj06476.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern char id127[],id67[];
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern void Wf2dmapFriend_InitText(u8 *p, const u32 *q, int heap);
extern void Wf2dmapFriend_InitGfx(char *p, void *q, int heap);
extern void *func_020056A0(void *,void *,int);
extern void Wf2dmapFriend_Proc(void *p, char *q);
int Wf2dmapFriend_Create(void *p,int unused,void *q)
{
    char *v;
    func_02034AC4((u32)id127); func_02034AC4((u32)id67);
    GFL_HEAP_CreateChildHeap(1,52,0xc0000);
    v=PROCSYS_AllocProcWork(p,0x5b0,52);
    MI_CpuFill8(v,0,0x5b0);
    ((struct Obj06476 *)v)->f1F8=q; ((struct Obj06476 *)v)->f5A8=0;
    Wf2dmapFriend_InitText((u8 *)(v+0x190),((struct Obj06476 *)v)->f1F8,52);
    Wf2dmapFriend_InitGfx(v+4,v+0x190,52);
    if(((struct Obj06476 *)v)->f5A8==0) ((struct Obj06476 *)v)->f5A8=func_020056A0(Wf2dmapFriend_Proc,v,16);
    return 1;
}
