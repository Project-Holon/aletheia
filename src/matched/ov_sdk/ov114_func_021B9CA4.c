/*
 * function: NHTTPi_checkKeepAlive
 * address:  0x021B9CA4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Sizes a resource id: -1 stays -1, a recognised id yields -1, else 0.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0215F4DC(int, int *, int, int);

int NHTTPi_checkKeepAlive(int a)
{
    int v = 0;
    if (a == -1) {
        v = -1;
    } else {
        int n = 4;
        int tmp;
        if (func_0215F4DC(a, &tmp, 1, n) != n - 10)
            v = n - 5;
    }
    return v;
}
