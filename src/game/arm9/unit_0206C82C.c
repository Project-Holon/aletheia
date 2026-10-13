/*
 * file:     unit_0206C82C.c
 * unit:     yes
 * function: func_0206C82C, func_0206CB8C, func_0206D2E8, func_0206D3C4, func_0206D434, func_0206D778
 * address:  0x0206C82C
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
 *   g_renderState     0x02148B4C  data
 *   g_020A8370     0x020A8370  data
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DC98  0x0207DC98  arm
 *   func_0206ADBC  0x0206ADBC  arm
 *   func_0206ADF4  0x0206ADF4  arm
 *   func_0206AAD4  0x0206AAD4  arm
 *   func_0207B5C0  0x0207B5C0  arm
 *   func_0207BE14  0x0207BE14  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_02082AA8  0x02082AA8  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   g_0214A1B4     0x0214A1B4  data
 *   func_02082AC0  0x02082AC0  arm
 *   func_0207D918  0x0207D918  arm
 *   func_0207D934  0x0207D934  arm
 *   func_0207DCC8  0x0207DCC8  arm
 *   func_0207D8E0  0x0207D8E0  arm
 *   func_0206DC00  0x0206DC00  arm
 *   g_020A82B8     0x020A82B8  data
 *   func_0206DE88  0x0206DE88  arm
 *   g_020A82E8     0x020A82E8  data
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { fx32 _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33; } MtxFx44;

typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22, _30, _31, _32; } MtxFx43;

typedef struct {
    u32 cmd;
    u32 prm[2];
    MtxFx43 mtx;
    VecFx32 scale;
} BBData;

typedef unsigned short u16;

typedef long long fx64;

typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22; } MtxFx33;

typedef struct {
    MtxFx43 invM;
    MtxFx33 invN;
} EvpMtx;

typedef struct {
    MtxFx44 M;
    MtxFx33 N;
} EvpCache;

struct S0206D2E8 {
    u8 *cur;        /* 0x00 */
    u32 pad4;
    u32 flags;      /* 0x08 */
    u8 pad0c[0x34 - 0x0c];
    void (*cb)(struct S0206D2E8 *);  /* 0x34 */
    u8 pad38[0x96 - 0x38];
    u8 mode;        /* 0x96 */
};

struct Obj {
    u32 f00;
    u32 p04;
    u32 f08;
    u32 p0c[(0xe0 - 0x0c) / 4];
    u32 fe0;
    u32 fe4;
};

typedef short s16;

typedef struct {
    u32 w0;
    u32 w4;
    u32 op;
    u32 prm;
} TexImageCmd;

typedef struct {
    u8  pad00[0x10];
    u32 prmTexImage;
    u8  pad14[0x2c - 0x14];
    u16 origWidth;
    u16 origHeight;
} MatAnmResult;

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} Dict;

typedef struct { u16 sizeUnit; u16 sizeHeader; } DictEntryHeader;

typedef struct { u16 ofsDictTexToMatList; u16 ofsDictPlttToMatList; Dict dict; } ResMat;

typedef struct {
    u16 itemTag;
    u16 size;
    u8  pad04[0x1e - 0x04];
    u16 flag;
} ResMatData;

typedef struct {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u32 ofsShp;
    u32 ofsEvpMtx;
} ResMdl;

typedef struct {
    void *hintNext;
    ResMdl *resMdl;
} RenderObj;

typedef struct RS RS;

typedef void (*CbFunc)(RS *);

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
    MatAnmResult *pMatAnmResult;
    u8 padb4[0xcc - 0xb4];
    u32 isEvpCached[2];
    u8 padd4[0xd8 - 0xd4];
    ResMat *pResMat;
};

typedef struct {
    u32 cmd0;
    u32 mtxmode;
    MtxFx44 prjMtx;
    u32 cmd1;
    MtxFx43 cameraMtx;
    u8 pad7c[0xbc - 0x7c];
    MtxFx33 unkBC;
    VecFx32 unkE0;
    u8 padec[0xfc - 0xec];
    u32 flag;
} Glb;

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0206DB80(void);
extern int  func_0207DC98(MtxFx44 *m);
extern u32 *func_0206ADBC(void);
extern u32 *func_0206ADF4(void);
extern u32 *func_0206AAD4(void);
extern void func_0207B5C0(const MtxFx43 *src, MtxFx44 *dst);
extern void func_0207BE14(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
extern fx32 func_0207CBD0(const VecFx32 *v);
extern void func_0207CCA4(const VecFx32 *src, VecFx32 *dst);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern void func_02082AA8(const void *src, volatile void *dst, u32 n);
extern void func_02082AC0(u32 v, void *p, u32 n);
extern void func_0207D918(const MtxFx43 *m);
extern void func_0207D934(const MtxFx33 *m);
extern int  func_0207DCC8(MtxFx33 *m);
extern void func_0207D8E0(const void *m);
extern void func_0206DC00(const u32 *src, u32 sz);
extern void func_0206DE88(void *a, void *b);
void func_0206C82C(RS *rs, u32 opt);
void func_0206CB8C(RS *rs, u32 opt);
void func_0206D2E8(struct S0206D2E8 *s);
void func_0206D3C4(struct Obj *o, u32 which);
void func_0206D434(RS *rs, u32 opt);
void func_0206D778(RS *rs, u32 opt);
extern Glb g_renderState;
extern BBData g_020A8370;
extern EvpCache g_0214A1B4[];
extern TexImageCmd g_020A82B8;
extern MtxFx44 g_020A82E8;

#define GXFIFO (*(volatile u32 *)0x04000400)

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
 * NitroSystem G3D NNSi_G3dFuncSbc_BBY (sbc.c): the Y-axis billboard opcode,
 * callback slot 8 (cbVecFunc +0x2c, cbVecTiming +0x94). The sibling of
 * func_0206C524 (BB) with its own static command block at 0x020A8370: after
 * the translation row and row lengths it builds the upper 3x3 of the block's
 * matrix from the clip matrix's second row (row0 = (m._11, -m._10, 0),
 * row1 = m row 1, both VEC_Normalize'd by func_0207CCA4, row2 = their
 * VEC_CrossProduct, func_0207CAE8).
 *
 * Levers: a third pointer local for the block's matrix (loaded into r7 in the
 * prologue with the other two), and the six row stores written in reverse
 * field order (_12 first, _00 last).
 * DISCRIMINATING PIN: dsi/1.1p1 is DIFF.
 */
void func_0206C82C(RS *rs, u32 opt)
{
    u32 cmdLen = 2;
    VecFx32 *trans = (VecFx32 *)&g_020A8370.mtx._30;
    VecFx32 *scale = &g_020A8370.scale;
    MtxFx43 *mtx = &g_020A8370.mtx;

    if (rs->flag & 0x200) {
        if (opt == 0x40 || opt == 0x60)
            cmdLen++;
        if (opt == 0x20 || opt == 0x60)
            cmdLen++;
        rs->c += cmdLen;
        return;
    } else {
        u32 timing;
        u32 cbFlag;

        if (opt == 0x40 || opt == 0x60) {
            cmdLen++;
            if (!(rs->flag & 0x100)) {
                u32 arg;
                if (opt == 0x40)
                    arg = rs->c[2];
                else
                    arg = rs->c[3];
                func_0206DDA4(0x14, &arg, 1);
            }
        }

        timing = CheckPossibilityOfCallback(rs, 8);
        cbFlag = CallBackCheck_A(rs, 8, &timing);

        if (!(rs->flag & 0x100) && !cbFlag) {
            MtxFx44 m;

            func_0206DB80();
            GXFIFO = 0x00151110;
            GXFIFO = 0;
            GXFIFO = 0;
            while (func_0207DC98(&m))
                ;
            if (g_renderState.flag & 1) {
                MtxFx44 tmp;
                func_0207B5C0((const MtxFx43 *)func_0206ADBC(), &tmp);
                func_0207BE14(&m, &tmp, &m);
            } else if (g_renderState.flag & 2) {
                MtxFx44 tmp;
                func_0207B5C0(&g_renderState.cameraMtx, &tmp);
                func_0207BE14(&m, &tmp, &m);
            }
            trans->x = m._30;
            trans->y = m._31;
            trans->z = m._32;
            scale->x = func_0207CBD0((VecFx32 *)&m._00);
            scale->y = func_0207CBD0((VecFx32 *)&m._10);
            scale->z = func_0207CBD0((VecFx32 *)&m._20);

            mtx->_12 = m._12;
            mtx->_11 = m._11;
            mtx->_10 = m._10;
            mtx->_02 = 0;
            mtx->_01 = -m._10;
            mtx->_00 = m._11;
            func_0207CCA4((VecFx32 *)&mtx->_00, (VecFx32 *)&mtx->_00);
            func_0207CCA4((VecFx32 *)&mtx->_10, (VecFx32 *)&mtx->_10);
            func_0207CAE8((VecFx32 *)&mtx->_00, (VecFx32 *)&mtx->_10, (VecFx32 *)&mtx->_20);

            if (g_renderState.flag & 1) {
                GXFIFO = 0x00171012;
                func_02082AA8(&g_020A8370.prm[0], &GXFIFO, 8);
                func_02082AA8(func_0206ADF4(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                func_02082AA8(&g_020A8370.mtx, &GXFIFO, 0x3c);
            } else if (g_renderState.flag & 2) {
                GXFIFO = 0x00171012;
                func_02082AA8(&g_020A8370.prm[0], &GXFIFO, 8);
                func_02082AA8(func_0206AAD4(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                func_02082AA8(&g_020A8370.mtx, &GXFIFO, 0x3c);
            } else {
                func_02082AA8(&g_020A8370, &GXFIFO, 0x48);
            }
        }

        cbFlag = CallBackCheck_C(rs, 8, timing);

        if (opt == 0x20 || opt == 0x60) {
            cmdLen++;
            if (!cbFlag && !(rs->flag & 0x100)) {
                u32 arg = rs->c[2];
                func_0206DDA4(0x13, &arg, 1);
            }
        }
    }
    rs->c += cmdLen;
}

#define REG_MTX_MODE     (*(volatile u32 *)0x04000440)

#define REG_MTX_STORE    (*(volatile u32 *)0x0400044C)

#define REG_MTX_RESTORE  (*(volatile u32 *)0x04000450)

#define REG_MTX_IDENTITY (*(volatile u32 *)0x04000454)

static inline u32 BitVecCheck(const u32 *vec, u32 idx)
{
    return vec[idx >> 5] & (1 << (idx & 31));
}

static inline void BitVecSet(u32 *vec, u32 idx)
{
    vec[idx >> 5] |= 1 << (idx & 31);
}

/*
 * NitroSystem G3D NNSi_G3dFuncSbc_NODEMIX (sbc.c): the SBC envelope opcode
 * (3 + 3*numMtx bytes). For each (idxMtxSrc, idxNode, ratio) triple it makes
 * sure the node's envelope matrices are in the static cache at 0x0214A1B4
 * (0x64 bytes per node: MtxFx44 M then MtxFx33 N; cached bit per node in the
 * RS word array at +0xcc): restore idxMtxSrc, multiply by the model's inverse
 * bind matrices (evpMtx, 0x54 per node, at resMdl + ofsEvpMtx), read the clip
 * and vector matrices back. The weighted sums are accumulated with the N term
 * of each node deferred one iteration (overlapping the hardware read-back),
 * then loaded (func_0207D8E0) and stored to idxMtxDest.
 *
 * The two bss pool words 0x0214A1B4 / 0x0214A1F4 are the cache's M and N
 * columns (0x0214A1F4 = base + 0x40); both resolve sole-ref/self, which lifts
 * the cap docs/notes/pkt_0206CB8C.c.txt recorded.
 *
 * Levers, all measured: the cache addresses are (column base + off) with
 * off = idxNode * sizeof(EvpCache) a named local (smulbb, spilled at sp+4) --
 * &cache[idx].M / &cache[idx].N lets mwcc derive N from M and loses 8 bytes;
 * the cached bit is read and set through two inline bit-vector helpers (the
 * word is re-loaded for the set); pM is a function-scope local declared
 * before pN; `numMtx = rs->c[2]` and `p = rs->c + 3` are separate reads;
 * the bit test comes before the pM assignment; sumN is declared before sumM
 * (sumM at the lower address, cleared together as 0x54 bytes).
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to DIFF.
 */
void func_0206CB8C(RS *rs, u32 opt)
{
    const EvpMtx *evpMtx;
    u32 numMtx;
    u32 i;
    fx64 w = 0;
    MtxFx33 sumN;
    MtxFx43 sumM;
    u8 *p;
    const ResMdl *mdl = rs->pRenderObj->resMdl;
    MtxFx44 *pM;
    MtxFx33 *pN;

    numMtx = rs->c[2];
    evpMtx = (const EvpMtx *)((u8 *)mdl + mdl->ofsEvpMtx);
    p = rs->c + 3;
    func_02082AC0(0, &sumM, sizeof(sumM) + sizeof(sumN));
    func_0206DB80();

    REG_MTX_MODE = 0;
    REG_MTX_STORE = 1;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;

    for (i = 0; i < numMtx; ++i) {
        u32 idxNode = p[1];
        u32 off = idxNode * sizeof(EvpCache);
        u32 cached = BitVecCheck(rs->isEvpCached, idxNode);
        pM = (MtxFx44 *)((u8 *)&g_0214A1B4[0].M + off);

        if (!cached) {
            BitVecSet(rs->isEvpCached, idxNode);
            REG_MTX_RESTORE = p[0];
            REG_MTX_MODE = 1;
            func_0207D918(&evpMtx[idxNode].invM);
        }

        if (i != 0) {
            sumN._00 += (w * pN->_00) >> 12;
            sumN._01 += (w * pN->_01) >> 12;
            sumN._02 += (w * pN->_02) >> 12;
            sumN._10 += (w * pN->_10) >> 12;
            sumN._11 += (w * pN->_11) >> 12;
            sumN._12 += (w * pN->_12) >> 12;
            sumN._20 += (w * pN->_20) >> 12;
            sumN._21 += (w * pN->_21) >> 12;
            sumN._22 += (w * pN->_22) >> 12;
        }

        if (!cached) {
            while (func_0207DC98(pM))
                ;
            REG_MTX_MODE = 2;
            func_0207D934(&evpMtx[idxNode].invN);
        }

        w = p[2] << 4;
        sumM._00 += (w * pM->_00) >> 12;
        sumM._01 += (w * pM->_01) >> 12;
        sumM._02 += (w * pM->_02) >> 12;
        sumM._10 += (w * pM->_10) >> 12;
        sumM._11 += (w * pM->_11) >> 12;
        sumM._12 += (w * pM->_12) >> 12;
        sumM._20 += (w * pM->_20) >> 12;
        sumM._21 += (w * pM->_21) >> 12;
        sumM._22 += (w * pM->_22) >> 12;
        sumM._30 += (w * pM->_30) >> 12;
        sumM._31 += (w * pM->_31) >> 12;
        sumM._32 += (w * pM->_32) >> 12;

        p += 3;
        pN = (MtxFx33 *)((u8 *)&g_0214A1B4[0].N + off);
        if (!cached) {
            while (func_0207DCC8(pN))
                ;
        }
    }

    sumN._00 += (w * pN->_00) >> 12;
    sumN._01 += (w * pN->_01) >> 12;
    sumN._02 += (w * pN->_02) >> 12;
    sumN._10 += (w * pN->_10) >> 12;
    sumN._11 += (w * pN->_11) >> 12;
    sumN._12 += (w * pN->_12) >> 12;
    sumN._20 += (w * pN->_20) >> 12;
    sumN._21 += (w * pN->_21) >> 12;
    sumN._22 += (w * pN->_22) >> 12;

    func_0207D8E0(&sumN);
    REG_MTX_MODE = 1;
    func_0207D8E0(&sumM);

    REG_MTX_MODE = 0;
    REG_MTX_RESTORE = 1;
    REG_MTX_MODE = 2;
    REG_MTX_STORE = rs->c[1];
    rs->c += 3 * (rs->c[2] + 1);
}

/*
 * A script-opcode step: run the 0x34 hook in mode 1, decode the nine-byte
 * instruction word at [s] into a byte offset (p[1..4]) and a payload
 * (p[5..8]), both assembled byte-by-byte because the stream is unaligned,
 * hand them to func_0206DC00 unless flag 0x100 or the hook's own 0x40 bit
 * is set, run the hook again in mode 3, and advance the cursor by 9.
 *
 * PIN ../2.0/sp2: the re-read/forward tell (the func_02070BD8 /
 * func_02068EA0 family of docs/FRONTEND-PINS.md).  The hook dispatch appears
 * twice, at 0x0206D308..0x0206D31C and 0x0206D39C..0x0206D3B0, and both times
 * the image loads the hook pointer AFTER the flag store has retired:
 *   ldr r1, [r5, #8]  / mov r0, r5 / bic r1, r1, #0x40 /
 *   str r1, [r5, #8]  / ldr r1, [r5, #0x34] / blx r1
 * 1.1p1 -O4,p proves the store cannot alias the 0x34 field and hoists that
 * load above the read-modify-write, giving
 *   ldr r0, [r5, #8] / ldr r1, [r5, #0x34] / bic r2, r0, #0x40 /
 *   mov r0, r5 / str r2, [r5, #8]
 * -- the same 220 bytes with those five instructions permuted at both sites,
 * 28 concrete bytes out.  A `volatile` hook field, a `volatile` flags field,
 * the compound `&= ~0x40u` spelling, and binding the flag word and the hook
 * to named locals with the hook read written last all schedule identically
 * under 1.1p1.  Under the pin the same C is 220 bytes, 0 mismatches.
 */
void func_0206D2E8(struct S0206D2E8 *s)
{
    u32 m;
    u32 g;
    u8 *p;
    if (s->cb != 0) m = s->mode; else m = 0;
    if (m == 1) {
        s->flags = s->flags & ~0x40;
        s->cb(s);
        if (s->cb != 0) m = s->mode; else m = 0;
        g = s->flags & 0x40;
    } else {
        g = 0;
    }
    if ((s->flags & 0x100) == 0 && g == 0) {
        p = s->cur;
        func_0206DC00((const u32 *)(p + (p[1] | (p[2] << 8) | (p[3] << 16) | (p[4] << 24))),
                      p[5] | (p[6] << 8) | (p[7] << 16) | (p[8] << 24));
    }
    if (m == 3) {
        s->flags = s->flags & ~0x40;
        s->cb(s);
    }
    s->cur = s->cur + 9;
}

/*
 * Bump a counter, and unless either of two status bits is set, push a
 * three-word packet of one repeated field (0xe0 or 0xe4, chosen by the second
 * argument) through the command queue as command 0x1b.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md).  The image
 * keeps `cmp r1, #0` at 0x0206D3E4 and `bne 0x0206D400` at 0x0206D3E8 over the
 * FOUR-instruction then-arm at 0x0206D3EC..0x0206D3F8 (`ldr r0,[r4,#0xe0]` /
 * three `str r0,[sp,...]`), and closes it with an unconditional `b 0x0206D410`
 * at 0x0206D3FC.  1.1p1 -O4,p predicates both arms instead -- `ldreq/streq x3`
 * then `ldrne/strne x3`, no branch and no join -- giving 104 bytes against the
 * original's 112, 46 concrete bytes out.  Under the pin the same C is 112
 * bytes, 0 mismatches.
 *
 * One lever under the pin: the field must be bound to a local `v` before the
 * three stores.  Written inline as `buf[2] = o->fe0; buf[1] = o->fe0; ...`,
 * 2.0 re-reads the field before EVERY store (six loads, 128 bytes); 1.1p1 CSEs
 * it either way, so the inline spelling looks equivalent under the default
 * compiler and is not.
 */
void func_0206D3C4(struct Obj *o, u32 which)
{
    u32 flags;
    u32 buf[3];

    flags = o->f08;
    if ((flags & 0x100) == 0 && (flags & 0x200) == 0) {
        u32 v;
        if (which == 0) {
            v = o->fe0;
            buf[2] = v;
            buf[1] = v;
            buf[0] = v;
        } else {
            v = o->fe4;
            buf[2] = v;
            buf[1] = v;
            buf[0] = v;
        }
        func_0206DDA4(0x1b, buf, 3);
    }
    o->f00 = o->f00 + 1;
}

static inline void *GetResDataByIdx(const Dict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const DictEntryHeader *hdr = (const DictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)((u32)hdr + sizeof(DictEntryHeader) + hdr->sizeUnit * idx);
    }
    return 0;
}

static inline ResMatData *GetMatDataByIdx(const ResMat *mat, u32 idx)
{
    if (mat) {
        const u32 *data = (const u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data)
            return (ResMatData *)((u8 *)mat + *data);
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

/*
 * NitroSystem G3D NNSi_G3dFuncSbc_ENVMAP (sbc.c): the SBC environment-map
 * opcode (3 bytes), callback slot 12 (cbVecFunc +0x3c, cbVecTiming +0x98).
 * Forces the material's TEXGEN field to NORMAL (0x80000000 in prmTexImage at
 * pMatAnmResult+0x10) and re-sends TEXIMAGE_PARAM through the static command
 * pair at 0x020A82B8 (+8 op, +0xc param); then, in the texture matrix mode:
 * timing A = MTX_SCALE by (w<<15, -h<<15, 16.0) and TEXCOORD (w<<3, h<<3)
 * from origWidth/origHeight (+0x2c/+0x2e); timing B = the material's effect
 * matrix (MATFLAG 0x2000, skipping the optional scale/rot/trans words);
 * timing C = MTX_MULT_3x3 by the camera (and the 3x3 at NNS_G3dGlb+0xbc when
 * flag bit 0) and the current vector matrix from func_0206DE88
 * (NNS_G3dGetCurrentMtx). Ends with MTX_MODE(POSITION_VECTOR).
 *
 * Levers: w/h are `int` (tools/permuter.py --types found it: u16 swaps r4 and
 * r5); the 3x3 matrix and the scale vector are declared at the top of the
 * gated block (stack order n at sp+0x20, scale at sp+0x14).
 * DISCRIMINATING PIN: dsi/1.1p1 is 848 bytes, push {r3-r8,lr}.
 */
void func_0206D434(RS *rs, u32 opt)
{
    if (!(rs->flag & 0x200) && (rs->flag & 1)) {
        MtxFx33 n;
        VecFx32 scale;
        u32 timing;

        if ((rs->pMatAnmResult->prmTexImage & 0xc0000000) != 0x80000000) {
            rs->pMatAnmResult->prmTexImage &= ~0xc0000000;
            rs->pMatAnmResult->prmTexImage |= 0x80000000;
            g_020A82B8.prm = rs->pMatAnmResult->prmTexImage;
            func_0206DDA4(g_020A82B8.op, &g_020A82B8.prm, 1);
        }
        {
            u32 arg = 3;
            func_0206DDA4(0x10, &arg, 1);
        }

        timing = CheckPossibilityOfCallback(rs, 12);
        if (!CallBackCheck_A(rs, 12, &timing)) {
            int w = rs->pMatAnmResult->origWidth;
            int h = rs->pMatAnmResult->origHeight;
            u32 arg;
            scale.x = w << 15;
            scale.y = -h << 15;
            scale.z = 0x10000;
            func_0206DDA4(0x1b, &scale, 3);
            arg = (u32)(u16)(s16)(w << 3) | ((u32)(u16)(s16)(h << 3) << 16);
            func_0206DDA4(0x22, &arg, 1);
        }

        if (!CallBackCheck_B(rs, 12, &timing)) {
            ResMatData *mat = GetMatDataByIdx(rs->pResMat, rs->c[1]);
            if (mat->flag & 0x2000) {
                u8 *p = (u8 *)mat + 0x2c;
                if (!(mat->flag & 2)) p += 8;
                if (!(mat->flag & 4)) p += 4;
                if (!(mat->flag & 8)) p += 8;
                func_0206DDA4(0x18, p, 16);
            }
        }

        if (!CallBackCheck_C(rs, 12, timing)) {
            {
                u32 arg = 2;
                func_0206DDA4(0x10, &arg, 1);
            }
            func_0206DE88(0, &n);
            {
                u32 arg = 3;
                func_0206DDA4(0x10, &arg, 1);
            }
            if (g_renderState.flag & 1) {
                func_0206DDA4(0x1a, &g_renderState.cameraMtx, 9);
                func_0206DDA4(0x1a, &g_renderState.unkBC, 9);
                func_0206DDA4(0x1a, &n, 9);
            } else if (g_renderState.flag & 2) {
                func_0206DDA4(0x1a, &g_renderState.cameraMtx, 9);
                func_0206DDA4(0x1a, &n, 9);
            } else {
                func_0206DDA4(0x1a, &n, 9);
            }
        }
        {
            u32 arg = 2;
            func_0206DDA4(0x10, &arg, 1);
        }
    }
    rs->c += 3;
}

/*
 * NitroSystem G3D NNSi_G3dFuncSbc_PRJMAP (sbc.c): the SBC projection-map
 * opcode (3 bytes), callback slot 13 (cbVecFunc +0x40, cbVecTiming +0x99).
 * Saves the current position matrix to slot 30 (MTX_STORE), forces TEXGEN
 * VERTEX (0xc0000000) through the static TEXIMAGE_PARAM pair at 0x020A82B8
 * (+0 op, +4 param; func_0206D434 uses the +8/+0xc pair), then in texture
 * matrix mode: timing A = MTX_LOAD_4x4 of the static matrix at 0x020A82E8
 * with (w<<15, -h<<15) scale and (w<<15, h<<15) translation; timing B = the
 * material's effect matrix; timing C = camera terms (NNS_G3dGlb +0xe0 trans,
 * +0xbc 3x3), the saved matrix, a clip-matrix read-back into the texture
 * matrix and a TEXCOORD of its translation. Restores slot 30 at the end.
 *
 * Lever: the TEXCOORD pair goes through named fx32 locals s = _30 >> 4,
 * t = _31 >> 4 before the (s16)(v >> 8) narrowing; written as one expression
 * mwcc folds the two shifts into one (8 bytes short).
 * The w/h are int as in func_0206D434.
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to DIFF.
 */
void func_0206D778(RS *rs, u32 opt)
{
    if (!(rs->flag & 0x200) && (rs->flag & 1)) {
        MtxFx43 m;
        MtxFx44 clip;
        u32 timing;

        func_0206DE88(&m, 0);
        {
            u32 arg = 30;
            func_0206DDA4(0x13, &arg, 1);
        }
        if ((rs->pMatAnmResult->prmTexImage & 0xc0000000) != 0xc0000000) {
            rs->pMatAnmResult->prmTexImage &= ~0xc0000000;
            rs->pMatAnmResult->prmTexImage |= 0xc0000000;
            g_020A82B8.w4 = rs->pMatAnmResult->prmTexImage;
            func_0206DDA4(g_020A82B8.w0, &g_020A82B8.w4, 1);
        }

        timing = CheckPossibilityOfCallback(rs, 13);
        if (!CallBackCheck_A(rs, 13, &timing)) {
            int w = rs->pMatAnmResult->origWidth;
            int h = rs->pMatAnmResult->origHeight;
            g_020A82E8._00 = w << 15;
            g_020A82E8._11 = -h << 15;
            g_020A82E8._30 = w << 15;
            g_020A82E8._31 = h << 15;
            func_0206DDA4(0x16, &g_020A82E8, 16);
        }

        if (!CallBackCheck_B(rs, 13, &timing)) {
            ResMatData *mat = GetMatDataByIdx(rs->pResMat, rs->c[1]);
            if (mat->flag & 0x2000) {
                u8 *p = (u8 *)mat + 0x2c;
                if (!(mat->flag & 2)) p += 8;
                if (!(mat->flag & 4)) p += 4;
                if (!(mat->flag & 8)) p += 8;
                func_0206DDA4(0x18, p, 16);
            }
        }

        if (!CallBackCheck_C(rs, 13, timing)) {
            if (g_renderState.flag & 1) {
                func_0206DDA4(0x1c, &g_renderState.unkE0, 3);
                func_0206DDA4(0x1a, &g_renderState.unkBC, 9);
                func_0206DDA4(0x19, &m, 12);
            } else if (g_renderState.flag & 2) {
                func_0206DDA4(0x19, &m, 12);
            } else {
                func_0206DDA4(0x19, func_0206AAD4(), 12);
                func_0206DDA4(0x19, &m, 12);
            }
            func_0206DB80();
            *(volatile u32 *)0x04000440 = 0;
            *(volatile u32 *)0x04000444 = 0;
            *(volatile u32 *)0x04000454 = 0;
            while (func_0207DC98(&clip))
                ;
            *(volatile u32 *)0x04000448 = 1;
            *(volatile u32 *)0x04000440 = 3;
            func_0206DDA4(0x16, &clip, 16);
            {
                fx32 s = clip._30 >> 4;
                fx32 t = clip._31 >> 4;
                u32 arg = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
                func_0206DDA4(0x22, &arg, 1);
            }
        }
        {
            u32 arg = 2;
            func_0206DDA4(0x10, &arg, 1);
        }
        {
            u32 arg = 30;
            func_0206DDA4(0x14, &arg, 1);
        }
    }
    rs->c += 3;
}
