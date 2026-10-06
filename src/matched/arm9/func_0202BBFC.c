/*
 * unit:     no
 * function: func_0202BBFC
 * address:  0x0202BBFC
 * packet:   pkt_0202BB68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Distance falloff: the vector at +4 of the record is taken relative to
 * the caller's point, and the remaining headroom (the radius at +0x10
 * less that distance) is divided by the radius through the hardware
 * divider sub_0207C768.  The quotient is an FX32, so it is scaled back
 * by 4096.0f in float before multiplying the amplitude at +0x14 and
 * truncating; that is the pool word 0x45800000 at 0x0202BC44.
 * Outside the radius the answer is 0.
 *
 * The compare is signed (bge), so the radius field is s32 and the
 * `mag >= radius` arm is the one written first.
 *
 * symbols:
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   sub_0207C768   0x0207C768  arm
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 */

typedef signed int s32;

struct Vec { s32 x, y, z; };

struct Rec {
    s32 pad0;
    struct Vec pos;
    s32 radius;
    s32 amp;
};

extern void VEC_Subtract(const struct Vec *a, const struct Vec *b,
                         struct Vec *out);
extern s32  VEC_Mag(const struct Vec *v);
typedef unsigned int   u32;
extern u32 sub_0207C768(u32 a, u32 b);

s32 func_0202BBFC(struct Rec *r, const struct Vec *p)
{
    struct Vec d;
    s32 mag;
    float q;

    VEC_Subtract(&r->pos, p, &d);
    mag = VEC_Mag(&d);
    if (r->radius < mag) {
        return 0;
    }
    q = (float)(s32)sub_0207C768((s32)(r->radius - mag), (s32)r->radius) / 4096.0f;
    return (s32)((float)r->amp * q);
}
