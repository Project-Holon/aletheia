/*
 * function: FLD3D_CI_StartSequence
 * address:  0x021C1CB0
 * packet:   pkt_ov021_021C1CB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_HEAP_GetAllocatableSize  0x0203038C  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FLD3D_CI_InitEventWork  0x021C313C  thumb  ov021
 *   FLD3D_CI_EventMain  0x021C1E7C  thumb  ov021
 *   d_021DA7F4     0x021DA7F4  data  ov021  a4
 */
#include "../include/Obj01213.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 d_021DA7F4[];

u32 GFL_HEAP_GetAllocatableSize(int a);
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void FLD3D_CI_InitEventWork(u32 a, u32 *p);
typedef unsigned char  u8;
int FLD3D_CI_EventMain(int a, int *st, u8 *ctx);

int FLD3D_CI_StartSequence(int a, char *b, int c)
{
    int r;

    if (GFL_HEAP_GetAllocatableSize(0x15) < d_021DA7F4[c])
        return 0;
    ((struct Obj01213 *)b)->f64 = 0;
    ((struct Obj01213 *)b)->f130 = 0;
    ((struct Obj01213 *)b)->f134 = 0;
    ((struct Obj01213 *)b)->f136 = 0;
    ((struct Obj01213 *)b)->f66 = c;
    *(u32 *)&((struct Obj01213 *)b)->f128 = 0;
    *(u32 *)&((struct Obj01213 *)b)->f12C = 0;
    ((struct Obj01213 *)b)->fC = 0;
    r = (int)func_020122C0((void *)a, 0, FLD3D_CI_EventMain, 0x40);
    FLD3D_CI_InitEventWork((u32)b, func_020124E8((struct Obj *)r));
    return r;
}
