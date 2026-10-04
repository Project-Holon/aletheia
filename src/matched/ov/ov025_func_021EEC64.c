/*
 * function: func_021EEC64
 * address:  0x021EEC64
 * packet:   pkt_ov025_021EEC64
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EEC64  0x021EEC64  thumb  ov025
 *   func_021EEE04  0x021EEE04  thumb  ov025
 *   func_021EEEE0  0x021EEEE0  thumb  ov025
 *   d_021EF770  0x021EF770  data  ov025  a4
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2248  0x021A2248  thumb  ov021
 */

extern int *func_021A21B8(int *p);
extern int func_021A2248(unsigned char *o, int arg);
extern void func_021EEE04(int, int, int);
extern void func_021EEEE0(int, int *);
extern int d_021EF770[];

int func_021EEC64(int a, int b, int c)
{
    int *p;

    p = func_021A21B8((int *)a);
    if (func_021A2248((unsigned char *)a, c) != 0) {
        if (d_021EF770[p[1] / 256] <= -8) {
            func_021EEE04(a, 1, c);
        }
    }
    func_021EEEE0(a, p);
    return 0;
}
