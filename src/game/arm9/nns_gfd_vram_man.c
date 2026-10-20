/*
 * file:     nns_gfd_vram_man.c
 * unit:     yes
 * function: NNS_GfdAllocVram, NNSi_GfdGetVramManagerWork, NNSi_GfdSetVramManagerWork, NNSi_GfdRingNextIndex, NNSi_GfdRingIsFull, NNSi_GfdRingIsEmpty, NNS_GfdFuncLoadTex, NNS_GfdFuncLoadTexPltt, NNS_GfdFuncLoadClearImageColor, NNS_GfdFuncLoadClearImageDepth, NNS_GfdFuncLoadBG0Char, NNS_GfdFuncLoadBG1Char, NNS_GfdFuncLoadBG2Char, NNS_GfdFuncLoadBG3Char, NNS_GfdFuncLoadBG0Scr, NNS_GfdFuncLoadBG1Scr, NNS_GfdFuncLoadBG2Scr, NNS_GfdFuncLoadBG3Scr, NNS_GfdFuncLoadBG2ScrDup, NNS_GfdFuncLoadBG3ScrDup, NNS_GfdFuncLoadOBJPltt, NNS_GfdFuncLoadBGPltt
 * address:  0x020616CC
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
 *   g_02146B74     0x02146B74  data
 *   _u32_div_f   0x0209C2B0  arm
 *   GX_LoadBGPltt  0x0207E3D0  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   GX_LoadBG0Char  0x0207EE68  arm
 *   GX_LoadBG2Char  0x0207F0B8  arm
 *   GX_EndLoadTexPltt  0x0207FADC  arm
 *   GX_LoadBG0Scr  0x0207E888  arm
 *   GX_LoadBG1Scr  0x0207EA00  arm
 *   GX_LoadBG3Scr  0x0207ECF0  arm
 *   GX_LoadBG1Char  0x0207EF90  arm
 *   GX_LoadBG3Char  0x0207F1E0  arm
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   GX_LoadTex  0x0207F7FC  arm
 *   GX_EndLoadTex  0x0207F9B4  arm
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt  0x0207FA40  arm
 *   GX_BeginLoadClearImage  0x0207FB2C  arm
 *   GX_LoadClearImageColor  0x0207FBBC  arm
 *   GX_LoadClearImageDepth  0x0207FC48  arm
 *   GX_EndLoadClearImage  0x0207FCE4  arm
 */

#include "../types.h"

struct Arena02146B74 {
    u32 cur;    /* 0x00  low  cursor, grows upward   */
    u32 end;    /* 0x04  high cursor, grows downward */
};

/* NNS GFD VRAM transfer ring header. */
struct NNSGfdVramRing {
    u8  pad_00[4];
    u32 numEntries;   /* 0x04 */
    u8  pad_08[4];
    u16 count;        /* 0x0c */
};

#include "gx_load3d.h"
u32 NNS_GfdAllocVram(u32 size, u32 flag, u32 dir);
void NNSi_GfdGetVramManagerWork(struct Arena02146B74 *dst);
void NNSi_GfdSetVramManagerWork(void *pWork);
u32 NNSi_GfdRingNextIndex(u8 *p, u32 v);
int NNSi_GfdRingIsFull(u8 *p);
int NNSi_GfdRingIsEmpty(void *p);
void NNS_GfdFuncLoadTex(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadTexPltt(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadClearImageColor(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadClearImageDepth(u32 a, u32 b, u32 c);
extern struct Arena02146B74 g_02146B74;
#include "gx_load2d.h"
void NNS_GfdFuncLoadBG0Char(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG1Char(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG2Char(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG3Char(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG0Scr(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG1Scr(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG2Scr(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG3Scr(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG2ScrDup(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBG3ScrDup(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadOBJPltt(u32 a, u32 b, u32 c);
void NNS_GfdFuncLoadBGPltt(u32 a, u32 b, u32 c);

/*
 * VRAM (or comparable fixed-arena) BUMP ALLOCATOR STEP, against the {cur, end}
 * pair at 0x02146B74 that src/matched/NNSi_GfdGetVramManagerWork.c also exposes.  `size` is
 * rounded up to eight bytes (zero meaning eight) and refused above 0x7FFF8;
 * `dir == 1` allocates off the low cursor, anything else off the high one;
 * `flag` picks whether the alignment pad is derived from 8 or from 16, and in
 * the 8-byte case additionally caps the arena at 0x10000.  The packed result
 * is the allocated offset over eight in the low halfword and the rounded size
 * over eight in the high halfword, zero when the request cannot be satisfied.
 *
 * THE COMPILER PIN.  This function is `../2.0/sp2`, not the project default.
 * It is the *only* pinned file in this cluster; every other matched source in
 * 0x020611D4..0x02061824 is 1.1p1.  The evidence is recorded in
 * docs/FRONTEND-PINS.md and is the "kept constants" tell: 1.1p1 CSEs the pool
 * load of &g_02146B74 to function entry and keeps it live across the whole
 * body, which costs `push {r3, r4, r5, lr}` where the image has
 * `push {r4, lr}` and spends r5 on a value the image never names.  The image
 * re-materialises the address from the pool six times, at 0x020616FC,
 * 0x02061724, 0x02061754, 0x02061778, 0x02061798 and 0x020617C4, against the
 * single ABS32 at 0x02061804.  2.0/sp2 reproduces that rematerialisation
 * exactly, and with it the narrower push, with no change to the C at all.
 *
 * docs/notes/pkt_020613D8.c.txt records two "walls" measured for this function
 * under 1.1p1 across some thirty spellings.  BOTH ARE COMPILER ARTEFACTS AND
 * BOTH VANISH UNDER THE PIN:
 *   WALL 2 (the pool-address hoist, ~200 differing bytes, which the note
 *     correctly localised to "only when BOTH halves are present") is exactly
 *     the tell above.
 *   WALL 1 (the pad if/else in the `dir == 1` arm: 1.1p1 predicates both arms
 *     and emits no `beq`, where the image predicates the first and branches
 *     over the second) also disappears -- 2.0/sp2 emits the `beq` from a plain
 *     if/else, provided the `flag != 0` arm is written FIRST.  The note's
 *     nineteen pad spellings were all correct C fighting the wrong front end.
 *
 * Three source facts the byte comparison pins, all measured under the pin:
 *
 * 1. THE FAILURE PATHS ARE TWO DIFFERENT SHAPES, and writing them uniformly
 *    costs bytes either way.  The two "arena too small" refusals (`goto fail1`
 *    / `goto fail2`) reach a shared `mov lr, #0` block that each half owns, so
 *    they are gotos; the two `>= 0x10000` refusals are predicated in place
 *    (`movhi lr, #0` / `bhi`), so they are ordinary `ok = 0;` assignments
 *    followed by a jump to the tail.  Writing all four as `ok = 0` gives
 *    `movlo lr, #0` before every `blo` (two extra instructions); writing all
 *    four as gotos loses the predication on the 0x10000 pair.
 * 2. THE 0x10000 TEST IS `>`, NOT `>=`.  The image's `cmp rN, #0x10000` with
 *    `movhi`/`bhi` is the strictly-greater form; `>= 0x10000u` gives
 *    `movhs`/`bhs`, four conditions wrong.  Spelling the same boundary as
 *    `> 0xffffu` instead costs a pool word, because 0xFFFF is not an ARM
 *    rotated immediate while 0x10000 is.
 * 3. THE TWO HALVES NAME THEIR LENGTH SEPARATELY.  `len` in the `dir == 1`
 *    half and `ln` in the other are the same quantity `n + off`, but sharing
 *    one local across both halves puts the else half's `end` in ip and its
 *    length in r4, where the image has `end` in lr and the length in ip: eight
 *    concrete bytes, and the last residue tools/permuter.py could not move
 *    (2200 anneal candidates and 310 exhausted single mutations, both flat at
 *    eight).  Two locals is what separates the live ranges.
 *
 * The permuter did find the rest of the way in from the 73-byte hand-written
 * start: expand(addr), expand(len), commute(|), then temp(tmp = cur),
 * temp(tmp1 = cur + len) -- which is why `tmp1` names `cur + len` and the
 * return is written high-half-first.
 *
 * Filing this entry also unblocks src/pending/BUTTON_MAN_Func1AA0.c in pkt_02051A54,
 * whose `bl` at +0x08 was capped at MATCH for want of a manifest entry here.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_GfdAllocVram.c \
 *       --func NNS_GfdAllocVram --addr 0x020616CC --arm --cc ../2.0/sp2
 *   EXACT, 316 bytes, 1 relocation site, resolved.
 */
u32 NNS_GfdAllocVram(u32 size, u32 flag, u32 dir)
{
    u32 n;
    u32 off;
    u32 len;
    u32 addr = 0;
    u32 ok;
    int cur2;
    u32 top;
    u32 ln;

    if (size == 0) {
        n = 8;
    } else {
        n = (size + 7) & ~7u;
    }
    if (n >= 0x7fff8u) {
        return 0;
    }

    if (dir == 1) {
        u32 cur = g_02146B74.cur;

        if (flag != 0) {
            off = (8 - (cur & 7)) & 7;
        } else {
            off = (16 - (cur & 0xf)) & 0xf;
        }
        len = n + off;
        if (g_02146B74.end - cur < len) {
            goto fail1;
        }
        top = cur + len;
        if (flag != 0 && top > 0x10000u) {
            ok = 0;
            goto done;
        }
        addr = cur + off;
        g_02146B74.cur = g_02146B74.cur + len;
        ok = 1;
        goto done;
fail1:
        ok = 0;
        goto done;
    } else {
        u32 end = g_02146B74.end;

        if (end < n) {
            goto fail2;
        }
        if (flag != 0) {
            off = (end - n) & 7;
        } else {
            off = (end - n) & 0xf;
        }
        ln = n + off;
        cur2 = g_02146B74.cur;
        if (end - cur2 < ln) {
            goto fail2;
        }
        if (flag != 0 && end > 0x10000u) {
            ok = 0;
            goto done;
        }
        ok = 1;
        g_02146B74.end = g_02146B74.end - ln;
        addr = g_02146B74.end;
        goto done;
fail2:
        ok = 0;
        goto done;
    }

done:
    if (ok == 0) {
        return 0;
    }
    return ((n >> 3) << 16) | ((addr << 13) >> 16);
}

void NNSi_GfdGetVramManagerWork(struct Arena02146B74 *dst)
{
    dst->cur = g_02146B74.cur;
    dst->end = g_02146B74.end;
}

void NNSi_GfdSetVramManagerWork(void *pWork)
{
    g_02146B74.cur = ((struct Arena02146B74 *)pWork)->cur;
    g_02146B74.end = ((struct Arena02146B74 *)pWork)->end;
}

/*
 * Returns (value + 1) modulo the +4 word, truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdRingNextIndex.c \
 *       --func NNSi_GfdRingNextIndex --addr 0x02061840 --arm --cc 1.1p1
 */
u32 NNSi_GfdRingNextIndex(u8 *p, u32 v)
{
    return (u16)((v + 1) % ((struct NNSGfdVramRing *)p)->numEntries);
}

/*
 * Returns whether the +0xc halfword equals the +4 word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdRingIsFull.c \
 *       --func NNSi_GfdRingIsFull --addr 0x02061860 --arm --cc 1.1p1
 */
int NNSi_GfdRingIsFull(u8 *p)
{
    u16 a = ((struct NNSGfdVramRing *)p)->count;
    u32 b = ((struct NNSGfdVramRing *)p)->numEntries;

    return a == b ? 1 : 0;
}

/*
 * Returns whether the +0xc halfword is zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdRingIsEmpty.c \
 *       --func NNSi_GfdRingIsEmpty --addr 0x02061878 --arm --cc 1.1p1
 */
int NNSi_GfdRingIsEmpty(void *p)
{
    return ((struct NNSGfdVramRing *)p)->count == 0 ? 1 : 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_GfdFuncLoadTex.c \
 *       --func NNS_GfdFuncLoadTex --addr 0x0206188C --arm --cc 1.1p1
 */
void NNS_GfdFuncLoadTex(u32 a, u32 b, u32 c)
{
    GX_BeginLoadTex();
    GX_LoadTex((void *)a, b, c);
    GX_EndLoadTex();
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_GfdFuncLoadTexPltt.c \
 *       --func NNS_GfdFuncLoadTexPltt --addr 0x020618B8 --arm --cc 1.1p1
 */
void NNS_GfdFuncLoadTexPltt(u32 a, u32 b, u32 c)
{
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt((void *)a, b, c);
    GX_EndLoadTexPltt();
}

/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * PARKED AT MATCH: every concrete byte is right; the PC24 at +0x0018 is
 * wildcarded because 0x0207FBBC (GX_LoadClearImageColor) has exactly one
 * branch reference image wide and it is that call, so no cut of a
 * one-function range frees it.  Blocking evidence class: label/matched, no
 * outside witness -- the SDK table names the address but attest() has no
 * class that trusts a table alone.  It unsticks when the callee has its own
 * EXACT entry or a second caller.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNS_GfdFuncLoadClearImageColor.c \
 *       --func NNS_GfdFuncLoadClearImageColor --addr 0x020618E4 --arm --cc 1.1p1
 */
void NNS_GfdFuncLoadClearImageColor(u32 a, u32 b, u32 c)
{
    GX_BeginLoadClearImage();
    GX_LoadClearImageColor((void *)a, c);
    GX_EndLoadClearImage();
}

/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * PARKED AT MATCH: every concrete byte is right; the PC24 at +0x0018 is
 * wildcarded because 0x0207FC48 (GX_LoadClearImageDepth) has exactly one
 * branch reference image wide and it is that call.  Same class and same
 * unblock as src/pending/NNS_GfdFuncLoadClearImageColor.c: label/matched, no outside witness.
 * The `*` is disasm.py's extent for the original running past the leaf.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNS_GfdFuncLoadClearImageDepth.c \
 *       --func NNS_GfdFuncLoadClearImageDepth --addr 0x02061908 --arm --cc 1.1p1
 */
void NNS_GfdFuncLoadClearImageDepth(u32 a, u32 b, u32 c)
{
    GX_BeginLoadClearImage();
    GX_LoadClearImageDepth((void *)a, c);
    GX_EndLoadClearImage();
}

void NNS_GfdFuncLoadBG0Char(u32 a, u32 b, u32 c)
{
    GX_LoadBG0Char((void *)a, b, c);
}

void NNS_GfdFuncLoadBG1Char(u32 a, u32 b, u32 c)
{
    GX_LoadBG1Char((void *)a, b, c);
}

void NNS_GfdFuncLoadBG2Char(u32 a, u32 b, u32 c)
{
    GX_LoadBG2Char((void *)a, b, c);
}

void NNS_GfdFuncLoadBG3Char(u32 a, u32 b, u32 c)
{
    GX_LoadBG3Char((void *)a, b, c);
}

void NNS_GfdFuncLoadBG0Scr(u32 a, u32 b, u32 c)
{
    GX_LoadBG0Scr((void *)a, b, c);
}

void NNS_GfdFuncLoadBG1Scr(u32 a, u32 b, u32 c)
{
    GX_LoadBG1Scr((void *)a, b, c);
}

void NNS_GfdFuncLoadBG2Scr(u32 a, u32 b, u32 c)
{
    GX_LoadBG2Scr((void *)a, b, c);
}

void NNS_GfdFuncLoadBG3Scr(u32 a, u32 b, u32 c)
{
    GX_LoadBG3Scr((void *)a, b, c);
}

void NNS_GfdFuncLoadBG2ScrDup(u32 a, u32 b, u32 c)
{
    GX_LoadBG2Scr((void *)a, b, c);
}

void NNS_GfdFuncLoadBG3ScrDup(u32 a, u32 b, u32 c)
{
    GX_LoadBG3Scr((void *)a, b, c);
}

void NNS_GfdFuncLoadOBJPltt(u32 a, u32 b, u32 c)
{
    GX_LoadOBJPltt((void *)a, b, c);
}

void NNS_GfdFuncLoadBGPltt(u32 a, u32 b, u32 c)
{
    GX_LoadBGPltt((void *)a, b, c);
}
