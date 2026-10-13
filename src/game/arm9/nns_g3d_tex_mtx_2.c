/*
 * file:     nns_g3d_tex_mtx_2.c
 * unit:     yes
 * function: func_02071C14, func_02071C94
 * address:  0x02071C14
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef short          s16;

typedef unsigned int   u32;

typedef int            s32;

typedef long long      s64;

struct SRC_02071C14 {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    s16 f22;
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
};

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

struct SRC_02071C94 {
    u8  pad_00[0x24];
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
};



/*
 * The 128-byte constructor of the cluster_02071360 family: f18/f1c
 * straight into the diagonal slots f00/f14, f04/f10 zeroed, and BOTH
 * translations through a 64-bit product against the diagonal:
 *   f30 = (f18 * ((-f2c << 11) - f24 * f2c)) >> 8  +  f2c << 15
 *   f34 = (f1c * (f28 * f2e + (-f2e << 11))) >> 8  +  f2e << 15
 *
 * What the image needs, all found by tools/permuter.py (hill then anneal,
 * 21 -> 6 -> 1 byte out, the last byte an s16 type probe whose value-
 * preserving u16 form closes it):
 *   - the four source halfword/word reads bound to locals BEFORE the first
 *     store to d->f30 (the image loads f2c, f24, f2e, f28 ahead of that
 *     store; f18/f1c and the final f2e are re-read after it);
 *   - the f34 multiplier computed into its own local ahead of the f30
 *     product (permuter `temp` + `hoist-up`);
 *   - the f2c local typed u16, the field's own type (s32 swaps r5/r6).
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 is 128 bytes with 6
 * concrete bytes out, a single swapped pair -- 1.1p1 schedules the final
 * `ldrh r1, [r1, #0x2e]` one slot EARLIER, ahead of `lsr r2, lr, #8`.
 * Under ../2.0/sp2 it is 0 out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02071C14.c \
 *       --func func_02071C14 --addr 0x02071C14 --arm --cc ../2.0/sp2
 */
void func_02071C14(struct DST *d, struct SRC_02071C14 *s)
{
    u16 c;
    s32 e, x, y;
    s64 m;
    s32 t34;

    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;

    c = s->f2c;
    x = s->f24;
    e = s->f2e;
    y = s->f28;

    t34 = y * e + ((0 - e) << 11);

    m = (s64)s->f18 * (((0 - c) << 11) - x * c);
    d->f30 = (s32)(m >> 8) + (c << 15);

    m = (s64)s->f1c * t34;
    d->f34 = (s32)(m >> 8) + ((s32)s->f2e << 15);

    d->f10 = 0;
}


/*
 * The scale-and-negate constructor of the 0x02071CDC family, following
 * 0x02071C14 in docs/notes/pkt_02071B2C.c.txt.  Writes the 0x1000 unit
 * scale into f00/f14, zeroes f04/f10, and derives f30/f34 from the
 * source's f24/f2c and f28/f2e pairs, the first of the two negated.
 *
 * Pin evidence (2.0), measured 2026-09-21: the "kept constants" tell in
 * exactly the stm-merge form its family-mate src/matched/func_02071180.c
 * already carries.  The image materialises the zero LATE, `mov ip, #0`
 * (`00 c0 a0 e3`) at 0x02071CA0, AFTER both `str r2, [r0]` at 0x02071C98
 * and `str r2, [r0, #0x14]` at 0x02071C9C have retired, which is what keeps
 * the f00 and f04 stores separate.  dsi/1.1p1 -O4,p sinks the zero above
 * the f00 store and MERGES the pair into one `stm r0, {r2, ip}`, giving 68
 * bytes against the original's 72 with the whole body shifted by four (56
 * concrete bytes out).  Under the pin the C below is 72 bytes, 0
 * mismatches, no relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02071C94.c \
 *       --func func_02071C94 --addr 0x02071C94 --arm --cc ../2.0/sp2
 */
void func_02071C94(struct DST *d, struct SRC_02071C94 *s)
{
    s32 n;

    d->f00 = 0x1000;
    d->f14 = 0x1000;
    d->f04 = 0;

    n = 0 - s->f24;
    d->f30 = n * s->f2c * 16;

    n = s->f28;
    d->f34 = n * s->f2e * 16;

    d->f10 = 0;
}
