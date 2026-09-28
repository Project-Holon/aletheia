/*
 * function: func_021FE1B8
 * address:  0x021FE1B8
 * packet:   pkt_ov094_021FE1B8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   FX_Div           0x0207C768  arm
 *   _ll_mul          0x0209C054  arm
 *   g_02148B98       0x02148B98  data
 *   g_02148B54       0x02148B54  data
 *   func_021FE254    0x021FE254  thumb
 */
typedef int fx32;
typedef long long fx64;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[4][3]; } MtxFx43;
typedef struct { fx32 m[4][4]; } MtxFx44;

extern MtxFx43 g_02148B98;
extern MtxFx44 g_02148B54;

void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);
void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
fx32 FX_Div(fx32 numer, fx32 denom);
void func_021FE254(const VecFx32 *v, const MtxFx44 *m, VecFx32 *out, fx32 *w);

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

void func_021FE1B8(VecFx32 *v, const VecFx32 *ofs)
{
    fx32 w;
    MtxFx44 m;

    MTX_Copy43To44_(&g_02148B98, &m);
    MTX_Concat44(&m, &g_02148B54, &m);
    if (ofs != 0) {
        v->x += ofs->x;
        v->y += ofs->y;
        v->z += ofs->z;
    }
    func_021FE254(v, &m, v, &w);
    v->x = FX_MUL(FX_Div(v->x, w), 0x4000);
    v->y = FX_MUL(FX_Div(v->y, w), 0x3000);
    v->z = -v->z;
}
