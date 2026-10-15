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
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021BC8D8 0x021BC8D8 data a4
 */
#include "../../matched/include/Obj25637.h"
#include "../../matched/include/Obj14684.h"

struct Obj0203159C;
struct S020315D4;
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);
extern void MI_CpuFill8(void *,int,int);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
int ZUKAN_SEARCH_PROC_Create(struct Obj0203159C *obj,int unused,unsigned value);
int ZUKAN_SEARCH_PROC_IsDone(int a,int b,int c,unsigned char *p);
int ZUKAN_SEARCH_PROC_Delete(struct S020315D4 *p);
int ZUKAN_SEARCH_PROC_Update(unsigned char *p);
extern unsigned char d_021BC8D8[];

int ZUKAN_SEARCH_PROC_Create(struct Obj0203159C *obj,int unused,unsigned value){unsigned char *p;GFL_HEAP_CreateChildHeap(1,126,0x60000);p=PROCSYS_AllocProcWork(obj,16,126);MI_CpuFill8(p,0,16);((struct Obj25637 *)p)->f0=value;return 1;}

int ZUKAN_SEARCH_PROC_IsDone(int a,int b,int c,unsigned char *p){return ZUKAN_SEARCH_PROC_Update(p)==0;}

int ZUKAN_SEARCH_PROC_Delete(struct S020315D4 *p){func_020315D4(p);func_020306F0(126);return 1;}

int ZUKAN_SEARCH_PROC_Update(unsigned char *p){((struct Obj14684 *)p)->fC=(*(unsigned (**)(unsigned char *))(d_021BC8D8+*(unsigned *)(p+12)*4))(p);return ((struct Obj14684 *)p)->fC!=6;}
