/*
 * function: func_02206E2C
 * address:  0x02206E2C
 * packet:   pkt_ov195_02206E2C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _fgr 0x0209BBB0 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _s32_div_f 0x0209C0A4 arm
 *
 * Builds a 18 x 18 grid of 0x80-byte entries: each gets two rounded fx32
 * corner sets, a position (cur) and its copy (org). The 0.0f offsets and the
 * 16/3 step are locals (z, k): the compiler propagates them only after folding,
 * so `z * (A / k)` stays a _fmul and `(float)r * k` keeps k as the second operand.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef s32 fx32;

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

typedef struct Ent {
    u32 w00;
    s32 f04, f08, f0c, f10;
    u8 b14, pad15;
    s16 h16, h18, h1a, h1c, h1e, h20, h22, h24, h26, h28, h2a, h2c;
    u8 pad2e[0x68 - 0x2e];
    Vec3 cur;
    Vec3 org;
} Ent;

typedef struct Grid {
    u8 pad00[0x1c];
    Vec3 v;
    u8 pad28[0x74 - 0x28];
    Ent e[18][18];
    u8 count;
} Grid;

void func_02206E2C(Grid *p, u16 heap)
{
    int i;
    float a0, b, c, d;
    int q, r;
    float A, z, k;
    Ent *e;

    p->v.x = 0;
    p->v.y = 0;
    p->v.z = 0;
    p->count = 18;
    z = 0.0f;
    k = 5.3333335f;
    A = 2.0220568f;
    a0 = -18.198511f + A / 2.0f;
    b = 18.198511f - A / 2.0f;
    c = z * (A / k);
    d = z * (A / k);
    for (i = 0; i < 324; i++) {
        r = i % 18;
        q = i / 18;
        e = &p->e[q][r];
        e->w00 = 60;
        e->b14 = 31;
        e->h16 = FX_F32_TO_FX32((0.0f - A) / 2.0f - c);
        e->h18 = FX_F32_TO_FX32(A / 2.0f + d);
        e->h1a = 0;
        e->h1c = FX_F32_TO_FX32((0.0f - A) / 2.0f - c);
        e->h1e = FX_F32_TO_FX32((0.0f - A) / 2.0f - d);
        e->h20 = 0;
        e->h22 = FX_F32_TO_FX32(A / 2.0f + c);
        e->h24 = FX_F32_TO_FX32((0.0f - A) / 2.0f - d);
        e->h26 = 0;
        e->h28 = FX_F32_TO_FX32(A / 2.0f + c);
        e->h2a = FX_F32_TO_FX32(A / 2.0f + d);
        e->h2c = 0;
        e->cur = p->v;
        e->cur.x += FX_F32_TO_FX32(a0 + A * (float)r);
        e->cur.y += FX_F32_TO_FX32(b - A * (float)q);
        e->f04 = FX_F32_TO_FX32(16.0f + (float)r * k - z);
        e->f0c = FX_F32_TO_FX32(16.0f + (float)q * k - z);
        e->f08 = e->f04 + FX_F32_TO_FX32(k + 2.0f * z);
        e->f10 = e->f0c + FX_F32_TO_FX32(k + 2.0f * z);
        e->org = e->cur;
    }
}
