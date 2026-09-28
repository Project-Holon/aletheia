/*
 * function: func_0216A8F0
 * address:  0x0216A8F0
 * packet:   pkt_ov010_0216A8F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three-phase orbit step: spiral out over 110 frames, circle at radius 3
 * for 80, spiral in for 80, returning 1 when done. FX_Mul must be the
 * inline function with the table value first (the macro, or the radius
 * first, puts the radius in r0:r1 and spills its sign word: 368 out).
 *
 * symbols:
 *   func_0216D89C    0x0216D89C  thumb  ov010
 *   FX_SinCosTable_  0x020A1B38  data
 *   _ll_mul          0x0209C054  arm
 *   _u32_div_f       0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Orbit {
    u32 count;          /* 0x00 */
    void *obj;          /* 0x04 */
    VecFx32 pos;        /* 0x08 */
} Orbit;

extern const s16 FX_SinCosTable_[];
extern void func_0216D89C(void *obj, const VecFx32 *pos);

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}


int func_0216A8F0(void *unused, u32 *mode, Orbit *o)
{
    VecFx32 pos;
    u32 cnt;
    s32 idx;
    fx32 r;

    pos = o->pos;
    cnt = ++o->count;
    switch (*mode) {
    case 0:
        idx = (cnt << 17) / 110;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        r = (cnt * 3 << 16) / 110;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], r);
        pos.z += FX_Mul(FX_SinCosTable_[idx], r);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 110) {
            o->count = 0;
            *mode = 1;
        }
        break;
    case 1:
        idx = (cnt << 16) / 80;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], 0x30000);
        pos.z += FX_Mul(FX_SinCosTable_[idx], 0x30000);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 80) {
            o->count = 0;
            *mode = 2;
        }
        break;
    case 2:
        idx = (cnt << 16) / 80;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        r = ((80 - cnt) * 3 << 16) / 80;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], r);
        pos.z += FX_Mul(FX_SinCosTable_[idx], r);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 80)
            return 1;
        break;
    }
    return 0;
}
