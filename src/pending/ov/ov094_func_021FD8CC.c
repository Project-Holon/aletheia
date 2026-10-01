/*
 * function: func_021FD8CC
 * address:  0x021FD8CC
 * packet:   pkt_ov094_021FD8CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_02051A34  0x02051A34  arm
 *   func_0207BC08  0x0207BC08  arm
 *   func_021FE1B8  0x021FE1B8  thumb  ov094
 *   func_02051838  0x02051838  arm
 *   d_020A1B38  0x020A1B38  data
 *   _ll_mul  0x0209C054  arm
 *
 * 2026-10-01 DIFF: same instruction stream except colouring. The image
 * keeps the 0 (high word of the 0x800 rounding addend) in r4, the register
 * of the dead `active` parameter, for all three MULs and both `= 0` stores,
 * with the angle index in r7 and `b` in r6; this C puts `b` in r4, the zero
 * in r7, and rematerialises a fresh zero (r3) in the else arm. Declaring `s`
 * after `v`, `a`, `b` fixed s/active (r5/r4). Tried: if/else vs ternary
 * index, a named zero local, one-expression MUL (worse, 23..92 bytes).
 * Lane G1-18 also tried (no gain): int a/b with u16 casts, b declared
 * before a, a static inline MUL, the index as an int local, moving the
 * `= 0` stores first in each arm, inlining the a/b expressions (worse).
 * Caller func_021FD1CC (same lane) shows s is a 0x60 object: 3x3 matrix,
 * pos at 0x24, counters from 0x30.
 */
typedef signed short s16;
typedef unsigned short u16;
typedef struct { int x, y, z; } VecFx32;
extern const s16 d_020A1B38[];
extern int *func_02051A34(void *p);
extern void func_0207BC08(const VecFx32 *a, const void *b, VecFx32 *out);
extern void func_02051838(void *p, const VecFx32 *v);
extern void func_021FE1B8(VecFx32 *v, const VecFx32 *ofs);
#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))
void func_021FD8CC(void *p, int active)
{
    VecFx32 v;
    u16 a;
    u16 b;
    int *s;

    s = func_02051A34(p);
    if (s[18] == 0 || active == 0)
        return;
    if (s[19] == 3) {
        if (s[20] != 0) {
            s[20]--;
            return;
        }
        s[22] += 0xc;
        s[21] += s[22];
        s[20] = s[21] >> 12;
    }
    s[18]--;
    s[14] += s[16];
    s[15] += s[17];
    a = (s[14] >> 12) + 0xc000;
    b = (s[15] >> 12) + 0xc000;
    v.x = d_020A1B38[(a >> 4) * 2];
    v.x = MUL(v.x, s[12]);
    v.x += s[12];
    if (s[19] == 6) {
        v.z = d_020A1B38[(b >> 4) * 2 + 1];
        v.z = MUL(v.z, s[13]);
        v.y = 0;
    } else {
        v.y = d_020A1B38[(s[19] == 5) ? (b >> 4) * 2 + 1 : (a >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    }
    func_0207BC08(&v, s, &v);
    if (s[23] != 0)
        func_021FE1B8(&v, 0);
    func_02051838(p, &v);
}
