/*
 * function: FIELD_RAIL_SlerpDir
 * address:  0x021B9A50
 * packet:   pkt_ov021_021B9A50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spherical interpolation between the directions a and b at t: the two
 * normalised inputs weighted by sin((1-t)w)/sin(w) and sin(tw)/sin(w),
 * summed and normalised into out; b's direction when sin(w) is 0.
 * The rounding term is `FX32_ONE >> 1` added to an s64: the image keeps it
 * unfolded (movs #1 / lsls #0xc / lsrs #1), where `0x800LL` folds to
 * movs #2 / lsls #0xa. The table reads are ldrh, so the table is u16 here.
 *
 * symbols:
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   FX_Div           0x0207C768  arm
 *   VEC_Add          0x0207C9D0  arm
 *   BUTTON_MAN_ScaleVec    0x020520A4  arm
 *   _ll_mul          0x0209C054  arm
 *   FX_SinCosTable_       0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef struct { int x, y, z; } V;

extern void VEC_Normalize(V *a, V *o);
extern int VEC_DotProduct(V *a, V *b);
extern u16 FX_AcosIdx(int x);
extern int FX_Div(int n, int d);
extern void VEC_Add(V *a, V *b, V *o);
struct Vec3;
extern void BUTTON_MAN_ScaleVec(const struct Vec3 *v, int s, struct Vec3 *dst);
extern u16 FX_SinCosTable_[];

#define FX32_ONE ((int)0x00001000L)

static inline int FX_Mul(int a, int b)
{
    return (int)(((long long)a * b + (FX32_ONE >> 1)) >> 12);
}

void FIELD_RAIL_SlerpDir(V *out, V *a, V *b, int t)
{
    V na;
    V nb;
    u16 w;
    int s;
    int aw;

    VEC_Normalize(a, &na);
    VEC_Normalize(b, &nb);
    w = FX_AcosIdx(VEC_DotProduct(&na, &nb));
    s = FX_SinCosTable_[(w >> 4) * 2];
    if (s == 0) {
        *out = nb;
        return;
    }
    aw = w << 12;
    BUTTON_MAN_ScaleVec((const struct Vec3 *)(&na), FX_Div(FX_SinCosTable_[(FX_Mul(aw, FX32_ONE - t) >> 16) * 2], s), (struct Vec3 *)(&na));
    BUTTON_MAN_ScaleVec((const struct Vec3 *)(&nb), FX_Div(FX_SinCosTable_[(FX_Mul(aw, t) >> 16) * 2], s), (struct Vec3 *)(&nb));
    VEC_Add(&na, &nb, out);
    VEC_Normalize(out, out);
}
