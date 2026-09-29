/*
 * function: func_02162F74
 * address:  0x02162F74
 * packet:   pkt_ov010_02162F74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

int func_02162F74(char *p, int *v)
{
    u16 *q;
    int x, z;

    if (*(u16 *)(p + 8) == 1) {
        return 0;
    }
    q = (u16 *)(p + 10);
    x = (v[0] >> 4) / 0x1000;
    z = (v[2] >> 4) / 0x1000;
    if (*(u16 *)(p + 10) <= x && *(u16 *)(p + 10) + q[2] > x
        && q[1] <= z && q[1] + q[3] > z) {
        return 1;
    }
    return 0;
}
