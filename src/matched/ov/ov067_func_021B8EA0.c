/*
 * function: func_021B8EA0
 * address:  0x021B8EA0
 * packet:   pkt_ov067_021B8EA0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * pass 2 2026-10-06 P2L28: EXACT (was DIFF 14/256 in X8 and G4L7). The fix is the callee
 *   declaration that the matched ov067 callers 021B8B74 and 021B806C use: func_021B8434 takes
 *   `s8 a`, and v is an s8 local. With `int a` the 1 for the stack argument was placed after
 *   the u8 narrowing of d; with s8 it is stored first, as in the image. EXACT in c99 and c.
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
extern void func_021B8434(struct S *s, s8 a, u8 b, u16 c, u32 d);

int func_021B8EA0(struct S *s)
{
    u32 d;
    s8 v;
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
