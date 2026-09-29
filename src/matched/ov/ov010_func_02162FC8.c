/*
 * function: func_02162FC8
 * address:  0x02162FC8
 * packet:   pkt_ov010_02162FC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;
typedef short s16;

int func_02162FC8(char *p, u16 *v)
{
    u16 *q;

    if (*(u16 *)(p + 8) == 0) {
        return 0;
    }
    q = (u16 *)(p + 10);
    if (*(u16 *)(p + 10) == v[0] && q[1] <= v[3] && q[1] + q[3] > v[3]
        && ((s16 *)q)[2] <= ((s16 *)v)[2] && ((s16 *)q)[2] + q[4] > ((s16 *)v)[2]) {
        return 1;
    }
    return 0;
}
