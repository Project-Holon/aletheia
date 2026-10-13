/*
 * function: func_02213814
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
 *   func_02082BCC 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */
#include "../include/Obj25303.h"
#include "../include/Obj25304.h"
struct Obj0203159C;
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);
extern void func_02082BCC(void *,int,unsigned);
extern void *PROCSYS_Create(int);
extern void GFL_USE_FadeOutBgm(unsigned);
int func_02213814(struct Obj0203159C *p,int unused,char *q){void *r;GFL_HEAP_CreateChildHeap(1,88,336);r=PROCSYS_AllocProcWork(p,16,88);func_02082BCC(r,0,16);((struct Obj25303 *)q)->fC=0;((struct Obj25304 *)r)->f0=PROCSYS_Create(88);GFL_USE_FadeOutBgm(16);return 1;}
