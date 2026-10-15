/*
 * function: STAFF_ROLL_Init
 * address: 0x021B95A0
 * packet: pkt_ov181_021B95A0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes live r0 from 0203159C as the buffer pointer; its owner declaration is void.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj24498.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj0203159C;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
int STAFF_ROLL_Init(struct Obj0203159C *p,int unused,u32 v) { u8 *q; GFL_HEAP_CreateChildHeap(1,142,0x125000); q=PROCSYS_AllocProcWork(p,756,142); MI_CpuFill8(q,0,756); ((struct Obj24498 *)q)->f0=v; return 1; }
