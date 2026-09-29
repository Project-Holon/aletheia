/*
 * function: func_021C73B4
 * address:  0x021C73B4
 * packet:   pkt_ov021_021C73B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; the one wildcard is the _d2f call (0x0209B64C, arm runtime
 * double-to-float). Blocker: no witness outside the range, and the only
 * caller of it in this range is this function. Arm9 runtime leaf, not filed.
 *
 * symbols:
 *   d_021DAAC8     0x021DAAC8  data  ov021  a2
 *   func_0209C5E0  0x0209C5E0  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _fmul          0x0209C77C  arm
 *   _fdiv          0x0209CE10  arm
 *   _ffix          0x0209C494  arm
 */

typedef unsigned short u16;

typedef struct { u16 v[4]; } T4;

extern T4 d_021DAAC8;
extern double func_0209C5E0(double x);

u16 func_021C73B4(float a, float b, float c)
{
    T4 t = d_021DAAC8;
    float x = 4.0f * c;
    float f = x * x / b;
    int n = (int)(float)func_0209C5E0((double)(f * a));

    return t.v[n % 4];
}
