/*
 * file:     arc_tool.c
 * unit:     yes
 * function: ARC_TOOL_ReadMemberRangeImpl, ARC_TOOL_LoadMemberRangeImpl, ARC_TOOL_OpenArchive, ARC_TOOL_SeekMember, ARC_TOOL_ReadMember, ARC_TOOL_LoadMember, ARC_TOOL_ReadMemberRange, ARC_TOOL_LoadMemberRange, ARC_TOOL_LoadMemberFromPath, ARC_TOOL_GetArchiveFileCount, ARC_TOOL_GetMemberSize, ARC_TOOL_CreateHandle, ARC_TOOL_CreateHandleFromMemory, ARC_TOOL_ReadHandleHeader, ARC_TOOL_DeleteHandle, ARC_TOOL_LoadHandleMember, ARC_TOOL_ReadHandleMember, ARC_TOOL_GetHandleMemberSize, ARC_TOOL_ReadHandleMemberRange, ARC_TOOL_GetHandleMemberOffsetOut, ARC_TOOL_GetHandleMemberOffset, ARC_TOOL_ReadHandle, ARC_TOOL_SeekHandle, ARC_TOOL_GetHandleFileCount, ARC_UTIL_UploadBgCharFromArchive, ARC_UTIL_UploadBgCharFromHandle, ARC_UTIL_UploadBgChar, ARC_UTIL_RegisterObjCharFromArchive, ARC_UTIL_RegisterObjCharFromHandle, ARC_UTIL_RegisterObjChar, ARC_UTIL_UploadScreenFromHandle, ARC_UTIL_UploadScreen, ARC_UTIL_UploadBgPaletteFromArchive, ARC_UTIL_UploadBgPaletteFromHandle, ARC_UTIL_UploadBgPaletteAddFromArchive, ARC_UTIL_UploadBgPaletteAddFromHandle, ARC_UTIL_UploadBgPaletteAddFromHandleExt, ARC_UTIL_UploadBgPalette, ARC_UTIL_UploadPaletteFromArchiveWhole, ARC_UTIL_UploadPaletteFromHandleWhole, ARC_UTIL_UploadPaletteFromArchive, ARC_UTIL_UploadPaletteFromHandle, ARC_UTIL_UploadPalette, ARC_UTIL_LoadBgCharDataFromArchive, ARC_UTIL_LoadBgCharDataFromHandle, ARC_UTIL_LoadScreenDataFromArchive, ARC_UTIL_LoadScreenDataFromHandle, ARC_UTIL_LoadPaletteDataFromArchive, ARC_UTIL_LoadPaletteDataFromHandle, ARC_UTIL_LoadPaletteBlockFromArchive, ARC_UTIL_LoadPaletteBlockFromHandle, ARC_UTIL_LoadCellBankFromArchive, ARC_UTIL_LoadCellBankFromHandle, ARC_UTIL_LoadMultiCellBankFromArchive, ARC_UTIL_LoadMultiCellBankFromHandle, ARC_UTIL_LoadAnimBankFromArchive, ARC_UTIL_LoadAnimBankFromHandle, ARC_UTIL_LoadMultiAnimBankFromArchive, ARC_UTIL_LoadMultiAnimBankFromHandle
 * address:  0x02048D00
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
 *   func_02030734      0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   ARC_TOOL_gArchiveTable     0x02146A68  data
 *   FS_CloseFile  0x02078A80  arm
 *   FS_ReadFile  0x02078B70  arm
 *   arc_tool_file  0x020A7EE0  data
 *   FS_InitFile             0x020788AC  arm
 *   FS_OpenFile     0x02078C18  arm
 *   FS_CreateFileFromMemory 0x0207A940  arm
 *   FS_SeekFile             0x02078B44  arm
 *   func_02034734           0x02034734  arm
 *   arc_tool_msg_member_range       0x020A7EEC  data
 *   arc_tool_msg_member_bounds  0x020A7F18  data
 *   func_0204968C  0x0204968C  arm
 *   sub_0204A380   0x0204A380  arm
 *   NNS_G2dGetUnpackedCharacterDataEx       0x02062A4C  arm
 *   BG_SYS_LoadTileData       0x02040B1C  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_0204979C       0x0204979C  arm
 *   BG_SYS_CreateTileRun  0x02040B58  arm
 *   func_0204982C  0x0204982C  arm
 *   NNS_G2dGetUnpackedCharacterData       0x02062A00  arm
 *   ARC_UTIL_gScreenLoadFns          0x020A135C  data
 *   sub_02049A18   0x02049A18  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_GetField16  0x0204169C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DecodeTileSource  0x02040AF0  arm
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *   sub_02049B90   0x02049B90  arm
 *   sub_02049BDC   0x02049BDC  arm
 *   ARC_UTIL_gPaletteLoadFns     0x020A1364  data
 *   NNS_G2dGetUnpackedPaletteCompressInfo  0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   func_0207F308  0x0207F308  arm
 *   func_0207F428  0x0207F428  arm
 *   func_0207F5B0  0x0207F5B0  arm
 *   func_0207F65C  0x0207F65C  arm
 *   func_0207F47C  0x0207F47C  arm
 *   func_0207F560  0x0207F560  arm
 *   func_0207F6A8  0x0207F6A8  arm
 *   func_0207F754  0x0207F754  arm
 *   NNS_G2dGetUnpackedCellBank  0x02062820  arm
 *   NNS_G2dGetUnpackedAnimBankEx  0x02062670  arm
 *   NNS_G2dGetUnpackedMultiCellBank  0x02062920  arm
 *   NNSi_G2dGetUnpackedAnimBank  0x0206267C  arm
 *   G3D_SYSTEM_CreateResourcePath 0x02046E90 arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm arm9
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm arm9
 */
#include "g3d_util_shared_types.h"
#include "g3d_light_shared_types.h"

struct ArcFile;

struct FSFile;

struct NitroFileHeader;

typedef signed int     s32;

struct ArcFile {
    u8 file[0x48];
};

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

struct UnpackedGfxBlock {
    u8 pad_00[0x10];
    u32 size;
    void *data;
};

struct UnpackedPalette {
    u8  pad00[8];
    u32 size;
    u8  data[1];
};

struct PaletteBlock {
    u32 fmt;
    u8  pad04[4];
    u32 size;
    u32 data;
};

typedef void (*GfxLoadFn)(u32 data, u32 dest, u32 size);

extern void *func_02030734(u16 heapID, u32 size, int clear, const char *file, int line);

extern u32 func_020307B0(void *p);

extern void DWCi_ScreenDC_FlushRange(int a, int b);

extern void  DC_FlushRange(void *addr, u32 size);

extern void FS_ReadFile(struct ArcHandle *arc, void *dst, u32 size);

extern void FS_CloseFile(void *p);

extern void FS_InitFile(void *file);

extern void FS_OpenFile(struct ArcFile *arc, u32 value);

extern void FS_CreateFileFromMemory(void *file, void *src, u32 size);

extern int FS_SeekFile(struct ArcHandle *arc, u32 pos, u32 origin);

extern void func_02034734(const char *file, u32 line, const char *msg, ...);

extern u32 func_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);

extern void *sub_0204A380(void *a0, u32 a1, u32 a2, u32 a3);

extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);

extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);

extern void ENV_SetResourceSet(void *p);

extern u32 func_0204979C(void *buf, u32 a1, u32 a2);

extern u32 BG_SYS_CreateTileRun(u32 index, const void *src, u32 size);

extern u32 func_0204982C(void *buf, u32 kind, u32 a2, u32 size);

extern s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out);

extern u32 sub_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);

extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);

extern u8 BG_SYS_GetField16(int channel);

extern u32 BG_SYS_GetBuf(int channel);

extern void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset);

extern void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);

extern void func_020409B4(u8 channel);

extern void func_02041B6C(u8 channel);

extern void sub_02049B90(u32 a, u32 b, u32 c, u32 zero, u32 d, u32 e, u16 f);

extern void sub_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);

extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);

extern void func_0207F308(void);

extern void func_0207F428(void);

extern void func_0207F5B0(void);

extern void func_0207F65C(void);

extern void func_0207F47C(void);

extern void func_0207F560(void);

extern void func_0207F6A8(void);

extern void func_0207F754(void);

extern int NNS_G2dGetUnpackedCellBank(int a, int *out);

extern int   NNS_G2dGetUnpackedAnimBankEx(void *ptr, u32 val);

extern int NNS_G2dGetUnpackedMultiCellBank(u32 a, u32 *out);

extern int   NNSi_G2dGetUnpackedAnimBank(void *ptr, u32 val);

void ARC_TOOL_ReadMemberRangeImpl(void *dst, u32 archive_id, u32 member, u32 offset, u32 size);

void *ARC_TOOL_LoadMemberRangeImpl(u32 archive_id, u32 member, u16 heap, u32 offset, u32 size);

void ARC_TOOL_OpenArchive(struct ArcFile *arc, u32 id);

u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 member, u32 base, u32 size);

void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u16 heap);

void ARC_TOOL_ReadMemberRange(void *dst, u32 archive_id, u32 member, u32 offset, u32 size);

void *ARC_TOOL_LoadMemberRange(u32 archive_id, u32 member, u16 heap, u32 offset, u32 size);

void *ARC_TOOL_LoadMemberFromPath(const char *path, u32 a, u16 heap);

u32 ARC_TOOL_GetArchiveFileCount(u32 a);

u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);

void *ARC_TOOL_CreateHandle(u32 id, u16 heap);

void *ARC_TOOL_CreateHandleFromMemory(void *a0, u32 a1, u16 heap);

void ARC_TOOL_ReadHandleHeader(struct ArcHandle *arc);

void ARC_TOOL_DeleteHandle(void *arc);

void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 member, u16 heap);

void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 member, void *dst);

u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 member);

void ARC_TOOL_ReadHandleMemberRange(struct ArcHandle *arc, u32 member, u32 offset, u32 size, void *dst);

void ARC_TOOL_GetHandleMemberOffsetOut(struct ArcHandle *arc, u32 member, u32 *out);

u32 ARC_TOOL_GetHandleMemberOffset(struct ArcHandle *arc, u32 member);

void ARC_TOOL_ReadHandle(struct ArcHandleRaw *arc, u32 size, void *dst);

int ARC_TOOL_SeekHandle(struct FSFile *file, long offset);

u16 ARC_TOOL_GetHandleFileCount(void *obj);

u32 ARC_UTIL_UploadBgCharFromArchive(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);

u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

u32 ARC_UTIL_UploadBgChar(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);

u32 ARC_UTIL_RegisterObjCharFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);

u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);

u32 ARC_UTIL_RegisterObjChar(void *buf, u32 a1, u32 a2);

u32 ARC_UTIL_UploadScreenFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

u32 ARC_UTIL_UploadScreen(void *buf, u32 kind, u32 a2, u32 size);

void ARC_UTIL_UploadBgPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);

void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);

void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

void ARC_UTIL_UploadPalette(void *file, u32 kind, u32 offset, u32 dest, u32 size);

void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadPaletteDataFromHandle(void *a0, u32 a1, u32 a2, void **out, u16 a4);

void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u16 a3);

void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u16 a3);

void *ARC_UTIL_LoadCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadCellBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadMultiCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadMultiCellBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadAnimBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadAnimBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

void *ARC_UTIL_LoadMultiAnimBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

int ARC_UTIL_LoadMember(int a0, int a1, int a2, u16 a3);

void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u16 a3);

extern struct ArcTableInfo ARC_TOOL_gArchiveTable;

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

extern const GfxLoadFn ARC_UTIL_gPaletteLoadFns[];

/*
 * Read one sub-file of one archive into a buffer the caller owns.  The whole
 * archive handle is a 0x48 byte stack local: ARC_TOOL_OpenArchive binds it to the
 * archive named by `archive_id` (it indexes the 235-entry a/x/y/z name table
 * at 0x020A6C58), ARC_TOOL_SeekMember seeks the member and returns its byte size,
 * FS_ReadFile is the read and FS_CloseFile closes the handle again.
 *
 * Nothing survives the call, so this is the one-shot form: a caller that wants
 * the archive to stay open uses func_020490F4 instead.
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
    struct ArcFile h;

    ARC_TOOL_OpenArchive(&h, archiveID);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)(&h), dst, ARC_TOOL_SeekMember((struct ArcHandle *)&h, memberIdx, offset, size));
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
    struct ArcFile h;
    u32 memberSize;
    void *buf;

    ARC_TOOL_OpenArchive(&h, archiveID);
    memberSize = ARC_TOOL_SeekMember((struct ArcHandle *)&h, memberIdx, offset, size);
    buf = func_02030734(heapID, memberSize, 0, arc_tool_file, 0xbb);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)(&h), buf, memberSize);
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
 * entry points and func_02034734, literal for ARC_TOOL_gArchiveTable and the arc_tool.c
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
void ARC_TOOL_OpenArchive(struct ArcFile *arc, u32 archiveID)
{
    FS_InitFile(arc);
    if (ARC_TOOL_gArchiveTable.useRecords == 0) {
        FS_OpenFile(arc, ARC_TOOL_gArchiveTable.entries[archiveID]);
    } else {
        u32 *tbl = (u32 *)ARC_TOOL_gArchiveTable.entries;
        struct ArcRecord *rec = (struct ArcRecord *)tbl + archiveID;
        u32 end = rec->end;
        u32 start = rec->start;

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

    FS_SeekFile(arc, 0xc, 0);
    FS_ReadFile(arc, &tmp, 2);
    fatOffset = tmp;

    FS_SeekFile(arc, fatOffset + 4, 0);
    FS_ReadFile(arc, &info, 6);
    if (info.count <= memberIdx) {
        func_02034734(arc_tool_file, 0xfb, arc_tool_msg_member_range, info.count,
                      memberIdx);
    }

    off = fatOffset + info.offset;
    FS_SeekFile(arc, off + 4, 0);
    FS_ReadFile(arc, &tmp, 4);
    off += tmp;
    FS_SeekFile(arc, fatOffset + 0xc + memberIdx * 8, 0);

    FS_ReadFile(arc, range, 8);
    FS_SeekFile(arc, skip + (off + 8 + range[0]), 0);

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
    struct ArcFile file;
    void *p;
    u32 size;

    FS_InitFile(&file);
    ((void (*)(struct ArcFile *f, const char *path))FS_OpenFile)(&file, path);
    size = ARC_TOOL_SeekMember((struct ArcHandle *)(&file), memberIdx, 0, 0);
    p = func_02030734(heapID, size, 0, arc_tool_file, 0x182);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)(&file), p, size);
    FS_CloseFile(&file);
    return p;
}

u32 ARC_TOOL_GetArchiveFileCount(u32 archiveID)
{
    char buf[0x48];
    int headerSize;
    u16 header[3];

    headerSize = 0;
    ARC_TOOL_OpenArchive((struct ArcFile *)buf, archiveID);
    FS_SeekFile((struct ArcHandle *)buf, 0xc, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)buf, &headerSize, 2);
    FS_SeekFile((struct ArcHandle *)buf, headerSize + 4, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)buf, header, 6);
    FS_CloseFile(buf);
    return header[2];
}

u32 ARC_TOOL_GetMemberSize(u32 archiveID, u32 memberIdx)
{
    char buf[0x48];
    u32 size;

    ARC_TOOL_OpenArchive((struct ArcFile *)buf, archiveID);
    size = ARC_TOOL_SeekMember((struct ArcHandle *)buf, memberIdx, 0, 0);
    FS_CloseFile(buf);
    return size;
}

/*
 * Constructor: take a 0x50-byte record from the debug allocator, tie it to
 * the caller's object through ARC_TOOL_OpenArchive, run the one-time init at
 * ARC_TOOL_ReadHandleHeader and hand the record back.  The allocator's __FILE__/__LINE__
 * pair is the usual ABS32 into the packed string area plus a pooled 0x209,
 * which is not an ARM rotated immediate.
 */
void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID)
{
    void *rec = func_02030734(heapID, 0x50, 0, arc_tool_file, 0x209);

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
    void *handle = func_02030734(heapID, 0x50, 0, arc_tool_file, 0x21f);

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
    FS_SeekFile((struct ArcHandle *)arc, 0xc, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, &arc->fatOffset, 2);
    FS_SeekFile((struct ArcHandle *)arc, arc->fatOffset + 4, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, &scan, 6);
    arc->count = scan.fileCount;
    off = arc->fatOffset + scan.fatSize;
    FS_SeekFile((struct ArcHandle *)arc, off + 4, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, &scan.nameTableSize, 4);
    arc->imageBase = off + scan.nameTableSize;
}

void ARC_TOOL_DeleteHandle(void *handle)
{
    FS_CloseFile(handle);
    func_020307B0(handle);
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
void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 memberIdx, u16 heapID)
{
    u32 range[2];
    void *buf;

    if (arc->count <= memberIdx) {
        func_02034734(arc_tool_file, 613, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile((struct ArcHandle *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, range, 8);
    FS_SeekFile((struct ArcHandle *)arc, arc->imageBase + 8 + range[0], 0);

    buf = func_02030734(heapID, range[1] - range[0], 0, arc_tool_file, 619);
    if (buf != 0) {
        ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, buf, range[1] - range[0]);
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
        func_02034734(arc_tool_file, 642, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile((struct ArcHandle *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, range, 8);
    FS_SeekFile((struct ArcHandle *)arc, arc->imageBase + 8 + range[0], 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, dst, range[1] - range[0]);
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
        func_02034734(arc_tool_file, 665, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile((struct ArcHandle *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, range, 8);
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
        func_02034734(arc_tool_file, 689, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile((struct ArcHandle *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, &start, 4);
    FS_SeekFile((struct ArcHandle *)arc, offset + (arc->imageBase + 8 + start), 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, dst, size);
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
        func_02034734(arc_tool_file, 713, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile((struct ArcHandle *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, &start, 4);
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
        func_02034734(arc_tool_file, 725, arc_tool_msg_member_bounds,
                      arc->count, memberIdx);
    }

    FS_SeekFile((struct ArcHandle *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, &start, 4);
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
    ((s32 (*)(struct FSFile *file, void *buffer, s32 length))FS_ReadFile)((struct FSFile *)arc, dst, size);
}

int ARC_TOOL_SeekHandle(struct FSFile *file, long offset)
{
    return FS_SeekFile((struct ArcHandle *)file, offset, 0);
}

u16 ARC_TOOL_GetHandleFileCount(void *obj)
{
    return ((struct ArcHandle *)obj)->count;
}

u32 ARC_UTIL_UploadBgCharFromArchive(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6)
{
    u32 ret = ARC_UTIL_LoadMember((int)a0, (int)a1, a5, a6);
    return func_0204968C((void *)ret, (u32)a2, (u32)a3, a4, a5);
}

/*
 * Seven-argument entry point of the text-printing layer: resolve a handle
 * through sub_0204A380 from the first two arguments and the last two, then
 * hand that handle plus the middle arguments to ARC_UTIL_UploadBgChar.
 *
 * The sixth argument is read from the caller's stack slot twice, once as
 * sub_0204A380's third argument and once as ARC_UTIL_UploadBgChar's fifth: the
 * compiler will not keep it in a callee-saved register across the first
 * call, because re-reading the incoming slot is free
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The seventh is read with `ldrh`, which is what names it u16.  The third
 * and fourth arguments are parked in r5/r4 because they are live across
 * the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_UploadBgCharFromHandle.c \
 *       --func ARC_UTIL_UploadBgCharFromHandle --addr 0x02049658 --cc 1.1p1 --arm
 */
u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    return ARC_UTIL_UploadBgChar((void *)((u32)sub_0204A380(a, b, f, g)), c, d, e, f);
}

/*
 * The write-into-an-existing-slot counterpart of src/matched/ARC_UTIL_RegisterObjChar.c:
 * the same NNS_G2dGetUnpackedCharacterDataEx lookup and the same "size of zero means the object's
 * own size at +0x10" rule, but the result goes straight into BG_SYS_LoadTileData
 * instead of coming back as a packed handle, and the caller's handle is
 * released either way. The whole body sits inside the `if`, which is why the
 * failed lookup is a forward branch to the release rather than a shared exit
 * block.
 *
 * `and r0, r6, #0xff` is BG_SYS_LoadTileData's first parameter being `u8`, not a
 * mask written in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_UploadBgChar.c \
 *       --func ARC_UTIL_UploadBgChar --addr 0x0204968C --cc 1.1p1 --arm
 */
u32 ARC_UTIL_UploadBgChar(void *buf, u32 a1, u32 a2, u32 a3, u32 unused)
{
    struct UnpackedGfxBlock *res;

    if (NNS_G2dGetUnpackedCharacterDataEx(buf, (void **)(&res)) != 0) {
        if (a3 == 0) {
            a3 = res->size;
        }
        BG_SYS_LoadTileData((u8)a1, (const void *)res->data, a3, a2);
    }

    ENV_SetResourceSet(buf);
    return a3;
}

/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to func_0204979C to be registered, and
 * releases the loader's handle again. Returning 0 on a failed load is the
 * `movs`/`moveq`/`popeq` triple: the load result is tested by the move that
 * stores it, so no separate `cmp` appears.
 *
 * The flag word is the sixth argument and arrives as a halfword, and
 * ARC_UTIL_LoadMember's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * The twin of src/matched/ARC_UTIL_RegisterObjCharFromHandle.c, differing only in which loader it
 * calls. ARC_UTIL_LoadMember has thirteen further callers image-wide and
 * func_0204979C its second caller at 0x02049780, so both resolve through the
 * `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_RegisterObjCharFromArchive.c \
 *       --func ARC_UTIL_RegisterObjCharFromArchive --addr 0x020496E4 --cc 1.1p1 --arm
 */
u32 ARC_UTIL_RegisterObjCharFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = (void *)ARC_UTIL_LoadMember((u32)a0, (u32)a1, (u32)a4, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}

/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to func_0204979C to be registered, and
 * releases the loader's handle again. Returning 0 on a failed load is the
 * `movs`/`moveq`/`popeq` triple: the load result is tested by the move that
 * stores it, so no separate `cmp` appears.
 *
 * The flag word is the sixth argument and arrives as a halfword, and
 * ARC_UTIL_LoadHandleMember's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * ARC_UTIL_LoadHandleMember resolves through the `matched` class against
 * src/matched/ARC_UTIL_LoadHandleMember.c; func_0204979C through the `label` class, its
 * outside witness being the second caller at 0x02049724.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_RegisterObjCharFromHandle.c \
 *       --func ARC_UTIL_RegisterObjCharFromHandle --addr 0x02049740 --cc 1.1p1 --arm
 */
u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = ARC_UTIL_LoadHandleMember(a0, a1, a4, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}

/*
 * Registers a loaded graphics buffer and answers a packed handle: the slot
 * index in the low halfword and the size the caller asked for (or the
 * object's own size at +0x10, when the caller passed zero) in the high one.
 * A failed lookup and a -1 from the allocator both return a plain 0.
 *
 * The two failure paths share one `mov r0, #0` / `pop` block at 0x020497F8.
 * Statements sit between the two guards, so only an explicit `goto` to a
 * trailing `return 0` reproduces that; written as two plain `return 0`
 * statements mwcc predicates both epilogues instead and 53 of 100 bytes move
 * (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *
 * The packed result is written `((u16)a2 << 16) | (u16)slot`, not the other
 * way round: the accumulator of a commutative chain is its second operand
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md),
 * and only this order leaves the low half in r0 and folds the high half in as
 * `orr r0, r0, r1, lsl #16`.
 *
 * NNS_G2dGetUnpackedCharacterDataEx fills a caller-owned pointer through its second argument, so
 * the local is read back twice, once inside the `a2 == 0` arm and once for
 * the unconditional `+0x14` field. That is why the pair of `ldr` from `[sp]`
 * straddles the predicated `ldreq`: the conditional read cannot be shared
 * with the unconditional one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_RegisterObjChar.c \
 *       --func ARC_UTIL_RegisterObjChar --addr 0x0204979C --cc 1.1p1 --arm
 */
u32 ARC_UTIL_RegisterObjChar(void *buf, u32 a1, u32 a2)
{
    struct UnpackedGfxBlock *res;
    s32 slot;

    if (NNS_G2dGetUnpackedCharacterDataEx(buf, (void **)(&res)) == 0) {
        goto fail;
    }

    if (a2 == 0) {
        a2 = res->size;
    }

    slot = BG_SYS_CreateTileRun(a1, (const void *)res->data, a2);
    if (slot == -1) {
        goto fail;
    }

    return ((u16)a2 << 16) | (u16)slot;

fail:
    return 0;
}

/*
 * Byte-correct, capped at MATCH. Blocked on: func_0204982C (0x0204982C) has
 * exactly one branch reference in the whole image, the `bl` at 0x02049824
 * inside this function, and it begins at the first byte past this function's
 * own extent (02049800..0204982C), so no evidence class witnesses it. This
 * used to print EXACT anyway (`compare()` claimed EXACT from literal byte
 * equality alone, without checking that every relocation field had actually
 * been resolved), because the PC24 field's compiler-emitted displacement to
 * the immediately-following address happens to coincide with the image's
 * bytes by plain adjacency, not by attestation; `compare()` now requires
 * `fb.mask` to be entirely hard before claiming EXACT, so this correctly
 * reports MATCH. It graduates for real only once 0x0204982C has an EXACT
 * entry of its own: src/pending/ARC_UTIL_UploadScreen.c is the C for it, stuck at
 * MATCH on the unattestable data address 0x020A135C. ARC_UTIL_LoadHandleMember resolves
 * normally (label, and src/matched/ARC_UTIL_LoadHandleMember.c).
 *
 * A seven-argument front end that loads an archive member and hands the
 * buffer to the flush-and-dispatch worker; the flag word is passed straight
 * through as a halfword rather than having its top bit forced on, which is
 * what distinguishes this family member from src/matched/ARC_UTIL_RegisterObjCharFromHandle.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ARC_UTIL_UploadScreenFromHandle.c \
 *       --func ARC_UTIL_UploadScreenFromHandle --addr 0x02049800 --cc 1.1p1 --arm
 */
u32 ARC_UTIL_UploadScreenFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    return func_0204982C(ARC_UTIL_LoadHandleMember(a0, a1, a5, a6), a2, a3, a4);
}

extern void (*ARC_UTIL_gScreenLoadFns[])(void *addr, u32 a1, u32 size);

/*
 * Byte-correct, capped at MATCH. Blocked on: ARC_UTIL_gScreenLoadFns (0x020A135C) is named
 * by exactly one word in the whole image, the pool word at 0x02049898 inside
 * this function, so the `literal` class has no witness outside the compared
 * range, and being plain data it has no other class available. The range is a
 * single function, so there is no cut to make. It needs a second reference
 * somewhere in the image, which does not exist, or an attested data
 * definition at 0x020A135C. The other three relocations resolve.
 *
 * This is the DMA-flush variant of src/matched/ARC_UTIL_UploadBgChar.c: the same
 * NNS_G2dGetUnpackedCharacterData lookup (the sibling of NNS_G2dGetUnpackedCharacterDataEx), the same "a size of
 * zero means the object's own size at +0x10" rule, then a `DC_FlushRange`
 * over the object's buffer and a dispatch through the five-entry function
 * table at 0x020A135C indexed by the second argument.
 *
 * The buffer pointer is read from the caller-owned local twice, once for the
 * flush and once for the dispatch, because the call between them may write
 * through the pointer the local holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ARC_UTIL_UploadScreen.c \
 *       --func ARC_UTIL_UploadScreen --addr 0x0204982C --cc 1.1p1 --arm
 */
u32 ARC_UTIL_UploadScreen(void *buf, u32 kind, u32 a2, u32 size)
{
    struct UnpackedGfxBlock *res;

    if (NNS_G2dGetUnpackedCharacterData(buf, (void **)(&res)) != 0) {
        if (size == 0) {
            size = res->size;
        }
        DC_FlushRange(res->data, size);
        ARC_UTIL_gScreenLoadFns[kind](res->data, a2, size);
    }

    ENV_SetResourceSet(buf);
    return size;
}

/*
 * Seven-argument front end: load an archive member with the top allocation
 * bit forced on, exactly as src/matched/ARC_UTIL_RegisterObjCharFromArchive.c does, and forward the
 * buffer to ARC_UTIL_UploadBgPalette with two of its six arguments pinned to zero. The
 * handle is not released here; ARC_UTIL_UploadBgPalette does that itself (see its
 * near-miss note in docs/notes/ARC_UTIL_UploadBgPalette.c.txt, which is where its
 * six-argument shape comes from).
 *
 * The two zeros are one `mov r3, #0` reused for the register argument and
 * the stack argument, so the stack store of a4 has to be emitted between the
 * two: writing the zeros first costs a second materialisation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_UploadBgPaletteFromArchive.c \
 *       --func ARC_UTIL_UploadBgPaletteFromArchive --addr 0x0204989C --cc 1.1p1 --arm
 */
void ARC_UTIL_UploadBgPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags)
{
    ARC_UTIL_UploadBgPalette((void *)ARC_UTIL_LoadMember((u32)a0, (u32)a1, (u32)a5, (u16)((flags & 0x7FFF) | 0x8000)),
                  a2, a3, 0, a4, 0);
}

/*
 * The same two-step shape as ARC_UTIL_UploadBgCharFromHandle, but the handle lookup forces
 * the top bit of its u16 selector on: `(g & 0x7fff) | 0x8000`.  0x7fff
 * does not fit an ARM rotated immediate, so it costs a pool word, while
 * 0x8000 is `orr r2, r2, #0x8000` in one instruction; the `lsl #16` /
 * `lsr #16` pair after them is the u16 truncation of the result, not a
 * bitfield (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * read the other way: an equal-amount pair is the narrowing cast).
 *
 * The second call gets two spliced zeros, one in r3 and one in the second
 * outgoing stack slot; a single `mov r3, #0` serves both, which is why it
 * lands between the two stack stores rather than before them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_UploadBgPaletteFromHandle.c \
 *       --func ARC_UTIL_UploadBgPaletteFromHandle --addr 0x020498F4 --cc 1.1p1 --arm
 */
void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    sub_02049A18(sub_0204A380(a, b, f, (u16)((g & 0x7fff) | 0x8000)),
                 c, d, 0, e, 0);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Sound / audio event trigger wrappers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204994C.c \
 *       --addr 0x0204994C --arm
 */
u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = ARC_UTIL_LoadMember(a0, a1, a6, a7);
    return ARC_UTIL_UploadBgPalette((void *)res, a2, a3, a4, a5, 0);
}

u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)ARC_UTIL_LoadHandleMember(a0, a1, a6, a7);
    return ARC_UTIL_UploadBgPalette((void *)res, a2, a3, a4, a5, 0);
}

u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)ARC_UTIL_LoadHandleMember(a0, a1, a6, a7);
    return ARC_UTIL_UploadBgPalette((void *)res, a2, a3, a4, a5, 1);
}

/*
 * arc_tool.c (wave 13): the palette-upload worker the sound/palette front
 * ends of unit_0204994C.c, ARC_UTIL_UploadBgPaletteFromArchive.c and ARC_UTIL_UploadBgPaletteFromHandle.c forward to.
 * Look up the resource's palette block; default the size to the block's own
 * (+0x08); when `add` is non-zero, add it to every entry of the data at +0x0C
 * -- as halfwords (size / 2 of them) when BG_SYS_GetField16 says the channel is
 * not 8-bit, else as bytes; then upload through BG_SYS_DecodeTileSource plus the
 * flag-selected commit (func_02041B6C / func_020409B4) or BG_SYS_PushTileSource, and
 * release the resource either way.  Every `and rN, r7, #0xff` is a callee's
 * u8 channel parameter, not a cast in the source.
 *
 * WHAT CLOSED IT (docs/notes/ARC_UTIL_UploadBgPalette.c.txt: 300 against 296, 122 out):
 * the callees take `u8 channel` and the caller passes the u32 unchanged; the
 * two loops each own a block-scoped counter (a shared `i` makes the compiler
 * hoist one `mov r3, #0` above the arm test, 4 bytes short); and inside each
 * block the counter is declared BEFORE the element pointer (the other order
 * swaps the two registers in both loops, 17 bytes).
 */
u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag)
{
    struct UnpackedPalette *pal;

    if (NNS_G2dGetUnpackedScreenData(file, (void **)(&pal)) != 0) {
        if (size == 0)
            size = pal->size;
        if (add != 0) {
            if (BG_SYS_GetField16((u8)channel) == 0) {
                u32 i;
                u16 *p = (u16 *)pal->data;
                for (i = 0; i < size / 2; i++)
                    p[i] += (u16)add;
            } else {
                u32 i;
                u8 *p = pal->data;
                for (i = 0; i < size; i++)
                    p[i] += (u8)add;
            }
        }
        if ((int)BG_SYS_GetBuf((u8)channel) != 0) {
            BG_SYS_DecodeTileSource((u8)channel, pal->data, size, a2);
            if (flag != 0)
                func_02041B6C(channel);
            else
                func_020409B4(channel);
        } else {
            BG_SYS_PushTileSource((u8)channel, pal->data, size, a2);
        }
    }
    return func_020307B0(file);
}

/*
 * A whole translation unit range, matched as one byte range.
 *
 * Two sibling entry points of the text-printing layer, each a six-to-seven
 * argument forwarder that splices a zero in as the fourth argument of the
 * real worker (sub_02049B90 and sub_02049BDC respectively).
 *
 * The shape is the whole content: `stmdb sp!, {lr}` plus `sub sp, #0xc`
 * builds the outgoing stack argument area, the two incoming stack
 * arguments are lifted out at [sp,#0x10] and [sp,#0x14], and `stm sp,
 * {r3, lr}` writes the displaced r3 and the first lifted argument into
 * the callee's slots in one go.  Only then is r3 reloaded with the
 * spliced 0.  The last argument is read with `ldrh`, which is the only
 * evidence that it is a u16 rather than a word.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02049B40.c \
 *       --addr 0x02049B40 --arm
 */
void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049B90(a, b, c, 0, d, e, f);
}

void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049BDC(a, b, c, 0, d, e, f);
}

/*
 * One of two seven-argument entry points on the cell-actor system, an
 * address apart, that differ only in which half of ARC_UTIL_UploadPalette's dispatch
 * they reach first (ARC_UTIL_LoadHandleMember in ARC_UTIL_UploadPaletteFromHandle, 0x0204A1BC here); both
 * then forward into 0x02049C28 itself.
 *
 * The seventh parameter is a u16: it is read off the caller's stack with
 * `ldrh` (a 32-bit parameter would be `ldr`), masked with the pooled 0x7FFF
 * and re-set to the 0x8000 bit before being passed as the fourth argument of
 * the dispatch call.  0x7FFF is not an ARM immediate, which is why it costs a
 * pool word rather than a `mov`.
 *
 * The second call's first argument is the first call's result: no register is
 * written for it, r0 is simply left as the callee returned it.  Declaring the
 * dispatch call's own first argument as a saved parameter instead costs the
 * function a callee-saved register, a 4-byte frame and 16 bytes.
 *
 * Complements ARC_UTIL_UploadPaletteFromHandle, which is a separate file on purpose: 0x02049C28
 * has five branch references image wide and three of them are inside
 * 0x02049C28 itself, so a `tu` spanning both wrappers loses every witness and
 * only the two single-function ranges keep one each.
 */
void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = ARC_UTIL_LoadMember(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    ARC_UTIL_UploadPalette((void *)r, a2, a3, a4, a5);
}

/*
 * The second half of the pair described in src/matched/ARC_UTIL_UploadPaletteFromArchive.c: same
 * seven-argument shape, reaching ARC_UTIL_LoadHandleMember rather than ARC_UTIL_LoadMember
 * before forwarding into 0x02049C28.
 *
 * Kept as its own file deliberately.  Both halves call 0x02049C28, and
 * 0x02049C28 has five branch references image wide with three of them inside
 * 0x02049C28 itself, so a `tu` span over both wrappers has no witness left
 * for either call and caps at MATCH; as two single-function ranges each is the
 * other's witness and both are EXACT.
 */
void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = (u32)ARC_UTIL_LoadHandleMember(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    ARC_UTIL_UploadPalette((void *)r, a2, a3, a4, a5);
}

/*
 * arc_tool.c (wave 13): load a palette resource into VRAM.  With a loaded
 * resource file: look up its PMCP block (optional) and its PLTT block; when
 * the PLTT block is there, advance its data pointer by `offset`, and when the
 * caller passed size 0 take the block's own size (no PMCP) or the PMCP count
 * times 0x20 (format 3) / 0x200 (anything else), less `offset`; flush the
 * range and dispatch through the eight-entry loader table 0x020A1364 by
 * `kind`, wrapping kinds 2/6/3/7 (source order, which is what the emitted
 * bodies say) in the matching Begin/End extended-palette calls.  The file is
 * released either way.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02049C28.c.txt: 20 bytes out, "a4 in r5 at
 * entry, v separately"):
 *   - there is no separate `v`: the size PARAMETER is the value that is
 *     defaulted, reduced by offset and passed on (`size = ...; size -=
 *     offset;`), which is why the image loads it into r5 at entry and keeps
 *     it there;
 *   - the early `if (file == 0) return;` the note's shape omitted (the
 *     image's `movs sb, r0` / `addeq` / `popeq`);
 *   - the two out-pointer locals declared PLTT first, PMCP second, so PMCP
 *     lands at sp+0 and PLTT at sp+4.
 * The table's const qualifier does not change the bytes.
 */
void ARC_UTIL_UploadPalette(void *file, u32 kind, u32 offset, u32 dest, u32 size)
{
    struct PaletteBlock *pltt;
    u16 *pmcp;
    int cmp;

    if (file == 0)
        return;
    cmp = NNS_G2dGetUnpackedPaletteCompressInfo(file, (void **)(&pmcp));
    if (NNS_G2dGetUnpackedPaletteData(file, (void **)(&pltt)) != 0) {
        pltt->data += offset;
        if (size == 0) {
            if (cmp == 0)
                size = pltt->size;
            else
                size = *pmcp * (pltt->fmt == 3 ? 0x20 : 0x200);
            size -= offset;
        }
        DWCi_ScreenDC_FlushRange(pltt->data, size);
        switch (kind) {
        case 2:
            func_0207F308();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            func_0207F428();
            break;
        case 6:
            func_0207F5B0();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            func_0207F65C();
            break;
        case 3:
            func_0207F47C();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            func_0207F560();
            break;
        case 7:
            func_0207F6A8();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            func_0207F754();
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        default:
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            break;
        }
    }
    func_020307B0(file);
}

/*
 * Cell-actor binding helpers.  Each binds an actor of a given kind through
 * ARC_UTIL_LoadMember (kind table 1, 5-argument form) or ARC_UTIL_LoadHandleMember (kind
 * table 2, wrapper over ARC_UTIL_LoadHandleMemberWithSize), runs the per-kind hook, and releases
 * the actor again when the hook fails.  ARC_UTIL_LoadPaletteBlockFromArchive / ARC_UTIL_LoadPaletteBlockFromHandle are
 * the 4-argument forms and pass 0 as the third argument.
 */
void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterDataEx(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterDataEx(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterData(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterData(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedScreenData(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteDataFromHandle(void *a0, u32 a1, u32 a2, void **out, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedScreenData(res, out)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u16 a3)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, 0, a3);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedPaletteData(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u16 a3)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, 0, a3);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedPaletteData(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCellBank((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadCellBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCellBank((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedAnimBankEx(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

/*
 * A whole translation unit, matched as one byte range.
 */
void *ARC_UTIL_LoadMultiCellBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedAnimBankEx(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadAnimBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedMultiCellBank((u32)res, (u32 *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadAnimBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedMultiCellBank((u32)res, (u32 *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNSi_G2dGetUnpackedAnimBank(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiAnimBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNSi_G2dGetUnpackedAnimBank(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}
