/*
 * nns_g3d_anm_calc_types.h: NitroSystem g3d resource layouts and render-state
 * fields read by the animation sampling functions in nns_g3d_anm_calc.c.
 */
#ifndef NNS_G3D_ANM_CALC_TYPES_H
#define NNS_G3D_ANM_CALC_TYPES_H

#include "../arm9/nns_g3d_anm_types.h"
#include "../arm9/nns_g3d_glb_types.h"

#include "../types.h"

/* flag bits of NNSG3dResNodeData and of a joint animation record */
#define NNS_G3D_SRTFLAG_TRANS_ZERO  0x01
#define NNS_G3D_SRTFLAG_ROT_ZERO    0x02
#define NNS_G3D_SRTFLAG_SCALE_ONE   0x04
#define NNS_G3D_SRTFLAG_PIVOT_EXIST 0x08
#define NNS_G3D_SRTFLAG_IDXPIVOT_MASK 0xf0
#define NNS_G3D_SRTFLAG_PIVOT_MINUS 0x100
#define NNS_G3D_SRTFLAG_PIVOT_REVC  0x200
#define NNS_G3D_SRTFLAG_PIVOT_REVD  0x400

/* joint animation flags (NNSG3dResJntAnm.flag) */
#define NNS_G3D_JNTANM_FLAG_INTERPOLATE         0x01
#define NNS_G3D_JNTANM_FLAG_END_TO_START_INTERP 0x02

/* info word of a joint animation key array (translation, rotation, scale) */
#define NNS_G3D_JNTANM_SINFO_STEP_MASK        0xc0000000
#define NNS_G3D_JNTANM_SINFO_STEP_2           0x40000000
#define NNS_G3D_JNTANM_SINFO_STEP_4           0x80000000
#define NNS_G3D_JNTANM_SINFO_FX16ARRAY        0x20000000
#define NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK  0x1fff0000
#define NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT 16

/* Sbc NODEDESC command: command byte, node index, parent node index and flags. */
typedef struct NNSG3dSbcNodeDesc {
    u8 cmd;
    u8 nodeId;
    u8 parentNodeId;
    u8 flag;
} NNSG3dSbcNodeDesc;

/* NNSG3dSbcNodeDesc.flag bits read by the Maya scale handler */
#define NNS_G3D_SBC_NODEDESC_FLAG_PARENT_SCALE 0x01
#define NNS_G3D_SBC_NODEDESC_FLAG_STORE_SCALE  0x02

/* Dictionary header; entries start at ofsEntry (u16 sizeUnit, u16 ofsName, units). */
typedef struct NNSG3dResDictTreeNode {
    u8 refBit;
    u8 idxLeft;
    u8 idxRight;
    u8 idxEntry;
} NNSG3dResDictTreeNode;

typedef struct NNSG3dResDict {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} NNSG3dResDict;

typedef struct NNSG3dResDictEntryHdr {
    u16 sizeUnit;
    u16 ofsName;
} NNSG3dResDictEntryHdr;

/* One dictionary unit: offset of the data from the dictionary start. */
typedef struct NNSG3dResDictUnit {
    u32 ofsData;
} NNSG3dResDictUnit;

/* Model node data; the T/R/S payload that follows depends on flag. */
typedef struct NNSG3dResNodeData {
    u16  flag;
    s16  rotM00;
    fx32 trans[3];
} NNSG3dResNodeData;

typedef struct NNSG3dResMdlInfo {
    u8 sbcType;
    u8 scalingRule;
    u8 texMtxMode;
    u8 numNode;
    u8 numMat;
    u8 numShp;
    u8 firstUnusedMtxStackId;
    u8 dummy_;
    fx32 posScale;
    fx32 invPosScale;
    u16 numVertex;
    u16 numPolygon;
    u16 numTriangle;
    u16 numQuad;
    fx16 boxX;
    fx16 boxY;
    fx16 boxZ;
    fx16 boxW;
    fx16 boxH;
    fx16 boxD;
    fx32 boxPosScale;
    fx32 boxInvPosScale;
} NNSG3dResMdlInfo;

/* Model resource: block offsets, the info block, then the node dictionary at +0x40. */
typedef struct NNSG3dResMdl {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u32 ofsShp;
    u32 ofsEvpMtx;
    NNSG3dResMdlInfo info;
    NNSG3dResDict nodeInfo;
} NNSG3dResMdl;

typedef struct NNSG3dResAnmHdr {
    u8  category0;
    u8  category1;
    u16 revision;
} NNSG3dResAnmHdr;

/* Common prefix of every animation resource: header and frame count. */
typedef struct NNSG3dResAnmCommon {
    NNSG3dResAnmHdr hdr;
    u16 numFrame;
} NNSG3dResAnmCommon;

/* Joint animation resource (NSBCA); ofsNodeAnm[] is indexed by node. */
typedef struct NNSG3dResJntAnm {
    NNSG3dResAnmHdr hdr;
    u16 numFrame;
    u16 numNode;
    u32 flag;
    u32 ofsRot3;
    u32 ofsRot9;
    u16 ofsNodeAnm[1];
} NNSG3dResJntAnm;

/* One entry of a pivot-column table; the four tables are interleaved byte-wise. */
typedef struct NNSG3dPivotSlot {
    u8 index;
    u8 others[3];
} NNSG3dPivotSlot;

/* Key array descriptor: info word and byte offset of the keys from the resource. */
typedef struct NNSG3dJntAnmTInfo {
    u32 info;
    u32 offset;
} NNSG3dJntAnmTInfo;
typedef NNSG3dJntAnmTInfo NNSG3dJntAnmSInfo;
typedef NNSG3dJntAnmTInfo NNSG3dJntAnmRInfo;

typedef struct ScaleFx16 {
    fx16 s;
    fx16 invs;
} ScaleFx16;

typedef struct ScaleFx32 {
    fx32 s;
    fx32 invs;
} ScaleFx32;

typedef void (*NNSG3dJntScaleFunc)(NNSG3dJntAnmResult *pResult, const fx32 *pScale,
                                   const NNSG3dSbcNodeDesc *pCmd, u32 flag);

/* Item tag header shared by material, shape and node resource items. */
typedef struct NNSG3dResItemTag {
    u16 tag;
    u16 size;
} NNSG3dResItemTag;

/* Material block of a model: two name-to-material lists, then the material dictionary. */
typedef struct NNSG3dResMat {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    NNSG3dResDict dict;
} NNSG3dResMat;

/* Shape block of a model: its dictionary comes first. */
typedef struct NNSG3dResShp {
    NNSG3dResDict dict;
} NNSG3dResShp;

/* NNSG3dResMatData.flag bits */
#define NNS_G3D_MATFLAG_TEXMTX_USE       0x0001
#define NNS_G3D_MATFLAG_TEXMTX_SCALEONE  0x0002
#define NNS_G3D_MATFLAG_TEXMTX_ROTZERO   0x0004
#define NNS_G3D_MATFLAG_TEXMTX_TRANSZERO 0x0008
#define NNS_G3D_MATFLAG_WIREFRAME        0x0020
#define NNS_G3D_MATFLAG_EFFECTMTX        0x2000

/* One material item (the effect-matrix words start at +0x2c). */
typedef struct NNSG3dResMatData {
    u16  itemTag;
    u16  size;
    u32  diffAmb;
    u32  specEmi;
    u32  polyAttr;
    u32  polyAttrMask;
    u32  texImageParam;
    u32  texImageParamMask;
    u16  texPlttBase;
    u16  flag;
    u16  origWidth;
    u16  origHeight;
    fx32 magW;
    fx32 magH;
    u32  effectData[1];
} NNSG3dResMatData;

/* One shape item: display list offset and size follow the tag. */
typedef struct NNSG3dResShpData {
    u16 itemTag;
    u16 size;
    u32 flag;
    u32 ofsDisplayList;
    u32 sizeDisplayList;
} NNSG3dResShpData;

/* NNSG3dMatAnmResult flag bits */
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE  0x01
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO   0x02
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO 0x04
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET       0x08
#define NNS_G3D_MATANM_RESULTFLAG_WIREFRAME        0x20

/* Result of one material sample (0x38 bytes). */
typedef struct NNSG3dMatAnmResult {
    u32  flag;
    u32  prmMatColor0;
    u32  prmMatColor1;
    u32  prmPolygonAttr;
    u32  prmTexImage;
    u32  prmTexPltt;
    fx32 scaleS;
    fx32 scaleT;
    fx16 sinR;
    fx16 cosR;
    fx32 transS;
    fx32 transT;
    u16  origWidth;
    u16  origHeight;
    fx32 magW;
    fx32 magH;
} NNSG3dMatAnmResult;

/* Visibility sample of one node. */
typedef struct NNSG3dVisAnmResult {
    u32 isVisible;
} NNSG3dVisAnmResult;

/* Sbc command ids, also the indexes of the RS callback vectors. */
#define NNS_G3D_SBC_NOP      0
#define NNS_G3D_SBC_RET      1
#define NNS_G3D_SBC_NODE     2
#define NNS_G3D_SBC_MTX      3
#define NNS_G3D_SBC_MAT      4
#define NNS_G3D_SBC_SHP      5
#define NNS_G3D_SBC_NODEDESC 6
#define NNS_G3D_SBC_BB       7
#define NNS_G3D_SBC_BBY      8
#define NNS_G3D_SBC_NODEMIX  9
#define NNS_G3D_SBC_CALLDL   10
#define NNS_G3D_SBC_POSSCALE 11
#define NNS_G3D_SBC_ENVMAP   12
#define NNS_G3D_SBC_PRJMAP   13

/* NNSG3dRS.flag bits */
#define NNS_G3D_RSFLAG_NODE_VISIBLE        0x0001
#define NNS_G3D_RSFLAG_MAT_TRANSPARENT     0x0002
#define NNS_G3D_RSFLAG_CURRENT_NODE_VALID  0x0004
#define NNS_G3D_RSFLAG_CURRENT_MAT_VALID   0x0008
#define NNS_G3D_RSFLAG_CURRENT_NODEDESC_VALID 0x0010
#define NNS_G3D_RSFLAG_RETURN              0x0020
#define NNS_G3D_RSFLAG_SKIP                0x0040
#define NNS_G3D_RSFLAG_OPT_RECORD          0x0080
#define NNS_G3D_RSFLAG_OPT_NOGECMD         0x0100
#define NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW    0x0200
#define NNS_G3D_RSFLAG_OPT_SKIP_SBCMTXCALC 0x0400

struct NNSG3dRS;
typedef void (*NNSG3dSbcCallBackFunc)(struct NNSG3dRS *pRS);
typedef void (*NNSG3dFuncMatTexMtx)(NNSG3dMatAnmResult *pResult);
typedef void (*NNSG3dFuncJntMtx)(const NNSG3dJntAnmResult *pResult);
typedef void (*NNSG3dFuncBlendMat)(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 idxMat);
typedef int  (*NNSG3dFuncBlendJnt)(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 idxNode);
typedef int  (*NNSG3dFuncBlendVis)(NNSG3dVisAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 idxNode);

/* NNSG3dRenderObj.flag bits (mirrored into NNSG3dRS.flag by the Sbc init). */
#define NNS_G3D_RENDEROBJ_FLAG_RECORD 0x01
#define NNS_G3D_RENDEROBJ_FLAG_NOGECMD 0x02
#define NNS_G3D_RENDEROBJ_FLAG_SKIP_SBCDRAW 0x04
#define NNS_G3D_RENDEROBJ_FLAG_SKIP_SBCMTXCALC 0x08
/* Set while the animation existence bitmaps need rebuilding. */
#define NNS_G3D_RENDEROBJ_FLAG_RESET_ANMEXIST 0x10

/* A drawable model instance: resource, animation chains, and the result caches. */
typedef struct NNSG3dRenderObj {
    u32                   flag;
    const NNSG3dResMdl   *resMdl;
    NNSG3dAnmObj         *anmMat;
    NNSG3dFuncBlendMat    funcBlendMat;
    NNSG3dAnmObj         *anmJnt;
    NNSG3dFuncBlendJnt    funcBlendJnt;
    NNSG3dAnmObj         *anmVis;
    NNSG3dFuncBlendVis    funcBlendVis;
    NNSG3dSbcCallBackFunc cbFunc;
    u8                    cbCmd;
    u8                    cbTiming;
    u8                    reserved26[2];
    NNSG3dSbcCallBackFunc cbInitFunc;
    u32                   reserved2C;
    const u8             *ptrSbc;
    NNSG3dJntAnmResult   *recJntAnm;
    NNSG3dMatAnmResult   *recMatAnm;
    u32                   matAnmExist[2];
    u32                   jntAnmExist[2];
    u32                   visAnmExist[2];
} NNSG3dRenderObj;

/*
 * Render state of the running Sbc interpreter (0x188 bytes).  c stays typed as
 * the command header for the animation sampling code; Sbc handlers read the
 * stream as bytes through NNS_G3D_SBC_BYTE and advance it with NNS_G3D_SBC_ADVANCE.
 */
typedef struct NNSG3dRS {
    const NNSG3dSbcNodeDesc *c;
    NNSG3dRenderObj     *pRenderObj;
    u32                  flag;
    NNSG3dSbcCallBackFunc cbVecFunc[32];
    u8                   cbVecTiming[32];
    u8                   currentNode;
    u8                   currentMat;
    u8                   currentNodeDesc;
    u8                   dummy_;
    NNSG3dMatAnmResult  *pMatAnmResult;
    NNSG3dJntAnmResult  *pJntAnmResult;
    NNSG3dVisAnmResult  *pVisAnmResult;
    u32                  isMatCached[2];
    union {
        u32 bits[4];
        struct {
            u32 isMtxCached[2];
            u32 isEvpCached[2];
        };
    };
    const NNSG3dResDict *nodeDict;
    NNSG3dResMat        *pResMat;
    NNSG3dResShp        *pResShp;
    fx32                 posScale;
    fx32                 invPosScale;
    NNSG3dJntScaleFunc   jntScaleFunc;
    NNSG3dFuncJntMtx     jntMtxFunc;
    NNSG3dFuncMatTexMtx  matTexMtxFunc;
    NNSG3dMatAnmResult   tmpMatAnmResult;
    NNSG3dJntAnmResult   tmpJntAnmResult;
    NNSG3dVisAnmResult   tmpVisAnmResult;
} NNSG3dRS;

#define NNS_G3D_SBC_BYTE(pRS, i) (((const u8 *)(pRS)->c)[i])
#define NNS_G3D_SBC_ADVANCE(pRS, n) \
    ((pRS)->c = (const NNSG3dSbcNodeDesc *)((const u8 *)(pRS)->c + (n)))

/* track descriptor words of the material and texture SRT animations */
#define NNS_G3D_ANMTRACK_CONST      0x20000000
#define NNS_G3D_ANMTRACK_FX16       0x10000000
#define NNS_G3D_ANMTRACK_COUNT_MASK 0x0000ffff

/* Name of a dictionary entry: 16 bytes. */
typedef union NNSG3dResName {
    char name[16];
    u32 val[4];
} NNSG3dResName;

/* Material color animation (NSBMA): dictionary of NNSG3dResMatAnmData at +8. */
typedef struct NNSG3dResMatAnm {
    NNSG3dResAnmHdr hdr;
    u16 numFrame;
    u16 dummy;
    NNSG3dResDict dict;
} NNSG3dResMatAnm;

/* Per-material color tracks; each word is a track descriptor. */
typedef struct NNSG3dResMatAnmData {
    u32 diffuse;
    u32 ambient;
    u32 specular;
    u32 emission;
    u32 polygonAlpha;
} NNSG3dResMatAnmData;

/* Texture SRT animation (NSBTA): dictionary of NNSG3dResTexSRTAnmData at +8. */
typedef struct NNSG3dResTexSRTAnm {
    NNSG3dResAnmHdr hdr;
    u16 numFrame;
    u16 dummy;
    NNSG3dResDict dict;
} NNSG3dResTexSRTAnm;

/* A track: descriptor word and byte offset of its keys from the resource. */
typedef struct NNSG3dTexSRTTrack {
    u32 info;
    u32 offset;
} NNSG3dTexSRTTrack;

typedef struct NNSG3dResTexSRTAnmData {
    NNSG3dTexSRTTrack scaleS;
    NNSG3dTexSRTTrack scaleT;
    NNSG3dTexSRTTrack rot;
    NNSG3dTexSRTTrack transS;
    NNSG3dTexSRTTrack transT;
} NNSG3dResTexSRTAnmData;

/* Texture pattern animation (NSBTP): dictionary at +0xc. */
typedef struct NNSG3dResTexPatAnm {
    NNSG3dResAnmHdr hdr;
    u16 numFrame;
    u8  numTex;
    u8  numPltt;
    u16 ofsTexName;
    u16 ofsPlttName;
    NNSG3dResDict dict;
} NNSG3dResTexPatAnm;

/* Extra NNSG3dJntAnmResult.flag bit set by the Maya scale handler: scaleEx0 holds the parent's inverse scale. */
#define NNS_G3D_JNTANM_RESULTFLAG_HAS_PARENT_SCALE 0x20

/* Geometry engine matrix command ids as passed to the command writer. */
#define NNS_G3D_GECMD_MTX_MULT_4x3 0x19
#define NNS_G3D_GECMD_MTX_MULT_3x3 0x1a
#define NNS_G3D_GECMD_MTX_SCALE    0x1b
#define NNS_G3D_GECMD_MTX_TRANS    0x1c

typedef struct NNSG3dVec3Fx {
    fx32 x;
    fx32 y;
    fx32 z;
} NNSG3dVec3Fx;

/* Row of the Maya scale table: the stored inverse scale, then the unused rest of the 0x18-byte record. */
typedef struct NNSG3dMayaScaleRow {
    NNSG3dVec3Fx invScale;
    fx32         reserved0C[3];
} NNSG3dMayaScaleRow;

/* Display list record for a texture matrix load: command word, then its parameters. */
typedef struct NNSG3dTexMtxCmd {
    u32     op;
    u32     mtxMode;
    MtxFx44 mtx;
    u32     mtxModeRestore;
} NNSG3dTexMtxCmd;

typedef struct NNSG3dTexMtxCmd43 {
    u32     op;
    u32     mtxMode;
    MtxFx43 mtx;
    u32     mtxModeRestore;
} NNSG3dTexMtxCmd43;

/* Texture matrix builder selected by the low three bits of NNSG3dMatAnmResult.flag. */
typedef void (*NNSG3dTexMtxBuildFunc)(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);

/* Visibility animation (NSBVA): one bit per node per frame. */
typedef struct NNSG3dResVisAnm {
    NNSG3dResAnmHdr hdr;
    u16 numFrame;
    u16 numNode;
    u8  reserved08[4];
    u32 visData[1];
} NNSG3dResVisAnm;

/* Frame value record of a texture pattern animation: frame index, texture and palette names. */
typedef struct NNSG3dResTexPatAnmFV {
    u16 idxFrame;
    u8  idTex;
    u8  idPltt;
} NNSG3dResTexPatAnmFV;

/* Texture block of a texture resource (NSBTX), 0x40 bytes before the texture dictionary. */
typedef struct NNSG3dResTexInfo {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
} NNSG3dResTexInfo;

typedef struct NNSG3dResTex4x4Info {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
    u32 ofsTexPlttIdx;
} NNSG3dResTex4x4Info;

typedef struct NNSG3dResPlttInfo {
    u32 vramKey;
    u16 sizePltt;
    u16 flag;
    u16 ofsDict;
    u16 dummy_;
    u32 ofsPlttData;
} NNSG3dResPlttInfo;

typedef struct NNSG3dResTex {
    u32                 header[2];
    NNSG3dResTexInfo    texInfo;
    NNSG3dResTex4x4Info tex4x4Info;
    NNSG3dResPlttInfo   plttInfo;
    NNSG3dResDict       dictTex;
} NNSG3dResTex;

/* Texture dictionary entry: TEXIMAGE_PARAM and the packed original size. */
typedef struct NNSG3dResDictTexData {
    u32 texImageParam;
    u32 extraParam;
} NNSG3dResDictTexData;

/* Palette dictionary entry. */
typedef struct NNSG3dResDictPlttData {
    u16 offset;
    u16 flag;
} NNSG3dResDictPlttData;

#endif
