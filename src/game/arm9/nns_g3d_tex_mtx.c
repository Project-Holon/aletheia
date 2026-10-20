/*
 * file:     nns_g3d_tex_mtx.c
 * unit:     yes
 * function: NNSi_G3dTexMtxScaleRotTrans, NNSi_G3dTexMtxRotTrans, NNSi_G3dTexMtxScaleTrans2, NNSi_G3dTexMtxTrans2, NNSi_G3dTexMtxScaleRot, NNSi_G3dTexMtxRot, NNSi_G3dTexMtxScale, NNSi_G3dTexMtxIdentity2, NNSi_G3dSendTexMtx, NNSi_G3dTexMtxScaleRotTrans_Max, NNSi_G3dTexMtxRotTrans_Max, NNSi_G3dTexMtxScaleTrans_Max, NNSi_G3dTexMtxTrans_Max, NNSi_G3dTexMtxScaleRot_Max, NNSi_G3dTexMtxRot_Max, NNSi_G3dTexMtxScale_Max, NNSi_G3dTexMtxIdentity_Max, NNSi_G3dSendTexMtx_Max
 * address:  0x02071A24
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from nns_g3d_tex_mtx.c, nns_g3d_tex_mtx_max.c by tools/splitfile.py.
 *
 * symbols:
 *   FX_DivAsync  0x0207C930  arm
 *   FX_GetDivResult  0x0207C86C  arm
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   gNNSiG3dTexMtxFuncTable  0x020A8458  data
 *   data_020A8478  0x020A8478  data
 */

#include "../types.h"

#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_LOAD      0x08

#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_FUNC_MASK 0x07

/* Result of the material animation (0x38 bytes). */
#include "nns_g3d_anm_calc_types.h"

/* Texture matrix (MtxFx44 layout); the constructors write m00, m01, m10, m11, m30 and m31. */
typedef struct {
    s32 m00, m01, m02, m03;
    s32 m10, m11, m12, m13;
    s32 m20, m21, m22, m23;
    s32 m30, m31, m32, m33;
} TexMtx;

/* Geometry command record: MTX_MODE(texture), MTX_LOAD_4x4 or MTX_MULT_4x4, MTX_MODE(position/vector). */
typedef struct {
    u32    cmds;
    s32    mtxModeTexture;
    TexMtx mtx;
    s32    mtxModePosVec;
} TexMtxCmd;

typedef void (*NNSiG3dTexMtxFunc)(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

#ifdef __MWERKS__
extern void FX_DivAsync(s32 numer, s32 denom);
extern s32  FX_GetDivResult(void); /* original prototype; the definition differs in return type */
#else
#include "fx_cp.h"
#endif

#include "nns_g3d_ge.h"

void NNSi_G3dTexMtxScaleRotTrans(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxRotTrans(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxScaleTrans2(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxTrans2(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxScaleRot(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxRot(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxScale(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxIdentity2(TexMtx *pTexMtx);

void NNSi_G3dSendTexMtx(NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxScaleRotTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxRotTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxScaleTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

void NNSi_G3dTexMtxTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm);

extern NNSiG3dTexMtxFunc gNNSiG3dTexMtxFuncTable[];

/*
 * Texture matrix from scale, rotation and translation. The two plain negated
 * multipliers of NNSi_G3dTexMtxScaleRot are replaced by the
 * translation-weighted pair
 *   offsetS = (-origWidth << 11) - transS * origWidth
 *   offsetT = transT * origHeight + (-origHeight << 11)
 * and m30 = (p*offsetS - q*offsetT) >> 8 + origWidth << 15,
 * m31 = (bd*offsetS + r*offsetT) >> 8 + origHeight << 15.
 * Not pinned: exact under both 1.1p1 and 2.0.
 */
void NNSi_G3dTexMtxScaleRotTrans(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx;
    s32 scaleSCos, scaleSSin, scaleTCos, scaleTSin, divResult;
    s32 offsetS, offsetT;
    s64 acc;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);
    FX_DivAsync(heightFx, widthFx);
    scaleSCos = (s32)(((s64)pMatAnm->scaleS * pMatAnm->cosR) >> 12);
    scaleSSin = (s32)(((s64)pMatAnm->scaleS * pMatAnm->sinR) >> 12);
    scaleTCos = (s32)(((s64)pMatAnm->scaleT * pMatAnm->cosR) >> 12);
    scaleTSin = (s32)(((s64)pMatAnm->scaleT * pMatAnm->sinR) >> 12);
    pTexMtx->m00 = scaleSCos;
    pTexMtx->m11 = scaleTCos;
    divResult = FX_GetDivResult();
    pTexMtx->m01 = (scaleTSin * divResult) >> 12;
    FX_DivAsync(widthFx, heightFx);
    offsetS = ((0 - (s32)pMatAnm->origWidth) << 11) - pMatAnm->transS * pMatAnm->origWidth;
    offsetT = pMatAnm->transT * pMatAnm->origHeight + ((0 - (s32)pMatAnm->origHeight) << 11);
    acc = (s64)scaleSCos * offsetS - (s64)scaleSSin * offsetT;
    pTexMtx->m30 = (s32)(acc >> 8) + ((s32)pMatAnm->origWidth << 15);
    acc = (s64)scaleTSin * offsetS + (s64)scaleTCos * offsetT;
    pTexMtx->m31 = ((s32)pMatAnm->origHeight << 15) + (s32)(acc >> 8);
    divResult = FX_GetDivResult();
    pTexMtx->m10 = ((0 - scaleSSin) * divResult) >> 12;
}

/*
 * Texture matrix from rotation and translation (scale one). Brackets the
 * body with the two FX_DivAsync divide calls (arguments swapped between
 * them), writes the s16 cosR into m00 and m11, derives m01/m10 from sinR and
 * the divide result, and builds m30/m31 from transS/transT biased by the
 * original width and height.
 *
 * Spelling tells (bytes out on the whole function):
 *   33 -> 18  bind the two halfwords to named locals `width`/`height` and read
 *             origWidth first: unbound, the origHeight ldrh is emitted ahead
 *             of the origWidth one.
 *   18 -> 11  write m31's `<< 15` term first and the shifted product second;
 *             m30 keeps the opposite order.
 *   11 ->  9  bind cosR/sinR to `cosRot`/`sinRot` before the m31 chain.
 *    9 ->  0  the m31 chain is `sinRot * (s64)offsetS + cosRot * (s64)offsetT`:
 *             both the term order and each factor's operand order matter.
 * Not pinned: 1.1p1 reproduces it exactly.
 */
void NNSi_G3dTexMtxRotTrans(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx, divResult;
    s32 offsetS, offsetT, width, height, cosRot, sinRot;
    s64 acc;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);
    FX_DivAsync(heightFx, widthFx);
    pTexMtx->m00 = pMatAnm->cosR;
    pTexMtx->m11 = pMatAnm->cosR;
    divResult = FX_GetDivResult();
    pTexMtx->m01 = (pMatAnm->sinR * divResult) >> 12;
    FX_DivAsync(widthFx, heightFx);
    width = (s32)pMatAnm->origWidth;
    height = (s32)pMatAnm->origHeight;
    offsetT = pMatAnm->transT * height;
    offsetT = offsetT + ((0 - height) << 11);
    offsetS = pMatAnm->transS * width;
    offsetS = ((0 - width) << 11) - offsetS;
    acc = (s64)pMatAnm->cosR * offsetS - (s64)pMatAnm->sinR * offsetT;
    pTexMtx->m30 = (s32)(acc >> 8) + ((s32)pMatAnm->origWidth << 15);
    cosRot = pMatAnm->cosR;
    sinRot = pMatAnm->sinR;
    acc = sinRot * (s64)offsetS + cosRot * (s64)offsetT;
    pTexMtx->m31 = ((s32)pMatAnm->origHeight << 15) + (s32)(acc >> 8);
    divResult = FX_GetDivResult();
    pTexMtx->m10 = ((0 - (s32)pMatAnm->sinR) * divResult) >> 12;
}

/*
 * Scale and translation (rotation zero): scaleS/scaleT straight into the
 * diagonal slots m00/m11, m01/m10 zeroed, and both translations through a
 * 64-bit product against the scale:
 *   m30 = (scaleS * ((-origWidth << 11) - transS * origWidth)) >> 8  +  origWidth << 15
 *   m31 = (scaleT * (transT * origHeight + (-origHeight << 11))) >> 8  +  origHeight << 15
 *
 * What the image needs:
 *   - the four source reads (origWidth, transS, origHeight, transT) bound to
 *     locals before the first store to m30;
 *   - the m31 multiplier computed into its own local ahead of the m30
 *     product;
 *   - the origWidth local typed u16, the field's own type (s32 swaps r5/r6).
 * Needs ../2.0/sp2: under 1.1p1 the final `ldrh` of origHeight is scheduled
 * one slot earlier, ahead of `lsr r2, lr, #8`.
 */
void NNSi_G3dTexMtxScaleTrans2(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    u16 origWidth;
    s32 origHeight, transS, transT;
    s64 acc;
    s32 offsetT;

    pTexMtx->m00 = pMatAnm->scaleS;
    pTexMtx->m11 = pMatAnm->scaleT;
    pTexMtx->m01 = 0;

    origWidth = pMatAnm->origWidth;
    transS = pMatAnm->transS;
    origHeight = pMatAnm->origHeight;
    transT = pMatAnm->transT;

    offsetT = transT * origHeight + ((0 - origHeight) << 11);

    acc = (s64)pMatAnm->scaleS * (((0 - origWidth) << 11) - transS * origWidth);
    pTexMtx->m30 = (s32)(acc >> 8) + (origWidth << 15);

    acc = (s64)pMatAnm->scaleT * offsetT;
    pTexMtx->m31 = (s32)(acc >> 8) + ((s32)pMatAnm->origHeight << 15);

    pTexMtx->m10 = 0;
}

/*
 * Translation only (scale one, rotation zero): writes the 0x1000 unit scale
 * into m00/m11, zeroes m01/m10, and derives m30/m31 from the negated transS
 * and transT scaled by the original width and height.
 *
 * Needs ../2.0/sp2: the image materialises the zero late (`mov ip, #0` after
 * both unit-scale stores), which keeps the m00 and m01 stores separate;
 * 1.1p1 merges them into one `stm r0, {r2, ip}` and comes out 4 bytes short.
 */
void NNSi_G3dTexMtxTrans2(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 trans;

    pTexMtx->m00 = 0x1000;
    pTexMtx->m11 = 0x1000;
    pTexMtx->m01 = 0;

    trans = 0 - pMatAnm->transS;
    pTexMtx->m30 = trans * pMatAnm->origWidth * 16;

    trans = pMatAnm->transT;
    pTexMtx->m31 = trans * pMatAnm->origHeight * 16;

    pTexMtx->m10 = 0;
}

/*
 * Texture matrix from scale and rotation (translation zero). Every quartet
 * is `((s64)field * field) >> 12`.
 *
 * The m30/m31 pair is one chained term per statement: the smull/smlal split
 * names the operand order, so the additive term is written second (mwcc gives
 * the smull to the second operand and the smlal to the first). The two
 * negations are the two-statement form (`n = 0 - x`); folding them into the
 * multiply re-associates and loses both `rsb`s.
 */
void NNSi_G3dTexMtxScaleRot(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx;
    s32 scaleSCos, scaleSSin, scaleTCos, scaleTSin, divResult;
    s32 negWidth, negHeight;
    s64 acc;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);
    FX_DivAsync(heightFx, widthFx);
    scaleSCos = (s32)(((s64)pMatAnm->scaleS * pMatAnm->cosR) >> 12);
    scaleSSin = (s32)(((s64)pMatAnm->scaleS * pMatAnm->sinR) >> 12);
    scaleTCos = (s32)(((s64)pMatAnm->scaleT * pMatAnm->cosR) >> 12);
    scaleTSin = (s32)(((s64)pMatAnm->scaleT * pMatAnm->sinR) >> 12);
    pTexMtx->m00 = scaleSCos;
    pTexMtx->m11 = scaleTCos;
    divResult = FX_GetDivResult();
    pTexMtx->m01 = (scaleTSin * divResult) >> 12;
    FX_DivAsync(widthFx, heightFx);
    negWidth = 0 - (s32)pMatAnm->origWidth;
    negHeight = 0 - (s32)pMatAnm->origHeight;
    acc = (s64)scaleSCos * (negWidth << 11) - (s64)scaleSSin * (negHeight << 11);
    pTexMtx->m30 = (s32)(acc >> 8) + ((s32)pMatAnm->origWidth << 15);
    acc = (s64)scaleTSin * (negWidth << 11) + (s64)scaleTCos * (negHeight << 11);
    pTexMtx->m31 = (s32)(acc >> 8) + ((s32)pMatAnm->origHeight << 15);
    divResult = FX_GetDivResult();
    pTexMtx->m10 = ((0 - scaleSSin) * divResult) >> 12;
}

/*
 * Texture matrix from rotation only (scale one, translation zero). In m30 the
 * `<< 15` term is written last (`(acc >> 8) + (origWidth << 15)`), in m31 it
 * is written first; spelled the other way round the allocator names r3/r4/r2
 * for the three loads where the image names r2/r3/ip.
 */
void NNSi_G3dTexMtxRot(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx;
    s32 divResult;
    s32 negWidth, negHeight;
    s64 acc;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);
    FX_DivAsync(heightFx, widthFx);
    pTexMtx->m00 = pMatAnm->cosR;
    pTexMtx->m11 = pMatAnm->cosR;
    divResult = FX_GetDivResult();
    pTexMtx->m01 = (pMatAnm->sinR * divResult) >> 12;
    FX_DivAsync(widthFx, heightFx);
    negWidth = 0 - (s32)pMatAnm->origWidth;
    negHeight = 0 - (s32)pMatAnm->origHeight;
    acc = (s64)pMatAnm->cosR * (negWidth << 11) - (s64)pMatAnm->sinR * (negHeight << 11);
    pTexMtx->m30 = (s32)(acc >> 8) + ((s32)pMatAnm->origWidth << 15);
    acc = (s64)pMatAnm->sinR * (negWidth << 11) + (s64)pMatAnm->cosR * (negHeight << 11);
    pTexMtx->m31 = ((s32)pMatAnm->origHeight << 15) + (s32)(acc >> 8);
    divResult = FX_GetDivResult();
    pTexMtx->m10 = ((0 - (s32)pMatAnm->sinR) * divResult) >> 12;
}

/* Texture matrix from scale only (no rotation, no translation). */
void NNSi_G3dTexMtxScale(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 offsetS, offsetT;

    pTexMtx->m00 = pMatAnm->scaleS;
    pTexMtx->m11 = pMatAnm->scaleT;
    pTexMtx->m01 = 0;
    offsetS = 0x1000 - pMatAnm->scaleS;
    pTexMtx->m30 = (offsetS * (s32)pMatAnm->origWidth) << 3;
    offsetT = 0x1000 - pMatAnm->scaleT;
    pTexMtx->m31 = (offsetT * (s32)pMatAnm->origHeight) << 3;
    pTexMtx->m10 = 0;
}

/*
 * Identity texture matrix (scale one, rotation zero, translation zero).
 * Needs ../2.0/sp2: the image materialises the unit scale first
 * (`mov r2, #0x1000`, `str r2, [r0]`) and the zero after it; 1.1p1 schedules
 * the zero first. The same 36-byte body appears again at 0x02072524.
 */
void NNSi_G3dTexMtxIdentity2(TexMtx *pTexMtx)
{
    pTexMtx->m00 = 0x1000;
    pTexMtx->m01 = 0;
    pTexMtx->m10 = 0;
    pTexMtx->m11 = 0x1000;
    pTexMtx->m30 = 0;
    pTexMtx->m31 = 0;
}

/*
 * Build the texture matrix command for a material animation result: fill the
 * 4x4 block through the constructor the flag bits 0..2 select, scale the two
 * rows by the magnification factors magW and magH, and hand the record to
 * NNS_G3dGeBufferOP_N (the geometry engine command buffer). Bit 3 of the flag
 * selects MTX_LOAD_4x4 (set) or MTX_MULT_4x4.
 *
 * Each scale is skipped when it is already the unit 0x1000, so both are
 * guarded compares rather than multiplies by one. Three levers:
 *
 * L1  magW and magH are plain fields. The image re-reads the factor from the
 *     result before the second and third multiply of each block, so the
 *     source reads pMatAnm->magW for each multiply and binds only the guard's
 *     load to a local `mag`.
 * L2  The call's base is a pointer local: the image spends two instructions
 *     on the argument (`add r1, sp, #0` then `add r1, r1, #4`); `&cmd.mtxModeTexture`
 *     folds to a single `add r1, sp, #4`. `(s32 *)&cmd` bound first, then
 *     `base + 1`, reproduces the pair.
 * L3  The constants are ordered by their first store: mwcc emits the constant
 *     movs in order of the first store that uses each. `mtxModeTexture,
 *     mtxModePosVec, mtx.m32, mtx.m33` is the only order that gives the image's
 *     `mov r1,#0 / mov r3,#3 / mov r2,#2 / mov r0,#0x1000`.
 */
void NNSi_G3dSendTexMtx(NNSG3dMatAnmResult *pMatAnm)
{
    TexMtxCmd cmd;
    s32 zero;
    s32 three = 3;
    s32 two = 2;
    s32 unit = 0x1000;

    zero = 0;
    if (pMatAnm->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_LOAD) {
        cmd.cmds = 0x00101610;
    } else {
        cmd.cmds = 0x00101810;
    }
    cmd.mtxModeTexture = three;
    cmd.mtxModePosVec = two;
    cmd.mtx.m32 = zero;
    cmd.mtx.m33 = unit;
    cmd.mtx.m23 = zero;
    cmd.mtx.m22 = zero;
    cmd.mtx.m21 = zero;
    cmd.mtx.m20 = zero;
    cmd.mtx.m13 = zero;
    cmd.mtx.m12 = zero;
    cmd.mtx.m03 = zero;
    cmd.mtx.m02 = zero;

    gNNSiG3dTexMtxFuncTable[pMatAnm->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_FUNC_MASK](&cmd.mtx, pMatAnm);

    {
        s32 mag = pMatAnm->magW;
        if (mag != 0x1000) {
            cmd.mtx.m00 = (s32)(((s64)mag * cmd.mtx.m00) >> 12);
            cmd.mtx.m01 = (s32)(((s64)pMatAnm->magW * cmd.mtx.m01) >> 12);
            cmd.mtx.m30 = (s32)(((s64)pMatAnm->magW * cmd.mtx.m30) >> 12);
        }
    }
    {
        s32 mag = pMatAnm->magH;
        if (mag != 0x1000) {
            cmd.mtx.m10 = (s32)(((s64)mag * cmd.mtx.m10) >> 12);
            cmd.mtx.m11 = (s32)(((s64)pMatAnm->magH * cmd.mtx.m11) >> 12);
            cmd.mtx.m31 = (s32)(((s64)pMatAnm->magH * cmd.mtx.m31) >> 12);
        }
    }

    {
        s32 *base = (s32 *)&cmd;
        NNS_G3dGeBufferOP_N(cmd.cmds, base + 1, 0x12);
    }
}

/*
 * Scale, rotation and translation, second constructor set: the full s32 2x2
 * block from scaleS/scaleT x sinR/cosR and the transS/transT cross terms, all
 * carried at 64-bit width.
 *
 * Levers, in the order they were needed:
 *  L-A  rotOffsetS and rotOffsetT are `s64`, not `s32`: the image shows the
 *       full 64x64 shape (`umull` / `mla` / `mla`), which only appears when
 *       both operands are 64-bit.
 *  L-B  rotOffsetT has its additive term written second, so the `smull` goes
 *       to `transT * sinR` and the `smlal` to `transS * cosR`.
 *  L-C  The m31 value (transTTerm) is computed before the m30 value though
 *       m30 is stored first; the `- 0x1000` is deferred past the m30 multiply.
 *  L-D  The live range of scaleSSin is split by a temporary: `tmp` is
 *       computed before scaleTCos, then copied. Written in place, the two
 *       exchange r4 and r5 (16 concrete bytes).
 * Not a pin: ../2.0/sp2 is no better, the default 1.1p1 produces the bytes.
 */
void NNSi_G3dTexMtxScaleRotTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx;
    s32 cosR, sinR, scaleS, scaleT;
    s32 scaleTCos, scaleSSin;
    s64 rotOffsetS, rotOffsetT;
    s32 transSTerm, transTTerm, origWidth;
    s32 tmp;

    widthFx = (s32)pMatAnm->origWidth << 12;
    heightFx = (s32)pMatAnm->origHeight << 12;
    FX_DivAsync(heightFx, widthFx);

    cosR = (s32)pMatAnm->cosR;
    scaleS = pMatAnm->scaleS;
    sinR = (s32)pMatAnm->sinR;
    scaleT = pMatAnm->scaleT;

    pTexMtx->m00 = (s32)(((s64)scaleS * cosR) >> 12);
    tmp = (s32)(((s64)scaleS * sinR) >> 12);
    scaleTCos = (s32)(((s64)scaleT * cosR) >> 12);
    scaleSSin = tmp;
    pTexMtx->m11 = scaleTCos;
    pTexMtx->m01 = ((s32)(((s64)scaleT * sinR) >> 12) * (s32)FX_GetDivResult()) >> 12;

    FX_DivAsync(widthFx, heightFx);

    origWidth = (s32)pMatAnm->origWidth;
    rotOffsetT = (((s64)pMatAnm->transS * (s32)pMatAnm->cosR) + ((s64)pMatAnm->transT * (s32)pMatAnm->sinR)) >> 12;
    rotOffsetS = (((s64)pMatAnm->transS * (s32)pMatAnm->sinR) - ((s64)pMatAnm->transT * (s32)pMatAnm->cosR)) >> 12;

    transTTerm = scaleTCos + (s32)((rotOffsetS * pMatAnm->scaleT) >> 12);
    transSTerm = scaleSSin - (s32)((rotOffsetT * pMatAnm->scaleS) >> 12);
    transTTerm = transTTerm - 0x1000;
    pTexMtx->m30 = (origWidth * transSTerm) << 4;
    pTexMtx->m31 = ((0 - (s32)pMatAnm->origHeight) * transTTerm) << 4;

    pTexMtx->m10 = ((0 - scaleSSin) * (s32)FX_GetDivResult()) >> 12;
}

/*
 * Rotation and translation (scale one), second constructor set: the 2x2 block
 * is the s16 sinR/cosR pair, but the m30/m31 translation pair carries the
 * transS/transT cross terms, so each is a 64-bit smull/smlal pair reduced by
 * `>> 12` (which folds to `lsr #12` + `orr lsl #20`).
 *
 * The one lever: in `crossT` the additive term is written second
 * (`transS*cosR + transT*sinR`). mwcc gives the smull to the second operand
 * and the smlal to the first, so the other spelling reverses all four loads
 * (12 concrete bytes).
 */
void NNSi_G3dTexMtxRotTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx, divResult, crossT, crossS;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);

    FX_DivAsync(heightFx, widthFx);

    pTexMtx->m00 = pMatAnm->cosR;
    pTexMtx->m11 = pMatAnm->cosR;

    divResult = (s32)FX_GetDivResult();
    pTexMtx->m01 = (pMatAnm->sinR * divResult) >> 12;

    FX_DivAsync(widthFx, heightFx);

    crossT = (s32)((((s64)pMatAnm->transS * pMatAnm->cosR) + ((s64)pMatAnm->transT * pMatAnm->sinR)) >> 12);
    crossS = (s32)((((s64)pMatAnm->transS * pMatAnm->sinR) - ((s64)pMatAnm->transT * pMatAnm->cosR)) >> 12);

    pTexMtx->m30 = ((s32)pMatAnm->origWidth * (pMatAnm->sinR - crossT)) << 4;
    pTexMtx->m31 = ((0 - (s32)pMatAnm->origHeight) * (pMatAnm->cosR + crossS - 0x1000)) << 4;

    divResult = (s32)FX_GetDivResult();
    pTexMtx->m10 = ((0 - (s32)pMatAnm->sinR) * divResult) >> 12;
}

/*
 * Scale and translation (rotation zero), second constructor set, without the
 * divide calls: the 2x2 block is copied straight through and only the
 * m30/m31 translation pair is scaled.
 *
 * Two levers, both about where the high half of the smull is bound:
 *  - `hi` must be a named local computed before the m30 store. Folded into
 *    the m31 expression, the compiler CSEs the two `scaleT` reads and the
 *    function comes out 128 bytes against the image's 132 (the image reads
 *    scaleT three times).
 *  - The addend order is `scaleT + hi`, not `hi + scaleT`.
 */
void NNSi_G3dTexMtxScaleTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 scaledTransS, scaledScaleT, negTransT, hi;

    pTexMtx->m00 = pMatAnm->scaleS;
    pTexMtx->m11 = pMatAnm->scaleT;
    pTexMtx->m01 = 0;

    scaledTransS = 0 - (s32)(((s64)pMatAnm->transS * pMatAnm->scaleS) >> 12);
    negTransT = 0 - pMatAnm->transT;
    hi = (s32)(((s64)negTransT * pMatAnm->scaleT) >> 12);
    pTexMtx->m30 = ((s32)pMatAnm->origWidth * scaledTransS) << 4;
    scaledScaleT = pMatAnm->scaleT + hi - 0x1000;
    pTexMtx->m31 = ((0 - (s32)pMatAnm->origHeight) * scaledScaleT) << 4;

    pTexMtx->m10 = 0;
}

/*
 * Translation only (scale one, rotation zero), second constructor set. The
 * double negation of the m31 term only survives as two separate named
 * locals assigned before the m30 store (folded together the function comes
 * out 68 bytes, separated it is the right 84). Needs ../2.0/sp2: under
 * 1.1p1 the m00 and m01 stores merge into one `stm r0, {r2, lr}` (80 bytes);
 * the image writes `str r2, [r0]` and `str r2, [r0, #0x14]` first and
 * materialises the zero late (`mov lr, #0`).
 */
void NNSi_G3dTexMtxTrans_Max(TexMtx *pTexMtx, NNSG3dMatAnmResult *pMatAnm)
{
    s32 negTransS, negTransT, negOrigHeight;

    pTexMtx->m00 = 0x1000;
    pTexMtx->m11 = 0x1000;
    pTexMtx->m01 = 0;

    negTransS = 0 - pMatAnm->transS;
    negTransT = 0 - pMatAnm->transT;
    pTexMtx->m30 = ((s32)pMatAnm->origWidth * negTransS) << 4;
    negOrigHeight = 0 - (s32)pMatAnm->origHeight;
    pTexMtx->m31 = (negOrigHeight * negTransT) << 4;

    pTexMtx->m10 = 0;
}

/*
 * Operand of the (DST, SRC) matrix-constructor family at 0x02071EAC, kept with
 * the five constructors that live at the top of this file; see
 * docs/families/cluster_02071EAC.h.  origHeight is volatile because NNSi_G3dTexMtxScaleRot_Max
 * reads it twice and the image keeps both loads.
 */
struct SRC {
    u8  pad_00[0x18];
    s32 scaleS;
    s32 scaleT;
    s16 rotSin;
    s16 rotCos;
    s32 transS;
    s32 transT;
    u16 origWidth;
    volatile u16 origHeight;
};

struct DST {
    s32 _00;
    s32 _01;
    u8  pad_08[8];
    s32 _10;
    s32 _11;
    u8  pad_18[0x18];
    s32 _30;
    s32 _31;
};

typedef struct TexMtxObj {
    u32 flag;
    u8  pad04[0x18 - 4];
    s32 scaleS;
    s32 scaleT;
    s16 rotSin;
    s16 rotCos;
    s32 transS;
    s32 transT;
    u8  pad2c[0x30 - 0x2c];
    volatile s32 magW;
    volatile s32 magH;
} TexMtxObj;

typedef struct TexMtxRec {
    u32 hdr;
    s32 texMtxMode;
    s32 _00;
    s32 _01;
    s32 _02;
    s32 _03;
    s32 _10;
    s32 _11;
    s32 _12;
    s32 _13;
    s32 _20;
    s32 _21;
    s32 _22;
    s32 _23;
    s32 _30;
    s32 _31;
    s32 _32;
    s32 _33;
    s32 posMtxMode;
} TexMtxRec;

typedef void (*Fill)(s32 *out, TexMtxObj *o);

void NNSi_G3dTexMtxScaleRot_Max(struct DST *d, struct SRC *s);

void NNSi_G3dTexMtxRot_Max(struct DST *d, struct SRC *s);

void NNSi_G3dTexMtxScale_Max(struct DST *d, struct SRC *s);

void NNSi_G3dTexMtxIdentity_Max(struct DST *d);

void NNSi_G3dSendTexMtx_Max(TexMtxObj *o);

extern Fill data_020A8478[];

/*
 * The s32 2x2 member of the (DST_02072374, SRC) matrix-constructor family
 * (docs/families/cluster_02071EAC.h): scaleS/scaleT x rotSin/rotCos through four
 * `smull`s reduced by the family's `>> 12`, with both FX divisions and the
 * plain 32-bit _30/_31 pair.
 *
 * CLOSED AFTER THREE PREVIOUS PASSES.  docs/notes/pkt_02072374.c.txt records
 * this address at DIFF 17, then 7, then 8 across three lanes and some
 * thirty-odd measured spellings, and concludes that the residue -- a stable
 * r5/r6 exchange over seven instructions, all of them `smull` / `lsr` /
 * `orr` / `mul` / `rsb`, i.e. multiply-class instructions or direct consumers
 * of one -- "is chosen after linearisation and is not source-addressable".
 * It IS source-addressable, and the address is ONE STATEMENT REORDER.
 *
 * THE LEVER: THE `d->_00` STORE SITS AFTER BOTH `q` AND `r`, NOT BEFORE THEM.
 * The note's best source writes
 *     d->_00 = (s32)(((s64_02072374)e * a) >> 12);
 *     q = ...; r = ...; d->_11 = r;
 * which is the image's STORE order but not its VALUE order.  Moving the f00
 * store down, so the three narrowings are computed as a run and only then
 * stored,
 *     q = (s32)(((s64_02072374)e * b) >> 12);
 *     r = (s32)(((s64_02072374)c * a) >> 12);
 *     d->_00 = (s32)(((s64_02072374)e * a) >> 12);
 *     d->_11 = r;
 * takes it from 8 concrete bytes to 0.  The reason is the one the cluster
 * header's L8 names: a value's colour follows its first-definition order, and
 * an intervening store re-numbers everything after it.  With the store out of
 * the way, `c`'s product is numbered before `q`'s and the two take the
 * image's registers.  The note's own row "q hoisted above r with the f14
 * store last (7, the same as the filed shape)" was one step from this and
 * stopped at moving the f14 store rather than the f00 store.
 *
 * Found by tools/permuter.py in a single hill pass -- `reorder(+2)`, 269
 * compiles, 8 -> 0 -- after thirty-odd hand spellings had not reached it.
 *
 * The other three levers the note establishes are all still required and are
 * carried below unchanged:
 *   - the two `<< 12` shifted angle values are NAMED LOCALS live across the
 *     whole body (L4 of docs/families/cluster_02070B64.h), which is what
 *     forces the ten-register push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr};
 *   - `b` (rotSin) is bound BEFORE `c` (scaleT), matching the image's load order
 *     rotCos / scaleS / rotSin / scaleT at 0x0207239C..0x020723A8;
 *   - `s->origHeight` is `volatile`, so the second `ldrh` at 0x020723B0 survives.
 *
 * NO PIN.  With the reorder in place the DEFAULT dsi/1.1p1 produces the bytes
 * exactly as ../2.0/sp2 does (both 204 bytes, 0 mismatches), so the file takes
 * the project default.  This retires the note's standing question about which
 * front end is "the better of the two" here: at the correct source neither is
 * better, and the 8-vs-14 gap the note measured was an artefact of the
 * mis-ordered store, not a front-end tell.
 */
/*
 * The s32 2x2 member of the (DST, SRC) matrix-constructor family
 * (docs/families/cluster_02071EAC.h): scaleS/scaleT x rotSin/rotCos through four
 * `smull`s reduced by the family's `>> 12`, with both FX divisions and the
 * plain 32-bit _30/_31 pair.
 *
 * CLOSED AFTER THREE PREVIOUS PASSES.  docs/notes/pkt_02072374.c.txt records
 * this address at DIFF 17, then 7, then 8 across three lanes and some
 * thirty-odd measured spellings, and concludes that the residue -- a stable
 * r5/r6 exchange over seven instructions, all of them `smull` / `lsr` /
 * `orr` / `mul` / `rsb`, i.e. multiply-class instructions or direct consumers
 * of one -- "is chosen after linearisation and is not source-addressable".
 * It IS source-addressable, and the address is ONE STATEMENT REORDER.
 *
 * THE LEVER: THE `d->_00` STORE SITS AFTER BOTH `q` AND `r`, NOT BEFORE THEM.
 * The note's best source writes
 *     d->_00 = (s32)(((s64)e * a) >> 12);
 *     q = ...; r = ...; d->_11 = r;
 * which is the image's STORE order but not its VALUE order.  Moving the f00
 * store down, so the three narrowings are computed as a run and only then
 * stored,
 *     q = (s32)(((s64)e * b) >> 12);
 *     r = (s32)(((s64)c * a) >> 12);
 *     d->_00 = (s32)(((s64)e * a) >> 12);
 *     d->_11 = r;
 * takes it from 8 concrete bytes to 0.  The reason is the one the cluster
 * header's L8 names: a value's colour follows its first-definition order, and
 * an intervening store re-numbers everything after it.  With the store out of
 * the way, `c`'s product is numbered before `q`'s and the two take the
 * image's registers.  The note's own row "q hoisted above r with the f14
 * store last (7, the same as the filed shape)" was one step from this and
 * stopped at moving the f14 store rather than the f00 store.
 *
 * Found by tools/permuter.py in a single hill pass -- `reorder(+2)`, 269
 * compiles, 8 -> 0 -- after thirty-odd hand spellings had not reached it.
 *
 * The other three levers the note establishes are all still required and are
 * carried below unchanged:
 *   - the two `<< 12` shifted angle values are NAMED LOCALS live across the
 *     whole body (L4 of docs/families/cluster_02070B64.h), which is what
 *     forces the ten-register push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr};
 *   - `b` (rotSin) is bound BEFORE `c` (scaleT), matching the image's load order
 *     rotCos / scaleS / rotSin / scaleT at 0x0207239C..0x020723A8;
 *   - `s->origHeight` is `volatile`, so the second `ldrh` at 0x020723B0 survives.
 *
 * NO PIN.  With the reorder in place the DEFAULT dsi/1.1p1 produces the bytes
 * exactly as ../2.0/sp2 does (both 204 bytes, 0 mismatches), so the file takes
 * the project default.  This retires the note's standing question about which
 * front end is "the better of the two" here: at the correct source neither is
 * better, and the 8-vs-14 gap the note measured was an artefact of the
 * mis-ordered store, not a front-end tell.
 */
void NNSi_G3dTexMtxScaleRot_Max(struct DST *d, struct SRC *s)
{
    s32 e, a, c, b;
    s32 q, r;
    s32 f12, e12;

    f12 = (s32)s->origWidth << 12;
    e12 = (s32)s->origHeight << 12;
    FX_DivAsync(e12, f12);

    e = s->scaleS;
    a = (s32)s->rotCos;
    b = (s32)s->rotSin;
    c = s->scaleT;

    q = (s32)(((s64)e * b) >> 12);
    r = (s32)(((s64)c * a) >> 12);
    d->_00 = (s32)(((s64)e * a) >> 12);
    d->_11 = r;
    d->_01 = ((s32)(((s64)c * b) >> 12) * FX_GetDivResult()) >> 12;

    FX_DivAsync(f12, e12);

    d->_30 = ((s32)s->origWidth * q) << 4;
    d->_31 = ((0 - (s32)s->origHeight) * (r - 0x1000)) << 4;
    d->_10 = ((0 - q) * FX_GetDivResult()) >> 12;
}

/*
 * Two functions of the 0x02071CDC constructor family, 228 bytes: the
 * all-s16_02072374 variant at 0x02072440 (164 B, no smull anywhere - every term is
 * a plain `ldrsh` times an `ldrh`) and the UNLABELLED leaf at 0x020724E4
 * (64 B), which saves no lr and so never gets a func_ label. Folding the
 * follower in here is what turns the lead function's EXACT* into EXACT.
 *
 * The third leaf of the file, the pure-identity writer at 0x02072524
 * (36 B, byte-identical to the one at 0x02071EFC), is NOT in this unit:
 * 1.1p1 -O4,p hoists `mov r1, #0` ahead of `mov r2, #0x1000` where the
 * image materialises 0x1000 first. Nine store-order and constant-binding
 * spellings all give the same 3-instruction swap; see
 * docs/notes/NNSi_G3dTexMtxIdentity2.c.txt.
 */
/*
 * Two functions of the 0x02071CDC constructor family, 228 bytes: the
 * all-s16 variant at 0x02072440 (164 B, no smull anywhere - every term is
 * a plain `ldrsh` times an `ldrh`) and the UNLABELLED leaf at 0x020724E4
 * (64 B), which saves no lr and so never gets a func_ label. Folding the
 * follower in here is what turns the lead function's EXACT* into EXACT.
 *
 * The third leaf of the file, the pure-identity writer at 0x02072524
 * (36 B, byte-identical to the one at 0x02071EFC), is NOT in this unit:
 * 1.1p1 -O4,p hoists `mov r1, #0` ahead of `mov r2, #0x1000` where the
 * image materialises 0x1000 first. Nine store-order and constant-binding
 * spellings all give the same 3-instruction swap; see
 * docs/notes/NNSi_G3dTexMtxIdentity2.c.txt.
 */
void NNSi_G3dTexMtxRot_Max(struct DST *d, struct SRC *s)
{
    s32 e12, f12, t;

    e12 = (s32)((u32)s->origWidth << 12);
    f12 = (s32)((u32)s->origHeight << 12);

    FX_DivAsync(f12, e12);

    d->_00 = s->rotCos;
    d->_11 = s->rotCos;

    t = FX_GetDivResult();
    d->_01 = (s->rotSin * t) >> 12;

    FX_DivAsync(e12, f12);

    d->_30 = ((s32)s->origWidth * s->rotSin) << 4;
    d->_31 = ((0 - (s32)s->origHeight) * (s->rotCos - 0x1000)) << 4;

    t = FX_GetDivResult();
    d->_10 = ((0 - (s32)s->rotSin) * t) >> 12;
}

void NNSi_G3dTexMtxScale_Max(struct DST *d, struct SRC *s)
{
    d->_00 = s->scaleS;
    d->_11 = s->scaleT;
    d->_01 = 0;
    d->_30 = 0;
    d->_31 = ((0 - (s32)s->origHeight) * (s->scaleT - 0x1000)) << 4;
    d->_10 = 0;
}

/*
 * The identity member of the 0x02071CDC constructor family, an unlabelled
 * leaf (saves no lr). The same 36-byte body appears twice in this file, at
 * 0x02072524 and 0x02072524.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md),
 * the same measurement already taken for src/matched/NNSi_G3dTexMtxIdentity.c: the
 * image materialises the unit scale FIRST, `mov r2, #0x1000`
 * (`01 2a a0 e3`) at 0x02072524 followed by `str r2, [r0]`, and only then
 * `mov r1, #0` (`00 10 a0 e3`) at 0x0207252C. dsi/1.1p1 -O4,p schedules the
 * zero first for the same 36 bytes, 9 concrete bytes out, under all ten
 * spellings measured in docs/notes/NNSi_G3dTexMtxIdentity_Max.c.txt (store order,
 * constants bound to locals, zero derived from the live 0x1000, re-read of
 * a stored field). Under the pin the same C is 36 bytes, 0 mismatches.
 */
void NNSi_G3dTexMtxIdentity_Max(struct DST *d)
{
    d->_00 = 0x1000;
    d->_01 = 0;
    d->_10 = 0;
    d->_11 = 0x1000;
    d->_30 = 0;
    d->_31 = 0;
}

/*
 * One of the two CALLERS of the 0x02071CDC constructor family
 * (docs/notes/pkt_02071DD4.c.txt).  It builds a 0x4c-byte command record
 * on the stack, fills the record's 2x3 matrix block by dispatching on the
 * low three bits of the object's flag word through a pointer table, then
 * applies the object's magW/magH scales to the two rows -- each through the
 * family's `>> 12` on an s64_02072524 product, which folds to `lsr #0xc` +
 * `orr ..., lsl #20` -- and hands the record to NNS_G3dGeBufferOP_N.
 *
 * Each scale is skipped outright when it is already the unit 0x1000, so
 * both are guarded compares against 0x1000 rather than multiplies by one.
 *
 * Three levers, all measured, and all needed:
 *
 * L1  magW/magH ARE `volatile`.  The image RE-READS the scale from the
 *     object before the second and third multiply of each block
 *     (`ldr r2,[r4,#0x30]` at 0x02071FC4, `ldr r1,[r4,#0x30]` at
 *     0x02071FDC); 1.1p1 otherwise forwards the register it still holds
 *     live and batches all three smulls, which is 8 bytes short.  But
 *     plain `volatile` also re-reads for the GUARD compare and comes out
 *     4 bytes LONG, so the guard's own load is bound to a local `s` and
 *     the FIRST multiply uses that local while the other two re-read.
 * L2  THE CALL'S BASE IS A POINTER LOCAL.  The image spends two
 *     instructions on the argument, `add r1, sp, #0` then
 *     `add r1, r1, #4` (0x02072040/0x02072048); `&r.texMtxMode` folds to a
 *     single `add r1, sp, #4` and loses 4 bytes.  `(s32 *)&r` bound
 *     first, then `base + 1`, reproduces the pair.
 * L3  THE FOUR HEADER CONSTANTS ARE ORDERED BY THE STORES, NOT THE
 *     DECLARATIONS.  mwcc emits the constant movs in order of the first
 *     store that uses each, and sinks any constant whose store sits
 *     after the zero run.  `f04, f48, f40, f44` is the only one of the
 *     orderings measured that gives the image's `mov r1,#0 / mov r3,#3 /
 *     mov r2,#2 / mov r0,#0x1000`; f44-first is 27 bytes out and
 *     f48-first 8, differing by a pure rotation of the three non-zero
 *     constants.  Declaration order and binding the constants to locals
 *     at all are both insensitive.
 *
 * Derived from src/matched/NNSi_G3dSendTexMtx.c, its sibling and the other caller of
 * the 0x02071CDC constructor family (docs/notes/pkt_02071DD4.c.txt, "NOT
 * ATTEMPTED").  Same 0x4c-byte stack record, same two header constants
 * (0x00101610 / 0x00101810), same 2x3 fill dispatched through the low three
 * flag bits -- through data_020A8478 here rather than gNNSiG3dTexMtxFuncTable -- and the
 * same two f30/f34 scale blocks.  L1, L2 and L3 above all transferred
 * unchanged, including the `volatile` f30/f34 with the guard's own load bound
 * to `s`, and were not re-derived.
 *
 * What this one adds over NNSi_G3dSendTexMtx: three flag-guarded writes back into
 * the OBJECT, ahead of the dispatch -- bit 0 sets f1c and f18 to the unit
 * scale, bit 1 sets h22 to 0x1000 and h20 to 0, bit 2 clears f28 and f24.  The
 * store order inside each pair is high field first, and each guard re-reads
 * o->flag (`ldr r0,[r4]` at 0x020725AC, 0x020725BC, 0x020725D8, 0x020725EC).
 * h20/h22 are s16_02072524: the pair is `strh`.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md), and exactly
 * the one docs/notes/pkt_02071DD4.c.txt flagged at this address in advance.
 * The image keeps `tst r0, #2` at 0x020725C0 (`02 00 10 e3`) and `beq 0x020725D8`
 * at 0x020725C4 (`03 00 00 0a`) over the FOUR-instruction bit-1 guard body at
 * 0x020725C8..0x020725D4 (`mov r0,#0x1000` / `strh r0,[r4,#0x22]` /
 * `mov r0,#0` / `strh r0,[r4,#0x20]`).  1.1p1 -O4,p predicates it to
 * `movne/strhne/movne/strhne` -- and, having done so, reverses the pair to
 * h20-then-h22 -- giving 388 bytes against the original's 392, 226 concrete
 * bytes out and the whole body shifted by four.  The bit-0 and bit-2 guards,
 * being two instructions each, are predicated under BOTH front ends and are
 * not evidence either way.  Under the pin the same C is 392 bytes,
 * 0 mismatches.
 */
void NNSi_G3dSendTexMtx_Max(TexMtxObj *o)
{
    TexMtxRec r;
    s32 zero;
    s32 three = 3;
    s32 two = 2;
    s32 unit = 0x1000;

    zero = 0;
    if (o->flag & 8) {
        r.hdr = 0x00101610;
    } else {
        r.hdr = 0x00101810;
    }
    r.texMtxMode = three;
    r.posMtxMode = two;
    r._32 = zero;
    r._33 = unit;
    r._23 = zero;
    r._22 = zero;
    r._21 = zero;
    r._20 = zero;
    r._13 = zero;
    r._12 = zero;
    r._03 = zero;
    r._02 = zero;

    if (o->flag & 1) {
        o->scaleT = unit;
        o->scaleS = unit;
    }
    if (o->flag & 2) {
        o->rotCos = 0x1000;
        o->rotSin = 0;
    }
    if (o->flag & 4) {
        o->transT = 0;
        o->transS = 0;
    }

    data_020A8478[o->flag & 7](&r._00, o);

    {
        s32 s = o->magW;
        if (s != 0x1000) {
            r._00 = (s32)(((s64)s * r._00) >> 12);
            r._01 = (s32)(((s64)o->magW * r._01) >> 12);
            r._30 = (s32)(((s64)o->magW * r._30) >> 12);
        }
    }
    {
        s32 s = o->magH;
        if (s != 0x1000) {
            r._10 = (s32)(((s64)s * r._10) >> 12);
            r._11 = (s32)(((s64)o->magH * r._11) >> 12);
            r._31 = (s32)(((s64)o->magH * r._31) >> 12);
        }
    }

    {
        s32 *matrixWords = (s32 *)&r;
        NNS_G3dGeBufferOP_N(r.hdr, matrixWords + 1, 0x12);
    }
}
