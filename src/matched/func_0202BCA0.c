/*
 * unit:     no
 * function: func_0202BCA0
 * address:  0x0202BCA0
 * packet:   pkt_0202BCA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * status:   EXACT
 *
 * symbols:
 *   VEC_Subtract      0x0207CA00  arm
 *   VEC_Normalize     0x0207CCA4  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_DotProduct    0x0207CA68  arm
 *   _ll_mul           0x0209C054  arm
 *   _fflt             0x0209BDBC  arm
 *   _fdiv             0x0209CE10  arm
 *   _fmul             0x0209C77C  arm
 *   _ffix             0x0209C494  arm
 *
 * Signed pan, -0x80..0x7f, for a point heard from a listener: build the
 * listener's right-hand axis by crossing its forward vector with world up
 * (and normalising twice, which is what the doubled VEC_Normalize pair is),
 * then project the listener-to-source direction onto it.  The three
 * _ll_mul + shift-by-12 triples are FX_Mul in its open form, scaling the
 * normalised axis by the source distance.
 *
 * The two vector arguments arrive as pointers and are copied into locals
 * before use; the ldm/stm pairs at the top are those copies, not aliasing
 * work (see docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * The 4096.0f divisor is the pool word 0x45800000 at 0x0202BDCC; 0x43000000
 * is 128.0f, materialised as movs #0x43 / lsls #0x18 rather than pooled.
 */

typedef signed int   s32;
typedef signed long long s64;

struct Vec { s32 x, y, z; };

struct Listener {
    s32 pad00;
    struct Vec fwd;
};

extern void VEC_Subtract(const struct Vec *a, const struct Vec *b,
                         struct Vec *out);
extern void VEC_Normalize(const struct Vec *v, struct Vec *out);
extern void VEC_CrossProduct(const struct Vec *a, const struct Vec *b,
                             struct Vec *out);
extern s32  VEC_DotProduct(const struct Vec *a, const struct Vec *b);

s32 func_0202BCA0(const struct Listener *l, const struct Vec *ps,
                  const struct Vec *pp)
{
    struct Vec d;
    struct Vec rel;
    struct Vec sv2;
    struct Vec up;
    struct Vec sv;
    struct Vec axis;
    struct Vec scaled;
    struct Vec n;
    struct Vec src;
    struct Vec pos;
    struct Vec fwd;
    s32 dist;
    s32 pan;

    src = *ps;
    pos = *pp;
    fwd = l->fwd;
    VEC_Subtract(&pos, &src, &d);
    VEC_Subtract(&fwd, &src, &rel);

    up.x = 0;
    up.y = 0x1000;
    up.z = 0;
    VEC_Normalize(&d, &n);
    VEC_CrossProduct(&n, &up, &axis);
    VEC_Normalize(&axis, &axis);
    VEC_CrossProduct(&axis, &n, &scaled);
    VEC_Normalize(&scaled, &scaled);
    VEC_Normalize(&scaled, &scaled);

    dist = VEC_DotProduct(&rel, &scaled);
    sv.x = (s32)(((s64)scaled.x * dist + 0x800) >> 12);
    sv.y = (s32)(((s64)scaled.y * dist + 0x800) >> 12);
    sv.z = (s32)(((s64)scaled.z * dist + 0x800) >> 12);

    VEC_Subtract(&rel, &sv, &sv2);
    VEC_Normalize(&sv2, &sv2);
    pan = (s32)((float)VEC_DotProduct(&axis, &sv2) / 4096.0f * 128.0f);
    if (pan < -0x80) {
        pan = -0x80;
    }
    if (pan > 0x7f) {
        pan = 0x7f;
    }
    return pan;
}
