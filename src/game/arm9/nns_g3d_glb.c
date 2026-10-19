/*
 * file:     nns_g3d_glb.c
 * unit:     yes
 * function: NNS_G3dGlbInit, NNS_G3dGlbFlush, NNS_G3dGlbFlushP, NNS_G3dGlbFlushWVP, NNS_G3dGlbBaseTrans, NNS_G3dGlbBaseScale, NNS_G3dGlbLightVector, NNS_G3dGlbLightColor, NNS_G3dGlbMaterialColorDiffAmb, NNS_G3dGlbMaterialColorSpecEmi, NNS_G3dGlbGetInvCameraMtx, MTX_Inverse44, NNS_G3dGlbGetInvProjectionMtx, NNSi_G3dGlbUpdateWV, NNS_G3dGlbGetWVMtx, NNS_G3dGlbGetInvWVMtx, NNS_G3dGlbGetInvVPMtx, NNS_G3dGlbGetViewPort
 * address:  0x0206A700
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * NitroSystem g3d global state (NNS_G3dGlb at 0x02148B4C): init, flush of the
 * cached geometry-command mirror, the light, material and base-transform
 * setters, and the lazily computed derived matrices (inverse camera, inverse
 * projection, world-view and its inverse, inverse view-projection).
 *
 * Compiler pins: most functions are ../2.0/sp2 on the "kept constants" tell
 * (docs/FRONTEND-PINS.md): the image re-materialises the NNS_G3dGlb address
 * from its pool word at each use, where dsi/1.1p1 hoists it into a callee-saved
 * register and grows the push list.  NNS_G3dGlbBaseTrans and
 * NNS_G3dGlbBaseScale are 1.1p1.
 *
 * symbols:
 *   MTX_Identity43_  0x0207B598  arm
 *   MTX_Identity44_  0x0207BDB4  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   NNS_G3dGeBufferOP_N    0x0206DDA4  arm
 *   MTX_Inverse33    0x0207B0A4  arm
 *   MTX_Inverse43  0x0207B67C  arm
 *   MI_Copy64B        0x02082BA0  arm
 *   MTX_Identity44_   0x0207BDB4  arm
 *   FX_InvFx64c       0x0207C788  arm
 *   MTX_Concat43  0x0207B9F0  arm
 *   MTX_ScaleApply43  0x0207B60C  arm
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44  0x0207BE14  arm
 *   NNS_G3dGlb                   0x02148B4C  data
 */
#include "nns_g3d_glb_types.h"

typedef long long fx64;
typedef long long fx64c;

extern void MTX_Identity43_(MtxFx43 *);
extern void MTX_Identity44_(MtxFx44 *);
extern void MTX_Identity33_(MtxFx33 *);
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 nParams);
extern void MTX_Inverse33(const MtxFx33 *src, MtxFx33 *dst);
extern void MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst);
extern void MI_Copy64B(const void *src, void *dst);
extern fx64c FX_InvFx64c(fx32 v);
extern void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab);
extern void MTX_ScaleApply43(const MtxFx43 *src, MtxFx43 *dst, fx32 x, fx32 y, fx32 z);
extern void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);
extern void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
void NNS_G3dGlbInit(void);
void NNS_G3dGlbFlush(void);
void NNS_G3dGlbFlushP(void);
void NNS_G3dGlbFlushWVP(void);
void NNS_G3dGlbBaseTrans(const VecFx32 *pTrans);
void NNS_G3dGlbBaseScale(const VecFx32 *pScale);
void NNS_G3dGlbLightVector(int lightId, int x, int y, int z);
void NNS_G3dGlbLightColor(int lightId, u32 lightColor);
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 isSetVtxColor);
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 isShininess);
MtxFx43 *NNS_G3dGlbGetInvCameraMtx(void);
int MTX_Inverse44(const MtxFx44 *pSrc, MtxFx44 *pDst);
MtxFx44 *NNS_G3dGlbGetInvProjectionMtx(void);
void NNSi_G3dGlbUpdateWV(void);
MtxFx43 *NNS_G3dGlbGetWVMtx(void);
MtxFx43 *NNS_G3dGlbGetInvWVMtx(void);
MtxFx44 *NNS_G3dGlbGetInvVPMtx(void);
void NNS_G3dGlbGetViewPort(u32 *x1, u32 *y1, u32 *x2, u32 *y2);

/*
 * NNS_G3dGlbInit: writes the initial command words, identity matrices,
 * default lights, colors, polygon attribute, viewport and base transform into
 * the block, around three identity-matrix calls, then a second pass over the
 * 0xec..0x260 window.
 *
 * Pinned ../2.0/sp2: the image re-loads the block base pool word three times
 * and materialises the cmd0/mtxmodeProj zero as its own `mov r0, #0` stored
 * with two separate `str`.  1.1p1 hoists the base into r5, CSEs the zero into
 * r4 and merges the pair into one `stm`.
 */
void NNS_G3dGlbInit(void)
{
    NNSG3dGlb *glb = &NNS_G3dGlb;
    u32 a, b;

    glb->cmd0 = 0x17101610;
    glb->mtxmodeProj = 0;
    glb->mtxmodePosVec = 2;
    glb->cmd1 = 0x32323232;
    glb->cmd2 = 0x60293130;
    glb->cmd3 = 0x33333333;
    glb->cmd4 = 0x002A1B19;
    MTX_Identity43_(&glb->cameraMtx);
    MTX_Identity44_(&glb->projMtx);

    a = 0x40000200;
    b = 0xC0080000;
    glb = &NNS_G3dGlb;
    glb->lightVec[0] = 0x2D8B62D8;
    glb->lightVec[1] = a;
    glb->lightVec[2] = a + 0x3FFFFFFF;
    glb->lightVec[3] = b;
    glb->prmMatColor0 = 0x4210C210;
    glb->prmMatColor1 = 0x4210C210;
    glb->prmPolygonAttr = 0x001F008F;
    glb->prmViewPort = b - 0x90000;
    glb->lightColor[0] = 0x00007FFF;
    glb->lightColor[1] = 0x4000001F;
    glb->lightColor[2] = 0x800003E0;
    glb->lightColor[3] = 0x7e00 - a;
    glb->prmBaseTrans.x = 0;
    glb->prmBaseTrans.y = 0;
    glb->prmBaseTrans.z = 0;
    MTX_Identity33_(&glb->prmBaseRot);

    glb = &NNS_G3dGlb;
    glb->prmBaseScale.x = 0x1000;
    glb->prmBaseScale.y = 0x1000;
    glb->prmBaseScale.z = 0x1000;
    glb->prmTexImageParam = 0;
    glb->flag = 0;
    glb->viewFlipMtx.m[0][2] = 0;
    glb->viewFlipMtx.m[0][1] = 0;
    glb->viewFlipMtx.m[0][0] = 0;
    glb->viewFlipMtx.m[1][2] = 0;
    glb->viewFlipMtx.m[1][0] = 0;
    glb->viewFlipMtx.m[1][1] = 0x1000;
    glb->viewFlipMtx.m[2][1] = 0;
    glb->viewFlipMtx.m[2][0] = 0;
    glb->viewFlipMtx.m[2][2] = (u32)-0x1000;
}

/*
 * Flush of the whole command mirror: registers the 0x3e words at +4, keyed by
 * cmd0, then clears bits 0 and 1 of the flag word.
 *
 * Pinned ../2.0/sp2 (the image re-loads the pool word twice, `push {r3, lr}`).
 * Two spelling points, both needed: the record pointer is `(char *)&NNS_G3dGlb
 * + 4` (as an array index the offset folds into a second pool word; through the
 * char cast it fuses into the post-indexed `ldr r0, [r1], #4`), and the two
 * bit clears are separate statements (one expression folds to a single `bic #3`).
 */
void NNS_G3dGlbFlush(void)
{
    NNS_G3dGeBufferOP_N(NNS_G3dGlb.cmd0, (char *)&NNS_G3dGlb + 4, 0x3e);
    NNS_G3dGlb.flag &= ~1u;
    NNS_G3dGlb.flag &= ~2u;
}

/*
 * Flush of the projection and camera parts: projection block, camera matrix,
 * a projection-mode word and the light/material mirror, then bit 1 of the flag
 * word is set and bit 0 cleared.  The local carries the one-word mode argument
 * whose address is taken (hence the 8-byte frame).
 */
void NNS_G3dGlbFlushP(void)
{
    NNS_G3dGeBufferOP_N(0x1610, &NNS_G3dGlb.mtxmodeProj, 0x11);
    NNS_G3dGeBufferOP_N(0x19, &NNS_G3dGlb.cameraMtx, 0xC);
    {
        int mode = 2;
        NNS_G3dGeBufferOP_N(0x10, &mode, 1);
    }
    NNS_G3dGeBufferOP_N(0x15, &NNS_G3dGlb.cmd1, 0x20);
    NNS_G3dGlb.flag = (NNS_G3dGlb.flag & ~1u) | 2;
}

/*
 * Flush of the full state with the base transform: nine registrations against
 * the same command helper NNS_G3dGeBufferOP_N, one with a one-word out-parameter
 * (mode 2) and one reading a 12-byte inverse of the base rotation, then bit 0
 * of the flag word is set and bit 1 cleared.  The 0x34-byte frame is the
 * 13-word scratch array: w[0] is the mode word, w[1..12] the record.
 *
 * Pinned ../2.0/sp2: the image materialises every call small constants fresh at
 * each site and keeps a bare `stmdb sp!, {lr}` frame; 1.1p1 CSEs 0x19, 0xc and
 * 1 into callee-saved registers.  The pool is shared (0x0206A9CC and
 * 0x0206A9D0 are each loaded twice), so every `ldr [pc]` has to be resolved to
 * its word.  The `+ 4` on cmd1 must go through a `char *` cast: as an array
 * index the offset folds into the pool word and drops the image `add r1, r1,
 * #4`.
 */
void NNS_G3dGlbFlushWVP(void)
{
    u32 w[13];

    NNS_G3dGeBufferOP_N(0x1610, &NNS_G3dGlb.mtxmodeProj, 0x11);
    NNS_G3dGeBufferOP_N(0x19, &NNS_G3dGlb.cameraMtx, 0xC);
    NNS_G3dGeBufferOP_N(0x1b19, &NNS_G3dGlb.prmBaseRot, 0xF);
    w[0] = 2;
    NNS_G3dGeBufferOP_N(0x10, &w[0], 1);
    MTX_Inverse33(&NNS_G3dGlb.prmBaseRot, (MtxFx33 *)&w[1]);
    NNS_G3dGeBufferOP_N(0x17, &w[1], 0xC);
    NNS_G3dGeBufferOP_N(NNS_G3dGlb.cmd1, (char *)&NNS_G3dGlb.cmd1 + 4, 0xE);
    NNS_G3dGeBufferOP_N(0x15, 0, 0);
    NNS_G3dGeBufferOP_N(0x2a, &NNS_G3dGlb.prmTexImageParam, 1);
    NNS_G3dGlb.flag = (NNS_G3dGlb.flag | 1) & ~2u;
}

/* NNS_G3dGlbBaseTrans: set the base translation of the model matrix. */
void NNS_G3dGlbBaseTrans(const VecFx32 *pTrans)
{
    if (pTrans == 0) {
        return;
    }
    NNS_G3dGlb.prmBaseTrans = *pTrans;
    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_BASE_DEPENDENT;
}

/*
 * NNS_G3dGlbBaseScale: copies the caller scale vector into prmBaseScale and
 * clears the 0xa4 bit group of the flag word.
 *
 * The destination being one object with the flag word decides the schedule:
 * as two separate objects the compiler hoists the flag-word load above the
 * store and needs a second pool register (52 bytes); as one object every
 * access is ordered behind the 12-byte copy (48 bytes).
 */
void NNS_G3dGlbBaseScale(const VecFx32 *pScale)
{
    if (pScale == 0) {
        return;
    }
    NNS_G3dGlb.prmBaseScale = *pScale;
    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_BASE_DEPENDENT;
}

/*
 * NNS_G3dGlbLightVector: packs three 10-bit fields (each taken from a signed
 * value shifted right by three) plus the light index at bits 30..31 into one
 * word of the lightVec array.
 */
void NNS_G3dGlbLightVector(int lightId, int x, int y, int z)
{
    NNS_G3dGlb.lightVec[lightId] = (u32)(((x >> 3) & 0x3FF) | (((y >> 3) & 0x3FF) << 10)
                                         | (((z >> 3) & 0x3FF) << 20) | (lightId << 30));
}

/* NNS_G3dGlbLightColor: store the color of one light with the light index in bits 30..31. */
void NNS_G3dGlbLightColor(int lightId, u32 lightColor)
{
    NNS_G3dGlb.lightColor[lightId] = lightColor | (u32)(lightId << 30);
}

/*
 * NNS_G3dGlbMaterialColorDiffAmb: packs the diffuse color, the set-vertex-color
 * bit at bit 15 and the ambient color into prmMatColor0.  Unlabelled leaf (no
 * prologue), so the extent of this and the next function is inferred.
 */
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 isSetVtxColor)
{
    NNS_G3dGlb.prmMatColor0 = diffuse | (ambient << 16) | ((u32)(isSetVtxColor != 0) << 15);
}

/*
 * NNS_G3dGlbMaterialColorSpecEmi: the twin of NNS_G3dGlbMaterialColorDiffAmb,
 * packing the specular color, the shininess-table bit at bit 15 and the
 * emission color into prmMatColor1.
 */
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 isShininess)
{
    NNS_G3dGlb.prmMatColor1 = specular | (emission << 16) | ((u32)(isShininess != 0) << 15);
}

/*
 * Returns the inverse camera matrix, computing it on first use: if the flag
 * word does not carry the valid bit, invert cameraMtx into invCameraMtx and
 * set the bit.
 *
 * Pinned ../2.0/sp2: the image re-materialises the NNS_G3dGlb address from its
 * pool word after the call and keeps `push {r3, lr}`; 1.1p1 keeps it live in r4.
 */
MtxFx43 *NNS_G3dGlbGetInvCameraMtx(void)
{
    if ((NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_INV_CAMERA_VALID) == 0) {
        MTX_Inverse43(&NNS_G3dGlb.cameraMtx, &NNS_G3dGlb.invCameraMtx);
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_INV_CAMERA_VALID;
    }
    return &NNS_G3dGlb.invCameraMtx;
}

static inline fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
    fx64 tmp = v64c * v32 + 0x80000000LL;
    return (fx32)(tmp >> 32);
}

/*
 * 4x4 fx32 matrix inverse, Gauss-Jordan with partial pivoting (a game-side
 * MTX_Inverse44: the SDK in this image carries only MTX_Inverse33/43).
 * Copies pSrc into a stack MtxFx44 (MI_Copy64B), sets pDst to identity,
 * returns -1 on a zero pivot column, else 0.  Row normalisation is
 * FX_Mul32x64c(v, FX_InvFx64c(pivot)) (rounded, >> 32); elimination is an
 * UNROUNDED (fx64)a * b >> 12.
 *
 * Register allocation depends on variable identity, not spelling: the
 * elimination row variable is the SAME variable (j) that recorded the pivot
 * row, so their live ranges merge.
 */
int MTX_Inverse44(const MtxFx44 *pSrc, MtxFx44 *pDst)
{
    MtxFx44 tmp;
    int i, j, k, r;
    fx32 max;

    MI_Copy64B(pSrc, &tmp);
    MTX_Identity44_(pDst);

    for (i = 0; i < 4; ++i) {
        j = i;
        max = 0;
        for (r = i; r < 4; ++r) {
            fx32 ftmp = tmp.m[r][i];
            if (ftmp < 0)
                ftmp = -ftmp;
            if (ftmp > max) {
                max = ftmp;
                j = r;
            }
        }
        if (max == 0)
            return -1;
        if (j != i) {
            for (k = 0; k < 4; ++k) {
                fx32 x;
                x = tmp.m[i][k];
                tmp.m[i][k] = tmp.m[j][k];
                tmp.m[j][k] = x;
                x = pDst->m[i][k];
                pDst->m[i][k] = pDst->m[j][k];
                pDst->m[j][k] = x;
            }
        }
        {
            fx64c recip = FX_InvFx64c(tmp.m[i][i]);
            for (k = 0; k < 4; ++k) {
                tmp.m[i][k] = FX_Mul32x64c(tmp.m[i][k], recip);
                pDst->m[i][k] = FX_Mul32x64c(pDst->m[i][k], recip);
            }
        }
        for (j = 0; j < 4; ++j) {
            if (j != i) {
                fx32 a = tmp.m[j][i];
                for (k = 0; k < 4; ++k) {
                    tmp.m[j][k] -= (fx32)(((fx64)a * tmp.m[i][k]) >> 12);
                    pDst->m[j][k] -= (fx32)(((fx64)a * pDst->m[i][k]) >> 12);
                }
            }
        }
    }
    return 0;
}

/*
 * Returns the inverse projection matrix, computing it on first use (flag bit
 * 0x10) with MTX_Inverse44.  Same shape and ../2.0/sp2 pin as NNS_G3dGlbGetInvCameraMtx.
 */
MtxFx44 *NNS_G3dGlbGetInvProjectionMtx(void)
{
    if ((NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_INV_PROJ_VALID) == 0) {
        MTX_Inverse44(&NNS_G3dGlb.projMtx, &NNS_G3dGlb.invProjMtx);
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_INV_PROJ_VALID;
    }
    return &NNS_G3dGlb.invProjMtx;
}

/*
 * Recomputes the world-view matrices: wvMtx = base transform * camera, scaled
 * by prmBaseScale, then invWvMtx = inverse of wvMtx.
 *
 * Pinned ../2.0/sp2: the image re-materialises the NNS_G3dGlb address before
 * the three calls and loads the slot addresses straight into r0..r2 with a bare
 * `push {r3, lr}`; 1.1p1 keeps them in callee-saved registers.
 */
void NNSi_G3dGlbUpdateWV(void)
{
    MTX_Concat43((const MtxFx43 *)&NNS_G3dGlb.prmBaseRot, &NNS_G3dGlb.cameraMtx, &NNS_G3dGlb.wvMtx);
    MTX_ScaleApply43(&NNS_G3dGlb.wvMtx, &NNS_G3dGlb.wvMtx, NNS_G3dGlb.prmBaseScale.x,
                  NNS_G3dGlb.prmBaseScale.y, NNS_G3dGlb.prmBaseScale.z);
    MTX_Inverse43(&NNS_G3dGlb.wvMtx, &NNS_G3dGlb.invWvMtx);
}

/*
 * Returns the world-view matrix, recomputing both world-view matrices first
 * if the valid bit (0x80) is clear.  Pinned ../2.0/sp2: the address of the
 * returned slot is loaded once, after the branch target.
 */
MtxFx43 *NNS_G3dGlbGetWVMtx(void)
{
    if ((NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_WV_VALID) == 0) {
        NNSi_G3dGlbUpdateWV();
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_WV_VALID;
    }
    return &NNS_G3dGlb.wvMtx;
}

/* Twin of NNS_G3dGlbGetWVMtx returning the inverse world-view matrix. Pinned ../2.0/sp2. */
MtxFx43 *NNS_G3dGlbGetInvWVMtx(void)
{
    if ((NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_WV_VALID) == 0) {
        NNSi_G3dGlbUpdateWV();
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_WV_VALID;
    }
    return &NNS_G3dGlb.invWvMtx;
}

/*
 * Returns the inverse view-projection matrix (invProj * invCamera), computing
 * it on first use (flag bit 0x40).  Pinned ../2.0/sp2: the NNS_G3dGlb address
 * is re-materialised after the two calls; 1.1p1 keeps it in a callee-saved
 * register and grows the frame.
 */
MtxFx44 *NNS_G3dGlbGetInvVPMtx(void)
{
    MtxFx44 cameraMtx44;
    MtxFx43 *invCamera;
    MtxFx44 *invProj;

    if ((NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_INV_VP_VALID) == 0) {
        invCamera = NNS_G3dGlbGetInvCameraMtx();
        invProj = NNS_G3dGlbGetInvProjectionMtx();
        MTX_Copy43To44_(invCamera, &cameraMtx44);
        MTX_Concat44(invProj, &cameraMtx44, &NNS_G3dGlb.invVpMtx);
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_INV_VP_VALID;
    }
    return &NNS_G3dGlb.invVpMtx;
}

/*
 * NNS_G3dGlbGetViewPort: spreads the viewport word over up to four word-sized
 * destinations, one byte per word, low byte first (x1, y1, x2, y2).  Each arm
 * re-spells the global rather than sharing a local, which makes the image
 * re-load the pool word in every arm.  Pinned ../2.0/sp2: with 1.1p1 all four
 * arms are if-converted into predicated instructions.
 */
void NNS_G3dGlbGetViewPort(u32 *x1, u32 *y1, u32 *x2, u32 *y2)
{
    if (x1 != 0)
        *x1 = NNS_G3dGlb.prmViewPort & 0xff;
    if (y1 != 0)
        *y1 = (NNS_G3dGlb.prmViewPort >> 8) & 0xff;
    if (x2 != 0)
        *x2 = (NNS_G3dGlb.prmViewPort >> 16) & 0xff;
    if (y2 != 0)
        *y2 = (NNS_G3dGlb.prmViewPort >> 24) & 0xff;
}
