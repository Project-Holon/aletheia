/*
 * file:     shinka_demo_view_p10.c
 * unit:     yes
 * function: func_02206E2C, func_02207510
 * address:  0x02206E2C
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 */
#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))
#define REG_MTX_PUSH       (*(vu32 *)0x04000444)
#define REG_MTX_POP        (*(vu32 *)0x04000448)
#define REG_MTX_TRANS      (*(vu32 *)0x04000470)
#define REG_NORMAL         (*(vu32 *)0x04000484)
#define REG_TEXCOORD       (*(vu32 *)0x04000488)
#define REG_VTX_16         (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR   (*(vu32 *)0x040004A4)
#define REG_TEXIMAGE_PARAM (*(vu32 *)0x040004A8)
#define REG_TEXPLTT_BASE   (*(vu32 *)0x040004AC)
#define REG_BEGIN_VTXS     (*(vu32 *)0x04000500)
#define REG_END_VTXS       (*(vu32 *)0x04000504)
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef s32 fx32;

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

typedef struct Grid_02206E2C {
    u8 pad00[0x1c];
    Vec3 v;
    u8 pad28[0x74 - 0x28];
    Ent e[18][18];
    u8 count;
} Grid_02206E2C;

typedef s16 fx16;

typedef volatile u32 vu32;

typedef struct Cell {
    u32 f00;
    fx32 s0, s1, t0, t1;
    u8 visible;
    u8 pad15;
    fx16 v[4][3];
    u8 pad2e[0x68 - 0x2e];
    fx32 tx, ty, tz;
    u8 pad74[0x80 - 0x74];
} Cell;

typedef struct Row {
    Cell cell[0x12];
} Row;

typedef struct Grid_02207510 {
    u8 pad00[0x14];
    u32 tex;
    u32 pltt;
    fx32 x, y, z;
    u8 pad28[0x74 - 0x28];
    Row row[0x12];
    u8 rows;
} Grid_02207510;

void func_02206E2C(Grid_02206E2C *p, u16 heap);
void func_02207510(Grid_02207510 *w, u16 heap);


/*
 * Builds a 18 x 18 grid of 0x80-byte entries: each gets two rounded fx32
 * corner sets, a position (cur) and its copy (org). The 0.0f offsets and the
 * 16/3 step are locals (z, k): the compiler propagates them only after folding,
 * so `z * (A / k)` stays a _fmul and `(float)r * k` keeps k as the second operand.
 */
void func_02206E2C(Grid_02206E2C *p, u16 heap)
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


static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}


static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}


static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}


/*
 * Grid of textured quads, rows of 0x12 cells of 0x80 bytes, one push /
 * translate / quad / pop per visible cell.
 */
void func_02207510(Grid_02207510 *w, u16 heap)
{
    int j;
    int i;
    Cell *c;

    REG_TEXIMAGE_PARAM = (w->tex >> 3) | 0x6E430000;
    REG_TEXPLTT_BASE = w->pltt >> 4;
    j = 0;
    REG_MTX_PUSH = j;
    G3_Translate(w->x, w->y, w->z);
    REG_POLYGON_ATTR = 0x001F0080;
    for (; j < w->rows; j++) {
        for (i = 0; i < 0x12; i++) {
            c = &w->row[j].cell[i];
            if (c->visible != 0) {
                REG_MTX_PUSH = 0;
                G3_Translate(c->tx, c->ty, c->tz);
                REG_BEGIN_VTXS = 1;
                REG_NORMAL = 0x20000000;
                G3_TexCoord(c->s0, c->t0);
                G3_Vtx(c->v[0][0], c->v[0][1], c->v[0][2]);
                G3_TexCoord(c->s0, c->t1);
                G3_Vtx(c->v[1][0], c->v[1][1], c->v[1][2]);
                G3_TexCoord(c->s1, c->t1);
                G3_Vtx(c->v[2][0], c->v[2][1], c->v[2][2]);
                G3_TexCoord(c->s1, c->t0);
                G3_Vtx(c->v[3][0], c->v[3][1], c->v[3][2]);
                REG_END_VTXS = 0;
                REG_MTX_POP = 1;
            }
        }
    }
    REG_MTX_POP = 1;
}
