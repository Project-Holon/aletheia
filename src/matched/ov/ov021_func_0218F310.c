/*
 * function: func_0218F310
 * address:  0x0218F310
 * packet:   pkt_ov021_0218F310
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clamps a point to a ring sector around the centre at +8/+0xc: radius
 * capped at +0x10, angle clamped to [+0x16, +0x14]; returns 1 when clamped.
 * `const` on a lets the a->cz load schedule above the c.y = 0 store
 * (docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md);
 * the table entry read into an s16 local puts it in r0:r1 of _ll_mul, and
 * `r = 1` repeated in both inner arms gives the cross-jumped clamp blocks.
 *
 * symbols:
 *   VEC_Subtract     0x0207CA00  arm
 *   VEC_Mag          0x0207CBD0  arm
 *   FX_Modf          0x0207D14C  arm
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   _ll_mul          0x0209C054  arm
 *   d_021D3E38       0x021D3E38  data   a4
 *   d_020A1B38       0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { int x, y, z; } V;
typedef struct {
    char pad00[8];
    int cx;
    int cz;
    int rmax;
    u16 amax;
    u16 amin;
} Ring;

extern void VEC_Subtract(V *a, V *b, V *o);
extern int VEC_Mag(V *a);
extern int FX_Modf(int x, int *ip);
extern void VEC_Normalize(V *a, V *o);
extern void VEC_CrossProduct(V *a, V *b, V *o);
extern int VEC_DotProduct(V *a, V *b);
extern u16 FX_AcosIdx(int x);
extern V d_021D3E38;
extern s16 d_020A1B38[];

int func_0218F310(const Ring *a, V *b, V *out)
{
    V k;
    V c;
    V d;
    V e;
    V n;
    V x;
    int m;
    int r;
    u16 ang;
    u16 lo, hi;
    int d1, d2;
    int i;
    s16 s;

    k = d_021D3E38;
    c = *b;
    d = *b;
    out->x = b->x;
    out->y = b->y;
    out->z = b->z;
    e.x = a->cx;
    e.y = 0;
    r = 0;
    c.y = 0;
    e.z = a->cz;
    VEC_Subtract(&c, &e, &n);
    m = VEC_Mag(&n);
    if (FX_Modf(m, &m) > 0) {
        m += 0x1000;
    }
    VEC_Normalize(&n, &n);
    VEC_CrossProduct(&k, &n, &x);
    ang = FX_AcosIdx(VEC_DotProduct(&k, &n));
    if (x.y < 0) {
        ang = 0x10000 - ang;
    }
    if (m > a->rmax) {
        m = a->rmax;
        r = 1;
    }
    lo = a->amin;
    hi = a->amax;
    if (hi != lo) {
        if (hi > lo) {
            if (lo < ang && hi >= ang) {
                d1 = hi - ang;
                if (d1 < 0) d1 = -d1;
                d2 = lo - ang;
                if (d2 < 0) d2 = -d2;
                if (d2 > d1) {
                    ang = hi;
                    r = 1;
                } else {
                    ang = lo;
                    r = 1;
                }
            }
        } else if (hi > ang) {
            ang = hi;
            r = 1;
        } else if (lo < ang) {
            ang = lo;
            r = 1;
        }
    }
    if (r != 0) {
        i = (ang >> 4) * 2;
        s = d_020A1B38[i];
        out->x = e.x + (int)(((long long)s * m + 0x800) >> 12);
        s = d_020A1B38[i + 1];
        out->z = e.z + (int)(((long long)s * m + 0x800) >> 12);
        out->y = d.y;
    }
    return r;
}
