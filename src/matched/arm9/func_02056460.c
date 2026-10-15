/*
 * function: SPL_EMITTER_CalcRotMtx
 * address:  0x02056460
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Row 1 of the two-entry billboard basis table at 0x020A7FE4
 * (func_02054718_Hooks / func_0205429C_Hooks): { 0x02056420, 0x02056460 }.
 * Both rows take (sin, cos, MtxFx43 *) from a sin/cos pair read out of the
 * Verts table at 0x020A1B38 and fill a 4x3 rig matrix.
 *
 * Row 0 (0x02056420, an unlabelled leaf) is the plain rotation about +Y.
 * This row is the rotation about the diagonal axis (1,1,1)/sqrt(3): the two
 * pool constants are 0x555 = 4096/3 (k*k for k = 1/sqrt(3)) and 0x93D = 2365
 * = 4096/sqrt(3) (k itself), so with d = (1-cos)*k*k and e = sin*k the
 * matrix is the standard axis-angle form, diagonal d+cos and the two
 * off-diagonals d-e and d+e, with the translation row left zero.
 *
 * Returns void, NOT u32: the sibling table rows are declared
 * `u32 (*const [])(s32, s32, void *)` in src/matched/SPL_EMITTER_UpdateFrameA68Ex.c, but a
 * `return 0` here costs the extra `mov r0, r4` and makes the function 176
 * bytes against 172.  The table is a mixed-prototype table.
 *
 * TWO SPELLINGS ARE LOAD-BEARING, both found by tools/permuter.py
 * (--mode anneal --budget 2000, EXACT at compile 1499 from an 8-byte residue):
 *   1. `d + cos` is written out at all THREE diagonal sites, never bound to
 *      one local.  A shared `s32 a = d + cs;` puts the value in lr where the
 *      image has it in r1 (the parameter's own register), 8 bytes out.
 *   2. `cs2 = cs;` splits the live range of the cos parameter before the
 *      second group of stores, and `p = d; p = p + e;` gives the first
 *      `d + e` its own definition point.  Without the split the same 8 bytes
 *      stay wrong.  Both are pure allocator levers; the arithmetic is
 *      unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_CalcRotMtx.c \
 *       --func SPL_EMITTER_CalcRotMtx --addr 0x02056460 --arm --cc ../1.2/sp2
 */

typedef signed int       s32;
typedef signed long long s64;

struct MtxFx43 { s32 m[12]; };

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void SPL_EMITTER_CalcRotMtx(s32 sn, s32 cs, struct MtxFx43 *m)
{
    s32 d = FX_Mul(0x1000 - cs, 0x555);
    s32 e = FX_Mul(sn, 0x93D);
    s32 p;
    s32 cs2;

    p = d;
    p = p + e;

    m->m[0] = d + cs;
    m->m[3] = p;
    m->m[6] = d - e;
    m->m[9] = 0;

    cs2 = cs;
    m->m[1] = d - e;
    m->m[4] = d + cs2;
    m->m[7] = d + e;
    m->m[10] = 0;

    m->m[2] = d + e;
    m->m[5] = d - e;
    m->m[8] = d + cs2;
    m->m[11] = 0;
}
