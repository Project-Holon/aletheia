/*
 * function: UNION_EFF_InitIconGroup
 * address:  0x0217FB70
 * packet:   pkt_ov019_0217F8C0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sub-object constructor reached from UNION_EFF_Create (called at +0x14 with
 * p+0x20).  Grabs a handle from ARC_TOOL_CreateHandle(0x59) -- the r1 "owner" word is a
 * leftover of the caller, so only r0 is set, the one-argument forwarding shape
 * -- then fills two fields from G3D_SYSTEM_CreateResourceArcHandle(h, index) and asserts each with
 * G3D_SYSTEM_TransVramTexture; a zero result goes to sub_02034714 against d_02180814.
 *
 * symbols:
 *   ARC_TOOL_CreateHandle   0x020490F4  arm
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   sub_02034714   0x02034714  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_02180814     0x02180814  data  ov019 a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07393.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 d_02180814[];

void UNION_EFF_InitIconGroup(char *p, u32 heap)
{
    void *h = ARC_TOOL_CreateHandle((u32)((void *)0x59), heap);

    *(u32 *)&((struct Obj07393 *)p)->fC8 = (u32)G3D_SYSTEM_CreateResourceArcHandle((u32)h, 0x16);
    *(u32 *)&((struct Obj07393 *)p)->fCC = (u32)G3D_SYSTEM_CreateResourceArcHandle((u32)h, 0x17);
    if (G3D_SYSTEM_TransVramTexture(*(int * *)&((struct Obj07393 *)p)->fC8) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (G3D_SYSTEM_TransVramTexture(*(int * *)&((struct Obj07393 *)p)->fCC) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    ARC_TOOL_DeleteHandle(h);
}
