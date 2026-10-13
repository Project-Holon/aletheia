/*
 * file:     nns_g3d_anm.c
 * unit:     yes
 * function: NNSi_G3dAnmBlendMat, NNSi_G3dAnmBlendJntVec, NNSi_G3dAnmBlendJnt, NNSi_G3dAnmBlendVis
 * address:  0x0206AF08
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   MIi_CpuCopy32     0x02082A90  arm
 *   FX_Div      0x0207C768  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_Normalize     0x0207CCA4  arm
 */
#include "nns_g3d_anm_types.h"

extern void MIi_CpuClearFast(u32 val, void *dst, u32 len);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 len);
extern s32  FX_Div(s32 num, s32 den);
extern void VEC_CrossProduct(const s32 *a, const s32 *b, s32 *c);
extern void VEC_Normalize(const s32 *a, s32 *b);
int NNSi_G3dAnmBlendMat(void *pResult, const NNSG3dAnmObj *pAnmObj, u32 matIdx);
void NNSi_G3dAnmBlendJntVec(volatile s32 *dst, const s32 *src, s32 weight, int isOne);
int NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 jntIdx);
int NNSi_G3dAnmBlendVis(u32 *pResult, const NNSG3dAnmObj *pAnmObj, u32 nodeIdx);


/*
 * Material animation blend: calls the sampling function of every animation in
 * the chain that maps this material and returns 1 when at least one did.
 */
int NNSi_G3dAnmBlendMat(void *pResult, const NNSG3dAnmObj *pAnmObj, u32 matIdx)
{
    int hasResult = 0;

    while (pAnmObj != 0) {
        if (matIdx < pAnmObj->numMapData) {
            u16 mapData = pAnmObj->mapData[matIdx];

            if ((mapData & NNS_G3D_ANMOBJ_MAPDATA_MASK) == NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                NNSG3dAnmObjFunc funcAnm = pAnmObj->funcAnm;

                if (funcAnm != 0) {
                    funcAnm(pResult, pAnmObj, mapData & NNS_G3D_ANMOBJ_MAPDATA_ID);
                    hasResult = 1;
                }
            }
        }
        pAnmObj = pAnmObj->next;
    }
    return hasResult;
}


/*
 * Mixes a weighted three-word vector into dst: with `isOne` set the source is
 * the implicit (1, 1, 1) and it just adds the weight to each word, otherwise
 * it accumulates the 12.12 fixed-point product (weight * src[i]) >> 12.
 *
 * `dst` must be spelled `volatile`: with a plain `s32 *` mwcc schedules the
 * two arms differently.  The plain-pointer spelling matches the `else` arm
 * exactly (ldr src, ldr dst, mul, add, str) but groups the `if` arm into
 * three hoisted loads, three adds and three stores; the volatile spelling
 * reproduces the original's strictly sequential ldr/add/str per word.
 */
void NNSi_G3dAnmBlendJntVec(volatile s32 *dst, const s32 *src, s32 weight, int isOne)
{
    if (isOne) {
        dst[0] += weight;
        dst[1] += weight;
        dst[2] += weight;
    } else {
        dst[0] += (weight * src[0]) >> 12;
        dst[1] += (weight * src[1]) >> 12;
        dst[2] += (weight * src[2]) >> 12;
    }
}


/*
 * Joint animation blend: the weighted blend of the animation chain that
 * NNSi_G3dAnmBlendMat walks.  Each animation contributes a 0x58-byte joint
 * result weighted by its ratio, clamped to 0x1000 (1.0 in 20.12) and
 * normalised against the running total through the hardware divider FX_Div.
 * Three shortcuts come first: a single-animation chain dispatches straight
 * through its sampling function; a zero total returns 0; and exactly one live
 * contributor dispatches that one animation.  The tail re-orthonormalises the
 * accumulated rotation with VEC_CrossProduct / VEC_Normalize, falling back to
 * the FIRST contributor's own axes (saved into the `firstRow0`/`firstRow2`
 * stack copies on the first pass) when an axis accumulated to zero.  The
 * translation is the only vector whose product is taken 64-bit (`smull` +
 * `lsr #12` + `orr lsl #20` in the image), which is what fixes the
 * `(long long)` cast there against the plain `mul`/`asr #12` of the rotation
 * arms.
 *
 * 2.0/sp2 pin, the docs/FRONTEND-PINS.md "repeated small constant takes a
 * callee-saved register" tell exactly: under dsi/1.1p1 this same source is
 * 1008 bytes, with 0x58 and 0xc hoisted into r4 and rematerialised as
 * `sub r0, r4, #0x59` / `mov r2, r4`; 2.0/sp2 rematerialises each literal at
 * its use and is byte-exact.
 *
 * Four spellings measured against the listing:
 *   - the single-animation fast path must be NESTED ifs with a `return 0` per
 *     arm, not a chain of early-return guards: the guard chain predicates
 *     the epilogue (`addhs sp / movhs r0 / pophs`) where the original
 *     branches to three separate `mov r0,#0` epilogues.
 *   - `numLive` is declared AFTER `cur`, which is what puts the chain cursor
 *     in r2 and the counter in r3 rather than the other way round
 *     (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *   - `firstRow0` is declared before `firstRow2`, giving the later declaration
 *     the lower stack address (sp+0 for `firstRow2`, sp+0xc for `firstRow0`).
 *   - the ROT_ZERO arm adds the weight to rot[0][0] and rot[1][1], the
 *     image's +0x28 and +0x38 stores.
 */
int NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 jntIdx)
{
    NNSG3dJntAnmResult sample;
    s32 firstRow0[3];
    s32 firstRow2[3];
    s32 totalRatio;
    int numSampled;
    const NNSG3dAnmObj *last;
    const NNSG3dAnmObj *cur;
    int numLive;
    s32 weight;
    u16 mapData;

    if (pAnmObj == 0) {
        return 0;
    }
    if (pAnmObj->next == 0) {
        if (jntIdx < pAnmObj->numMapData) {
            mapData = pAnmObj->mapData[jntIdx];
            if ((mapData & NNS_G3D_ANMOBJ_MAPDATA_MASK) == NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                if (pAnmObj->funcAnm == 0) {
                    return 0;
                }
                pAnmObj->funcAnm(pResult, pAnmObj, mapData & NNS_G3D_ANMOBJ_MAPDATA_ID);
                return 1;
            }
            return 0;
        }
        return 0;
    }

    totalRatio = 0;
    numLive = 0;
    numSampled = 0;
    cur = pAnmObj;
    do {
        if (jntIdx < cur->numMapData
            && (cur->mapData[jntIdx] & NNS_G3D_ANMOBJ_MAPDATA_MASK) == NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
            if (cur->ratio > 0x1000) {
                totalRatio += 0x1000;
            } else if (cur->ratio > 0) {
                totalRatio += cur->ratio;
            }
            last = cur;
            numLive++;
        }
        cur = cur->next;
    } while (cur != 0);

    if (totalRatio == 0) {
        return 0;
    }
    if (numLive == 1) {
        mapData = last->mapData[jntIdx];
        if (last->funcAnm == 0) {
            return 0;
        }
        last->funcAnm(pResult, last, mapData & NNS_G3D_ANMOBJ_MAPDATA_ID);
        return 1;
    }

    MIi_CpuClearFast(0, pResult, sizeof(NNSG3dJntAnmResult));
    pResult->flag = -1;

    cur = pAnmObj;
    do {
        if (jntIdx < cur->numMapData
            && (cur->mapData[jntIdx] & NNS_G3D_ANMOBJ_MAPDATA_MASK) == NNS_G3D_ANMOBJ_MAPDATA_EXIST
            && cur->ratio > 0 && cur->funcAnm != 0) {
            cur->funcAnm(&sample, cur, cur->mapData[jntIdx] & NNS_G3D_ANMOBJ_MAPDATA_ID);
            if (numSampled == 0) {
                MIi_CpuCopy32(sample.rot[0], firstRow0, 0xc);
                MIi_CpuCopy32(sample.rot[2], firstRow2, 0xc);
            }
            if (totalRatio == 0x1000) {
                weight = cur->ratio;
            } else {
                weight = FX_Div(cur->ratio, totalRatio);
            }
            NNSi_G3dAnmBlendJntVec(pResult->scale, sample.scale, weight,
                                   sample.flag & NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE);
            NNSi_G3dAnmBlendJntVec(pResult->scaleEx0, sample.scaleEx0, weight,
                                   sample.flag & NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE);
            NNSi_G3dAnmBlendJntVec(pResult->scaleEx1, sample.scaleEx1, weight,
                                   sample.flag & NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE);
            if (!(sample.flag & NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO)) {
                pResult->trans[0] += (s32)(((long long)weight * sample.trans[0]) >> 12);
                pResult->trans[1] += (s32)(((long long)weight * sample.trans[1]) >> 12);
                pResult->trans[2] += (s32)(((long long)weight * sample.trans[2]) >> 12);
            }
            if (!(sample.flag & NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO)) {
                pResult->rot[0][0] += (weight * sample.rot[0][0]) >> 12;
                pResult->rot[0][1] += (weight * sample.rot[0][1]) >> 12;
                pResult->rot[0][2] += (weight * sample.rot[0][2]) >> 12;
                pResult->rot[1][0] += (weight * sample.rot[1][0]) >> 12;
                pResult->rot[1][1] += (weight * sample.rot[1][1]) >> 12;
                pResult->rot[1][2] += (weight * sample.rot[1][2]) >> 12;
            } else {
                pResult->rot[0][0] += weight;
                pResult->rot[1][1] += weight;
            }
            pResult->flag &= sample.flag;
        }
        cur = cur->next;
        numSampled++;
    } while (cur != 0);

    VEC_CrossProduct(pResult->rot[0], pResult->rot[1], pResult->rot[2]);
    if (pResult->rot[0][0] == 0 && pResult->rot[0][1] == 0 && pResult->rot[0][2] == 0) {
        MIi_CpuCopy32(firstRow0, pResult->rot[0], 0xc);
    } else {
        VEC_Normalize(pResult->rot[0], pResult->rot[0]);
    }
    if (pResult->rot[2][0] == 0 && pResult->rot[2][1] == 0 && pResult->rot[2][2] == 0) {
        MIi_CpuCopy32(firstRow2, pResult->rot[2], 0xc);
    } else {
        VEC_Normalize(pResult->rot[2], pResult->rot[2]);
    }
    VEC_CrossProduct(pResult->rot[2], pResult->rot[0], pResult->rot[1]);
    return 1;
}


/*
 * Visibility animation blend: walk the chain of animation objects and OR the
 * result of every object that maps this node into *pResult. Returns 1 when
 * at least one object contributed.
 */
int NNSi_G3dAnmBlendVis(u32 *pResult, const NNSG3dAnmObj *pAnmObj, u32 nodeIdx)
{
    int hasResult = 0;
    u32 objResult;

    *pResult = 0;
    do {
        if (nodeIdx < pAnmObj->numMapData) {
            u16 mapData = pAnmObj->mapData[nodeIdx];
            if ((mapData & NNS_G3D_ANMOBJ_MAPDATA_MASK) == NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                if (pAnmObj->funcAnm != 0) {
                    pAnmObj->funcAnm(&objResult, pAnmObj, mapData & NNS_G3D_ANMOBJ_MAPDATA_ID);
                    *pResult |= objResult;
                    hasResult = 1;
                }
            }
        }
        pAnmObj = pAnmObj->next;
    } while (pAnmObj != 0);
    return hasResult;
}
