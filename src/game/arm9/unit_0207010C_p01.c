/*
 * file:     unit_0207010C_p01.c
 * unit:     yes
 * function: func_0207010C, func_02070274, func_02070360
 * address:  0x0207010C
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
 *   data_020A8230    0x020A8230  data
 */
#include "../../matched/include/Obj16639.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Src70360 {
    u8  pad00[8];
    u8  b08;
    volatile u8 b09;
    u8  pad0a[4];
    u16 h0e;
};

struct Ctx70360 {
    u8  pad00[8];
    u32 f08;
    u32 f0c;
    u8  pad10[9];
    u8  b19;
    u16 h1a[1];
};

struct Arg70360 {
    u8  pad00[8];
    u32 f08;
    u8  pad0c[12];
    u8  b18;
};

void MIi_CpuClear16(u16 value, void *dest, u32 size);
s32 func_0206E7EC(void *name, void *ent);
u16 func_0207010C(u8 *base, u32 flags, u32 idx);
u16 func_02070274(u8 *base, u32 flags, u32 idx);
extern u32 data_020A8230;



/*
 * RGB555 colour keyframe sampler, the u16-key sibling of
 * src/matched/func_02070274.c (same descriptor word: bit 29 = inline value,
 * bits 31:30 = key stride, bits 28:16 = key count, bits 15:0 = key offset).
 * The two-key mean and the 3:1 blend are done per channel group with the
 * 0x7C1F (red+blue) and 0x03E0 (green) masks, so one add serves two
 * channels.  func_02070434 calls it four times (0x0207048C..0x020704E0).
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): the
 * image keeps `cmp r2, r3` / `bls 0x02070168` at 0x02070150 / 0x02070154
 * over the four-instruction clamp return (`bic r1, r3, #1` / `add r0, r0,
 * r1` / `ldrh r0, [r0, #2]` / `bx lr`); dsi/1.1p1 -O4,p predicates it to
 * bichi/addhi/ldrhhi/bxhi and the same C is 352 bytes against 360, 246
 * concrete bytes out.  Under ../2.0/sp2 the same C is 360 bytes, 0 mismatches.
 *
 * Source levers: the shared `two:` block takes its own index i0 (not idx),
 * as in src/matched/func_02070624.c; the 3:1 arm's index pair is a fresh
 * pair (i0, j), not idx rewritten in place; and the 3:1 arm reads its second
 * key p[j] directly in both channel sums rather than through a local (found
 * by tools/permuter.py, expand(v1)).
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0207010C.c \
 *       --func func_0207010C --addr 0x0207010C --cc ../2.0/sp2 --arm
 */
u16 func_0207010C(u8 *base, u32 flags, u32 idx)
{
    u16 *p;
    u32 n;
    u32 i0;
    u32 v0, v1, g, rb;

    if (flags & 0x20000000)
        return (u16)flags;

    p = (u16 *)(base + (u16)flags);

    if ((flags & 0xc0000000) == 0)
        return p[idx];

    n = (flags & 0x1fff0000) >> 16;
    if (flags & 0x40000000) {
        if (idx & 1) {
            if (idx > n)
                return (p + (n >> 1))[1];
            i0 = idx >> 1;
            goto two;
        }
        return p[idx >> 1];
    } else {
        u32 r = idx & 3;
        if (r != 0) {
            if (idx > n)
                return (p + (n >> 2))[r];
            if (idx & 1) {
                u32 j;
                if (idx & 2) { j = idx >> 2; i0 = j + 1; }
                else { i0 = idx >> 2; j = i0 + 1; }
                v0 = p[i0];
                g = ((v0 & 0x3e0) * 3 + (p[j] & 0x3e0)) >> 2;
                rb = ((v0 & 0x7c1f) * 3 + (p[j] & 0x7c1f)) >> 2;
                return (u16)((rb & 0x7c1f) | (g & 0x3e0));
            }
            i0 = idx >> 2;
            goto two;
        }
        return p[idx >> 2];
    }

two:
    v0 = p[i0];
    v1 = (p + i0)[1];
    g = ((v0 & 0x3e0) + (v1 & 0x3e0)) >> 1;
    rb = ((v0 & 0x7c1f) + (v1 & 0x7c1f)) >> 1;
    return (u16)((rb & 0x7c1f) | (g & 0x3e0));
}



/*
 * u8 keyframe sampler, the byte-key sibling of src/matched/func_02070524.c
 * (same track descriptor word: bit 29 = inline value, returned as its low
 * half; bits 31:30 = full / half / quarter key stride; bits 28:16 = key
 * count n; bits 15:0 = the key block's offset from base).  Its one caller,
 * func_02070434 at 0x0207050C, shifts the result into bits 16..20 of a
 * packed word, hence the u16 return.
 *
 * Front end: filed under the packet's ../2.0/sp2 unit pin
 * (docs/notes/pkt_0206EB00.c.txt, docs/FRONTEND-PINS.md).  This function is
 * neutral between front ends: the same C is EXACT under dsi/1.1p1 as well (measured
 * 2026-09-22), so it carries no tell of its own.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070274.c \
 *       --func func_02070274 --addr 0x02070274 --cc ../2.0/sp2 --arm
 */
u16 func_02070274(u8 *base, u32 flags, u32 idx)
{
    u8 *p;
    u32 n;
    u32 i0;
    u32 v0, v1;

    if (flags & 0x20000000)
        return (u16)flags;

    p = base + (u16)flags;

    if ((flags & 0xc0000000) == 0)
        return p[idx];

    n = (flags & 0x1fff0000) >> 16;
    if (flags & 0x40000000) {
        if (idx & 1) {
            if (idx > n)
                return (p + (n >> 1))[1];
            idx = idx >> 1;
            v0 = p[idx];
            v1 = (p + idx)[1];
            return (u16)((v0 + v1) >> 1);
        }
        return p[idx >> 1];
    } else {
        u32 r = idx & 3;
        if (r != 0) {
            if (idx > n)
                return (p + (n >> 2))[r];
            if (idx & 1) {
                if (idx & 2) { idx = idx >> 2; i0 = idx + 1; }
                else { i0 = idx >> 2; idx = i0 + 1; }
                v0 = p[i0];
                v1 = p[idx];
                v0 *= 3;
                v0 += v1;
                return (u16)(v0 >> 2);
            }
            idx = idx >> 2;
            v0 = p[idx];
            v1 = (p + idx)[1];
            return (u16)((v0 + v1) >> 1);
        }
        return p[idx >> 2];
    }
}


static inline void *GetName(struct Src70360 *src, u32 idx)
{
    u8 *tbl = (u8 *)src + 8;
    if (tbl != 0 && idx < src->b09) {
        u8 *q = tbl + src->h0e;
        return q + ((struct Obj16639 *)q)->f2 + idx * 0x10;
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
 * Channel binder: seeds ctx->f0c from the handler table word at
 * data_020A8230, copies the slot count, clears the halfword slot table at
 * +0x1a, then for each of src's b09 name entries resolves the name through
 * func_0206E7EC and stores `i | 0x100` at the returned slot.
 *
 * WHAT CLOSED IT (wave 10), after the 10-instruction prologue window of
 * docs/notes/func_02070360.c.txt at 1.1p1: the body is two INLINE HELPERS,
 * a name-entry accessor GetName(src, i) (the +8 table idiom, entries at a
 * 0x10 stride that the compiler strength-reduces into the r8 step) and a
 * guarded lookup Lookup(names, ent) returning -1 when there is no name
 * table.  Written that way the function is size-exact under ../2.0/sp2 and
 * the prologue window is right (the separate `mov r0,#0` for the clear's
 * fill and `mov r6,#0` for the counter is the pin's "kept constants" tell);
 * dsi/1.1p1 on the same C is 204 bytes with an 8-register push.  The last
 * r6/r7 swap is declaration order: `u32 i;` before `u8 *names;`.
 * `volatile u8 b09` is still required (216 bytes without it).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070360.c
 *       --func func_02070360 --addr 0x02070360 --arm --cc ../2.0/sp2
 */
void func_02070360(struct Ctx70360 *ctx, struct Src70360 *src, struct Arg70360 *arg)
{
    u32 i;
    u8 *names;

    if (arg != 0 && arg->f08 != 0)
        names = (u8 *)arg + arg->f08;
    else
        names = 0;

    ctx->f0c = data_020A8230;
    ctx->b19 = arg->b18;
    MIi_CpuClear16(0, ctx->h1a, (u32)ctx->b19 * 2);

    for (i = 0; i < src->b09; i++) {
        s32 slot = Lookup(names, GetName(src, i));
        if (slot >= 0)
            ctx->h1a[slot] = (u16)(i | 0x100);
    }
}
