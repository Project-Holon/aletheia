/*
 * file:     unit_0204F720.c
 * unit:     yes
 * function: func_0204F720, func_0204F748, func_0204F764, func_0204F794, BILLBOARD_SetElemRotZ, BILLBOARD_Draw
 * address:  0x0204F720
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   G3X_Reset          0x0207DA8C  arm
 *   func_02048AE8      0x02048AE8  arm
 *   func_02048B0C      0x02048B0C  arm
 *   func_02048B30      0x02048B30  arm
 *   G3i_LookAt_        0x0207D7C4  arm
 *   MTX_LookAt         0x0207BCA0  arm
 *   MTX_Inverse43      0x0207B67C  arm
 *   MI_Copy36B         0x02082B60  arm
 *   VEC_Subtract       0x0207CA00  arm
 *   VEC_Normalize      0x0207CCA4  arm
 *   MTX_Identity33_    0x0207ADC4  arm
 *   MTX_RotY33_        0x0207AF1C  thumb
 *   G3D_LIGHT_GetSlotColor      0x02048C80  arm
 *   G3D_LIGHT_GetSlotFlags      0x02048CCC  arm
 *   FX_Div             0x0207C768  arm
 *   G3_MultTransMtx33  0x0207D950  arm
 *   G3_RotZ            0x0207D888  arm
 *   _s32_div_f         0x0209C0A4  arm
 *   FX_SinCosTable_    0x020A1B38  data
 *   gBillboardQuad     0x020A1514  data
 */
#include "billboard_types.h"

struct Camera;
struct LightSlot;

typedef int BOOL;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct { fx32 m[4][3]; } MtxFx43;

struct Quad { fx16 y0, y1, x0, x1; };

extern void G3X_Reset(void);
extern void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, BOOL draw, MtxFx43 *mtx);
extern void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);
extern int  MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst);
extern void MI_Copy36B(const void *pSrc, void *pDest);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern void MTX_Identity33_(MtxFx33 *pDst);
extern void MTX_RotY33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern void G3_MultTransMtx33(const MtxFx33 *mtx, const VecFx32 *trans);
extern void G3_RotZ(fx32 s, fx32 c);
extern void func_02048AE8(struct Camera *cam, VecFx32 *out);
extern void func_02048B0C(struct Camera *cam, VecFx32 *out);
extern void func_02048B30(struct Camera *cam, VecFx32 *out);
extern void G3D_LIGHT_GetSlotColor(struct LightSlot *lights, u8 lightIndex, VecFx16 *outVector);
extern void G3D_LIGHT_GetSlotFlags(struct LightSlot *lights, u8 lightIndex, u16 *outColor);
void func_0204F720(struct BbBoard *board, u32 elemIndex, u32 *visible);
u32 func_0204F748(struct BbBoard *board, int elemIndex);
void func_0204F764(struct BbBoard *board, u32 elemIndex, u32 *flipS);
void func_0204F794(struct BbBoard *board, u32 elemIndex, u32 *flipT);
void BILLBOARD_SetElemRotZ(struct BbBoard *board, int elemIndex, u16 *rotZ);
extern const fx16 FX_SinCosTable_[];
extern const struct Quad gBillboardQuad[];


/*
 * Set or clear bit 9 of the record's u16 at +0x18 depending on whether the
 * caller's word is 1.  Both arms are conditional instructions and there is no
 * narrowing shift pair, so the field is a 1-bit bitfield assigned 1/0 rather
 * than a read-modify-write of the whole halfword, and the address is written
 * inside each arm so the condition is evaluated first.
 */
void func_0204F720(struct BbBoard *board, u32 elemIndex, u32 *visible)
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
 * it is the follower that makes func_0204F720 EXACT*.  Seeding 0x0204F748 in
 * layout/function_starts.txt turns that EXACT* into EXACT; that file is the
 * integrator's, not this packet's.
 *
 * It is the same array and the same stride as the three accessors in
 * src/matched/unit_0204F6B4.c, one bit along: that file has bit 9, this one
 * bit 10.  The entry type is declared with its sizeof at 0x1c, so the encoder
 * emits the image's `mov r0, #0x1c` plus `mla`.
 */
u32 func_0204F748(struct BbBoard *board, int elemIndex)
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
void func_0204F764(struct BbBoard *board, u32 elemIndex, u32 *flipS)
{
    struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    elem->flipS = (u16)*flipS;
}


/*
 * Same as func_0204F764 one bit up: the caller's word goes into bit 11.
 */
void func_0204F794(struct BbBoard *board, u32 elemIndex, u32 *flipT)
{
    struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    elem->flipT = (u16)*flipT;
}


/*
 * Halfword store at +0x16 of one 0x1c-byte entry of the descriptor's +8
 * array.  Note +0x16 rather than +0x12/+0x14 - it is the third of the three
 * halfword fields that func_0204F684 and func_0204F6B4's family work on, and
 * it is the follower that makes func_0204F794 EXACT*.
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


#define reg_G3_MTX_MODE        (*(volatile u32 *)0x04000440)

#define reg_G3_MTX_PUSH        (*(volatile u32 *)0x04000444)

#define reg_G3_MTX_POP         (*(volatile u32 *)0x04000448)

#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)

#define reg_G3_COLOR           (*(volatile u32 *)0x04000480)

#define reg_G3_NORMAL          (*(volatile u32 *)0x04000484)

#define reg_G3_TEXCOORD        (*(volatile u32 *)0x04000488)

#define reg_G3_VTX_16          (*(volatile u32 *)0x0400048C)

#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)

#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)

#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)

#define reg_G3_DIF_AMB         (*(volatile u32 *)0x040004C0)

#define reg_G3_SPE_EMI         (*(volatile u32 *)0x040004C4)

#define reg_G3_LIGHT_VECTOR    (*(volatile u32 *)0x040004C8)

#define reg_G3_LIGHT_COLOR     (*(volatile u32 *)0x040004CC)

#define reg_G3_BEGIN_VTXS      (*(volatile u32 *)0x04000500)

#define reg_G3_END_VTXS        (*(volatile u32 *)0x04000504)


#define GX_VECFX10(x, y, z) \
    ((u32)(((((x) >> 3) & 0x3ff) << 0) | \
           ((((y) >> 3) & 0x3ff) << 10) | \
           ((((z) >> 3) & 0x3ff) << 20)))

#define GX_FX16PAIR(a, b)  ((u32)((u32)(u16)(a) | ((u32)(u16)(b) << 16)))

#define GX_FX16ST(x)       ((s16)((x) >> 8))

#define GX_ST(s, t)        ((u32)((u16)GX_FX16ST(s) | ((u16)GX_FX16ST(t) << 16)))


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
 * G3D_LIGHT_GetSlotColor/CCC take a u8 index here (`and r1, r8, #0xff`).
 */
void BILLBOARD_Draw(struct BbBoard *board, struct Camera *camera, struct LightSlot *lights)
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
    func_02048AE8(camera, &cameraPos);
    func_02048B0C(camera, &cameraUp);
    func_02048B30(camera, &cameraTarget);
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
            G3D_LIGHT_GetSlotColor(lights, lightIndex, &lightVec);
            G3D_LIGHT_GetSlotFlags(lights, lightIndex, &lightColor);
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
