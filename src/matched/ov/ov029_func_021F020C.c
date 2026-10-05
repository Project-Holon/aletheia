/*
 * function: func_021F020C
 * address:  0x021F020C
 * packet:   pkt_ov029_021F020C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 * note 2026-10-05 (wD6 lane14): closed by reusing parameter a for x (the early
 * `adds r4,r1,#0` copy), b for the b/8 - lo[m] intermediate, and two 8-byte
 * struct copies of the tables (ldm r5,{r3,r5}).
 *
 * symbols:
 *   func_021F020C  0x021F020C  thumb  ov029
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   d_021F333C     0x021F333C  data  a4
 *   d_021F334C     0x021F334C  data  a4
 */

struct Pair {
    int a;
    int b;
};

extern unsigned int func_021F2B9C(unsigned char *p, int a, int b);
extern struct Pair d_021F333C;
extern struct Pair d_021F334C;

int func_021F020C(const void *p, int a, int b, int *c, int *d)
{
    int y;
    struct Pair lo;
    struct Pair hi;
    int ret = 5;
    int m;

    lo = d_021F333C;
    hi = d_021F334C;
    a = (a / 8 + 2) / 4;
    if (a < 0) {
        return 5;
    }
    m = a % 2;
    b = b / 8 - (&lo.a)[m];
    if (b < 0) {
        return 5;
    }
    y = b / 4;
    if (a < 9 && y < (&hi.a)[m]) {
        ret = func_021F2B9C((unsigned char *)p, a, y);
    }
    *c = a;
    *d = y;
    return ret;
}
