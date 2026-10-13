/*
 * file:     unit_02071A24.c
 * unit:     yes
 * function: func_02071A24, func_02071B2C
 * address:  0x02071A24
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

/* NNS texture matrix constructor, translation + scale + rotation. */
/*
 * The full-rotate constructor with the smull quartet: the body of
 * src/matched/func_02071CDC.c with its two plain negated multipliers
 * replaced by the translation-weighted pair func_02071C14 uses,
 *   a = (-origWidth << 11) - transS * origWidth
 *   b = transT * origHeight + (-origHeight << 11)
 * and m30 = (p*a - q*b) >> 8 + origWidth << 15, m31 = (bd*a + r*b) >> 8 +
 * origHeight << 15.
 *
 * The only residue of the first compile (11 bytes, both front ends) was
 * the cluster rule in docs/families/cluster_02071360.h: in the m31 term
 * the `<< 15` bias is written FIRST, in the m30 term LAST.  With that one
 * change it is 264 bytes, 0 out.
 *
 * Front end: NOT pinned.  EXACT under both dsi/1.1p1 and ../2.0/sp2 with
 * the same C; filed under the project default like func_02071CDC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02071A24.c \
 *       --func func_02071A24 --addr 0x02071A24 --arm
 */
void func_02071A24(TexMtx *pTexMtx, MatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx;
    s32 scaleSCos, scaleSSin, scaleTCos, scaleTSin, divResult;
    s32 offsetS, offsetT;
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
    offsetS = ((0 - (s32)pMatAnm->origWidth) << 11) - pMatAnm->transS * pMatAnm->origWidth;
    offsetT = pMatAnm->transT * pMatAnm->origHeight + ((0 - (s32)pMatAnm->origHeight) << 11);
    acc = (s64)scaleSCos * offsetS - (s64)scaleSSin * offsetT;
    pTexMtx->m30 = (s32)(acc >> 8) + ((s32)pMatAnm->origWidth << 15);
    acc = (s64)scaleTSin * offsetS + (s64)scaleTCos * offsetT;
    pTexMtx->m31 = ((s32)pMatAnm->origHeight << 15) + (s32)(acc >> 8);
    divResult = func_0207C86C();
    pTexMtx->m10 = ((0 - scaleSSin) * divResult) >> 12;
}

/*
 * The rotate-and-scale constructor of the 0x02071CDC family, 232 bytes.
 * Brackets the body with the two func_0207C930 mode calls (arguments swapped
 * between them), writes the s16 cosR into m00 and m11, derives m01/m10 from
 * sinR and func_0207C86C's return, and builds the m30/m31 pair out of the
 * transS/transT vectors biased by the origWidth/origHeight halfwords.
 *
 * FOUR SPELLING TELLS, each measured (bytes out on the whole function):
 *   33 -> 18  bind the two halfwords to named locals `e`/`f` and read origWidth
 *             FIRST: unbound, the compiler emits the origHeight ldrh ahead of the
 *             origWidth one at +0x58 and reshuffles everything downstream.
 *   18 -> 11  write m31's `<< 15` term FIRST and the shifted product second
 *             (`(origHeight << 15) + (m >> 8)`), the operand-order tell already
 *             recorded for this family in src/matched/unit_02071DD4.c; m30
 *             keeps the opposite order, `(m >> 8) + (origWidth << 15)`.
 *   11 ->  9  bind cosR/sinR to `a`/`bb` before the m31 chain.
 *    9 ->  0  the m31 chain is `bb * (s64)p + a * (s64)q`: BOTH the term
 *             order and each factor's operand order matter. The permuter
 *             (hill, 794 compiles) found it as three commute mutations from
 *             `(s64)q * a + (s64)p * bb`; every hand spelling in between sat
 *             at 9 bytes with the two `ldrsh` at +0xA8/+0xAC swapped.
 *
 * Not pinned: 1.1p1 reproduces it exactly, unlike its neighbours 0x02071360
 * and 0x02071C14.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02071B2C.c \
 *       --func func_02071B2C --addr 0x02071B2C --arm --cc 1.1p1
 */
void func_02071B2C(TexMtx *pTexMtx, MatAnmResult *pMatAnm)
{
    s32 widthFx, heightFx, divResult;
    s32 offsetS, offsetT, width, height, cosRot, sinRot;
    s64 acc;

    widthFx = (s32)((u32)pMatAnm->origWidth << 12);
    heightFx = (s32)((u32)pMatAnm->origHeight << 12);
    func_0207C930(heightFx, widthFx);
    pTexMtx->m00 = pMatAnm->cosR;
    pTexMtx->m11 = pMatAnm->cosR;
    divResult = func_0207C86C();
    pTexMtx->m01 = (pMatAnm->sinR * divResult) >> 12;
    func_0207C930(widthFx, heightFx);
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
    divResult = func_0207C86C();
    pTexMtx->m10 = ((0 - (s32)pMatAnm->sinR) * divResult) >> 12;
}
