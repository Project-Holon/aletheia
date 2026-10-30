/*
 * file:     bmp.c
 * unit:     yes
 * function: BMP_Create, BMP_CreateFromBuffer, BMP_CreateFromVram, BMP_Delete, BMP_GetPixels, BMP_GetWidth, BMP_GetHeight, BMP_GetByteSize, BMP_CopyPixels, BMP_CreateFromArchive, BMP_InitFromCharData, BMP_GetTileBytes, BMP_Blit, BMP_BlitPaletteOffset, BMP_FillRect, BMP_Clear, BMP_Blit4bpp, BMP_Blit8bpp, BMP_Blit4bppTo8bpp, BMP_Blit4bppToVram, BMP_Blit8bppToVram, BMP_FillRect4bpp, BMP_FillRect8bpp, BMP_FillRect4bppVram, BMP_FillRect8bppVram, BMP_ConvertToLinear
 * address:  0x02043678
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from bmp.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   bmp_File       0x020A7E68  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_UTIL_LoadMember       0x0204A1BC  arm
 *   ARC_UTIL_LoadHandleMember 0x0204A380  arm
 *   NNS_G2dGetUnpackedCharacterDataEx       0x02062A4C  arm
 *   OS_Terminate        0x02088234  arm
 *   MIi_CpuCopy32       0x02082A90  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../version.h"
#include "bmp_shared_types.h"
#include "nns_g2d_res_types.h"


/*
 * Where a bitmap's pixels live (Bmp.storage).  A VRAM destination cannot be
 * written a byte at a time, so the VRAM workers read-modify-write halfwords.
 */
enum {
    BMP_STORAGE_OWNED    = 0,   /* pixel buffer allocated with the Bmp, freed with it */
    BMP_STORAGE_BORROWED = 1,   /* caller's buffer, not freed by BMP_Delete */
    BMP_STORAGE_VRAM     = 2    /* caller's buffer in VRAM, halfword writes only */
};


#include "gfl_heap_wrap.h"


#include "arc_util.h"
struct NitroFileHeader;

#include "nns_g2d_anim_bank.h"

#include "os_terminate_processor.h"

#include "mi_memory.h"


struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);

struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);

struct Bmp *BMP_CreateFromVram(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);

void BMP_Delete(struct Bmp *bmp);

void *BMP_GetPixels(const struct Bmp *bmp);

u16 BMP_GetWidth(const struct Bmp *bmp);

u16 BMP_GetHeight(const struct Bmp *bmp);

u32 BMP_GetByteSize(const struct Bmp *bmp);

void BMP_CopyPixels(const struct Bmp *src, struct Bmp *dst);

struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId);

void BMP_InitFromCharData(struct Bmp *bmp, NNSG2dCharacterData *charData, u32 heapId);

u8 BMP_GetTileBytes(struct Bmp *bmp);

void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u16 colorKey);

void BMP_BlitPaletteOffset(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 w, u32 h, u16 colorKey, u16 paletteBase);

void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u16 h, u8 value);

void BMP_Clear(struct Bmp *bmp, u8 value);

void BMP_Blit4bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey);

void BMP_Blit8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey);

void BMP_Blit4bppTo8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey, u8 paletteBase);

void BMP_Blit4bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16 dstX, s16 dstY, u16 w, u16 h, u16 colorKey);

void BMP_Blit8bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16 dstX, s16 dstY, u16 w, u16 h, u16 colorKey);

void BMP_FillRect4bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u32 value);

void BMP_FillRect8bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);

void BMP_FillRect4bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);

void BMP_FillRect8bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);

struct Bmp *BMP_ConvertToLinear(struct Bmp *bmp, u32 keepCopy, u16 heapId);

extern const char bmp_File[];       /* "bmp.c" */

/*
 * TU: bmp.c.  The __FILE__ pointer at 0x020A7E68 reads "bmp.c", lines 97
 * and 103 here.
 *
 * Allocate a bitmap descriptor and its pixel buffer on the same heap.  The
 * width and height reach the descriptor multiplied by 8 (they arrive in
 * tiles), the buffer is widthTiles * heightTiles * tileBytes bytes, and the descriptor is
 * allocated uncleared while the buffer is cleared.  The `__FILE__` pointer
 * is reloaded into r3 for the second call rather than kept, because r3 is
 * an argument register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Create.c \
 *       --func BMP_Create --addr 0x02043678 --cc 1.1p1 --arm
 */
struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId)
{
    struct Bmp *bmp;

    bmp = GFL_HEAP_Alloc(heapId, sizeof(struct Bmp), 0, bmp_File, 97);

    bmp->width  = widthTiles * 8;
    bmp->height = heightTiles * 8;
    bmp->tileBytes  = tileBytes;

    bmp->pixels = GFL_HEAP_Alloc(heapId, tileBytes * (widthTiles * heightTiles), 1,
                                bmp_File, 103);
    bmp->storage = BMP_STORAGE_OWNED;

    return bmp;
}

/*
 * TU: bmp.c (__FILE__ 0x020A7E68, line 123).
 *
 * Wrap a pixel buffer the caller already owns in a fresh descriptor: same
 * 0xc-byte descriptor BMP_Create builds, but nothing is allocated for
 * the pixels and the storage halfword at +0x0a is BMP_STORAGE_BORROWED.  The heap id is the fifth
 * argument and arrives on the stack as a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CreateFromBuffer.c  *       --func BMP_CreateFromBuffer --addr 0x020436FC --cc 1.1p1 --arm
 */
struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes,
                            u16 heapId)
{
    struct Bmp *bmp;

    bmp = GFL_HEAP_Alloc(heapId, sizeof(struct Bmp), 0, bmp_File, 123);

    bmp->width  = widthTiles * 8;
    bmp->height = heightTiles * 8;
    bmp->pixels = pixels;
    bmp->tileBytes  = tileBytes;
    bmp->storage   = BMP_STORAGE_BORROWED;

    return bmp;
}

/*
 * TU: bmp.c (__FILE__ 0x020A7E68, line 148).
 *
 * Wrap a pixel buffer the caller already owns in a fresh descriptor: same
 * 0xc-byte descriptor BMP_Create builds, but nothing is allocated for
 * the pixels and the storage halfword at +0x0a is BMP_STORAGE_VRAM.  The heap id is the fifth
 * argument and arrives on the stack as a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CreateFromVram.c  *       --func BMP_CreateFromVram --addr 0x02043754 --cc 1.1p1 --arm
 */
struct Bmp *BMP_CreateFromVram(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes,
                            u16 heapId)
{
    struct Bmp *bmp;

    bmp = GFL_HEAP_Alloc(heapId, sizeof(struct Bmp), 0, bmp_File, 148);

    bmp->width  = widthTiles * 8;
    bmp->height = heightTiles * 8;
    bmp->pixels = pixels;
    bmp->tileBytes  = tileBytes;
    bmp->storage   = BMP_STORAGE_VRAM;

    return bmp;
}

/*
 * Destructor: release the owned buffer at +0x00 first, but only when the
 * halfword count at +0x0a is zero, then release the object itself.  The
 * guard is inverted in the original (`bne` over the first release), which
 * is the source order of a plain `if (bmp->storage == BMP_STORAGE_OWNED)` with no else.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Delete.c \
 *       --func BMP_Delete --addr 0x020437AC --cc 1.1p1 --arm
 */
void BMP_Delete(struct Bmp *bmp)
{
    if (bmp->storage == BMP_STORAGE_OWNED)
        GFL_HEAP_Free(bmp->pixels);

    GFL_HEAP_Free(bmp);
}

/*
 * TU: bmp.c.  Accessor for the pixel buffer of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetPixels.c  *       --func BMP_GetPixels --addr 0x020437D4 --cc 1.1p1 --arm
 */
void *BMP_GetPixels(const struct Bmp *bmp)
{
    return bmp->pixels;
}

/*
 * TU: bmp.c.  Accessor for the pixel width of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetWidth.c  *       --func BMP_GetWidth --addr 0x020437DC --cc 1.1p1 --arm
 */
u16 BMP_GetWidth(const struct Bmp *bmp)
{
    return bmp->width;
}

/*
 * TU: bmp.c.  Accessor for the pixel height of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetHeight.c  *       --func BMP_GetHeight --addr 0x020437E4 --cc 1.1p1 --arm
 */
u16 BMP_GetHeight(const struct Bmp *bmp)
{
    return bmp->height;
}

/*
 * TU: bmp.c.  Byte size of a bitmap's pixel buffer: tileBytes * ((width / 8) * height / 8). The first division is an `lsr` because the width comes out of a u16 field and is known non-negative; the second is a signed `asr` triple because it divides an int product.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetByteSize.c  *       --func BMP_GetByteSize --addr 0x020437EC --cc 1.1p1 --arm
 */
u32 BMP_GetByteSize(const struct Bmp *bmp)
{
    return bmp->tileBytes * ((bmp->width / 8) * bmp->height / 8);
}

/*
 * TU: bmp.c.  Copy one bitmap's pixels over another's, clipped to whichever
 * of the two buffers is smaller.  Both sizes come from BMP_GetByteSize rather
 * than from the descriptors directly, and the comparison is unsigned
 * (`movlo`), so the sizes are u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CopyPixels.c \
 *       --func BMP_CopyPixels --addr 0x02043814 --cc 1.1p1 --arm
 */
void BMP_CopyPixels(const struct Bmp *src, struct Bmp *dst)
{
    u32 copySize;
    u32 dstSize;

    copySize = BMP_GetByteSize(src);
    dstSize = BMP_GetByteSize(dst);

    if (dstSize < copySize)
        copySize = dstSize;

    MIi_CpuCopy32(src->pixels, dst->pixels, copySize);
}

/*
 * bmp.c's "load a bitmap out of an archive" entry point,
 * 0x0204384C-0x02043900 including its three pool words.  It allocates the
 * twelve-byte bitmap object ("bmp.c", line 266), opens the archive member,
 * asks 0x02062A4C for the decoded header, hands both to the constructor at
 * 0x02043900 and releases the archive handle.  A header that does not
 * resolve is fatal: `OS_Terminate` and then NULL.
 *
 * The archive-handle argument is `(heap & 0x7FFF) | 0x8000` narrowed to a
 * halfword, which is what the `and`/`orr` against the pooled 0x7FFF followed
 * by the `lsl #16`/`lsr #16` pair spells: 0x7FFF is not an ARM rotated
 * immediate and costs a pool word, 0x8000 is one.
 *
 * The zero in r4 is the allocator's alignment argument and the NULL return
 * in one register; it is materialised once, before the call, and survives to
 * the failure epilogue
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The failure arm falls through the `bne`, so the source tests `== 0` and
 * not the success condition
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to the constructor at 0x02043900 resolves on the `matched` class
 * through src/matched/unit_02043900.c, which lives in this same shard, so
 * `manifest --verify --shard pkt_0204384C` has to run twice from a cold
 * shard: the first pass records 0x02043900 and the second one sees it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204384C.c \
 *       --addr 0x0204384C --cc 1.1p1 --arm
 */
struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId)
{
    struct Bmp *bmp;
    void       *resource;
    NNSG2dCharacterData *charData;

    bmp = (struct Bmp *)GFL_HEAP_Alloc(heapId, sizeof(struct Bmp), 0, bmp_File, 266);
    resource = (void *)ARC_UTIL_LoadMember(arcId, memberId, compressed, (u16)((heapId & 0x7FFF) | 0x8000));
    if (NNS_G2dGetUnpackedCharacterDataEx(resource, (void **)(&charData)) == 0) {
        OS_Terminate();
        return 0;
    }
    BMP_InitFromCharData(bmp, charData, heapId);
    GFL_HEAP_Free(resource);
    return bmp;
}

#if LANGUAGE == LANGUAGE_JAPANESE
/* Same as BMP_CreateFromArchive, but reads the member from an open archive handle. */
void *ARC_UTIL_LoadHandleMember(void *narc, u32 fileID, u32 decompress, u16 heapID);

struct Bmp *BMP_CreateFromHandle(void *arc, u32 memberId, u32 compressed, u32 heapId)
{
    struct Bmp *bmp;
    void       *resource;
    NNSG2dCharacterData *charData;

    bmp = (struct Bmp *)GFL_HEAP_Alloc(heapId, sizeof(struct Bmp), 0, bmp_File, 297);
    resource = (void *)ARC_UTIL_LoadHandleMember(arc, memberId, compressed, (u16)((heapId & 0x7FFF) | 0x8000));
    if (NNS_G2dGetUnpackedCharacterDataEx(resource, (void **)(&charData)) == 0) {
        OS_Terminate();
        return 0;
    }
    BMP_InitFromCharData(bmp, charData, heapId);
    GFL_HEAP_Free(resource);
    return bmp;
}
#endif

/*
 * bmp.c's bitmap constructor, 0x02043900-0x02043994 including its two pool
 * words.  The file-name pool word is 0x020A7E68, which spells "bmp.c", and
 * the line number is 321.  The accessor that follows at 0x02043994 is kept
 * in its own file so its manifest entry survives
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * The header the constructor reads is a resource record: two halfword cell
 * counts at +0 and +2 (stored back multiplied by eight, so the bitmap's +4
 * and +6 are pixel extents and the record's are tiles), a format word at +4,
 * a byte size at +0x10 and the source pointer at +0x14.  Format 3 means a
 * +8 of 0x20 and format 4 means 0x40; anything else leaves +8 untouched.
 *
 * The literal zero is written once into r6 and spends its life as three
 * different things: the allocator's alignment argument, the halfword stored
 * at +0xA, and nothing else
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The format test is a two-case `switch`, not an `if`/`else if` chain, and
 * the difference is four bytes and the whole tail's schedule: the chain
 * predicates the first arm in place (`moveq`/`strheq` then `beq` over the
 * rest) and needs no joining `b`, while the switch puts the first case out
 * of line at 0x0204396C and reaches the join with the `b` at 0x02043968.
 * With the chain the two stores after the allocation also come out in the
 * other order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02043900.c \
 *       --addr 0x02043900 --cc 1.1p1 --arm
 */
void BMP_InitFromCharData(struct Bmp *bmp, NNSG2dCharacterData *charData, u32 heapId)
{
    bmp->width = charData->W * 8;
    bmp->height = charData->H * 8;
    bmp->pixels = GFL_HEAP_Alloc(heapId, charData->szByte, 0, bmp_File, 321);
    bmp->storage = BMP_STORAGE_OWNED;
    switch (charData->pixelFmt) {
    case 3:
        bmp->tileBytes = BMP_TILE_BYTES_4BPP;
        break;
    case 4:
        bmp->tileBytes = BMP_TILE_BYTES_8BPP;
        break;
    }
    MIi_CpuCopy32(charData->pRawData, bmp->pixels, charData->szByte);
}

/*
 * bmp.c's accessor for the halfword at +8, the field the blit dispatcher at
 * 0x020439A0 compares between source and destination.  The `ldrh` followed
 * by `and r0, r0, #0xff` is the field's own width against the function's:
 * the field is a halfword and the return type is a byte, so the truncation
 * is at the return, not at the load.  No relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetTileBytes.c \
 *       --func BMP_GetTileBytes --addr 0x02043994 --cc 1.1p1 --arm
 */
u8 BMP_GetTileBytes(struct Bmp *bmp)
{
    return bmp->tileBytes;
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's nine-argument blit dispatcher.  Source and destination bitmaps must agree
 * on the halfword at +8; after that the halfword at +0xA of the destination picks
 * one of two families and the +8 value picks between the 0x20 member of that
 * family and the general one.
 *
 * The two families have different prototypes, and that is what the shift
 * pairs in the second arm are: the 0x020445F4 family takes the two register
 * coordinates and the last two stack arguments as `u16` and the middle two
 * as `s16`, so every one of the six is re-extended at the call
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * does not apply; these are equal-amount pairs, plain narrowing casts).  The
 * 0x02043B98 family takes all nine wide and needs none of it.  This
 * function's own parameters must therefore be the wide types: a `u16`
 * parameter would arrive already extended and the call would not re-extend
 * it.
 *
 * Both branch polarities are the source order
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): the `!= 2` arm
 * falls through, and inside each arm the `== 0x20` arm falls through.  The
 * five outgoing stack stores are written out in both arms of the first
 * family and the compiler tail-merges them ahead of the `cmp`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md); in the
 * second family it keeps two copies instead, because the narrowing makes the
 * two blocks different lengths.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Blit.c \
 *       --func BMP_Blit --addr 0x020439A0 --cc 1.1p1 --arm
 */
void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY,
                   int dstX, int dstY, u32 w, u32 h, u16 colorKey)
{
    if (src->tileBytes != dst->tileBytes) {
        return;
    }
    if (dst->storage != BMP_STORAGE_VRAM) {
        if (src->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_Blit4bpp(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        } else {
            BMP_Blit8bpp(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        }
    } else {
        if (src->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_Blit4bppToVram(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        } else {
            BMP_Blit8bppToVram(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        }
    }
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's ten-argument forwarder onto 0x0204427C.  The first four arguments
 * pass through in their registers; the six stacked ones are copied down to
 * the outgoing frame, and the last two are re-read narrow: the ninth with a
 * plain `ldrh` (the parameter and the callee's are both halfwords, so the
 * load is the declared width and nothing else is needed) and the tenth with
 * `ldrh` plus `and ip, ip, #0xff`, which is a halfword parameter narrowed to
 * the callee's byte one.  A word parameter narrowed to a byte would have
 * been a single `ldrb` off the home slot, so the `ldrh` is what names the
 * incoming width.
 *
 * Every one of the 72 concrete bytes is reproduced.  The single relocation
 * stays wildcarded: 0x0204427C is called from here and from nowhere else in
 * the image, so the `label` class has no witness outside the compared range,
 * it is not in the manifest, and a one-function range admits no cut.  It
 * closes when 0x0204427C is matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BMP_BlitPaletteOffset.c \
 *       --func BMP_BlitPaletteOffset --addr 0x02043AAC --cc 1.1p1 --arm
 */
void BMP_BlitPaletteOffset(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY,
                   u32 dstX, u32 dstY, u32 w, u32 h, u16 colorKey,
                   u16 paletteBase)
{
    BMP_Blit4bppTo8bpp(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey, paletteBase);
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's six-argument fill dispatcher, the single-bitmap sibling of the
 * blit dispatcher at 0x020439A0: the same two-level switch on the source
 * bitmap's +0xA and +8 halfwords, over four workers, but with nothing to
 * narrow, so the two outgoing stack words are one `stm sp, {r4, lr}` written
 * out in each arm rather than a tail-merged run of `str`s.
 *
 * Both `ldrh`s are hoisted ahead of their `cmp`s and the +8 load is issued
 * even on the path that will not use it; that is scheduling, not a third
 * read of the struct.
 *
 * The fall-through arm is the source order in both tests
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): `!= 2` first,
 * then `== 0x20`.
 *
 * Every one of the 104 concrete bytes is reproduced; all four relocations
 * stay wildcarded for the same reason as src/pending/BMP_Blit.c: each of
 * the four fill workers is called from this dispatcher and from nowhere else
 * in the image, so no site has a `label` witness outside the compared range,
 * none of the four is in the manifest, and the range is one function so
 * there is no cut.  0x02044CE0 already has a near-miss note,
 * docs/notes/BMP_FillRect8bpp.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BMP_FillRect.c \
 *       --func BMP_FillRect --addr 0x02043AF4 --cc 1.1p1 --arm
 */
void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u16 h, u8 value)
{
    if (bmp->storage != BMP_STORAGE_VRAM) {
        if (bmp->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_FillRect4bpp(bmp, x, y, w, h, value);
        } else {
            BMP_FillRect8bpp(bmp, x, y, w, h, value);
        }
    } else {
        if (bmp->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_FillRect4bppVram(bmp, x, y, w, h, value);
        } else {
            BMP_FillRect8bppVram(bmp, x, y, w, h, value);
        }
    }
}

/*
 * Clears a tiled character buffer to a constant pixel value.  The tile
 * count is (width/8) * (height/8) and the byte count is that times the
 * per-tile size at +8, 0x20 for 4bpp and 0x40 for 8bpp.  In the 4bpp case
 * the fill value is a nibble, so it is replicated into both halves of the
 * byte before the fill.
 */
void BMP_Clear(struct Bmp *bmp, u8 value)
{
    u32 size = ((u32)bmp->width >> 3) * ((u32)bmp->height >> 3) * bmp->tileBytes;

    if (bmp->tileBytes == BMP_TILE_BYTES_4BPP) {
        value = (value & 0xf) | ((value & 0xf) << 4);
    }

    MI_CpuFill8(bmp->pixels, value, size);
}

static inline s32 ClipBlitRect(struct Bmp *src, const struct Bmp *dst, s32 *srcX, s32 *srcY,
                           s32 *dstX, s32 *dstY, u32 *w, u32 *h)
{
    u32 clippedH = *h;
    u32 clippedW = *w;
    if (clippedW > src->width)
        clippedW = src->width;
    if (*dstX >= dst->width || *dstX <= -(s32)clippedW)
        return 0;
    if (clippedH > src->height)
        clippedH = src->height;
    if (*dstY >= dst->height || *dstY <= -(s32)clippedH)
        return 0;
    if (*dstX < 0) {
        clippedW += *dstX;
        *srcX -= *dstX;
        *dstX = 0;
    } else if (*dstX + clippedW > dst->width) {
        clippedW -= *dstX + clippedW - dst->width;
    }
    if (*dstY < 0) {
        clippedH += *dstY;
        *srcY -= *dstY;
        *dstY = 0;
    } else if (*dstY + clippedH > dst->height) {
        clippedH -= *dstY + clippedH - dst->height;
    }
    *w = clippedW;
    *h = clippedH;
    return 1;
}

/*
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination,
 * byte read-modify-write of one nibble, optional colour key (0xFFFF =
 * none).  The 4bpp sibling of BMP_Blit8bpp (same dispatcher arm, same
 * inlined clip helper, same parameter types) and the byte-store sibling
 * of BMP_Blit4bppToVram.
 *
 * Levers on top of BMP_Blit8bpp's, each measured:
 *   - the store is written `(v << sh) | (*p & (0xf0 >> sh))`: the other
 *     operand order lets the compiler hoist the *p load above the source
 *     read, which costs a spill slot (984 bytes against 948);
 *   - both loops read the source through a pointer q computed BEFORE the
 *     destination pointer, with the source tile-row local assigned first:
 *     the preheader then computes the source row and product first, as the
 *     image does (100 out otherwise).
 */
void BMP_Blit4bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY,
                   u32 w, u32 h, u16 colorKey)
{
    s32 srcRowTiles, dstRowTiles;
    u32 row, col;
    s32 curDstX, curSrcX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u32 pixel, shift;
    u8 *dstPtr;
    u8 *srcPtr;

    if (!ClipBlitRect(src, dst, &srcX, &srcY, &dstX, &dstY, &w, &h))
        return;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curDstX++, curSrcX++) {
                srcTileY = (srcY * 4) & 0x3fe0;
                srcPtr = (u8 *)(src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0)
                           + srcTileY * srcRowTiles + ((srcY * 4) & 0x1c));
                dstTileY = (dstY * 4) & 0x3fe0;
                dstPtr = (u8 *)(dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0)
                           + dstTileY * dstRowTiles);
                dstPtr += (dstY * 4) & 0x1c;
                shift = (u32)(curDstX << 31) >> 29;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                *dstPtr = (pixel << shift) | (*dstPtr & (0xf0 >> shift));
            }
    } else {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curSrcX++, curDstX++) {
                srcKeyedTileY = (srcY * 4) & 0x3fe0;
                srcPtr = (u8 *)(src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0)
                           + srcKeyedTileY * srcRowTiles + ((srcY * 4) & 0x1c));
                dstKeyedTileY = (dstY * 4) & 0x3fe0;
                dstPtr = (u8 *)(dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0)
                           + dstKeyedTileY * dstRowTiles);
                dstPtr += (dstY * 4) & 0x1c;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                if (pixel != colorKey) {
                    shift = (u32)(curDstX << 31) >> 29;
                    *dstPtr = (pixel << shift) | (*dstPtr & (0xf0 >> shift));
                }
            }
    }
}

/*
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination,
 * byte stores, optional colour key (0xFFFF = none).  Reached from the blit
 * dispatcher BMP_Blit's first arm (destination not in VRAM), which passes all nine
 * arguments wide; the key is ldrh'd off the stack here, so it is u16 on
 * this side.
 *
 * The prologue is an inlined clip helper returning a flag (the image's
 * mov r4,#0 / mov r4,#1 / cmp r4,#0).  Width and height are clamped to the
 * source, the destination origin is rejected when fully outside, and a
 * negative origin is folded into the width/height and the source origin.
 * All the comparisons against the clipped extents are unsigned
 * (movhi/subhi) and those against the destination origin signed (bge/bgt),
 * which is what fixes the u32 extents and the s32 origins.
 *
 * Levers, each measured (compiled bytes out):
 *   - dst is `const struct Surf *` in the helper: that is what makes the
 *     compiler re-read dst->width after the clip (812 bytes without);
 *   - the helper reads *h BEFORE *w into its locals (88 out; 701 the
 *     other way);
 *   - the keyed loop reads the source through a pointer q and tests *q
 *     (14 out; a u8 temporary gives 65 and a different schedule);
 *   - the inner loop headers: dxx before xx in the initialisers, and the
 *     keyed loop steps xx before dxx (a three-register rotation, 12 -> 4
 *     -> 0);
 *   - the address arithmetic is the family's single integer sum over
 *     (u32)pixels (BMP_FillRect8bpp) with one tile-row local per address.
 */
void BMP_Blit8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY,
                   u32 w, u32 h, u16 colorKey)
{
    s32 srcRowTiles, dstRowTiles;
    u32 row, col;
    s32 curDstX, curSrcX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u8 pixel;
    u8 *dstPtr;
    u8 *srcPtr;

    if (!ClipBlitRect(src, dst, &srcX, &srcY, &dstX, &dstY, &w, &h))
        return;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curDstX++, curSrcX++) {
                srcTileY = (srcY * 8) & 0x7fc0;
                pixel = *(u8 *)(src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0)
                            + srcTileY * srcRowTiles + ((srcY * 8) & 0x38));
                dstTileY = (dstY * 8) & 0x7fc0;
                *(u8 *)((uptr)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                        + dstTileY * dstRowTiles + ((dstY * 8) & 0x38)) = pixel;
            }
    } else {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curSrcX++, curDstX++) {
                srcKeyedTileY = (srcY * 8) & 0x7fc0;
                srcPtr = (u8 *)(src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0)
                           + srcKeyedTileY * srcRowTiles + ((srcY * 8) & 0x38));
                dstKeyedTileY = (dstY * 8) & 0x7fc0;
                dstPtr = (u8 *)(dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                           + dstKeyedTileY * dstRowTiles);
                dstPtr += (dstY * 8) & 0x38;
                if (*srcPtr != colorKey)
                    *dstPtr = *srcPtr;
            }
    }
}

/*
 * bmp.c blit worker, 4bpp tiled source expanded onto an 8bpp tiled
 * destination with a palette offset: every source nibble is widened to a
 * byte and `pal` is added to it unless it is zero.  With key == 0xFFFF every
 * pixel is stored (a zero nibble stays zero); otherwise zero nibbles are
 * skipped.  Reached only through the forwarder BMP_BlitPaletteOffset, whose narrowing
 * loads fix the u16 key and u8 pal.  Same inlined clip helper and parameter
 * types as BMP_Blit4bpp / BMP_Blit8bpp; source-side masks are the 4bpp ones
 * (0x3fe0 / 0x1c), destination-side the 8bpp ones (0x7fc0 / 0x38).
 *
 * Three levers in the keyed loop, each measured against
 * docs/notes/pkt_02043B98.c.txt's 276-byte best:
 *   - the source pointer is computed BEFORE the destination pointer (as in
 *     BMP_Blit4bpp) and the keyed store is `v += pal; *p = v;` inside the
 *     braces: 888 bytes, 114 out (q-then-p with `*p = v + pal` is 880);
 *   - `xx * 4` bound to a named temporary (`xx4`) in the keyed loop:
 *     4 out (tools/permuter.py anneal, then ablated to this one lever);
 *   - the keyed source pointer is plain pointer arithmetic on src->pixels,
 *     not the `(u32)` sum: that fixes the last `add`/`ldrb` operand order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Blit4bppTo8bpp.c \
 *       --func BMP_Blit4bppTo8bpp --addr 0x0204427C --cc 1.1p1 --arm
 */
void BMP_Blit4bppTo8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY,
                   u32 w, u32 h, u16 colorKey, u8 paletteBase)
{
    s32 srcRowTiles, dstRowTiles;
    u32 row, col;
    s32 curDstX, curSrcX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u32 pixel;
    u8 *dstPtr;
    u8 *srcPtr;
    s32 srcX4;

    if (!ClipBlitRect(src, dst, &srcX, &srcY, &dstX, &dstY, &w, &h))
        return;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curDstX++, curSrcX++) {
                srcTileY = (srcY * 4) & 0x3fe0;
                srcPtr = (u8 *)(src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0)
                           + srcTileY * srcRowTiles + ((srcY * 4) & 0x1c));
                dstTileY = (dstY * 8) & 0x7fc0;
                dstPtr = (u8 *)(dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                           + dstTileY * dstRowTiles);
                dstPtr += (dstY * 8) & 0x38;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                if (pixel != 0)
                    pixel += paletteBase;
                *dstPtr = pixel;
            }
    } else {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curSrcX++, curDstX++) {
                srcKeyedTileY = (srcY * 4) & 0x3fe0;
                dstKeyedTileY = (dstY * 8) & 0x7fc0;
                srcX4 = curSrcX * 4;
                srcPtr = src->pixels + ((curSrcX >> 1) & 3) + (srcX4 & 0x3fe0) + srcKeyedTileY * srcRowTiles
                    + ((srcY * 4) & 0x1c);
                dstPtr = (u8 *)(dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                           + dstKeyedTileY * dstRowTiles);
                dstPtr += (dstY * 8) & 0x38;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                if (pixel != 0) {
                    pixel += paletteBase;
                    *dstPtr = pixel;
                }
            }
    }
}

/*
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination that
 * is written a HALFWORD at a time (BMP_FillRect4bppVram's read-modify-write
 * store), with an optional colour key (0xFFFF = none).  Reached from the
 * blit dispatcher BMP_Blit's VRAM-destination arm, whose shift pairs give
 * the narrow parameter types (x, y, w, h u16; dx, dy s16); the key is
 * loaded with ldrh here, so it is u16 on this side.  The plain and keyed
 * loops are written out in full, each with its OWN pair of tile-row
 * locals (sharing one pair across both loops costs ~150 bytes of
 * allocation).
 *
 * The clip against the destination goes through a fresh temporary t.
 * Reusing xend/yend for the difference makes the compiler emit the
 * conditional add with the reused variable as the first operand
 * (add fp, r5, r2) where the image has add fp, r2, r5; that was the
 * last 4 bytes.
 */
void BMP_Blit4bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16 dstX, s16 dstY, u16 w, u16 h, u16 colorKey)
{
    s32 srcXEnd, srcYEnd, srcRowTiles, dstRowTiles;
    s32 curSrcY, curSrcX, curDstY, curDstX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    uptr srcAddr, dstAddr;
    s32 dstOdd;
    u32 word;
    u16 highByte, lowByte;
    s32 dstRoom;
    u32 pixel, shift;
    dstRoom = dst->width - dstX;
    if (dstRoom < w)
        srcXEnd = srcX + dstRoom;
    else
        srcXEnd = w + srcX;
    dstRoom = dst->height - dstY;
    if (dstRoom < h)
        srcYEnd = srcY + dstRoom;
    else
        srcYEnd = h + srcY;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcTileY = (curSrcY * 4) & 0x3fe0;
                    srcAddr = (uptr)src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0) + srcTileY * srcRowTiles;
                    srcAddr += (curSrcY * 4) & 0x1c;
                    dstTileY = (curDstY * 4) & 0x3fe0;
                    dstAddr = (uptr)dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0) + dstTileY * dstRowTiles;
                    dstAddr += (curDstY * 4) & 0x1c;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        dstOdd = 1;
                    } else
                        dstOdd = 0;
                    word = *(u16 *)dstAddr;
                    highByte = word >> 8;
                    lowByte = word & 0xff;
                    pixel = (*(u8 *)srcAddr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                    shift = (u32)(curDstX << 31) >> 29;
                    if (dstOdd == 0)
                        *(u16 *)dstAddr = (((0xf0 >> shift) & lowByte) | (pixel << shift)) | (highByte << 8);
                    else
                        *(u16 *)dstAddr = (((highByte & (0xf0 >> shift)) | (pixel << shift)) << 8) | lowByte;
                }
    } else {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcKeyedTileY = (curSrcY * 4) & 0x3fe0;
                    srcAddr = (uptr)src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0) + srcKeyedTileY * srcRowTiles;
                    srcAddr += (curSrcY * 4) & 0x1c;
                    dstKeyedTileY = (curDstY * 4) & 0x3fe0;
                    dstAddr = (uptr)dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0) + dstKeyedTileY * dstRowTiles;
                    dstAddr += (curDstY * 4) & 0x1c;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        dstOdd = 1;
                    } else
                        dstOdd = 0;
                    word = *(u16 *)dstAddr;
                    highByte = word >> 8;
                    lowByte = word & 0xff;
                    pixel = (*(u8 *)srcAddr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                    if (pixel != colorKey) {
                        shift = (u32)(curDstX << 31) >> 29;
                        if (dstOdd == 0)
                            *(u16 *)dstAddr = (((0xf0 >> shift) & lowByte) | (pixel << shift)) | (highByte << 8);
                        else
                            *(u16 *)dstAddr = (((highByte & (0xf0 >> shift)) | (pixel << shift)) << 8) | lowByte;
                    }
                }
    }
}

/*
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination
 * written a HALFWORD at a time: when the destination byte is odd the
 * store covers it and the byte before, both taken from the source pair
 * ending at the source pixel; otherwise the source pair starting at it.
 * Optional colour key (0xFFFF = none), compared against the source byte.
 * Reached from BMP_Blit's VRAM-destination arm (x, y, w, h u16; dx, dy s16;
 * the key is ldrh'd, so u16 here).
 *
 * The same four levers as BMP_Blit4bppToVram, all measured:
 *   - the address is one integer sum over (u32)pixels with the in-tile
 *     row added afterwards;
 *   - each of the four tile-row masks has its own function-scope local
 *     (shared locals: 149 out; none: 31);
 *   - in the odd arm d is decremented BEFORE the two loads, which keeps
 *     the shared first load in each arm (326 out otherwise);
 *   - the clip goes through a fresh temporary t with u16 x/y; reusing
 *     xend/yend flips the operands of the conditional add (4 out), and
 *     a fresh t with s32 x/y reshuffles the allocation (167 out).
 */
void BMP_Blit8bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16 dstX, s16 dstY, u16 w, u16 h, u16 colorKey)
{
    s32 srcXEnd, srcYEnd, srcRowTiles, dstRowTiles;
    s32 curSrcY, curSrcX, curDstY, curDstX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    uptr srcAddr, dstAddr;
    u16 word;
    s32 dstRoom;
    dstRoom = dst->width - dstX;
    if (dstRoom < w)
        srcXEnd = srcX + dstRoom;
    else
        srcXEnd = w + srcX;
    dstRoom = dst->height - dstY;
    if (dstRoom < h)
        srcYEnd = srcY + dstRoom;
    else
        srcYEnd = h + srcY;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcTileY = (curSrcY * 8) & 0x7fc0;
                    srcAddr = (uptr)src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0) + srcTileY * srcRowTiles;
                    srcAddr += (curSrcY * 8) & 0x38;
                    dstTileY = (curDstY * 8) & 0x7fc0;
                    dstAddr = (uptr)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0) + dstTileY * dstRowTiles;
                    dstAddr += (curDstY * 8) & 0x38;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        word = (((u8 *)srcAddr)[0] << 8) | ((u8 *)srcAddr)[-1];
                    } else {
                        word = ((u8 *)srcAddr)[0] | (((u8 *)srcAddr)[1] << 8);
                    }
                    *(u16 *)dstAddr = word;
                }
    } else {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcKeyedTileY = (curSrcY * 8) & 0x7fc0;
                    srcAddr = (uptr)src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0) + srcKeyedTileY * srcRowTiles;
                    srcAddr += (curSrcY * 8) & 0x38;
                    dstKeyedTileY = (curDstY * 8) & 0x7fc0;
                    dstAddr = (uptr)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0) + dstKeyedTileY * dstRowTiles;
                    dstAddr += (curDstY * 8) & 0x38;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        word = (((u8 *)srcAddr)[0] << 8) | ((u8 *)srcAddr)[-1];
                    } else {
                        word = ((u8 *)srcAddr)[0] | (((u8 *)srcAddr)[1] << 8);
                    }
                    if (*(u8 *)srcAddr != colorKey)
                        *(u16 *)dstAddr = word;
                }
    }
}

/*
 * bmp.c fill worker, 4bpp tiled (two pixels per byte), reached from the
 * fill dispatcher BMP_FillRect.  Clips right/bottom before the loops and
 * left/top per pixel (signed cmp/cmpge/blt triple), then merges the
 * nibble: odd x takes the high nibble, even x the low one.
 *
 * THE LEVERS (2026-09-22, wave 10), each measured:
 *   - the address is one integer sum over (u32)s->pixels, with only the
 *     tile-row mask lifted into a function-scope local (same lever as
 *     BMP_FillRect8bpp);
 *   - the in-tile row is added to the POINTER afterwards (`p += ...`),
 *     which is what makes the load/store `[p, row]` rather than
 *     `[row, p]` (6 out when it is a fifth term of the sum);
 *   - `hi = value << 4` is assigned INSIDE the guarded body.  LICM then
 *     hoists the shift out of both loops but the `(u8)` narrowing only
 *     one level, so the raw shift is live across the outer loop and is
 *     spilled together with tilesWide: that one extra value is the whole
 *     `sub sp, sp, #8` frame the earlier passes could not reach (208
 *     bytes with hi computed once before the loops);
 *   - the even arm's `(u8)(*p & 0xf0)` is the unfolded `and #0xff`.
 */
void BMP_FillRect4bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u32 value)
{
    s32 row;
    s32 col;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileRowOffset;
    u8 *pixelPtr;
    u32 highNibble;

    if (right > bmp->width)
        right = bmp->width;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                highNibble = value << 4;
                tileRowOffset = (row * 4) & 0x3fe0;
                pixelPtr = (u8 *)(bmp->pixels + ((col >> 1) & 3) + ((col * 4) & 0x3fe0)
                           + tileRowOffset * tilesWide);
                pixelPtr += (row * 4) & 0x1c;
                if (col & 1)
                    *pixelPtr = (*pixelPtr & 0x0f) | (u8)highNibble;
                else
                    *pixelPtr = (u8)(*pixelPtr & 0xf0) | value;
            }
}

/*
 * bmp.c fill worker (8bpp tiled, one byte per pixel), reached from the
 * fill dispatcher BMP_FillRect.  Clips right/bottom against the
 * descriptor before the loops and left/top per pixel (the signed
 * cmp/cmpge/blt triple), then stores the fill byte at the 8x8-tiled
 * address.  0x02044CE0 and 0x02044EBC are byte-identical twins.
 *
 * THE LEVER (2026-09-22, wave 10): the address is ONE integer expression
 * over the pixel pointer cast to u32, evaluated inside the guarded body,
 * with only the tile-row mask lifted into a function-scope local.  The
 * compiler hoists that local and the product out of the inner loop into
 * the preheader AFTER the entry test (the image's placement) but does not
 * fold the tile row and the in-tile row into one mla, which it does for
 * every pointer-arithmetic or subscript spelling.  Pointer arithmetic
 * (u8 *) with the same terms stays at 17 out; the per-row locals of the
 * older best source at 81.
 */
void BMP_FillRect8bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 row;
    s32 col;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileRowOffset;

    if (right > bmp->width)
        right = bmp->width;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                tileRowOffset = (row * 8) & 0x7fc0;
                *(u8 *)((uptr)bmp->pixels + (col & 7) + ((col * 8) & 0x7fc0)
                        + tileRowOffset * tilesWide + ((row * 8) & 0x38)) = value;
            }
}

/*
 * bmp.c fill worker, 4bpp tiled plotted through a HALFWORD read-modify-
 * write (the pixel's byte is halfword-aligned downward, merged, and the
 * pair stored back with strh).  Reached from BMP_FillRect.
 *
 * Levers (2026-09-22, wave 10), each measured:
 *   - the address is the family's single integer sum over (u32)s->pixels
 *     with the tile-row mask in a function-scope local and the in-tile row
 *     added afterwards (BMP_FillRect4bpp);
 *   - hi/lo are u16 locals of a u32 halfword read: `hi = c >> 8` becomes
 *     the image's lsl #8 / lsr #16, and `lo = c & 0xff` its and / lsl #16
 *     with the lsr #16 folded into every use;
 *   - odd is set inside the `if (a & 1)`, which lets tst/subne and the
 *     movne/moveq pair share one flag setting;
 *   - the even arm is written first (`odd == 0`), the fall-through order;
 *   - right is computed and clamped BEFORE bottom is computed: bottom lives
 *     in its spill slot from its first store, and initialising both up
 *     front adds a reload (312 bytes).
 */
void BMP_FillRect4bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 row;
    s32 col;
    s32 right;
    s32 bottom;
    s32 tilesWide;
    s32 tileRowOffset;
    uptr addr;
    s32 addrOdd;
    u32 word;
    u16 highByte, lowByte;
    u32 shift;

    right = x + w;
    if (right > bmp->width)
        right = bmp->width;
    bottom = y + h;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                tileRowOffset = (row * 4) & 0x3fe0;
                addr = (uptr)bmp->pixels + ((col >> 1) & 3) + ((col * 4) & 0x3fe0)
                    + tileRowOffset * tilesWide;
                addr += (row * 4) & 0x1c;
                if (addr & 1) {
                    addr -= 1;
                    addrOdd = 1;
                } else
                    addrOdd = 0;
                word = *(u16 *)addr;
                highByte = word >> 8;
                lowByte = word & 0xff;
                shift = (u32)(col << 31) >> 29;
                if (addrOdd == 0)
                    *(u16 *)addr = (((0xf0 >> shift) & lowByte) | (value << shift)) | (highByte << 8);
                else
                    *(u16 *)addr = (((highByte & (0xf0 >> shift)) | (value << shift)) << 8) | lowByte;
            }
}

void BMP_FillRect8bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 row;
    s32 col;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileRowOffset;

    if (right > bmp->width)
        right = bmp->width;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                tileRowOffset = (row * 8) & 0x7fc0;
                *(u8 *)((uptr)bmp->pixels + (col & 7) + ((col * 8) & 0x7fc0)
                        + tileRowOffset * tilesWide + ((row * 8) & 0x38)) = value;
            }
}

/*
 * bmp.c de-tile entry point: builds a new descriptor of the same extent
 * and tile size, copies the 8x8-tiled pixels of src into it in linear order,
 * and either returns it or (keepCopy == 0) copies it back over src, frees it
 * and returns NULL.
 *
 * WHAT CLOSED IT (wave 12, 2026-09-23), after three passes stuck at 6
 * bytes on the width/height load-register pair: the four extents are u16
 * LOCALS, `w = width / 8` etc.  The `lsl #13 / lsr #16` pair the older
 * sources spelled as `(u32)(f * 8192) >> 16` is simply the u16 truncation
 * of an unsigned divide by 8.  With all four u16 the residue drops to 13,
 * and assigning them in the order h, w, dep, d (height before width) is
 * what gives the image's colouring; declaration order is inert.
 */
struct Bmp *BMP_ConvertToLinear(struct Bmp *bmp, u32 keepCopy, u16 heapId)
{
    struct Bmp *linear;
    s32 index, byteCount;
    u16 widthTiles;
    u16 heightTiles;
    u16 tileRowBytes;
    u16 tileBytes;

    heightTiles = bmp->height / 8;
    widthTiles = bmp->width / 8;
    tileBytes = bmp->tileBytes;
    tileRowBytes = tileBytes / 8;
    linear = BMP_Create(widthTiles, heightTiles, tileBytes, heapId);
    byteCount = widthTiles * heightTiles * tileBytes;
    for (index = 0; index < byteCount; index++) {
        s32 pixelRow, rowOffset, tileColumn, byteInTileRow;
        pixelRow = index / (widthTiles * tileRowBytes);
        rowOffset = index % (widthTiles * tileRowBytes);
        byteInTileRow = rowOffset % tileRowBytes;
        tileColumn = rowOffset / tileRowBytes;
        linear->pixels[index] = bmp->pixels[(pixelRow % 8) * tileRowBytes + byteInTileRow + (pixelRow / 8 * widthTiles + tileColumn) * tileBytes];
    }
    if (keepCopy == 0) {
        BMP_CopyPixels(linear, bmp);
        BMP_Delete(linear);
        linear = 0;
    }
    return linear;
}
