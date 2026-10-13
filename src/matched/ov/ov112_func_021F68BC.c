/*
 * function: func_021F68BC
 * address: 0x021F68BC
 * packet: pkt_ov112_021F68BC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MUSICAL_DIST_SAVE_Create 0x0200C52C thumb
 *   MUSICAL_DIST_SAVE_GetPayload 0x0200C6D8 thumb
 *   MUSICAL_DIST_SAVE_GetPayloadSize 0x0200C6DC thumb
 *   MUSICAL_DIST_SAVE_Delete 0x0200C5A4 thumb
 *   ARC_TOOL_CreateHandleFromMemory 0x0204913C arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021F83E4 0x021F83E4 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021F83E4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct ArcFile;
struct Blk2C;
struct MusicalDist;
extern struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *sys, u32 heap);
extern u32 MUSICAL_DIST_SAVE_GetPayload(struct Blk2C *p);
extern u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct Blk2C *p);
extern void *ARC_TOOL_CreateHandleFromMemory(void *a0, u32 a1, u32 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *p);
void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap)
{
    void *x;
    void *arc;
    u32 c, d, e;
    u8 *q;
    *p = kind;
    if (kind >= 4) {
        x = MUSICAL_DIST_SAVE_Create(sys, heap);
        arc = ARC_TOOL_CreateHandleFromMemory((void *)MUSICAL_DIST_SAVE_GetPayload(x), MUSICAL_DIST_SAVE_GetPayloadSize(x), (u16)((heap & 0x7fff) | 0x8000));
    } else {
        arc = func_020490F4(kind + 0x6f, (u16)((heap & 0x7fff) | 0x8000));
    }
    *(void **)(p + 4) = ARC_UTIL_LoadHandleMemberWithSize(arc, 0, 0, heap, (u32 *)(p + 0x20));
    *(void **)(p + 8) = ARC_UTIL_LoadHandleMemberWithSize(arc, 1, 0, heap, (u32 *)(p + 0x24));
    *(void **)(p + 0xc) = ARC_UTIL_LoadHandleMemberWithSize(arc, 2, 0, heap, (u32 *)(p + 0x28));
    c = ARC_TOOL_GetHandleMemberSize(arc, 4);
    d = ARC_TOOL_GetHandleMemberSize(arc, 3);
    e = ARC_TOOL_GetHandleMemberSize(arc, 5);
    *(u32 *)(p + 0x2c) = c + 0xc + d + e;
    q = func_02030734(heap, *(u32 *)(p + 0x2c), 1, d_021F83E4, 0x104);
    *(u8 **)(p + 0x10) = q;
    *(u8 **)(p + 0x14) = q + 0xc;
    *(u8 **)(p + 0x18) = q + 0xc + c;
    *(u32 *)(p + 0x1c) = d + *(u32 *)(p + 0x18);
    *(u32 *)q = c;
    *(u32 *)(q + 4) = d;
    *(u32 *)(q + 8) = e;
    ARC_TOOL_ReadHandleMember(arc, 4, *(void **)(p + 0x14));
    ARC_TOOL_ReadHandleMember(arc, 3, *(void **)(p + 0x18));
    ARC_TOOL_ReadHandleMember(arc, 5, *(void **)(p + 0x1c));
    ARC_TOOL_DeleteHandle(arc);
    if (kind >= 4) MUSICAL_DIST_SAVE_Delete(x);
}
