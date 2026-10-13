/*
 * function: UNION_EFF_InitAnimGroup
 * address:  0x0217F97C
 * packet:   pkt_ov019_0217F8C0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sub-object constructor reached from UNION_EFF_Create (called at +0x10 with the
 * block base).  Same shape as UNION_EFF_InitIconGroup: handle ARC_TOOL_CreateHandle(0x59) with
 * the r1 "owner" word a leftover, fill two fields from G3D_SYSTEM_CreateResourceArcHandle(h, idx),
 * assert the first through G3D_SYSTEM_TransVramTexture / sub_02034714 (d_02180814), then
 * release the handle.  Only the first index is checked here.
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
#include "../include/Obj09419.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 d_02180814[];

void UNION_EFF_InitAnimGroup(char *p, u32 heap)
{
    void *h = ARC_TOOL_CreateHandle((u32)((void *)0x59), heap);

    *(u32 *)&((struct Obj09419 *)p)->f14 = (u32)G3D_SYSTEM_CreateResourceArcHandle((u32)h, 0x14);
    ((struct Obj09419 *)p)->f18 = (u32)G3D_SYSTEM_CreateResourceArcHandle((u32)h, 0x15);
    if (G3D_SYSTEM_TransVramTexture(*(int * *)&((struct Obj09419 *)p)->f14) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    ARC_TOOL_DeleteHandle(h);
}
