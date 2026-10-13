/*
 * function: FIELD_TASK_GetSpinAcmdEaseOut
 * address:  0x021C73B4
 * packet:   pkt_ov021_021C73B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gSpinAcmdEaseOut     0x021DAAC8  data  ov021  a2
 *   func_0209C5E0  0x0209C5E0  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _fmul          0x0209C77C  arm
 *   _fdiv          0x0209CE10  arm
 *   _ffix          0x0209C494  arm
 */

typedef unsigned short u16;

typedef struct { u16 v[4]; } T4;

extern T4 gSpinAcmdEaseOut;
extern double func_0209C5E0(double x);

u16 FIELD_TASK_GetSpinAcmdEaseOut(float a, float b, float c)
{
    T4 t = gSpinAcmdEaseOut;
    float x = 4.0f * c;
    float f = x * x / b;
    int n = (int)(float)func_0209C5E0((double)(f * a));

    return t.v[n % 4];
}
