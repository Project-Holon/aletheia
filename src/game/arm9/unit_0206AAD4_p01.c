/*
 * file:     unit_0206AAD4_p01.c
 * unit:     yes
 * function: func_0206AAD4, func_0206AB18
 * address:  0x0206AAD4
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
 *   g_02148B4C   0x02148B4C  data
 *   g_02148B98   0x02148B98  data
 *   g_02148C4C   0x02148C4C  data
 *   func_0207B67C  0x0207B67C  arm
 *   MI_Copy64B        0x02082BA0  arm
 *   MTX_Identity44_   0x0207BDB4  arm
 *   FX_InvFx64c       0x0207C788  arm
 */
typedef unsigned int u32;

typedef int s32;

typedef s32 fx32;

typedef long long fx64;

typedef long long fx64c;

typedef struct { fx32 m[4][4]; } MtxFx44;

extern void func_0207B67C(u32 *a, u32 *b);
extern void MI_Copy64B(const void *src, void *dst);
extern void MTX_Identity44_(MtxFx44 *pDst);
extern fx64c FX_InvFx64c(fx32 v);
u32 *func_0206AAD4(void);
int func_0206AB18(const MtxFx44 *pSrc, MtxFx44 *pDst);
extern u32 g_02148B4C[];
extern u32 g_02148B98[];
extern u32 g_02148C4C[];


/*
 *           arm9 image, in this function's own literal pool at 0x0206AB14
 *           (+0040), so `literal` has no witness outside the compared range
 *           0206AAD4..0206AB18 and no cut can free it.
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: the image
 * re-materialises the flags object 0x02148B4C from its pool word at +0034
 * after the call at +001C, keeps the frame at `push {r3, lr}` and the body at
 * 68 bytes (56 code + three pool words).  dsi/1.1p1 keeps 0x02148B4C live in
 * r4 across the call, grows the frame to `push {r4, lr}` and leaves 24
 * differing bytes; dsi/../2.0/sp2 with this C reproduces all 68 bytes with
 * zero concrete differences.  Same family tell as src/matched/func_0206ADBC.c,
 * src/matched/func_0206ADF4.c and src/pending/func_0206AD64.c.
 *
 * Rig-slot setup for bit 3: if the flags object's +0xfc word does not already
 * carry the bit, hand the slot pair (0x02148B98, 0x02148C4C) to the matrix
 * helper and set it, then answer with the slot address either way.  Three of
 * the four sites resolve (the call on `label`, the two other pool words on
 * `literal`); only the returned slot address stays wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AAD4.c \
 *       --func func_0206AAD4 --addr 0x0206AAD4 --cc ../2.0/sp2 --arm
 */
u32 *func_0206AAD4(void)
{
    if ((g_02148B4C[0x3f] & 8) == 0) {
        func_0207B67C(g_02148B98, g_02148C4C);
        g_02148B4C[0x3f] |= 8;
    }
    return g_02148C4C;
}


static inline fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
    fx64 tmp = v64c * v32 + 0x80000000LL;
    return (fx32)(tmp >> 32);
}


/*
 * 4x4 fx32 matrix inverse, Gauss-Jordan with partial pivoting (a game-side
 * MTX_Inverse44: the SDK in this image carries only MTX_Inverse33/43).
 * Copies pSrc into a stack MtxFx44 (MI_Copy64B), sets pDst to identity,
 * returns -1 on a zero pivot column, else 0.  Row normalisation is
 * FX_Mul32x64c(v, FX_InvFx64c(pivot)) (rounded, >> 32); elimination is an
 * UNROUNDED (fx64)a * b >> 12.  (The sdk name FX_InvFx64c for 0x0207C788 is
 * libmatch's; it takes one argument.)
 *
 * WHAT CLOSED IT: VARIABLE IDENTITY, not spelling.  With a dedicated loop
 * variable for the elimination row the compile is 520/520 with a 17-byte
 * three-register rotation (j/a/a>>31 in r2/ip/r3 against ip/r3/r2) that
 * hill (252 singles) and anneal (700) could not move.  The image's allocation
 * appears when the elimination row variable is the SAME variable that
 * recorded the pivot row (here j), so its live ranges merge.  A sweep of 90
 * role assignments found ten EXACT, all sharing the elimination row
 * variable with an earlier role.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206AB18.c
 *       --func func_0206AB18 --addr 0x0206AB18 --arm --cc ../2.0/sp2
 */
int func_0206AB18(const MtxFx44 *pSrc, MtxFx44 *pDst)
{
    MtxFx44 tmp;
    int i, j, k, r;
    fx32 max;

    MI_Copy64B(pSrc, &tmp);
    MTX_Identity44_(pDst);

    for (i = 0; i < 4; ++i) {
        j = i;
        max = 0;
        for (r = i; r < 4; ++r) {
            fx32 ftmp = tmp.m[r][i];
            if (ftmp < 0)
                ftmp = -ftmp;
            if (ftmp > max) {
                max = ftmp;
                j = r;
            }
        }
        if (max == 0)
            return -1;
        if (j != i) {
            for (k = 0; k < 4; ++k) {
                fx32 x;
                x = tmp.m[i][k];
                tmp.m[i][k] = tmp.m[j][k];
                tmp.m[j][k] = x;
                x = pDst->m[i][k];
                pDst->m[i][k] = pDst->m[j][k];
                pDst->m[j][k] = x;
            }
        }
        {
            fx64c recip = FX_InvFx64c(tmp.m[i][i]);
            for (k = 0; k < 4; ++k) {
                tmp.m[i][k] = FX_Mul32x64c(tmp.m[i][k], recip);
                pDst->m[i][k] = FX_Mul32x64c(pDst->m[i][k], recip);
            }
        }
        for (j = 0; j < 4; ++j) {
            if (j != i) {
                fx32 a = tmp.m[j][i];
                for (k = 0; k < 4; ++k) {
                    tmp.m[j][k] -= (fx32)(((fx64)a * tmp.m[i][k]) >> 12);
                    pDst->m[j][k] -= (fx32)(((fx64)a * pDst->m[i][k]) >> 12);
                }
            }
        }
    }
    return 0;
}
