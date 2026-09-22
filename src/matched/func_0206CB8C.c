/*
 * function: func_0206CB8C
 * address:  0x0206CB8C
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   g_0214A1B4     0x0214A1B4  data
 *   func_02082AC0  0x02082AC0  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207D918  0x0207D918  arm
 *   func_0207DC98  0x0207DC98  arm
 *   func_0207D934  0x0207D934  arm
 *   func_0207DCC8  0x0207DCC8  arm
 *   func_0207D8E0  0x0207D8E0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int fx32;
typedef long long fx64;

typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22; } MtxFx33;
typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22, _30, _31, _32; } MtxFx43;
typedef struct { fx32 _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33; } MtxFx44;

typedef struct {
    MtxFx43 invM;
    MtxFx33 invN;
} EvpMtx;

typedef struct {
    MtxFx44 M;
    MtxFx33 N;
} EvpCache;
extern EvpCache g_0214A1B4[];

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

typedef struct RS {
    u8 *c;
    RenderObj *pRenderObj;
    u32 flag;
    u8 pad0c[0xcc - 0x0c];
    u32 isEvpCached[2];
} RS;

#define REG_MTX_MODE     (*(volatile u32 *)0x04000440)
#define REG_MTX_STORE    (*(volatile u32 *)0x0400044C)
#define REG_MTX_RESTORE  (*(volatile u32 *)0x04000450)
#define REG_MTX_IDENTITY (*(volatile u32 *)0x04000454)

extern void func_02082AC0(u32 v, void *p, u32 n);
extern void func_0206DB80(void);
extern void func_0207D918(const MtxFx43 *m);
extern int  func_0207DC98(MtxFx44 *m);
extern void func_0207D934(const MtxFx33 *m);
extern int  func_0207DCC8(MtxFx33 *m);
extern void func_0207D8E0(const void *m);

static inline u32 BitVecCheck(const u32 *vec, u32 idx)
{
    return vec[idx >> 5] & (1 << (idx & 31));
}

static inline void BitVecSet(u32 *vec, u32 idx)
{
    vec[idx >> 5] |= 1 << (idx & 31);
}

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
