/*
 * file:     zukan_search_proc.c
 * unit:     yes
 * function: ZUKAN_SEARCH_PROC_Create, ZUKAN_SEARCH_PROC_IsDone, ZUKAN_SEARCH_PROC_Delete, ZUKAN_SEARCH_PROC_Update
 * address:  0x021BC240
 * region:   ov211
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   d_021BC8D8 0x021BC8D8 data a4
 */
#include "zukan_search_types.h"

struct ProcSystem;
struct Proc;
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, unsigned int size, unsigned int heapId);
extern void MI_CpuFill8(void *,int,int);
extern void PROCSYS_FreeProcWork(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
int ZUKAN_SEARCH_PROC_Create(struct ProcSystem *obj,int unused,struct ZukanSearchOwner *owner);
int ZUKAN_SEARCH_PROC_IsDone(int unused1,int unused2,int unused3,struct ZukanSearchWork *work);
int ZUKAN_SEARCH_PROC_Delete(struct Proc *obj);
int ZUKAN_SEARCH_PROC_Update(struct ZukanSearchWork *work);
extern unsigned char d_021BC8D8[];

int ZUKAN_SEARCH_PROC_Create(struct ProcSystem *obj,int unused,struct ZukanSearchOwner *owner){struct ZukanSearchWork *work;GFL_HEAP_CreateChildHeap(1,126,0x60000);work=PROCSYS_AllocProcWork((struct Proc *)obj,16,126);MI_CpuFill8(work,0,16);work->owner=owner;return 1;}

int ZUKAN_SEARCH_PROC_IsDone(int unused1,int unused2,int unused3,struct ZukanSearchWork *work){return ZUKAN_SEARCH_PROC_Update(work)==0;}

int ZUKAN_SEARCH_PROC_Delete(struct Proc *obj){PROCSYS_FreeProcWork(obj);GFL_HEAP_DeleteChecked(126);return 1;}

int ZUKAN_SEARCH_PROC_Update(struct ZukanSearchWork *work){work->procState=(*(unsigned (**)(struct ZukanSearchWork *))(d_021BC8D8+work->procState*4))(work);return work->procState!=6;}
