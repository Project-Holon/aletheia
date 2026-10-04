/*
 * function: ov208_func_021C5090
 * address:  0x021C5090
 * packet:   pkt_ov208_021C5090
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015F14  0x02015F14  thumb
 *   func_02015C78  0x02015C78  thumb
 *   _fflt  0x0209BDBC  arm
 *   _fgr  0x0209BBB0  arm
 *   _fmul  0x0209C77C  arm
 *   _fadd  0x0209C95C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 */

typedef signed int fx32;
typedef unsigned int u32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

typedef signed short   s16;
extern s16 func_02015F14(void *p);
extern void func_02015C78(u32 obj, Vec *v);

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

void ov208_func_021C5090(u32 obj)
{
    Vec v;
    float y;

    y = 0.25f * -(float)func_02015F14((void *)obj);
    v.x = FX_F32_TO_FX32(y);
    v.y = 0;
    v.z = 0;
    func_02015C78(obj, &v);
}
