/*
 * packet: pkt_ov187_0220AF40
 * function: func_0220AF40
 * address: 0x0220AF40
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov187
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BATTLE_REC_AllocWork 0x0200B400 thumb
 *   func_0220B008 0x0220B008 thumb ov187
 *   func_0220B0F8 0x0220B0F8 thumb ov187
 *   d_0220B2A0 0x0220B2A0 data a4
 */
#include "../include/Obj24881.h"
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void *MI_CpuFill8(void *, int, unsigned);
extern void BATTLE_REC_AllocWork(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct S;
extern void func_0220B008(struct S *p, u32 a, u32 b, u32 c);
extern void func_0220B0F8(u8 *p, u32 v);
extern const char d_0220B2A0[];
int func_0220AF40(struct Obj0203159C *a, unsigned unused, unsigned mode)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1, 0x59, 0x12000);
    p = PROCSYS_AllocProcWork(a, 0x17f4, 0x59);
    MI_CpuFill8(p, 0, 0x17f4);
    ((struct Obj24881 *)p)->f17F0 = mode;
    BATTLE_REC_AllocWork(0x59);
    func_0220B008((struct S *)p, (unsigned)d_0220B2A0, (unsigned)p, 0x59);
    func_0220B0F8((u8 *)p, 0);
    return 1;
}
