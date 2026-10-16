/*
 * file:     arc_util.c
 * unit:     yes
 * function: ARC_UTIL_LoadMember, ARC_UTIL_LoadMemberWithSize, ARC_UTIL_LoadHandleMember, ARC_UTIL_LoadHandleMemberWithSize
 * address:  0x0204A1BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from g3d_util.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   arc_util_file   0x020A7F30  data
 *   ARC_TOOL_ReadMember 0x02048F4C arm arm9
 *   ARC_TOOL_GetMemberSize 0x020490A8 arm arm9
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm arm9
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm arm9
 */
#include "g3d_util_shared_types.h"

struct LzHeader {
    u32 sizeAndType;
};

extern void *GFL_HEAP_Alloc(u16 heapID, u32 size, int clear, const char *file, int line);

extern u32 GFL_HEAP_Free(void *p);

extern void MI_UncompressLZ8(const void *src, void *dest);

void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);

void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 member, void *dst);

u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 member);

int ARC_UTIL_LoadMember(int a0, int a1, int a2, u16 a3);

int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, u16 a3, u32 *out);

void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u16 a3);

void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

extern const char  arc_util_file[];

extern const char arc_util_file[];

/*
 * arc_util.c's "open a member and read it" entry.  The three __LINE__
 * constants 1599, 1603 and 1611 are the only three the pool carries, and
 * each is the fifth argument of a GFL_HEAP_Alloc call whose fourth
 * argument is the file-name word at 0x020A7F30 ("arc_util.c").
 */
int ARC_UTIL_LoadMember(int archiveID, int memberIdx, int decompress, u16 heapID)
{
    int size;
    int buf;
    int outBuf;

    if (decompress != 0) {
        size = ARC_TOOL_GetMemberSize(archiveID, memberIdx);
        buf = (int)GFL_HEAP_Alloc((u16)((heapID & 0x7fff) | 0x8000), size, 0, arc_util_file, 1599);
    } else {
        size = ARC_TOOL_GetMemberSize(archiveID, memberIdx);
        buf = (int)GFL_HEAP_Alloc(heapID, size, 0, arc_util_file, 1603);
    }
    ARC_TOOL_ReadMember((void *)buf, archiveID, memberIdx);
    if (decompress != 0) {
        outBuf = (int)GFL_HEAP_Alloc(heapID, ((struct LzHeader *)buf)->sizeAndType >> 8, 0, arc_util_file, 1611);
        ((int (*)(int a0, int a1))MI_UncompressLZ8)(buf, outBuf);
        GFL_HEAP_Free((void *)buf);
        buf = outBuf;
    }
    return buf;
}

/*
 * The out-parameter twin of ARC_UTIL_LoadMember directly above it: the handle
 * ARC_TOOL_GetMemberSize returns is written through the fifth (stack) argument and
 * the same three arc_util.c line numbers appear, shifted by 43.
 */
int ARC_UTIL_LoadMemberWithSize(int archiveID, int memberIdx, int decompress, u16 heapID, u32 *out)
{
    int buf;
    int outBuf;

    *out = ARC_TOOL_GetMemberSize(archiveID, memberIdx);
    if (decompress != 0) {
        buf = (int)GFL_HEAP_Alloc((u16)((heapID & 0x7fff) | 0x8000), *out, 0, arc_util_file, 1642);
    } else {
        buf = (int)GFL_HEAP_Alloc(heapID, *out, 0, arc_util_file, 1646);
    }
    ARC_TOOL_ReadMember((void *)buf, archiveID, memberIdx);
    if (decompress != 0) {
        *out = ((struct LzHeader *)buf)->sizeAndType >> 8;
        outBuf = (int)GFL_HEAP_Alloc(heapID, *out, 0, arc_util_file, 1656);
        ((int (*)(int a0, int a1))MI_UncompressLZ8)(buf, outBuf);
        GFL_HEAP_Free((void *)buf);
        buf = outBuf;
    }
    return buf;
}

void *ARC_UTIL_LoadHandleMember(void *narc, u32 fileID, u32 decompress, u16 heapID)
{
    u32 size;
    return ARC_UTIL_LoadHandleMemberWithSize(narc, fileID, decompress, heapID, &size);
}

/*
 * arc_util.c: load one archive member into a fresh heap block, optionally
 * LZ8-decompressing it into a second block.  ARM, not Thumb (the old
 * pending file compiled Thumb and read ISA).
 *
 * Shape facts the image fixes: the allocation is written in both arms of
 * the decompress test (the image cross-jumps them onto one call, with
 * *out_size re-read at the join); the heap id is a u32 narrowed at each
 * use; the NULL check wraps the rest rather than returning early, so every
 * exit shares `mov r0, r4; pop`; on a failed second allocation the result
 * is the NULL block (buf = d unconditionally).  The decompressing arm is
 * line 1709 and the plain arm 1713: the pool order says so.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_LoadHandleMemberWithSize.c  *       --func ARC_UTIL_LoadHandleMemberWithSize --addr 0x0204A39C --arm --cc 1.1p1
 */
void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileID, int decompress, u32 heapID, u32 *out_size)
{
    void *buf;
    void *outBuf;

    *out_size = ARC_TOOL_GetHandleMemberSize(narc, fileID);
    if (decompress != 0) {
        buf = GFL_HEAP_Alloc((u16)(((u16)heapID & 0x7FFF) | 0x8000), *out_size, 0, arc_util_file, 1709);
    } else {
        buf = GFL_HEAP_Alloc((u16)heapID, *out_size, 0, arc_util_file, 1713);
    }
    if (buf != 0) {
        ARC_TOOL_ReadHandleMember(narc, fileID, buf);
        if (decompress != 0) {
            *out_size = ((struct LzHeader *)buf)->sizeAndType >> 8;
            outBuf = GFL_HEAP_Alloc((u16)heapID, *out_size, 0, arc_util_file, 1725);
            if (outBuf != 0) {
                MI_UncompressLZ8(buf, outBuf);
                GFL_HEAP_Free(buf);
            }
            buf = outBuf;
        }
    }
    return buf;
}
