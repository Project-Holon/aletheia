/*
 * function: func_02193790
 * address:  0x02193790
 * packet:   pkt_ov021_02193790
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _ll_mul        0x0209C054  arm
 *   func_0207C768  0x0207C768  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int fx32;
typedef long long s64;

typedef struct Vec {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

typedef struct Tile {
    s16 n0[3];
    s16 n1[3];
    fx32 d0;
    fx32 d1;
    u32 attr : 31;
    u32 flag : 1;
} Tile;

typedef struct Plane {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
    u32 attr;
    fx32 height;
    int w[0x3C];
    int valid;
} Plane;

extern u32 func_0207C768(u32 a, u32 b);

static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

static inline void VecSet(Plane *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}

void func_02193790(Plane *out, const int *map, Vec *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int lx = x % 0x10000;
    int lz = z % 0x10000;
    Tile *t = (Tile *)((char *)map + map[2] + 4) + (x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000));
    fx32 d;

    if (t->flag == 0) {
        if (lx + lz < 0x10000) {
            VecSet(out, t->n0[0], t->n0[1], -t->n0[2]);
            d = t->d0;
        } else {
            VecSet(out, t->n1[0], t->n1[1], -t->n1[2]);
            d = t->d1;
        }
    } else {
        if (lx > lz) {
            VecSet(out, t->n0[0], t->n0[1], -t->n0[2]);
            d = t->d0;
        } else {
            VecSet(out, t->n1[0], t->n1[1], -t->n1[2]);
            d = t->d1;
        }
    }
    {
        fx32 ny = out->y;
        fx32 mz = FX_MUL(out->z, pos->z);
        fx32 mx = FX_MUL(out->x, pos->x);
        out->attr = t->attr;
        out->height = base + func_0207C768(-(d + (mx + mz)), ny);
    }
    out->valid = 1;
}
