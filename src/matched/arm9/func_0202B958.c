/*
 * function: ISS_3DS_SYS_LoadTable
 * address:  0x0202B958
 * packet:   pkt_0202B744
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Same list dance as ISS_ZONE_SYS_LoadRecords, on a node whose record table sits at
 * 0x264 and whose record count at 0x268; the node's own u16 id supplies the
 * selector.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_3DS_SYS_LoadTable.c \
 *       --func ISS_3DS_SYS_LoadTable --addr 0x0202B958 --thumb --cc 1.1p1
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   ARC_TOOL_GetHandleFileCount  0x0204961C  arm
 */
#include "../include/Obj01019.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
extern u16    ARC_TOOL_GetHandleFileCount(void *obj);
struct ArcFile;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern void   ARC_TOOL_DeleteHandle(void *h);

void ISS_3DS_SYS_LoadTable(u8 *p)
{
    u32  id = ((struct Obj01019 *)p)->f0;
    void *h = func_020490F4(0xb9, (u16)((id & 0x7fff) | 0x8000));
    u8   n = (u8)ARC_TOOL_GetHandleFileCount(h);
    u32  i;

    p[0x268] = n;
    ((struct Obj01019 *)p)->f264 = (u32)func_02030734(id, (u32)(n << 3), 0,
                                             (const void *)0x020A7738, 0x178);

    for (i = 0; i < (u32)n; i++) {
        ARC_TOOL_ReadHandleMember(h, i, (void *)(((struct Obj01019 *)p)->f264 + (i << 3)));
    }
    ARC_TOOL_DeleteHandle(h);
}
