/*
 * function: SAVE_SCREEN_NoticeInit
 * address: 0x021B9BAC
 * packet: pkt_ov205_021B9BAC
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: own 0203159C is void, but this caller consumes allocator result r0 at 021B9BCA; its body stores that result then returns without overwriting r0.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 */
#include "../include/Obj10885.h"
#include "../include/Obj14634.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj0203159C;extern void GFL_HEAP_CreateChildHeap(u32 src,u32 dst,u32 size);extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,u32,u32);extern void func_02082A7C(u32,void *,u32);
int SAVE_SCREEN_NoticeInit(struct Obj0203159C *obj,u32 unused,char *ctx) { char *p;GFL_HEAP_CreateChildHeap(1,84,0x40000);p=PROCSYS_AllocProcWork(obj,28,84);func_02082A7C(0,p,28);((struct Obj10885 *)p)->f0=84;((struct Obj10885 *)p)->f4=((struct Obj14634 *)ctx)->f4;((struct Obj10885 *)p)->f8=((struct Obj14634 *)ctx)->f8;return 1; }
