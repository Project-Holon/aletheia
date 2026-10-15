/*
 * function: GURU2_EntryProcInit
 * address: 0x021DC860
 * packet: pkt_ov137_021DC860
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 */
#include "../include/Obj10612.h"
#include "../include/Obj23664.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern void *PROCSYS_Create(int a0);
int GURU2_EntryProcInit(void *obj,int a,u8 *ctx) { u8 *p=PROCSYS_AllocProcWork(obj,36,4); MI_CpuFill8(p,0,36); ((struct Obj10612 *)p)->f10=((struct Obj23664 *)ctx)->f4; ((struct Obj10612 *)p)->f8=ctx; ((struct Obj10612 *)p)->f20=PROCSYS_Create(1); return 1; }
