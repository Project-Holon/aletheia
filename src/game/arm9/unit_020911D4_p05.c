/*
 * file:     unit_020911D4_p05.c
 * unit:     yes
 * function: func_02091D38, func_02091E44, func_02092004, func_02092120, func_02092144, func_020921D8, func_020921F4
 * address:  0x02091D38
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A8730  0x020A8730  data
 *   g_020A877C  0x020A877C  data
 *   g_020A87C8  0x020A87C8  data
 *   g_02153BD4  0x02153BD4  data
 *   g_02150FEC  0x02150FEC  data
 *   arr_02153B8C  0x02153B8C  data
 *   arr_02153BB0  0x02153BB0  data
 *   func_020860D0  0x020860D0  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_02091CBC  0x02091CBC  arm
 *   g_02153FAC  0x02153FAC  data
 *   func_02091650  0x02091650  arm
 */
struct P02091CBC;
struct S02091650;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32_02091D38;

struct H { u32 unk00; u32 *unk04; };

typedef signed int s32_02091E44;

struct F04 { u32 lo : 2; u32 mode : 3; u32 m2 : 2; u32 omode : 3; u32 hi : 22; };

struct F08 { u32 mode : 3; u32 hi : 29; };

struct File {
    u32 f00;
    struct F04 f04;
    struct F08 f08;
    u8  f0c;
    u8  f0d;
    u8  f0e[2];
    u8  pad10[0x08];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 (*f38)(u32 a, u32 *pos, u32 whence, u32 d);
    u32 f3c;
    u32 f40;
    u32 pad44;
    u32 f48;
};

extern s32_02091D38 func_020860D0(void *blk);
extern void func_02086028(void *blk);
extern void func_02086078(void *blk);
extern int func_02091CBC(struct P02091CBC *p);
extern int func_02091650(struct S02091650 *p, u32 *a1);
s32_02091D38 func_02091D38(u32 a0);
extern u8  g_020A8730[];
extern u8  g_020A877C[];
extern u8  g_020A87C8[];
extern u8  g_02153BD4[];
extern struct H g_02150FEC;
extern u32 arr_02153B8C[];
extern u32 arr_02153BB0[];
extern u32 g_02153FAC;

/*
 * The one-argument member of the refcounted-resource wrapper family
 * (src/matched/func_02092004.c is the three-argument one, and
 * src/matched/func_020916D4.c the four-argument one with a two-way dispatch).
 * Three-way id dispatch on a0, block base 0x02153BD4 with a 0x18 stride, the
 * two parallel arrays arr_02153B8C / arr_02153BB0, and the reference token
 * g_02150FEC.unk04[0x1b].
 *
 * docs/notes/pkt_02091D38.c.txt left this at 265 of 268 bytes with a
 * three-instruction residue on the equality compare, and named the fix it had
 * not tried: bind BOTH sides to named locals in a nested if/else inside the
 * outer else, ARRAY ELEMENT FIRST --
 *
 *     u32 cur = arr_02153B8C[idx];
 *     u32 ref = g_02150FEC.unk04[0x1b];
 *     if (cur == ref) ... else ...
 *
 * not an `else if` on the bare expression.  Two live named temporaries on the
 * compare is what lands arr in r1 and the field in r0; the `else if` spelling
 * canonicalises either operand order to the swapped pair.  That spelling
 * closes it, exactly as the note predicted from 0x02092004.
 *
 * g_02150FEC is a two-word object whose SECOND word is the pointer: the pool
 * word is 0x02150FEC itself, so the field must be reached through
 * `g_02150FEC.unk04`, never through a symbol named for 0x02150FF0.  The three
 * id constants are ADDRESSES compared against a0, so they are declared as
 * objects and their address taken; declaring them `u32` makes the compiler
 * dereference them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02091D38.c \
 *       --func func_02091D38 --addr 0x02091D38 --arm --cc 1.1p1
 */
s32_02091D38 func_02091D38(u32 a0)
{
    u32 idx = (a0 == (u32)g_020A8730) ? 2 : (a0 == (u32)g_020A877C) ? 3
            : (a0 == (u32)g_020A87C8) ? 4 : 5;
    u8 *blk = g_02153BD4 + idx * 0x18;
    s32_02091D38 r;

    if (func_020860D0(blk) == 0) {
        arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
        arr_02153BB0[idx] = 1;
    } else {
        u32 cur = arr_02153B8C[idx];
        u32 ref = g_02150FEC.unk04[0x1b];

        if (cur == ref) {
            arr_02153BB0[idx]++;
        } else {
            func_02086028(blk);
            arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
            arr_02153BB0[idx] = 1;
        }
    }
    r = func_02091CBC((struct P02091CBC *)a0);
    arr_02153BB0[idx]--;
    if (arr_02153BB0[idx] == 0) func_02086078(blk);
    return r;
}

/*
 * The seek (fseek shape) of the buffered-stdio object documented in
 * docs/families/cluster_02091588.h and cluster_02091AE8.h.  The real entry is
 * the push {r0-r3} home area at 0x02091E44 (the +0x38 handler takes &pos); the
 * listing's label at 0x02091E48 is the body, hence EXACT* against a 4-byte
 * listing extent until the seed at 0x02091E44 replaces it.
 *
 * Closed wave 12 after four lanes stalled at 448/28.  The two coupled residues
 * were both in the declarations, not the allocator:
 *   - the f08 state is a BITFIELD MEMBER OF THE STRUCT and is ASSIGNED as one
 *     (`p->f08.mode = 2;` / `= 0;`).  That is the `bic ip, #7 / orr #2` read-
 *     modify-write off the word the mode test already loaded, and the plain
 *     re-read after the store; no volatile view is involved.
 *   - the in-window test is `if (pos >= f18 || pos < f34) mode = 0; else
 *     {...}`: the disjunction's THEN arm is the `b` the image keeps between
 *     the two compares.  The positive `&&` form cross-jumps it away.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02091E44.c \
 *       --func func_02091E44 --addr 0x02091E44 --arm --cc 1.1p1
 *   EXACT*, 448 bytes, 3 of 3 relocation sites resolved.
 *   ../2.0/sp2 and ../2.0/sp2p2: 488 bytes, DIFF.
 */
s32_02091E44 func_02091E44(struct File *p, u32 pos, u32 whence)
{
    u8 mode;

    mode = p->f04.omode;
    if (mode != 1 || p->f0d != 0) {
        g_02153FAC = 0x28;
        return -1;
    }
    if (p->f08.mode == 1 && func_02091650((struct S02091650 *)p, 0) != 0) {
        p->f0d = 1;
        p->f28 = 0;
        g_02153FAC = 0x28;
        return -1;
    }
    if (whence == 1) {
        whence = 0;
        pos += func_02091CBC((struct P02091CBC *)p);
    }
    if (whence != 2 && p->f04.mode != 3 && p->f08.mode - 2 <= 1) {
        if (pos >= p->f18 || pos < p->f34) {
            p->f08.mode = 0;
        } else {
            p->f24 = p->f1c + (pos - p->f34);
            p->f28 = p->f18 - pos;
            p->f08.mode = 2;
        }
    } else {
        p->f08.mode = 0;
    }
    if (p->f08.mode == 0) {
        if (p->f38 != 0 && p->f38(p->f00, &pos, whence, p->f48) != 0) {
            p->f0d = 1;
            p->f28 = 0;
            g_02153FAC = 0x28;
            return -1;
        }
        p->f0c = 0;
        p->f18 = pos;
        p->f28 = 0;
    }
    return 0;
}

#include "../../matched/include/Obj11692.h"

typedef int            s32;

extern s32 func_020860D0(void *blk);
s32 func_02092004(u32 a0, u32 a1, u32 a2);
int func_02092120(void *a0);

/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocking: label, no outside witness -- the one wildcard site is +0x00D4
 *           PC24 func_02091E44, whose only branch in the image is this call
 *           (match.py: "has no witness outside 02092004..02092120").  Cut
 *           does not help: the site is inside the single function, so
 *           --suggest-split has nothing to offer.  Byte-correct as it
 *           stands: converts with no edit the moment 0x02091E44 has a
 *           manifest entry of its own.
 */
s32 func_02092004(u32 a0, u32 a1, u32 a2)
{
    u32 idx = (a0 == (u32)g_020A8730) ? 2 : (a0 == (u32)g_020A877C) ? 3
            : (a0 == (u32)g_020A87C8) ? 4 : 5;
    u8 *blk = g_02153BD4 + idx * 0x18;
    s32 r;

    if (func_020860D0(blk) == 0) {
        arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
        arr_02153BB0[idx] = 1;
    } else {
        u32 cur = arr_02153B8C[idx];
        u32 ref = g_02150FEC.unk04[0x1b];

        if (cur == ref) {
            arr_02153BB0[idx]++;
        } else {
            func_02086028(blk);
            arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
            arr_02153BB0[idx] = 1;
        }
    }
    r = func_02091E44((struct File *)a0, a1, a2);
    arr_02153BB0[idx]--;
    if (arr_02153BB0[idx] == 0) func_02086078(blk);
    return r;
}

int func_02092120(void *a0){ int t0; ((struct Obj11692 *)((char *)(a0)))->fD = (unsigned char)0; t0 = func_02092004((int)a0, (int)0, (int)0); ((struct Obj11692 *)((char *)(a0)))->fD = (unsigned char)0; return t0; }

typedef unsigned long long u64;

u32 func_02092144(u64 x);
int func_020921D8(double v);

/*
 * 64-bit population count: the four SWAR stages of the standard bit-count
 * idiom over an unsigned long long, then the horizontal fold.  The last three
 * folds are unmasked (`x += x >> 8`, `>> 16`, `>> 32`) because the count of
 * 64 bits can never carry out of a byte, so no 0x00FF00FF mask is needed.
 *
 * The 32-bit halves of the 64-bit shifts are what pin the type: `orr r3, r3,
 * r1, lsl #31` after `lsr r3, r0, #1` is a 64-bit `>> 1`, and `and r2, r2,
 * r1, lsr #1` masks the high word separately.  The three masks are 64-bit
 * constants whose two halves happen to be equal, which is why one pool word
 * each (0x55555555, 0x33333333, 0x0F0F0F0F) serves both words.
 *
 * `x + (x >> 32)` is not emitted as a shift at all: at that point the value
 * is under 0x100, so only the low half matters and mwcc folds the 64-bit add
 * to `adds r0, r1, r0` (low word plus high word) with the carry dropped.
 *
 * The listing extent (148 bytes) includes this function's three-word pool at
 * 0x020921CC..0x020921D4; nothing here is a relocation, so the whole range is
 * compared byte for byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02092144.c \
 *       --func func_02092144 --addr 0x02092144 --cc 1.1p1 --arm
 *   EXACT, 148 bytes, no relocation sites.
 */
u32 func_02092144(u64 x)
{
    x = x - ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32);
    return (u32)x & 0xFF;
}

int func_020921D8(double v)
{
    u32 *w = (u32 *)&v;

    return (w[1] & 0x80000000u) ? 1 : 0;
}

/*
 * note:     the trailing star is the unlabelled leaf at 0x02092264 (and the
 *           word-run of unlabelled leaves after it), not a byte difference:
 *           the listing extent runs to the next func_ label at 0x020922B0.
 *           Wants a seed at 0x02092264 in layout/function_starts.txt.
 */
int func_020921F4(double v)
{
    if ((*(u32 *)((char *)&v + 4) & 0x7FF00000u) != 0) {
        if ((*(u32 *)((char *)&v + 4) & 0x7FF00000u) == 0x7FF00000u)
            return ((*(u32 *)((char *)&v + 4) & 0xFFFFFu) != 0 ||
                    *(u32 *)&v != 0) ? 1 : 2;
    } else {
        return ((*(u32 *)((char *)&v + 4) & 0xFFFFFu) != 0 ||
                *(u32 *)&v != 0) ? 5 : 3;
    }
    return 4;
}
