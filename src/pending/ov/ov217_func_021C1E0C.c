/*
 * function: func_021C1E0C
 * address:  0x021C1E0C
 * packet:   pkt_ov217_021C1E0C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wC1 lane06): 296 bytes, float loop (100 points on a circle of
 * radius r = (f32)(p+0x1b0)/4096, FX32_CONST of R*cos / R*sin / 0 into s16
 * triples at p+0x1ba+6i).  Body and pool constants are right (4096.0f, 2pi,
 * 100.0f, pi/2; cos = 0x0209A390, sin = 0x0209AA08, third value is a runtime
 * FX32_CONST of a 0.0f local).  Residue: the original keeps p, r, and the three
 * field offsets (0x1b0 base, +0xa, +0xc, +0xe) in stack slots with every offset
 * statement emitted in source order (copy then add, stored twice), 0.5f hoisted
 * into r7, and e = p+6i in r6; this draft schedules the offset math together
 * and rematerialises 0.5f (316 vs 312 bytes).  Tried: enum Off local, copy+add
 * offsets, h = 0.5f local, z = 0.0f local.
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
 *
 * Note 2026-10-04 (wD1 lane06): Not retried (float loop, see note above).
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
typedef double f64;
typedef enum { K1B0 = 0x1b0 } Off;

extern f64 cos(f64 x);
extern f64 sin(f64 x);

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + h) : ((x) * 4096.0f - h)))

void func_021C1E0C(u8 *p)
{
    f32 r;
    Off o;
    s32 ox;
    s32 oy;
    s32 i;
    f32 h = 0.5f;
    f32 z = 0.0f;
    o = K1B0;
    r = FX_FX32_TO_F32(*(s32 *)(p + o));
    ox = o;
    ox += 0xa;
    oy = o;
    oy += 0xc;
    o += 0xe;
    for (i = 0; i < 100; i++) {
        f32 t = 1.5707964f - (6.2831855f * (f32)i) / 100.0f;
        f32 x = r * (f32)cos((f64)t);
        f32 y = r * (f32)sin((f64)t);
        u8 *e = p + i * 6;
        *(s16 *)(e + ox) = FX32_CONST(x);
        *(s16 *)(e + oy) = FX32_CONST(y);
        *(s16 *)(e + o) = FX32_CONST(z);
    }
}
