/*
 * function: func_0207D184
 * address:  0x0207D184
 * packet:   pkt_0207D184
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FX_AcosIdx (libfx.TWL.HYB.a fx_asinacosidx.o)
 *
 * symbols:
 *   FX_SinCosTable_   0x020A1B38  data
 */

typedef long fx32;
typedef short fx16;
typedef unsigned short u16;

extern const fx16 FX_SinCosTable_[];

u16 func_0207D184(fx32 x)
{
    int left, right, mid;
    fx16 value;

    if (x >= 0) {
        left = 0;
        right = 1024;
    } else {
        left = 1024;
        right = 2048;
    }
    value = (fx16)x;

    while (left <= right) {
        fx16 v;

        mid = (left + right) / 2;
        v = FX_SinCosTable_[mid * 2 + 1];
        if (value == v) {
            break;
        }
        if (v < value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return (u16)(((mid * 2 + 1) << 16) / 8192);
}
