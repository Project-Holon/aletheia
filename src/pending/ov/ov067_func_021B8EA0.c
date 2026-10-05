/*
 * function: func_021B8EA0
 * address:  0x021B8EA0
 * packet:   pkt_ov067_021B8EA0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * recoup 2026-10-05 (wave P9 lane X8): no pending file existed; this is the old docs/notes
 *   draft, now filed. DIFF14 unchanged (256 bytes, 4 relocations resolved): the original emits
 *   `movs r6,#1; str r6,[sp]` before `lsls r2,r4,#24`, ours stores [sp] last. Levers tried, one
 *   compile each: func_021B841C declared int (matched return type) and lim int, plain literal 1
 *   for arg 5 and f70 (14 B, same); static inline go(s,v,d,flag) wrapper (14 B); s->f70 = 1 before
 *   the call (19 B); u32 one = 1 right before the call with literal return (14 B) and
 *   `call(..., one = 1)` (14 B); d = (lim < d) ? lim : d (20 B); call written in each arm (68 B);
 *   pragmas opt_lifetimes, opt_propagation, scheduling, peephole off (14 B each),
 *   opt_common_subs off (199 B), opt_dead_assignments off (120 B). Callee types: func_021B8434 is
 *   void (own file), func_021B841C returns int; no void-return problem. In matched 8DF0 the
 *   literal 1 sits in r0 and is stored first; here the 1 lives in r6 across the call and its
 *   first materialisation is placed after the lsls. Idioms checked: see lane report.
 *
 * symbols:
 *   func_021B841C  0x021B841C  thumb  ov067
 *   func_021B8434  0x021B8434  thumb  ov067
 *   d_021B94F8     0x021B94F8  data   ov067  a1
 *   d_021B94FE     0x021B94FE  data   ov067  a1
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 _0[0xb];
    s8 fb[6];
    u8 _11[0x70 - 0x11];
    u32 f70;
    u8 _74[0x85 - 0x74];
    s8 f85;
    u8 f86 : 5;
    u8 f86_5 : 3;
    u8 _87[0x89 - 0x87];
    u8 f89;
    u8 _8a[0x8c - 0x8a];
    u32 f8c;
    u32 f90;
};

extern const u8 d_021B94F8[6];
extern const u8 d_021B94FE[][6];

extern int func_021B841C(struct S *s, int dir);
extern void func_021B8434(struct S *s, int a, u8 b, u16 c, u32 d);

int func_021B8EA0(struct S *s)
{
    u32 d;
    int v;
    int lim;

    if ((s->f85 < 0 && s->f90 > s->f8c) || (s->f85 > 0 && s->f90 < s->f8c))
        return 0;
    d = s->f90 - s->f8c;
    if ((int)d < 0)
        d = -d;
    if (d == 0)
        return 0;
    for (s->f89 = 0; s->f89 < 6; s->f89++) {
        if (d >= d_021B94FE[s->f86][s->f89]) {
            v = s->fb[s->f89];
            d = d_021B94F8[s->f89];
            break;
        }
    }
    if (s->f89 == 6)
        return 0;
    if (s->f8c > s->f90)
        v *= -1;
    lim = func_021B841C(s, v);
    if (lim != 0) {
        if (lim < d)
            d = lim;
        func_021B8434(s, v, d, 3, 1);
        s->f70 = 1;
        return 1;
    }
    return 0;
}
