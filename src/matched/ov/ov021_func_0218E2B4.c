/*
 * function: FIELD_CAMERA_CalcOffsetPoint
 * address:  0x0218E2B4
 * packet:   pkt_ov021_0218E2B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a vector from two sin/cos table rows (fx 20.12 products), normalises it and copies it out.
 *
 * symbols:
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_MultAdd  0x0207CEE4  arm
 *   _ll_mul        0x0209C054  arm
 *   FX_SinCosTable_     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */

typedef short s16;
typedef struct { int x, y, z; } V;

extern void VEC_Normalize(V *a, V *b);
extern void VEC_MultAdd(int e, V *v, V *a, V *o);
extern s16 FX_SinCosTable_[];

void FIELD_CAMERA_CalcOffsetPoint(V *a, V *out, int i, int j, int e)
{
    V v;
    int x, y;
    s16 p, q;
    int k;

    k = (i >> 4) * 2;
    x = FX_SinCosTable_[k];
    y = FX_SinCosTable_[k + 1];
    p = FX_SinCosTable_[(j >> 4) * 2];
    q = FX_SinCosTable_[(j >> 4) * 2 + 1];
    if (q < 0) q = -q;
    if (q < 0x200) q = 0x200;
    v.x = (int)(((long long)x * q + 0x800) >> 12);
    v.y = p;
    v.z = (int)(((long long)y * q + 0x800) >> 12);
    VEC_Normalize(&v, &v);
    VEC_MultAdd(e, &v, a, &v);
    *out = v;
}
