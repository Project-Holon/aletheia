/*
 * function: GFL_NET_SAVE_InitWork
 * address:  0x02010A5C
 * packet:   pkt_02010A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sub_020124F4   0x020124F4  thumb
 *   sub_02012EBC   0x02012EBC  thumb
 *   GAME_SYNC_GetBlock   0x02009448  thumb
 *   BLOCK20_SAVEDATA_GetPending   0x020092EC  thumb
 */
#include "../include/Obj04833.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *dst, int val, unsigned n);
extern void *sub_020124F4(u16 heap);
struct Big;
struct Sub02009448Obj;
extern void *sub_02012EBC(struct Big *p);
extern struct Sub02009448Obj *GAME_SYNC_GetBlock(void *sys);
struct Sub02009210Obj;
extern u8 BLOCK20_SAVEDATA_GetPending(const struct Sub02009210Obj *obj);

int GFL_NET_SAVE_InitWork(void *a0)
{
    u8 *p;
    void *sys;

    GFL_HEAP_CreateChildHeap(1, 0x67, 0x78000);
    p = PROCSYS_AllocProcWork(a0, 0x1d8, 0x67);
    MI_CpuFill8(p, 0, 0x1d8);
    ((struct Obj04833 *)p)->f1D0 = 0x67;
    sys = sub_020124F4(0x67);
    ((struct Obj04833 *)p)->f44 = sys;
    if (BLOCK20_SAVEDATA_GetPending((const struct Sub02009210Obj *)GAME_SYNC_GetBlock(sub_02012EBC(sys))) != 0) {
        ((struct Obj04833 *)p)->f1D4 = 1;
        ((struct Obj04833 *)p)->f54 = 1;
    } else {
        ((struct Obj04833 *)p)->f1D4 = 0;
        ((struct Obj04833 *)p)->f54 = 0;
    }
    return 1;
}
