/*
 * function: func_021F096C
 * address:  0x021F096C
 * packet:   pkt_ov032_021F096C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tries the point against the triangles of two fixed 5-vertex fans (byte
 * index triples in d_021F3538); returns 1 - j for the fan that hits, else -1.
 * Copying the vertices as Vec2 structs gives the x-then-y load order; the
 * `k = 0` ahead of the fan pointer keeps `movs r4, #0` first.
 *
 * symbols:
 *   func_021F089C  0x021F089C  thumb  ov032
 *   d_021F356C     0x021F356C  data  a4
 *   d_021F3538     0x021F3538  data  a1
 */

typedef unsigned char u8;

typedef struct { int x, y; } Vec2;

extern int func_021F089C(void *pt, int *tri);
extern Vec2 d_021F356C[2][5];
extern u8 d_021F3538[][3];

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
