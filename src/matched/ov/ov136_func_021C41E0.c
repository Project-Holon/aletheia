/*
 * function: func_021C41E0
 * address: 0x021C41E0
 * packet: pkt_ov136_021C41E0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_021C4184 0x021C4184 thumb ov136
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   func_0203F8F4 0x0203F8F4 arm
 */
#include "../include/Obj01064.h"
#include "../include/Obj08198.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void MIi_CpuClearFast(unsigned, void *, unsigned);
extern signed char func_02012FFC(void);
extern void func_021C4184(void *, u8 *);
typedef unsigned int   u32;
struct GfFont;
struct Tcbl;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0203F8F4(u16);
int func_021C41E0(void *a, void *b, u8 *p)
{
    u8 *q;
    u8 v;
    GFL_HEAP_CreateChildHeap(1, 0x64, 0x20000);
    q = PROCSYS_AllocProcWork(a, 0x15C, 0x64);
    MIi_CpuClearFast(0, q, 0x15C);
    ((struct Obj01064 *)q)->f0 = 0x64;
    ((struct Obj01064 *)q)->f1C = p;
    q[0xB] = ((struct Obj08198 *)p)->f0;
    q[0xC] = q[0xB];
    q[0x16] = p[2];
    q[0x17] = p[3];
    v = q[0x16];
    q[0x1A] = v;
    q[0x1B] = v;
    ((struct Obj08198 *)p)->f0 = 0xFFFF;
    q[0x15] = func_02012FFC();
    func_021C4184(q, *(u8 * *)&((struct Obj01064 *)q)->f1C);
    ((struct Obj01064 *)q)->f24 = GF_FONT_Create((unsigned)0x17, (unsigned)0, (unsigned)0, (unsigned)0, (u16)(((struct Obj01064 *)q)->f0));
    ((struct Obj01064 *)q)->f100 = TCBL_Create((u16)(((struct Obj01064 *)q)->f0), ((struct Obj01064 *)q)->f0, 0x20, 0x20);
    q[0xA] = 1;
    func_0203F8F4(((struct Obj01064 *)q)->f0);
    return 1;
}
