/*
 * function: ISS_ZONE_SYS_LoadRecords
 * address:  0x0202BEEC
 * packet:   pkt_0202BEDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of ISS_3DS_SYS_LoadTable: builds a selector out of the caller's id, takes
 * a handle from func_020490F4, sizes the record table from ARC_TOOL_GetHandleFileCount's
 * count and allocates it with func_02030734, then reads every 8-byte record
 * into the handle with ARC_TOOL_ReadHandleMemberRange and releases it with ARC_TOOL_DeleteHandle.
 * The record table is at +8 and the count byte at +4 rather than the +0x264
 * and +0x268 ISS_3DS_SYS_LoadTable uses, and the count here stays a signed int (the
 * guard is `ble`), which is the whole difference between the two.
 *
 * The five-argument window read is the same call ARC_TOOL_ReadHandleMemberRange makes from
 * its other sites; the buffer is its own stack word because the argument
 * count already spends r0-r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_LoadRecords.c \
 *       --func ISS_ZONE_SYS_LoadRecords --addr 0x0202BEEC --thumb --cc 1.1p1
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   ARC_TOOL_GetHandleFileCount  0x0204961C  arm
 */
#include "../include/Obj08807.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
struct ArcFile;
extern u16 ARC_TOOL_GetHandleFileCount(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void   ARC_TOOL_DeleteHandle(void *handle);

void ISS_ZONE_SYS_LoadRecords(u8 *p, u32 id)
{
    void *h = func_020490F4(0x88, (u16)((id & 0x7fff) | 0x8000));
    int   n = ARC_TOOL_GetHandleFileCount(h);
    int   i;

    p[4] = (u8)n;
    ((struct Obj08807 *)p)->f8 = (u32)func_02030734(id, (u32)(n << 3), 0,
                                         (const void *)0x020A7748, 0xd2);

    for (i = 0; i < n; i++) {
        ARC_TOOL_ReadHandleMemberRange(h, (u32)i, 0, 8,
                      (void *)(((struct Obj08807 *)p)->f8 + ((u32)i << 3)));
    }
    ARC_TOOL_DeleteHandle(h);
}
