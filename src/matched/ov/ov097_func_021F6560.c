/*
 * function: func_021F6560
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
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj21988.h"
struct Obj0203159C;
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned int,unsigned int);
extern void func_02082BCC(void *,int,unsigned int);
int func_021F6560(struct Obj0203159C *a, int b, int c) { void *p; GFL_HEAP_CreateChildHeap(1,0x71,0x18000); p=PROCSYS_AllocProcWork(a,0x120,0x71); func_02082BCC(p,0,0x120); ((struct Obj21988 *)p)->f0=c; return 1; }
