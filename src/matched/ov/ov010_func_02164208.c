/*
 * function: func_02164208
 * address:  0x02164208
 * packet:   pkt_ov010_02164208
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_02164208(int dir, int *p, int amt)
{
    switch (dir) {
    case 0:
        p[2] -= amt;
        break;
    case 1:
        p[2] += amt;
        break;
    case 2:
        p[0] -= amt;
        break;
    case 3:
        p[0] += amt;
        break;
    }
}
