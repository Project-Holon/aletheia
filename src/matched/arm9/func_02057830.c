/*
 * function: func_02057830
 * address:  0x02057830
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  own-pool - the one unresolved site is the ABS32 to g_020A7FEC at
 *           +0x284, and that address's only pooled word image-wide is the word
 *           at 0x02057AB4, inside this function's own range
 *           (0x02057830..0x02057AB8).  `match.py one` prints verbatim:
 *           "+0284 ABS32 g_020A7FEC -> unresolved: 020A7FEC (data, from
 *           header) has no witness outside 02057830..02057AB8".  Confirmed by
 *           a raw word scan of the arm9 region: exactly one occurrence of the
 *           little-endian word ec 7f 0a 02, at 0x02057AB4.  The four PC24
 *           branch sites all resolve `label`.  A single-function row, so
 *           --suggest-split has nothing to cut: the site's only witness is
 *           inside the range that needs it.
 * symbols:
 *   func_0207CAA4  0x0207CAA4  arm
 *   func_0207CDB8  0x0207CDB8  arm
 *   g_020A7FEC     0x020A7FEC  data
 *
 * First transcription (wave r11 lane B), MATCH on the second variant: 648 of
 * 648 bytes, every concrete byte identical, only the own-pool site wildcarded.
 * Whole body from the structure map in docs/notes/pkt_02057830.c.txt,
 * re-confirmed by a fresh `match.py show --addr 0x02057830` this run.
 *
 * Shape: a rig basis build.  `a` is the pooled axis (0, 0x1000, 0) at
 * 0x020A7FEC, `v` comes from a two-bit mode field of the object graph
 * `m->f20->f00->mode` (one of the three unit axes, or VEC_Fx16Normalize of
 * m+0x50 in the default arm), then the two basis rows are the cross product
 * of v with a and of v with the first row, computed inline with the FX_Mul
 * rounding quartet (the same shape as the sibling func_020576D0), and the
 * two rows are normalised in place with the same two-identical-arguments
 * call the sibling records as load-bearing.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02057830.c \
 *       --func func_02057830 --addr 0x02057830 --arm --cc ../1.2/sp2
 */

typedef int          fx32;
typedef long long    fx64;
typedef short        s16;
typedef unsigned char u8;
typedef unsigned int  u32;

struct Vec16 { s16 x, y, z; };

struct Mode {
    u32 _unused : 6;
    u32 mode    : 2;
    u32 _rest   : 24;
};

struct Mid { struct Mode *f00; };

struct Rig {
    u8           pad_00[0x20];
    struct Mid  *f20;
    u8           pad_24[0x2c];
    struct Vec16 f50;
    u8           pad_56[0x2e];
    s16          r0[3];
    s16          r1[3];
};

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((fx64)a * b + 0x800) >> 12);
}

extern void func_0207CDB8(struct Vec16 *v, struct Vec16 *w);
extern fx32 func_0207CAA4(const struct Vec16 *a, const struct Vec16 *b);
extern const struct Vec16 g_020A7FEC;

void func_02057830(struct Rig *m)
{
    struct Vec16 a;
    struct Vec16 v;
    fx32 d;

    a = g_020A7FEC;

    switch (m->f20->f00->mode) {
    case 2:
        v.x = 0x1000;
        v.y = 0;
        v.z = 0;
        break;
    case 1:
        v.x = 0;
        v.y = 0x1000;
        v.z = 0;
        break;
    case 0:
        v.x = 0;
        v.y = 0;
        v.z = 0x1000;
        break;
    default:
        func_0207CDB8(&m->f50, &v);
        break;
    }

    d = func_0207CAA4(&a, &v);
    if (d == 0x1000 || d == -0x1000) {
        a.x = 0x1000;
        a.y = 0;
        a.z = 0;
    }

    m->r0[0] = FX_Mul(v.y, a.z) - FX_Mul(v.z, a.y);
    m->r0[1] = FX_Mul(v.z, a.x) - FX_Mul(v.x, a.z);
    m->r0[2] = FX_Mul(v.x, a.y) - FX_Mul(v.y, a.x);
    m->r1[0] = FX_Mul(v.y, m->r0[2]) - FX_Mul(v.z, m->r0[1]);
    m->r1[1] = FX_Mul(v.z, m->r0[0]) - FX_Mul(v.x, m->r0[2]);
    m->r1[2] = FX_Mul(v.x, m->r0[1]) - FX_Mul(v.y, m->r0[0]);

    func_0207CDB8((struct Vec16 *)(m->pad_00 + 0x84), (struct Vec16 *)(m->pad_00 + 0x84));
    func_0207CDB8((struct Vec16 *)(m->pad_00 + 0x8a), (struct Vec16 *)(m->pad_00 + 0x8a));
}
