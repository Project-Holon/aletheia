/*
 * function: ZUKAN_Create
 * address: 0x021C8E80
 * packet: pkt_ov212_021C8E80
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 021C8F2A.
 * prototype: caller consumes r0 from legacy void 0203159C and 02031324;
 * 31324 forwards r0 to matched 31354(int), which returns allocation.
 * 3064C visibly receives three inputs here; retain caller's r2 size.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   ZUKAN_LoadListAndSelection 0x021C9288 thumb ov212
 *   ZUKAN_FixLastViewedSpecies 0x021C92EC thumb ov212
 *   ZUKAN_InitQuery 0x021C9380 thumb ov212
 */
#include "../include/Obj00635.h"
#include "../include/Obj25642.h"
#include "../include/Obj25643.h"
#include "../include/Obj25644.h"
#include "../include/Obj25645.h"
#include "../include/Obj25646.h"
#include "../include/Obj25647.h"
#include "../include/Obj25648.h"
#include "../include/Obj25649.h"
#include "../include/Obj25650.h"
typedef unsigned short u16;
struct Proc;struct Blk37;
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Proc *,unsigned,unsigned);
extern void MI_CpuFill8(void *,unsigned char,unsigned);
extern void *PROCSYS_Create(int);
extern u16 ZUKAN_LoadListAndSelection(struct Blk37 *,u16 **,unsigned);
extern void ZUKAN_FixLastViewedSpecies(void *p, u16 *ids, unsigned count);
extern void ZUKAN_InitQuery(struct Blk37 *,unsigned char *);
int ZUKAN_Create(struct Proc *obj,int unused,char *ctx)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,105,0x8000);
    p=PROCSYS_AllocProcWork(obj,44,105);
    MI_CpuFill8(p,0,44);
    ((struct Obj00635 *)p)->f0=ctx;
    ((struct Obj00635 *)p)->f4=PROCSYS_Create(105);
    ((struct Obj00635 *)p)->f10=ZUKAN_LoadListAndSelection(*(struct Blk37 * *)&((struct Obj25642 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(u16 **)(p+12),105);
    ((struct Obj00635 *)p)->f12=0;
    ZUKAN_FixLastViewedSpecies(*(struct Blk37 * *)&((struct Obj25643 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,*(u16 * *)&((struct Obj00635 *)p)->fC,((struct Obj00635 *)p)->f10);
    ZUKAN_InitQuery(*(struct Blk37 * *)&((struct Obj25644 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(unsigned char *)(p+20));
    if(((struct Obj25645 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==0){((struct Obj00635 *)p)->f1C=1;}
    else if(((struct Obj25646 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==1){((struct Obj00635 *)p)->f1C=3;}
    else if(((struct Obj25647 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==2){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=1;}
    else if(((struct Obj25648 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==3){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=2;}
    else if(((struct Obj25649 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==4){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=3;}
    else if(((struct Obj25650 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==5){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=4;}
    else {((struct Obj00635 *)p)->f1C=7;}
    return 1;
}
