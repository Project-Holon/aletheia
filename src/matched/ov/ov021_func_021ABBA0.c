/*
 * function: func_021ABBA0
 * address:  0x021ABBA0
 * packet:   pkt_ov021_021ABBA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef unsigned short u16;
typedef struct { int x; int y; int z; } V;

void func_021ABBA0(u16 *r, V *v, int *o1, int *o2)
{
    V t = *v;

    t.x -= 0x8000;
    t.z -= 0x8000;
    *o1 = r[4] << 16;
    if (r[2] == 1)
        *o2 = t.x - (r[0] << 16);
    else
        *o2 = t.z - (r[1] << 16);
}
