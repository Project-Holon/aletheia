/*
 * function: FIELD_RAIL_ProjectOnSegment
 * address:  0x021BAE7C
 * packet:   pkt_ov021_021BAE7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: 406 bytes compiled against a 408-byte extent (trailing pad).
 * The result vector is written through the SDK's inline VEC_Set, whose
 * arguments are evaluated z, y, x before the three stores.
 *
 * symbols:
 *   VEC_Subtract      0x0207CA00  arm
 *   VEC_Normalize     0x0207CCA4  arm
 *   VEC_Mag           0x0207CBD0  arm
 *   FX_Div            0x0207C768  arm
 *   VEC_DotProduct    0x0207CA68  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_Add           0x0207C9D0  arm
 *   VEC_Distance      0x0207CF3C  arm
 *   _ll_mul           0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef int fx32;
typedef long long fx64;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    u8 pad[0x30];
    VecFx32 pos;
} Obj;

extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern fx32 VEC_Mag(const VecFx32 *v);
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern fx32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

static inline void VEC_Set(VecFx32 *v, fx32 x, fx32 y, fx32 z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

int FIELD_RAIL_ProjectOnSegment(Obj *a, Obj *b, VecFx32 *c, VecFx32 *out, fx32 *t, VecFx32 *axis)
{
    VecFx32 d1;
    VecFx32 d2;
    VecFx32 d1n;
    VecFx32 n1;
    VecFx32 n2;
    fx32 len1;
    fx32 len2;
    fx32 inv;
    fx32 s;
    fx32 dy;

    VEC_Subtract(&a->pos, &b->pos, &d1);
    VEC_Subtract(c, &b->pos, &d2);
    VEC_Normalize(&d1, &d1n);
    len1 = VEC_Mag(&d1);
    d1 = d1n;
    len2 = VEC_Mag(&d2);
    VEC_Normalize(&d2, &d2);
    inv = FX_Div(len2, len1);
    d2.x = FX_MUL(d2.x, inv);
    d2.y = FX_MUL(d2.y, inv);
    d2.z = FX_MUL(d2.z, inv);
    *t = VEC_DotProduct(&d1, &d2);
    if (*t > 0x1000) {
        return 0;
    }
    if (*t < 0) {
        return 0;
    }
    *t = FX_MUL(*t, len1);
    VEC_Normalize(&d1, &n1);
    VEC_Normalize(&d2, &n2);
    VEC_CrossProduct(&n1, &n2, axis);
    s = *t;
    VEC_Set(out, FX_MUL(d1n.x, s), FX_MUL(d1n.y, s), FX_MUL(d1n.z, s));
    VEC_Add(&b->pos, out, out);
    if (VEC_Distance(c, out) >= 0x100000) {
        return 0;
    }
    dy = c->y - out->y;
    if (dy < 0) {
        dy = -dy;
    }
    if (dy > 0x8000) {
        return 0;
    }
    return 1;
}
