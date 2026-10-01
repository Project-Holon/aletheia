/*
 * function: func_0218C574
 * address:  0x0218C574
 * packet:   pkt_ov021_0218C574
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 */

typedef struct {
    int a, b, c;
    int *d;
} S;

int func_0218BBD0(int a, int b);

void func_0218C574(int a, S *s, int b)
{
    *s->d = func_0218BBD0(a, b);
}
