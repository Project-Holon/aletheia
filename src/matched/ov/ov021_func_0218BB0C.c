/*
 * function: FIELD_BUILDMODEL_LoadModelArchive
 * address:  0x0218BB0C
 * packet:   pkt_ov021_0218BB0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_GetHandleFileCount  0x0204961C  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj00572.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
struct ArcFile;
extern u16 ARC_TOOL_GetHandleFileCount(void *obj);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *h);

void FIELD_BUILDMODEL_LoadModelArchive(u8 *s, u16 a, u32 n)
{
    void *h;
    u8 *r;

    h = func_020490F4(a, (u16)((((struct Obj00572 *)s)->f0 & 0x7fff) | 0x8000));
    if (ARC_TOOL_GetHandleFileCount(h) <= n)
        n = 0;
    r = ARC_TOOL_LoadHandleMember(h, n, ((struct Obj00572 *)s)->f0);
    *(u8 * *)&((struct Obj00572 *)s)->f18 = r;
    ((struct Obj00572 *)s)->f1AC = (u32)r[2] >> 1;
    if (((struct Obj00572 *)s)->f1AC > 0x190)
        ((struct Obj00572 *)s)->f1AC = 0x80;
    ARC_TOOL_DeleteHandle(h);
}
