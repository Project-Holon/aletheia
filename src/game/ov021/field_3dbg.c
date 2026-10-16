/*
 * file:     field_3dbg.c
 * unit:     yes
 * function: FIELD_3DBG_CreateBillboard, FIELD_3DBG_DeleteBillboard, FIELD_3DBG_DrawBillboard, FIELD_3DBG_ReleaseBillboardTextureVram, FIELD_3DBG_FreeBillboardTexture, FIELD_3DBG_LoadBillboardTexture, FIELD_3DBG_SetBillboardVisible, FIELD_3DBG_SetBillboardPolygonId, FIELD_3DBG_SetBillboardTexOffsetX, FIELD_3DBG_SetBillboardTexOffsetY, FIELD_3DBG_SetBillboardScaleX, FIELD_3DBG_SetBillboardScaleY, FIELD_3DBG_LoadTexture, FIELD_3DBG_FreeTexture, FIELD_3DBG_ReleaseTextureVram, FIELD_3DBG_IsTextureLoaded, FIELD_3DBG_CalcQuadGeometry, FIELD_3DBG_DrawQuad, FIELD_3DBG_SetPolygonAttr, FIELD_3DBG_SetTextureParams
 * address:  0x021A15A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   abs_id_20      0x00000020  data
 *   abs_id_21      0x00000021  data
 *   abs_id_22      0x00000022  data
 *   ov035_func_021EFEC0  0x021EFEC0  thumb  ov035
 *   abs_id_23      0x00000023  data
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   g_Field3dbgSourceName     0x021DDE5C  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   func_0207D8C4  0x0207D8C4  arm
 *   g_DefaultProjectionMtx     0x02148B54  data  a4
 *   G3D_SYSTEM_GetResourceSize  0x02046C94  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   G3D_SYSTEM_InitResourceByFile  0x02046CE0  arm
 *   G3D_SYSTEM_AllocVramTexture  0x02047180  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_TransAllocatedTexture  0x02047204  arm
 *   FX_Div            0x0207C768  arm
 *   MTX_Identity33_   0x0207ADC4  arm
 *   MTX_RotZ33_       0x0207AF38  thumb
 *   MTX_Scale33_      0x0207AE24  thumb
 *   MTX_Concat33      0x0207B388  arm
 *   FX_SinCosTable_   0x020A1B38  data
 *   G3_MultMtx33  0x0207D934  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 */
#define REG_MTX_MODE     (*(volatile u32 *)0x04000440)
#define REG_MTX_PUSH     (*(volatile u32 *)0x04000444)
#define REG_MTX_POP      (*(volatile u32 *)0x04000448)
#define REG_MTX_IDENTITY (*(volatile u32 *)0x04000454)
#define REG_MTX_SCALE    (*(volatile u32 *)0x0400046C)
#define REG_TEXCOORD     (*(volatile u32 *)0x04000488)
#define REG_VTX_16       (*(volatile u32 *)0x0400048C)
#define REG_POLYGON_ATTR (*(volatile u32 *)0x040004A4)
#define REG_DIF_AMB      (*(volatile u32 *)0x040004C0)
#define REG_TEXIMAGE_PARAM (*(volatile u32 *)0x040004A8)
#define REG_PLTT_BASE    (*(volatile u32 *)0x040004AC)
#define REG_BEGIN_VTXS   (*(volatile u32 *)0x04000500)
#define REG_END_VTXS     (*(volatile u32 *)0x04000504)

#include "field_3dbg_types.h"
#include "field_subscreen_types.h"

struct G3dResource;

/* 4x4 projection matrix as read back from the geometry engine. */
typedef struct {
    fx32 xScale;
    fx32 xRowRest[3];
    fx32 yRowLead;
    fx32 yScale;
    fx32 zwRows[10];
} ProjectionMtx;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

extern void *ov035_func_021EFEC0(void *work, void *gameSystem, u32 heapId);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern void NNS_G3dGeFlushBuffer(void);
extern void func_0207D8C4(ProjectionMtx *m);
extern int G3D_SYSTEM_GetResourceSize(void);
extern void *ARC_TOOL_LoadHandleMember(void *archive, u32 fileId, u16 heapId);
extern void G3D_SYSTEM_InitResourceByFile(void *dst, void *src);
extern int G3D_SYSTEM_AllocVramTexture(void *resource);
extern void G3D_SYSTEM_DeleteResource(struct G3dResource *resource);
extern int G3D_SYSTEM_FreeVramTexture(void *resource);
u32 G3D_SYSTEM_TransAllocatedTexture(struct G3dResource *p);
fx32 FX_Div(fx32 numer, fx32 denom);
void MTX_Identity33_(MtxFx33 *pDst);
void MTX_RotZ33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_Scale33_(MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
extern void G3_MultMtx33(const void *m);
u32 func_02047388(struct G3dResource *resource);
u32 func_020473B8(struct G3dResource *resource);
Field3dbgBillboard *FIELD_3DBG_CreateBillboard(const Field3dbgBillboardDesc *desc, u32 heapId);
int FIELD_3DBG_DeleteBillboard(Field3dbgBillboard *billboard);
void FIELD_3DBG_DrawBillboard(Field3dbgBillboard *billboard);
void FIELD_3DBG_ReleaseBillboardTextureVram(Field3dbgBillboard *billboard);
void FIELD_3DBG_FreeBillboardTexture(Field3dbgBillboard *billboard);
int FIELD_3DBG_LoadBillboardTexture(Field3dbgBillboard *billboard, void *archive, const Field3dbgTextureDesc *desc, u32 heapId);
void FIELD_3DBG_SetBillboardVisible(Field3dbgBillboard *billboard, u32 isVisible);
void FIELD_3DBG_SetBillboardPolygonId(Field3dbgBillboard *billboard, u8 polygonId);
void FIELD_3DBG_SetBillboardTexOffsetX(Field3dbgBillboard *billboard, fx32 texOffsetX);
void FIELD_3DBG_SetBillboardTexOffsetY(Field3dbgBillboard *billboard, fx32 texOffsetY);
void FIELD_3DBG_SetBillboardScaleX(Field3dbgBillboard *billboard, fx32 scaleX);
void FIELD_3DBG_SetBillboardScaleY(Field3dbgBillboard *billboard, fx32 scaleY);
void FIELD_3DBG_LoadTexture(Field3dbgTexture *tex, void *archive, const Field3dbgTextureDesc *desc, u32 heapId);
int FIELD_3DBG_FreeTexture(Field3dbgTexture *tex);
void FIELD_3DBG_ReleaseTextureVram(Field3dbgTexture *tex);
u32 FIELD_3DBG_IsTextureLoaded(Field3dbgTexture *tex);
void FIELD_3DBG_CalcQuadGeometry(Field3dbgQuadGeometry *out, const Field3dbgBillboard *in, const Field3dbgTexture *texture, const ProjectionMtx *proj);
void FIELD_3DBG_DrawQuad(const Field3dbgQuadGeometry *geom);
void FIELD_3DBG_SetPolygonAttr(Field3dbgBillboard *billboard);
void FIELD_3DBG_SetTextureParams(Field3dbgBillboard *billboard);
extern unsigned char abs_id_20[];
extern unsigned char abs_id_21[];
extern unsigned char abs_id_22[];
extern unsigned char abs_id_23[];
extern char g_Field3dbgSourceName[];
extern ProjectionMtx g_DefaultProjectionMtx;
extern const s16 FX_SinCosTable_[];

/* Allocate a billboard and copy its size, distance and polygon id from desc. */
Field3dbgBillboard *FIELD_3DBG_CreateBillboard(const Field3dbgBillboardDesc *desc, u32 heapId)
{
    Field3dbgBillboard *billboard = GFL_HEAP_Alloc((u16)heapId, 0x70, 1, g_Field3dbgSourceName, 0x95);
    billboard->width = desc->width;
    billboard->height = desc->height;
    billboard->distance = desc->distance;
    billboard->polygonId = desc->polygonId;
    billboard->isVisible = 1;
    return billboard;
}

/* Free the billboard's texture if loaded, then the billboard itself. */
int FIELD_3DBG_DeleteBillboard(Field3dbgBillboard *billboard)
{
    if (FIELD_3DBG_IsTextureLoaded(&billboard->tex) != 0) {
        FIELD_3DBG_FreeTexture(&billboard->tex);
    }
    return GFL_HEAP_Free(billboard);
}

/* Draw the billboard as one textured quad. */
void FIELD_3DBG_DrawBillboard(Field3dbgBillboard *billboard)
{
    ProjectionMtx proj;
    if (billboard != 0 && billboard->isVisible != 0 && FIELD_3DBG_IsTextureLoaded(&billboard->tex) != 0) {
        NNS_G3dGeFlushBuffer();
        REG_MTX_MODE = 0;
        proj = g_DefaultProjectionMtx;
        func_0207D8C4(&proj);
        REG_MTX_MODE = 2;
        REG_MTX_IDENTITY = 0;
        REG_MTX_PUSH = 0;
        FIELD_3DBG_CalcQuadGeometry(&billboard->geom, billboard, &billboard->tex, &proj);
        FIELD_3DBG_SetPolygonAttr(billboard);
        FIELD_3DBG_SetTextureParams(billboard);
        FIELD_3DBG_DrawQuad(&billboard->geom);
        REG_MTX_POP = 1;
    }
}

/* Release the VRAM copy of the billboard's texture. */
void FIELD_3DBG_ReleaseBillboardTextureVram(Field3dbgBillboard *billboard)
{
    if (billboard != 0)
        FIELD_3DBG_ReleaseTextureVram(&billboard->tex);
}

/* Free the billboard's texture resource if loaded. */
void FIELD_3DBG_FreeBillboardTexture(Field3dbgBillboard *billboard)
{
    if (FIELD_3DBG_IsTextureLoaded(&billboard->tex) != 0)
        FIELD_3DBG_FreeTexture(&billboard->tex);
}

/* Replace the billboard's texture with the one described by desc and reset its transform. */
int FIELD_3DBG_LoadBillboardTexture(Field3dbgBillboard *billboard, void *archive, const Field3dbgTextureDesc *desc, u32 heapId)
{
    if (FIELD_3DBG_IsTextureLoaded(&billboard->tex) != 0) {
        FIELD_3DBG_FreeTexture(&billboard->tex);
    }
    FIELD_3DBG_LoadTexture(&billboard->tex, archive, desc, heapId);
    billboard->alpha = desc->alpha;
    billboard->scaleX = (1 << 12);
    billboard->scaleY = (1 << 12);
    billboard->rotation = 0;
    return 0;
}

void FIELD_3DBG_SetBillboardVisible(Field3dbgBillboard *billboard, u32 isVisible)
{
    billboard->isVisible = isVisible;
}

void FIELD_3DBG_SetBillboardPolygonId(Field3dbgBillboard *billboard, u8 polygonId)
{
    billboard->polygonId = polygonId;
}

void FIELD_3DBG_SetBillboardTexOffsetX(Field3dbgBillboard *billboard, fx32 texOffsetX)
{
    billboard->texOffsetX = texOffsetX;
}

void FIELD_3DBG_SetBillboardTexOffsetY(Field3dbgBillboard *billboard, fx32 texOffsetY)
{
    billboard->texOffsetY = texOffsetY;
}

void FIELD_3DBG_SetBillboardScaleX(Field3dbgBillboard *billboard, fx32 scaleX)
{
    billboard->scaleX = scaleX;
}

void FIELD_3DBG_SetBillboardScaleY(Field3dbgBillboard *billboard, fx32 scaleY)
{
    billboard->scaleY = scaleY;
}

/*
 * Load a texture resource from the archive into tex.
 * `const` on desc is what schedules the second (u16)heapId truncation ahead of
 * the store of the allocation to tex->resource.
 */
void FIELD_3DBG_LoadTexture(Field3dbgTexture *tex, void *archive, const Field3dbgTextureDesc *desc, u32 heapId)
{
    void *data;

    tex->sizeS = desc->sizeS;
    tex->sizeT = desc->sizeT;
    tex->repeat = desc->repeat;
    tex->flip = desc->flip;
    tex->format = desc->format;
    tex->plttColor0 = desc->plttColor0;
    tex->resource = GFL_HEAP_Alloc((u16)heapId, G3D_SYSTEM_GetResourceSize(), 1, g_Field3dbgSourceName, 0x2ad);
    data = ARC_TOOL_LoadHandleMember(archive, desc->fileId, heapId);
    G3D_SYSTEM_InitResourceByFile(tex->resource, data);
    G3D_SYSTEM_AllocVramTexture(tex->resource);
    tex->isLoaded = 1;
    tex->isResident = 1;
}

/* Free the texture resource and mark the texture as not loaded. */
int FIELD_3DBG_FreeTexture(Field3dbgTexture *tex)
{
    G3D_SYSTEM_FreeVramTexture(tex->resource);
    G3D_SYSTEM_DeleteResource(tex->resource);
    tex->resource = 0;
    tex->isLoaded = 0;
    return 0;
}

/* Release the VRAM copy of the texture. */
void FIELD_3DBG_ReleaseTextureVram(Field3dbgTexture *tex)
{
    if (tex->isResident != 0) {
        G3D_SYSTEM_TransAllocatedTexture(tex->resource);
        tex->isResident = 0;
    }
}

u32 FIELD_3DBG_IsTextureLoaded(Field3dbgTexture *tex)
{
    return tex->isLoaded;
}

static inline fx16 FX_SinIdx(int idx) { return FX_SinCosTable_[idx * 2]; }

static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[idx * 2 + 1]; }

/*
 * Compute the quad extents (distance divided by the projection scales, then
 * normalised by the largest of the three), the texture window and the
 * rotation/scale matrix of a billboard.
 *
 * Notes: `in` is const (lets in->distance and out->halfHeight loads rise above
 * the out->halfWidth store); the 3-way max is four arms each calling
 * FX_Div(.., 0x4000) into out->scale (tail-merged). The texture window stores
 * use two locals, both computed before any store, with y declared before x:
 * that keeps (texOffsetX<<12)+(width<<12) unfolded and gives the late texT0
 * store from r2.
 */
void FIELD_3DBG_CalcQuadGeometry(Field3dbgQuadGeometry *out, const Field3dbgBillboard *in, const Field3dbgTexture *texture, const ProjectionMtx *proj)
{
    MtxFx33 scaleMtx;
    fx32 y;
    fx32 x;

    out->halfHeight = FX_Div(in->distance, proj->yScale);
    out->halfWidth = FX_Div(in->distance, proj->xScale);
    out->depth = in->distance;
    if (out->halfHeight > out->halfWidth) {
        if (out->halfHeight > out->depth) {
            out->scale = FX_Div(out->halfHeight, 0x4000);
        } else {
            out->scale = FX_Div(out->depth, 0x4000);
        }
    } else if (out->halfWidth > out->depth) {
        out->scale = FX_Div(out->halfWidth, 0x4000);
    } else {
        out->scale = FX_Div(out->depth, 0x4000);
    }
    out->halfWidth = FX_Div(out->halfWidth, out->scale);
    out->halfHeight = FX_Div(out->halfHeight, out->scale);
    out->depth = FX_Div(out->depth, out->scale);
    x = in->texOffsetX << 12;
    y = in->texOffsetY << 12;
    out->texS0 = x;
    out->texS1 = x + (in->width << 12);
    out->texT0 = y;
    out->texT1 = y + (in->height << 12);
    MTX_Identity33_(&out->rotation);
    MTX_RotZ33_(&out->rotation, FX_SinIdx(in->rotation >> 4), FX_CosIdx(in->rotation >> 4));
    MTX_Scale33_(&scaleMtx, in->scaleX, in->scaleY, 0x1000);
    MTX_Concat33(&out->rotation, &scaleMtx, &out->rotation);
}

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(fx16)(s >> 8) | ((u32)(u16)(fx16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

/*
 * Draws one textured quad through the geometry engine registers
 * (MTX_MODE 0x04000440 .. END_VTXS 0x04000504); G3_MultMtx33 is the
 * 3x3 matrix multiply (command 0x1A). The parameter must be const: without
 * it every geom load is repeated after each volatile register store (340 B).
 */
void FIELD_3DBG_DrawQuad(const Field3dbgQuadGeometry *geom)
{
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    G3_MultMtx33(&geom->rotation);
    REG_MTX_MODE = 2;
    REG_MTX_SCALE = geom->scale;
    REG_MTX_SCALE = geom->scale;
    REG_MTX_SCALE = geom->scale;
    REG_BEGIN_VTXS = 1;
    G3_TexCoord(geom->texS0, geom->texT0);
    G3_Vtx(-geom->halfWidth, geom->halfHeight, -geom->depth);
    G3_TexCoord(geom->texS0, geom->texT1);
    G3_Vtx(-geom->halfWidth, -geom->halfHeight, -geom->depth);
    G3_TexCoord(geom->texS1, geom->texT1);
    G3_Vtx(geom->halfWidth, -geom->halfHeight, -geom->depth);
    G3_TexCoord(geom->texS1, geom->texT0);
    G3_Vtx(geom->halfWidth, geom->halfHeight, -geom->depth);
    REG_END_VTXS = 0;
}

static inline void G3_PolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc)
{
    REG_POLYGON_ATTR = (u32)((light << 0) | (polyMode << 4) | (cullMode << 6) | misc |
                                        (polygonID << 24) | (alpha << 16));
}

/*
 * G3_MaterialColorDiffAmb(white, white, TRUE) as a literal, then the SDK
 * G3_PolygonAttr inline (int parameters) with the billboard's polygon id and alpha.
 */
void FIELD_3DBG_SetPolygonAttr(Field3dbgBillboard *billboard)
{
    REG_DIF_AMB = 0x7FFFFFFF;
    G3_PolygonAttr(0, 0, 2, billboard->polygonId, billboard->alpha, 0x8000);
}

static inline void G3_TexImageParam(GXTexFmt fmt, GXTexGen gen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG_TEXIMAGE_PARAM = (u32)((addr >> 3) | (fmt << 26) | (gen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}

static inline void G3_TexPlttBase(u32 addr, GXTexFmt fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == GX_TEXFMT_PLTT4)));
    REG_PLTT_BASE = param;
}

static inline u32 NNS_GfdGetTexKeyAddr(u32 key) { return (u32)((0x0000FFFF & key) << 3); }

static inline u32 NNS_GfdGetPlttKeyAddr(u32 key) { return (u32)((0x0000FFFF & key) << 3); }

/*
 * SDK G3_TexImageParam / G3_TexPlttBase inlines with the SDK enum parameter
 * types (enum parameters are materialised as temporaries before the body,
 * which gives the load order and the [sp] spill of the tex key), NNS key
 * address inlines, and the format read once into an int local.
 */
void FIELD_3DBG_SetTextureParams(Field3dbgBillboard *billboard)
{
    u32 texKey = func_02047388(billboard->tex.resource);
    int format = billboard->tex.format;

    G3_TexImageParam(format, GX_TEXGEN_TEXCOORD, billboard->tex.sizeS, billboard->tex.sizeT, billboard->tex.repeat, billboard->tex.flip, billboard->tex.plttColor0, NNS_GfdGetTexKeyAddr(texKey));
    G3_TexPlttBase(NNS_GfdGetPlttKeyAddr(func_020473B8(billboard->tex.resource)), format);
}
