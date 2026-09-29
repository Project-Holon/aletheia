/*
 * function: func_021C734C
 * address:  0x021C734C
 * packet:   pkt_ov021_021C734C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same table pick as func_021C72F8 with an a*a and b*b (quadratic) curve.
 *
 * symbols:
 *   d_021DAAB8  0x021DAAB8  data  ov021  a2
 *   _fmul  0x0209C77C  arm
 *   _fdiv  0x0209CE10  arm
 *   _ffix  0x0209C494  arm
 */

typedef unsigned short u16;

typedef struct { u16 v[4]; } T4;

extern T4 d_021DAAB8;

u16 func_021C734C(float a, float b, float c)
{
    T4 t = d_021DAAB8;
    float f = 4.0f * c / (b * b);
    float g = f * a;
    int n = (int)(a * g);

    return t.v[n % 4];
}
