/*
 * function: FIELD_TASK_GetSpinAcmdLinear
 * address:  0x021C72F8
 * packet:   pkt_ov021_021C72F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks one of four halfwords from a table by (int)(4*c/b*a) % 4, in soft float.
 * The last multiply keeps its operand order only through a named float local;
 * inline it and the compiler swaps to a * f.
 *
 * symbols:
 *   gSpinAcmdLinear  0x021DAAC0  data  ov021  a2
 *   _fmul  0x0209C77C  arm
 *   _fdiv  0x0209CE10  arm
 *   _ffix  0x0209C494  arm
 */

typedef unsigned short u16;

typedef struct { u16 v[4]; } T4;

extern T4 gSpinAcmdLinear;

u16 FIELD_TASK_GetSpinAcmdLinear(float a, float b, float c)
{
    T4 t = gSpinAcmdLinear;
    float f = 4.0f * c / b;
    int n = (int)(f * a);

    return t.v[n % 4];
}
