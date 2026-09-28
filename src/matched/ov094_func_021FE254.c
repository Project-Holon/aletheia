/*
 * function: func_021FE254
 * address:  0x021FE254
 * packet:   pkt_ov094_021FE254
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _ll_mul  0x0209C054  arm
 */
typedef int fx32;
typedef long long fx64;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[4][4]; } MtxFx44;

void func_021FE254(const VecFx32 *v, const MtxFx44 *m, fx32 *out, fx32 *w)
{
    fx64 y = v->y;
    fx64 x = v->x;
    fx64 z = v->z;
    fx64 t;

    t = z * m->m[2][0] + (x * m->m[0][0] + y * m->m[1][0]);
    out[0] = (fx32)(t >> 12) + m->m[3][0];
    t = z * m->m[2][1] + (x * m->m[0][1] + y * m->m[1][1]);
    out[1] = (fx32)(t >> 12) + m->m[3][1];
    t = z * m->m[2][2] + (x * m->m[0][2] + y * m->m[1][2]);
    out[2] = (fx32)(t >> 12) + m->m[3][2];
    t = z * m->m[2][3] + (x * m->m[0][3] + y * m->m[1][3]);
    *w = (fx32)(t >> 12) + m->m[3][3];
}
