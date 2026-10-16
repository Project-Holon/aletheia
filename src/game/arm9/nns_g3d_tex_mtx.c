/*
 * file:     nns_g3d_tex_mtx.c
 * unit:     yes
 * function: NNSi_G3dTexMtxScaleRotTrans, NNSi_G3dTexMtxRotTrans, NNSi_G3dTexMtxScaleTrans2, NNSi_G3dTexMtxTrans2, NNSi_G3dTexMtxScaleRot, NNSi_G3dTexMtxRot, NNSi_G3dTexMtxScale, NNSi_G3dTexMtxIdentity2, NNSi_G3dSendTexMtx, NNSi_G3dTexMtxScaleRotTrans_Max, NNSi_G3dTexMtxRotTrans_Max, NNSi_G3dTexMtxScaleTrans_Max, NNSi_G3dTexMtxTrans_Max
 * address:  0x02071A24
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g3d texture matrix constructors. A material animation result
 * (NNSG3dMatAnmResult) carries scale, rotation (sin, cos) and translation of
 * the texture coordinates; the result flag bits 0..2 (scale is one, rotation
 * is zero, translation is zero) select which of eight constructors fills the
 * 4x4 texture matrix. This file holds two sets of them: the centred set
 * (NNSi_G3dTexMtx*, which rotates around the texture centre using the
 * original width and height) and the second set (NNSi_G3dTexMtxScaleTrans2 ...), which
 * folds the translation into the matrix differently. NNSi_G3dSendTexMtx picks a
 * constructor by flag, applies the magnification factors and sends the
 * matrix to the geometry engine buffer.
 *
 * Compiler notes:
 *  - NNSi_G3dTexMtxIdentity2, NNSi_G3dTexMtxTrans2 and NNSi_G3dTexMtxTrans_Max need ../2.0/sp2: the
 *    image materialises the 0x1000 unit scale first (or the zero late), so
 *    the two stores to m00 and m01 stay separate; 1.1p1 merges them into one
 *    `stm` and comes out 4 bytes shorter. NNSi_G3dTexMtxScaleTrans2 differs from 1.1p1
 *    by one swapped pair of loads. For NNSi_G3dTexMtxTrans_Max the double negation of
 *    the m31 term only survives as two separate named locals assigned before
 *    the m30 store.
 *  - The smull quartets are `((s64)field * field) >> 12`: the sign comes
 *    from the field type (scaleS/scaleT are s32, sinR/cosR are s16), never
 *    from a cast. The `>> 12` folds to `lsr #12` + `orr lsl #20` because
 *    only the low word is live.
 *  - In the m30/m31 pair the `<< 15` term is written last for m30 and first
 *    for m31; the other way round swaps three register names.
 *
 * symbols:
 *   FX_DivAsync  0x0207C930  arm
 *   FX_GetDivResult  0x0207C86C  arm
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   gNNSiG3dTexMtxFuncTable  0x020A8458  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef short          s16;

typedef unsigned int   u32;

typedef int            s32;

typedef long long      s64;

/* NNSG3dMatAnmResult flag bits that select the texture matrix constructor. */
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE  0x01
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO   0x02
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO 0x04
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_LOAD      0x08
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_FUNC_MASK 0x07

/* Result of the material animation (0x38 bytes). */
typedef struct {
    u32 flag;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmTexImageParam;
    u32 prmTexPlttBase;
    s32 scaleS;
    s32 scaleT;
    s16 sinR;
    s16 cosR;
    s32 transS;
    s32 transT;
    u16 origWidth;
    u16 origHeight;
    s32 magW;
    s32 magH;
} NNSG3dMatAnmResult;

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

extern void FX_DivAsync(u32 numer, u32 denom);
extern u32 FX_GetDivResult(void);
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
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
