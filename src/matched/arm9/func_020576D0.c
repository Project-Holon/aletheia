/*
 * function: func_020576D0
 * address:  0x020576D0
 * packet:   pkt_02056460
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   VEC_Fx16CrossProduct   0x0207CB68  arm
 *   VEC_Fx16Normalize   0x0207CDB8  arm
 *
 * out = M * src for a rig matrix M whose two 3x2 s16 rows live at m+0x84 and
 * m+0x8a; the third row is their cross product, normalised in place:
 *
 *     VEC_CrossProduct((VEC16 *)(m+0x84), (VEC16 *)(m+0x8a), &v);
 *     VEC_Fx16Normalize(&v, &v);        <-- TWO arguments, both the same
 *     out[0..2] = FX_Mul(src->x, m->r0[k]) + FX_Mul(src->y, m->r1[k])
 *               + FX_Mul(src->z, v[k]);
 *
 * 0x0207CB68 is the 104-byte cross product (six smulbb / sub / +0x800 / asr
 * #12 quartets), 0x0207CDB8 the 300-byte Fx16 normaliser (reads r0, writes a
 * global through a pooled pointer).  The normaliser's own body never reads
 * r1, but the CALLER must still materialise it: `add r0, sp, #0` followed by
 * `mov r1, r0` is in the image at 0x020576D4+0x24/+0x28, so the call in the
 * original source passes the vector twice.  Omitting the second argument
 * costs exactly those 4 bytes (348 vs 352) and shifts every later
 * instruction, so it reads as a whole-body register-plan diff; it is the
 * one thing to get right on this row.
 *
 * The `mov ip, #0x800` register-form rounding constant feeding `adds` is the
 * 1.2 constant-materialisation tell (docs/FRONTEND-PINS.md), and the pin is
 * the family pin for 0x0205429C..0x020584E0.  -proc arm946e is MEASURED for
 * this row, not quoted from layout/proc_hints.txt (which calls the packet
 * arm7tdmi): at arm7tdmi the frame is not this one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020576D0.c \
 *       --func func_020576D0 --addr 0x020576D0 --arm --cc ../1.2/sp2
 */

typedef int          fx32;
typedef long long    fx64;
typedef short        s16;
typedef unsigned char u8;

struct Vec16  { s16 x, y, z; };
struct VecFx32 { fx32 x, y, z; };

struct Mtx3 {
    u8  pad[0x84];
    s16 r0[3];
    s16 r1[3];
};

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((fx64)a * b + 0x800) >> 12);
}

extern void VEC_Fx16CrossProduct(const struct Vec16 *a, const struct Vec16 *b, struct Vec16 *out);
extern void VEC_Fx16Normalize(struct Vec16 *v, struct Vec16 *w);

void func_020576D0(fx32 *out, const struct VecFx32 *src, const struct Mtx3 *m)
{
    struct Vec16 v;

    VEC_Fx16CrossProduct((const struct Vec16 *)(m->pad + 0x84),
                  (const struct Vec16 *)(m->pad + 0x8a), &v);
    VEC_Fx16Normalize(&v, &v);

    out[0] = FX_Mul(src->x, m->r0[0]) + FX_Mul(src->y, m->r1[0]) + FX_Mul(src->z, v.x);
    out[1] = FX_Mul(src->x, m->r0[1]) + FX_Mul(src->y, m->r1[1]) + FX_Mul(src->z, v.y);
    out[2] = FX_Mul(src->x, m->r0[2]) + FX_Mul(src->y, m->r1[2]) + FX_Mul(src->z, v.z);
}
