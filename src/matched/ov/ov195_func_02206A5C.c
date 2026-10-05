/*
 * function: func_02206A5C
 * address:  0x02206A5C
 * packet:   pkt_ov195_02206A5C
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 2026-10-05 (wave P2 lane Q1b, pengy share): EXACT* (974 B compiled, the
 * listing extent is 976 B with the trailing pad). Written bottom-up from the
 * matched twin func_02206E2C (same Grid/Ent, 18 x 18 entries of 0x80 bytes).
 * What closed the dx/dy/dz block: fx64 (long long) locals lx, ly, lz assigned
 * in the loop body (lz, then lx, then ly) and multiplied directly; LICM hoists
 * their sign words above the first _ll_mul and spills them, which gives the
 * extra frame word and the r6/r7 colours. Declaration order l2, dx.., row sets
 * the slots ([sp,#0x10] row, [sp,#0x18] l2). The pool word 0.13580248f
 * (0x3E0B0FCE) replaces the earlier 0.13636364f guess. Tried before: static
 * inline FX_Mul with long long parameters (966 B, no change).
 *
 * symbols:
 *   func_02206E2C 0x02206E2C thumb ov195
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _fgr 0x0209BBB0 arm
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _ffix 0x0209C494 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   func_0207C768 0x0207C768 arm
 *   d_020A1B38 0x020A1B38 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef s32 fx32;

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((long long)a * b + 0x800) >> 12);
}

typedef struct SC { s16 s; s16 c; } SC;
extern const SC d_020A1B38[];
extern int FX_Sqrt(int);
extern int func_0207C768(int a, int b);
extern void func_02206E2C(void *p);

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

typedef struct Ent {
    u8 pad00[0x30];
    s32 f30;
    Vec3 v34;
    s32 f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64;
    Vec3 cur;
    Vec3 org;
} Ent;

typedef struct Grid {
    u8 pad00[0x28];
    s32 f28;
    u16 h2c[16];
    u16 h4c;
    u8 pad4e[2];
    u16 h50;
    u16 h52, h54, h56, h58, h5a;
    s16 h5c;
    u16 h5e, h60;
    u8 pad62[2];
    s32 f64, f68, f6c, f70;
    Ent e[18][18];
    u8 count;
} Grid;

void func_02206A5C(Grid *p)
{
    u8 i;
    u8 q;
    u8 j;
    u8 d;
    u8 v;
    int m;
    float s, t;
    int l2;
    Ent *e;
    int dx, dy, dz, l1;
    Ent *row;
    long long lx, ly, lz;

    func_02206E2C(p);
    p->f28 = 0;
    for (i = 0; i < 16; i++)
        p->h2c[i] = 0x7FFF;
    p->h4c = 0x7FFF;
    q = 0;
    p->h56 = q;
    p->h52 = q;
    p->h54 = q;
    p->h58 = q;
    p->h5a = 0x11;
    p->h5c = 8;
    p->h5e = q;
    p->h60 = p->h5c + 1;
    p->f64 = q;
    p->f68 = q;
    p->f6c = q;
    p->f70 = q;
    p->count = q;
    for (; q < 18; q++) {
        j = 0;
        d = q / 3;
        row = p->e[q];
        m = q % 3;
        for (; j < 18; j++) {
            e = &row[j];
            e->f30 = 0;
            e->v34 = e->cur;
            if (m == 0) {
                if (j < 9)
                    v = 6 * j;
                else
                    v = 6 * (j - 9) + 1;
            } else if (m == 1) {
                if (j < 9)
                    v = 6 * j + 2;
                else
                    v = 6 * (j - 9) + 3;
            } else {
                if (j < 9)
                    v = 6 * j + 4;
                else
                    v = 6 * (j - 9) + 5;
            }
            e->f4c = ((int)v << 16) / 54;
            e->f54 = FX_F32_TO_FX32(22.0f - 7.3333335f * (float)d - 0.13580248f * (float)v);
            t = (float)e->f54 / 4096.0f;
            s = 10.0f + 2.0f * (2.0f * (t * (10.0f * t) / 44.0f / 44.0f));
            e->f50 = FX_F32_TO_FX32(s);
            e->f58 = FX_Mul(e->f50, d_020A1B38[e->f4c >> 4].c);
            e->f60 = FX_Mul(e->f50, d_020A1B38[e->f4c >> 4].s);
            e->f5c = e->f54;
            dx = e->f58 - e->cur.x;
            dy = e->f5c - e->cur.y;
            dz = e->f60 - e->cur.z;
            lz = dz;
            lx = dx;
            ly = dy;
            l1 = FX_Sqrt((fx32)((lx * lx + 0x800) >> 12) + (fx32)((lz * lz + 0x800) >> 12));
            l2 = FX_Sqrt((fx32)((ly * ly + 0x800) >> 12));
            if (l1 > 0x1000) {
                e->f40 = func_0207C768(dx, l1);
                e->f48 = func_0207C768(dz, l1);
            } else {
                e->f40 = dx;
                e->f48 = dz;
            }
            if (l2 > 0x1000)
                e->f44 = func_0207C768(dy, l2);
            else
                e->f44 = dy;
            e->f64 = 0;
        }
    }
}
