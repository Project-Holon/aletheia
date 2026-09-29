/*
 * function: func_021EFF00
 * address:  0x021EFF00
 * packet:   pkt_ov029_021EFF00
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EFF00  0x021EFF00  thumb  ov029
 */

void func_021EFF00(int x, int y, int *a, int *b)
{
    int m = x % 2;

    if (m == 0) {
        a[0] = x;
        b[0] = y - 1;
        a[1] = x;
        b[1] = y + 1;
        a[2] = x + 1;
        b[2] = y;
        a[3] = x + 1;
        b[3] = y - 1;
        a[4] = x - 1;
        b[4] = y;
        a[5] = x - 1;
        b[5] = y - 1;
    } else {
        a[0] = x;
        b[0] = y - 1;
        a[1] = x;
        b[1] = y + 1;
        a[2] = x + 1;
        b[2] = y;
        a[3] = x + 1;
        b[3] = y + 1;
        a[4] = x - 1;
        b[4] = y;
        a[5] = x - 1;
        b[5] = y + 1;
    }
}
