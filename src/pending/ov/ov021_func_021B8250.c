/*
 * function: func_021B8250
 * address:  0x021B8250
 * packet:   pkt_ov021_021B8250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: twin of func_021B7DE0 (same mul/spill/copy residue, see its
 * header). Everything else matches, the tail shifted by 2 B: the image
 * hoists `movs r3,#0x48` and `ldr r7,[r6,#0x34]` into the first struct copy,
 * multiplies off into r3 during the second copy, spills it, and passes
 * `adds r0,r3,#0; adds r0,r7,r0`; this compiler sinks the multiply to the
 * first call. Inert: __restrict out, base before/after either copy, off
 * before *out = a, `(u32)base + off`.
 *
 * symbols:
 *   func_021B9278  0x021B9278  thumb  ov021
 *   func_021B9280  0x021B9280  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u16 h0; u8 b2; u8 pad3; s16 h4; u16 h6; } Arg;
typedef struct Tbl { u16 f0; u16 f2; u8 pad4[0x10]; u8 *f14; } Tbl;

typedef struct Mgr {
    u8 pad00[0x20];
    Tbl tbl;
    u8 pad38[0x14];
    u32 f4C;
} Mgr;

extern int func_021B9278(u8 *a, u32 b, Tbl *t);
extern int func_021B9280(u8 *a, s32 y, s32 v, Tbl *t);

void func_021B8250(Mgr *m, const Arg *src, Arg *out)
{
    Arg a;
    u8 *base;
    s32 off;
    s32 x;
    s32 y;
    s32 v;
    s32 w;

    a = *src;
    *out = a;
    off = a.h0 * 0x48;
    base = m->tbl.f14;
    y = a.h6 << 4;
    x = a.h4 << 4;
    v = func_021B9278(base + off, m->f4C, &m->tbl);
    w = func_021B9280(base + off, y, v, &m->tbl);
    if (y >= v)
        out->h6 = (v - 1) / 16;
    if ((x < 0 ? -x : x) > w) {
        if (x > 0)
            out->h4 = w / 16;
        else
            out->h4 = -w / 16;
    }
}
