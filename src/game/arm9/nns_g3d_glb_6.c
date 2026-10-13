/*
 * file:     nns_g3d_glb_6.c
 * unit:     yes
 * function: func_0206AAD4, func_0206AB18, func_0206AD20, func_0206AD64, func_0206ADBC, func_0206ADF4, func_0206AE2C, func_0206AE94
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
 *   g_renderState   0x02148B4C  data
 *   g_renderStateDrawParams   0x02148B98  data
 *   g_02148C4C   0x02148C4C  data
 *   func_0207B67C  0x0207B67C  arm
 *   MI_Copy64B        0x02082BA0  arm
 *   MTX_Identity44_   0x0207BDB4  arm
 *   FX_InvFx64c       0x0207C788  arm
 *   SCREENTEX_ProjectionMatrix   0x02148B54  data
 *   g_02148D0C   0x02148D0C  data
 *   g_renderStateIdentityMtx   0x02148C08  data
 *   g_02148C7C   0x02148C7C  data
 *   g_02148CAC   0x02148CAC  data
 *   func_0207B9F0  0x0207B9F0  arm
 *   func_0207B60C  0x0207B60C  arm
 *   g_02148D4C   0x02148D4C  data
 *   func_0207B5C0  0x0207B5C0  arm
 *   func_0207BE14  0x0207BE14  arm
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
extern void func_0207B9F0(void *a, void *b, void *c);
extern void func_0207B60C(void *a, void *b, u32 c, u32 d, u32 e);
extern void  func_0207B5C0(void *a, void *buf);
extern void  func_0207BE14(void *a, void *buf, void *c);
u32 *func_0206AAD4(void);
int func_0206AB18(const MtxFx44 *pSrc, MtxFx44 *pDst);
u32 *func_0206AD20(void);
void func_0206AD64(void);
u32 *func_0206ADBC(void);
u32 *func_0206ADF4(void);
void *func_0206AE2C(void);
void func_0206AE94(u32 *a0, u32 *a1, u32 *a2, u32 *a3);
extern u32 g_renderState[];
extern u32 g_renderStateDrawParams[];
extern u32 g_02148C4C[];
extern u32 SCREENTEX_ProjectionMatrix[];
extern u32 g_02148D0C[];
extern char g_renderStateIdentityMtx[];
extern u32 g_02148C7C[];
extern u32 g_02148CAC[];
extern char g_02148D4C[];




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
    if ((g_renderState[0x3f] & 8) == 0) {
        func_0207B67C(g_renderStateDrawParams, g_02148C4C);
        g_renderState[0x3f] |= 8;
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




/*
 *           +001C inside this function, so `label` has no witness outside the
 *           compared range 0206AD20..0206AD64 and the site stays wildcarded;
 *           own-pool: g_02148D0C (0x02148D0C) occurs exactly once in the whole
 *           arm9 image, in this function's own pool at 0x0206AD60 (+0040).
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: identical
 * shape and identical tell to src/pending/func_0206AAD4.c - the flags object
 * 0x02148B4C is re-materialised from its pool word at +0034 after the call,
 * 68 bytes (56 code + three pool words), `push {r3, lr}`, zero concrete
 * differences under dsi/../2.0/sp2 where dsi/1.1p1 grows the frame to r4 and
 * leaves 21 differing bytes.
 *
 * Rig-slot setup for bit 4: if the flags object's +0xfc word does not already
 * carry 0x10, hand the slot pair (0x02148B54, 0x02148D0C) to the matrix helper
 * and set it, then answer with the slot address either way.  Two of the four
 * sites resolve on `literal` (0x02148B4C x115, 0x02148B54 x22); the call and
 * the returned slot address stay wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AD20.c \
 *       --func func_0206AD20 --addr 0x0206AD20 --cc ../2.0/sp2 --arm
 */
u32 *func_0206AD20(void)
{
    if ((g_renderState[0x3f] & 0x10) == 0) {
        func_0206AB18((const MtxFx44 *)SCREENTEX_ProjectionMatrix, (MtxFx44 *)g_02148D0C);
        g_renderState[0x3f] |= 0x10;
    }
    return g_02148D0C;
}




/*
 * Pin evidence (2.0), measured 2026-09-19:
 *   The image re-materialises the address of the flags object 0x02148B4C from
 *   its pool word at +0014, *before* the three calls, and loads the two other
 *   slot addresses (0x02148C08, 0x02148B98) straight into r0/r1/r2; the frame
 *   is a bare `push {r3, lr}` and the body is 88 bytes.
 *   dsi/1.1p1 keeps those addresses live in callee-saved registers instead
 *   (frame `push {r3, r4, r5, lr}` at 96 bytes, or 100 bytes with the same C
 *   spelled for it), which is the documented "kept constants" tell in
 *   docs/FRONTEND-PINS.md.  dsi/../2.0/sp2 with this C compiles to the
 *   original's 88 bytes with zero concrete mismatches; dsi/1.1p1 gives 78
 *   differing bytes and dsi/../1.2/sp2 gives 76 across 100 bytes.  Same tell
 *   and same family as src/pending/func_0206B6A4.c, already pinned.
 *
 * Rig-slot teardown for the flags object at 0x02148B4C: release the two
 * scratch buffers, hand the three power-of-two state words to the matrix
 * helper, then hand the pair back to the slot fetch.
 *
 * PARKED AT MATCH.  Every concrete byte of the 88-byte body reproduces under
 * the pin; the single open site is func_0207B60C's only branch reference
 * anywhere in the image, the `bl` at 0x0206AD94 inside this function, so the
 * PC24 site is its own witness and no C can resolve it.  It unsticks the day
 * 0x0207B60C is itself an EXACT manifest entry (`matched`) or a second caller
 * turns up in an overlay.  The other two calls resolve on `label` and every
 * ABS32 resolves on `literal`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AD64.c \
 *       --func func_0206AD64 --addr 0x0206AD64 --arm --cc ../2.0/sp2
 */
void func_0206AD64(void)
{
    func_0207B9F0(g_renderStateIdentityMtx, g_renderStateDrawParams, g_02148C7C);
    func_0207B60C(g_02148C7C, g_02148C7C, g_renderState[0x3b], g_renderState[0x3c],
                  g_renderState[0x3d]);
    func_0207B67C(g_02148C7C, g_02148CAC);
}



/*
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3:
 *   The image re-materialises the flags object 0x02148B4C from its pool word
 *   at +002C (a fresh `ldr r0, [pc, #0x10]` after the call at +0018) and keeps
 *   a bare 56-byte body with a `push {r3, lr}` frame.  dsi/1.1p1 keeps the
 *   address live in a callee-saved register across the call and grows the
 *   frame to `push {r4, lr}` with 21 differing bytes; dsi/../2.0/sp2 with this
 *   C compiles to the original's 56 bytes with zero concrete mismatches.  Same
 *   tell ("kept constants", docs/FRONTEND-PINS.md) and same family as
 *   src/pending/func_0206AD64.c and src/pending/func_0206AE2C.c, both already
 *   pinned to ../2.0/sp2 by wave r6.
 *
 * Rig-slot setup for bit 7: if the flags object's +0xfc word does not already
 * carry 0x80, run the slot teardown and set it.  The address of the slot at
 * 0x02148C7C is returned either way, which is why the pool word for it sits
 * last and is loaded once, after the branch target.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206ADBC.c \
 *       --func func_0206ADBC --addr 0x0206ADBC --cc ../2.0/sp2 --arm
 */
u32 *func_0206ADBC(void)
{
    if ((g_renderState[0x3f] & 0x80) == 0) {
        func_0206AD64();
        g_renderState[0x3f] |= 0x80;
    }
    return g_02148C7C;
}



/*
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: identical
 * shape and identical tell to its twin src/matched/func_0206ADBC.c - the flags
 * object 0x02148B4C is re-materialised from its pool word at +002C after the
 * call, 56 bytes, `push {r3, lr}`, zero concrete mismatches under
 * dsi/../2.0/sp2 where dsi/1.1p1 keeps the address live in r4 and grows the
 * frame.  The only difference from the twin is the slot address returned
 * (0x02148CAC instead of 0x02148C7C), which each function carries in its own
 * pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206ADF4.c \
 *       --func func_0206ADF4 --addr 0x0206ADF4 --cc ../2.0/sp2 --arm
 */
u32 *func_0206ADF4(void)
{
    if ((g_renderState[0x3f] & 0x80) == 0) {
        func_0206AD64();
        g_renderState[0x3f] |= 0x80;
    }
    return g_02148CAC;
}



/*
 * Pin evidence (2.0): the image re-materialises the address of the flags
 * object 0x02148B4C from its pool word at +0044, *after* the two calls at
 * +0020 and +0040; 1.1p1 keeps that address live across both calls in a
 * callee-saved register and grows the frame (push {r3,r4,r5,lr}), which is
 * the documented 2.0 tell in docs/FRONTEND-PINS.md ("kept constants": the
 * image rematerialises a constant from the pool where the build keeps it
 * live in a callee-saved register).  Same family as src/pending/
 * func_0206B6A4.c, pinned for the identical tell.
 *
 * PARKED AT MATCH.  Under the pin every concrete byte of the 88-byte body
 * reproduces; the single open site is the call to func_0206AAD4 at +0010,
 * which is the only branch to that address anywhere in the image.  It
 * unsticks when 0x0206AAD4 is itself an EXACT manifest entry (`matched`) or
 * a second caller turns up in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AE2C.c \
 *       --func func_0206AE2C --addr 0x0206AE2C --cc ../2.0/sp2 --arm
 */
void *func_0206AE2C(void)
{
    char buf[0x40];
    void *a;
    void *b;

    if ((g_renderState[0x3f] & 0x40) == 0) {
        a = func_0206AAD4();
        b = func_0206AD20();
        func_0207B5C0(a, buf);
        func_0207BE14(b, buf, g_02148D4C);
        g_renderState[0x3f] |= 0x40;
    }
    return g_02148D4C;
}



/*
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: with
 * dsi/1.1p1 every one of the four guarded arms is if-converted into predicated
 * instructions (`cmp r0, #0` / `ldrne ip, [pc, #0x54]` / `ldrne ip, [ip, #0xa0]`
 * / `andne ip, ip, #0xff` / `strne ip, [r0]`), which shortens the body to 100
 * bytes and leaves 81 differing bytes; dsi/../2.0/sp2 emits the image's
 * branchy form (`cmp` / `beq` over an unconditional body, with only the last
 * arm predicated as `bxeq lr`) at exactly 116 bytes with zero concrete
 * mismatches.  Same front end as the rest of this packet's filed rows
 * (docs/FRONTEND-PINS.md: pkt_0206AA78 keeps constants live / re-materialises
 * them from the pool per front end).  Neither `-proc arm7tdmi` nor volatile
 * destination pointers changed the 1.1p1 if-conversion.
 *
 * Four-byte nibble extractor: the word at g_renderState + 0xa0 is spread over up
 * to four word-sized destinations, one byte per word, low byte first.  Each
 * arm re-spells the global rather than sharing a named local, which is what
 * makes the image re-load the pool word in every arm (and what puts the first
 * arm's value in ip while the rest use r0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AE94.c \
 *       --func func_0206AE94 --addr 0x0206AE94 --cc ../2.0/sp2 --arm
 */
void func_0206AE94(u32 *a0, u32 *a1, u32 *a2, u32 *a3)
{
    if (a0 != 0)
        *a0 = g_renderState[0x28] & 0xff;
    if (a1 != 0)
        *a1 = (g_renderState[0x28] >> 8) & 0xff;
    if (a2 != 0)
        *a2 = (g_renderState[0x28] >> 16) & 0xff;
    if (a3 != 0)
        *a3 = (g_renderState[0x28] >> 24) & 0xff;
}
