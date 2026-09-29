/*
 * function: func_0219BC48
 * address:  0x0219BC48
 * packet:   pkt_ov021_0219BC48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0219BCC0  0x0219BCC0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_0216D67C(int a);
extern int func_0216D590(int a);
extern int func_021AE884(int a);
extern int func_0216DD1C(int a, int *out, u32 *iter);
extern int func_0219BCC0(int a, u8 *b, int c);

int func_0219BC48(int a, u8 *b)
{
    u32 iter;
    int out;
    int r7;
    int r6;
    int t;

    t = func_0216D67C(a);
    iter = 0;
    r7 = func_0216D590(a);
    r6 = func_021AE884(a);
    while (func_0216DD1C(t, &out, &iter) == 1) {
        if (a != out && r7 == func_0216D590(out) && r6 == func_021AE884(out)) {
            if (b[1] == 0) {
                func_0219BCC0(a, b, out);
            }
            return 1;
        }
    }
    b[1] = 0;
    return 0;
}
