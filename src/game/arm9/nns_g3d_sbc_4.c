/*
 * file:     nns_g3d_sbc_4.c
 * unit:     yes
 * function: func_0206BEA0, func_0206BF50, func_0206C024, func_0206C0C4
 * address:  0x0206BEA0
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
 *   tbl_020A82C8   0x020A82C8  data
 *   func_0206DC00  0x0206DC00  arm
 *   tbl_020A82D8   0x020A82D8  data
 *   g_020A1974     0x020A1974  data  a1
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_020834A8  0x020834A8  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} Dict;

typedef struct {
    u16 sizeUnit;
    u16 sizeHeader;
} DictEntryHeader;

typedef struct {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    Dict dict;
} ResMat;

typedef struct {
    u16 tag;
    u16 size;
} ItemTag;

typedef struct Ctx_0206BEA0 {
    u8  *c;
    u32 p04;
    u32 flag;
    u8  p0c[0xad - 0x0c];
    u8  currentMat;
    u8  pad[0xd8 - 0xae];
    ResMat *pResMat;
} Ctx_0206BEA0;

typedef struct Obj0206BF50 Obj0206BF50;

struct Obj0206BF50 {
    u32   f00;
    u32   f04;
    u32   f08;
    u8    pad0c[0x20 - 0x0c];
    void (*f20)(Obj0206BF50 *);
    u8    pad24[0x91 - 0x24];
    u8    f91;
};

typedef struct Arg0206BF50 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
} Arg0206BF50;

typedef struct {
    Dict dict;
} ResShp;

typedef struct Ctx_0206C024 {
    u8  *c;
    u32 p04;
    u32 flag;
    u8  p0c[0xdc - 0x0c];
    ResShp *pResShp;
} Ctx_0206C024;

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

extern void func_0206DC00(const u32 *src, u32 sz);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_020834A8(void *p);
void func_0206BEA0(Ctx_0206BEA0 *rs, u32 opt);
void func_0206BF50(Obj0206BF50 *p, u32 unused, Arg0206BF50 *a);
void func_0206C024(Ctx_0206C024 *rs, u32 opt);
void func_0206C0C4(RS *rs, u32 opt);
extern const u8 g_020A1974[][4];




extern void (*tbl_020A82C8[])(Ctx_0206BEA0 *, u32, const ItemTag *, u32);




static inline void *GetResDataByIdx(const Dict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const DictEntryHeader *hdr = (const DictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)((u32)hdr + sizeof(DictEntryHeader) + hdr->sizeUnit * idx);
    }
    return 0;
}




static inline const ItemTag *GetMatDataByIdx(const ResMat *mat, u32 idx)
{
    if (mat) {
        const u32 *data = (const u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data)
            return (const ItemTag *)((u8 *)mat + *data);
    }
    return 0;
}




/*
 * NNSi_G3dFuncSbc_MAT: the SBC MAT opcode (2 bytes). Gate on rs->flag (0x200 skip; bit 0 / bit 3 plus
 * rs->currentMat at +0xad decide whether the material is re-sent), look the
 * material up in rs->pResMat (+0xd8, dictionary at +4) and dispatch through
 * the material-type table on its item tag with (rs, opt, mat, idxMat).
 *
 * IDENTIFICATION: this cluster is the NitroSystem G3D SBC interpreter (sbc.c).
 * The two things that closed it after 29 bytes of register tie: (1) handlers
 * take (rs, opt) and the dispatched function takes FOUR arguments
 * (rs, opt, data, idx), which pins data in r2 and idx in r3 across the blx;
 * (2) the lookup is the two NNS inline accessors (NNS_G3dGetResDataByIdx and
 * the Get*DataByIdx wrapper that null-tests the resource itself), written as
 * static inline, which reproduces the doubled zero arm without gotos.
 * Byte-identical under dsi/1.1p1 as well; pinned ../2.0/sp2 with the cluster.
 */
void func_0206BEA0(Ctx_0206BEA0 *rs, u32 opt)
{
    if (!(rs->flag & 0x200)) {
        u32 idxMat = *(rs->c + 1);
        if ((rs->flag & 1) || !(rs->flag & 8) || idxMat != rs->currentMat) {
            const ItemTag *mat = GetMatDataByIdx(rs->pResMat, idxMat);
            (*tbl_020A82C8[mat->tag])(rs, opt, mat, idxMat);
        }
    }
    rs->c += 2;
}




/*
 * The four-stop hook walk of the 0x0206B94C family, one slot over: the state
 * byte at +0x91 is read through the +0x20 hook (zero when the hook is null),
 * and stops 1, 2 and 3 each clear bit 6 of the status word at +0x08 and call
 * the hook. Only the flag/0x100 gate between stops 1 and 2 does work, handing
 * func_0206DC00 the second argument's own +0x08 offset and its +0x0c word.
 *
 * PINNED ../2.0/sp2 on the re-read/forward tell (docs/FRONTEND-PINS.md), the
 * same measurement as src/matched/func_0206B94C.c one packet over. The hook
 * dispatch appears THREE times, at 0x0206BF74..0x0206BF88,
 * 0x0206BFD8..0x0206BFEC and 0x0206C008..0x0206C01C, and every time the image
 * loads the hook pointer AFTER the flag store has retired: `ldr r1, [r5, #8]`
 * (`08 10 95 e5`) / `mov r0, r5` / `bic r1, r1, #0x40` (`40 10 c1 e3`) /
 * `str r1, [r5, #8]` (`08 10 85 e5`) / `ldr r1, [r5, #0x20]` (`20 10 95 e5`) /
 * `blx r1` (`31 ff 2f e1`). dsi/1.1p1 -O4,p hoists that load above the
 * read-modify-write at all three sites: the same 212 bytes, 42 concrete bytes
 * out. Under the pin the same C is 212 bytes, 0 mismatches.
 *
 * NOT a 1.2 candidate despite the three `blx r1`: the returns are
 * `popne {r4, r5, r6, pc}` / `pop {r4, r5, r6, pc}`, not the ARMv4T pair.
 */
void func_0206BF50(Obj0206BF50 *p, u32 unused, Arg0206BF50 *a)
{
    u32 st;
    u32 flag;

    st = p->f20 ? p->f91 : 0;
    if (st == 1) {
        p->f08 &= ~0x40;
        p->f20(p);
        st = p->f20 ? p->f91 : 0;
        flag = p->f08 & 0x40;
    } else {
        flag = 0;
    }
    if (flag == 0) {
        if (!(p->f08 & 0x100)) {
            func_0206DC00((const u32 *)((u8 *)a + a->f08), a->f0c);
        }
    }
    if (st == 2) {
        p->f08 &= ~0x40;
        p->f20(p);
        st = p->f20 ? p->f91 : 0;
    }
    if (st == 3) {
        p->f08 &= ~0x40;
        p->f20(p);
    }
}



extern void (*tbl_020A82D8[])(Ctx_0206C024 *, u32, const ItemTag *, u32);



static inline const ItemTag *GetShpDataByIdx(const ResShp *mat, u32 idx)
{
    if (mat) {
        const u32 *data = (const u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data)
            return (const ItemTag *)((u8 *)mat + *data);
    }
    return 0;
}



/*
 * NNSi_G3dFuncSbc_SHP: the SBC SHP opcode (2 bytes). Gate on rs->flag (0x200 skip, bit 0
 * material valid, bit 1 not-drawn), look the shape up in rs->pResShp (+0xdc,
 * dictionary at +0) and dispatch through the shape-type table on its item tag
 * with (rs, opt, shp, idxShp).
 *
 * IDENTIFICATION: this cluster is the NitroSystem G3D SBC interpreter (sbc.c).
 * The two things that closed it after 29 bytes of register tie: (1) handlers
 * take (rs, opt) and the dispatched function takes FOUR arguments
 * (rs, opt, data, idx), which pins data in r2 and idx in r3 across the blx;
 * (2) the lookup is the two NNS inline accessors (NNS_G3dGetResDataByIdx and
 * the Get*DataByIdx wrapper that null-tests the resource itself), written as
 * static inline, which reproduces the doubled zero arm without gotos.
 * Byte-identical under dsi/1.1p1 as well; pinned ../2.0/sp2 with the cluster.
 */
void func_0206C024(Ctx_0206C024 *rs, u32 opt)
{
    if (!(rs->flag & 0x200) && (rs->flag & 1) && !(rs->flag & 2)) {
        u32 idxShp = *(rs->c + 1);
        const ItemTag *shp = GetShpDataByIdx(rs->pResShp, idxShp);
        (*tbl_020A82D8[shp->tag])(rs, opt, shp, idxShp);
    }
    rs->c += 2;
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


/*
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
 */
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
