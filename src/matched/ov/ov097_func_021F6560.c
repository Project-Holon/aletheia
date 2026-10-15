/*
 * function: VS_MULTI_LIST_ProcInit
 * address: 0x021F6560
 * packet: pkt_ov097_021F6560
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller reads r0 after PROCSYS_AllocProcWork; declare its live pointer result despite the callee's legacy void return.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj21988.h"
struct Proc;
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Proc *,unsigned int,unsigned int);
extern void MI_CpuFill8(void *,int,unsigned int);
int VS_MULTI_LIST_ProcInit(struct Proc *a, int b, int c) { void *p; GFL_HEAP_CreateChildHeap(1,0x71,0x18000); p=PROCSYS_AllocProcWork(a,0x120,0x71); MI_CpuFill8(p,0,0x120); ((struct Obj21988 *)p)->f0=c; return 1; }
