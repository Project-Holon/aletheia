/*
 * function: func_0206C0C4
 * address:  0x0206C0C4
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D NNSi_G3dFuncSbc_NODEDESC (sbc.c): the SBC node-descriptor
 * opcode (4 bytes, +1 per MTX_RESTORE/MTX_STORE option), callback slot 6
 * (cbVecFunc +0x24, cbVecTiming +0x92). Records the node in currentNodeDesc
 * (+0xae) and sets RSFLAG bit 4; with bit 10 set it only steps the cursor.
 * Otherwise it resolves the joint's SRT: from the render object's recorded
 * result (recJntAnm +0x34, 0x58 per node, reused unless RSFLAG_OPT_RECORD
 * 0x80), from the blend callback (+0x10 anmJnt, +0x14 funcBlendJnt), or from
 * the model's own NodeData (pResNodeInfo +0xd4): translation, the rotation as
 * zero / pivot-compressed / full 3x3, then the scale via funcJntScale (+0xe8).
 * Timing B hands the result to funcJntMtx (+0xec) unless NOGECMD.
 *
 * The pivot table at 0x020A1974 is NNS's pivotUtil_[9][4] (u8): the four
 * pool words 0x020A1974..77 are its four columns, now attested sole-ref/self
 * (the cap docs/notes/pkt_0206BEA0.c.txt recorded predates that class).
 * Lever for the last 8 bytes: the C and D entries are ternaries
 * `(flag & 0x200) ? -B : B`, which mwcc keeps branchy; the if-statement form
 * `if (flag & 0x200) B = -B;` is if-converted to predicated moves.
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to DIFF.
 *
 * symbols:
 *   g_020A1974     0x020A1974  data  a1
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_020834A8  0x020834A8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef short fx16;
typedef int fx32;
typedef int BOOL;

typedef struct { fx32 x, y, z; } VecFx32;
typedef union {
    struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22; };
    fx32 a[9];
} MtxFx33;

typedef struct {
    u32     flag;
    VecFx32 scale;
    VecFx32 scaleEx0;
    VecFx32 scaleEx1;
    MtxFx33 rot;
    VecFx32 trans;
} JntAnmResult;

typedef struct RenderObj RenderObj;
typedef BOOL (*BlendJntFunc)(JntAnmResult *, void *, u32);
struct RenderObj {
    u8 pad00[0x10];
    void *anmJnt;
    BlendJntFunc funcBlendJnt;
    u8 pad18[0x34 - 0x18];
    JntAnmResult *recJntAnm;
};

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} Dict;
typedef struct { u16 sizeUnit; u16 sizeHeader; } DictEntryHeader;
typedef struct { Dict dict; } ResNodeInfo;
typedef struct { u16 flag; fx16 _00; } ResNodeData;

typedef struct RS RS;
typedef void (*CbFunc)(RS *);
typedef void (*JntScaleFunc)(JntAnmResult *, const fx32 *, const u8 *, u32);
typedef void (*JntMtxFunc)(const JntAnmResult *);
struct RS {
    u8 *c;
    RenderObj *pRenderObj;
    u32 flag;
    CbFunc cbVecFunc[32];
    u8 cbVecTiming[32];
    u8 currentNode;
    u8 currentMat;
    u8 currentNodeDesc;
    u8 dummy_;
    void *pMatAnmResult;
    JntAnmResult *pJntAnmResult;
    u8 padb8[0xd4 - 0xb8];
    ResNodeInfo *pResNodeInfo;
    void *pResMat;
    void *pResShp;
    void *funcE0;
    void *funcE4;
    JntScaleFunc funcJntScale;
    JntMtxFunc funcJntMtx;
    u8 padf0[0x12c - 0xf0];
    JntAnmResult tmpJntAnmResult;
};

extern const u8 g_020A1974[][4];

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_020834A8(void *p);

static inline void *GetResDataByIdx(const Dict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const DictEntryHeader *hdr = (const DictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)((u32)hdr + sizeof(DictEntryHeader) + hdr->sizeUnit * idx);
    }
    return 0;
}

static inline const ResNodeData *GetNodeDataByIdx(const ResNodeInfo *info, u32 idx)
{
    if (info) {
        const u32 *data = (const u32 *)GetResDataByIdx(&info->dict, idx);
        if (data)
            return (const ResNodeData *)((u8 *)info + *data);
    }
    return 0;
}

static inline u32 CheckPossibilityOfCallback(RS *rs, u32 cmd)
{
    return rs->cbVecFunc[cmd] ? rs->cbVecTiming[cmd] : 0;
}

static inline u32 CallBackCheck_A(RS *rs, u32 cmd, u32 *pTiming)
{
    if (*pTiming == 1) {
        rs->flag &= ~0x40;
        (*rs->cbVecFunc[cmd])(rs);
        *pTiming = CheckPossibilityOfCallback(rs, cmd);
        return rs->flag & 0x40;
    }
    return 0;
}

static inline u32 CallBackCheck_B(RS *rs, u32 cmd, u32 *pTiming)
{
    if (*pTiming == 2) {
        rs->flag &= ~0x40;
        (*rs->cbVecFunc[cmd])(rs);
        *pTiming = CheckPossibilityOfCallback(rs, cmd);
        return rs->flag & 0x40;
    }
    return 0;
}

static inline u32 CallBackCheck_C(RS *rs, u32 cmd, u32 timing)
{
    if (timing == 3) {
        rs->flag &= ~0x40;
        (*rs->cbVecFunc[cmd])(rs);
        return rs->flag & 0x40;
    }
    return 0;
}

void func_0206C0C4(RS *rs, u32 opt)
{
    u32 cmdLen = 4;
    u32 idxNode = rs->c[1];
    u32 timing;
    u32 cbFlag;

    rs->currentNodeDesc = (u8)idxNode;
    rs->flag |= 0x10;

    if (rs->flag & 0x400) {
        if (opt == 0x40 || opt == 0x60)
            cmdLen++;
        if (opt == 0x20 || opt == 0x60) {
            cmdLen++;
            if (!(rs->flag & 0x100)) {
                u32 arg = rs->c[4];
                func_0206DDA4(0x14, &arg, 1);
            }
        }
        rs->c += cmdLen;
        return;
    }

    if (opt == 0x40 || opt == 0x60) {
        u32 arg;
        if (opt == 0x40)
            arg = rs->c[4];
        else
            arg = rs->c[5];
        cmdLen++;
        if (!(rs->flag & 0x100))
            func_0206DDA4(0x14, &arg, 1);
    }

    rs->pJntAnmResult = &rs->tmpJntAnmResult;
    timing = CheckPossibilityOfCallback(rs, 6);
    if (!CallBackCheck_A(rs, 6, &timing)) {
        JntAnmResult *pResult;
        BOOL isRead;

        if (rs->pRenderObj->recJntAnm) {
            pResult = &rs->pRenderObj->recJntAnm[idxNode];
            isRead = !(rs->flag & 0x80);
        } else {
            pResult = &rs->tmpJntAnmResult;
            isRead = 0;
        }

        if (!isRead) {
            pResult->flag = 0;
            if (!rs->pRenderObj->anmJnt ||
                !(*rs->pRenderObj->funcBlendJnt)(pResult, rs->pRenderObj->anmJnt, idxNode)) {
                const ResNodeData *nd = GetNodeDataByIdx(rs->pResNodeInfo, idxNode);
                const fx32 *p = (const fx32 *)(nd + 1);

                if (nd->flag & 1) {
                    pResult->flag |= 4;
                } else {
                    pResult->trans.x = p[0];
                    pResult->trans.y = p[1];
                    pResult->trans.z = p[2];
                    p += 3;
                }

                if (nd->flag & 2) {
                    pResult->flag |= 2;
                } else if (nd->flag & 8) {
                    fx32 B;
                    fx32 A;
                    u32 idxPivot = (nd->flag & 0xf0) >> 4;

                    A = ((const fx16 *)p)[0];
                    B = ((const fx16 *)p)[1];
                    func_020834A8(&pResult->rot);
                    pResult->rot.a[idxPivot] = (nd->flag & 0x100) ? -0x1000 : 0x1000;
                    pResult->rot.a[g_020A1974[idxPivot][0]] = A;
                    pResult->rot.a[g_020A1974[idxPivot][1]] = B;
                    pResult->rot.a[g_020A1974[idxPivot][2]] = (nd->flag & 0x200) ? -B : B;
                    pResult->rot.a[g_020A1974[idxPivot][3]] = (nd->flag & 0x400) ? -A : A;
                    p++;
                } else {
                    const fx16 *q = (const fx16 *)p;
                    pResult->rot._00 = nd->_00;
                    pResult->rot._01 = q[0];
                    pResult->rot._02 = q[1];
                    pResult->rot._10 = q[2];
                    pResult->rot._11 = q[3];
                    pResult->rot._12 = q[4];
                    pResult->rot._20 = q[5];
                    pResult->rot._21 = q[6];
                    pResult->rot._22 = q[7];
                    p += 4;
                }
                (*rs->funcJntScale)(pResult, p, rs->c, nd->flag);
            }
        }
        rs->pJntAnmResult = pResult;
    }

    if (!CallBackCheck_B(rs, 6, &timing) && !(rs->flag & 0x100))
        (*rs->funcJntMtx)(rs->pJntAnmResult);
    rs->pJntAnmResult = 0;

    cbFlag = CallBackCheck_C(rs, 6, timing);

    if (opt == 0x20 || opt == 0x60) {
        cmdLen++;
        if (!cbFlag && !(rs->flag & 0x100)) {
            u32 arg = rs->c[4];
            func_0206DDA4(0x13, &arg, 1);
        }
    }
    rs->c += cmdLen;
}
