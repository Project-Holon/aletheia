/*
 * function: func_02051F34
 * address:  0x02051F34
 * packet:   pkt_02051E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   VEC_Subtract    0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   VEC_Mag         0x0207CBD0  arm
 *   VEC_Normalize   0x0207CCA4  arm
 *   FX_Div          0x0207C768  arm
 *   func_020520A4   0x020520A4  arm
 *
 * Segment-versus-sphere test: project the ball's centre onto the segment
 * p0 -> dir (t = FX_Div(dot(d, c - p0), dot(d, d)), d = dir - p0); on the
 * segment compare the distance against b->r + seg->pad18, off it compare the
 * distance to the far end and then to p0 against b->r.  Fills a 20-byte
 * { hit, normal, dist } block copied to *out when out is non-null; returns hit.
 * Compiler pin dsi/1.1p1 (a PART 1 math helper of cluster_02051E64).
 *
 * What closed it (wave 9, from the wave-7 note's 72-byte point): the distance
 * is a register local `d` compared at the shared join, and res.d is stored
 * AFTER the limit is loaded (`d = VEC_Mag(..); lim = ..; res.d = d;`).
 * Comparing res.d itself reloads it from the stack at the join.
 */

typedef unsigned int u32;

struct Vec3 { int x; int y; int z; };

struct Seg {
    struct Vec3 p0;   /* 0x00 */
    struct Vec3 dir;  /* 0x0c */
    u32 pad18;
};

struct Ball {
    struct Vec3 c;    /* 0x00 */
    int r;            /* 0x0c */
};

struct Out {
    u32 hit;          /* 0x00 */
    struct Vec3 n;    /* 0x04 */
    int d;            /* 0x10 */
};

extern void VEC_Subtract(const struct Vec3 *a, const struct Vec3 *b, struct Vec3 *d);
extern int  VEC_DotProduct(const struct Vec3 *a, const struct Vec3 *b);
extern int  VEC_Mag(const struct Vec3 *v);
extern void VEC_Normalize(const struct Vec3 *v, struct Vec3 *d);
extern int  FX_Div(int a, int b);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *d);

u32 func_02051F34(struct Seg *seg, struct Ball *b, struct Out *out)
{
    struct Out  res;    /* sp+0x24: res.hit, n, d -- copied out as one block */
    struct Vec3 sd;     /* sp+0x18 */
    struct Vec3 bc;     /* sp+0x0c */
    struct Vec3 tmp;    /* sp+0x00 */
    int t;
    int d;
    int lim;

    res.hit = 0;
    VEC_Subtract(&seg->dir, &seg->p0, &sd);
    VEC_Subtract(&b->c, &seg->p0, &bc);

    t = FX_Div(VEC_DotProduct(&sd, &bc), VEC_DotProduct(&sd, &sd));
    if (t >= 0 && t <= 0x1000) {
        func_020520A4(&sd, t, &sd);
        VEC_Subtract(&sd, &bc, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r + seg->pad18;
        res.d = d;
    } else {
        VEC_Subtract(&b->c, &seg->dir, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
        if (d <= lim) {
            res.hit = 1;
            goto done;
        }
        tmp = bc;
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
    }
    if (d <= lim)
        res.hit = 1;
done:
    if (out != 0) {
        VEC_Normalize(&tmp, &res.n);
        *out = res;
    }
    return res.hit;
}
