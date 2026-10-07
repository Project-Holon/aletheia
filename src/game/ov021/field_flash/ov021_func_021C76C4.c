/*
 * function: func_021C76C4
 * address:  0x021C76C4
 * packet:   pkt_ov021_021C76C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fmul  0x0209C77C  arm
 *   _fdiv  0x0209CE10  arm
 *   _fsub  0x0209CB8C  arm
 *   _fadd  0x0209C95C  arm
 *   _fgr   0x0209BBB0  arm
 *   _ffix  0x0209C494  arm
 */

typedef int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

void func_021C76C4(Vec *out, float a, float b, float c)
{
    float y = c / (b * b);
    float z = y * a;
    float v = c - a * z;

    out->x = 0;
    out->y = FX_F32_TO_FX32(v);
    out->z = 0;
}
