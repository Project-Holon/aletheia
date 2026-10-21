/*
 * file:     blink_palanm.c
 * unit:     yes
 * function: BLINK_PALANM_Create, BLINK_PALANM_LoadPalettes, BLINK_PALANM_Delete, BLINK_PALANM_Update, BLINK_PALANM_ResetPhase
 * address:  0x0202E940
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   blink_palanm_File    0x020A7804  data
 *   ARC_UTIL_LoadPaletteBlockFromHandle      0x02049F78  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 */
#include "comm_player_support_shared_types.h"
#include "../types.h"

struct ResourceFile;

/*
 * BLINK_PALANM object: cross-fades a run of palette colors between two
 * source rows (srcColors, dstColors) into outColors and uploads the result.
 */
struct BlinkPalAnm {
    u16 *srcColors;     /* 0x00, allocated by BLINK_PALANM_LoadPalettes */
    u16 *dstColors;     /* 0x04, allocated by BLINK_PALANM_LoadPalettes */
    u16 *outColors;     /* 0x08, colorCount entries, allocated at creation */
    u16 firstColor;     /* 0x0c, first palette color to overwrite */
    u16 colorCount;     /* 0x0e */
    u16 phase;          /* 0x10, 0..0xFFFF, advances 0x400 per frame */
    u16 reserved12;     /* 0x12, zeroed at creation, never read */
    u32 targetMask;     /* 0x14, which palettes to upload to (0xe/0x1e/0xf/0x1f) */
    u16 heapId;         /* 0x18 */
};

/* Palette resource as ARC_UTIL_LoadPaletteBlockFromHandle returns it: colors start at +0xC. */
struct PaletteFile {
    u8 header[0xC];
    u8 *colors;
};

#include "gfl_heap_wrap.h"


#include "mi_memory.h"

#include "arc_util.h"

#include "nns_gfd_vram_transfer.h"

struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heapId);

void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *anm, void *archive, u32 fileId, u32 srcStart, u32 dstStart);

u32 BLINK_PALANM_Delete(struct BlinkPalAnm *anm);

s32 BLINK_PALANM_Update(struct BlinkPalAnm *anm);

void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *anm);

extern const char blink_palanm_File[];

extern const s16 FX_SinCosTable_[];

/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x3c and 0x3d).
 *
 * The mode chain must write `targetMask` in EVERY arm, not into a local read
 * once at the end: with the local the scheduler hoists `movs r0, #0xf`
 * above the `cmp` and saves the branch, and the tail comes out two bytes
 * short (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heapId)
{
    struct BlinkPalAnm *anm;

    anm = GFL_HEAP_Alloc(heapId, sizeof(struct BlinkPalAnm), 0, blink_palanm_File, 0x3c);
    anm->outColors = GFL_HEAP_Alloc(heapId, (u32)colorCount * 2, 0, blink_palanm_File, 0x3d);
    anm->firstColor = firstColor;
    anm->colorCount = colorCount;
    anm->phase = 0;
    anm->reserved12 = 0;
    anm->heapId = heapId;
    if (mode == 0xfffe) {
        anm->targetMask = 0xe;
    } else if (mode == 0xffff) {
        anm->targetMask = 0x1e;
    } else if (mode <= 3) {
        anm->targetMask = 0xf;
    } else {
        anm->targetMask = 0x1f;
    }

    return anm;
}

/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x83 and 0x84).
 * Loads the palette file and copies two rows of colorCount colors into the
 * source and target buffers.
 */
void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *anm, void *archive, u32 fileId, u32 srcStart, u32 dstStart)
{
    struct PaletteFile *file;
    struct ResourceFile *handle;
    u8 *colors;

    anm->srcColors = GFL_HEAP_Alloc(anm->heapId, (u32)anm->colorCount * 2, 0, blink_palanm_File,
                                   0x83);
    anm->dstColors = GFL_HEAP_Alloc(anm->heapId, (u32)anm->colorCount * 2, 0, blink_palanm_File,
                                   0x84);
    handle = ARC_UTIL_LoadPaletteBlockFromHandle((void *)archive, fileId, (&file), anm->heapId);
    colors = file->colors;
    MI_CpuCopy8(colors + srcStart * 2, anm->srcColors, (int)((u32)anm->colorCount * 2));
    MI_CpuCopy8(colors + dstStart * 2, anm->dstColors, (int)((u32)anm->colorCount * 2));
    GFL_HEAP_Free(handle);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * A four-call destructor: three owned buffers and then the object
 * itself, freed in the order dstColors, srcColors, outColors, self. The order
 * is the source's, because this compiler does not reorder calls.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 */
u32 BLINK_PALANM_Delete(struct BlinkPalAnm *anm)
{
    GFL_HEAP_Free(anm->dstColors);
    GFL_HEAP_Free(anm->srcColors);
    GFL_HEAP_Free(anm->outColors);
    return GFL_HEAP_Free(anm);
}

/*
 * blink_palanm.c: the per-frame BGR555 cross-fade.  Advances the phase word
 * at +0x10 by 0x400 (wrapping at 0x10000), takes the fade scale as
 * (FX_SinCosTable_[phase >> 4 pair, second entry] + 0x1000) / 2, blends
 * every color of the src row toward the dst row into the output row, then
 * hands the output row to NNS_GfdRegisterNewVramTransferTask.
 *
 * Two facts closed it (wave 13).  The colors are u16 locals, not s32: with
 * `s32 b` the dst channel extraction is scheduled differently (46 out).  And
 * the final pack is `(r << 10) | (bl | (g << 5))`: the channel ORed last is
 * the one the compiler evaluates FIRST, so red is blended and held, then
 * blue, then green, exactly the image's order; the left-nested
 * `(r << 10) | (g << 5) | bl` evaluates green before blue.
 *
 * EXACT* because the listing extent runs 8 bytes long: the unlabelled leaf
 * at 0x0202EB04 follows the pool word.
 */
s32 BLINK_PALANM_Update(struct BlinkPalAnm *anm)
{
    s32 scale;
    u32 i;
    u16 from;
    u16 to;
    s32 red;
    s32 green;
    s32 blue;

    if (anm->phase + 0x400 >= 0x10000) {
        anm->phase = anm->phase - 0xFC00;
    } else {
        anm->phase = anm->phase + 0x400;
    }

    scale = (FX_SinCosTable_[((anm->phase >> 4) << 1) + 1] + 0x1000) / 2;

    for (i = 0; i < anm->colorCount; i++) {
        from = anm->srcColors[i];
        to = anm->dstColors[i];
        red = (u8)(((from >> 10) & 0x1f)
                   + (((((to >> 10) & 0x1f) - ((from >> 10) & 0x1f)) * scale) >> 12));
        blue = (u8)((from & 0x1f)
                    + ((((to & 0x1f) - (from & 0x1f)) * scale) >> 12));
        green = (u8)(((from >> 5) & 0x1f)
                     + (((((to >> 5) & 0x1f) - ((from >> 5) & 0x1f)) * scale) >> 12));
        anm->outColors[i] = (u16)((red << 10) | (blue | (green << 5)));
    }

    return NNS_GfdRegisterNewVramTransferTask(anm->targetMask, anm->firstColor * 2, anm->outColors, anm->colorCount * 2);
}

/*
 * blink_palanm.c: resets the fade phase word at +0x10 of the blink object
 * (the word BLINK_PALANM_Update advances by 0x400 per frame).  An unlabelled leaf
 * with no prologue sitting after BLINK_PALANM_Update's pool word at 0x0202EB00, so
 * the listing folds it into BLINK_PALANM_Update's extent (204 against the real
 * 196).
 */
void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *anm)
{
    anm->phase = 0;
}
