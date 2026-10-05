/*
 * function: func_021C1E0C
 * address:  0x021C1E0C
 * packet:   pkt_ov217_021C1E0C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 100 points on a circle of radius r = (p+0x1b0)/4096, stored as FX32 s16
 * triples at p+0x1ba+6i. The base offset 0x1b0 is a local (o + 0xa, o + 0xc,
 * o + 0xe stay as spilled runtime adds); the first converted value goes through
 * a local so its _ffix call comes before the p + i*6 address.
 *
 * symbols:
 *   cos            0x0209A390  arm
 *   sin            0x0209AA08  arm
 *   _fflt          0x0209BDBC  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fgr           0x0209BBB0  arm
 */

typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f64 cos(f64 x);
extern f64 sin(f64 x);

#define FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))

void func_021C1E0C(u8 *p)
{
    s32 i;
    f32 r;
    s32 o = 0x1b0;
    r = *(s32 *)(p + o) / 4096.0f;
    for (i = 0; i < 100; i++) {
        f32 t = 1.5707964f - (6.2831855f * (f32)i) / 100.0f;
        f32 x = r * (f32)cos((f64)t);
        f32 y = r * (f32)sin((f64)t);
        f32 z = 0.0f;
        s32 v = FX32_CONST(x);
        *(s16 *)(p + i * 6 + (o + 0xa)) = v;
        *(s16 *)(p + i * 6 + (o + 0xc)) = FX32_CONST(y);
        *(s16 *)(p + i * 6 + (o + 0xe)) = FX32_CONST(z);
    }
}
