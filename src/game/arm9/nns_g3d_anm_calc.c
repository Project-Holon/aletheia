/*
 * file:     nns_g3d_anm_calc.c
 * unit:     yes
 * function: NNSi_G3dAnmObjInitNsBca, NNSi_G3dAnmCalcNsBca, NNSi_G3dGetNodeTransFromMdl, NNSi_G3dGetNodeScaleFromMdl, NNSi_G3dGetNodeRotFromMdl, NNSi_G3dAnmCalcJntAnmNode, NNSi_G3dAnmGetTransData, NNSi_G3dAnmGetTransDataEx, NNSi_G3dAnmGetScaleData, NNSi_G3dAnmGetScaleDataEx, NNSi_G3dAnmGetRotData, NNSi_G3dAnmGetRotDataEx, NNSi_G3dAnmDecodeRotKey, NNSi_G3dAnmGetMatColorData, NNSi_G3dAnmGetMatAlphaData, NNSi_G3dAnmObjInitNsBma, NNSi_G3dAnmCalcNsBma, NNSi_G3dAnmGetTexSRTScalarData, NNSi_G3dAnmGetTexSRTRotData, NNSi_G3dAnmGetTexSRTData, NNSi_G3dAnmObjInitNsBta, NNSi_G3dAnmCalcNsBta, NNSi_G3dAnmObjInitNsBtp, NNSi_G3dAnmSetTexParam, NNSi_G3dAnmSetPlttParam, NNSi_G3dAnmCalcNsBtp, NNSi_G3dAnmObjInitNsBva, NNSi_G3dAnmCalcNsBva, NNSi_G3dSendJointSRTBasic, NNSi_G3dGetJointScaleBasic, NNSi_G3dSendJointSRTMaya, NNSi_G3dGetJointScaleMaya, NNSi_G3dTexMtxScaleRotTrans4x4, NNSi_G3dTexMtxRotTrans4x4, NNSi_G3dTexMtxScaleTrans, NNSi_G3dTexMtxTrans, NNSi_G3dTexMtxScaleRot4x4, NNSi_G3dTexMtxRot4x4, NNSi_G3dTexMtxScale4x4, NNSi_G3dTexMtxIdentity, NNSi_G3dSendTexMtx4x4, NNSi_G3dSendJointSRTSi3d, NNSi_G3dGetJointScaleSi3d, NNSi_G3dSendTexMtx4x3
 * address:  0x0206EB00
 * region:   arm9
 * compiler: dsi/../2.0/sp2p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g3d animation sampling: joint, material color, texture SRT,
 * texture pattern and visibility animations (object init and per-frame
 * sampling), the joint scale handlers and the geometry-command senders.
 *
 * Per-file compiler pin, "kept branches"/"kept constants" family
 * (docs/FRONTEND-PINS.md). Under dsi/1.1p1 the image's `mov r0, #0` at
 * 0x0206EB24 is CSE'd out of the loop counter's own zero (`mov r4, #0`
 * hoisted to 0x0206EB18) and the frame grows a fourth callee-saved
 * register: 1.1p1 emits `push {r4, r5, r6, lr}` against the original's
 * `push {r3, r4, r5, lr}`, 22 concrete bytes out at the same 124. Under
 * ../2.0/sp2 the same C rematerialises the zero and gives 124 bytes, 0
 * concrete mismatches.
 *
 * symbols:
 *   g_020A8224       0x020A8224  data
 *   MIi_CpuClear16    0x02082A48  arm
 *   gCurrentRS      0x02148DB0  data
 *   g_020A1998      0x020A1998  data  a1
 *   g_020A1999      0x020A1999  data  a1
 *   g_020A199A      0x020A199A  data  a1
 *   g_020A199B      0x020A199B  data  a1
 *   MI_Zero36B   0x020834A8  thumb
 *   VEC_Normalize   0x0207CCA4  arm
 *   MIi_CpuClear16   0x02082A48  arm
 *   NNS_G3dGetResDictIdxByName    0x0206E7EC  arm
 *   data_020A8230    0x020A8230  data
 *   data_020A8228    0x020A8228  data
 *   data_020A822C    0x020A822C  data
 *   NNS_G3dGetResDataByName  0x0206E62C  arm
 *   FX_Div  0x0207C768  arm
 *   NNSi_G3dTexPatAnmGetFrameValue  0x0206EA58  arm
 *   NNSi_G3dGetTexPatAnmTexNameByIdx  0x0206EA00  arm
 *   NNSi_G3dGetTexPatAnmPlttNameByIdx  0x0206EA2C  arm
 *   data_020A8220  0x020A8220  data
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   g_02149BC0  0x02149BC0  data
 *   FX_DivAsync       0x0207C930  arm
 *   FX_GetDivResult   0x0207C86C  arm
 *   FX_DivAsync  0x0207C930  arm
 *   FX_GetDivResult  0x0207C86C  arm
 *   g_dispatch       0x020A8438  data a4
 *   MIi_CpuCopy32  0x02082A90  arm
 *   g_02149BB4     0x02149BB4  data
 */
#include "nns_g3d_anm_calc_types.h"

#define FX32_SHIFT 12
#define FX_Whole(a) ((fx32)((a) >> FX32_SHIFT))
#define GetTexKeyAddr(key) ((u32)(((key) & 0x0000FFFF) << 3))

/* Volatile views: the image re-reads these fields where plain access would be cached. */
#define VOLATILE_MATANM(p) ((volatile NNSG3dMatAnmResult *)(p))
#define VOLATILE_JNTANM(p) ((volatile NNSG3dJntAnmResult *)(p))

extern void MIi_CpuClear16(u32 val, void *dst, u32 n);
extern void MI_Zero36B(void *p);
extern void VEC_Normalize(const int *src, int *dst);
s32 NNS_G3dGetResDictIdxByName(const NNSG3dResDict *pDict, const NNSG3dResName *pName);
extern void *NNS_G3dGetResDataByName(const NNSG3dResDict *pDict, const NNSG3dResName *pName);
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern const NNSG3dResTexPatAnmFV *NNSi_G3dTexPatAnmGetFrameValue(const NNSG3dResTexPatAnm *pPatAnm, u32 dataIdx, u32 frame);
extern const NNSG3dResName *NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx);
extern const NNSG3dResName *NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx);
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void FX_DivAsync(s32 num, s32 den);
extern s32  FX_GetDivResult(void);
extern void FX_DivAsync(fx32 numer, fx32 denom);
extern fx32 FX_GetDivResult(void);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *pAnmObj, const NNSG3dResJntAnm *pJntAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dGetNodeTransFromMdl(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetNodeScaleFromMdl(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetNodeRotFromMdl(NNSG3dJntAnmResult *pResult);
void NNSi_G3dAnmCalcJntAnmNode(const NNSG3dResJntAnm *pJntAnm, u32 dataIdx, u32 frame, NNSG3dJntAnmResult *pResult);
void NNSi_G3dAnmGetTransData(int *pVal, int frame, const NNSG3dJntAnmTInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetTransDataEx(int *pVal, int frame, const NNSG3dJntAnmTInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetScaleData(fx32 *pScaleInv, fx32 fxFrame, const NNSG3dJntAnmSInfo *pData, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetScaleDataEx(fx32 *pScaleInv, int frame, const NNSG3dJntAnmSInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetRotData(fx32 (*pRot)[3], int frame, const NNSG3dJntAnmRInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetRotDataEx(fx32 (*pRot)[3], int frame, const NNSG3dJntAnmRInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
int NNSi_G3dAnmDecodeRotKey(fx32 *pRot, const s16 *pArrayRot3, const s16 *pArrayRot9, u32 data);
u16 NNSi_G3dAnmGetMatColorData(const u8 *pRes, u32 info, u32 frameIdx);
u16 NNSi_G3dAnmGetMatAlphaData(const u8 *pRes, u32 info, u32 frameIdx);
void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *pAnmObj, const NNSG3dResMatAnm *pMatAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
s32 NNSi_G3dAnmGetTexSRTScalarData(const void *pRes, u32 info, u32 offset, u32 frameIdx);
int NNSi_G3dAnmGetTexSRTRotData(const void *pRes, u32 info, u32 offset, u32 frameIdx);
void NNSi_G3dAnmGetTexSRTData(const NNSG3dResTexSRTAnm *pSrtAnm, u32 dataIdx, u32 frame, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *pAnmObj, const NNSG3dResTexSRTAnm *pSrtAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *pAnmObj, const NNSG3dResTexPatAnm *pPatAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmSetTexParam(const NNSG3dResTex *pTex, const NNSG3dResName *pName, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmSetPlttParam(const NNSG3dResTex *pTex, const NNSG3dResName *pName, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *pAnmObj, const NNSG3dResVisAnm *pVisAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBva(NNSG3dVisAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dSendJointSRTBasic(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag);
void NNSi_G3dSendJointSRTMaya(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetJointScaleMaya(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag);
void NNSi_G3dTexMtxScaleRotTrans4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxRotTrans4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxScaleTrans(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxTrans(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxScaleRot4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxRot4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxScale4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxIdentity(MtxFx44 *pMtx);
void NNSi_G3dSendTexMtx4x4(NNSG3dMatAnmResult *pResult);
void NNSi_G3dSendJointSRTSi3d(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetJointScaleSi3d(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag);
void NNSi_G3dSendTexMtx4x3(NNSG3dMatAnmResult *pResult);
extern NNSG3dAnmObjFunc g_020A8224;
extern NNSG3dRS *gCurrentRS;
extern const NNSG3dPivotSlot g_020A1998[];
extern const NNSG3dPivotSlot g_020A1999[];
extern const NNSG3dPivotSlot g_020A199A[];
extern const NNSG3dPivotSlot g_020A199B[];
extern NNSG3dAnmObjFunc data_020A8230;
extern NNSG3dAnmObjFunc data_020A8228;
extern NNSG3dAnmObjFunc data_020A822C;
extern NNSG3dAnmObjFunc data_020A8220;
extern NNSG3dMayaScaleRow g_02149BC0[];
extern NNSG3dTexMtxBuildFunc g_dispatch[8];
extern s32 g_02149BB4[][6];

/*
 * Initialises a joint animation object (NitroSystem NNSi_G3dAnmObjInitNsBca):
 * stores the resource and the sampling function, clears the node map (two
 * bytes per model node) and fills one map entry per animated node with the
 * node id (top byte of the word the node's ofsNodeAnm offset points to) and
 * the "exists" bit.
 *
 * Per-file compiler pin, "kept branches"/"kept constants" family
 * (docs/FRONTEND-PINS.md). Under dsi/1.1p1 the image's `mov r0, #0` at
 * 0x0206EB24 is CSE'd out of the loop counter's own zero (`mov r4, #0`
 * hoisted to 0x0206EB18) and the frame grows a fourth callee-saved
 * register: 1.1p1 emits `push {r4, r5, r6, lr}` against the original's
 * `push {r3, r4, r5, lr}`, 22 concrete bytes out at the same 124. Under
 * ../2.0/sp2 the same C rematerialises the zero and gives 124 bytes, 0
 * concrete mismatches.
 */
void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *pAnmObj, const NNSG3dResJntAnm *pJntAnm, const NNSG3dResMdl *pMdl)
{
    u8 numNode;

    pAnmObj->resAnm = pJntAnm;
    pAnmObj->funcAnm = g_020A8224;
    numNode = pMdl->info.numNode;
    pAnmObj->numMapData = numNode;
    MIi_CpuClear16(0, pAnmObj->mapData, (u32)numNode << 1);
    {
        u32 i = 0;
        const u16 *ofsNodeAnm = pJntAnm->ofsNodeAnm;
        while (i < pJntAnm->numNode) {
            pAnmObj->mapData[i] =
                (u16)((*(const u32 *)((const u8 *)pJntAnm + ofsNodeAnm[i]) >> 24) | 0x100);
            i = i + 1;
        }
    }
}

/*
 * Joint animation sampling function (NNSi_G3dAnmCalcNsBca): clamps the 20.12
 * frame of the animation object into [0, (numFrame << 12) - 1] and forwards
 * to the per-node decoder.
 *
 * The callee takes FOUR arguments and the caller's own first argument is the
 * FOURTH, not the first (the image's `mov r3, r0` at 0x0206EB80 is that
 * argument being parked in r3 before r0 is reloaded with the table pointer).
 * Written as a three-argument forward of r0 the compiler lands at 56 bytes
 * against 60.
 */
void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx)
{
    fx32 frame;
    fx32 frameLimit;
    const NNSG3dResJntAnm *pJntAnm;

    pJntAnm = (const NNSG3dResJntAnm *)pAnmObj->resAnm;
    frameLimit = (fx32)((u32)pJntAnm->numFrame << 12);
    frame = (fx32)pAnmObj->frame;
    if (frame >= frameLimit) {
        frame = frameLimit - 1;
    } else if (frame < 0) {
        frame = 0;
    }
    NNSi_G3dAnmCalcJntAnmNode(pJntAnm, dataIdx, frame, pResult);
}

/*
 * Copies the model's own translation of the current node into the joint
 * result (or flags the result translation-zero).  Resolves the node through
 * the global render state at 0x02148DB0: sbc node index -> node dictionary
 * (render state +0xD4) -> unit through the table at dict + ofsEntry -> node
 * data by the unit's offset.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md).
 * The image keeps `tst r1, #1` at 0x0206EC18 and `beq 0x0206EC30` at
 * 0x0206EC1C over the four-instruction guard body at 0x0206EC20..0x0206EC2C
 * (`ldr r1,[r0]` / `orr r1,r1,#4` / `str r1,[r0]` / `bx lr`); dsi/1.1p1
 * -O4,p predicates it to ldrne/orrne/strne/bxne, giving 148 bytes against
 * the original's 152. Under ../2.0/sp2 the same C is 152 bytes, 0 mismatches.
 */
void NNSi_G3dGetNodeTransFromMdl(NNSG3dJntAnmResult *pResult)
{
    NNSG3dRS *pRS = gCurrentRS;
    const NNSG3dResDict *pDict;
    const NNSG3dResNodeData *pNode;
    const u8 *pUnitTbl;
    u32 unit;

    unit = pRS->c->nodeId;
    pDict = pRS->nodeDict;
    if (pDict == 0) goto none;
    if (pDict == 0) goto nullent;
    if (unit >= pDict->numEntry) goto nullent;
    pUnitTbl = (const u8 *)pDict + pDict->ofsEntry;
    unit = (u32)(pUnitTbl + 4 + ((const NNSG3dResDictEntryHdr *)pUnitTbl)->sizeUnit * unit);
    goto have;
nullent:
    unit = 0;
have:
    if (unit == 0) goto none;
    pNode = (const NNSG3dResNodeData *)((const u8 *)pDict + ((const NNSG3dResDictUnit *)unit)->ofsData);
    goto set;
none:
    pNode = 0;
set:
    if ((pNode->flag & NNS_G3D_SRTFLAG_TRANS_ZERO) != 0) {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO;
        return;
    }
    pResult->trans[0] = pNode->trans[0];
    pResult->trans[1] = pNode->trans[1];
    pResult->trans[2] = pNode->trans[2];
}

static inline const u8 *getDictUnit(const NNSG3dResDict *pDict, u32 idx)
{
    const u8 *pUnitTbl;
    if (pDict != 0 && idx < pDict->numEntry) {
        pUnitTbl = (const u8 *)pDict + pDict->ofsEntry;
        return pUnitTbl + 4 + ((const NNSG3dResDictEntryHdr *)pUnitTbl)->sizeUnit * idx;
    }
    return 0;
}

static inline const u8 *getDictData(const NNSG3dResDict *pDict, u32 idx)
{
    const u8 *pUnit;
    if (pDict != 0) {
        pUnit = getDictUnit(pDict, idx);
        if (pUnit != 0)
            return (const u8 *)pDict + ((const NNSG3dResDictUnit *)pUnit)->ofsData;
    }
    return 0;
}

/*
 * Resolves the current node through the global render state at 0x02148DB0,
 * skips the node's optional translation and rotation blocks by its flag bits,
 * and hands the scale payload to the render state's joint scale function.
 * NNSi_G3dAnmCalcJntAnmNode calls it for the third flag group.
 *
 * Closing levers over a 23-30 byte register residue:
 *   - the resolve is TWO NESTED INLINE HELPERS, getDictUnit() and
 *     getDictData().  Inlining is what renumbers the values so that the
 *     render state lands in ip and the dictionary in r4; the same statements
 *     written flat in the body stay at 7-16 bytes out whatever the
 *     declaration order;
 *   - the scale function takes FOUR arguments, (result, payload, sbc command,
 *     flags): the image loads the command into r2 at 0x0206EC5C and never
 *     writes r2 again, and the flag word stays in r3 up to the `blx`.  The
 *     same four-argument call is what NNSi_G3dAnmCalcJntAnmNode makes at its emit tail.
 *     A three-argument call is 21 bytes out.
 *
 * Front end: the unit's ../2.0/sp2 pin.  With the inline helpers this function
 * is compiler-neutral (EXACT under dsi/1.1p1 as well).
 */
void NNSi_G3dGetNodeScaleFromMdl(NNSG3dJntAnmResult *pResult)
{
    NNSG3dRS *pRS = gCurrentRS;
    const NNSG3dSbcNodeDesc *pCmd = pRS->c;
    const u8 *p;
    u32 flag;

    p = getDictData(pRS->nodeDict, pCmd->nodeId);
    flag = ((const u16 *)p)[0];
    p = p + 4;
    if ((flag & NNS_G3D_SRTFLAG_TRANS_ZERO) == 0) p += 0xc;
    if ((flag & NNS_G3D_SRTFLAG_ROT_ZERO) == 0) {
        if ((flag & NNS_G3D_SRTFLAG_PIVOT_EXIST) != 0) p += 4; else p += 0x10;
    }
    pRS->jntScaleFunc(pResult, (const fx32 *)p, pCmd, flag);
}

/*
 * Copies the model's own rotation of the current node into the joint result.
 * Node flag bit 1 is rotation zero, bit 3 selects the pivot-compressed form
 * (0xf0 the pivot index, 0x100 / 0x200 / 0x400 the pivot sign and the C / D
 * sign reversals over the four pivot-column tables at 0x020A1998..B), else
 * the nine rotation entries are copied out.  MI_Zero36B is MI_Zero36B.
 *
 * THE LEVER: the pivot index is `long`, not int.  With int, node and
 * pivot swap r4 / r5 at every use; mwcc colours long and int as different
 * types.  EXACT under ../2.0/sp2 as well.
 */
void NNSi_G3dGetNodeRotFromMdl(NNSG3dJntAnmResult *pResult)
{
    NNSG3dRS *pRS = gCurrentRS;
    const u8 *pNodeData;
    u32 flag;
    const s16 *pRot;
    long pivotIdx;
    int pivotU;
    int pivotV;

    pNodeData = getDictData(pRS->nodeDict, pRS->c->nodeId);
    flag = ((const u16 *)pNodeData)[0];
    pRot = (const s16 *)(pNodeData + 4);
    if ((flag & NNS_G3D_SRTFLAG_TRANS_ZERO) == 0) pRot = (const s16 *)((const u8 *)pRot + 0xc);
    if ((flag & NNS_G3D_SRTFLAG_ROT_ZERO) == 0) {
        if ((flag & NNS_G3D_SRTFLAG_PIVOT_EXIST) != 0) {
            pivotIdx = (int)(flag & NNS_G3D_SRTFLAG_IDXPIVOT_MASK) >> 4;
            pivotU = pRot[0];
            pivotV = pRot[1];
            MI_Zero36B(pResult->rot);
            ((fx32 *)pResult->rot)[pivotIdx] = (((const NNSG3dResNodeData *)pNodeData)->flag & NNS_G3D_SRTFLAG_PIVOT_MINUS) ? -0x1000 : 0x1000;
            ((fx32 *)pResult->rot)[g_020A1998[pivotIdx].index] = pivotU;
            ((fx32 *)pResult->rot)[g_020A1999[pivotIdx].index] = pivotV;
            ((fx32 *)pResult->rot)[g_020A199A[pivotIdx].index] = (((const NNSG3dResNodeData *)pNodeData)->flag & NNS_G3D_SRTFLAG_PIVOT_REVC) ? -pivotV : pivotV;
            ((fx32 *)pResult->rot)[g_020A199B[pivotIdx].index] = (((const NNSG3dResNodeData *)pNodeData)->flag & NNS_G3D_SRTFLAG_PIVOT_REVD) ? -pivotU : pivotU;
        } else {
            ((fx32 *)pResult->rot)[0] = ((const NNSG3dResNodeData *)pNodeData)->rotM00;
            ((fx32 *)pResult->rot)[1] = pRot[0];
            ((fx32 *)pResult->rot)[2] = pRot[1];
            ((fx32 *)pResult->rot)[3] = pRot[2];
            ((fx32 *)pResult->rot)[4] = pRot[3];
            ((fx32 *)pResult->rot)[5] = pRot[4];
            ((fx32 *)pResult->rot)[6] = pRot[5];
            ((fx32 *)pResult->rot)[7] = pRot[6];
            ((fx32 *)pResult->rot)[8] = pRot[7];
        }
    } else {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO;
    }
}

/*
 * The per-node channel decoder of the joint animation player.  Finds the
 * node record through the u16 table at pJntAnm->ofsNodeAnm, then walks the
 * record flag groups: the three translation channels (NNSi_G3dAnmGetTransData /
 * NNSi_G3dAnmGetTransDataEx) or the zero/model-default flags, the rotation (NNSi_G3dAnmGetRotData
 * / NNSi_G3dAnmGetRotDataEx, or one packed key through NNSi_G3dAnmDecodeRotKey with row 2 rebuilt
 * by the cross product), and the three scale channels (NNSi_G3dAnmGetScaleData /
 * NNSi_G3dAnmGetScaleDataEx) into the scale block, then emits through the render state
 * four-argument scale function.  A dead node (flag bit 0) emits with
 * result flag 7; the 0x600-guarded arm hands off to NNSi_G3dGetNodeScaleFromMdl, which
 * emits on its own.
 *
 * Two levers closed a p/lerp register swap at 22 sites:
 *   - lerp is ONE conditional expression,
 *       lerp = ((frame & 0xfff) != 0 && (pJntAnm->flag & NNS_G3D_JNTANM_FLAG_INTERPOLATE) != 0) ? 1 : 0;
 *     which keeps the image `movne r6,#1 / bne / mov r6,#0` shape and
 *     gives the cursor r5 (the goto form and the if/else form give the
 *     swap, the bare `&&` value is 944 bytes);
 *   - the cofactor block is NNSi_G3dAnmGetRotDataEx's: three temporaries from direct
 *     field reads, stored after all three are computed (the six bound locals
 *     are 23 bytes of register naming out once lerp is right).
 * The flag groups are plain nested if/else (the earlier goto ladder
 * compiles identically).  Every group puts the call arm first.
 */
void NNSi_G3dAnmCalcJntAnmNode(const NNSG3dResJntAnm *pJntAnm, u32 dataIdx, u32 frame, NNSG3dJntAnmResult *pResult)
{
    u32 *p;
    u32 flag;
    u32 *pRec;
    int lerp;
    u32 scaleInv[6];
    u32 sInvPair[6];

    pRec = (u32 *)((u8 *)pJntAnm + pJntAnm->ofsNodeAnm[dataIdx]);
    flag = pRec[0];
    if ((flag & 1) != 0) {
        pResult->flag = 7;
    } else {
        p = pRec + 1;
        lerp = ((frame & 0xfff) != 0 && (pJntAnm->flag & NNS_G3D_JNTANM_FLAG_INTERPOLATE) != 0) ? 1 : 0;
        pResult->flag = 0;

        if ((flag & 6) == 0) {
            if ((flag & 8) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetTransDataEx((int *)(&pResult->trans[0]), frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                else
                    NNSi_G3dAnmGetTransData((int *)(&pResult->trans[0]), frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                p = p + 2;
            } else {
                pResult->trans[0] = *p++;
            }
            if ((flag & 0x10) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetTransDataEx((int *)(&pResult->trans[1]), frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                else
                    NNSi_G3dAnmGetTransData((int *)(&pResult->trans[1]), frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                p = p + 2;
            } else {
                pResult->trans[1] = *p++;
            }
            if ((flag & 0x20) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetTransDataEx((int *)(&pResult->trans[2]), frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                else
                    NNSi_G3dAnmGetTransData((int *)(&pResult->trans[2]), frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                p = p + 2;
            } else {
                pResult->trans[2] = *p++;
            }
        } else if ((flag & 2) != 0) {
            pResult->flag = pResult->flag | NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO;
        } else {
            NNSi_G3dGetNodeTransFromMdl(pResult);
        }

        if ((flag & 0xc0) == 0) {
            if ((flag & 0x100) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetRotDataEx(pResult->rot, frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                else
                    NNSi_G3dAnmGetRotData(pResult->rot, frame, (const NNSG3dJntAnmTInfo *)p, pJntAnm);
                p = p + 2;
            } else {
                u32 *rot3 = (u32 *)((u8 *)pJntAnm + pJntAnm->ofsRot3);
                u32 *rot9 = (u32 *)((u8 *)pJntAnm + pJntAnm->ofsRot9);
                if (NNSi_G3dAnmDecodeRotKey(&pResult->rot[0][0], (s16 *)rot3, (s16 *)rot9, *p) != 0) {
                    int row2X, row2Y, row2Z;
                    row2X = (pResult->rot[0][1] * pResult->rot[1][2] - pResult->rot[0][2] * pResult->rot[1][1]) >> 12;
                    row2Y = (pResult->rot[0][2] * pResult->rot[1][0] - pResult->rot[0][0] * pResult->rot[1][2]) >> 12;
                    row2Z = (pResult->rot[0][0] * pResult->rot[1][1] - pResult->rot[0][1] * pResult->rot[1][0]) >> 12;
                    pResult->rot[2][0] = row2X;
                    pResult->rot[2][1] = row2Y;
                    pResult->rot[2][2] = row2Z;
                }
                p = p + 1;
            }
        } else if ((flag & 0x40) != 0) {
            pResult->flag = pResult->flag | NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO;
        } else {
            NNSi_G3dGetNodeRotFromMdl(pResult);
        }

        if ((flag & 0x600) == 0) {
            if ((flag & 0x800) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetScaleDataEx((fx32 *)(&sInvPair[4]), frame, (const NNSG3dJntAnmSInfo *)p, pJntAnm);
                else
                    NNSi_G3dAnmGetScaleData((fx32 *)(&sInvPair[4]), frame, (const NNSG3dJntAnmSInfo *)p, pJntAnm);
                scaleInv[0] = sInvPair[4];
                scaleInv[3] = sInvPair[5];
            } else {
                scaleInv[0] = p[0];
                scaleInv[3] = p[1];
            }
            if ((flag & 0x1000) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetScaleDataEx((fx32 *)(&sInvPair[2]), frame, (const NNSG3dJntAnmSInfo *)(p + 2), pJntAnm);
                else
                    NNSi_G3dAnmGetScaleData((fx32 *)(&sInvPair[2]), frame, (const NNSG3dJntAnmSInfo *)(p + 2), pJntAnm);
                scaleInv[1] = sInvPair[2];
                scaleInv[4] = sInvPair[3];
            } else {
                scaleInv[1] = p[2];
                scaleInv[4] = p[3];
            }
            if ((flag & 0x2000) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetScaleDataEx((fx32 *)(&sInvPair[0]), frame, (const NNSG3dJntAnmSInfo *)(p + 4), pJntAnm);
                else
                    NNSi_G3dAnmGetScaleData((fx32 *)(&sInvPair[0]), frame, (const NNSG3dJntAnmSInfo *)(p + 4), pJntAnm);
                scaleInv[2] = sInvPair[0];
                scaleInv[5] = sInvPair[1];
            } else {
                scaleInv[2] = p[4];
                scaleInv[5] = p[5];
            }
        } else if ((flag & 0x200) != 0) {
            pResult->flag = pResult->flag | NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE;
        } else {
            NNSi_G3dGetNodeScaleFromMdl(pResult);
            return;
        }
    }

    {
        u32 scaleFlag = (pResult->flag & 1) ? 4 : 0;
        NNSG3dRS *pRS = gCurrentRS;
        pRS->jntScaleFunc(pResult, (const fx32 *)&scaleInv[0], pRS->c, scaleFlag);
    }
}

/*
 * Translation keyframe fetch without the lerp (NNSi_G3dAnmCalcJntAnmNode calls it for the
 * three translation channels when the frame has no fraction or the joint
 * animation flag has the interpolation bit clear): writes the key (plain), the
 * mean of two keys (interp2) or the 3:1 blend of two keys into *pVal.  Info
 * bit 29 selects s16 keys over fx32 keys; the fx32 3:1 blend is a 64-bit
 * expression.
 *
 * Per-file compiler pin ../2.0/sp2p2, NOT the packet's ../2.0/sp2, on a new
 * front-end tell (docs/FRONTEND-PINS.md, "64-bit multiply by a constant"):
 * the image multiplies the sign-extended fx32 key by 3 as
 * `mov r2, #3` / `umull lr, ip, r3, r2` / `asr r3, r3, #0x1f` /
 * `mla ip, r3, r2, ip` at 0x0206F2CC..0x0206F2D8, i.e. it knows the
 * constant's high word is zero.  ../2.0/sp2 (and 2.0 base/sp1/sp1p5) never
 * fold it: every spelling adds `mov ip, #0` / `mla hi, lo, ip, hi`, which
 * costs two more callee-saved registers (`push {r3, r4, r5, lr}` against the
 * image's `push {r4, lr}`) and the same C is 352 bytes / 184 concrete bytes
 * out.  dsi/1.1p1 folds the multiply but predicates the image's kept
 * branches (336 bytes, 82 out).  ../2.0/sp2p2 (and sp2p3/sp2p4) do both:
 * 344 bytes, 0 mismatches.  Every other matched member of this family is
 * also EXACT under sp2p2, so this is a refinement of the family pin rather
 * than a different compiler.
 *
 * Source levers:
 *   - statements in the order ofs, idx, pArray, info: idx must be taken from
 *     the frame before pArray is formed so that pArray reuses the frame's
 *     register (r1) and idx lands in r4;
 *   - nonInterp is written s16-arm first with its own return; 2.0 inverts it
 *     into the image's `ldreq/streq/popeq` word arm.  Word-arm-first is
 *     predicated whole and four bytes short;
 *   - interp2 is spelled with a pointer pS16 / byte offset for s16 and a
 *     pointer pWord built in the arm for fx32 (pWord[1] read first);
 *   - the `idx & 2` arm goes through a named temporary (`idx = idx >> 2`
 *     directly is 77 bytes out: the value numbering moves idx out of r4);
 *   - the 64-bit product is bound to a function-scope `product` before the
 *     sum, so the `adds` takes the product as its first operand.
 */
void NNSi_G3dAnmGetTransData(int *pVal, int frame, const NNSG3dJntAnmTInfo *pInfo, const NNSG3dResJntAnm *pJntAnm)
{
    int *pArray;
    u32 info;
    u32 idx;
    u32 ofs;
    u32 lastInterp, idxTriple, quarter;
    int v, vSub;
    long long product;

    ofs = pInfo->offset;
    idx = (u32)(frame >> 12);
    pArray = (int *)((const u8 *)pJntAnm + ofs);
    info = pInfo->info;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_MASK) {
        lastInterp = (info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT;
        if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
            if (idx & 1) {
                if (idx > lastInterp) {
                    idx = (lastInterp >> 1) + 1;
                    goto nonInterp;
                }
                idx = idx >> 1;
                goto interp2;
            }
            idx = idx >> 1;
            goto nonInterp;
        } else {
            u32 rem = idx & 3;
            if (rem != 0) {
                if (idx > lastInterp) { idx = rem + (lastInterp >> 2); goto nonInterp; }
                if (idx & 1) {
                    if (idx & 2) { quarter = idx >> 2; idx = quarter; idxTriple = idx + 1; }
                    else { idxTriple = idx >> 2; idx = idxTriple + 1; }
                    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
                        v = ((s16 *)pArray)[idxTriple];
                        vSub = ((s16 *)pArray)[idx];
                        v *= 3;
                        v += vSub;
                        *pVal = v >> 2;
                        return;
                    }
                    product = (long long)pArray[idxTriple] * 3;
                    *pVal = (int)((product + pArray[idx]) >> 2);
                    return;
                }
                idx = idx >> 2;
                goto interp2;
            }
            idx = idx >> 2;
        }
    }
    goto nonInterp;

interp2:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        s16 *pS16 = (s16 *)pArray + idx;
        u32 byteOfs = idx << 1;
        v = *(s16 *)((u8 *)pArray + byteOfs);
        vSub = pS16[1];
        v = (v + vSub) >> 1;
    } else {
        int *pWord = pArray + idx;
        vSub = pWord[1];
        v = pArray[idx];
        v = (v >> 1) + (vSub >> 1);
    }
    *pVal = v;
    return;

nonInterp:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        *pVal = ((s16 *)pArray)[idx];
        return;
    }
    *pVal = pArray[idx];
}

/*
 * Translation keyframe lerp (NNSi_G3dAnmCalcJntAnmNode calls it for the three translation
 * channels when the frame has a fraction and the joint animation flag has the
 * interpolation bit set).  The last key either wrap-blends against key 0
 * (flag bit 1) or is fetched plain; every other key picks a (mask, mul, shift)
 * triple per stride and falls into one shared lerp tail.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): the
 * image predicates the wrap blend's word arm and BRANCHES over the s16 arm
 * (`ldreq r3,[ip,lr,lsl #2]` / `ldreq r1,[ip]` / `beq 0x0206F3DC` at
 * 0x0206F3C4..0x0206F3CC); dsi/1.1p1 -O4,p predicates both arms, giving 340
 * bytes against 348, 232 concrete bytes out.  Under ../2.0/sp2 the same C
 * is 348 bytes, 0 mismatches.
 *
 * Closing levers: every width choice is written s16-arm FIRST as a plain
 * if/else (no goto to a shared label); the lerp tail's two arms are spelled
 * as NNSi_G3dAnmGetTransData's interp2 block (s16 via a byte offset `idx << 1` plus a
 * pointer pS16, word via a pointer pWord built inside the arm); and in
 * `last:` the mask is assigned before `mul = 1`.
 */
void NNSi_G3dAnmGetTransDataEx(int *pVal, int frame, const NNSG3dJntAnmTInfo *pInfo, const NNSG3dResJntAnm *pJntAnm)
{
    u8 *pArray = (u8 *)pJntAnm + pInfo->offset;
    u32 info = pInfo->info;
    int idx = frame >> 12;
    u32 lastInterp, frac, mul, shift;
    int v0, v1;

    if ((int)(pJntAnm->numFrame - 1) != (frame >> 12)) goto general;

    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) != 0) {
        if ((info & NNS_G3D_JNTANM_SINFO_STEP_2) != 0) {
            idx = (idx & 1) + ((u32)idx >> 1);
        } else {
            idx = (idx & 3) + ((u32)idx >> 2);
        }
    }
    if ((pJntAnm->flag & NNS_G3D_JNTANM_FLAG_END_TO_START_INTERP) != 0) {
        frac = frame & 0xfff;
        if ((info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) != 0) {
            v0 = ((s16 *)pArray)[idx];
            v1 = *(s16 *)pArray;
        } else {
            v0 = ((int *)pArray)[idx];
            v1 = *(int *)pArray;
        }
        *pVal = v0 + (((v1 - v0) * (int)frac) >> 12);
        return;
    }
    if ((info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) != 0) {
        *pVal = ((s16 *)pArray)[idx];
    } else {
        *pVal = ((int *)pArray)[idx];
    }
    return;

general:
    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) == 0) goto last;
    {
        u32 lastInterpField = info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK;
        lastInterp = lastInterpField >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT;
    }
    if ((info & NNS_G3D_JNTANM_SINFO_STEP_2) != 0) {
        if ((u32)idx >= lastInterp) {
            idx = lastInterp >> 1;
            goto last;
        }
        idx = (u32)idx >> 1;
        frame = frame & (int)(NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK >> 16);
        mul = 2;
        shift = 1;
        goto lerp;
    }
    if ((u32)idx >= lastInterp) {
        idx = (idx & 3) + ((u32)idx >> 2);
        goto last;
    }
    idx = (u32)idx >> 2;
    frame = frame & 0x3fff;
    mul = 4;
    shift = 2;
    goto lerp;
last:
    frame = frame & 0xfff;
    mul = 1;
    shift = 0;
lerp:
    if ((info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) != 0) {
        s16 *pS16 = (s16 *)pArray + idx;
        u32 byteOfs = (u32)idx << 1;
        v0 = *(s16 *)(pArray + byteOfs);
        v1 = pS16[1];
    } else {
        int *pWord = (int *)pArray + idx;
        v0 = ((int *)pArray)[idx];
        v1 = pWord[1];
    }
    *pVal = (int)((v0 * (int)mul + (((v1 - v0) * frame) >> 12)) >> shift);
}

/*
 * Vector-2 keyframe sampler without the lerp (NNSi_G3dAnmCalcJntAnmNode calls it when the
 * cursor has no fraction or root->f08 bit 0 is clear): the NitroSystem G3D
 * joint-animation scale fetch, which reads a (scale, inverse scale) pair per
 * key.  Written from the start in the library's shape (wave 20, lane
 * nns_fresh): the NNS_G3D_JNTANM_SINFO_* step / last-interp / fx16_0206EB7C flags,
 * the frame through FX_Whole, one pArray base, the goto SCALE_NONINTERP /
 * SCALE_INTERP_2 tails and the inline 1:3 blend, keys as (s, invs) pair
 * structs.  The NitroSystem name of the routine is not attested in this
 * repository; the identifiers follow the library's style only.
 *
 * Compiler pin ../2.0/sp2p2, the family pin (docs/families/cluster_0206EB00.h,
 * "64-bit multiply by a constant"): ../2.0/sp2 and dsi/1.1p1 both DIFF.
 *
 * Source levers, all read off the image:
 *   - frame taken before pArray and info, so pArray reuses Frame's r1;
 *   - keys indexed through pair structs (a flat fx16_0206EB7C/fx32 array with 2 * idx
 *     emits an extra lsl per key, 556 bytes);
 *   - SCALE_INTERP_2 through one element pointer `base + idx` read at [0]
 *     and [1] (array subscripts at idx and idx + 1 form idx + 1 separately);
 *   - fx32 1:3 blend through element pointers for idx and idxSub and the
 *     64-bit product named, `product = (fx64)v * 3; (product + vSub) >> 2`, which puts
 *     the product first in the adds (the unnamed sum canonicalises to
 *     vSub first, the old 2-byte residue);
 *   - fx16_0206EB7C 1:3 blend by array subscript with the base advanced to the
 *     idxSub element for the second key, so that address forms in the
 *     base's dying register.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmGetScaleData.c \
 *       --func NNSi_G3dAnmGetScaleData --addr 0x0206F4C8 --cc ../2.0/sp2p2 --arm
 */
void NNSi_G3dAnmGetScaleData(fx32 *pScaleInv, fx32 fxFrame, const NNSG3dJntAnmSInfo *pData, const NNSG3dResJntAnm *pJntAnm)
{
    u32 frame = (u32)FX_Whole(fxFrame);
    const void *pArray = (const void *)((const u8 *)pJntAnm + pData->offset);
    u32 info = pData->info;
    u32 lastInterp;
    u32 idx;
    u32 idxSub;

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK))
    {
        idx = frame;
        goto SCALE_NONINTERP;
    }

    lastInterp = (info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2)
    {
        if (frame & 1)
        {
            if (frame > lastInterp)
            {
                idx = (lastInterp >> 1) + 1;
                goto SCALE_NONINTERP;
            }
            else
            {
                idx = frame >> 1;
                goto SCALE_INTERP_2;
            }
        }
        else
        {
            idx = frame >> 1;
            goto SCALE_NONINTERP;
        }
    }
    else
    {
        if (frame & 3)
        {
            if (frame > lastInterp)
            {
                idx = (lastInterp >> 2) + (frame & 3);
                goto SCALE_NONINTERP;
            }

            if (frame & 1)
            {
                fx32 v, vSub;

                if (frame & 2)
                {
                    idxSub = frame >> 2;
                    idx = idxSub + 1;
                }
                else
                {
                    idx = frame >> 2;
                    idxSub = idx + 1;
                }

                if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
                {
                    const ScaleFx16 *pFx16 = (const ScaleFx16 *)pArray;

                    v = pFx16[idx].s;
                    vSub = pFx16[idxSub].s;
                    pScaleInv[0] = (v * 3 + vSub) >> 2;

                    v = pFx16[idx].invs;
                    pFx16 += idxSub;
                    vSub = pFx16->invs;
                    pScaleInv[1] = (v * 3 + vSub) >> 2;
                }
                else
                {
                    const ScaleFx32 *pFx32 = (const ScaleFx32 *)pArray + idx;
                    const ScaleFx32 *pFx32Sub = (const ScaleFx32 *)pArray + idxSub;

                    fx64 product;

                    v = pFx32->s;
                    vSub = pFx32Sub->s;
                    product = (fx64)v * 3;
                    pScaleInv[0] = (fx32)((product + vSub) >> 2);

                    v = pFx32->invs;
                    vSub = pFx32Sub->invs;
                    product = (fx64)v * 3;
                    pScaleInv[1] = (fx32)((product + vSub) >> 2);
                }

                return;
            }
            else
            {
                idx = frame >> 2;
                goto SCALE_INTERP_2;
            }
        }
        else
        {
            idx = frame >> 2;
            goto SCALE_NONINTERP;
        }
    }

SCALE_NONINTERP:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
    {
        const ScaleFx16 *pFx16 = (const ScaleFx16 *)pArray;
        pScaleInv[0] = pFx16[idx].s;
        pScaleInv[1] = pFx16[idx].invs;
    }
    else
    {
        const ScaleFx32 *pFx32 = (const ScaleFx32 *)pArray;
        pScaleInv[0] = pFx32[idx].s;
        pScaleInv[1] = pFx32[idx].invs;
    }
    return;

SCALE_INTERP_2:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
    {
        const ScaleFx16 *pFx16 = (const ScaleFx16 *)pArray + idx;
        pScaleInv[0] = (pFx16[0].s + pFx16[1].s) >> 1;
        pScaleInv[1] = (pFx16[0].invs + pFx16[1].invs) >> 1;
    }
    else
    {
        const ScaleFx32 *pFx32 = (const ScaleFx32 *)pArray + idx;
        pScaleInv[0] = (pFx32[0].s + pFx32[1].s) >> 1;
        pScaleInv[1] = (pFx32[0].invs + pFx32[1].invs) >> 1;
    }
}

/*
 * Scale key lerp (NitroSystem getScaleDataEx): the two-component sibling of
 * NNSi_G3dAnmGetTransDataEx (same record, same header, same flag cascade), called by
 * NNSi_G3dAnmCalcJntAnmNode for the three scale channels when the frame has a fraction
 * and the joint animation flag has the interpolation bit set.  Keys are
 * (scale, inverse scale) pairs of fx32, or of fx16 with info bit 29.  The
 * last key either wraps against key 0 (flag bit 1, idxNext = 0 into the
 * shared lerp tail) or is fetched plain; otherwise the (mask, mul, shift)
 * triple is chosen per stride and one shared tail lerps both components.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): the
 * image keeps `tst r2, #0x20000000` / `beq 0x0206F720` at 0x0206F700 /
 * 0x0206F704 over the six-instruction fx16 plain-fetch arm; dsi/1.1p1 -O4,p
 * predicates the fx32 arm instead (`ldreq/addeq/streq/ldreq`) and the same C
 * is 392 bytes against 404, 285 concrete bytes out.  Under ../2.0/sp2 the
 * same C is 404 bytes, 0 mismatches.
 *
 * Two source levers: keys indexed through the pair struct types (an `int`
 * subscript `[idx * 2]` emits an extra `lsl`), and in `last:` the mask
 * `frame & 0xfff` assigned BEFORE `mul = 1` (the other order lets the
 * compiler derive 0xfff as `rsb r5, r4, #0x1000` and drop the pool word,
 * 4 bytes).
 */
void NNSi_G3dAnmGetScaleDataEx(fx32 *pScaleInv, int frame, const NNSG3dJntAnmSInfo *pInfo, const NNSG3dResJntAnm *pJntAnm)
{
    u8 *pArray = (u8 *)pJntAnm + pInfo->offset;
    u32 info = pInfo->info;
    int idx = frame >> 12;
    u32 lastInterp, idxNext, mul, shift;
    int s0, inv0, s1, inv1;

    if ((int)(pJntAnm->numFrame - 1) != (frame >> 12)) goto general;

    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) != 0) {
        if ((info & NNS_G3D_JNTANM_SINFO_STEP_2) != 0) {
            idx = (idx & 1) + ((u32)idx >> 1);
        } else {
            idx = (idx & 3) + ((u32)idx >> 2);
        }
    }
    if ((pJntAnm->flag & NNS_G3D_JNTANM_FLAG_END_TO_START_INTERP) != 0) {
        idxNext = 0;
        goto last;
    }
    if ((info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) != 0) {
        pScaleInv[0] = ((ScaleFx16 *)pArray)[idx].s;
        pScaleInv[1] = ((ScaleFx16 *)pArray)[idx].invs;
    } else {
        pScaleInv[0] = ((ScaleFx32 *)pArray)[idx].s;
        pScaleInv[1] = ((ScaleFx32 *)pArray)[idx].invs;
    }
    return;

general:
    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) == 0) goto next;
    {
        u32 lastInterpField = info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK;
        lastInterp = lastInterpField >> 16;
    }
    if ((info & NNS_G3D_JNTANM_SINFO_STEP_2) != 0) {
        if ((u32)idx >= lastInterp) {
            idx = lastInterp >> 1;
            idxNext = idx + 1;
            goto last;
        }
        idx = (u32)idx >> 1;
        idxNext = idx + 1;
        frame = frame & (int)(NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT);
        mul = 2;
        shift = 1;
        goto lerp;
    }
    if ((u32)idx >= lastInterp) {
        idx = (idx & 3) + ((u32)idx >> 2);
        idxNext = idx + 1;
        goto last;
    }
    idx = (u32)idx >> 2;
    idxNext = idx + 1;
    frame = frame & 0x3fff;
    mul = 4;
    shift = 2;
    goto lerp;
next:
    idxNext = idx + 1;
last:
    frame = frame & 0xfff;
    mul = 1;
    shift = 0;
lerp:
    if ((info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) != 0) {
        s0 = ((ScaleFx16 *)pArray)[idx].s;
        inv0 = ((ScaleFx16 *)pArray)[idx].invs;
        s1 = ((ScaleFx16 *)pArray)[idxNext].s;
        inv1 = ((ScaleFx16 *)pArray)[idxNext].invs;
    } else {
        s0 = ((ScaleFx32 *)pArray)[idx].s;
        inv0 = ((ScaleFx32 *)pArray)[idx].invs;
        s1 = ((ScaleFx32 *)pArray)[idxNext].s;
        inv1 = ((ScaleFx32 *)pArray)[idxNext].invs;
    }
    pScaleInv[0] = (int)((s0 * (int)mul + (((s1 - s0) * frame) >> 12)) >> shift);
    pScaleInv[1] = (int)((inv0 * (int)mul + (((inv1 - inv0) * frame) >> 12)) >> shift);
}

/*
 * Rotation key fetch without the lerp (NitroSystem getRotData): NNSi_G3dAnmGetTransData's
 * flag cascade with NNSi_G3dAnmDecodeRotKey decodes in place of key loads.  plain: decode
 * key idx into pRot, rebuild row 2 by the cross product if the decode returned
 * 1, else normalise it; two: decode idxBlend into pRot and idxBlend + 1 into
 * rotB and sum; 3:1: decode idxTriple into pRot and idxBlend into rotA,
 * pRot = rotA + pRot * 3.  Rows 0 and 1 are normalised with VEC_Normalize;
 * row 2 is blended and normalised only when neither decode returned 1, else
 * rebuilt by the cross product.
 *
 * The 3:1 arm's decode accumulator is its OWN variable, declared with its
 * initialiser at the top of the `if (idx & 1)` block (`u32 needCross3 = 0;`).
 * A separate function-scope variable assigned 0 at the same point does not
 * move the register swap.  The cross product is three temporaries from direct
 * field reads, stored after all three are computed; the two path's second
 * decode indexes `((u16 *)pArray + idxBlend)[1]`.
 */
void NNSi_G3dAnmGetRotData(fx32 (*pRot)[3], int frame, const NNSG3dJntAnmRInfo *pInfo, const NNSG3dResJntAnm *pJntAnm)
{
    u32 info;
    u32 idx;
    u32 lastInterp, idxTriple;
    u32 ofsRot9;
    u32 ofsRot3;
    u8 *pArray;
    u32 needCross;
    u32 idxBlend;
    int rotA[9];
    int rotB[9];

    info = pInfo->info;
    idx = (u32)(frame >> 12);
    pArray = (u8 *)pJntAnm + pInfo->offset;
    ofsRot3 = pJntAnm->ofsRot3;
    ofsRot9 = pJntAnm->ofsRot9;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_MASK) {
        lastInterp = (info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK) >> 16;
        if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
            if (idx & 1) {
                if (idx > lastInterp) {
                    idx = (lastInterp >> 1) + 1;
                    goto plain;
                }
                idxBlend = idx >> 1;
                goto two;
            }
            idx = idx >> 1;
            goto plain;
        } else {
            u32 rem = idx & 3;
            if (rem != 0) {
                if (idx > lastInterp) { idx = rem + (lastInterp >> 2); goto plain; }
                if (idx & 1) {
                    u32 needCross3 = 0;

                    if (idx & 2) { idxBlend = idx >> 2; idxTriple = idxBlend + 1; }
                    else { idxTriple = idx >> 2; idxBlend = idxTriple + 1; }
                    needCross3 |= NNSi_G3dAnmDecodeRotKey(&pRot[0][0], (s16 *)((u8 *)pJntAnm + ofsRot3), (s16 *)((u8 *)pJntAnm + ofsRot9), ((u16 *)pArray)[idxTriple]);
                    needCross3 |= NNSi_G3dAnmDecodeRotKey(rotA, (s16 *)((u8 *)pJntAnm + ofsRot3), (s16 *)((u8 *)pJntAnm + ofsRot9), ((u16 *)pArray)[idxBlend]);
                    pRot[0][0] = rotA[0] + pRot[0][0] * 3;
                    pRot[0][1] = rotA[1] + pRot[0][1] * 3;
                    pRot[0][2] = rotA[2] + pRot[0][2] * 3;
                    pRot[1][0] = rotA[3] + pRot[1][0] * 3;
                    pRot[1][1] = rotA[4] + pRot[1][1] * 3;
                    pRot[1][2] = rotA[5] + pRot[1][2] * 3;
                    VEC_Normalize(pRot[0], pRot[0]);
                    VEC_Normalize(pRot[1], pRot[1]);
                    if (needCross3 == 0) {
                        pRot[2][0] = rotA[6] + pRot[2][0] * 3;
                        pRot[2][1] = rotA[7] + pRot[2][1] * 3;
                        pRot[2][2] = rotA[8] + pRot[2][2] * 3;
                        VEC_Normalize(pRot[2], pRot[2]);
                    } else {
                        int cross0, cross1, cross2;
                        cross0 = (pRot[0][1] * pRot[1][2] - pRot[0][2] * pRot[1][1]) >> 12;
                        cross1 = (pRot[0][2] * pRot[1][0] - pRot[0][0] * pRot[1][2]) >> 12;
                        cross2 = (pRot[0][0] * pRot[1][1] - pRot[0][1] * pRot[1][0]) >> 12;
                        pRot[2][0] = cross0;
                        pRot[2][1] = cross1;
                        pRot[2][2] = cross2;
                    }
                    return;
                }
                idxBlend = idx >> 2;
                goto two;
            }
            idx = idx >> 2;
        }
    }
    goto plain;

two:
    needCross = 0;
    needCross |= NNSi_G3dAnmDecodeRotKey(&pRot[0][0], (s16 *)((u8 *)pJntAnm + ofsRot3), (s16 *)((u8 *)pJntAnm + ofsRot9), ((u16 *)pArray)[idxBlend]);
    needCross |= NNSi_G3dAnmDecodeRotKey(rotB, (s16 *)((u8 *)pJntAnm + ofsRot3), (s16 *)((u8 *)pJntAnm + ofsRot9), ((u16 *)pArray + idxBlend)[1]);
    pRot[0][0] = pRot[0][0] + rotB[0];
    pRot[0][1] = pRot[0][1] + rotB[1];
    pRot[0][2] = pRot[0][2] + rotB[2];
    pRot[1][0] = pRot[1][0] + rotB[3];
    pRot[1][1] = pRot[1][1] + rotB[4];
    pRot[1][2] = pRot[1][2] + rotB[5];
    VEC_Normalize(pRot[0], pRot[0]);
    VEC_Normalize(pRot[1], pRot[1]);
    if (needCross == 0) {
        pRot[2][0] = pRot[2][0] + rotB[6];
        pRot[2][1] = pRot[2][1] + rotB[7];
        pRot[2][2] = pRot[2][2] + rotB[8];
        VEC_Normalize(pRot[2], pRot[2]);
    } else {
        int cross0, cross1, cross2;
        cross0 = (pRot[0][1] * pRot[1][2] - pRot[0][2] * pRot[1][1]) >> 12;
        cross1 = (pRot[0][2] * pRot[1][0] - pRot[0][0] * pRot[1][2]) >> 12;
        cross2 = (pRot[0][0] * pRot[1][1] - pRot[0][1] * pRot[1][0]) >> 12;
        pRot[2][0] = cross0;
        pRot[2][1] = cross1;
        pRot[2][2] = cross2;
    }
    return;

plain:
    if (NNSi_G3dAnmDecodeRotKey(&pRot[0][0], (s16 *)((u8 *)pJntAnm + ofsRot3), (s16 *)((u8 *)pJntAnm + ofsRot9), ((u16 *)pArray)[idx]) != 0) {
        int cross0, cross1, cross2;
        cross0 = (pRot[0][1] * pRot[1][2] - pRot[0][2] * pRot[1][1]) >> 12;
        cross1 = (pRot[0][2] * pRot[1][0] - pRot[0][0] * pRot[1][2]) >> 12;
        cross2 = (pRot[0][0] * pRot[1][1] - pRot[0][1] * pRot[1][0]) >> 12;
        pRot[2][0] = cross0;
        pRot[2][1] = cross1;
        pRot[2][2] = cross2;
    } else {
        VEC_Normalize(pRot[2], pRot[2]);
    }
}

/*
 * Rotation key lerp (NitroSystem getRotDataEx lerp form): the NNSi_G3dAnmGetScaleDataEx
 * flag cascade, keys decoded by NNSi_G3dAnmDecodeRotKey from the two key arrays of the
 * resource (rot3 and rot9), rows 0 and 1 lerped and VEC_Normalize'd, row 2
 * rebuilt by the cross product when either decode returned 1, else lerped
 * and normalised.  Same C under ../2.0/sp2p2 (the family pin,
 * docs/FRONTEND-PINS.md NNSi_G3dAnmGetTransData row); dsi/1.1p1 is 824 bytes against
 * 836.
 *
 * The two key arrays are POINTER locals computed once at the top, as
 * NitroSystem spells pArrayRot3 / pArrayRot9, not u32 offsets added at each
 * call (the compiler still re-forms the address at every call site, so the
 * bytes do not show the difference), plus the declaration order below.
 */
void NNSi_G3dAnmGetRotDataEx(fx32 (*pRot)[3], int frame, const NNSG3dJntAnmRInfo *pInfo, const NNSG3dResJntAnm *pJntAnm)
{
    int idx;
    u32 needCross;
    s16 *pArrayRot3;
    u32 idxNext;
    int frac;
    u32 mul;
    u32 lastInterp;
    u32 info;
    u8 *pArray;
    s16 *pArrayRot9;
    int rotA[9];
    int rotB[9];

    pArray = (u8 *)pJntAnm + pInfo->offset;
    idx = frame >> 12;
    pArrayRot3 = (s16 *)((u8 *)pJntAnm + pJntAnm->ofsRot3);
    pArrayRot9 = (s16 *)((u8 *)pJntAnm + pJntAnm->ofsRot9);
    info = pInfo->info;

    if ((int)(pJntAnm->numFrame - 1) != (frame >> 12)) goto general;

    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) != 0) {
        if ((info & NNS_G3D_JNTANM_SINFO_STEP_2) != 0) {
            idx = (idx & 1) + ((u32)idx >> 1);
        } else {
            idx = (idx & 3) + ((u32)idx >> 2);
        }
    }
    if ((pJntAnm->flag & NNS_G3D_JNTANM_FLAG_END_TO_START_INTERP) != 0) {
        idxNext = 0;
        goto last;
    }
    if (NNSi_G3dAnmDecodeRotKey(&pRot[0][0], pArrayRot3, pArrayRot9, ((u16 *)pArray)[idx]) != 0) {
        {
            int cross0, cross1, cross2;
            cross0 = (pRot[0][1] * pRot[1][2] - pRot[0][2] * pRot[1][1]) >> 12;
            cross1 = (pRot[0][2] * pRot[1][0] - pRot[0][0] * pRot[1][2]) >> 12;
            cross2 = (pRot[0][0] * pRot[1][1] - pRot[0][1] * pRot[1][0]) >> 12;
            pRot[2][0] = cross0;
            pRot[2][1] = cross1;
            pRot[2][2] = cross2;
        }
    } else {
        VEC_Normalize(pRot[2], pRot[2]);
    }
    return;

general:
    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) == 0) goto next;
    {
        u32 lastInterpField = info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK;
        lastInterp = lastInterpField >> 16;
    }
    if ((info & NNS_G3D_JNTANM_SINFO_STEP_2) != 0) {
        if ((u32)idx >= lastInterp) {
            idx = lastInterp >> 1;
            idxNext = idx + 1;
            goto last;
        }
        idx = (u32)idx >> 1;
        idxNext = idx + 1;
        frac = frame & (int)(NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT);
        mul = 2;
        goto lerp;
    }
    if ((u32)idx >= lastInterp) {
        idx = (idx & 3) + ((u32)idx >> 2);
        idxNext = idx + 1;
        goto last;
    }
    idx = (u32)idx >> 2;
    idxNext = idx + 1;
    frac = frame & 0x3fff;
    mul = 4;
    goto lerp;
next:
    idxNext = idx + 1;
last:
    frac = frame & 0xfff;
    mul = 1;
lerp:
    needCross = 0;
    needCross |= NNSi_G3dAnmDecodeRotKey(rotA, pArrayRot3, pArrayRot9, ((u16 *)pArray)[idx]);
    needCross |= NNSi_G3dAnmDecodeRotKey(rotB, pArrayRot3, pArrayRot9, ((u16 *)pArray)[idxNext]);
    pRot[0][0] = rotA[0] * (int)mul + (((rotB[0] - rotA[0]) * frac) >> 12);
    pRot[0][1] = rotA[1] * (int)mul + (((rotB[1] - rotA[1]) * frac) >> 12);
    pRot[0][2] = rotA[2] * (int)mul + (((rotB[2] - rotA[2]) * frac) >> 12);
    pRot[1][0] = rotA[3] * (int)mul + (((rotB[3] - rotA[3]) * frac) >> 12);
    pRot[1][1] = rotA[4] * (int)mul + (((rotB[4] - rotA[4]) * frac) >> 12);
    pRot[1][2] = rotA[5] * (int)mul + (((rotB[5] - rotA[5]) * frac) >> 12);
    VEC_Normalize(pRot[0], pRot[0]);
    VEC_Normalize(pRot[1], pRot[1]);
    if (needCross == 0) {
        pRot[2][0] = rotA[6] * (int)mul + (((rotB[6] - rotA[6]) * frac) >> 12);
        pRot[2][1] = rotA[7] * (int)mul + (((rotB[7] - rotA[7]) * frac) >> 12);
        pRot[2][2] = rotA[8] * (int)mul + (((rotB[8] - rotA[8]) * frac) >> 12);
        VEC_Normalize(pRot[2], pRot[2]);
    } else {
            int cross0, cross1, cross2;
            cross0 = (pRot[0][1] * pRot[1][2] - pRot[0][2] * pRot[1][1]) >> 12;
            cross1 = (pRot[0][2] * pRot[1][0] - pRot[0][0] * pRot[1][2]) >> 12;
            cross2 = (pRot[0][0] * pRot[1][1] - pRot[0][1] * pRot[1][0]) >> 12;
            pRot[2][0] = cross0;
            pRot[2][1] = cross1;
            pRot[2][2] = cross2;
        }
}

/*
 * Decodes one packed rotation key into a 3x3 matrix (NitroSystem getRotDataEx).
 * data bit 15 set: a pivot form -- clear the matrix, put +-1.0 (bit 4 of the
 * entry's first word) on the pivot slot (low nibble) and the two remaining
 * values (negated by bits 5 and 6) on the slots the four pivot-column tables
 * name; returns 0.  Bit 15 clear: five quantised s16 values (>> 3 each) whose
 * low three bits pack a 13-bit sixth value (row 1 col 2, sign-extended);
 * returns 1, and the caller rebuilds row 2 by the cross product.
 *
 * Two levers:
 *   - the pivot-column tables are `const`: mwcc then knows a store through
 *     `pRot` cannot modify them and hoists each column's `ldrb` above the
 *     earlier stores, which is the image's order (load 1998, store pRot[k],
 *     load 1999, store, store).  Non-const, the loads stay after the stores
 *     (32 bytes out);
 *   - the packed arm is written row by row (load, store >> 3, fold into
 *     packed), not as five loads followed by the packing chain.
 * The whole-matrix clear is written highest element first.
 */
int NNSi_G3dAnmDecodeRotKey(fx32 *pRot, const s16 *pArrayRot3, const s16 *pArrayRot9, u32 data)
{
    if (data & 0x8000) {
        u32 idx;
        const s16 *pRow;
        int head, valU, valV, pivotIdx;

        pRot[8] = 0;
        pRot[7] = 0;
        pRot[6] = 0;
        pRot[5] = 0;
        pRot[4] = 0;
        pRot[3] = 0;
        pRot[2] = 0;
        pRot[1] = 0;
        pRot[0] = 0;
        idx = (data & 0x7fff) * 3;
        pRow = pArrayRot3 + idx;
        head = pArrayRot3[idx];
        valU = pRow[1];
        valV = pRow[2];
        pivotIdx = head & 0xf;
        pRot[pivotIdx] = (head & 0x10) ? -0x1000 : 0x1000;
        pRot[g_020A1998[pivotIdx].index] = valU;
        pRot[g_020A1999[pivotIdx].index] = valV;
        pRot[g_020A199A[pivotIdx].index] = (pRow[0] & 0x20) ? -valV : valV;
        pRot[g_020A199B[pivotIdx].index] = (pRow[0] & 0x40) ? -valU : valU;
        return 0;
    } else {
        u32 idx = (data & 0x7fff) * 5;
        const s16 *pRow = pArrayRot9 + idx;
        s16 q0, q1, q2, q3, q4, packed;

        q4 = pRow[4];
        pRot[4] = q4 >> 3;
        packed = q4 & 7;
        q0 = pArrayRot9[idx];
        pRot[0] = q0 >> 3;
        packed = (q0 & 7) | (packed << 3);
        q1 = pRow[1];
        pRot[1] = q1 >> 3;
        packed = (q1 & 7) | (packed << 3);
        q2 = pRow[2];
        pRot[2] = q2 >> 3;
        packed = (q2 & 7) | (packed << 3);
        q3 = pRow[3];
        pRot[3] = q3 >> 3;
        packed = (q3 & 7) | (packed << 3);
        pRot[5] = (packed << 19) >> 19;
        return 1;
    }
}

/*
 * RGB555 color track sampler of the material animation: one track descriptor
 * word (bit 29 = inline value in the low half, bits 31:30 = key stride, bits
 * 28:16 = last interpolated frame, bits 15:0 = key offset from the resource).
 * The two-key mean and the 3:1 blend are done per channel group with the
 * 0x7C1F (red+blue) and 0x03E0 (green) masks, so one add serves two
 * channels.  NNSi_G3dAnmCalcNsBma calls it four times (0x0207048C..0x020704E0).
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): the
 * image keeps `cmp r2, r3` / `bls 0x02070168` at 0x02070150 / 0x02070154
 * over the four-instruction clamp return (`bic r1, r3, #1` / `add r0, r0,
 * r1` / `ldrh r0, [r0, #2]` / `bx lr`); dsi/1.1p1 -O4,p predicates it to
 * bichi/addhi/ldrhhi/bxhi and the same C is 352 bytes against 360, 246
 * concrete bytes out.  Under ../2.0/sp2 the same C is 360 bytes, 0 mismatches.
 *
 * Source levers: the shared `two:` block takes its own index keyIdx (not
 * frameIdx), as in NNSi_G3dAnmGetTexSRTRotData; the 3:1 arm's index pair is a fresh pair
 * (keyIdx, keyIdxNext), not frameIdx rewritten in place; and the 3:1 arm
 * reads its second key pKeys[keyIdxNext] directly in both channel sums
 * rather than through a local.
 */
u16 NNSi_G3dAnmGetMatColorData(const u8 *pRes, u32 info, u32 frameIdx)
{
    const u16 *pKeys;
    u32 lastInterp;
    u32 keyIdx;
    u32 key0, key1, green, redBlue;

    if (info & NNS_G3D_ANMTRACK_CONST)
        return (u16)info;

    pKeys = (const u16 *)(pRes + (u16)info);

    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) == 0)
        return pKeys[frameIdx];

    lastInterp = (info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT;
    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
        if (frameIdx & 1) {
            if (frameIdx > lastInterp)
                return (pKeys + (lastInterp >> 1))[1];
            keyIdx = frameIdx >> 1;
            goto two;
        }
        return pKeys[frameIdx >> 1];
    } else {
        u32 rem = frameIdx & 3;
        if (rem != 0) {
            if (frameIdx > lastInterp)
                return (pKeys + (lastInterp >> 2))[rem];
            if (frameIdx & 1) {
                u32 keyIdxNext;
                if (frameIdx & 2) { keyIdxNext = frameIdx >> 2; keyIdx = keyIdxNext + 1; }
                else { keyIdx = frameIdx >> 2; keyIdxNext = keyIdx + 1; }
                key0 = pKeys[keyIdx];
                green = ((key0 & 0x3e0) * 3 + (pKeys[keyIdxNext] & 0x3e0)) >> 2;
                redBlue = ((key0 & 0x7c1f) * 3 + (pKeys[keyIdxNext] & 0x7c1f)) >> 2;
                return (u16)((redBlue & 0x7c1f) | (green & 0x3e0));
            }
            keyIdx = frameIdx >> 2;
            goto two;
        }
        return pKeys[frameIdx >> 2];
    }

two:
    key0 = pKeys[keyIdx];
    key1 = (pKeys + keyIdx)[1];
    green = ((key0 & 0x3e0) + (key1 & 0x3e0)) >> 1;
    redBlue = ((key0 & 0x7c1f) + (key1 & 0x7c1f)) >> 1;
    return (u16)((redBlue & 0x7c1f) | (green & 0x3e0));
}

/*
 * u8 key track sampler of the material animation (same descriptor word as
 * NNSi_G3dAnmGetMatColorData: bit 29 = inline value, returned as its low half; bits 31:30
 * = full / half / quarter key stride; bits 28:16 = last interpolated frame;
 * bits 15:0 = the key block's offset from the resource).  Its one caller,
 * NNSi_G3dAnmCalcNsBma at 0x0207050C, shifts the result into bits 16..20 of the
 * polygon attribute word (the polygon alpha), hence the u16 return.
 *
 * Front end: neutral between front ends: the same C is EXACT under dsi/1.1p1
 * as well, so it carries no tell of its own.
 */
u16 NNSi_G3dAnmGetMatAlphaData(const u8 *pRes, u32 info, u32 frameIdx)
{
    const u8 *pKeys;
    u32 lastInterp;
    u32 keyIdx;
    u32 key0, key1;

    if (info & NNS_G3D_ANMTRACK_CONST)
        return (u16)info;

    pKeys = pRes + (u16)info;

    if ((info & NNS_G3D_JNTANM_SINFO_STEP_MASK) == 0)
        return pKeys[frameIdx];

    lastInterp = (info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT;
    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
        if (frameIdx & 1) {
            if (frameIdx > lastInterp)
                return (pKeys + (lastInterp >> 1))[1];
            frameIdx = frameIdx >> 1;
            key0 = pKeys[frameIdx];
            key1 = (pKeys + frameIdx)[1];
            return (u16)((key0 + key1) >> 1);
        }
        return pKeys[frameIdx >> 1];
    } else {
        u32 rem = frameIdx & 3;
        if (rem != 0) {
            if (frameIdx > lastInterp)
                return (pKeys + (lastInterp >> 2))[rem];
            if (frameIdx & 1) {
                if (frameIdx & 2) { frameIdx = frameIdx >> 2; keyIdx = frameIdx + 1; }
                else { keyIdx = frameIdx >> 2; frameIdx = keyIdx + 1; }
                key0 = pKeys[keyIdx];
                key1 = pKeys[frameIdx];
                key0 *= 3;
                key0 += key1;
                return (u16)(key0 >> 2);
            }
            frameIdx = frameIdx >> 2;
            key0 = pKeys[frameIdx];
            key1 = (pKeys + frameIdx)[1];
            return (u16)((key0 + key1) >> 1);
        }
        return pKeys[frameIdx >> 2];
    }
}

static inline const NNSG3dResName *getAnmDictName(const NNSG3dResMatAnm *pAnm, u32 idx)
{
    const u8 *tbl = (const u8 *)pAnm + 8;
    if (tbl != 0 && idx < ((const volatile NNSG3dResMatAnm *)pAnm)->dict.numEntry) {
        const u8 *q = tbl + pAnm->dict.ofsEntry;
        return (const NNSG3dResName *)(q + ((const NNSG3dResDictEntryHdr *)q)->ofsName + idx * 0x10);
    }
    return 0;
}

static inline s32 lookupMatIdx(const NNSG3dResMat *pMat, const NNSG3dResName *pName)
{
    if (pMat != 0)
        return NNS_G3dGetResDictIdxByName(&pMat->dict, pName);
    return -1;
}

/*
 * Material color animation binder (NitroSystem NNSi_G3dAnmObjInitNsBma):
 * seeds the animation object's sampling function from the handler table word
 * at data_020A8230 (= &NNSi_G3dAnmCalcNsBma), copies the material count, clears the
 * halfword map at mapData, then for each of the animation's dictionary
 * entries resolves its name in the model's material dictionary through
 * NNS_G3dGetResDictIdxByName and stores `i | 0x100` at the returned slot.
 *
 * The body is two INLINE HELPERS, a name-entry accessor getAnmDictName(pAnm,
 * i) (entries at a 0x10 stride that the compiler strength-reduces into the r8
 * step) and a guarded lookup lookupMatIdx(pMat, pName) returning -1 when the
 * model has no material block.  Written that way the function is size-exact
 * under ../2.0/sp2 and the prologue window is right (the separate `mov r0,#0`
 * for the clear's fill and `mov r6,#0` for the counter is the pin's "kept
 * constants" tell); dsi/1.1p1 on the same C is 204 bytes with an 8-register
 * push.  The last r6/r7 swap is declaration order: `u32 i;` before the
 * material block pointer.  The animation's entry count is read through a
 * volatile view (216 bytes without it).
 */
void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *pAnmObj, const NNSG3dResMatAnm *pMatAnm, const NNSG3dResMdl *pMdl)
{
    u32 i;
    const NNSG3dResMat *pMat;

    if (pMdl != 0 && pMdl->ofsMat != 0)
        pMat = (const NNSG3dResMat *)((const u8 *)pMdl + pMdl->ofsMat);
    else
        pMat = 0;

    pAnmObj->funcAnm = data_020A8230;
    pAnmObj->numMapData = pMdl->info.numMat;
    MIi_CpuClear16(0, pAnmObj->mapData, (u32)pAnmObj->numMapData * 2);

    for (i = 0; i < ((const volatile NNSG3dResMatAnm *)pMatAnm)->dict.numEntry; i++) {
        s32 slot = lookupMatIdx(pMat, getAnmDictName(pMatAnm, i));
        if (slot >= 0)
            pAnmObj->mapData[slot] = (u16)(i | NNS_G3D_ANMOBJ_MAPDATA_EXIST);
    }
}

static inline const NNSG3dResMatAnmData *getMatAnmData(const NNSG3dResMatAnm *pMatAnm, u32 idx)
{
    const u8 *tbl = (const u8 *)pMatAnm + 8;
    if (tbl != 0 && idx < pMatAnm->dict.numEntry) {
        const u8 *p = tbl + pMatAnm->dict.ofsEntry;
        return (const NNSG3dResMatAnmData *)(((const NNSG3dResDictEntryHdr *)p)->sizeUnit * idx + (u32)(p + 4));
    }
    return 0;
}

/*
 * Material color animation sampling function (NitroSystem
 * NNSi_G3dAnmCalcNsBma): resolves the material's track record through the
 * dictionary at +8 (inlined getMatAnmData, the same body NNSi_G3dAnmGetTexSRTData spells
 * out), samples four color tracks with NNSi_G3dAnmGetMatColorData into two packed words
 * (low | high << 16, each keeping its own bit 15 as a flag), and the alpha
 * track with NNSi_G3dAnmGetMatAlphaData into bits 16-20 of the polygon attribute.  The
 * frame is pAnmObj->frame >> 12 (20.12 fixed).
 *
 * Levers: the index is narrowed at the call into a u32-parameter inline
 * helper (`getMatAnmData(pMatAnm, (u16)dataIdx)`), which gives the image's
 * unsigned `cmp numEntry, idx, lsr #16` / `bls`; a u16 parameter compares
 * signed.  The frame local is u32 (the callee takes u32), the shift on the
 * s32 field stays `asr`.  Byte-identical under dsi/1.1p1 and ../2.0/sp2.
 */
void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx)
{
    const NNSG3dResMatAnm *pMatAnm = (const NNSG3dResMatAnm *)pAnmObj->resAnm;
    u32 frame = pAnmObj->frame >> 12;
    const NNSG3dResMatAnmData *pData;
    u32 a, b;

    pData = getMatAnmData(pMatAnm, (u16)dataIdx);

    a = NNSi_G3dAnmGetMatColorData((const u8 *)pMatAnm, pData->diffuse, frame);
    b = NNSi_G3dAnmGetMatColorData((const u8 *)pMatAnm, pData->ambient, frame);
    pResult->prmMatColor0 = a | (b << 16) | (((pResult->prmMatColor0 & 0x8000) ? 1 : 0) << 15);

    a = NNSi_G3dAnmGetMatColorData((const u8 *)pMatAnm, pData->emission, frame);
    b = NNSi_G3dAnmGetMatColorData((const u8 *)pMatAnm, pData->specular, frame);
    pResult->prmMatColor1 = b | (a << 16) | (((pResult->prmMatColor1 & 0x8000) ? 1 : 0) << 15);

    a = NNSi_G3dAnmGetMatAlphaData((const u8 *)pMatAnm, pData->polygonAlpha, frame);
    pResult->prmPolygonAttr = (pResult->prmPolygonAttr & ~0x1F0000) | (a << 16);
}

/*
 * Scalar key track sampler of the texture SRT animation (NitroSystem
 * getTexSRTData family; the callee NNSi_G3dAnmGetTexSRTData uses for the two scale
 * tracks and the two translation tracks).  `info` is the track descriptor
 * word: bit 29 means the value is inline (return `offset` unchanged), bits
 * 31:30 select the key stride (full / half / quarter), bit 28 selects s16
 * keys over u32 keys, and bits 15:0 are the last interpolated frame.  A
 * half-stride odd index averages the two neighbouring keys; a quarter-stride
 * index is either that average or the 3:1 weighted average, depending on the
 * low two bits.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): under
 * the project default dsi/1.1p1 -O4,p this body is 4 bytes LONG, because
 * 1.1p1 keeps the `two:` block's u32 arm as a branch where the image
 * predicates it.  Under ../2.0/sp2 the same C is byte-exact.
 *
 * Three source levers, all measured, all needed:
 *   1. the quad tail spelled as three statements (`v0 *= 3; v0 += v1;
 *      return v0 >> 2;`), not as the single expression `(v0*3 + v1) >> 2`,
 *      which normalises the accumulate into `add r0, r1, r0`;
 *   2. in the `two:` block the s16 (bit-28 set) arm is written FIRST and the
 *      u32 arm as the `else`.  Writing the u32 arm first emits the two
 *      trailing s16 address computations in the other order
 *      (`lsl` before `add`), which no respelling of that arm reaches;
 *   3. the u32 arm's pointer pWord is computed INSIDE that arm.  Hoisting it
 *      above the `if` emits the `add` unpredicated where the image has
 *      `addeq`.
 */
s32 NNSi_G3dAnmGetTexSRTScalarData(const void *pRes, u32 info, u32 offset, u32 frameIdx)
{
    u32 lastInterp;
    u32 keyIdx;
    s32 key0, key1;
    s16 *pS16;
    u32 *pWord;
    const u32 *pKeys;

    if (info & NNS_G3D_ANMTRACK_CONST)
        return offset;

    pKeys = (const u32 *)((int)pRes + offset);

    if (info & NNS_G3D_JNTANM_SINFO_STEP_MASK) {
        lastInterp = info & NNS_G3D_ANMTRACK_COUNT_MASK;
        if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
            if (frameIdx & 1) {
                if (frameIdx > lastInterp) {
                    frameIdx = (lastInterp >> 1) + 1;
                    goto plain;
                }
                frameIdx = frameIdx >> 1;
                goto two;
            }
            frameIdx = frameIdx >> 1;
            goto plain;
        } else {
            u32 rem = frameIdx & 3;
            if (rem != 0) {
                if (frameIdx > lastInterp) { frameIdx = rem + (lastInterp >> 2); goto plain; }
                if (frameIdx & 1) {
                    if (frameIdx & 2) { frameIdx = frameIdx >> 2; keyIdx = frameIdx + 1; }
                    else { keyIdx = frameIdx >> 2; frameIdx = keyIdx + 1; }
                    if (!(info & NNS_G3D_ANMTRACK_FX16)) {
                        key0 = pKeys[keyIdx];
                        key1 = pKeys[frameIdx];
                        goto quad;
                    }
                    pS16 = (s16 *)pKeys;
                    key0 = pS16[keyIdx];
                    key1 = pS16[frameIdx];
                quad:
                    key0 *= 3;
                    key0 += key1;
                    return key0 >> 2;
                }
                frameIdx = frameIdx >> 2;
                goto two;
            }
            frameIdx = frameIdx >> 2;
        }
    }

plain:
    if (!(info & NNS_G3D_ANMTRACK_FX16))
        return pKeys[frameIdx];
    return ((s16 *)pKeys)[frameIdx];

two:
    if (info & NNS_G3D_ANMTRACK_FX16) {
        s16 *pS16Key = (s16 *)pKeys + frameIdx;
        u32 byteOfs = frameIdx << 1;
        key0 = *(s16 *)((char *)pKeys + byteOfs);
        key1 = pS16Key[1];
    } else {
        pWord = (u32 *)pKeys + frameIdx;
        key0 = pKeys[frameIdx];
        key1 = pWord[1];
    }
    return (key0 + key1) >> 1;
}

/*
 * Rotation key track sampler of the texture SRT animation: the exact sibling
 * of NNSi_G3dAnmGetTexSRTScalarData (the same flag cascade, word for word) but every key is a
 * PAIR of s16 (sin, cos) packed into one word, and the result is the two
 * interpolated components packed back into one u32.  NNSi_G3dAnmGetTexSRTData uses it
 * for the rotation track, where NNSi_G3dAnmGetTexSRTScalarData serves the scalar scale and
 * translation tracks.  `info` bit 29 = inline value, bits 31:30 = key stride,
 * bits 15:0 = last interpolated frame; unlike NNSi_G3dAnmGetTexSRTScalarData there is no
 * bit-28 width selector, because the key type is always the s16 pair.
 *
 * Per-file compiler pin ../2.0/sp2, not the project default.
 *
 * Three source levers, all measured:
 *   1. in BOTH tail blocks the value read by byte-offset off `pKeys` must be
 *      read and folded before the pointer local is created, or the four live
 *      s16 plus the pointer plus `pKeys` want a sixth register and the leaf
 *      grows a `push {r3, lr}` the image does not have (the image is a pure
 *      leaf with four bare `bx lr`);
 *   2. the low half of the packed result is `((u32)(x >> k) & 0xffff)`, a
 *      shift and a mask.  Spelling it as the double shift
 *      `((u32)(x << (16-k)) >> 16)` emits the two halves' adds in the other
 *      order and exchanges r0 and r1 through all five packing instructions;
 *   3. in the `two:` block the high half's sum must go to a FRESH local
 *      (`s32 sum = a + b;`) rather than accumulating into `a` (`a += b;`).
 *      The compound form keeps `a` live past its last read, so its sum lands
 *      in r1 and the low half's sum is then forced out of r0; letting `a` die
 *      at the sum puts both adds in r0 exactly as the image has them.
 *      The quad block already has this shape for free, because its `*3`
 *      weighting means each half is folded as it is read.
 */
int NNSi_G3dAnmGetTexSRTRotData(const void *pRes, u32 info, u32 offset, u32 frameIdx)
{
    u32 lastInterp;
    u32 keyIdx;
    const u32 *pKeys;

    if (info & NNS_G3D_ANMTRACK_CONST)
        return offset;

    pKeys = (const u32 *)((int)pRes + offset);

    if (info & NNS_G3D_JNTANM_SINFO_STEP_MASK) {
        lastInterp = info & NNS_G3D_ANMTRACK_COUNT_MASK;
        if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
            if (frameIdx & 1) {
                if (frameIdx > lastInterp) { frameIdx = (lastInterp >> 1) + 1; goto plain; }
                keyIdx = frameIdx >> 1;
                goto two;
            }
            frameIdx = frameIdx >> 1;
            goto plain;
        } else {
            u32 rem = frameIdx & 3;
            if (rem != 0) {
                if (frameIdx > lastInterp) { frameIdx = rem + (lastInterp >> 2); goto plain; }
                if (frameIdx & 1) {
                    s32 sinHi, cosHi, sinLo, cosLo;
                    if (frameIdx & 2) { frameIdx = frameIdx >> 2; keyIdx = frameIdx + 1; }
                    else              { keyIdx = frameIdx >> 2; frameIdx = keyIdx + 1; }
                    sinLo = *(s16 *)((char *)pKeys + (keyIdx << 2));
                    cosLo = *(s16 *)((char *)pKeys + (frameIdx << 2));
                    sinLo *= 3;
                    sinLo += cosLo;
                    sinHi = ((s16 *)(pKeys + keyIdx))[1];
                    cosHi = ((s16 *)(pKeys + frameIdx))[1];
                    sinHi *= 3;
                    sinHi += cosHi;
                    return ((u32)(sinLo >> 2) & 0xffff) | (u32)((sinHi >> 2) << 16);
                }
                keyIdx = frameIdx >> 2;
                goto two;
            }
            frameIdx = frameIdx >> 2;
        }
    }

plain:
    return pKeys[frameIdx];

two:
    {
        s32 sinLo = *(s16 *)((char *)pKeys + (keyIdx << 2));
        s16 *pPair = (s16 *)(pKeys + keyIdx);
        s32 sinHi = pPair[1];
        s32 cosHi = pPair[3];
        s32 cosLo = pPair[2];
        s32 sum = sinHi + cosHi;
        sinLo += cosLo;
        return ((u32)(sinLo >> 1) & 0xffff) | (u32)((sum >> 1) << 16);
    }
}

/*
 * Samples one texture SRT animation entry's five tracks (two scale, one
 * rotation pair, two translation) out of the per-material track record,
 * writing the results into the material result and maintaining the three
 * "identity" bits of its flag word (scale one, rotation zero, translation
 * zero).
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md). Under
 * the pinned default dsi/1.1p1 -O4,p this body is 4 bytes short at +0x00A0;
 * under ../2.0/sp2 the same C is 256 bytes with ZERO concrete mismatches.
 * The one source change was the order of the two translation stores.
 */
void NNSi_G3dAnmGetTexSRTData(const NNSG3dResTexSRTAnm *pSrtAnm, u32 dataIdx, u32 frame, NNSG3dMatAnmResult *pResult)
{
    const u8 *tbl;
    u32 resultFlag;
    s32 a, b;
    const NNSG3dResTexSRTAnmData *pData;

    tbl = (const u8 *)pSrtAnm + 8;
    if (tbl != 0 && dataIdx < pSrtAnm->dict.numEntry) {
        const u8 *p = tbl + pSrtAnm->dict.ofsEntry;
        pData = (const NNSG3dResTexSRTAnmData *)(((const NNSG3dResDictEntryHdr *)p)->sizeUnit * dataIdx + (u32)(p + 4));
    } else {
        pData = 0;
    }

    resultFlag = pResult->flag;

    a = NNSi_G3dAnmGetTexSRTScalarData(pSrtAnm, pData->transS.info, pData->transS.offset, frame);
    b = NNSi_G3dAnmGetTexSRTScalarData(pSrtAnm, pData->transT.info, pData->transT.offset, frame);
    if (a == 0 && b == 0) {
        resultFlag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO;
    } else {
        pResult->transS = (u32)a;
        pResult->transT = (u32)b;
        resultFlag &= ~4u;
    }

    a = NNSi_G3dAnmGetTexSRTRotData(pSrtAnm, pData->rot.info, pData->rot.offset, frame);
    if (a == 0x10000000) {
        resultFlag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO;
        goto rot_done;
    }
    {
        u32 rv = (u32)a;
        pResult->sinR = (u16)rv;
        rv >>= 16;
        pResult->cosR = (u16)rv;
    }
    resultFlag &= ~2u;
rot_done:
    ;

    a = NNSi_G3dAnmGetTexSRTScalarData(pSrtAnm, pData->scaleS.info, pData->scaleS.offset, frame);
    b = NNSi_G3dAnmGetTexSRTScalarData(pSrtAnm, pData->scaleT.info, pData->scaleT.offset, frame);
    if (a == 0x1000 && b == 0x1000) {
        resultFlag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE;
    } else {
        pResult->scaleS = a;
        pResult->scaleT = b;
        resultFlag &= ~1u;
    }

    pResult->flag = resultFlag;
}

/*
 * Twin of NNSi_G3dAnmObjInitNsBma, instruction for instruction (NitroSystem
 * NNSi_G3dAnmObjInitNsBta): the same binder, differing only in the
 * handler-table word that seeds funcAnm (data_020A8228, which holds
 * &NNSi_G3dAnmCalcNsBta, where NNSi_G3dAnmObjInitNsBma reads data_020A8230 = &NNSi_G3dAnmCalcNsBma).
 * The table at 0x020A8220.. pairs each binder (0x020A8244.., tagged by a
 * 4-char kind word) with the per-frame sampler it installs.  Same levers as
 * NNSi_G3dAnmObjInitNsBma: the getAnmDictName/lookupMatIdx inline helpers, a volatile
 * entry count, `i` declared before the material block, and the ../2.0/sp2 pin.
 */
void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *pAnmObj, const NNSG3dResTexSRTAnm *pSrtAnm, const NNSG3dResMdl *pMdl)
{
    u32 i;
    const NNSG3dResMat *pMat;

    if (pMdl != 0 && pMdl->ofsMat != 0)
        pMat = (const NNSG3dResMat *)((const u8 *)pMdl + pMdl->ofsMat);
    else
        pMat = 0;

    pAnmObj->funcAnm = data_020A8228;
    pAnmObj->numMapData = pMdl->info.numMat;
    MIi_CpuClear16(0, pAnmObj->mapData, (u32)pAnmObj->numMapData * 2);

    for (i = 0; i < ((const volatile NNSG3dResTexSRTAnm *)pSrtAnm)->dict.numEntry; i++) {
        s32 slot = lookupMatIdx(pMat, getAnmDictName((const NNSG3dResMatAnm *)pSrtAnm, i));
        if (slot >= 0)
            pAnmObj->mapData[slot] = (u16)(i | NNS_G3D_ANMOBJ_MAPDATA_EXIST);
    }
}

/*
 * Texture SRT animation sampling function (NitroSystem NNSi_G3dAnmCalcNsBta).
 *
 * Both result fields the tail touches are read-modify-write after the call;
 * the sampler at 0x02070730 is forwarded the animation object's frame index
 * (frame >> 12, arithmetic) and its resource, then the two-bit TexGen field
 * of the TEXIMAGE_PARAM word is rewritten to 0b01 (texcoord source) and bit 3
 * of the flag word (texture matrix set) is set.
 */
void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx)
{
    NNSi_G3dAnmGetTexSRTData((const NNSG3dResTexSRTAnm *)pAnmObj->resAnm, (u16)dataIdx, pAnmObj->frame >> 12, pResult);
    pResult->prmTexImage = (pResult->prmTexImage & ~0xc0000000u) | 0x40000000u;
    pResult->flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET;
}

static inline const NNSG3dResName *getTexPatDictName(const NNSG3dResTexPatAnm *pPatAnm, u32 idx)
{
    const u8 *tbl = (const u8 *)pPatAnm + 0xc;
    if (tbl != 0 && idx < ((const volatile NNSG3dResTexPatAnm *)pPatAnm)->dict.numEntry) {
        const u8 *q = tbl + pPatAnm->dict.ofsEntry;
        return (const NNSG3dResName *)(q + ((const NNSG3dResDictEntryHdr *)q)->ofsName + idx * 0x10);
    }
    return 0;
}

/*
 * Third member of the NNSi_G3dAnmObjInitNsBma / NNSi_G3dAnmObjInitNsBta binder set
 * (NitroSystem NNSi_G3dAnmObjInitNsBtp).  Same body with two differences: it
 * also records the source resource in the animation object (the u32 store is
 * why the clear's size re-reads numMapData from memory: the store may alias
 * it), and its name dictionary sits at +0xc of the resource instead of +8.
 * Seeds funcAnm from data_020A822C (= &NNSi_G3dAnmCalcNsBtp).  Same levers:
 * getTexPatDictName/lookupMatIdx inline helpers, a volatile entry count, `i`
 * declared before the material block, ../2.0/sp2.
 */
void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *pAnmObj, const NNSG3dResTexPatAnm *pPatAnm, const NNSG3dResMdl *pMdl)
{
    u32 i;
    const NNSG3dResMat *pMat;

    if (pMdl != 0 && pMdl->ofsMat != 0)
        pMat = (const NNSG3dResMat *)((const u8 *)pMdl + pMdl->ofsMat);
    else
        pMat = 0;

    pAnmObj->funcAnm = data_020A822C;
    pAnmObj->numMapData = pMdl->info.numMat;
    pAnmObj->resAnm = pPatAnm;
    MIi_CpuClear16(0, pAnmObj->mapData, (u32)pAnmObj->numMapData * 2);

    for (i = 0; i < ((const volatile NNSG3dResTexPatAnm *)pPatAnm)->dict.numEntry; i++) {
        s32 slot = lookupMatIdx(pMat, getTexPatDictName(pPatAnm, i));
        if (slot >= 0)
            pAnmObj->mapData[slot] = (u16)(i | NNS_G3D_ANMOBJ_MAPDATA_EXIST);
    }
}

/*
 * Texture-parameter setter of the texture pattern animation: looks the
 * texture up by name in the texture block's dictionary, rebases its
 * TEXIMAGE_PARAM on the VRAM address of the plain or the 4x4-compressed
 * texture slot (format field 5, 0x14000000), stores the original width and
 * height (two 11-bit fields of the extra parameter) and derives the
 * magnification factors with a fixed-point divide, FX32_ONE when unchanged.
 *
 * The VRAM key goes through GetTexKeyAddr(key) >> 3, i.e.
 * ((key & 0xffff) << 3) >> 3, and prmTexImage is updated with `&=` then `|=`.
 * Pinned to ../2.0/sp2: 1.1p1 is 28 bytes out.
 */
void NNSi_G3dAnmSetTexParam(const NNSG3dResTex *pTex, const NNSG3dResName *pName, NNSG3dMatAnmResult *pResult)
{
    const NNSG3dResDictTexData *pData = (const NNSG3dResDictTexData *)(pTex ? NNS_G3dGetResDataByName(&pTex->dictTex, pName) : 0);
    u32 offset;
    if ((pData->texImageParam & 0x1c000000) != 0x14000000)
        offset = GetTexKeyAddr(pTex->texInfo.vramKey) >> 3;
    else
        offset = GetTexKeyAddr(pTex->tex4x4Info.vramKey) >> 3;
    pResult->prmTexImage &= 0xc00f0000;
    pResult->prmTexImage |= pData->texImageParam + offset;
    pResult->origWidth  = (u16)((pData->extraParam & 0x7ff) >> 0);
    pResult->origHeight = (u16)((pData->extraParam & (0x7ff << 11)) >> 11);
    {
        u32 width = (pData->extraParam & 0x7ff) >> 0;
        u32 height = (pData->extraParam & (0x7ff << 11)) >> 11;
        pResult->magW = (width != pResult->origWidth) ? FX_Div((fx32)(width << 12), (fx32)(pResult->origWidth << 12)) : 0x1000;
        pResult->magH = (height != pResult->origHeight) ? FX_Div((fx32)(height << 12), (fx32)(pResult->origHeight << 12)) : 0x1000;
    }
}

static inline const NNSG3dResDictPlttData *getPlttDictData(const NNSG3dResTex *pTex, const NNSG3dResName *pName)
{
    if (pTex != 0 && pTex->plttInfo.ofsDict != 0)
        return (const NNSG3dResDictPlttData *)NNS_G3dGetResDataByName((const NNSG3dResDict *)((const u8 *)pTex + pTex->plttInfo.ofsDict), pName);
    return 0;
}

/*
 * Resolves the palette offset for the bound slot: the dictionary entry
 * (offset, flag) of the texture block's palette dictionary, plus the 16-bit
 * base held in the palette VRAM key (masked to 29 bits).  When flag bit 0 is
 * clear both are halved before the sum is stored in prmTexPltt: the 4-colour
 * palette rule (offsets in 8-byte units for 4-colour, 16-byte otherwise).
 *
 * The two shift pairs `<<15, >>16` are not an explicit truncation but
 * `v >>= 1` on u16 locals (the store's narrowing folded into the shift).
 * Pinned to ../2.0/sp2 (1.1p1 is 100 bytes).
 */
void NNSi_G3dAnmSetPlttParam(const NNSG3dResTex *pTex, const NNSG3dResName *pName, NNSG3dMatAnmResult *pResult)
{
    const NNSG3dResDictPlttData *pData = getPlttDictData(pTex, pName);
    u16 base = (u16)pTex->plttInfo.vramKey & ~0xE0000000;
    u16 offset = pData->offset;
    if (!(pData->flag & 1)) {
        offset >>= 1;
        base >>= 1;
    }
    pResult->prmTexPltt = offset + base;
}

/*
 * Texture pattern animation sampling function (NitroSystem
 * NNSi_G3dAnmCalcNsBtp).  Looks up the frame value record, sets the texture
 * parameters by texture name and, when the record names a palette (index not
 * 0xff), the palette parameters too.
 *
 * Two spelling notes:
 *   - the two narrowings passed to NNSi_G3dTexPatAnmGetFrameValue are u32
 *     shift pairs, NOT u16 casts: `(t << 16) >> 16` and `(frame << 4) >> 16`
 *     give the image's `lsl/lsr` pairs, while u16 parameters and casts add a
 *     second pair on the second argument (+8 bytes).
 *   - pPatAnm must be declared after the pointer that receives the first
 *     call's result; declared first, the registers shift.
 */
void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx)
{
    const NNSG3dResTexPatAnm *pPatAnm;
    const NNSG3dResTexPatAnmFV *pFV;

    pPatAnm = (const NNSG3dResTexPatAnm *)pAnmObj->resAnm;
    pFV = NNSi_G3dTexPatAnmGetFrameValue(pPatAnm, (dataIdx << 16) >> 16, ((u32)pAnmObj->frame << 4) >> 16);
    NNSi_G3dAnmSetTexParam((const NNSG3dResTex *)pAnmObj->resTex, NNSi_G3dGetTexPatAnmTexNameByIdx(pPatAnm, pFV->idTex), pResult);
    if (pFV->idPltt == 0xff)
        return;
    NNSi_G3dAnmSetPlttParam((const NNSG3dResTex *)pAnmObj->resTex, NNSi_G3dGetTexPatAnmPlttNameByIdx(pPatAnm, pFV->idPltt), pResult);
}

/*
 * Visibility animation object init (NitroSystem NNSi_G3dAnmObjInitNsBva): an
 * identity node map.  Stores the sampling function, copies the node count
 * from the model, stores the resource, and fills mapData with `i | EXIST`.
 * The counter is assigned before the loop and the bound is re-read from the
 * object each iteration (that gives `mov ip, #0` hoisted above the first
 * store and the two `ldrb` reloads).
 */
void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *pAnmObj, const NNSG3dResVisAnm *pVisAnm, const NNSG3dResMdl *pMdl)
{
    u32 i = 0;
    pAnmObj->funcAnm = data_020A8220;
    pAnmObj->numMapData = pMdl->info.numNode;
    pAnmObj->resAnm = pVisAnm;
    while (i < pAnmObj->numMapData) {
        pAnmObj->mapData[i] = (u16)(i | NNS_G3D_ANMOBJ_MAPDATA_EXIST);
        i = i + 1;
    }
}

/* Visibility animation sampling function: the visibility bit of node dataIdx at the current frame. */
void NNSi_G3dAnmCalcNsBva(NNSG3dVisAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx)
{
    const NNSG3dResVisAnm *pVisAnm = (const NNSG3dResVisAnm *)pAnmObj->resAnm;
    u32 bitIdx = (pAnmObj->frame >> 12) * pVisAnm->numNode + dataIdx;

    pResult->isVisible = pVisAnm->visData[bitIdx >> 5] & (1u << (bitIdx & 0x1f));
}

/*
 * Sends a joint result as geometry commands, without the Maya scale terms:
 * rotation and translation as one 4x3 multiply, a 3x3 multiply (rotation
 * only) or a translate, then the scale unless it is one.
 *
 * Pinned to ../2.0/sp2, "kept branches": the image writes the 0x19 and 0x1c
 * arms out separately, each closing with its own `bl` and an unconditional
 * branch to the join, and gives the 0x1a arm a third call site.  1.1p1 -O4,p
 * re-lays the outer arms.  The flag word is re-read before the trailing
 * scale test, so the second read of pResult->flag is required.
 */
void NNSi_G3dSendJointSRTBasic(NNSG3dJntAnmResult *pResult)
{
    u32 flag;

    flag = pResult->flag;
    if ((flag & NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO) == 0) {
        if ((flag & NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO) == 0)
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_MULT_4x3, &pResult->rot[0][0], 0xc);
        else
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_TRANS, &pResult->trans[0], 3);
    } else {
        if ((flag & NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO) == 0)
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_MULT_3x3, &pResult->rot[0][0], 9);
    }

    flag = pResult->flag;
    if ((flag & NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE) == 0)
        NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_SCALE, &pResult->scale[0], 3);
}

/*
 * Joint scale handler for the basic scaling rule (jntScaleFunc): when the
 * scale-is-one flag is set it marks the result, otherwise it copies the
 * three scale words into the result; either way both extra scales are
 * marked as one.  The copy is three field assignments (ldr/str pairs), not
 * a struct assignment, which would emit ldm/stm.  The command pointer is
 * part of the table signature and is not read.
 */
void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag)
{
    (void)pCmd;

    if (flag & NNS_G3D_SRTFLAG_SCALE_ONE) {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE;
    } else {
        pResult->scale[0] = pScale[0];
        pResult->scale[1] = pScale[1];
        pResult->scale[2] = pScale[2];
    }

    pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE | NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE;
}

/*
 * The wide sibling of NNSi_G3dSendJointSRTBasic for the Maya scaling rule: the same
 * flag-driven fan-out of geometry commands, with a leading block that sends
 * the parent's inverse scale (scaleEx0) and a `first` latch that decides
 * whether the rotation and translation go out as one 4x3 multiply.
 *
 * Pinned to ../2.0/sp2, "kept branches": the image writes the two arms of
 * the rotation fan-out separately, each closing with its own unconditional
 * branch to the join, with the shared `add r1, r5, #0x28` hoisted before the
 * `beq`.  1.1p1 -O4,p cross-jumps the pair into one `bl` (188 bytes against
 * the original's 196).
 */
void NNSi_G3dSendJointSRTMaya(NNSG3dJntAnmResult *pResult)
{
    u32 flag;
    u32 first;

    flag = pResult->flag;
    first = 0;
    if ((flag & NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO) == 0)
        first = 1;
    if ((flag & NNS_G3D_JNTANM_RESULTFLAG_HAS_PARENT_SCALE) != 0 && (flag & NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE) == 0) {
        if (first != 0) {
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_TRANS, &pResult->trans[0], 3);
            first = 0;
        }
        NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_SCALE, &pResult->scaleEx0[0], 3);
    }
    flag = pResult->flag;
    if ((flag & NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO) == 0) {
        if (first != 0)
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_MULT_4x3, &pResult->rot[0][0], 0xc);
        else
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_MULT_3x3, &pResult->rot[0][0], 9);
    } else {
        if (first != 0)
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_TRANS, &pResult->trans[0], 3);
    }
    flag = pResult->flag;
    if ((flag & NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE) == 0)
        NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_SCALE, &pResult->scale[0], 3);
}

/*
 * Joint scale handler for the Maya scaling rule (jntScaleFunc).  pScale holds
 * the scale (words 0..2) and its inverse (words 3..5).  Node descriptor flag
 * bit 1 stores them for the children (scale-is-one only sets the node's bit
 * in the cached-matrix bitmap); flag bit 0 reads the parent's stored inverse
 * scale into scaleEx0, or marks it as one when the parent's bit is set.
 *
 * Pinned to ../2.0/sp2, "kept branches" and re-read tells: the image keeps
 * `beq` over the three-instruction guard body, which re-reads the flag word
 * just written; 1.1p1 predicates the block and forwards the live value
 * (328 bytes against 336).  The three-word row copy is a struct assignment
 * (`ldm`/`stm`), not three field assignments.
 */
void NNSi_G3dGetJointScaleMaya(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag)
{
    u32 nodeFlag;

    nodeFlag = pCmd->flag;

    if (flag & NNS_G3D_SRTFLAG_SCALE_ONE) {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE;
        if (nodeFlag & NNS_G3D_SBC_NODEDESC_FLAG_STORE_SCALE) {
            u32 nodeId = pCmd->nodeId;
            gCurrentRS->isMtxCached[nodeId >> 5] |= 1U << (nodeId & 0x1f);
        }
    } else {
        pResult->scale[0] = pScale[0];
        pResult->scale[1] = pScale[1];
        pResult->scale[2] = pScale[2];
        if (nodeFlag & NNS_G3D_SBC_NODEDESC_FLAG_STORE_SCALE) {
            u32 nodeId = pCmd->nodeId;
            gCurrentRS->isMtxCached[nodeId >> 5] &= ~(1U << (nodeId & 0x1f));
            g_02149BC0[nodeId].invScale.x = pScale[3];
            g_02149BC0[nodeId].invScale.y = pScale[4];
            g_02149BC0[nodeId].invScale.z = pScale[5];
        }
    }

    if (nodeFlag & NNS_G3D_SBC_NODEDESC_FLAG_PARENT_SCALE) {
        u32 parentId = pCmd->parentNodeId;
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_HAS_PARENT_SCALE;
        if (gCurrentRS->isMtxCached[parentId >> 5] & (1U << (parentId & 0x1f))) {
            pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE;
        } else {
            *(NNSG3dVec3Fx *)pResult->scaleEx0 = g_02149BC0[parentId].invScale;
        }
    }

    pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE;
}

/*
 * Texture matrix builder, scale + rotation + translation (the 64-bit smull
 * member of the family): the 2x2 block is the scale times the rotation, and
 * the aspect correction comes from two hardware divides (h/w and w/h).
 *
 * The two scaleS products are computed scaleS * sinR FIRST and
 * scaleS * cosR SECOND, even though the cosR one is stored first; written in
 * store order the allocator picks the image's register pair reversed.
 *
 * Pinned to ../2.0/sp2, "kept constants" in its scheduling form: the image
 * loads the two s16 fields in the order cosR then sinR and consumes them in
 * the opposite order; 1.1p1 refuses to separate a load from its first use and
 * swaps the loads (264 bytes, 8 concrete bytes out).
 */
void NNSi_G3dTexMtxScaleRotTrans4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult)
{
    s32 width, height;
    s32 cosR, scaleS, sinR, scaleT;
    s32 scaleSCos, scaleSSin, scaleTSin, scaleTCos;
    s32 n;

    width = (s32)pResult->origWidth << 12;
    height = (s32)pResult->origHeight << 12;
    FX_DivAsync(height, width);

    cosR = (s32)pResult->cosR;
    scaleS = pResult->scaleS;
    sinR = (s32)pResult->sinR;
    scaleT = pResult->scaleT;

    scaleSSin = (s32)(((s64)scaleS * sinR) >> 12);
    scaleSCos = (s32)(((s64)scaleS * cosR) >> 12);
    scaleTSin = (s32)(((s64)scaleT * sinR) >> 12);
    scaleTCos = (s32)(((s64)scaleT * cosR) >> 12);

    pMtx->_00 = scaleSCos;
    pMtx->_11 = scaleTCos;
    pMtx->_01 = ((0 - scaleTSin) * FX_GetDivResult()) >> 12;

    FX_DivAsync(width, height);

    n = pResult->scaleS - (scaleSSin + scaleSCos);
    pMtx->_30 = ((s32)pResult->origWidth * n << 3)
              - ((s32)pResult->origWidth * (s32)(((s64)pResult->scaleS * pResult->transS) >> 8));
    n = ((scaleTSin - scaleTCos) - pResult->scaleT) + 0x2000;
    pMtx->_31 = ((s32)pResult->origHeight * (s32)(((s64)pResult->scaleT * pResult->transT) >> 8))
              + ((s32)pResult->origHeight * n << 3);

    pMtx->_10 = (scaleSSin * FX_GetDivResult()) >> 12;
}

/*
 * Texture matrix builder, rotation + translation (scale is one): two
 * FX_DivAsync/FX_GetDivResult scale pairs (the async divider is started, the
 * destination words are written, and the quotient is read back) plus the two
 * translation terms.
 *
 * Two spelling facts:
 *   - the negated sum must be TWO statements (`n = sinR + cosR; n = 0 - n;`).
 *     Written as one expression, `-(sinR + cosR) + 0x1000` folds to a single
 *     `rsb r2, r1, #0x1000` and loses four bytes and the whole register plan.
 *   - the _31 term is written with the `<< 4` product as the SECOND operand of
 *     the `+`, because the accumulator of a commutative chain is its second
 *     operand; the other order swaps every register in the block.
 */
void NNSi_G3dTexMtxRotTrans4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult)
{
    s32 width = pResult->origWidth << 12;
    s32 height = pResult->origHeight << 12;
    s32 n;
    s32 q;

    FX_DivAsync(height, width);
    pMtx->_00 = pResult->cosR;
    pMtx->_11 = pResult->cosR;
    q = FX_GetDivResult();
    pMtx->_01 = (-pResult->sinR * q) >> 12;
    FX_DivAsync(width, height);
    n = pResult->sinR + pResult->cosR;
    n = 0 - n;
    pMtx->_30 = (pResult->origWidth * (n + 0x1000) << 3)
              - (pResult->transS * pResult->origWidth << 4);
    n = pResult->sinR - pResult->cosR;
    pMtx->_31 = (pResult->origHeight * (n + 0x1000) << 3)
              + (pResult->transT * pResult->origHeight << 4);
    q = FX_GetDivResult();
    pMtx->_10 = (pResult->sinR * q) >> 12;
}

/*
 * Texture matrix builder, scale + translation (no rotation): fills the
 * scale diagonal and the two translation terms.
 *
 * The _31 term's aspect factor is written as two subtractions of the same
 * field, `-scaleT - scaleT + 0x1000 * 2`, rather than `-(scaleT << 1)` or a
 * multiply by 2; with it scaleT lands in r4 and transT in ip as in the image.
 * Pinned to ../2.0/sp2 (1.1p1 is 116 bytes against the image's 124).
 */
void NNSi_G3dTexMtxScaleTrans(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult)
{
    pMtx->_00 = pResult->scaleS;
    pMtx->_11 = pResult->scaleT;

    pMtx->_01 = 0;

    pMtx->_30 = -(fx32)((fx64)pResult->scaleS * pResult->transS >> 8) * pResult->origWidth;
    pMtx->_31 = ((-pResult->scaleT - pResult->scaleT + 0x1000 * 2) * pResult->origHeight << 3) +
                (fx32)((fx64)pResult->scaleT * pResult->transT >> 8) * pResult->origHeight;

    pMtx->_10 = 0;
}

/*
 * Texture matrix builder, translation only (unlabelled leaf, saves no lr):
 * _00 and _11 take the 0x1000 unit scale, _01 and _10 are zero, and _30 and
 * _31 are the plain `-(transS * origWidth) << 4` form.
 *
 * Pinned to ../2.0/sp2, "kept constants": the image materialises the zero
 * LATE, `mov ip, #0` after the `str r2, [r0]`, so the _00 and _01 stores stay
 * separate.  1.1p1 -O4,p hoists the zero and merges the pair into one `stm`.
 */
void NNSi_G3dTexMtxTrans(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult)
{
    fx32 t;

    pMtx->_00 = 0x1000;
    pMtx->_11 = 0x1000;
    pMtx->_01 = 0;

    t = pResult->transS * (fx32)pResult->origWidth;
    pMtx->_30 = (0 - t) << 4;

    t = pResult->transT * (fx32)pResult->origHeight;
    pMtx->_31 = t << 4;

    pMtx->_10 = 0;
}

/*
 * Texture matrix builder, scale + rotation (no translation): all four
 * products of the scale and the rotation at 64-bit width, reduced by
 * `>> 12`, both fixed-point divisions, and a translation pair whose operands
 * are sums and differences of the four products.
 *
 * Three levers:
 *   - the two `<< 12` shifted sizes are named locals: the image computes them
 *     once and re-feeds the same two registers to the second divide with the
 *     arguments swapped (that forces the ten-register push).
 *   - two live ranges are split by a fresh temporary: `t` holds the
 *     scaleS * sinR narrowing, computed BEFORE the cosR product and only
 *     assigned to scaleSSin after it, and `u` holds the _30 operand before it
 *     is copied into `n`.
 *   - the _31 operand is `(scaleTSin - scaleTCos) - scaleT` with the
 *     `+ 0x2000` as a separate statement (two instructions in the image).
 *
 * Pinned to ../2.0/sp2, "kept constants" in its scheduling form: 1.1p1 loads
 * sinR before cosR and colours the first product r7, where the image loads
 * cosR first and colours it r6 (12 bytes out under 1.1p1).
 */
void NNSi_G3dTexMtxScaleRot4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult)
{
    s32 width, height;
    s32 cosR, scaleS, sinR, scaleT;
    s32 scaleSCos, scaleSSin, scaleTSin, scaleTCos;
    s32 n;
    s32 t, u;

    width = (s32)pResult->origWidth << 12;
    height = (s32)pResult->origHeight << 12;
    FX_DivAsync(height, width);

    cosR = (s32)pResult->cosR;
    scaleS = pResult->scaleS;
    sinR = (s32)pResult->sinR;
    scaleT = pResult->scaleT;

    t  = (s32)(((s64)scaleS * sinR) >> 12);
    scaleSCos = (s32)(((s64)scaleS * cosR) >> 12);
    scaleSSin = t;
    scaleTSin = (s32)(((s64)scaleT * sinR) >> 12);
    scaleTCos = (s32)(((s64)scaleT * cosR) >> 12);

    pMtx->_00 = scaleSCos;
    pMtx->_11 = scaleTCos;
    pMtx->_01 = ((0 - scaleTSin) * FX_GetDivResult()) >> 12;

    FX_DivAsync(width, height);

    u = pResult->scaleS - (scaleSSin + scaleSCos);
    n = u;
    pMtx->_30 = ((s32)pResult->origWidth * n) << 3;

    n = (scaleTSin - scaleTCos) - pResult->scaleT;
    n = n + 0x2000;
    pMtx->_31 = ((s32)pResult->origHeight * n) << 3;

    pMtx->_10 = (scaleSSin * FX_GetDivResult()) >> 12;
}

/*
 * Texture matrix builder, rotation only: _00 and _11 take cosR, _01 and _10
 * the aspect-corrected sinR from two hardware divides (h/w and w/h).
 *
 * The _30 factor's negation is done in u32, `(fx32)-(u32)(sinR + cosR) +
 * 0x1000`.  A signed negation folds with the + 0x1000 into one rsb (180
 * bytes); a three-statement spelling keeps the size but swaps the registers.
 * Pinned to ../2.0/sp2.
 */
void NNSi_G3dTexMtxRot4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult)
{
    fx32 width = pResult->origWidth << 12;
    fx32 height = pResult->origHeight << 12;
    FX_DivAsync(height, width);
    pMtx->_00 = pResult->cosR;
    pMtx->_11 = pResult->cosR;
    pMtx->_01 = (-pResult->sinR * FX_GetDivResult()) >> 12;
    FX_DivAsync(width, height);
    pMtx->_30 = (pResult->origWidth * ((fx32)-(u32)(pResult->sinR + pResult->cosR) + 0x1000)) << 3;
    pMtx->_31 = (pResult->origHeight * (pResult->sinR - pResult->cosR + 0x1000)) << 3;
    pMtx->_10 = (pResult->sinR * FX_GetDivResult()) >> 12;
}

/*
 * Texture matrix builder, scale only (68 bytes): copies scaleS and scaleT
 * into the diagonal, zeroes _01, _10 and _30 and derives _31 from scaleT and
 * origHeight.
 *
 * The _31 term forms `lsl r1, r2, #1; rsb r1, r1, #0; add r1, r1, #0x2000;
 * mul; lsl #3`, i.e. -(2*scaleT) + 0x2000 with the constant added LAST.
 * Every factored spelling folds it; only the doubled operand written out
 * twice, `0x1000 - scaleT + 0x1000 - scaleT`, keeps the negate and the
 * separate add.  Not pinned: EXACT under both front ends.
 */
void NNSi_G3dTexMtxScale4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult)
{
    pMtx->_00 = pResult->scaleS;
    pMtx->_11 = pResult->scaleT;
    pMtx->_01 = 0;
    pMtx->_30 = 0;
    pMtx->_31 = (0x1000 - pResult->scaleT + 0x1000 - pResult->scaleT) * pResult->origHeight * 8;
    pMtx->_10 = 0;
}

/*
 * Texture matrix builder, identity (unlabelled leaf, saves no lr): writes the
 * 0x1000 unit scale into _00 and _11 and zeroes _01, _10, _30 and _31.
 *
 * Pinned to ../2.0/sp2, "kept constants": the image materialises the unit
 * scale FIRST, `mov r2, #0x1000` followed by `str r2, [r0]`, and only then
 * `mov r1, #0`.  1.1p1 -O4,p schedules the zero first; binding both constants
 * to locals, or writing _11 immediately after _00, keeps that schedule.
 */
void NNSi_G3dTexMtxIdentity(MtxFx44 *pMtx)
{
    pMtx->_00 = 0x1000;
    pMtx->_01 = 0;
    pMtx->_10 = 0;
    pMtx->_11 = 0x1000;
    pMtx->_30 = 0;
    pMtx->_31 = 0;
}

/*
 * Sends the texture matrix of a material (4x4 form): builds a display-list
 * record on the stack (packed MTX_MODE/matrix-load command word, texture
 * mode, 4x4 matrix, restore mode), fills the matrix through the builder
 * selected by the low three bits of the flag word, then applies the two
 * fixed-point (1.12) magnification factors to the matrix terms of each axis
 * when the factor is not unity, and hands the record to NNS_G3dGeBufferOP_N.
 *
 * magW and magH are read through a volatile view: the image re-reads them
 * before each of the three smulls in its block, where 1.1p1 -O4,p otherwise
 * caches the field in a register and batches the multiplies (308 bytes
 * against the original's 328).
 */
void NNSi_G3dSendTexMtx4x4(NNSG3dMatAnmResult *pResult)
{
    NNSG3dTexMtxCmd cmd;
    fx32 mag;

    if (pResult->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET) cmd.op = 0x00101610;
    else                                                      cmd.op = 0x00101810;

    cmd.mtxMode = 3;
    cmd.mtxModeRestore = 2;
    cmd.mtx._32 = 0;
    cmd.mtx._23 = 0;
    cmd.mtx._22 = 0;
    cmd.mtx._21 = 0;
    cmd.mtx._20 = 0;
    cmd.mtx._13 = 0;
    cmd.mtx._12 = 0;
    cmd.mtx._03 = 0;
    cmd.mtx._02 = 0;
    cmd.mtx._33 = 0x1000;

    g_dispatch[pResult->flag & 7](&cmd.mtx, pResult);

    mag = VOLATILE_MATANM(pResult)->magW;
    if (mag != 0x1000) {
        cmd.mtx._00 = (fx32)(((long long)mag * cmd.mtx._00) >> 12);
        cmd.mtx._01 = (fx32)(((long long)VOLATILE_MATANM(pResult)->magW * cmd.mtx._01) >> 12);
        cmd.mtx._30 = (fx32)(((long long)VOLATILE_MATANM(pResult)->magW * cmd.mtx._30) >> 12);
    }
    mag = VOLATILE_MATANM(pResult)->magH;
    if (mag != 0x1000) {
        cmd.mtx._10 = (fx32)(((long long)mag * cmd.mtx._10) >> 12);
        cmd.mtx._11 = (fx32)(((long long)VOLATILE_MATANM(pResult)->magH * cmd.mtx._11) >> 12);
        cmd.mtx._31 = (fx32)(((long long)VOLATILE_MATANM(pResult)->magH * cmd.mtx._31) >> 12);
    }

    {
        char *pBase = (char *)&cmd;
        NNS_G3dGeBufferOP_N(cmd.op, pBase + 4, 0x12);
    }
}

/*
 * Sends a joint result as geometry commands for the Si3d scaling rule: one
 * call per component group, each gated by a bit of the flag word.  Bits 3/4
 * (mask 0x18) select whether the scale blocks are sent raw or the
 * translation is pre-scaled by the 1.12 factors in scaleEx0; bit 2
 * suppresses the translation, bit 1 selects the long (0xc) over the short
 * (9) matrix push, and bit 0 suppresses the final scale push.
 *
 * Pinned to ../2.0/sp2, "kept branches".  The translation is read through a
 * volatile view (the image re-reads it for each product).
 */
void NNSi_G3dSendJointSRTSi3d(NNSG3dJntAnmResult *pResult)
{
    fx32 tmp[3];
    int send4x3 = 0;
    int scaleExFlag;

    scaleExFlag = pResult->flag & (NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE | NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE);
    if (scaleExFlag == 0)
        NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_SCALE, &pResult->scaleEx1[0], 3);

    if (!(pResult->flag & NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO)) {
        if (scaleExFlag != 0) {
            send4x3 = 1;
        } else {
            tmp[0] = (fx32)(((long long)VOLATILE_JNTANM(pResult)->trans[0] * pResult->scaleEx0[0]) >> 12);
            tmp[1] = (fx32)(((long long)VOLATILE_JNTANM(pResult)->trans[1] * pResult->scaleEx0[1]) >> 12);
            tmp[2] = (fx32)(((long long)VOLATILE_JNTANM(pResult)->trans[2] * pResult->scaleEx0[2]) >> 12);
            NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_TRANS, tmp, 3);
        }
    }

    if (!(pResult->flag & NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO)) {
        if (send4x3) NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_MULT_4x3, &pResult->rot[0][0], 0xc);
        else         NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_MULT_3x3, &pResult->rot[0][0], 9);
    } else if (send4x3) {
        NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_TRANS, &pResult->trans[0], 3);
    }

    if (scaleExFlag == 0)
        NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_SCALE, &pResult->scaleEx0[0], 3);

    if (!(pResult->flag & NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE))
        NNS_G3dGeBufferOP_N(NNS_G3D_GECMD_MTX_SCALE, &pResult->scale[0], 3);
}

/*
 * Joint scale handler for the Si3d scaling rule (jntScaleFunc): propagates
 * the parent scale.  The node's own slot and its parent's slot name two
 * records of the 0x18-byte scale table at g_02149BB4 (scale and inverse
 * scale); the cached-matrix bitmap of the render state marks "scale is one".
 *   flag has SCALE_ONE:  mark the result; if the parent's bit is set, set
 *               the node's bit and mark scaleEx as one; otherwise copy the
 *               parent's record over the node's and into scaleEx0/scaleEx1.
 *   otherwise:  copy the scale into the result; if the parent's bit is set,
 *               copy the scale into the node's record, clear the node's bit
 *               and mark scaleEx as one; otherwise clear the node's bit, set
 *               the node's record to the scale times the parent's record
 *               component-wise in 1.12 ((s64)x*y >> 12, six terms) and copy
 *               the parent's record into scaleEx0/scaleEx1.
 *
 * The six pool words of the image are ONE `s32 [][6]` table, whose column k
 * is addressed as symbol+4k; the single 2-D extern reproduces all six.  The
 * copy is MIi_CpuCopy32 (source first).
 *
 * Pinned to ../2.0/sp2, "kept constants": the image rematerialises the copy
 * size `mov r2, #0x18` before each call; 1.1p1 keeps 0x18 in a callee-saved
 * register (536 bytes against 540).
 */
void NNSi_G3dGetJointScaleSi3d(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag)
{
    u32 nodeId = pCmd->nodeId;
    u32 parentId = pCmd->parentNodeId;

    if (flag & NNS_G3D_SRTFLAG_SCALE_ONE) {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE;
        if (gCurrentRS->isMtxCached[parentId >> 5] & (1 << (parentId & 0x1f))) {
            gCurrentRS->isMtxCached[nodeId >> 5] |= 1 << (nodeId & 0x1f);
            pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE | NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE;
            return;
        }
        MIi_CpuCopy32(g_02149BB4[parentId], g_02149BB4[nodeId], 0x18);
        MIi_CpuCopy32(g_02149BB4[parentId], pResult->scaleEx0, 0x18);
        return;
    }

    pResult->scale[0] = pScale[0];
    pResult->scale[1] = pScale[1];
    pResult->scale[2] = pScale[2];
    if (gCurrentRS->isMtxCached[parentId >> 5] & (1 << (parentId & 0x1f))) {
        MIi_CpuCopy32(pScale, g_02149BB4[nodeId], 0x18);
        gCurrentRS->isMtxCached[nodeId >> 5] &= ~(1 << (nodeId & 0x1f));
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE | NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE;
        return;
    }
    gCurrentRS->isMtxCached[nodeId >> 5] &= ~(1 << (nodeId & 0x1f));
    g_02149BB4[nodeId][0] = (s32)(((s64)pScale[0] * g_02149BB4[parentId][0]) >> 12);
    g_02149BB4[nodeId][1] = (s32)(((s64)pScale[1] * g_02149BB4[parentId][1]) >> 12);
    g_02149BB4[nodeId][2] = (s32)(((s64)pScale[2] * g_02149BB4[parentId][2]) >> 12);
    g_02149BB4[nodeId][3] = (s32)(((s64)pScale[3] * g_02149BB4[parentId][3]) >> 12);
    g_02149BB4[nodeId][4] = (s32)(((s64)pScale[4] * g_02149BB4[parentId][4]) >> 12);
    g_02149BB4[nodeId][5] = (s32)(((s64)pScale[5] * g_02149BB4[parentId][5]) >> 12);
    MIi_CpuCopy32(g_02149BB4[parentId], pResult->scaleEx0, 0x18);
}

/*
 * Sends the texture matrix of a material (4x3 form), the sibling of
 * NNSi_G3dSendTexMtx4x4: fills a 15-word display-list record on the stack, selects
 * the translation source out of the flag word's bits 3 / 2 / 0, applies the
 * two 1.12 magnification factors when they are not unity, and hands the whole
 * record to NNS_G3dGeBufferOP_N with a count of 0xe.
 *
 * Pinned to ../2.0/sp2, "kept branches": the image emits real branches for
 * the three-way translation select; 1.1p1 -O4,p if-converts the two inner
 * arms into predicated runs and drops both `b`s (440 bytes against 452).
 *
 * Two volatile tells, both needed:
 *   flag          the inner test re-reads the flag word although it is in a
 *                 register already.
 *   magW, magH    each factor is loaded twice, once for the compare against
 *                 0x1000 and again for the second product.
 * One read is NOT volatile: the outer else-branch reuses the flag value in a
 * register, so the bit-0 test there reads the local `flagCopy` taken before
 * the `& 4` test (volatile there costs one `ldr` and shifts the tail).
 */
void NNSi_G3dSendTexMtx4x3(NNSG3dMatAnmResult *pResult)
{
    NNSG3dTexMtxCmd43 cmd;
    s32 mag;
    u32 flagCopy;

    if (VOLATILE_MATANM(pResult)->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET) cmd.op = 0x00101710;
    else                                                                       cmd.op = 0x00101910;

    cmd.mtxMode = 3;
    cmd.mtx._32 = 0;
    cmd.mtx._22 = 0;
    cmd.mtx._21 = 0;
    cmd.mtx._20 = 0;
    cmd.mtx._12 = 0;
    cmd.mtx._10 = 0;
    cmd.mtx._02 = 0;
    cmd.mtx._01 = 0;
    cmd.mtxModeRestore = 2;

    flagCopy = VOLATILE_MATANM(pResult)->flag;
    if (flagCopy & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO) {
        cmd.mtx._30 = 0;
        cmd.mtx._31 = 0;
        if (VOLATILE_MATANM(pResult)->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE) {
            cmd.mtx._00 = 0x1000;
            cmd.mtx._11 = 0x1000;
        } else {
            cmd.mtx._00 = pResult->scaleS;
            cmd.mtx._11 = pResult->scaleT;
        }
    } else if (flagCopy & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE) {
        cmd.mtx._30 = (0 - (pResult->transS << 4)) * (s32)pResult->origWidth;
        cmd.mtx._31 = (0 - (pResult->transT << 4)) * (s32)pResult->origHeight;
        cmd.mtx._00 = 0x1000;
        cmd.mtx._11 = 0x1000;
    } else {
        cmd.mtx._30 = (s32)pResult->origWidth * (0 - (s32)(((s64)pResult->scaleS * pResult->transS) >> 8));
        cmd.mtx._31 = (s32)pResult->origHeight * (0 - (s32)(((s64)pResult->scaleT * pResult->transT) >> 8));
        cmd.mtx._00 = pResult->scaleS;
        cmd.mtx._11 = pResult->scaleT;
    }

    mag = VOLATILE_MATANM(pResult)->magW;
    if (mag != 0x1000) {
        cmd.mtx._00 = (s32)(((s64)mag * cmd.mtx._00) >> 12);
        cmd.mtx._30 = (s32)(((s64)VOLATILE_MATANM(pResult)->magW * cmd.mtx._30) >> 12);
    }
    mag = VOLATILE_MATANM(pResult)->magH;
    if (mag != 0x1000) {
        cmd.mtx._11 = (s32)(((s64)mag * cmd.mtx._11) >> 12);
        cmd.mtx._31 = (s32)(((s64)VOLATILE_MATANM(pResult)->magH * cmd.mtx._31) >> 12);
    }

    {
        char *pBase = (char *)&cmd;
        NNS_G3dGeBufferOP_N(cmd.op, pBase + 4, 0x0e);
    }
}
