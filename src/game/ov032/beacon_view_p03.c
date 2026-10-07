/*
 * file:     beacon_view_p03.c
 * unit:     yes
 * function: func_021F096C, func_021F0A18
 * address:  0x021F096C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F089C  0x021F089C  thumb  ov032
 *   d_021F356C     0x021F356C  data  a4
 *   d_021F3538     0x021F3538  data  a1
 *   func_0204B898  0x0204B898  arm
 *   func_02035D40  0x02035D40  arm
 *   func_021F0DD8  0x021F0DD8  thumb  ov032
 *   d_021F3530     0x021F3530  data  a2
 */
struct Obj;
struct Ctx;
typedef unsigned char u8;

typedef struct { int x, y; } Vec2;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021F089C(void *pt, int *tri);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
extern void func_021F0DD8(u32 v);
int func_021F096C(u8 *p, void *pt);
int func_021F0A18(u8 *p, u32 *v);
extern Vec2 d_021F356C[2][5];
extern u8 d_021F3538[][3];
extern u16 d_021F3530[];


/*
 * Tries the point against the triangles of two fixed 5-vertex fans (byte
 * index triples in d_021F3538); returns 1 - j for the fan that hits, else -1.
 * Copying the vertices as Vec2 structs gives the x-then-y load order; the
 * `k = 0` ahead of the fan pointer keeps `movs r4, #0` first.
 */
int func_021F096C(u8 *p, void *pt)
{
    int flags;
    int j;
    int k;
    Vec2 t[3];

    flags = 0;
    if (p[0x7c] != 0)
        flags |= 1;
    if (p[0x7c] + p[0x7d] < p[0x7b])
        flags |= 2;
    for (j = 0; j < 2; j++) {
        if (flags & (j + 1)) {
            Vec2 *v;
            k = 0;
            v = d_021F356C[j];
            for (; k < 3; k++) {
                t[0] = v[d_021F3538[k][0]];
                t[1] = v[d_021F3538[k][1]];
                t[2] = v[d_021F3538[k][2]];
                if (func_021F089C(pt, (int *)t))
                    return 1 - j;
            }
        }
    }
    return -1;
}


int func_021F0A18(u8 *p, u32 *v)
{
    u8 b[5];
    int i;

    b[4] = 0xff;
    for (i = 0; i < 4; i++) {
        u32 a = func_0204B898((struct Obj *)(*(u32 *)(p + 0x2bc + i * 4)));
        if ((u8)(a - (i * 3 + 1)) % 3 < 2) {
            b[0] = 0xac;
            b[1] = b[0] + 0x18;
            b[2] = i * 32 + 0x84;
            b[3] = b[2] + 0x18;
            if (func_02035D40((struct Ctx *)b, v[0], v[1]) != -1) {
                func_021F0DD8(d_021F3530[i]);
                return i;
            }
        }
    }
    return -1;
}
