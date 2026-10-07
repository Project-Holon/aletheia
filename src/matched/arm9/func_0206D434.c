/*
 * function: func_0206D434
 * address:  0x0206D434
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   g_02148B4C     0x02148B4C  data
 *   g_020A82B8     0x020A82B8  data
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0206DE88  0x0206DE88  arm
 */

#include "../include/G_TexImageCmd.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22; } MtxFx33;
typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22, _30, _31, _32; } MtxFx43;
typedef struct { fx32 m[16]; } MtxFx44;

typedef struct {
    u32 cmd0;
    u32 mtxmode;
    MtxFx44 prjMtx;
    u32 cmd1;
    MtxFx43 cameraMtx;
    u8 pad7c[0xbc - 0x7c];
    MtxFx33 unkBC;
    u8 pade0[0xfc - 0xe0];
    u32 flag;
} Glb;
extern Glb g_02148B4C;

typedef struct {
    u32 w0;
    u32 w4;
    u32 op;
    u32 prm;
} TexImageCmd;
extern struct TexImageCmd g_020A82B8;

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

typedef struct RS RS;
typedef void (*CbFunc)(RS *);
struct RS {
    u8 *c;
    void *pRenderObj;
    u32 flag;
    CbFunc cbVecFunc[32];
    u8 cbVecTiming[32];
    u8 currentNode;
    u8 currentMat;
    u8 currentNodeDesc;
    u8 dummy_;
    MatAnmResult *pMatAnmResult;
    u8 padb4[0xd8 - 0xb4];
    ResMat *pResMat;
};

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0206DE88(void *a, void *b);

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
            if (g_02148B4C.flag & 1) {
                func_0206DDA4(0x1a, &g_02148B4C.cameraMtx, 9);
                func_0206DDA4(0x1a, &g_02148B4C.unkBC, 9);
                func_0206DDA4(0x1a, &n, 9);
            } else if (g_02148B4C.flag & 2) {
                func_0206DDA4(0x1a, &g_02148B4C.cameraMtx, 9);
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
