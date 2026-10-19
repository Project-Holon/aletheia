/*
 * file:     arc_util.c
 * unit:     yes
 * function: ARC_UTIL_UploadBgCharFromArchive, ARC_UTIL_UploadBgCharFromHandle, ARC_UTIL_UploadBgChar, ARC_UTIL_RegisterObjCharFromArchive, ARC_UTIL_RegisterObjCharFromHandle, ARC_UTIL_RegisterObjChar, ARC_UTIL_UploadScreenFromHandle, ARC_UTIL_UploadScreen, ARC_UTIL_UploadBgPaletteFromArchive, ARC_UTIL_UploadBgPaletteFromHandle, ARC_UTIL_UploadBgPaletteAddFromArchive, ARC_UTIL_UploadBgPaletteAddFromHandle, ARC_UTIL_UploadBgPaletteAddFromHandleExt, ARC_UTIL_UploadBgPalette, ARC_UTIL_UploadPaletteFromArchiveWhole, ARC_UTIL_UploadPaletteFromHandleWhole, ARC_UTIL_UploadPaletteFromArchive, ARC_UTIL_UploadPaletteFromHandle, ARC_UTIL_UploadPalette, ARC_UTIL_LoadBgCharDataFromArchive, ARC_UTIL_LoadBgCharDataFromHandle, ARC_UTIL_LoadScreenDataFromArchive, ARC_UTIL_LoadScreenDataFromHandle, ARC_UTIL_LoadPaletteDataFromArchive, ARC_UTIL_LoadPaletteDataFromHandle, ARC_UTIL_LoadPaletteBlockFromArchive, ARC_UTIL_LoadPaletteBlockFromHandle, ARC_UTIL_LoadCellBankFromArchive, ARC_UTIL_LoadCellBankFromHandle, ARC_UTIL_LoadMultiCellBankFromArchive, ARC_UTIL_LoadMultiCellBankFromHandle, ARC_UTIL_LoadAnimBankFromArchive, ARC_UTIL_LoadAnimBankFromHandle, ARC_UTIL_LoadMultiAnimBankFromArchive, ARC_UTIL_LoadMultiAnimBankFromHandle, ARC_UTIL_LoadMember, ARC_UTIL_LoadMemberWithSize, ARC_UTIL_LoadHandleMember, ARC_UTIL_LoadHandleMemberWithSize
 * address:  0x02049624
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from arc_util_head.c, arc_util.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free   0x020307B0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   ARC_UTIL_UploadBgChar  0x0204968C  arm
 *   ARC_UTIL_LoadHandleMember   0x0204A380  arm
 *   NNS_G2dGetUnpackedCharacterDataEx       0x02062A4C  arm
 *   BG_SYS_LoadTileData       0x02040B1C  arm
 *   ARC_UTIL_RegisterObjChar       0x0204979C  arm
 *   BG_SYS_CreateTileRun  0x02040B58  arm
 *   ARC_UTIL_UploadScreen  0x0204982C  arm
 *   NNS_G2dGetUnpackedCharacterData       0x02062A00  arm
 *   ARC_UTIL_gScreenLoadFns          0x020A135C  data
 *   ARC_UTIL_UploadBgPalette   0x02049A18  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_GetColorMode  0x0204169C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DecodeTileSource  0x02040AF0  arm
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   ARC_UTIL_UploadPaletteFromArchive   0x02049B90  arm
 *   ARC_UTIL_UploadPaletteFromHandle   0x02049BDC  arm
 *   ARC_UTIL_gPaletteLoadFns     0x020A1364  data
 *   NNS_G2dGetUnpackedPaletteCompressInfo  0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   GX_BeginLoadBGExtPltt  0x0207F308  arm
 *   GX_EndLoadBGExtPltt  0x0207F428  arm
 *   GXS_BeginLoadBGExtPltt  0x0207F5B0  arm
 *   GXS_EndLoadBGExtPltt  0x0207F65C  arm
 *   GX_BeginLoadOBJExtPltt  0x0207F47C  arm
 *   GX_EndLoadOBJExtPltt  0x0207F560  arm
 *   GXS_BeginLoadOBJExtPltt  0x0207F6A8  arm
 *   GXS_EndLoadOBJExtPltt  0x0207F754  arm
 *   NNS_G2dGetUnpackedCellBank  0x02062820  arm
 *   NNS_G2dGetUnpackedAnimBankEx  0x02062670  arm
 *   NNS_G2dGetUnpackedMultiCellBank  0x02062920  arm
 *   NNSi_G2dGetUnpackedAnimBank  0x0206267C  arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm arm9
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   arc_util_file   0x020A7F30  data
 *   ARC_TOOL_ReadMember 0x02048F4C arm arm9
 *   ARC_TOOL_GetMemberSize 0x020490A8 arm arm9
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm arm9
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm arm9
 */
#include "g3d_util_shared_types.h"
#include "arc_tool_shared_types.h"

struct NitroFileHeader;

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

extern u32 GFL_HEAP_Free(void *p);

extern void  DC_FlushRange(void *addr, u32 size);

extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);

extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);


extern u32 BG_SYS_CreateTileRun(u32 index, const void *src, u32 size);

extern u32 ARC_UTIL_UploadScreen(void *buf, u32 kind, u32 dest, u32 size);

extern s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out);

extern u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 offset, u32 add, u32 size, u32 flag);

extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);

extern u8 BG_SYS_GetColorMode(int channel);

extern u32 BG_SYS_GetBuf(int channel);

extern void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset);

extern void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);

extern void BG_SYS_PushTile(u8 channel);

extern void BG_SYS_MarkTileDirty(u8 channel);

extern void ARC_UTIL_UploadPaletteFromArchive(u32 a, u32 b, u32 c, u32 zero, u32 d, u32 e, u16 f);

extern void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);

extern s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);

extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);

extern void GX_BeginLoadBGExtPltt(void);

extern void GX_EndLoadBGExtPltt(void);

extern void *GXS_BeginLoadBGExtPltt(void);

extern void GXS_EndLoadBGExtPltt(void);

extern void GX_BeginLoadOBJExtPltt(void);

extern void GX_EndLoadOBJExtPltt(void);

extern void *GXS_BeginLoadOBJExtPltt(void);

extern void GXS_EndLoadOBJExtPltt(void);

extern int NNS_G2dGetUnpackedCellBank(void *a, s32 *out);

extern int   NNS_G2dGetUnpackedAnimBankEx(void *ptr, u32 val);

extern int NNS_G2dGetUnpackedMultiCellBank(void *a, u32 *out);

extern int   NNSi_G2dGetUnpackedAnimBank(void *ptr, u32 val);

u32 ARC_UTIL_UploadBgCharFromArchive(void *archiveID, void *memberIdx, void *bgId, void *tileOffset, u32 size, u32 heapID, u16 allocFlags);

u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

u32 ARC_UTIL_UploadBgChar(void *buf, u32 bgId, u32 tileOffset, u32 size, u32 unused);

u32 ARC_UTIL_RegisterObjCharFromArchive(u32 archiveID, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags);

u32 ARC_UTIL_RegisterObjCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags);

u32 ARC_UTIL_RegisterObjChar(void *buf, u32 bgId, u32 size);

u32 ARC_UTIL_UploadScreenFromHandle(void *arc, u32 memberIdx, u32 kind, u32 dest, u32 size, u32 heapID, u16 allocFlags);

u32 ARC_UTIL_UploadScreen(void *buf, u32 kind, u32 dest, u32 size);

void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);

void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);

u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);

u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);

u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 offset, u32 add, u32 size, u32 flag);

void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

void ARC_UTIL_UploadPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);

void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);

void ARC_UTIL_UploadPalette(void *file, u32 kind, u32 offset, u32 dest, u32 size);

void *ARC_UTIL_LoadBgCharDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);

void *ARC_UTIL_LoadBgCharDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);

void *ARC_UTIL_LoadScreenDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);

void *ARC_UTIL_LoadScreenDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);

void *ARC_UTIL_LoadPaletteDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);

void *ARC_UTIL_LoadPaletteDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void **out, u16 flags);

void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, void *unpackedOut, u16 flags);

void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, void *unpackedOut, u16 flags);

void *ARC_UTIL_LoadCellBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u8 *unpackedOut, u16 flags);

void *ARC_UTIL_LoadCellBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

void *ARC_UTIL_LoadMultiCellBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

void *ARC_UTIL_LoadMultiCellBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

void *ARC_UTIL_LoadAnimBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u8 *unpackedOut, u16 flags);

void *ARC_UTIL_LoadAnimBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

void *ARC_UTIL_LoadMultiAnimBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

int ARC_UTIL_LoadMember(int archiveID, int memberIdx, int decompress, u16 heapID);

void *ARC_UTIL_LoadHandleMember(void *narc, u32 fileID, u32 decompress, u16 heapID);

extern const GfxLoadFn ARC_UTIL_gPaletteLoadFns[];

u32 ARC_UTIL_UploadBgCharFromArchive(void *archiveID, void *memberIdx, void *bgId, void *tileOffset, u32 size, u32 heapID, u16 allocFlags)
{
    u32 ret = ARC_UTIL_LoadMember((int)archiveID, (int)memberIdx, heapID, allocFlags);
    return ARC_UTIL_UploadBgChar((void *)ret, (u32)bgId, (u32)tileOffset, size, heapID);
}

/*
 * Seven-argument entry point of the text-printing layer: resolve a handle
 * through ARC_UTIL_LoadHandleMember from the first two arguments and the last two, then
 * hand that handle plus the middle arguments to ARC_UTIL_UploadBgChar.
 *
 * The sixth argument is read from the caller's stack slot twice, once as
 * ARC_UTIL_LoadHandleMember's third argument and once as ARC_UTIL_UploadBgChar's fifth: the
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
u32 ARC_UTIL_UploadBgCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 tileOffset, u32 size, u32 heapID, u16 allocFlags)
{
    return ARC_UTIL_UploadBgChar((void *)((u32)ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, allocFlags)), bgId, tileOffset, size, heapID);
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
u32 ARC_UTIL_UploadBgChar(void *buf, u32 bgId, u32 tileOffset, u32 size, u32 unused)
{
    struct UnpackedGfxBlock *res;

    if (NNS_G2dGetUnpackedCharacterDataEx(buf, (void **)(&res)) != 0) {
        if (size == 0) {
            size = res->size;
        }
        BG_SYS_LoadTileData((u8)bgId, (const void *)res->data, size, tileOffset);
    }

    GFL_HEAP_Free(buf);
    return size;
}

/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to ARC_UTIL_RegisterObjChar to be registered, and
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
 * ARC_UTIL_RegisterObjChar its second caller at 0x02049780, so both resolve through the
 * `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_RegisterObjCharFromArchive.c \
 *       --func ARC_UTIL_RegisterObjCharFromArchive --addr 0x020496E4 --cc 1.1p1 --arm
 */
u32 ARC_UTIL_RegisterObjCharFromArchive(u32 archiveID, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags)
{
    void *buf;
    u32 res;

    buf = (void *)ARC_UTIL_LoadMember((u32)archiveID, (u32)memberIdx, (u32)heapID, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = ARC_UTIL_RegisterObjChar(buf, bgId, size);
    GFL_HEAP_Free(buf);
    return res;
}

/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to ARC_UTIL_RegisterObjChar to be registered, and
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
 * src/matched/ARC_UTIL_LoadHandleMember.c; ARC_UTIL_RegisterObjChar through the `label` class, its
 * outside witness being the second caller at 0x02049724.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_RegisterObjCharFromHandle.c \
 *       --func ARC_UTIL_RegisterObjCharFromHandle --addr 0x02049740 --cc 1.1p1 --arm
 */
u32 ARC_UTIL_RegisterObjCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags)
{
    void *buf;
    u32 res;

    buf = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = ARC_UTIL_RegisterObjChar(buf, bgId, size);
    GFL_HEAP_Free(buf);
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
u32 ARC_UTIL_RegisterObjChar(void *buf, u32 bgId, u32 size)
{
    struct UnpackedGfxBlock *res;
    s32 slot;

    if (NNS_G2dGetUnpackedCharacterDataEx(buf, (void **)(&res)) == 0) {
        goto fail;
    }

    if (size == 0) {
        size = res->size;
    }

    slot = BG_SYS_CreateTileRun(bgId, (const void *)res->data, size);
    if (slot == -1) {
        goto fail;
    }

    return ((u16)size << 16) | (u16)slot;

fail:
    return 0;
}

/*
 * Byte-correct, capped at MATCH. Blocked on: ARC_UTIL_UploadScreen (0x0204982C) has
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
u32 ARC_UTIL_UploadScreenFromHandle(void *arc, u32 memberIdx, u32 kind, u32 dest, u32 size, u32 heapID, u16 allocFlags)
{
    return ARC_UTIL_UploadScreen(ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, allocFlags), kind, dest, size);
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
u32 ARC_UTIL_UploadScreen(void *buf, u32 kind, u32 dest, u32 size)
{
    struct UnpackedGfxBlock *res;

    if (NNS_G2dGetUnpackedCharacterData(buf, (void **)(&res)) != 0) {
        if (size == 0) {
            size = res->size;
        }
        DC_FlushRange(res->data, size);
        ARC_UTIL_gScreenLoadFns[kind](res->data, dest, size);
    }

    GFL_HEAP_Free(buf);
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
void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags)
{
    ARC_UTIL_UploadBgPalette((void *)ARC_UTIL_LoadMember((u32)archiveID, (u32)memberIdx, (u32)heapID, (u16)((flags & 0x7FFF) | 0x8000)),
                  channel, offset, 0, size, 0);
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
void ARC_UTIL_UploadBgPaletteFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags)
{
    ARC_UTIL_UploadBgPalette(ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, (u16)((flags & 0x7fff) | 0x8000)),
                 channel, offset, 0, size, 0);
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
u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags)
{
    u32 res = ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    return ARC_UTIL_UploadBgPalette((void *)res, channel, offset, add, size, 0);
}

u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags)
{
    u32 res = (u32)ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    return ARC_UTIL_UploadBgPalette((void *)res, channel, offset, add, size, 0);
}

u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags)
{
    u32 res = (u32)ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    return ARC_UTIL_UploadBgPalette((void *)res, channel, offset, add, size, 1);
}

/*
 * arc_tool.c (wave 13): the palette-upload worker the sound/palette front
 * ends of unit_0204994C.c, ARC_UTIL_UploadBgPaletteFromArchive.c and ARC_UTIL_UploadBgPaletteFromHandle.c forward to.
 * Look up the resource's palette block; default the size to the block's own
 * (+0x08); when `add` is non-zero, add it to every entry of the data at +0x0C
 * -- as halfwords (size / 2 of them) when BG_SYS_GetColorMode says the channel is
 * not 8-bit, else as bytes; then upload through BG_SYS_DecodeTileSource plus the
 * flag-selected commit (BG_SYS_MarkTileDirty / BG_SYS_PushTile) or BG_SYS_PushTileSource, and
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
u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 offset, u32 add, u32 size, u32 flag)
{
    struct UnpackedPalette *pal;

    if (NNS_G2dGetUnpackedScreenData(file, (void **)(&pal)) != 0) {
        if (size == 0)
            size = pal->size;
        if (add != 0) {
            if (BG_SYS_GetColorMode((u8)channel) == 0) {
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
            BG_SYS_DecodeTileSource((u8)channel, pal->data, size, offset);
            if (flag != 0)
                BG_SYS_MarkTileDirty(channel);
            else
                BG_SYS_PushTile(channel);
        } else {
            BG_SYS_PushTileSource((u8)channel, pal->data, size, offset);
        }
    }
    return GFL_HEAP_Free(file);
}

/*
 * A whole translation unit range, matched as one byte range.
 *
 * Two sibling entry points of the text-printing layer, each a six-to-seven
 * argument forwarder that splices a zero in as the fourth argument of the
 * real worker (ARC_UTIL_UploadPaletteFromArchive and ARC_UTIL_UploadPaletteFromHandle respectively).
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
void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 archiveID, u32 memberIdx, u32 kind, u32 dest, u32 size, u16 flags)
{
    ARC_UTIL_UploadPaletteFromArchive(archiveID, memberIdx, kind, 0, dest, size, flags);
}

void ARC_UTIL_UploadPaletteFromHandleWhole(void *arc, u32 memberIdx, u32 kind, u32 dest, u32 size, u16 flags)
{
    ARC_UTIL_UploadPaletteFromHandle(arc, memberIdx, kind, 0, dest, size, flags);
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
void ARC_UTIL_UploadPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags)
{
    u32 buf = ARC_UTIL_LoadMember(archiveID, memberIdx, 0, (u16)((flags & 0x7fff) | 0x8000));
    ARC_UTIL_UploadPalette((void *)buf, kind, offset, dest, size);
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
void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags)
{
    u32 buf = (u32)ARC_UTIL_LoadHandleMember(arc, memberIdx, 0, (u16)((flags & 0x7fff) | 0x8000));
    ARC_UTIL_UploadPalette((void *)buf, kind, offset, dest, size);
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
        DC_FlushRange((void *)pltt->data, size);
        switch (kind) {
        case 2:
            GX_BeginLoadBGExtPltt();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            GX_EndLoadBGExtPltt();
            break;
        case 6:
            GXS_BeginLoadBGExtPltt();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            GXS_EndLoadBGExtPltt();
            break;
        case 3:
            GX_BeginLoadOBJExtPltt();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            GX_EndLoadOBJExtPltt();
            break;
        case 7:
            GXS_BeginLoadOBJExtPltt();
            ARC_UTIL_gPaletteLoadFns[kind](pltt->data, dest, size);
            GXS_EndLoadOBJExtPltt();
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
    GFL_HEAP_Free(file);
}

/*
 * Cell-actor binding helpers.  Each binds an actor of a given kind through
 * ARC_UTIL_LoadMember (kind table 1, 5-argument form) or ARC_UTIL_LoadHandleMember (kind
 * table 2, wrapper over ARC_UTIL_LoadHandleMemberWithSize), runs the per-kind hook, and releases
 * the actor again when the hook fails.  ARC_UTIL_LoadPaletteBlockFromArchive / ARC_UTIL_LoadPaletteBlockFromHandle are
 * the 4-argument forms and pass 0 as the third argument.
 */
void *ARC_UTIL_LoadBgCharDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterDataEx(res, (void **)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadBgCharDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterDataEx(res, (void **)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadScreenDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterData(res, (void **)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadScreenDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterData(res, (void **)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedScreenData(res, (void **)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void **out, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedScreenData(res, out)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, void *unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, 0, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedPaletteData(res, (void **)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, void *unpackedOut, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, 0, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedPaletteData(res, (void **)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadCellBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u8 *unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCellBank(res, (int *)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadCellBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCellBank(res, (int *)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiCellBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedAnimBankEx(res, unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

/*
 * A whole translation unit, matched as one byte range.
 */
void *ARC_UTIL_LoadMultiCellBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedAnimBankEx(res, unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadAnimBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u8 *unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedMultiCellBank(res, (u32 *)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadAnimBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedMultiCellBank(res, (u32 *)unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags)
{
    void *res = (void *)ARC_UTIL_LoadMember(archiveID, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNSi_G2dGetUnpackedAnimBank(res, unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiAnimBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags)
{
    void *res = ARC_UTIL_LoadHandleMember(arc, memberIdx, heapID, flags);
    if (res != 0) {
        if (!NNSi_G2dGetUnpackedAnimBank(res, unpackedOut)) {
            GFL_HEAP_Free(res);
            return 0;
        }
    }
    return res;
}

struct LzHeader {
    u32 sizeAndType;
};

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, char *site, unsigned short tag);

extern void MI_UncompressLZ8(const void *src, void *dest);

void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);

void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 member, void *dst);

u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 member);

int ARC_UTIL_LoadMemberWithSize(int archiveID, int memberIdx, int decompress, u16 heapID, u32 *out);

void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

extern const char  arc_util_file[];


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
        buf = (int)GFL_HEAP_Alloc((u16)((heapID & 0x7fff) | 0x8000), size, 0, (char *)arc_util_file, 1599);
    } else {
        size = ARC_TOOL_GetMemberSize(archiveID, memberIdx);
        buf = (int)GFL_HEAP_Alloc(heapID, size, 0, (char *)arc_util_file, 1603);
    }
    ARC_TOOL_ReadMember((void *)buf, archiveID, memberIdx);
    if (decompress != 0) {
        outBuf = (int)GFL_HEAP_Alloc(heapID, ((struct LzHeader *)buf)->sizeAndType >> 8, 0, (char *)arc_util_file, 1611);
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
        buf = (int)GFL_HEAP_Alloc((u16)((heapID & 0x7fff) | 0x8000), *out, 0, (char *)arc_util_file, 1642);
    } else {
        buf = (int)GFL_HEAP_Alloc(heapID, *out, 0, (char *)arc_util_file, 1646);
    }
    ARC_TOOL_ReadMember((void *)buf, archiveID, memberIdx);
    if (decompress != 0) {
        *out = ((struct LzHeader *)buf)->sizeAndType >> 8;
        outBuf = (int)GFL_HEAP_Alloc(heapID, *out, 0, (char *)arc_util_file, 1656);
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
        buf = GFL_HEAP_Alloc((u16)(((u16)heapID & 0x7FFF) | 0x8000), *out_size, 0, (char *)arc_util_file, 1709);
    } else {
        buf = GFL_HEAP_Alloc((u16)heapID, *out_size, 0, (char *)arc_util_file, 1713);
    }
    if (buf != 0) {
        ARC_TOOL_ReadHandleMember(narc, fileID, buf);
        if (decompress != 0) {
            *out_size = ((struct LzHeader *)buf)->sizeAndType >> 8;
            outBuf = GFL_HEAP_Alloc((u16)heapID, *out_size, 0, (char *)arc_util_file, 1725);
            if (outBuf != 0) {
                MI_UncompressLZ8(buf, outBuf);
                GFL_HEAP_Free(buf);
            }
            buf = outBuf;
        }
    }
    return buf;
}
