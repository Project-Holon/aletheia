/*
 * function: SPLAnim_Alpha
 * address:  0x02057BC0
 * packet:   pkt_02057BC0
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   g_02146A8C     0x02146A8C  data
 *
 * wave r10 lane closeC: EXACT, 220 bytes, 3 of 3 relocation sites resolved.
 * Two spellings closed the r8/r9 13-byte residue, and the first one is the
 * whole register tie-break:
 *
 *  - the third arm's base is `p->hi`, NOT `p->mid`.  The image's base shift is
 *    `lsl r6, r0, #0x11` at 0x02057C20 (rec << 17, i.e. the hi channel), where
 *    a `p->mid +` base emits `lsl r6, ..., #0x16` (rec << 22).  The two forms
 *    are the same value - hi + (t-0xff)*(hi-mid)/(0xff-b) equals
 *    mid + (t-b)*(hi-mid)/(0xff-b) - but only the hi-referenced form gives the
 *    image's instruction for instruction allocation, including the r3 handover
 *    at 0x02057C24 (`b` dies at the rsb on the line before, r3 is reused for hi).
 *
 *  - the tail's halfword is `w = (u16)((v * (0xff - q)) >> 8);`, a RIGHT shift.
 *    The image's `lsl r0, r1, #8` / `lsr r0, r0, #0x10` at 0x02057C70 is the
 *    u16 cast of a right shift of 8, not of a left shift: see
 *    docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 *    (32 - 16 = 16 = the cast width; 8 - 16 = -8 = the source shift).  The r8
 *    note's `<< 8` spelling compiles to `lsl #0x18`, one byte out.
 *
 * The r9 lever (moving the `b` definition inside the else or into the guard) and
 * the r8 lever set (24 declaration orders, five member types, the a/b assignment
 * order, nested-if, `b > t`, in-place member reads, three return types) are all
 * superseded by the base fix above; none of them is needed.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct Rec {
    u16 lo : 5;
    u16 mid : 5;
    u16 hi : 5;
    u16 _unused : 1;
    u8 f02;
    u8 _03;
    u8 a;
    u8 b;
};

struct S {
    char _00[0xc];
    struct Rec *f0c;
};

struct O {
    char _00[0x2e];
    u16 f2e;
};

u32 g_02146A8C;

extern int _s32_div_f(int num, int den);

void SPLAnim_Alpha(struct O *o, struct S *s, int t)
{
    struct Rec *p;
    int a;
    int b;
    int v;
    int r;
    int q;
    u16 f02;
    u16 w;

    p = s->f0c;
    a = p->a;
    b = p->b;

    if (t < a) {
        v = p->lo + t * (p->mid - p->lo) / a;
    } else if (t < b) {
        v = p->mid;
    } else {
        v = p->hi + (t - 0xff) * (p->hi - p->mid) / (0xff - b);
    }

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 24;
    f02 = p->f02;
    q = f02 * r;
    q = q >> 8;
    w = (u16)((v * (0xff - q)) >> 8);
    o->f2e = (o->f2e & ~0x3e0) | ((w & 0x1f) << 5);
}
