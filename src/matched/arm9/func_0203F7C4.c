/*
 * function: GF_STANDARD_SignedDistanceToLine
 * address:  0x0203F7C4
 * packet:   pkt_0203F7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   VEC_Subtract    0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   VEC_Normalize   0x0207CCA4  arm
 *
 * gf_standard.c: signed distance from point C to the line through A and B,
 * six plain-integer coordinates shifted into 20.12 on entry
 * (docs/families/gf_standard.h).  Closed from the 304-byte / 55-out source
 * of docs/notes/GF_STANDARD_SignedDistanceToLine.c.txt by one change: the value tested for the
 * sign is the SUM OF ALL THREE COMPONENTS of f = (0, 0, cross_z),
 *     cross = f.x + f.y + f.z;
 * not `f.z + a.z`.  The image's `add r2, r7, #0` is f.x + f.y (the zero
 * forwarded from the two stores), started early in the gap between the two
 * FX_Mul-style products, which is what interleaves the second product's
 * loads with the first one's normalisation.  The two `static inline`
 * helpers from the note are still load-bearing.
 */
typedef signed int   s32;
typedef signed long long s64;
typedef s32 fx32;

struct VecFx32 { fx32 x; fx32 y; fx32 z; };

extern void VEC_Subtract(const struct VecFx32 *a, const struct VecFx32 *b,
                         struct VecFx32 *out);
extern void VEC_Normalize(const struct VecFx32 *a, struct VecFx32 *out);
extern fx32 VEC_DotProduct(const struct VecFx32 *a, const struct VecFx32 *b);

static inline fx32 mulfx(fx32 p, fx32 q)
{
    return (fx32)(((s64)p * q + 0x800) >> 12);
}

static inline fx32 cross2(const struct VecFx32 *p, const struct VecFx32 *q)
{
    fx32 px = p->x;
    fx32 py = p->y;

    return mulfx(px, q->y) - mulfx(q->x, py);
}

s32 GF_STANDARD_SignedDistanceToLine(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy)
{
    struct VecFx32 a;
    struct VecFx32 b;
    struct VecFx32 d;
    struct VecFx32 f;
    struct VecFx32 c;
    fx32 cross;
    fx32 dist;
    s32  sign;

    a.x = ax << 12;  a.y = ay << 12;  a.z = 0;
    b.x = bx << 12;  b.y = by << 12;  b.z = 0;
    c.x = cx << 12;  c.y = cy << 12;  c.z = 0;

    VEC_Subtract(&a, &c, &a);
    VEC_Subtract(&b, &c, &b);

    f.x = 0;
    d.x = a.y;
    f.y = 0;
    d.y = a.x;
    d.z = 0;

    f.z = cross2(&a, &b);
    cross = f.x + f.y + f.z;

    VEC_Normalize(&d, &d);
    VEC_Subtract(&b, &a, &f);
    dist = VEC_DotProduct(&d, &f) >> 12;
    if (dist < 0) {
        dist = -dist;
    }
    if (cross <= 0) {
        sign = -1;
        dist = dist * sign;
    }
    return dist;
}
