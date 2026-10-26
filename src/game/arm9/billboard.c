/*
 * file:     billboard.c
 * unit:     yes
 * function: BILLBOARD_Create, BILLBOARD_Delete, BILLBOARD_SetFixedNormal, BILLBOARD_SetScale, BILLBOARD_SetDiffuse, BILLBOARD_SetAmbient, BILLBOARD_SetSpecular, BILLBOARD_SetEmission, BILLBOARD_SetPolyIdBase, BILLBOARD_SetQuadShape, BILLBOARD_SetImageOffset, BILLBOARD_GetImageSizeFromFlags, BILLBOARD_FindFreeImage, BILLBOARD_BindImageResource, BILLBOARD_SetImageFormat, BILLBOARD_AddImage, BILLBOARD_AddImageFromArchive, BILLBOARD_AddImageFromVramKeys, BILLBOARD_TrimImageResource, BILLBOARD_DeleteImage, BILLBOARD_ReleaseImageVramIfUsed, BILLBOARD_ReleaseImageVram, BILLBOARD_DeleteAllImages, BILLBOARD_GetImageVramAddr, BILLBOARD_GetImagePlttVramOffset, BILLBOARD_GetImageTexKey, BILLBOARD_SetImageTexAddr, BILLBOARD_GetImagePlttKey, BILLBOARD_CalcImageFrameRange, BILLBOARD_AddElem, BILLBOARD_FreeElem, BILLBOARD_GetElemId, BILLBOARD_SetElemId, BILLBOARD_SetElemPos, BILLBOARD_GetElemCell, BILLBOARD_SetElemCell, BILLBOARD_SetElemScale, BILLBOARD_SetElemAlpha, BILLBOARD_SetElemPolyId, BILLBOARD_GetElemVisible, BILLBOARD_SetElemVisible, BILLBOARD_GetElemFlipS, BILLBOARD_SetElemFlipS, BILLBOARD_SetElemFlipT, BILLBOARD_SetElemRotZ, BILLBOARD_Draw
 * address:  0x0204EBD4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from billboard.c, billboard_image.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   sBillboard     0x020A7FA4  data
 *   BILLBOARD_DeleteAllImages  0x0204F27C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   G3D_SYSTEM_TransVramTexture   0x02046FF8  arm
 *   G3D_SYSTEM_GetTexVramKey   0x02047388  arm
 *   G3D_SYSTEM_GetPlttVramKey   0x020473B8  arm
 *   gTexSizeTbl  0x020A14C0  data
 *   gTexParamS   0x020A14D4  data
 *   gTexParamT   0x020A14D8  data
 *   G3D_SYSTEM_CreateResourceArc   0x02046DB8  arm
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   G3D_SYSTEM_GetResourceTex  0x02047250  arm
 *   GFL_HEAP_CheckAllocator  0x020307E0  arm
 *   G3D_SYSTEM_FreeVramTexture   0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource   0x02046EFC  arm
 *   NNS_GfdDefaultFuncFreeTexVram  0x020A8144  data
 *   NNS_GfdDefaultFuncFreePlttVram  0x020A814C  data
 *   G3X_Reset          0x0207DA8C  arm
 *   G3D_CAMERA_GetEye      0x02048AE8  arm
 *   G3D_CAMERA_GetCamUp      0x02048B0C  arm
 *   G3D_CAMERA_GetCamTarget      0x02048B30  arm
 *   G3i_LookAt_        0x0207D7C4  arm
 *   MTX_LookAt         0x0207BCA0  arm
 *   MTX_Inverse43      0x0207B67C  arm
 *   MI_Copy36B         0x02082B60  arm
 *   VEC_Subtract       0x0207CA00  arm
 *   VEC_Normalize      0x0207CCA4  arm
 *   MTX_Identity33_    0x0207ADC4  arm
 *   MTX_RotY33_        0x0207AF1C  thumb
 *   G3D_LIGHT_GetDirection      0x02048C80  arm
 *   G3D_LIGHT_GetColor      0x02048CCC  arm
 *   FX_Div             0x0207C768  arm
 *   G3_MultTransMtx33  0x0207D950  arm
 *   G3_RotZ            0x0207D888  arm
 *   FX_SinCosTable_    0x020A1B38  data
 *   gBillboardQuad     0x020A1514  data
 */
#include "billboard_types.h"
#include "../sdk_ioreg.h"

struct Actor;

#include "../types.h"

struct Blk3 {
    u32 w[3];
};

struct Blob28 { u32 w[7]; };   /* 28 bytes, align 4 -> ldm/stm 16 + 12 */

void BILLBOARD_DeleteAllImages(struct BbBoard *board);

#include "../sdk_nnsfnd.h"
#include "gfl_heap_wrap.h"


void *BILLBOARD_Create(u8 *src, u32 heap);

void BILLBOARD_Delete(void *p);

void BILLBOARD_SetFixedNormal(u8 *board, short *normal);

void BILLBOARD_SetScale(u8 *dst, struct Blk3 *src);

void BILLBOARD_SetDiffuse(u8 *dst, u16 *src);

void BILLBOARD_SetAmbient(u8 *dst, u16 *src);

void BILLBOARD_SetSpecular(u8 *dst, u16 *src);

void BILLBOARD_SetEmission(u8 *dst, u16 *src);

void BILLBOARD_SetPolyIdBase(u8 *dst, u8 *src);

void BILLBOARD_SetQuadShape(u8 *dst, u8 val);

void BILLBOARD_SetImageOffset(u8 *dst, int a, int b);

void BILLBOARD_GetImageSizeFromFlags(s32 flags, u16 *a, u16 *b);

extern const char sBillboard[];

/*
 * billboard.c's board constructor; the only allocation site in the image
 * whose __FILE__ word is 0x020A7FA4 ("billboard.c", the NUL of
 * "battle_disp.c" at 0x020A7FA3 fixes where it starts).  Caller is
 * BILLBOARD_ACT_Create (arm9/particle.c).  Three GFL_HEAP_Alloc calls at lines 153, 159 and 161: the
 * 0x3c-byte board, its count0 * 0x28 record array and its count1 * 0x1c
 * element array.
 *
 * The whole payload is ONE 28-byte aggregate assignment at +0x0c, which mwcc
 * expands to a 16-byte ldm/stm pair with write-back followed by a 12-byte
 * pair without: the second pair reuses the bases the write-back left in r8
 * (source + 16) and sb (dest + 0x10), so the three bytes of `add` that a
 * spelled-out second copy costs are absent from the original.  The source
 * must be a 4-aligned aggregate; a struct of bytes compiles to a byte-copy
 * loop instead.
 */
void *BILLBOARD_Create(u8 *src, u32 heap)
{
    struct BbBoard *h;
    const char *file;
    int i;

    file = sBillboard;
    h = (struct BbBoard *)GFL_HEAP_Alloc(heap, sizeof(struct BbBoard), 1, file, 153);
    h->heapId = (u16)heap;
    *(struct Blob28 *)&h->imageCount = *(struct Blob28 *)src;
    h->images = (struct BbImage *)GFL_HEAP_Alloc(heap, h->imageCount * sizeof(struct BbImage), 1, file, 159);
    h->elems = (struct BbElem *)GFL_HEAP_Alloc(heap, h->elemCount * sizeof(struct BbElem), 1, file, 161);
    for (i = 0; i < h->imageCount; i++) {
        h->images[i].handle = 0;
        h->images[i].texFmt = 5;
    }
    for (i = 0; i < h->elemCount; i++) {
        u16 *q = (u16 *)&h->elems[i];
        *q = (u16)((*q & ~0x3FFFu) | 0x3FFFu);
    }
    h->useFixedNormal = 0;
    h->normalX = 0;
    h->normalY = 0;
    h->normalZ = 0;
    h->lookAtMode = 0;
    h->offsetS = 0;
    h->offsetT = 0;
    return h;
}

/*
 * Free an actor and its two sub-objects, in +8, +4, self order.
 */
void BILLBOARD_Delete(void *p)
{
    BILLBOARD_DeleteAllImages(p);
    GFL_HEAP_Free(((struct BbBoard *)p)->elems);
    GFL_HEAP_Free(((struct BbBoard *)p)->images);
    GFL_HEAP_Free(p);
}

/*
 * Sets the flag word at +0x2c and copies three signed halfwords out of the
 * caller's array into +0x30, +0x32 and +0x34.
 *
 * Unlabelled in the generated listing, and it is the follower that makes
 * BILLBOARD_Delete EXACT*: the prologue saves nothing, so `disasm.py` never
 * auto-labelled it, and the extent inferred for 0x0204ED24 runs through these
 * 36 bytes to the next label at 0x0204ED70
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Seeding
 * 0x0204ED4C in layout/function_starts.txt turns that EXACT* into EXACT and
 * changes nothing else - it is the integrator's file, not this packet's.
 *
 * The three `ldrsh` leave the array backwards (normal[2] first) and the three
 * `strh` write in order, so the values have to live in three registers at
 * once: the source holds them in locals, and the locals have to be *declared*
 * in reverse order (`z`, `y`, `x`) while being assigned in the same
 * reverse order.  Declared x, y, z the compiler gives normal[1] the higher of
 * the two scratch registers and normal[2] the lower one, which is four bytes of
 * register field wrong - see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 * Writing the three stores straight from the array (no locals) interleaves
 * each load with its store and is eight bytes wrong.
 */
void BILLBOARD_SetFixedNormal(u8 *board, short *normal)
{
    short z;
    short y;
    short x;

    ((struct BbBoard *)board)->useFixedNormal = 1;
    z = normal[2];
    y = normal[1];
    x = normal[0];
    ((struct BbBoard *)board)->normalX = x;
    ((struct BbBoard *)board)->normalY = y;
    ((struct BbBoard *)board)->normalZ = z;
}

/*
 * Copy the caller's 12-byte record into the actor at +0x10.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED70 and its body ends at 0x0204ED80.
 */
void BILLBOARD_SetScale(u8 *dst, struct Blk3 *src)
{
    *(struct Blk3 *)(dst + 0x10) = *src;
}

/*
 * Halfword field store into the actor at +0x1c from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED80 and its body ends at 0x0204ED8C.
 */
void BILLBOARD_SetDiffuse(u8 *dst, u16 *src)
{
    ((struct BbBoard *)dst)->diffuse = *src;
}

/*
 * Halfword field store into the actor at +0x1e from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED8C and its body ends at 0x0204ED98.
 */
void BILLBOARD_SetAmbient(u8 *dst, u16 *src)
{
    ((struct BbBoard *)dst)->ambient = *src;
}

/*
 * Halfword field store into the actor at +0x20 from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED98 and its body ends at 0x0204EDA4.
 */
void BILLBOARD_SetSpecular(u8 *dst, u16 *src)
{
    ((struct BbBoard *)dst)->specular = *src;
}

/*
 * Halfword field store into the actor at +0x22 from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDA4 and its body ends at 0x0204EDB0.
 */
void BILLBOARD_SetEmission(u8 *dst, u16 *src)
{
    ((struct BbBoard *)dst)->emission = *src;
}

/*
 * Byte field store into the actor at +0x24 from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDB0 and its body ends at 0x0204EDBC.
 */
void BILLBOARD_SetPolyIdBase(u8 *dst, u8 *src)
{
    ((struct BbBoard *)dst)->polyIdBase = *src;
}

/*
 * Byte field store into the actor at +0x25 straight from the value
 * parameter: there is no load in the image at all.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDBC and its body ends at 0x0204EDC4.
 */
void BILLBOARD_SetQuadShape(u8 *dst, u8 val)
{
    ((struct BbBoard *)dst)->quadShape = val;
}

/*
 * Two halfword field stores, +0x36 and +0x38, from the two value
 * parameters.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDC4 and its body ends at 0x0204EDD0.
 */
void BILLBOARD_SetImageOffset(u8 *dst, int a, int b)
{
    ((struct BbBoard *)dst)->offsetS = a;
    ((struct BbBoard *)dst)->offsetT = b;
}

/*
 * Turn two bit groups of the flags word into one-hot halfwords, each store
 * guarded by its own null check.  The `asr` on the high group is the tell
 * that the flags word is signed (an unsigned group would be lsr), and the
 * first guard is a real branch while the second is folded into conditional
 * instructions because nothing follows it.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDD0 and its body ends at 0x0204EE0C.
 */
void BILLBOARD_GetImageSizeFromFlags(s32 flags, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = (u16)(1 << (((flags & 0x70) >> 4) + 3));
    }
    if (b != 0) {
        *b = (u16)(1 << ((flags & 7) + 3));
    }
}

#define reg_G3_MTX_MODE        (*(volatile u32 *)REG_MTX_MODE_ADDR)

#define reg_G3_MTX_PUSH        (*(volatile u32 *)REG_MTX_PUSH_ADDR)

#define reg_G3_MTX_POP         (*(volatile u32 *)REG_MTX_POP_ADDR)

#define reg_G3_MTX_SCALE       (*(volatile u32 *)REG_MTX_SCALE_ADDR)

#define reg_G3_COLOR           (*(volatile u32 *)REG_COLOR_ADDR)

#define reg_G3_NORMAL          (*(volatile u32 *)REG_NORMAL_ADDR)

#define reg_G3_TEXCOORD        (*(volatile u32 *)REG_TEXCOORD_ADDR)

#define reg_G3_VTX_16          (*(volatile u32 *)REG_VTX_16_ADDR)

#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)REG_POLYGON_ATTR_ADDR)

#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)REG_TEXIMAGE_PARAM_ADDR)

#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)REG_TEXPLTT_BASE_ADDR)

#define reg_G3_DIF_AMB         (*(volatile u32 *)REG_DIF_AMB_ADDR)

#define reg_G3_SPE_EMI         (*(volatile u32 *)REG_SPE_EMI_ADDR)

#define reg_G3_LIGHT_VECTOR    (*(volatile u32 *)REG_LIGHT_VECTOR_ADDR)

#define reg_G3_LIGHT_COLOR     (*(volatile u32 *)REG_LIGHT_COLOR_ADDR)

#define reg_G3_BEGIN_VTXS      (*(volatile u32 *)REG_BEGIN_VTXS_ADDR)

#define reg_G3_END_VTXS        (*(volatile u32 *)REG_END_VTXS_ADDR)

#define GX_VECFX10(x, y, z) \
    ((u32)(((((x) >> 3) & 0x3ff) << 0) | \
           ((((y) >> 3) & 0x3ff) << 10) | \
           ((((z) >> 3) & 0x3ff) << 20)))

#define GX_FX16PAIR(a, b)  ((u32)((u32)(u16)(a) | ((u32)(u16)(b) << 16)))

#define GX_FX16ST(x)       ((s16)((x) >> 8))

#define GX_ST(s, t)        ((u32)((u16)GX_FX16ST(s) | ((u16)GX_FX16ST(t) << 16)))

struct G3dResource;      /* loaded NitroSystem file (g3d_system_types.h) */

struct G3dCamera;

struct LightSlot;

/* Head of the NitroSystem texture block (NNSG3dResTex), up to the texel
 * data offset. */
#include "nns_g3d_anm_calc_types.h"

/* One word of a table of (value, pad) pairs. */
struct TexParamEntry {
    u32 bits;
    u32 pad;
};

/* Byte-pointer view of the board's image array: BILLBOARD_ReleaseImageVramIfUsed's guard needs
 * the base typed u8 * to get its original instruction order.  Kept: with
 * board->images (a struct BbImage *) the front end hoists `base + off` above
 * the guard branch (18 bytes of DIFF); see open_items.tsv. */
struct BbBoardBytes {
    u16 heapId;
    u16 reserved02;
    u8 *images;
};

typedef void (*FreeVramFn)(u32 key);

#include "../sdk_fx.h"

struct Quad { fx16 y0, y1, x0, x1; };

#include "g3d_system.h"









#include "g3x.h"

#include "g3_util.h"

#include "fx_mtx43.h"


#include "mi_memory.h"

#include "fx_vec.h"


#include "fx_mtx33.h"


#include "fx_cp.h"

#include "g3imm.h"

struct G3dCamera;

#include "g3d_camera.h"


struct Rgb555;

#include "g3d_light.h"


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

void BILLBOARD_GetImageVramAddr(struct BbBoard *board, int index, int *outTexVramOffset);

int BILLBOARD_GetImagePlttVramOffset(struct BbBoard *board, int index, int *outPlttVramOffset);

void BILLBOARD_GetImageTexKey(struct BbBoard *board, int index, u32 *outTexVramKey);

void BILLBOARD_SetImageTexAddr(struct BbBoard *board, int imageIndex, u32 texKey);

void BILLBOARD_GetImagePlttKey(struct BbBoard *board, int imageIndex, u32 *outPlttKey);

void BILLBOARD_CalcImageFrameRange(struct BbBoard *board, u32 imageIndex, int frame, int *outOffset, int *outFrameSize, u8 useFrameIndex);

s32 BILLBOARD_AddElem(struct BbBoard *board, u32 imageIndex, u16 scaleX, u16 scaleY, VecFx32 *pos, u8 alpha, u32 light, u32 facingMode);

void BILLBOARD_FreeElem(struct BbBoard *board, u32 elemIndex);

void BILLBOARD_GetElemId(struct BbBoard *board, u32 elemIndex, u16 *outImageIndex);

void BILLBOARD_SetElemId(struct BbBoard *board, u32 elemIndex, u16 *imageIndex);

void BILLBOARD_SetElemPos(struct BbBoard *board, int elemIndex, VecFx32 *pos);

void BILLBOARD_GetElemCell(struct BbBoard *board, int elemIndex, u16 *outCell);

void BILLBOARD_SetElemCell(struct BbBoard *board, int elemIndex, u16 *cell);

void BILLBOARD_SetElemScale(struct BbBoard *board, int elemIndex, const s16 *scaleX, const s16 *scaleY);

void BILLBOARD_SetElemAlpha(struct BbBoard *board, int elemIndex, u8 *alpha);

void BILLBOARD_SetElemPolyId(struct BbBoard *board, int elemIndex, u8 *polyId);

u32 BILLBOARD_GetElemVisible(struct BbBoard *board, int elemIndex);

void BILLBOARD_SetElemVisible(struct BbBoard *board, u32 elemIndex, u32 *visible);

u32 BILLBOARD_GetElemFlipS(struct BbBoard *board, int elemIndex);

void BILLBOARD_SetElemFlipS(struct BbBoard *board, u32 elemIndex, u32 *flipS);

void BILLBOARD_SetElemFlipT(struct BbBoard *board, u32 elemIndex, u32 *flipT);

void BILLBOARD_SetElemRotZ(struct BbBoard *board, int elemIndex, u16 *rotZ);

void BILLBOARD_Draw(struct BbBoard *board, struct G3dCamera *camera, struct LightSlot *lights);

extern const u32 gTexSizeTbl[];

extern const struct TexParamEntry gTexParamS[];

extern const struct TexParamEntry gTexParamT[];

extern FreeVramFn NNS_GfdDefaultFuncFreeTexVram;

extern FreeVramFn NNS_GfdDefaultFuncFreePlttVram;

extern const fx16 FX_SinCosTable_[];

extern const struct Quad gBillboardQuad[];

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
    image->handle = resource;
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
    image->cellColumns = image->texWidth / image->cellWidth;
    image->cellRows = image->texHeight / image->cellHeight;
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
 * texels are already in VRAM, so the buffer is shrunk (GFL_HEAP_CheckAllocator) to end
 * where the texel data starts.  The file pointer is a named local, not an
 * inline call argument, or the record pointer would have to stay live in a
 * third callee-saved register across both calls.  Same shape as
 * src/matched/G3D_SYSTEM_CutTexture.c.
 */
void BILLBOARD_TrimImageResource(struct BbBoard *board, u32 index)
{
    struct BbImage      *image    = &board->images[index];
    struct G3dResource  *resource = image->handle;
    void                *file     = G3D_SYSTEM_GetResourceFile(resource);
    struct NNSG3dResTex *texBlock = G3D_SYSTEM_GetResourceTex(resource);
    GFL_HEAP_CheckAllocator(file, (u32)((u8 *)texBlock + texBlock->texInfo.ofsTex - (u8 *)file));
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
    u32 off = index * sizeof(struct BbImage);
    if (((struct BbImage *)((u8 *)board->images + off))->handle != 0) {
        G3D_SYSTEM_FreeVramTexture(((struct BbImage *)((u8 *)board->images + off))->handle);
        G3D_SYSTEM_DeleteResource(((struct BbImage *)((u8 *)board->images + off))->handle);
        ((struct BbImage *)((u8 *)board->images + off))->handle = 0;
    }
    ((struct BbImage *)((u8 *)board->images + off))->texFmt = 5;
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
    u32 off = index * sizeof(struct BbImage);
    if (*(struct G3dResource **)(((struct BbBoardBytes *)board)->images + off) != 0) {
        NNS_GfdDefaultFuncFreeTexVram(((struct BbImage *)((char *)board->images + off))->texKey);
        NNS_GfdDefaultFuncFreePlttVram(((struct BbImage *)((char *)board->images + off))->plttKey);
        ((struct BbImage *)((char *)board->images + off))->handle = 0;
    }
    ((struct BbImage *)((char *)board->images + off))->texFmt = 5;
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
    u32 off = index * sizeof(struct BbImage);
    NNS_GfdDefaultFuncFreeTexVram(((struct BbImage *)((u8 *)board->images + off))->texKey);
    NNS_GfdDefaultFuncFreePlttVram(((struct BbImage *)((u8 *)board->images + off))->plttKey);
    ((struct BbImage *)((u8 *)board->images + off))->handle = 0;
    ((struct BbImage *)((u8 *)board->images + off))->texFmt = 5;
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
void BILLBOARD_GetImageVramAddr(struct BbBoard *board, int index, int *outTexVramOffset){ *outTexVramOffset = (int)board->images[index].vramAddr; }

/* Palette VRAM byte offset of one record, through an out-parameter. */
int BILLBOARD_GetImagePlttVramOffset(struct BbBoard *board, int index, int *outPlttVramOffset){ return *outPlttVramOffset = (int)board->images[index].plttAddr; }

/*
 * Texture VRAM key getter through an out-parameter on one 0x28-byte record;
 * the `mla` means the stride is the record type's sizeof, not a byte offset.
 */
void BILLBOARD_GetImageTexKey(struct BbBoard *board, int index, u32 *outTexVramKey)
{
    struct BbImage *images = board->images;
    *outTexVramKey = images[index].texKey;
}

void BILLBOARD_SetImageTexAddr(struct BbBoard *board, int imageIndex, u32 texKey)
{
    u32 off = imageIndex * sizeof(struct BbImage);
    ((struct BbImage *)((u8 *)board->images + off))->texKey = texKey;
    ((struct BbImage *)((u8 *)board->images + off))->vramAddr = (((struct BbImage *)((u8 *)board->images + off))->texKey << 16) >> 13;
}

void BILLBOARD_GetImagePlttKey(struct BbBoard *board, int imageIndex, u32 *outPlttKey)
{
    *outPlttKey = ((struct BbImage *)(imageIndex * sizeof(struct BbImage) + (sptr)board->images))->plttKey;
}

void BILLBOARD_CalcImageFrameRange(struct BbBoard *board, u32 imageIndex, int frame, int *outOffset, int *outFrameSize, u8 useFrameIndex)
{
    struct BbImage *image = (struct BbImage *)((u8 *)board->images + imageIndex * sizeof(struct BbImage));
    int frameRow;

    switch (image->texFmt) {
    case 3:
        *outFrameSize = image->cellHeight * ((image->cellWidth << 5) / 8) / 8;
        break;
    case 1:
    case 4:
    case 6:
        *outFrameSize = image->cellHeight * ((image->cellWidth << 6) / 8) / 8;
        break;
    case 2:
        *outFrameSize = image->cellHeight * ((image->cellWidth << 4) / 8) / 8;
        break;
    }
    if (useFrameIndex == 0) {
        *outOffset = frame * *outFrameSize;
        return;
    }
    frameRow = frame / image->texWidth;
    *outOffset = *outFrameSize * frameRow + image->cellWidth * (frame % image->texWidth);
}

/*
 * billboard.c: allocate a free 0x1c-byte element (image index field 0x3FFF
 * = free) and initialise it. Every earlier residue came from spelling the
 * two packed halfwords as hand masks; the source is plain bitfield
 * assignment (14/2 at +0x00, 5/4/1/1/1/4 at +0x18), in the image's store
 * order.
 */
s32 BILLBOARD_AddElem(struct BbBoard *board, u32 imageIndex, u16 scaleX, u16 scaleY, VecFx32 *pos, u8 alpha, u32 light, u32 facingMode)
{
    s32 i;

    for (i = 0; i < board->elemCount; i++) {
        if (board->elems[i].imageIndex == BB_ELEM_FREE) {
            board->elems[i].imageIndex = (u16)imageIndex;
            board->elems[i].facingMode = (u16)facingMode;
            board->elems[i].scaleX = scaleX;
            board->elems[i].scaleY = scaleY;
            board->elems[i].rotZ = 0;
            board->elems[i].pos = *pos;
            board->elems[i].alpha = alpha;
            board->elems[i].polyId = 0;
            board->elems[i].visible = 0;
            board->elems[i].light = (u16)light;
            board->elems[i].flipS = 0;
            board->elems[i].flipT = 0;
            board->elems[i].cell = 0;
            return i;
        }
    }
    return 0;
}

/*
 * If the low 14 bits of the u16 at the element are not already all ones,
 * set them and leave the top two bits alone. The 14-bit width only survives
 * to a plain lsl/lsr pair as a bitfield
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 */
void BILLBOARD_FreeElem(struct BbBoard *board, u32 elemIndex)
{
    struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    if (elem->imageIndex != BB_ELEM_FREE) {
        elem->imageIndex = BB_ELEM_FREE;
    }
}

/*
 * Fourteen-bit field getter on the 0x1c-byte elements: the shift pair is an
 * equal `lsl #0x12` / `lsr #0x12`, and the stride is spelled as byte
 * arithmetic so it comes out as `mul` rather than `mla`.
 */
void BILLBOARD_GetElemId(struct BbBoard *board, u32 elemIndex, u16 *outImageIndex)
{
    *outImageIndex = ((struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem)))->imageIndex;
}

/*
 * Same element and field as BILLBOARD_FreeElem, but the low 14 bits are copied in
 * from the caller's u16. The compiler reuses the inverted mask it already
 * needed as `lsr #18` rather than materialising 0x3fff twice.
 */
void BILLBOARD_SetElemId(struct BbBoard *board, u32 elemIndex, u16 *imageIndex)
{
    u16 *packed = (u16 *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    *packed = (u16)((*packed & ~0x3fff) | (*imageIndex & 0x3fff));
}

/*
 * Twelve-byte aggregate copy out of the caller's vector into the position
 * of one element: one `ldm`/`stm` of three registers.
 */
void BILLBOARD_SetElemPos(struct BbBoard *board, int elemIndex, VecFx32 *pos)
{
    struct BbElem *elem = &board->elems[elemIndex];

    elem->pos = *pos;
}

void BILLBOARD_GetElemCell(struct BbBoard *board, int elemIndex, u16 *outCell)
{
    *outCell = board->elems[elemIndex].cell;
}

void BILLBOARD_SetElemCell(struct BbBoard *board, int elemIndex, u16 *cell)
{
    ((struct BbElem *)(elemIndex * sizeof(struct BbElem) + (sptr)board->elems))->cell = *cell;
}

void BILLBOARD_SetElemScale(struct BbBoard *board, int elemIndex, const s16 *scaleX, const s16 *scaleY)
{
    board->elems[elemIndex].scaleX = *scaleX;
    board->elems[elemIndex].scaleY = *scaleY;
}

/*
 * The three accessors that follow BILLBOARD_SetElemScale, 0x0204F6B4..0x0204F720, on
 * the bitfields of the packed halfword at +0x18 of one element: five bits
 * at bit 0 (alpha), four bits at bit 5 (polygon id offset), and the single
 * bit at bit 9 (visible).
 *
 * All three are unlabelled in the generated listing, because none of them
 * saves a register in a prologue and `disasm.py` only auto-labels a function
 * whose prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Each one is a read-modify-write of the whole halfword, which is what a
 * bitfield assignment costs.
 */
void BILLBOARD_SetElemAlpha(struct BbBoard *board, int elemIndex, u8 *alpha)
{
    struct BbElem *elem = &board->elems[elemIndex];

    elem->alpha = *alpha;
}

void BILLBOARD_SetElemPolyId(struct BbBoard *board, int elemIndex, u8 *polyId)
{
    struct BbElem *elem = &board->elems[elemIndex];

    elem->polyId = *polyId;
}

u32 BILLBOARD_GetElemVisible(struct BbBoard *board, int elemIndex)
{
    struct BbElem *elem = &board->elems[elemIndex];

    return elem->visible;
}

/*
 * Set or clear bit 9 of the record's u16 at +0x18 depending on whether the
 * caller's word is 1.  Both arms are conditional instructions and there is no
 * narrowing shift pair, so the field is a 1-bit bitfield assigned 1/0 rather
 * than a read-modify-write of the whole halfword, and the address is written
 * inside each arm so the condition is evaluated first.
 */
void BILLBOARD_SetElemVisible(struct BbBoard *board, u32 elemIndex, u32 *visible)
{
    if (*visible == 1) {
        struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));
        elem->visible = 1;
    } else {
        struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));
        elem->visible = 0;
    }
}

/*
 * The single bit at bit 10 of the packed halfword at +0x18 of one 0x1c-byte
 * entry of the descriptor's +8 array: `lsl #0x15` / `lsr #0x1f`, which is bit
 * 10 exactly, and no other read-modify-write.
 *
 * Unlabelled in the generated listing because the prologue saves nothing, and
 * it is the follower that makes BILLBOARD_SetElemVisible EXACT*.  Seeding 0x0204F748 in
 * layout/function_starts.txt turns that EXACT* into EXACT; that file is the
 * integrator's, not this packet's.
 *
 * It is the same array and the same stride as the three accessors in
 * src/matched/unit_0204F6B4.c, one bit along: that file has bit 9, this one
 * bit 10.  The entry type is declared with its sizeof at 0x1c, so the encoder
 * emits the image's `mov r0, #0x1c` plus `mla`.
 */
u32 BILLBOARD_GetElemFlipS(struct BbBoard *board, int elemIndex)
{
    struct BbElem *elem = &board->elems[elemIndex];

    return elem->flipS;
}

/*
 * Copy the caller's word, narrowed to 16 bits, into bit 10 of the +0x18
 * halfword.  The lsl #16 / lsr #16 pair comes from the u16 narrowing and the
 * lsl #31 / lsr #21 pair from the bit write, which is why the C has to keep
 * the narrowing visible: the bit is a 1-bit bitfield assigned a u16 value.
 */
void BILLBOARD_SetElemFlipS(struct BbBoard *board, u32 elemIndex, u32 *flipS)
{
    struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    elem->flipS = (u16)*flipS;
}

/*
 * Same as BILLBOARD_SetElemFlipS one bit up: the caller's word goes into bit 11.
 */
void BILLBOARD_SetElemFlipT(struct BbBoard *board, u32 elemIndex, u32 *flipT)
{
    struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    elem->flipT = (u16)*flipT;
}

/*
 * Halfword store at +0x16 of one 0x1c-byte entry of the descriptor's +8
 * array.  Note +0x16 rather than +0x12/+0x14 - it is the third of the three
 * halfword fields that BILLBOARD_SetElemScale and BILLBOARD_SetElemAlpha's family work on, and
 * it is the follower that makes BILLBOARD_SetElemFlipT EXACT*.
 *
 * Unlabelled in the generated listing: the prologue saves nothing.  Seeding
 * 0x0204F7C4 in layout/function_starts.txt turns that EXACT* into EXACT; that
 * file is the integrator's, not this packet's.
 */
void BILLBOARD_SetElemRotZ(struct BbBoard *board, int elemIndex, u16 *rotZ)
{
    struct BbElem *elem = &board->elems[elemIndex];

    elem->rotZ = *rotZ;
}

static inline void G3_MtxMode(int mode) { reg_G3_MTX_MODE = (u32)mode; }

static inline void G3_PushMtx(void) { reg_G3_MTX_PUSH = 0; }

static inline void G3_PopMtx(int num) { reg_G3_MTX_POP = (u32)num; }

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}

static inline void G3_Color(u16 rgb) { reg_G3_COLOR = (u32)rgb; }

static inline void G3_Normal(fx16 x, fx16 y, fx16 z) { reg_G3_NORMAL = GX_VECFX10(x, y, z); }

static inline void G3_TexCoord(fx32 s, fx32 t) { reg_G3_TEXCOORD = GX_ST(s, t); }

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    reg_G3_VTX_16 = GX_FX16PAIR(x, y);
    reg_G3_VTX_16 = (u32)(u16)z;
}

static inline void G3_PolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc)
{
    reg_G3_POLYGON_ATTR = (u32)((light << 0) | (polyMode << 4) | (cullMode << 6) | misc |
                                (polygonID << 24) | (alpha << 16));
}

static inline void G3_TexImageParam(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr)
{
    reg_G3_TEXIMAGE_PARAM = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}

static inline void G3_TexPlttBase(u32 addr, int texfmt)
{
    u32 param = (u32)(addr >> (4 - (texfmt == 2)));
    reg_G3_TEXPLTT_BASE = param;
}

static inline void G3_MaterialColorDiffAmb(u16 diffuse, u16 ambient, BOOL IsSetVtxColor)
{
    reg_G3_DIF_AMB = (u32)(diffuse | (ambient << 16) | ((IsSetVtxColor != 0) << 15));
}

static inline void G3_MaterialColorSpecEmi(u16 specular, u16 emission, BOOL IsShininess)
{
    reg_G3_SPE_EMI = (u32)(specular | (emission << 16) | ((IsShininess != 0) << 15));
}

static inline void G3_LightVector(int lightID, fx16 x, fx16 y, fx16 z)
{
    reg_G3_LIGHT_VECTOR = (u32)GX_VECFX10(x, y, z) | ((u32)lightID << 30);
}

static inline void G3_LightColor(int lightID, u16 rgb)
{
    reg_G3_LIGHT_COLOR = (u32)(rgb | ((u32)lightID << 30));
}

static inline void G3_Begin(int primitive) { reg_G3_BEGIN_VTXS = (u32)primitive; }

static inline void G3_End(void) { reg_G3_END_VTXS = 0; }

static inline fx16 FX_SinIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1)]; }

static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }

static inline void MTX_Copy43To33(const MtxFx43 *pSrc, MtxFx33 *pDst) { MI_Copy36B(pSrc, pDst); }

static inline void MTX_Identity33(MtxFx33 *pDst) { MTX_Identity33_(pDst); }

static inline void MTX_RotY33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotY33_(pDst, sinVal, cosVal); }

/*
 * billboard.c's draw pass: camera look-at, the four per-mode billboard
 * rotation matrices (full inverse view, Y-axis only, identity, Y-axis),
 * light upload, then one textured quad per visible element through the
 * NitroSDK immediate G3 inlines (g3imm.h, transcribed here as static
 * inlines over the 0x04000440.. registers).  0x0207C768 is FX_Div.
 *
 * Levers, all measured: `fx32 scale = b->scale` as a local (spilled, not
 * re-read for the three FX_Div calls); the four quad-table halfwords read
 * into fx16 locals BEFORE G3_Begin (ldrsh + per-use u16 narrowing); the
 * cell offset written `s0 = ...; s0 += b->offS;` (the one-expression form
 * swaps the mul/ldrsh destinations); a SEPARATE counter j for the light
 * loop (sharing i puts i in the lowest spill slot); declaration order
 * scale, s1/s0/t1/t0, i, j, nx/ny/nz fixes the remaining spill slots.
 * G3D_LIGHT_GetDirection/CCC take a u8 index here (`and r1, r8, #0xff`).
 */
void BILLBOARD_Draw(struct BbBoard *board, struct G3dCamera *camera, struct LightSlot *lights)
{
    MtxFx33 facing[4];
    VecFx32 cameraPos;
    VecFx32 cameraUp;
    VecFx32 cameraTarget;
    VecFx32 viewDir;
    MtxFx43 viewMtx;
    MtxFx43 invViewMtx;
    VecFx32 flatDir;
    VecFx32 localPos;
    VecFx16 lightVec;
    u16 lightColor;
    fx32 scale;
    fx32 sLeft, sRight, tTop, tBottom;
    int i;
    int lightIndex;
    fx16 normalX, normalY, normalZ;
    fx16 quadY0, quadY1, quadX0, quadX1;

    G3X_Reset();
    board->lookAtMode = 0;
    G3D_CAMERA_GetEye(camera, &cameraPos);
    G3D_CAMERA_GetCamUp(camera, &cameraUp);
    G3D_CAMERA_GetCamTarget(camera, &cameraTarget);
    if (board->lookAtMode == 0) {
        G3i_LookAt_(&cameraPos, &cameraUp, &cameraTarget, 1, &viewMtx);
    } else {
        MTX_LookAt(&cameraPos, &cameraUp, &cameraTarget, &viewMtx);
    }
    MTX_Inverse43(&viewMtx, &invViewMtx);
    MTX_Copy43To33(&invViewMtx, &facing[0]);

    VEC_Subtract(&cameraPos, &cameraTarget, &flatDir);
    flatDir.y = 0;
    VEC_Normalize(&flatDir, &flatDir);
    MTX_Identity33(&facing[1]);
    MTX_RotY33(&facing[1], flatDir.x, flatDir.z);
    MTX_RotY33(&facing[3], flatDir.x, flatDir.z);
    MTX_Identity33(&facing[2]);

    VEC_Subtract(&cameraPos, &cameraTarget, &viewDir);
    VEC_Normalize(&viewDir, &viewDir);

    if (board->useFixedNormal == 1) {
        normalX = board->normalX;
        normalY = board->normalY;
        normalZ = board->normalZ;
    } else {
        normalX = viewDir.x;
        normalY = viewDir.y;
        normalZ = viewDir.z;
    }

    if (lights != 0) {
        for (lightIndex = 0; lightIndex < 4; lightIndex++) {
            G3D_LIGHT_GetDirection(lights, lightIndex, (struct Rgb555 *)(&lightVec));
            G3D_LIGHT_GetColor(lights, lightIndex, &lightColor);
            G3_LightVector(lightIndex, lightVec.x, lightVec.y, lightVec.z);
            G3_LightColor(lightIndex, lightColor);
        }
    }

    G3_MtxMode(1);
    scale = board->scale;
    G3_Scale(scale, scale, scale);

    for (i = 0; i < board->elemCount; i++) {
        struct BbImage *image;
        struct BbElem *elem = &board->elems[i];

        if (elem->imageIndex == BB_ELEM_FREE) {
            continue;
        }
        if (!elem->visible) {
            continue;
        }
        image = &board->images[elem->imageIndex];

        if (elem->flipS) {
            sRight = (elem->cell % image->cellColumns) * image->cellWidth << 12;
            sRight += board->offsetS;
            sLeft = sRight + (image->cellWidth << 12);
        } else {
            sLeft = (elem->cell % image->cellColumns) * image->cellWidth << 12;
            sRight = sLeft + (image->cellWidth << 12);
        }
        if (elem->flipT) {
            tBottom = (elem->cell / image->cellColumns) * image->cellHeight << 12;
            tBottom += board->offsetT;
            tTop = tBottom + (image->cellHeight << 12);
        } else {
            tTop = (elem->cell / image->cellColumns) * image->cellHeight << 12;
            tBottom = tTop + (image->cellHeight << 12);
        }
        G3_PushMtx();
        localPos.x = FX_Div(elem->pos.x, scale);
        localPos.y = FX_Div(elem->pos.y, scale);
        localPos.z = FX_Div(elem->pos.z, scale);
        G3_MultTransMtx33(&facing[elem->facingMode], &localPos);
        G3_RotZ(-FX_SinIdx(elem->rotZ), FX_CosIdx(elem->rotZ));
        if (elem->facingMode == 3) {
            G3_Scale(elem->scaleX, 0x1000, elem->scaleY);
        } else {
            G3_Scale(elem->scaleX, elem->scaleY, 0x1000);
        }
        G3_TexImageParam(image->texFmt, 1, image->sizeS, image->sizeT, 0, 0, 1, image->vramAddr);
        G3_TexPlttBase(image->plttAddr, image->texFmt);
        G3_MaterialColorDiffAmb(board->diffuse, board->ambient, 1);
        G3_MaterialColorSpecEmi(board->specular, board->emission, 0);
        G3_PolygonAttr(elem->light, 0, 3, board->polyIdBase + elem->polyId, elem->alpha, 0x8000);
        quadY0 = gBillboardQuad[board->quadShape].y0;
        quadY1 = gBillboardQuad[board->quadShape].y1;
        quadX0 = gBillboardQuad[board->quadShape].x0;
        quadX1 = gBillboardQuad[board->quadShape].x1;
        G3_Begin(1);
        if (elem->light) {
            G3_Normal(normalX, normalY, normalZ);
        } else {
            G3_Color(0x7FFF);
        }
        if (elem->facingMode == 3) {
            G3_TexCoord(sLeft, tTop);
            G3_Vtx(quadX0, 0, quadY0);
            G3_TexCoord(sLeft, tBottom);
            G3_Vtx(quadX0, 0, quadY1);
            G3_TexCoord(sRight, tBottom);
            G3_Vtx(quadX1, 0, quadY1);
            G3_TexCoord(sRight, tTop);
            G3_Vtx(quadX1, 0, quadY0);
        } else {
            G3_TexCoord(sLeft, tTop);
            G3_Vtx(quadX0, quadY0, 0);
            G3_TexCoord(sLeft, tBottom);
            G3_Vtx(quadX0, quadY1, 0);
            G3_TexCoord(sRight, tBottom);
            G3_Vtx(quadX1, quadY1, 0);
            G3_TexCoord(sRight, tTop);
            G3_Vtx(quadX1, quadY0, 0);
        }
        G3_End();
        G3_PopMtx(1);
    }
}
