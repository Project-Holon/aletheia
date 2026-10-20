/*
 * file:     arc_tool.c
 * unit:     yes
 * function: ARC_TOOL_SetTable, ARC_TOOL_ReadMemberRangeImpl, ARC_TOOL_LoadMemberRangeImpl, ARC_TOOL_OpenArchive, ARC_TOOL_SeekMember, ARC_TOOL_ReadMember, ARC_TOOL_LoadMember, ARC_TOOL_ReadMemberRange, ARC_TOOL_LoadMemberRange, ARC_TOOL_LoadMemberFromPath, ARC_TOOL_GetArchiveFileCount, ARC_TOOL_GetMemberSize, ARC_TOOL_CreateHandle, ARC_TOOL_CreateHandleFromMemory, ARC_TOOL_ReadHandleHeader, ARC_TOOL_DeleteHandle, ARC_TOOL_LoadHandleMember, ARC_TOOL_ReadHandleMember, ARC_TOOL_GetHandleMemberSize, ARC_TOOL_ReadHandleMemberRange, ARC_TOOL_GetHandleMemberOffsetOut, ARC_TOOL_GetHandleMemberOffset, ARC_TOOL_ReadHandle, ARC_TOOL_SeekHandle, ARC_TOOL_GetHandleFileCount
 * address:  0x02048CEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from arc_tool_set_table.c, arc_tool.c by tools/splitfile.py.
 *
 * symbols:
 *   ARC_TOOL_gArchiveTable     0x02146A68  data
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   FS_CloseFile  0x02078A80  arm
 *   FS_ReadFile  0x02078B70  arm
 *   arc_tool_file  0x020A7EE0  data
 *   FS_InitFile             0x020788AC  arm
 *   FS_OpenFile     0x02078C18  arm
 *   FS_CreateFileFromMemory 0x0207A940  arm
 *   FS_SeekFile             0x02078B44  arm
 *   GF_PANIC_FailPrintf           0x02034734  arm
 *   arc_tool_msg_member_range       0x020A7EEC  data
 *   arc_tool_msg_member_bounds  0x020A7F18  data
 *   G3D_SYSTEM_CreateResourcePath 0x02046E90 arm
 */
#include "g3d_util_shared_types.h"
#include "g3d_light_shared_types.h"
#include "../types.h"

void ARC_TOOL_SetTable(void **a, u32 b);

extern struct ArcTableInfo ARC_TOOL_gArchiveTable;

void ARC_TOOL_SetTable(void **entries, u32 count)
{
    ARC_TOOL_gArchiveTable.entries = (u32 *)entries;
    ARC_TOOL_gArchiveTable.count = count;
    ARC_TOOL_gArchiveTable.useRecords = 0;
}

#include "../sdk_fs.h"

struct ArcRecord {
    u32          start;
    volatile u32 end;
};

struct ArcHeaderScan {
    u32 fatSize;
    u16 fileCount;
    u8  pad_06[2];
    u32 nameTableSize;
};

struct FatInfo {
    u32 offset;
    u16 count;
};

struct ArcHandleRaw {
    u8 raw[0x50];
};

#include "gfl_heap_wrap.h"






#include "fs_proc_mem.h"
#include "fs_file.h"


#include "gf_panic.h"

void ARC_TOOL_ReadMemberRangeImpl(void *dst, u32 archive_id, u32 member, u32 offset, u32 size);

void *ARC_TOOL_LoadMemberRangeImpl(u32 archive_id, u32 member, u16 heap, u32 offset, u32 size);

void ARC_TOOL_OpenArchive(FSFile *arc, u32 id);

u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 member, u32 base, u32 size);

void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u16 heap);

void ARC_TOOL_ReadMemberRange(void *dst, u32 archive_id, u32 member, u32 offset, u32 size);

void *ARC_TOOL_LoadMemberRange(u32 archive_id, u32 member, u16 heap, u32 offset, u32 size);

void *ARC_TOOL_LoadMemberFromPath(const char *path, u32 a, u16 heap);

u32 ARC_TOOL_GetArchiveFileCount(u32 a);

u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);

void *ARC_TOOL_CreateHandle(u32 id, unsigned int heap);

void *ARC_TOOL_CreateHandleFromMemory(void *buf, u32 size, u16 heap);

void ARC_TOOL_ReadHandleHeader(struct ArcHandle *arc);

void ARC_TOOL_DeleteHandle(void *arc);

void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 member, u32 heap);

void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 member, void *dst);

u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 member);

void ARC_TOOL_ReadHandleMemberRange(struct ArcHandle *arc, u32 member, u32 offset, u32 size, void *dst);

void ARC_TOOL_GetHandleMemberOffsetOut(struct ArcHandle *arc, u32 member, u32 *out);

u32 ARC_TOOL_GetHandleMemberOffset(struct ArcHandle *arc, u32 member);

void ARC_TOOL_ReadHandle(struct ArcHandleRaw *arc, u32 size, void *dst);

int ARC_TOOL_SeekHandle(struct FSFile *file, u32 offset);

u16 ARC_TOOL_GetHandleFileCount(void *obj);

extern const char arc_tool_file[];

extern const char arc_tool_file[];

extern const char arc_tool_msg_member_range[];

extern const char arc_tool_file[];

extern const char arc_tool_file[];

extern const char arc_tool_file[];

extern const char arc_tool_file[];

extern const char arc_tool_msg_member_bounds[];

extern const char arc_tool_file[];

extern const char arc_tool_msg_member_bounds[];

extern const char arc_tool_file[];

extern const char arc_tool_msg_member_bounds[];

extern const char arc_tool_file[];

extern const char arc_tool_msg_member_bounds[];

extern const char arc_tool_file[];

extern const char arc_tool_msg_member_bounds[];

extern const char arc_tool_file[];

extern const char arc_tool_msg_member_bounds[];

/*
 * Read one sub-file of one archive into a buffer the caller owns.  The whole
 * archive handle is a 0x48 byte stack local: ARC_TOOL_OpenArchive binds it to the
 * archive named by `archive_id` (it indexes the 235-entry a/x/y/z name table
 * at 0x020A6C58), ARC_TOOL_SeekMember seeks the member and returns its byte size,
 * FS_ReadFile is the read and FS_CloseFile closes the handle again.
 *
 * Nothing survives the call, so this is the one-shot form: a caller that wants
 * the archive to stay open uses ARC_TOOL_CreateHandle instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadMemberRangeImpl.c \
 *       --func ARC_TOOL_ReadMemberRangeImpl --addr 0x02048D00 --cc 1.1p1 --arm
 */
void ARC_TOOL_ReadMemberRangeImpl(void *dst, u32 archiveID, u32 memberIdx, u32 offset,
                   u32 size)
{
    FSFile h;

    ARC_TOOL_OpenArchive(&h, archiveID);
    FS_ReadFile(&h, dst, ARC_TOOL_SeekMember((struct ArcHandle *)&h, memberIdx, offset, size));
    FS_CloseFile(&h);
}

/*
 * The allocating twin of ARC_TOOL_ReadMemberRangeImpl: bind a temporary 0x48-byte archive
 * handle to `archive_id`, size the member, take a block of exactly that size
 * from the caller's heap, read the member into it, close the handle and hand
 * the block back.  The __FILE__ argument is "arc_tool.c" at 0x020A7EE0, the
 * same string src/matched/ARC_TOOL_CreateHandle.c already pins, with line 0xbb.
 *
 * This is the function the whole map-model path goes through: ARC_TOOL_LoadMember
 * calls it as ARC_TOOL_LoadMemberRangeImpl(9, matrix_id, heap, 0, NULL), and ov010's
 * MAP_MATRIX_Load is what supplies archive id 9 (a/0/0/9) and the matrix id
 * read out of the zone record's +0x04 lane.  See docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMemberRangeImpl.c \
 *       --func ARC_TOOL_LoadMemberRangeImpl --addr 0x02048D54 --cc 1.1p1 --arm
 */
void *ARC_TOOL_LoadMemberRangeImpl(u32 archiveID, u32 memberIdx, u16 heapID, u32 offset,
                    u32 size)
{
    FSFile h;
    u32 memberSize;
    void *buf;

    ARC_TOOL_OpenArchive(&h, archiveID);
    memberSize = ARC_TOOL_SeekMember((struct ArcHandle *)&h, memberIdx, offset, size);
    buf = GFL_HEAP_Alloc(heapID, memberSize, 0, (char *)arc_tool_file, 0xbb);
    FS_ReadFile(&h, buf, memberSize);
    FS_CloseFile(&h);
    return buf;
}

/*
 * The whole of packet pkt_02048DDC, 0x02048DDC-0x02048F4C: arc_tool.c's
 * archive binder (ARC_TOOL_OpenArchive) and the member resolver it hands off to
 * (ARC_TOOL_SeekMember), both open functions on the eidos port's blocked list.
 * Verified as one translation unit, so the literal pool at 0x02048E30
 * between the two functions and the two pool words at 0x02048F44/0x02048F48
 * are inside the compared range: 2 sections, 368 bytes, no padding, 16 of 16
 * relocation sites resolved (attestation classes: label for the five SDK
 * entry points and GF_PANIC_FailPrintf, literal for ARC_TOOL_gArchiveTable and the arc_tool.c
 * string, string for the assertion text).
 *
 * ---------------------------------------------------------------------------
 * ARC_TOOL_OpenArchive - "open archive by id"
 *
 * FS_InitFile binds the caller's 0x48-byte handle, then the one global at
 * 0x02146A68 picks the archive's storage: with its +0x08 flag clear the
 * +0x00 pointer is the 235-entry name table (installed by
 * ARC_TOOL_SetTable(0x020A6C58, 0xeb), see docs/ASSETS.md) and the member's name
 * is opened by path; with the flag set the same table is an array of 8-byte
 * {start, end} extents and the member is bound straight out of memory as
 * (start, end - start).  Nothing in the image ever sets +0x08, so the second
 * arm is dead code kept for the id-as-pointer build.
 *
 * The two arms must each read the +0x00 table pointer themselves: the
 * original spends a separate `ldr` in each arm and the record arm's pointer
 * lands in r3.  Three things in this spelling are shape, not semantics, and
 * each is load-bearing for -O4,p at 1.1p1 - each was measured against a
 * variant that differs only in the qualifier or the declaration:
 *
 *   - `u32 * volatile unk00`: without `volatile` the optimizer
 *     common-subexpresses the two arms' table-pointer loads, hoists the one
 *     load above the `bne` (the word arm then begins with `mov r0, r5` at
 *     +0x20 instead of +0x24) and the record arm reuses it.  A volatile load
 *     cannot be CSE'd, so each arm reloads, and the function is 88 bytes
 *     instead of 76.
 *   - `volatile u32 end` in the extent type: without it mwcc merges the
 *     record's two field loads into `ldm r2, {r1, r2}`, which is four bytes
 *     short and re-tiles the low word onto the materialised address.
 *   - `u32 *tbl` bound before the record pointer: with the pointer expression
 *     inlined into the subscript
 *     (`(struct ArcRecord *)ARC_TOOL_gArchiveTable.unk00 + id`) the same code comes out
 *     with the table in r1 and the materialised address in r2, i.e. every
 *     register in the record arm is off by one slot.  Naming the loaded table
 *     first makes mwcc keep it in r3 and use r1 for the address, as the
 *     original does.
 *
 * The 8-byte extent is {start, end} and the requested length is end - start;
 * the two locals mirror the original's evaluation order, which loads the high
 * word first.  A plain `u32 *` (or a plain `u32` plus a cast in the word arm)
 * instead of `u32 * volatile` is 76-84 bytes, never 88.  The sibling unit
 * src/matched/unit_02048C58.c declares the same global as three plain u32
 * fields, which is right for what it does (ARC_TOOL_SetTable writes it) and is
 * not enough for this reader.  See docs/notes/pkt_02048DDC.c.txt.
 *
 * ---------------------------------------------------------------------------
 * ARC_TOOL_SeekMember - resolve one member's extent
 *
 * Read the FAT offset out of the file header at +0xc, read the tail of the
 * table it points to ({u32 image delta, u16 count} at fatOffset+4), range
 * check the member index, walk to the member's {u32 start, u32 end} pair at
 * fatOffset+0xc+member*8 and seek to its first byte at base+image+8+start.
 * Returns the member's byte length, or `size` when the caller supplied one
 * (that is the `size_out` argument the sibling readers in src/matched/ pass
 * as 0).  The u32 at +4 doubles as the scratch the first two reads share,
 * which is why it is zeroed before the 2-byte read: the top half of the
 * u32 stays clear.
 *
 * The assertion's variadic tail is two values, the count and the member: r3
 * is never written on the assert path, so the `ldrh` that fed the guard's
 * `cmp` is still live and only the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 * 0x020A7EE0 is the arc_tool.c anchor src/matched/ARC_TOOL_LoadMemberRangeImpl.c already
 * pins; 0x020A7EEC is the assertion text, fixed from outside by the
 * terminator of the string in front of it.  The `ldreq`/`subeq` tail is
 * "take the caller's size if it is non-zero, else end - start".
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048DDC.c \
 *       --addr 0x02048DDC --cc 1.1p1 --arm
 * (both halves were also verified individually as `one` before folding them
 * into this unit: ARC_TOOL_OpenArchive 88 bytes, ARC_TOOL_SeekMember 280 bytes.)
 */
void ARC_TOOL_OpenArchive(FSFile *arc, u32 archiveID)
{
    FS_InitFile(arc);
    if (ARC_TOOL_gArchiveTable.useRecords == 0) {
        FS_OpenFile(arc, (const char *)(ARC_TOOL_gArchiveTable.entries[archiveID]));
    } else {
        u32 *tbl = (u32 *)ARC_TOOL_gArchiveTable.entries;
        struct ArcRecord *rec = (struct ArcRecord *)tbl + archiveID;
        u32 end = rec->end;
        uptr start = rec->start;

        FS_CreateFileFromMemory(arc, (void *)start, end - start);
    }
}

u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 memberIdx, u32 skip, u32 size)
{
    u32 range[2];
    struct FatInfo info;
    u32 tmp = 0;
    u32 fatOffset;
    u32 off;

    FS_SeekFile(&arc->file, 0xc, 0);
    FS_ReadFile(&arc->file, &tmp, 2);
    fatOffset = tmp;

    FS_SeekFile(&arc->file, fatOffset + 4, 0);
    FS_ReadFile(&arc->file, &info, 6);
    if (info.count <= memberIdx) {
        GF_PANIC_FailPrintf(arc_tool_file, 0xfb, arc_tool_msg_member_range, info.count,
                      memberIdx);
    }

    off = fatOffset + info.offset;
    FS_SeekFile(&arc->file, off + 4, 0);
    FS_ReadFile(&arc->file, &tmp, 4);
    off += tmp;
    FS_SeekFile(&arc->file, fatOffset + 0xc + memberIdx * 8, 0);

    FS_ReadFile(&arc->file, range, 8);
    FS_SeekFile(&arc->file, skip + (off + 8 + range[0]), 0);

    if (size == 0) {
        size = range[1] - range[0];
    }
    return size;
}

/*
 * "Read one archive sub-file into a caller-supplied buffer", the defaulting
 * wrapper around ARC_TOOL_ReadMemberRangeImpl.  ARC_TOOL_ReadMemberRangeImpl takes five arguments
 * (dst, archive id, member, mode, size_out); this entry point supplies zero
 * for the last two, which is why the body is a single `mov r3, #0` doing
 * double duty: the same zero reaches r3 (the fourth argument) and the one
 * word of outgoing stack area (the fifth).  The `push {r3, lr}` is the home
 * slot for that stack argument, not a saved register.
 *
 * ARC_TOOL_ReadMemberRangeImpl itself opens a temporary archive handle with ARC_TOOL_OpenArchive,
 * sizes the member with ARC_TOOL_SeekMember, reads it and closes the handle again.
 *
 * Kept in its own file so that the branch to ARC_TOOL_ReadMemberRangeImpl is witnessed from
 * outside this range by src/matched/ARC_TOOL_ReadMemberRange.c, which calls the same
 * target (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadMember.c \
 *       --func ARC_TOOL_ReadMember --addr 0x02048F4C --cc 1.1p1 --arm
 */
void ARC_TOOL_ReadMember(void *dst, u32 archiveID, u32 memberIdx)
{
    ARC_TOOL_ReadMemberRangeImpl(dst, archiveID, memberIdx, 0, 0);
}

/*
 * "Load one archive sub-file into a fresh heap block", the defaulting wrapper
 * around ARC_TOOL_LoadMemberRangeImpl.  Same shape as ARC_TOOL_ReadMember one entry above: the
 * callee takes (archive id, member, heap, mode, size_out) and this entry
 * point supplies zero for the last two, so one `mov r3, #0` feeds both r3 and
 * the single outgoing stack word, and `push {r3, lr}` is that word's home
 * slot rather than a saved register.
 *
 * This is the call the field code uses to pull a map matrix out of a/0/1/2's
 * sibling archive: MAP_MATRIX_Load in ov010 calls it as
 * ARC_TOOL_LoadMember(9, matrix_id, heap), i.e. archive id 9 = a/0/0/9, with the
 * matrix id taken straight from the zone record's +0x04 lane.  See the
 * "Zone to map model" section of docs/ASSETS.md.
 *
 * Kept in its own file so the branch to ARC_TOOL_LoadMemberRangeImpl is witnessed from
 * outside this range by src/matched/ARC_TOOL_LoadMemberRange.c
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMember.c \
 *       --func ARC_TOOL_LoadMember --addr 0x02048F60 --cc 1.1p1 --arm
 */
void *ARC_TOOL_LoadMember(u32 archiveID, u32 memberIdx, u16 heapID)
{
    return ARC_TOOL_LoadMemberRangeImpl(archiveID, memberIdx, heapID, 0, 0);
}

/*
 * The five-argument entry point of the same read: a pure forwarder to
 * ARC_TOOL_ReadMemberRangeImpl that copies the caller's one stack argument down into its own
 * outgoing stack area (`ldr ip, [sp, #8]` reads it across the two words this
 * function pushed) and leaves r0-r3 untouched.
 *
 * Kept in its own file so the branch to ARC_TOOL_ReadMemberRangeImpl is witnessed from
 * outside this range by src/matched/ARC_TOOL_ReadMember.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadMemberRange.c \
 *       --func ARC_TOOL_ReadMemberRange --addr 0x02048F74 --cc 1.1p1 --arm
 */
void ARC_TOOL_ReadMemberRange(void *dst, u32 archiveID, u32 memberIdx, u32 offset,
                   u32 size)
{
    ARC_TOOL_ReadMemberRangeImpl(dst, archiveID, memberIdx, offset, size);
}

/*
 * The five-argument entry point of the allocating load: a pure forwarder to
 * ARC_TOOL_LoadMemberRangeImpl, with the caller's single stack argument copied down through
 * ip exactly as ARC_TOOL_ReadMemberRange does for ARC_TOOL_ReadMemberRangeImpl.
 *
 * Kept in its own file so the branch to ARC_TOOL_LoadMemberRangeImpl is witnessed from
 * outside this range by src/matched/ARC_TOOL_LoadMember.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMemberRange.c \
 *       --func ARC_TOOL_LoadMemberRange --addr 0x02048F88 --cc 1.1p1 --arm
 */
void *ARC_TOOL_LoadMemberRange(u32 archiveID, u32 memberIdx, u16 heapID, u32 offset,
                    u32 size)
{
    return ARC_TOOL_LoadMemberRangeImpl(archiveID, memberIdx, heapID, offset, size);
}

/*
 * Promote-first callee of src/pending/G3D_SYSTEM_CreateResourcePath.c (parks lane 2).
 * Open one member of an archive by path, size it, allocate the block from
 * the debug allocator, read the bytes in and close.  Same shape as its
 * sibling ARC_TOOL_LoadHandleMember in the same cluster; the 0x4c frame is the 0x48
 * ArcFile handle at sp+4 plus the allocator's one outgoing stack word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMemberFromPath.c \
 *       --func ARC_TOOL_LoadMemberFromPath --addr 0x02048F9C --cc 1.1p1 --arm
 */
void *ARC_TOOL_LoadMemberFromPath(const char *path, u32 memberIdx, u16 heapID)
{
    FSFile file;
    void *p;
    u32 size;

    FS_InitFile(&file);
    FS_OpenFile(&file, path);
    size = ARC_TOOL_SeekMember((struct ArcHandle *)(&file), memberIdx, 0, 0);
    p = GFL_HEAP_Alloc(heapID, size, 0, (char *)arc_tool_file, 0x182);
    FS_ReadFile(&file, p, size);
    FS_CloseFile(&file);
    return p;
}

u32 ARC_TOOL_GetArchiveFileCount(u32 archiveID)
{
    char buf[0x48];
    int headerSize;
    u16 header[3];

    headerSize = 0;
    ARC_TOOL_OpenArchive((FSFile *)buf, archiveID);
    FS_SeekFile((FSFile *)buf, 0xc, 0);
    FS_ReadFile((FSFile *)buf, &headerSize, 2);
    FS_SeekFile((FSFile *)buf, headerSize + 4, 0);
    FS_ReadFile((FSFile *)buf, header, 6);
    FS_CloseFile((FSFile *)buf);
    return header[2];
}

u32 ARC_TOOL_GetMemberSize(u32 archiveID, u32 memberIdx)
{
    char buf[0x48];
    u32 size;

    ARC_TOOL_OpenArchive((FSFile *)buf, archiveID);
    size = ARC_TOOL_SeekMember((struct ArcHandle *)buf, memberIdx, 0, 0);
    FS_CloseFile((FSFile *)buf);
    return size;
}

/*
 * Constructor: take a 0x50-byte record from the debug allocator, tie it to
 * the caller's object through ARC_TOOL_OpenArchive, run the one-time init at
 * ARC_TOOL_ReadHandleHeader and hand the record back.  The allocator's __FILE__/__LINE__
 * pair is the usual ABS32 into the packed string area plus a pooled 0x209,
 * which is not an ARM rotated immediate.
 */
void *ARC_TOOL_CreateHandle(u32 archiveID, unsigned int heapID)
{
    void *rec = GFL_HEAP_Alloc(heapID, 0x50, 0, (char *)arc_tool_file, 0x209);

    ARC_TOOL_OpenArchive(rec, archiveID);
    ARC_TOOL_ReadHandleHeader(rec);
    return rec;
}

/*
 * arc_tool.c's memory-file opener: carve a 0x50-byte FSFile with the
 * three-argument allocator (the heap id is this function's THIRD parameter
 * and reaches the allocator first), initialise it, bind it to the caller's
 * buffer and length, run the reader over it, and hand the FSFile back.
 *
 * The __FILE__ argument is the arc_tool.c anchor at 0x020A7EE0 that
 * src/matched/ARC_TOOL_LoadMemberRangeImpl.c and the rest of the 0x02049xxx run already
 * pin; the stacked fifth argument is __LINE__ = 0x21f.  Its own pool word
 * (0x02049198) sits inside the compared range, so the site resolves through
 * the `string` class - the anchor's address is fixed by the terminator of the
 * string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_CreateHandleFromMemory.c \
 *       --func ARC_TOOL_CreateHandleFromMemory --addr 0x0204913C --cc 1.1p1 --arm
 */
void *ARC_TOOL_CreateHandleFromMemory(void *buf, u32 size, u16 heapID)
{
    void *handle = GFL_HEAP_Alloc(heapID, 0x50, 0, (char *)arc_tool_file, 0x21f);

    FS_InitFile(handle);
    FS_CreateFileFromMemory(handle, buf, size);
    ARC_TOOL_ReadHandleHeader(handle);
    return handle;
}

/*
 * Walk the reader past its own header.  A halfword count at +0x4c is read
 * first, then skipped by, then a six-byte record is read into a stack buffer
 * whose first word is added to that count and whose third halfword lands in
 * the object at +0x4e; the running total then skips the following four-byte
 * field, which is read into the second half of the same buffer and added to
 * the total for the final offset at +0x48.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadHandleHeader.c \
 *       --func ARC_TOOL_ReadHandleHeader --addr 0x0204919C --cc 1.1p1 --arm
 */
void ARC_TOOL_ReadHandleHeader(struct ArcHandle *arc)
{
    struct ArcHeaderScan scan;
    u32 off;

    arc->fatOffset = 0;
    FS_SeekFile(&arc->file, 0xc, 0);
    FS_ReadFile((FSFile *)arc, &arc->fatOffset, 2);
    FS_SeekFile(&arc->file, arc->fatOffset + 4, 0);
    FS_ReadFile((FSFile *)arc, &scan, 6);
    arc->count = scan.fileCount;
    off = arc->fatOffset + scan.fatSize;
    FS_SeekFile(&arc->file, off + 4, 0);
    FS_ReadFile((FSFile *)arc, &scan.nameTableSize, 4);
    arc->imageBase = off + scan.nameTableSize;
}

void ARC_TOOL_DeleteHandle(void *handle)
{
    FS_CloseFile(handle);
    GFL_HEAP_Free(handle);
}

/*
 * Read one member out of an open archive into a fresh heap block.  The
 * handle is an FSFile (0x48 bytes) with the archive's own bookkeeping
 * appended: the FAT offset at +0x4c and the member count at +0x4e, both
 * halfwords, and the image base at +0x48.
 *
 * The FAT entry is a pair of words (start, end) at
 * `fatOffset + 0xc + member * 8`, read into an on-stack two-word buffer;
 * the member's bytes then start at `imageBase + 8 + start` and run
 * `end - start` long.  The difference is written out twice, not cached in a
 * local: the original recomputes `sub r2, r3, r2` after the allocation from
 * two fresh stack loads.
 *
 * The assertion's variadic tail is two values, the count and the member,
 * not one.  The tell is that r3 is never written on the assert path: the
 * `ldrh r3, [r5, #0x4e]` that fed the guard's own `cmp` is still live, so
 * the first variadic argument costs no instruction at all, and only the
 * second reaches the stack.  Declared with a single variadic argument the
 * member lands in r3 instead and the `str r7, [sp]` disappears; see
 * docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md.
 *
 * 0x020A7EE0 is the arc_tool.c anchor this translation unit already uses in
 * ARC_TOOL_LoadMemberRangeImpl; 0x020A7F18 is the assertion message, attested by the
 * terminator of the string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadHandleMember.c \
 *       --func ARC_TOOL_LoadHandleMember --addr 0x02049250 --cc 1.1p1 --arm
 */
void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 memberIdx, u32 heapID)
{
    u32 range[2];
    void *buf;

    if (arc->count <= memberIdx) {
        GF_PANIC_FailPrintf(arc_tool_file, 613, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile(&arc->file, arc->fatOffset + 0xc + memberIdx * 8, 0);
    FS_ReadFile((FSFile *)arc, range, 8);
    FS_SeekFile(&arc->file, arc->imageBase + 8 + range[0], 0);

    buf = GFL_HEAP_Alloc(heapID, range[1] - range[0], 0, (char *)arc_tool_file, 619);
    if (buf != 0) {
        FS_ReadFile((FSFile *)arc, buf, range[1] - range[0]);
    }
    return buf;
}

/*
 * Read one archive member straight into a caller-supplied buffer: the
 * allocating variant is ARC_TOOL_LoadHandleMember one function above, and the FAT
 * lookup, the image-base offset and the length are identical.
 *
 * The bounds assertion is the same five-argument call ARC_TOOL_LoadHandleMember uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadHandleMember.c  *       --func ARC_TOOL_ReadHandleMember --addr 0x0204932C --cc 1.1p1 --arm
 */
void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 memberIdx, void *dst)
{
    u32 range[2];

    if (arc->count <= memberIdx) {
        GF_PANIC_FailPrintf(arc_tool_file, 642, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile(&arc->file, arc->fatOffset + 0xc + memberIdx * 8, 0);
    FS_ReadFile((FSFile *)arc, range, 8);
    FS_SeekFile(&arc->file, arc->imageBase + 8 + range[0], 0);
    FS_ReadFile((FSFile *)arc, dst, range[1] - range[0]);
}

/*
 * Return the byte length of one archive member without reading it: the
 * FAT entry's two words are fetched and subtracted, and the file cursor is
 * left parked on the FAT rather than on the member's data.
 *
 * The bounds assertion is the same five-argument call ARC_TOOL_LoadHandleMember uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_GetHandleMemberSize.c  *       --func ARC_TOOL_GetHandleMemberSize --addr 0x020493D4 --cc 1.1p1 --arm
 */
u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 memberIdx)
{
    u32 range[2];

    if (arc->count <= memberIdx) {
        GF_PANIC_FailPrintf(arc_tool_file, 665, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile(&arc->file, arc->fatOffset + 0xc + memberIdx * 8, 0);
    FS_ReadFile((FSFile *)arc, range, 8);
    return range[1] - range[0];
}

/*
 * Read a window out of the middle of one archive member.  Only the FAT
 * entry's first word is fetched (a 4-byte read, not 8), because the end
 * offset is never needed: the caller supplies both the offset into the
 * member and the length.
 *
 * The seek target is `offset + (imageBase + 8 + start)`: the accumulator of
 * the final `add` is the register holding the computed base, which is what
 * puts the caller's offset on the left of the source expression
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The bounds assertion is the same five-argument call ARC_TOOL_LoadHandleMember uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadHandleMemberRange.c  *       --func ARC_TOOL_ReadHandleMemberRange --addr 0x0204944C --cc 1.1p1 --arm
 */
void ARC_TOOL_ReadHandleMemberRange(struct ArcHandle *arc, u32 memberIdx, u32 offset, u32 size,
                   void *dst)
{
    u32 start;

    if (arc->count <= memberIdx) {
        GF_PANIC_FailPrintf(arc_tool_file, 689, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile(&arc->file, arc->fatOffset + 0xc + memberIdx * 8, 0);
    FS_ReadFile((FSFile *)arc, &start, 4);
    FS_SeekFile(&arc->file, offset + (arc->imageBase + 8 + start), 0);
    FS_ReadFile((FSFile *)arc, dst, size);
}

/*
 * Store the absolute image offset of one archive member through an out
 * parameter.  Only the FAT entry's start word is read; the end word is
 * never touched, which is the 4-byte read rather than 8.
 *
 * The bounds assertion is the same five-argument call ARC_TOOL_LoadHandleMember
 * uses: the count is already in r3 from the guard's own `cmp`, so only
 * the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_GetHandleMemberOffsetOut.c  *       --func ARC_TOOL_GetHandleMemberOffsetOut --addr 0x020494F4 --cc 1.1p1 --arm
 */
void ARC_TOOL_GetHandleMemberOffsetOut(struct ArcHandle *arc, u32 memberIdx, u32 *out)
{
    u32 start;

    if (arc->count <= memberIdx) {
        GF_PANIC_FailPrintf(arc_tool_file, 713, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile(&arc->file, arc->fatOffset + 0xc + memberIdx * 8, 0);
    FS_ReadFile((FSFile *)arc, &start, 4);
    *out = arc->imageBase + 8 + start;
}

/*
 * Return the absolute image offset of one archive member, the value
 * ARC_TOOL_GetHandleMemberOffsetOut writes through a pointer instead.
 *
 * The bounds assertion is the same five-argument call ARC_TOOL_LoadHandleMember
 * uses: the count is already in r3 from the guard's own `cmp`, so only
 * the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_GetHandleMemberOffset.c  *       --func ARC_TOOL_GetHandleMemberOffset --addr 0x02049578 --cc 1.1p1 --arm
 */
u32 ARC_TOOL_GetHandleMemberOffset(struct ArcHandle *arc, u32 memberIdx)
{
    u32 start;

    if (arc->count <= memberIdx) {
        GF_PANIC_FailPrintf(arc_tool_file, 725, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile(&arc->file, arc->fatOffset + 0xc + memberIdx * 8, 0);
    FS_ReadFile((FSFile *)arc, &start, 4);
    return arc->imageBase + 8 + start;
}

/*
 * Argument-swapping shim in front of the FS read: this entry point takes the
 * length before the destination, the reader takes them the other way round.
 * The swap costs the three-way `mov r3, r1 / mov r1, r2 / mov r2, r3`
 * shuffle and nothing else, so there is no frame at all and the call is a
 * tail call through a pool word and `bx ip`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadHandle.c \
 *       --func ARC_TOOL_ReadHandle --addr 0x020495F4 --cc 1.1p1 --arm
 */
void ARC_TOOL_ReadHandle(struct ArcHandleRaw *arc, u32 size, void *dst)
{
    FS_ReadFile((FSFile *)arc, dst, size);
}

int ARC_TOOL_SeekHandle(struct FSFile *file, u32 offset)
{
    return FS_SeekFile((FSFile *)file, offset, 0);
}

u16 ARC_TOOL_GetHandleFileCount(void *arc)
{
    return ((struct ArcHandle *)arc)->count;
}
