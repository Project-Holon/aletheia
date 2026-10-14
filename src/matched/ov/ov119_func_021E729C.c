/*
 * function: POKETRADE_2D_StepBezierCurve
 * address:  0x021E729C
 * packet:   pkt_ov119_021E729C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One step of a 20.12 fixed-point cubic Bezier: with t = idx / count the
 * four weights s^3, 3*t*s^2, 3*t^2*s, t^3 are built once, then applied to
 * the four control points p[0..3] to produce out.  When idx reaches
 * count-1 the result is p[3] and the return is 1; otherwise idx advances
 * and the return is 0.  (The struct is out, p[4], idx, count.)
 *
 * Lever (3 bytes out): the left operand of the widening multiply in
 * FX_MUL is an rvalue (3 * t), so left inline the compiler commutes it
 * into the second _ll_mul slot and computes it in the low registers;
 * binding 3*t / 3*t2 to a named local first pins it to the accumulator
 * register, which is the only difference from the original.  This is the
 * arithmetic instance of
 * docs/idioms/commutative-operand-order-names-the-temporary.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKETRADE_2D_StepBezierCurve.c \
 *       --func POKETRADE_2D_StepBezierCurve --addr 0x021E729C --cc dsi/1.1p1 \
 *       --thumb --region ov119 --flags=-O4,p
 *
 * symbols:
 *   FX_Div   0x0207C768  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 */

typedef signed char        s8;
typedef unsigned char      u8;
typedef signed short       s16;
typedef unsigned short     u16;
typedef signed int         s32;
typedef unsigned int       u32;
typedef signed long long   s64;

typedef s32 fx32;
typedef s64 fx64;

typedef struct { fx32 x, y, z; } VecFx32;

struct Curve {
    VecFx32 out;
    VecFx32 p[4];
    s32 idx;
    s32 count;
};

#define FX32_ONE 4096
#define FX_MUL(v1, v2) ((fx32)(((fx64)(v1) * (v2) + 0x800LL) >> 12))
#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))

extern u32 FX_Div(u32 a, u32 b);

int POKETRADE_2D_StepBezierCurve(struct Curve *c)
{
    fx32 t, s, t2, s2, ts2, s3, t2s, t3;
    fx32 tm3, t2m3;

    if (c->idx < c->count - 1) {
        t = FX_Div(FX_INT_TO_FX32(c->idx), FX_INT_TO_FX32(c->count));
        s = FX32_ONE - t;
        t2 = FX_MUL(t, t);
        s2 = FX_MUL(s, s);
        tm3 = 3 * t;
        ts2 = FX_MUL(tm3, s2);
        s3 = FX_MUL(s2, s);
        t2m3 = 3 * t2;
        t2s = FX_MUL(t2m3, s);
        t3 = FX_MUL(t2, t);
        c->out.x = FX_MUL(c->p[0].x, s3) + FX_MUL(c->p[1].x, ts2)
                 + FX_MUL(c->p[2].x, t2s) + FX_MUL(c->p[3].x, t3);
        c->out.y = FX_MUL(c->p[0].y, s3) + FX_MUL(c->p[1].y, ts2)
                 + FX_MUL(c->p[2].y, t2s) + FX_MUL(c->p[3].y, t3);
        c->out.z = FX_MUL(c->p[0].z, s3) + FX_MUL(c->p[1].z, ts2)
                 + FX_MUL(c->p[2].z, t2s) + FX_MUL(c->p[3].z, t3);
        c->idx++;
        return 0;
    }
    c->out = c->p[3];
    return 1;
}

