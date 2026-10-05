/*
 * function: func_021B6B24
 * address:  0x021B6B24
 * packet:   pkt_ov091_021B6B24
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * Palette fade (u8 step countdown at +0x100, brighten src[3][16] into dst, skipping
 * columns 2..4, then a sine blend of dst[i][2..4] between two 3-colour tables, then
 * func_02061CA4(15, 0xc0, dst, 0x60)). 560 B compiled, original 576.
 * 2026-10-05 (wave P3 lane R7): no matched twin found (lerp shape matches ov105 021B8734
 * only loosely). The first loop is exact in instruction order and colours once p is a
 * struct with src/dst [3][16] arrays and separate counters i, i2 (i2 declared after i).
 * Residue is in the second loop and the phase update: the original spills the row
 * pointer (p + i2*32) to [sp+4] and the delta to [sp+0x14], keeps f in r4 and j in r3,
 * recomputes j*2 and the stack table bases each iteration; ours keeps f in r2, j in r4,
 * row in r7 and hoists j*2. Phase update: original loads v into r3 and keeps the 0x102
 * pool offset in r1; ours puts v in r1. With `#pragma opt_dead_assignments off` the frame
 * (0x28), size (576) and all spill slots match (153 B differ, only r3/r4 colours, the
 * stack table address form and the v register); no other pragma helped (421, 482, 451,
 * 231, 231 B). Tried: row local at function scope, raw row pointer, int v, expression
 * without v, one struct for both tables, separate j2. Not filed with a pragma: DIFF.
 * Callee 02061CA4 matches its 4-parameter definition (the [sp] store is p's home slot).
 *
 * symbols:
 *   func_02082A60  0x02082A60  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021BEBFC     0x021BEBFC  data  a1
 *   d_021BEC04     0x021BEC04  data  a1
 *   d_020A1B38     0x020A1B38  data  a2
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct C3 { u16 v[3]; };
struct Pal {
    u8 pad0[0x10];
    u32 mode;
    u8 pad1[0x2c];
    u16 src[3][16];
    u16 dst[3][16];
    u8 step;
    u8 pad2;
    u16 phase;
};
extern const struct C3 d_021BEBFC;
extern const struct C3 d_021BEC04;
extern s16 d_020A1B38[];
extern void func_02082A60(void *src, void *dst, u32 size);
extern int func_02061CA4(u32 a, u32 b, void *c, u32 size);

void func_021B6B24(struct Pal *p)
{
    u8 i;
    u8 i2;
    u8 j;
    u8 j2;
    u8 k;
    struct { struct C3 lo; struct C3 hi; } t6;
    int f;

    func_02082A60(p->src, p->dst, 0x60);
    if (p->step != 0) {
        p->step--;
        k = p->step;
        if (k > 6) {
            k = 12 - k;
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 16; j++) {
                if (j >= 2 && j <= 4) {
                    continue;
                }
                {
                    u16 c = p->src[i][j];
                    u8 g = (c & 0x3e0) >> 5;
                    u8 b = (c & 0x7c00) >> 10;
                    u8 r = c & 0x1f;
                    int t;
                    t = r + k * 2;
                    if (t > 31) t = 31;
                    r = t;
                    t = g + k * 2;
                    if (t > 31) t = 31;
                    g = t;
                    t = b + k * 2;
                    if (t > 31) t = 31;
                    b = t;
                    p->dst[i][j] = r | (g << 5) | (b << 10);
                }
            }
        }
    }
    t6.hi = d_021BEBFC;
    t6.lo = d_021BEC04;
    if (p->mode == 0) {
        int t = p->phase + 0x400;
        if (t >= 0x10000) {
            t = p->phase - 0xfc00;
        }
        p->phase = t;
    } else {
        p->phase = 0xc000;
    }
    f = (d_020A1B38[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i2 = 0; i2 < 3; i2++) {
        for (j2 = 0; j2 < 3; j2++) {
            u16 a = t6.hi.v[j2];
            u16 b = t6.lo.v[j2];
            u8 ag = (a & 0x3e0) >> 5;
            u8 bg = (b & 0x3e0) >> 5;
            s8 dg = ((bg - ag) * f) >> 12;
            u8 ab = (a & 0x7c00) >> 10;
            u8 bb = (b & 0x7c00) >> 10;
            s8 db = ((bb - ab) * f) >> 12;
            u8 ar = a & 0x1f;
            u8 br = b & 0x1f;
            s8 dr = ((br - ar) * f) >> 12;
            int r = ar + dr;
            int g = ag + dg;
            int bl = ab + db;
            if (r > 31) r = 31; else if (r < 0) r = 0;
            if (g > 31) g = 31; else if (g < 0) g = 0;
            if (bl > 31) bl = 31; else if (bl < 0) bl = 0;
            p->dst[i2][j2 + 2] = (u8)r | ((u8)g << 5) | ((u8)bl << 10);
        }
    }
    func_02061CA4(15, 0xc0, p->dst, 0x60);
}
