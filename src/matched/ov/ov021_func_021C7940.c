/*
 * function: func_021C7940
 * address:  0x021C7940
 * packet:   pkt_ov021_021C7940
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fgr           0x0209BBB0  arm
 *   _ffltu         0x0209BE04  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 *   _ll_mul        0x0209C054  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef int fx32;
typedef float f32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

void func_021C7940(VecFx32 *out, u32 cnt, VecFx32 *v, u32 max)
{
    fx32 t;

    t = FX_F32_TO_FX32((f32)cnt / (f32)max);
    out->x = (fx32)(((long long)v->x * t + 0x800) >> 12);
    out->y = (fx32)(((long long)v->y * t + 0x800) >> 12);
    out->z = (fx32)(((long long)v->z * t + 0x800) >> 12);
}
