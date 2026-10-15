/*
 * function: WIFIBATTLEMATCH_SYS_CreateSubWork
 * address: 0x02213814
 * packet: pkt_ov199_02213814
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */
#include "../include/Obj25303.h"
#include "../include/Obj25304.h"
struct Proc;
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Proc *,unsigned,unsigned);
extern void MI_CpuFill8(void *,int,unsigned);
extern void *PROCSYS_Create(int);
extern void GFL_USE_FadeOutBgm(unsigned);
int WIFIBATTLEMATCH_SYS_CreateSubWork(struct Proc *p,int unused,char *q){void *r;GFL_HEAP_CreateChildHeap(1,88,336);r=PROCSYS_AllocProcWork(p,16,88);MI_CpuFill8(r,0,16);((struct Obj25303 *)q)->fC=0;((struct Obj25304 *)r)->f0=PROCSYS_Create(88);GFL_USE_FadeOutBgm(16);return 1;}
