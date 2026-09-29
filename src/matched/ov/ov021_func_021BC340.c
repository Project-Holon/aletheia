/*
 * function: func_021BC340
 * address:  0x021BC340
 * packet:   pkt_ov021_021BC340
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_021BC340(int a, int b)
{
    int r = 0;

    if (a == 0x71 || a == 0x159) {
        if (b == 0) {
            r = -0x800;
        }
    } else if (a == 0x8f) {
        if (b == 0) {
            r = 2 << 10;
        }
    } else if (a == 0x159 + 0x12) {
        if (b == 0) {
            r = -0x5800;
        }
    } else {
        if (b == 0) {
            r = 6 << 10;
        }
    }
    return r;
}
