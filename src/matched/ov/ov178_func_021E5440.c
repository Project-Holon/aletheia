/*
 * function: func_021E5440
 * address: 0x021E5440
 * packet: pkt_ov178_021E5440
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   func_021E56F4 0x021E56F4 thumb ov178
 *   func_021E57E0 0x021E57E0 thumb ov178
 *   d_02FFFC3C 0x02FFFC3C data a4
 */
#include "../include/Obj04565.h"
#include "../include/Obj14378.h"
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern void *PROCSYS_Create(int a0);
extern void func_021E56F4(void *,void *,void *);
extern void func_021E57E0(int *,int *,char *);
extern unsigned d_02FFFC3C;
typedef struct {unsigned words[9];} Copy;
int func_021E5440(void *handle,int unused,char *q)
{
 char *p;
 GFL_HEAP_CreateChildHeap(1,0x58,0x30000);
 p=PROCSYS_AllocProcWork(handle,0xFC,0x58);
 MI_CpuFill8(p,0,0xFC);
 *(Copy *)(p+0xD4)=*(Copy *)q;
 ((struct Obj04565 *)p)->fF8=0x58;
 ((struct Obj04565 *)p)->fD0=PROCSYS_Create(((struct Obj04565 *)p)->fF8);
 ((struct Obj04565 *)p)->f4=((struct Obj14378 *)q)->f4;
 func_021E56F4(q,p,p+8);func_021E57E0((int *)q,(int *)p,p+0xA0);
 ((struct Obj04565 *)p)->fC8=0;
 ((struct Obj04565 *)p)->fCC=d_02FFFC3C;
 ((struct Obj04565 *)p)->f0=0;((struct Obj14378 *)q)->f20=0;
 return 1;
}
