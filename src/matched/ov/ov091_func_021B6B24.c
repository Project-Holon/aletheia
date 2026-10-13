/*
 * function: POKELIST_UpdatePaletteFade
 * address:  0x021B6B24
 * packet:   pkt_ov091_021B6B24
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Palette fade (u8 step countdown at +0x100, brighten src[3][16] into dst, skipping
 * columns 2..4, then a sine blend of dst[i][2..4] between two 3-colour tables, then
 * func_02061CA4(15, 0xc0, dst, 0x60)).
 * note: final push 2026-10-05 G9L1, EXACT in c99 and c. Four source facts closed the draft
 * (182 B off): (1) the phase update stores in each if/else arm (p->phase = p->phase - 0xfc00
 * or p->phase = t), so the 0x102 offset stays live in r1 and v sits in r3; (2) each blended
 * channel is clamped into a shared int t (`...; r = t;`) and assigned to a u8 local, which
 * puts the byte truncation at the join as in the image; (3) the blend deltas are written
 * red first (ar, br, dr, then green, then blue); the scheduler still emits green first, but
 * the red values are born first and take the registers the image shows; (4) f is declared
 * after the counters, and b is u16 while a is int. Earlier notes: hi and lo are two struct C3
 * locals, each delta is read three times (clamp), tried-and-failed forms in git history.
 * Callee 02061CA4 matches its 4-parameter definition.
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
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

void POKELIST_UpdatePaletteFade(struct Pal *p)
{
    u8 i;
    u8 i2;
    u8 j;
    u8 j2;
    u8 k;
    int f;
    struct C3 hi;
    struct C3 lo;

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
    hi = d_021BEBFC;
    lo = d_021BEC04;
    if (p->mode == 0) {
        int t = p->phase + 0x400;
        if (t >= 0x10000) {
            p->phase = p->phase - 0xfc00;
        } else {
            p->phase = t;
        }
    } else {
        p->phase = 0xc000;
    }
    f = (d_020A1B38[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i2 = 0; i2 < 3; i2++) {
        for (j2 = 0; j2 < 3; j2++) {
            int a = hi.v[j2];
            u16 b = lo.v[j2];
            u8 ar = a & 0x1f;
            u8 br = b & 0x1f;
            s8 dr = ((br - ar) * f) >> 12;
            u8 ag = (a & 0x3e0) >> 5;
            u8 bg = (b & 0x3e0) >> 5;
            s8 dg = ((bg - ag) * f) >> 12;
            u8 ab = (a & 0x7c00) >> 10;
            u8 bb = (b & 0x7c00) >> 10;
            s8 db = ((bb - ab) * f) >> 12;
            u8 r, g, bl;
            int t;
            if (ar + dr > 31) t = 31; else if (ar + dr < 0) t = 0; else t = ar + dr;
            r = t;
            if (ag + dg > 31) t = 31; else if (ag + dg < 0) t = 0; else t = ag + dg;
            g = t;
            if (ab + db > 31) t = 31; else if (ab + db < 0) t = 0; else t = ab + db;
            bl = t;
            p->dst[i2][j2 + 2] = r | (g << 5) | (bl << 10);
        }
    }
    func_02061CA4((void *)15, 0xc0, (u32)p->dst, 0x60);
}

