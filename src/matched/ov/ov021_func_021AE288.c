/*
 * function: func_021AE288
 * address:  0x021AE288
 * packet:   pkt_ov021_021AE288
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AE79C  0x021AE79C  thumb  ov021
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021AE348  0x021AE348  thumb  ov021
 *   func_021AE7A8  0x021AE7A8  thumb  ov021
 */

typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
extern int func_021AE79C(u32 a);
extern int func_0216D63C(int a, int b);
extern void func_0216D828(int a, int *b);
extern int func_0216D5F8(int a);
extern int func_021AE348(int a, int b, int *c, int *d);
extern int func_021AE7A8(int a, int b, int c, int d);

int func_021AE288(int a, int b, int c, u16 *d)
{
    int q[2];
    int p[2];
    int r4, r7, sc;
    u16 r5;

    r4 = func_021AE79C(b);
    if ((u16)(r4 + 0xffff) <= 1) {
        r5 = 0;
        r7 = (s16)func_0216D63C(b, 0);
        func_0216D828(b, q);
        func_0216D828(c, p);
        if (r4 == 1) {
            sc = func_0216D5F8(b);
            r4 = func_021AE348(sc, r7, q, p);
            if (r4 != r5 - 1 && func_021AE7A8(b, sc, r4, a) == 0) {
                *d = sc;
                return r4;
            }
        } else {
            do {
                r4 = func_021AE348(r5, r7, q, p);
                if (r4 != -1 && func_021AE7A8(b, r5, r4, a) == 0) {
                    *d = r5;
                    return r4;
                }
                r5++;
            } while (r5 < 4);
        }
    }
    return -1;
}
