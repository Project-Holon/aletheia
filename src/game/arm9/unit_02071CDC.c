/*
 * file:     unit_02071CDC.c
 * unit:     yes
 * function: NNSi_G3dTexMtxScaleRot, NNSi_G3dTexMtxRot, NNSi_G3dTexMtxScale
 * address:  0x02071CDC
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
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;
typedef long long      s64;

/* NNSG3dMatAnmResult: the texture SRT part (0x38 bytes in all). */
typedef struct {
    u8  unused00[0x18];
    s32 scaleS;
    s32 scaleT;
    s16 sinR;
    s16 cosR;
    s32 transS;
    s32 transT;
    u16 origWidth;
    u16 origHeight;
} MatAnmResult;

/* Texture matrix: the six cells these constructors write (MtxFx44 layout). */
typedef struct {
    s32 m00;
    s32 m01;
    u8  unused08[8];
    s32 m10;
    s32 m11;
    u8  unused18[0x18];
    s32 m30;
    s32 m31;
} TexMtx;

extern void func_0207C930(u32 numer, u32 denom);
extern u32 func_0207C86C(void);
void NNSi_G3dTexMtxScaleRot(TexMtx *pTexMtx, MatAnmResult *pMatAnm);
void NNSi_G3dTexMtxRot(TexMtx *pTexMtx, MatAnmResult *pMatAnm);
void NNSi_G3dTexMtxScale(TexMtx *pTexMtx, MatAnmResult *pMatAnm);

/*
 * The smull/FX constructor for 0x02071B2C's family. Every quartet is
 * `((s64)field * field) >> 12`: the sign comes from the FIELD TYPE (scaleS/scaleT
 * are the `ldr` s32 pair, sinR/cosR the `ldrsh` s16 pair), never from a cast -
 * spell either as u32 and `umull` comes out. The `>> 12` folds to
 * `lsr #0xc` + `orr ..., lsl #20` because only the low word is live.
 *
 * The 0x30/0x34 pair is ONE chained term per statement: the smull/smlal
 * split names the operand order, so the additive term is written SECOND
 * (`scaleTSin * negWidth11 + scaleTCos * negHeight11`): mwcc gives the smull to the second operand and
 * the smlal to the first, and swapping them swaps the two instructions.
 * The two negations are the two-statement form (`n = 0 - x`) - folding them
 * into the multiply re-associates and loses both `rsb`s.
 */
/* Texture matrix from scale and rotation (no translation). */
void NNSi_G3dTexMtxScaleRot(TexMtx *pTexMtx, MatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx;
    s32 scaleSCos, scaleSSin, scaleTCos, scaleTSin, divResult;
    s32 negWidth, negHeight;
    s64 acc;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);
    func_0207C930(heightFx, widthFx);
    scaleSCos = (s32)(((s64)pMatAnm->scaleS * pMatAnm->cosR) >> 12);
    scaleSSin = (s32)(((s64)pMatAnm->scaleS * pMatAnm->sinR) >> 12);
    scaleTCos = (s32)(((s64)pMatAnm->scaleT * pMatAnm->cosR) >> 12);
    scaleTSin = (s32)(((s64)pMatAnm->scaleT * pMatAnm->sinR) >> 12);
    pTexMtx->m00 = scaleSCos;
    pTexMtx->m11 = scaleTCos;
    divResult = func_0207C86C();
    pTexMtx->m01 = (scaleTSin * divResult) >> 12;
    func_0207C930(widthFx, heightFx);
    negWidth = 0 - (s32)pMatAnm->origWidth;
    negHeight = 0 - (s32)pMatAnm->origHeight;
    acc = (s64)scaleSCos * (negWidth << 11) - (s64)scaleSSin * (negHeight << 11);
    pTexMtx->m30 = (s32)(acc >> 8) + ((s32)pMatAnm->origWidth << 15);
    acc = (s64)scaleTSin * (negWidth << 11) + (s64)scaleTCos * (negHeight << 11);
    pTexMtx->m31 = (s32)(acc >> 8) + ((s32)pMatAnm->origHeight << 15);
    divResult = func_0207C86C();
    pTexMtx->m10 = ((0 - scaleSSin) * divResult) >> 12;
}

/*
 * Two functions of the 0x02071CDC constructor family, 296 bytes:
 * 0x02071DD4 (the s16-only variant, 216 B) and the UNLABELLED leaf at
 * 0x02071EAC (80 B), which saves no lr and so never gets a func_ label -
 * folding it in here is what turns the lead function's EXACT* into EXACT.
 *
 * ONE operand-order tell decides the lead function's m30/m31 pair. In m30
 * the `<<15` term is written LAST (`(m >> 8) + (origWidth << 15)`); in m31 it is
 * written FIRST (`(origHeight << 15) + (m >> 8)`). Spelled the other way round the
 * instruction sequence is identical but the allocator names r3/r4/r2 for
 * the three loads where the image names r2/r3/ip: 9 concrete bytes out,
 * unreachable by any local-binding or statement-splitting spelling (six
 * measured).
 *
 * The third leaf of the file, at 0x02071EFC (36 B, the pure-identity
 * version), is NOT in this unit: 1.1p1 -O4,p hoists `mov r1, #0` ahead of
 * `mov r2, #0x1000` where the image materialises 0x1000 first, a stable
 * 3-instruction scheduling swap that survived eight store-order and
 * constant-binding spellings. See docs/notes/func_02071EFC.c.txt.
 */
/* Texture matrix from rotation only (scale one, no translation). */
void NNSi_G3dTexMtxRot(TexMtx *pTexMtx, MatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx;
    s32 divResult;
    s32 negWidth, negHeight;
    s64 acc;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);
    func_0207C930(heightFx, widthFx);
    pTexMtx->m00 = pMatAnm->cosR;
    pTexMtx->m11 = pMatAnm->cosR;
    divResult = func_0207C86C();
    pTexMtx->m01 = (pMatAnm->sinR * divResult) >> 12;
    func_0207C930(widthFx, heightFx);
    negWidth = 0 - (s32)pMatAnm->origWidth;
    negHeight = 0 - (s32)pMatAnm->origHeight;
    acc = (s64)pMatAnm->cosR * (negWidth << 11) - (s64)pMatAnm->sinR * (negHeight << 11);
    pTexMtx->m30 = (s32)(acc >> 8) + ((s32)pMatAnm->origWidth << 15);
    acc = (s64)pMatAnm->sinR * (negWidth << 11) + (s64)pMatAnm->cosR * (negHeight << 11);
    pTexMtx->m31 = ((s32)pMatAnm->origHeight << 15) + (s32)(acc >> 8);
    divResult = func_0207C86C();
    pTexMtx->m10 = ((0 - (s32)pMatAnm->sinR) * divResult) >> 12;
}

/* Texture matrix from scale only (no rotation, no translation). */
void NNSi_G3dTexMtxScale(TexMtx *pTexMtx, MatAnmResult *pMatAnm)
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
