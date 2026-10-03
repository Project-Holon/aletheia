/*
 * function: func_021D14C4
 * address:  0x021D14C4
 * packet:   pkt_ov021_021D14C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The a/0/0/8 grid tile reader (see docs/notes/func_021D14C4_tile_record_reader.c.txt):
 * picks the tile under pos, writes its surface normal, attribute word and
 * solved height into out[idx].
 *
 * Shape notes, each one measured:
 * - the normal table is read through an s16 pointer cast of a differently
 *   typed object, so mwcc cannot prove it disjoint from out: the setter's
 *   right-to-left arguments then stay as z, y, x temporaries (y spilled) and
 *   the pool word is reloaded per access. A plain s16 array sinks the loads.
 * - the height table is const (its load is scheduled above the z store).
 * - the tile record is read through a volatile pointer: the image reloads
 *   the norm halfword after the type test instead of reusing the type load;
 *   no non-volatile spelling (casts, unions, other access paths, const)
 *   stopped mwcc from CSE-ing the two halfword loads.
 * - the row index is x/0x10000 + w * (z/0x10000) in that operand order;
 *   p (= &out[idx]) is live into the tail, where only the x read uses it.
 *
 * symbols:
 *   d_021DB9A0     0x021DB9A0  data
 *   d_021DC158     0x021DC158  data
 *   _ll_mul        0x0209C054  arm
 *   func_0207C768  0x0207C768  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int fx32;
typedef long long s64;

typedef struct VecFx32_021D14C4 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32_021D14C4;

/* s16 (x, y, z) normal triples */
typedef struct Norm021D14C4 {
    s16 x;
    s16 y;
    s16 z;
} Norm021D14C4;

typedef struct Tile021D14C4 {
    u16 type : 2;
    u16 norm : 14;
    u16 d;
    u32 attr : 31;
    u32 flag : 1;
} Tile021D14C4;

typedef struct Sub021D14C4 {
    u16 type : 2;
    u16 norm0 : 14;
    u16 norm1;
    u16 d0;
    u16 d1;
} Sub021D14C4;

typedef struct Map021D14C4 {
    u16 w;
    u16 h;
    Tile021D14C4 tiles[1];
} Map021D14C4;

typedef struct Plane021D14C4 {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
    u32 attr;
    fx32 height;
} Plane021D14C4;

extern u32 func_0207C768(u32 a, u32 b);
extern Norm021D14C4 d_021DB9A0[];
#define NRM(i) ((s16 *)d_021DB9A0)[i]
extern const fx32 d_021DC158[];

static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

static inline void VecSet021D14C4(Plane021D14C4 *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}

void func_021D14C4(Plane021D14C4 *out, int idx, Map021D14C4 *map, VecFx32_021D14C4 *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int lx = x % 0x10000;
    int lz = z % 0x10000;
    int i = x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000);
    volatile Tile021D14C4 *t = &map->tiles[i];
    fx32 d;
    Plane021D14C4 *p;
    u8 type = t->type;

    if (type == 0) {
        int n = t->norm * 3;
        int di = t->d;
        VecSet021D14C4(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else if (type == 2) {
        Sub021D14C4 *s = (Sub021D14C4 *)(map->tiles + map->w * map->h) + t->d;
        int n;
        int di;
        if (t->flag == 0) {
            if (lx + lz < 0x10000) {
                n = s->norm0 * 3;
                di = s->d0;
            } else {
                n = s->norm1 * 3;
                di = s->d1;
            }
        } else {
            if (lx > lz) {
                n = s->norm0 * 3;
                di = s->d0;
            } else {
                n = s->norm1 * 3;
                di = s->d1;
            }
        }
        VecSet021D14C4(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else {
        VecSet021D14C4(p = &out[idx], 0, 0x1000, 0);
        d = 0;
    }
    {
        fx32 ny = out[idx].y;
        fx32 mz = FX_MUL(out[idx].z, pos->z);
        fx32 mx = FX_MUL(p->x, pos->x);
        out[idx].attr = t->attr;
        out[idx].height = base + func_0207C768(-(d + (mx + mz)), ny);
    }
}
