/*
 * file:     unit_02070524.c
 * unit:     yes
 * function: func_02070524, func_02070624, func_02070730, func_02070830, func_02070904
 * address:  0x02070524
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
 *   MIi_CpuClear16   0x02082A48  arm
 *   func_0206E7EC    0x0206E7EC  arm
 *   data_020A8228    0x020A8228  data
 */
#include "../../matched/include/Obj16643.h"
#include "../../matched/include/Obj02329.h"
#include "../../matched/include/Obj16645.h"
#include "../../matched/include/Obj16646.h"

struct Node70730;
struct Out70730;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef unsigned char  u8;

struct Rec70730 {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
};

struct Out70730 {
    u32 f00;
    u32 pad04[5];
    u32 f18, f1c, f20, f24, f28;
};

struct Node70730 {
    u8  pad00[9];
    u8  b09;
    u8  pad0a[4];
    u16 h0e;
};

struct Src70830 {
    u8  pad00[8];
    u8  b08;
    volatile u8 b09;
    u8  pad0a[4];
    u16 h0e;
};

struct Ctx70830 {
    u8  pad00[8];
    u32 f08;
    u32 f0c;
    u8  pad10[9];
    u8  b19;
    u16 h1a[1];
};

struct Arg70830 {
    u8  pad00[8];
    u32 f08;
    u8  pad0c[12];
    u8  b18;
};

struct Anim70904 { u32 f0; u32 f4; void *p8; };

struct Dst70904  { volatile u32 f0; u32 pad04[3]; volatile u32 f10; };

void MIi_CpuClear16(u16 value, void *dest, u32 size);
s32 func_0206E7EC(void *name, void *ent);
s32 func_02070524(u32 *base, u32 flags, u32 off, u32 idx);
int func_02070624(u32 *base, u32 flags, u32 off, u32 idx);
void func_02070730(struct Node70730 *node, u32 idx, u32 t, struct Out70730 *out);
void func_02070830(struct Ctx70830 *ctx, struct Src70830 *src, struct Arg70830 *arg);
void func_02070904(struct Dst70904 *dst, struct Anim70904 *a, u32 idx);
extern u32 data_020A8228;





/*
 * Scalar keyframe sampler for the animation track engine (the callee
 * func_02070730 uses for the two scale tracks and the two translation
 * tracks).  `flags` is the track descriptor word: bit 29 means the value is
 * inline (return `off` unchanged), bits 31:30 select the key stride
 * (full / half / quarter), bit 28 selects s16 keys over u32 keys, and bits
 * 15:0 are the key count.  A half-stride odd index averages the two
 * neighbouring keys; a quarter-stride index is either that average or the
 * 3:1 weighted average, depending on the low two bits.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): under
 * the project default dsi/1.1p1 -O4,p this body is 4 bytes LONG, because
 * 1.1p1 keeps the `two:` block's u32 arm as a branch where the image
 * predicates it.  Under ../2.0/sp2 the same C is byte-exact.
 *
 * Three source levers, all measured, all needed (see
 * docs/notes/func_02070524.c.txt for the full history):
 *   1. the quad tail spelled as three statements (`v0 *= 3; v0 += v1;
 *      return v0 >> 2;`), not as the single expression `(v0*3 + v1) >> 2`,
 *      which normalises the accumulate into `add r0, r1, r0`;
 *   2. in the `two:` block the s16 (bit-28 set) arm is written FIRST and the
 *      u32 arm as the `else`.  Writing the u32 arm first emits the two
 *      trailing s16 address computations in the other order
 *      (`lsl` before `add`), which no respelling of that arm reaches;
 *   3. the u32 arm's pointer `w` is computed INSIDE that arm.  Hoisting it
 *      above the `if` (the shape the note had reached) emits the `add`
 *      unpredicated where the image has `addeq`.
 *
 * No relocation sites: the function is self-contained.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070524.c \
 *       --func func_02070524 --addr 0x02070524 --cc ../2.0/sp2 --arm
 */
s32 func_02070524(u32 *base, u32 flags, u32 off, u32 idx)
{
    u32 n;
    u32 i0;
    s32 v0, v1;
    s16 *h;
    u32 *w;

    if (flags & 0x20000000)
        return off;

    base = (u32 *)((int)base + off);

    if (flags & 0xc0000000) {
        n = flags & 0xffff;
        if (flags & 0x40000000) {
            if (idx & 1) {
                if (idx > n) {
                    idx = (n >> 1) + 1;
                    goto plain;
                }
                idx = idx >> 1;
                goto two;
            }
            idx = idx >> 1;
            goto plain;
        } else {
            u32 r = idx & 3;
            if (r != 0) {
                if (idx > n) { idx = r + (n >> 2); goto plain; }
                if (idx & 1) {
                    if (idx & 2) { idx = idx >> 2; i0 = idx + 1; }
                    else { i0 = idx >> 2; idx = i0 + 1; }
                    if (!(flags & 0x10000000)) {
                        v0 = base[i0];
                        v1 = base[idx];
                        goto quad;
                    }
                    h = (s16 *)base;
                    v0 = h[i0];
                    v1 = h[idx];
                quad:
                    v0 *= 3;
                    v0 += v1;
                    return v0 >> 2;
                }
                idx = idx >> 2;
                goto two;
            }
            idx = idx >> 2;
        }
    }

plain:
    if (!(flags & 0x10000000))
        return base[idx];
    return ((s16 *)base)[idx];

two:
    if (flags & 0x10000000) {
        s16 *g = (s16 *)base + idx;
        u32 o = idx << 1;
        v0 = *(s16 *)((char *)base + o);
        v1 = g[1];
    } else {
        w = base + idx;
        v0 = base[idx];
        v1 = ((struct Obj16643 *)w)->f4;
    }
    return (v0 + v1) >> 1;
}





/*
 * Vector-2 keyframe sampler: the exact sibling of func_02070524 (the same flag
 * cascade, word for word) but every key is a PAIR of s16 packed into one word,
 * and the result is the two interpolated components packed back into one u32.
 * func_02070730 uses it for the animation node's rotation track, where
 * func_02070524 serves the scalar scale and translation tracks.  `flags` bit
 * 29 = inline value, bits 31:30 = key stride, bits 15:0 = key count; unlike
 * func_02070524 there is no bit-28 width selector, because the key type is
 * always the s16 pair.
 *
 * Per-file compiler pin, inherited from the cluster and from the caller
 * src/matched/func_02070730.c: ../2.0/sp2, not the project default.
 *
 * Three source levers, all measured (history in docs/notes/func_02070624.c.txt):
 *   1. in BOTH tail blocks the value read by byte-offset off `base` must be
 *      read and folded before the pointer local is created, or the four live
 *      s16 plus the pointer plus `base` want a sixth register and the leaf
 *      grows a `push {r3, lr}` the image does not have (the image is a pure
 *      leaf with four bare `bx lr`);
 *   2. the low half of the packed result is `((u32)(x >> k) & 0xffff)`, a
 *      shift and a mask.  Spelling it as the double shift
 *      `((u32)(x << (16-k)) >> 16)` emits the two halves' adds in the other
 *      order and exchanges r0 and r1 through all five packing instructions;
 *   3. in the `two:` block the high half's sum must go to a FRESH local
 *      (`s32 s = a + b;`) rather than accumulating into `a` (`a += b;`).
 *      The compound form keeps `a` live past its last read, so its sum lands
 *      in r1 and the low half's sum is then forced out of r0; letting `a` die
 *      at the sum puts both adds in r0 exactly as the image has them.
 *      Lever 3 was found by tools/permuter.py narrowing the residue to this
 *      one statement; the quad block already has this shape for free, because
 *      its `*3` weighting means each half is folded as it is read.
 *
 * No relocation sites: the function is self-contained.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070624.c \
 *       --func func_02070624 --addr 0x02070624 --cc ../2.0/sp2 --arm
 */
int func_02070624(u32 *base, u32 flags, u32 off, u32 idx)
{
    u32 n;
    u32 i0;

    if (flags & 0x20000000)
        return off;

    base = (u32 *)((int)base + off);

    if (flags & 0xc0000000) {
        n = flags & 0xffff;
        if (flags & 0x40000000) {
            if (idx & 1) {
                if (idx > n) { idx = (n >> 1) + 1; goto plain; }
                i0 = idx >> 1;
                goto two;
            }
            idx = idx >> 1;
            goto plain;
        } else {
            u32 r = idx & 3;
            if (r != 0) {
                if (idx > n) { idx = r + (n >> 2); goto plain; }
                if (idx & 1) {
                    s32 a, b, c, d;
                    if (idx & 2) { idx = idx >> 2; i0 = idx + 1; }
                    else         { i0 = idx >> 2; idx = i0 + 1; }
                    c = *(s16 *)((char *)base + (i0 << 2));
                    d = *(s16 *)((char *)base + (idx << 2));
                    c *= 3;
                    c += d;
                    a = ((s16 *)(base + i0))[1];
                    b = ((s16 *)(base + idx))[1];
                    a *= 3;
                    a += b;
                    return ((u32)(c >> 2) & 0xffff) | (u32)((a >> 2) << 16);
                }
                i0 = idx >> 2;
                goto two;
            }
            idx = idx >> 2;
        }
    }

plain:
    return base[idx];

two:
    {
        s32 c = *(s16 *)((char *)base + (i0 << 2));
        s16 *p = (s16 *)(base + i0);
        s32 a = p[1];
        s32 b = p[3];
        s32 d = p[2];
        s32 s = a + b;
        c += d;
        return ((u32)(c >> 1) & 0xffff) | (u32)((s >> 1) << 16);
    }
}




/*
 * Samples one animated node's six tracks (two scale, one rotation pair, two
 * translation) out of the per-node track descriptor record, writing the
 * results into the output block and maintaining the three "unchanged" bits of
 * its flags word.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md). Under
 * the pinned default dsi/1.1p1 -O4,p this body is 4 bytes short at +0x00A0;
 * under ../2.0/sp2 the same C is 256 bytes with ZERO concrete mismatches.
 * The one source change from the note was the order of the two translation
 * stores, which the 2.0 diff named directly (+0x0078/+0x007C emitted in
 * source order). Measurement and the probe are in docs/notes/func_02070730.c.txt.
 *
 * Parked at MATCH for lack of WITNESSES, not for lack of bytes: all 5
 * relocation sites (4x func_02070524, 1x func_02070624) are unresolved
 * because neither callee is EXACT in a shard and this function is their only
 * caller in the image, so every witness would fall inside 02070730..02070830
 * and no cut can free them. It becomes EXACT once those two are filed EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02070730.c \
 *       --func func_02070730 --addr 0x02070730 --cc ../2.0/sp2 --arm
 */
void func_02070730(struct Node70730 *node, u32 idx, u32 t, struct Out70730 *out)
{
    u8 *tbl;
    u32 fl;
    s32 a, b;
    struct Rec70730 *r;

    tbl = (u8 *)node + 8;
    if (tbl != 0 && idx < node->b09) {
        u8 *p = tbl + node->h0e;
        r = (struct Rec70730 *)(((struct Obj16645 *)p)->f0 * idx + (u32)(p + 4));
    } else {
        r = 0;
    }

    fl = out->f00;

    a = func_02070524((u32 *)node, r->f18, r->f1c, t);
    b = func_02070524((u32 *)node, r->f20, r->f24, t);
    if (a == 0 && b == 0) {
        fl |= 4;
    } else {
        out->f24 = (u32)a;
        out->f28 = (u32)b;
        fl &= ~4u;
    }

    a = func_02070624((u32 *)node, r->f10, r->f14, t);
    if (a == 0x10000000) {
        fl |= 2;
        goto rot_done;
    }
    {
        u32 rv = (u32)a;
        ((struct Obj02329 *)out)->f20 = (u16)rv;
        rv >>= 16;
        ((struct Obj02329 *)out)->f22 = (u16)rv;
    }
    fl &= ~2u;
rot_done:
    ;

    a = func_02070524((u32 *)node, r->f00, r->f04, t);
    b = func_02070524((u32 *)node, r->f08, r->f0c, t);
    if (a == 0x1000 && b == 0x1000) {
        fl |= 1;
    } else {
        out->f18 = a;
        out->f1c = b;
        fl &= ~1u;
    }

    out->f00 = fl;
}



static inline void *GetName(struct Src70830 *src, u32 idx)
{
    u8 *tbl = (u8 *)src + 8;
    if (tbl != 0 && idx < src->b09) {
        u8 *q = tbl + src->h0e;
        return q + ((struct Obj16646 *)q)->f2 + idx * 0x10;
    }
    return 0;
}



static inline s32 Lookup(u8 *names, void *ent)
{
    if (names != 0)
        return func_0206E7EC(names + 4, ent);
    return -1;
}



/*
 * Twin of func_02070360, instruction for instruction: the same channel
 * binder, differing only in the handler-table word that seeds ctx->f0c
 * (data_020A8228, which holds &func_02070904, where func_02070360 reads
 * data_020A8230 = &func_02070434).  The table at 0x020A8220.. pairs each
 * binder (0x020A8244.., tagged by a 4-char kind word) with the per-frame
 * driver it installs.  Same levers as func_02070360: the GetName/Lookup
 * inline helpers, `volatile u8 b09`, `i` declared before `names`, and the
 * ../2.0/sp2 pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070830.c
 *       --func func_02070830 --addr 0x02070830 --arm --cc ../2.0/sp2
 */
void func_02070830(struct Ctx70830 *ctx, struct Src70830 *src, struct Arg70830 *arg)
{
    u32 i;
    u8 *names;

    if (arg != 0 && arg->f08 != 0)
        names = (u8 *)arg + arg->f08;
    else
        names = 0;

    ctx->f0c = data_020A8228;
    ctx->b19 = arg->b18;
    MIi_CpuClear16(0, ctx->h1a, (u32)ctx->b19 * 2);

    for (i = 0; i < src->b09; i++) {
        s32 slot = Lookup(names, GetName(src, i));
        if (slot >= 0)
            ctx->h1a[slot] = (u16)(i | 0x100);
    }
}


/*
 * Blocked on evidence class `matched`: the one PC24 site is the bl to
 * func_02070730, and the only branch to that address anywhere in the image is
 * this very call, so no `label` witness exists outside the compared range.
 * Unblocks as soon as 0x02070730 has an EXACT manifest entry.
 *
 * Both struct fields the tail touches are `volatile`; without that on BOTH,
 * mwcc hoists the +0x00 load above the +0x10 store and reallocates.
 *
 * Forwards to the sampler at 0x02070730 with the animation record's frame
 * index (f0 >> 12, arithmetic) and its payload pointer, then rewrites the
 * two-bit state field at +0x10 to 0b01 and sets bit 3 of the flags word.
 */
void func_02070904(struct Dst70904 *dst, struct Anim70904 *a, u32 idx)
{
    func_02070730((struct Node70730 *)((struct Dst70904 *)a->p8), (u16)idx, (int)a->f0 >> 12, (struct Out70730 *)dst);
    dst->f10 = (dst->f10 & ~0xc0000000u) | 0x40000000u;
    dst->f0 |= 8;
}
