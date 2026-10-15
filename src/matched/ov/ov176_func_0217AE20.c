/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_Create
 * address: 0x0217AE20
 * packet: pkt_ov176_0217AE20
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034AC4 0x02034AC4 arm
 *   ov67_id 0x43 data
 *   ov177_id 0xB1 data
 *   BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic 0x0217AEF4 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_CreateView 0x0217AF2C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_CreateText 0x0217AF50 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_FadeIn 0x0217B014 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 */
#include "../include/Obj10694.h"
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern int func_02034AC4(signed int);
extern char ov67_id[],ov177_id[];
extern void BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_CreateView(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_CreateText(char *);
extern void BATTLE_CHAMPIONSHIP_FLOW_FadeIn(void *,int *,char *);
extern int *WIFIBATTLEMATCH_UTIL_CreateCallback(int a, int b, int c);
int BATTLE_CHAMPIONSHIP_FLOW_Create(void *a,void *b,void *context)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,0x4e,0x30200);
    p=PROCSYS_AllocProcWork(a,0x34,0x4e);
    MI_CpuFill8(p,0,0x34);
    ((struct Obj10694 *)p)->f28=context;
    ((struct Obj10694 *)p)->f0=0x4e;
    func_02034AC4((int)ov67_id);
    func_02034AC4((int)ov177_id);
    BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic((int *)p);
    BATTLE_CHAMPIONSHIP_FLOW_CreateView((int *)p);
    BATTLE_CHAMPIONSHIP_FLOW_CreateText(p);
    ((struct Obj10694 *)p)->f4=WIFIBATTLEMATCH_UTIL_CreateCallback((int)p,(int)BATTLE_CHAMPIONSHIP_FLOW_FadeIn,0x4e);
    return 1;
}
