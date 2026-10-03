/*
 * function: func_0217BED4
 * address:  0x0217BED4
 * packet:   pkt_ov018_0217BED4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   d_02182B60     0x02182B60  data   a4
 */

typedef struct { int x, y, z; } V12;

typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern short *func_0217BEA8(int);
extern const V12 d_02182B60;

int func_0217BED4(int a, V12 *out)
{
    short *p;
    int x, y, z;

    if (func_02013D5C(a) != 1) {
        p = func_0217BEA8(a);
        if (p == 0)
            return 0;
        z = p[4] << 16;
        y = p[3] << 16;
        x = p[2] << 16;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        *out = d_02182B60;
    }
    return 1;
}
