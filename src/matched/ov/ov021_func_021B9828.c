/*
 * function: FIELD_RAIL_IntersectSegmentPlane
 * address:  0x021B9828
 * packet:   pkt_ov021_021B9828
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Segment/plane intersection: the plane through c spanned by a and b, the
 * segment from d to e; writes the hit point to out and returns 1.
 * The hit point is computed z, y, x and stored x, y, z: an inline VEC_Set
 * evaluates its arguments last to first
 * (docs/idioms/an-inline-wrappers-arguments-are-evaluated-last-to-first.md).
 *
 * symbols:
 *   VEC_Subtract     0x0207CA00  arm
 *   VEC_Mag          0x0207CBD0  arm
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   FX_Div           0x0207C768  arm
 *   _ll_mul          0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef struct { int x, y, z; } V;

extern void VEC_Subtract(V *a, V *b, V *o);
extern int VEC_Mag(V *a);
extern void VEC_Normalize(V *a, V *o);
extern void VEC_CrossProduct(V *a, V *b, V *o);
extern int FX_Div(int n, int d);

static inline int FX_Mul(int a, int b)
{
    return (int)(((long long)a * b + 0x800LL) >> 12);
}

static inline void VEC_Set(V *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

int FIELD_RAIL_IntersectSegmentPlane(V *a, V *b, V *c, V *d, V *e, V *out)
{
    V n;
    V s;
    V u;
    V v;
    int len;
    int num;
    int den;
    int t;

    VEC_Subtract(e, d, &s);
    len = VEC_Mag(&s);
    VEC_Normalize(&s, &s);
    VEC_Normalize(a, &u);
    VEC_Normalize(b, &v);
    VEC_CrossProduct(&u, &v, &n);
    VEC_Normalize(&n, &n);
    num = (FX_Mul(n.x, c->x) + FX_Mul(n.y, c->y) + FX_Mul(n.z, c->z))
        - (FX_Mul(n.x, d->x) + FX_Mul(n.y, d->y) + FX_Mul(n.z, d->z));
    den = FX_Mul(n.x, s.x) + FX_Mul(n.y, s.y) + FX_Mul(n.z, s.z);
    if (den == 0) {
        return 0;
    }
    t = FX_Div(num, den);
    if (t > len) {
        return 0;
    }
    if (t <= 0x1000) {
        return 0;
    }
    VEC_Set(out, d->x + FX_Mul(s.x, t), d->y + FX_Mul(s.y, t),
            d->z + FX_Mul(s.z, t));
    return 1;
}
