/*
 * file:     unit_0204EE0C.c
 * unit:     yes
 * function: BILLBOARD_FindFreeImage, BILLBOARD_BindImageResource, BILLBOARD_SetImageFormat, BILLBOARD_AddImage, BILLBOARD_AddImageFromArchive, BILLBOARD_AddImageFromVramKeys, BILLBOARD_TrimImageResource, BILLBOARD_DeleteImage, BILLBOARD_ReleaseImageVramIfUsed, BILLBOARD_ReleaseImageVram, BILLBOARD_DeleteAllImages, BILLBOARD_GetImageVramAddr, func_0204F2CC, BILLBOARD_GetImageTexKey
 * address:  0x0204EE0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Home file: billboard.c (texture records of the billboard board).
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   G3D_SYSTEM_TransVramTexture   0x02046FF8  arm
 *   G3D_SYSTEM_GetTexVramKey   0x02047388  arm
 *   G3D_SYSTEM_GetPlttVramKey   0x020473B8  arm
 *   _s32_div_f   0x0209C0A4  arm
 *   gTexSizeTbl  0x020A14C0  data
 *   gTexParamS   0x020A14D4  data
 *   gTexParamT   0x020A14D8  data
 *   G3D_SYSTEM_CreateResourceArc   0x02046DB8  arm
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   G3D_SYSTEM_GetResourceTex  0x02047250  arm
 *   func_020307E0  0x020307E0  arm
 *   G3D_SYSTEM_FreeVramTexture   0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource   0x02046EFC  arm
 *   g_020A8144  0x020A8144  data
 *   g_020A814C  0x020A814C  data
 */
#include "billboard_types.h"

struct G3dResource;      /* loaded NitroSystem file (g3d_system_types.h) */

/* Head of the NitroSystem texture block (NNSG3dResTex), up to the texel
 * data offset. */
struct NNSG3dResTex {
    u32 blockKind;
    u32 blockSize;
    u32 texVramKey;
    u16 texSize;
    u16 texDictOffset;
    u16 texFlag;
    u16 texPad;
    u32 texelDataOffset;     /* from the start of the block */
};

/* One word of a table of (value, pad) pairs. */
struct TexParamEntry {
    u32 bits;
    u32 pad;
};

/* Byte-pointer view of the board's image array: BILLBOARD_ReleaseImageVramIfUsed's guard needs
 * the base typed u8 * to get its original instruction order. */
struct BbBoardBytes {
    u16 heapId;
    u16 reserved02;
    u8 *images;
};

typedef void (*FreeVramFn)(u32 key);

extern int G3D_SYSTEM_TransVramTexture(struct G3dResource *resource);
extern u32 G3D_SYSTEM_GetTexVramKey(struct G3dResource *resource);
extern u32 G3D_SYSTEM_GetPlttVramKey(struct G3dResource *resource);
extern s32 _s32_div_f(s32 a, s32 b);
extern void *G3D_SYSTEM_CreateResourceArc(u32 arcId, u32 dataId);
extern void *G3D_SYSTEM_GetResourceFile(struct G3dResource *resource);
extern struct NNSG3dResTex *G3D_SYSTEM_GetResourceTex(struct G3dResource *resource);
extern void func_020307E0(void *p, u32 size);
extern int G3D_SYSTEM_FreeVramTexture(struct G3dResource *resource);
extern void G3D_SYSTEM_DeleteResource(struct G3dResource *resource);

int BILLBOARD_FindFreeImage(struct BbBoard *board, int *outIndex);
void BILLBOARD_BindImageResource(struct BbImage *image, struct G3dResource *resource);
void BILLBOARD_SetImageFormat(struct BbImage *image, u32 formatIndex, s32 sizeCode, u32 columns, u8 rows);
u32 BILLBOARD_AddImage(struct BbBoard *board, struct G3dResource *resource, u32 formatIndex, u32 sizeCode, u8 columns, u8 rows);
u32 BILLBOARD_AddImageFromArchive(struct BbBoard *board, u32 arcId, u32 dataId, u32 formatIndex, u32 sizeCode, u8 columns, u8 rows);
int BILLBOARD_AddImageFromVramKeys(struct BbBoard *board, int texVramKey, int plttVramKey, int formatIndex, u32 sizeCode, u8 columns, u8 rows);
void BILLBOARD_TrimImageResource(struct BbBoard *board, u32 index);
void BILLBOARD_DeleteImage(struct BbBoard *board, int index);
void BILLBOARD_ReleaseImageVramIfUsed(struct BbBoard *board, u32 index);
void BILLBOARD_ReleaseImageVram(struct BbBoard *board, int index);
void BILLBOARD_DeleteAllImages(struct BbBoard *board);
void BILLBOARD_GetImageVramAddr(struct BbBoard *board, int index, int *outTexVramOffset);
void func_0204F2CC(struct BbBoard *board, int index, int *outPlttVramOffset);
void BILLBOARD_GetImageTexKey(struct BbBoard *board, int index, u32 *outTexVramKey);

extern const u32 gTexSizeTbl[];
extern const struct TexParamEntry gTexParamS[];
extern const struct TexParamEntry gTexParamT[];
extern FreeVramFn g_020A8144;
extern FreeVramFn g_020A814C;

/*
 * Scan the board for the first free texture record (resource NULL and
 * texFmt 5).  Writes its index (0 when none) and returns 1 when found.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_FindFreeImage.c \
 *       --func BILLBOARD_FindFreeImage --addr 0x0204EE0C --cc 1.1p1 --arm
 */
int BILLBOARD_FindFreeImage(struct BbBoard *board, int *outIndex)
{
    int i;
    u16 count = board->imageCount;
    for (i = 0; i < count; i++) {
        struct BbImage *image = &board->images[i];
        if (image->handle == 0 && image->texFmt == 5) {
            *outIndex = i;
            return 1;
        }
    }
    *outIndex = 0;
    return 0;
}

/*
 * Bind a loaded texture resource to a record: upload it to VRAM, then keep
 * the texture and palette VRAM keys and the byte offsets they stand for (the
 * low 16 bits of a key, times 8).  A resource that cannot be uploaded leaves
 * both offsets zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_BindImageResource.c \
 *       --func BILLBOARD_BindImageResource --addr 0x0204EE64 --cc 1.1p1 --arm
 */
void BILLBOARD_BindImageResource(struct BbImage *image, struct G3dResource *resource)
{
    u32 plttKey;
    image->handle = (u32)resource;
    if (G3D_SYSTEM_TransVramTexture(resource) == 0) {
        image->vramAddr = 0;
        image->plttAddr = 0;
        return;
    }
    image->texKey = G3D_SYSTEM_GetTexVramKey(resource);
    plttKey = G3D_SYSTEM_GetPlttVramKey(resource);
    image->plttKey = plttKey;
    image->vramAddr = (u32)(image->texKey << 16) >> 13;
    image->plttAddr = (u32)(plttKey << 16) >> 13;
}

/*
 * Seats a billboard cell's texture parameters: the S and T sizes come from
 * the two 3-bit fields of sizeCode (bits 4..6 and 0..2) as 1 << (n + 3), the
 * three table words go to 0x14/0x18/0x1C, and the two byte ratios at
 * 0x0A/0x0B are the sizes divided by columns and rows.
 *
 * Source order of the stores decides the prologue's colouring. The three
 * table stores come before the two size stores: with width written first the
 * sizeS field, sizeS + 3 and the constant 1 rotate through lr/r5/ip (14 bytes
 * out); with width after the table loads they land in ip/lr/r5 as the image.
 * The T field is not a named local: as a local it gets its own web and the
 * st half of the same rotation moves; written as `sizeCode & 7` at both uses
 * it is a CSE temporary and colours as the image.
 */
void BILLBOARD_SetImageFormat(struct BbImage *image, u32 formatIndex, s32 sizeCode, u32 columns, u8 rows)
{
    s32 sizeS = (sizeCode & 0x70) >> 4;
    image->texFmt = gTexSizeTbl[formatIndex];
    image->sizeS = gTexParamS[sizeS].bits;
    image->sizeT = gTexParamT[sizeCode & 7].bits;
    image->texWidth = 1 << (sizeS + 3);
    image->texHeight = 1 << ((sizeCode & 7) + 3);
    image->cellHeight = rows;
    image->cellWidth = columns;
    image->cellColumns = _s32_div_f(image->texWidth, image->cellWidth);
    image->cellRows = _s32_div_f(image->texHeight, image->cellHeight);
}

/*
 * Add a texture from an already loaded resource: find a free record, bind
 * the resource to it and set its format and cell layout.  Returns the record
 * index (not written when the board is full).
 *
 * The scan index is an out-parameter on the caller's own frame (`add r1,
 * sp, #4`), which is where the 8-byte frame comes from, and the same word is
 * the return value whether or not the scan succeeded, so the local is
 * deliberately left uninitialised: BILLBOARD_FindFreeImage writes it on both paths.
 *
 * The two trailing parameters are `u8`: a byte-typed parameter that arrives on
 * the stack is read with `ldrb` where a 32-bit one would be `ldr`, and that is
 * the only thing that distinguishes this prototype from BILLBOARD_AddImageFromArchive's
 * (a word, a byte, a byte).
 *
 * `&board->images[index]` is spelled as an index, not as byte arithmetic:
 * the element stride has to be a declared sizeof, because that is what emits
 * the `mov r6, #0x28` / `mla` pair the image has (an `index * 0x28` on a byte
 * pointer comes out as `mul` plus `add`).
 *
 * The record base is re-read for the second call, because the first one may
 * have changed it.
 */
u32 BILLBOARD_AddImage(struct BbBoard *board, struct G3dResource *resource, u32 formatIndex, u32 sizeCode, u8 columns, u8 rows)
{
    u32 index;
    if (BILLBOARD_FindFreeImage(board, (int *)(&index)) == 1) {
        BILLBOARD_BindImageResource(&board->images[index], resource);
        BILLBOARD_SetImageFormat(&board->images[index], formatIndex, sizeCode, columns, rows);
    }
    return index;
}

/*
 * The second wrapper, one call longer than BILLBOARD_AddImage: the resource it
 * binds is loaded from the archive with G3D_SYSTEM_CreateResourceArc(arcId, dataId) rather
 * than passed in, and the trailing parameters are one word and two bytes
 * rather than two bytes (`ldr` at sp+0x20, `ldrb` at sp+0x24 and sp+0x28).
 *
 * The frame and the scan out-parameter are the same as BILLBOARD_AddImage's, and
 * the record base is again re-read for each call.
 */
u32 BILLBOARD_AddImageFromArchive(struct BbBoard *board, u32 arcId, u32 dataId, u32 formatIndex, u32 sizeCode, u8 columns, u8 rows)
{
    u32 index;
    if (BILLBOARD_FindFreeImage(board, (int *)(&index)) == 1) {
        BILLBOARD_BindImageResource(&board->images[index], (struct G3dResource *)G3D_SYSTEM_CreateResourceArc(arcId, dataId));
        BILLBOARD_SetImageFormat(&board->images[index], formatIndex, sizeCode, columns, rows);
    }
    return index;
}

/*
 * billboard.c: take a free record and fill it from caller-supplied VRAM keys
 * (a texture that is already resident, so no resource), then set its format
 * and cell layout.  The pure register residue of the earlier notes (52
 * bytes, stride constant in ip instead of r0) was the spelling of the two
 * offset fields: `(u32)(u16)key << 3` gives the same instructions but a
 * different allocation; the sibling BILLBOARD_BindImageResource's `(u32)(key << 16) >> 13`
 * is what the image has.
 */
int BILLBOARD_AddImageFromVramKeys(struct BbBoard *board, int texVramKey, int plttVramKey, int formatIndex, u32 sizeCode, u8 columns, u8 rows)
{
    u32 index;
    if (BILLBOARD_FindFreeImage(board, (int *)(&index)) == 1) {
        board->images[index].handle = 0;
        board->images[index].texKey = texVramKey;
        board->images[index].plttKey = plttVramKey;
        board->images[index].vramAddr = (u32)(board->images[index].texKey << 16) >> 13;
        board->images[index].plttAddr = (u32)(board->images[index].plttKey << 16) >> 13;
        BILLBOARD_SetImageFormat(&board->images[index], formatIndex, sizeCode, columns, rows);
    }
    return index;
}

/*
 * Trim a record's resource buffer to the part the CPU still needs: the
 * texels are already in VRAM, so the buffer is shrunk (func_020307E0) to end
 * where the texel data starts.  The file pointer is a named local, not an
 * inline call argument, or the record pointer would have to stay live in a
 * third callee-saved register across both calls.  Same shape as
 * src/matched/sub_02046FCC.c.
 */
void BILLBOARD_TrimImageResource(struct BbBoard *board, u32 index)
{
    struct BbImage      *image    = &board->images[index];
    struct G3dResource  *resource = (struct G3dResource *)image->handle;
    void                *file     = G3D_SYSTEM_GetResourceFile(resource);
    struct NNSG3dResTex *texBlock = G3D_SYSTEM_GetResourceTex(resource);
    func_020307E0(file, (u32)((u8 *)texBlock + texBlock->texelDataOffset - (u8 *)file));
}

/*
 * The direct form of the record teardown: free the record's VRAM and delete
 * its resource if it is live, zero the resource, and stamp 5 into texFmt,
 * which is what BILLBOARD_FindFreeImage's scan looks for.
 *
 * Every access re-reads the board's textures pointer, so the source spells
 * the base out at each use instead of binding it to a pointer local; the two
 * calls take a fresh read of the record's resource each, since the first
 * call may have changed it.  The value the `cmp` tested is the one the
 * first call receives, which is why there is no reload between them.
 *
 * The sibling entry points are BILLBOARD_ReleaseImageVramIfUsed (guarded, through two
 * function-pointer globals) and BILLBOARD_ReleaseImageVram (unguarded, same two globals);
 * neither is contiguous with this one.
 */
void BILLBOARD_DeleteImage(struct BbBoard *board, int index)
{
    u32 off = index * 0x28;
    if (*(u32 *)((u8 *)board->images + off) != 0) {
        G3D_SYSTEM_FreeVramTexture((struct G3dResource *)(*(u32 *)((u8 *)board->images + off)));
        G3D_SYSTEM_DeleteResource((struct G3dResource *)(*(u32 *)((u8 *)board->images + off)));
        *(u32 *)((u8 *)board->images + off) = 0;
    }
    *(u32 *)((u8 *)board->images + off + 0x14) = 5;
}

/*
 * Free the VRAM of one record: when the record's first word is set, hand its
 * texture and palette VRAM keys to the two free callbacks installed in
 * 0x020A8144 / 0x020A814C, then clear the first word.  texFmt is stamped
 * 5 whether or not the release ran.
 *
 * The record size is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces a multiply whose constant is a power of two.
 * The board field is re-read for every statement after the first, because
 * the two indirect calls may write it, so the tail reloads +0x04 instead of
 * reusing the pointer computed for the guard.
 *
 * Address arithmetic: the guard reads the base through the byte view
 * (BbBoardBytes), the rest spell it as `(char *)board->images`.  The
 * cast is load-bearing - with the field left as `u8 *` the front end
 * schedules `base + off` for the first call argument ABOVE the guard branch
 * (a different 7-instruction block, 18 bytes of DIFF); spelled through a
 * `char *` the sum stays inside the guarded block.  See
 * docs/idioms/a-char-cast-on-the-base-pins-the-base-plus-index-sum.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ReleaseImageVramIfUsed.c \
 *       --func BILLBOARD_ReleaseImageVramIfUsed --addr 0x0204F1A0 --cc 1.1p1 --arm
 */
void BILLBOARD_ReleaseImageVramIfUsed(struct BbBoard *board, u32 index)
{
    u32 off = index * 0x28;
    if (*(u32 *)(((struct BbBoardBytes *)board)->images + off) != 0) {
        g_020A8144(*(u32 *)((char *)board->images + off + 0x20));
        g_020A814C(*(u32 *)((char *)board->images + off + 0x24));
        *(u32 *)((char *)board->images + off) = 0;
    }
    *(u32 *)((char *)board->images + off + 0x14) = 5;
}

/*
 * The unguarded record teardown: it runs the two free callbacks over the
 * record's texture and palette VRAM keys unconditionally (their addresses in
 * the pools are the two ABS32 relocations), then clears the resource and
 * stamps 5 into texFmt.
 *
 * A different file from BILLBOARD_ReleaseImageVramIfUsed, which is the same body behind the
 * "record is live" guard, and from BILLBOARD_DeleteImage, which does the same work
 * through two direct calls.  The three are consecutive in the image and call
 * 0x0204F5A8-free leaf helpers, so each stands alone.
 */
void BILLBOARD_ReleaseImageVram(struct BbBoard *board, int index)
{
    u32 off = index * 0x28;
    g_020A8144(*(u32 *)((u8 *)board->images + off + 0x20));
    g_020A814C(*(u32 *)((u8 *)board->images + off + 0x24));
    *(u32 *)((u8 *)board->images + off) = 0;
    *(u32 *)((u8 *)board->images + off + 0x14) = 5;
}

/*
 * Walk the board's u16 record count at +0xc and delete every record.  The
 * count is re-read on each iteration because BILLBOARD_DeleteImage may change it.
 * The comparison comes out signed (blt, not blo) because the u16 count
 * promotes to int against an s32 counter.
 */
void BILLBOARD_DeleteAllImages(struct BbBoard *board)
{
    s32 i;
    for (i = 0; i < board->imageCount; i++) {
        BILLBOARD_DeleteImage(board, i);
    }
}

/* Texture VRAM byte offset of one record, through an out-parameter. */
void BILLBOARD_GetImageVramAddr(struct BbBoard *board, int index, int *outTexVramOffset){ *outTexVramOffset = (int)*(int *)(((index * 0x28 + (int)board->images) + 12)); }

/* Palette VRAM byte offset of one record, through an out-parameter. */
void func_0204F2CC(struct BbBoard *board, int index, int *outPlttVramOffset){ *outPlttVramOffset = (int)*(int *)(((index * 0x28 + (int)board->images) + 16)); }

/*
 * Texture VRAM key getter through an out-parameter on one 0x28-byte record;
 * the `mla` means the stride is the record type's sizeof, not a byte offset.
 */
void BILLBOARD_GetImageTexKey(struct BbBoard *board, int index, u32 *outTexVramKey)
{
    struct BbImage *images = board->images;
    *outTexVramKey = images[index].texKey;
}
