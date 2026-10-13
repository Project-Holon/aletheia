/*
 * function: func_021BC240
 * address: 0x021BC240
 * packet: pkt_ov211_021BC240
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: caller consumes r0 from legacy void 0203159C allocation wrapper.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj25637.h"
struct Obj0203159C;extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);extern void MI_CpuFill8(void *,int,int);
int func_021BC240(struct Obj0203159C *obj,int unused,unsigned value){unsigned char *p;GFL_HEAP_CreateChildHeap(1,126,0x60000);p=PROCSYS_AllocProcWork(obj,16,126);MI_CpuFill8(p,0,16);((struct Obj25637 *)p)->f0=value;return 1;}
