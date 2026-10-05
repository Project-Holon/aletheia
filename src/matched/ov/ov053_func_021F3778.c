/*
 * function: func_021F3778
 * address:  0x021F3778
 * packet:   pkt_ov053_021F3778
 * region:   ov053
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218ECB4  0x0218ECB4  thumb  ov021
 *   func_0202B93C  0x0202B93C  thumb
 *   func_021F3A5C  0x021F3A5C  thumb  ov053
 *   func_021C4DE4  0x021C4DE4  thumb  ov021
 *   func_021F3A38  0x021F3A38  thumb  ov053
 *   func_021F3A7C  0x021F3A7C  thumb  ov053
 *   func_021F3A6C  0x021F3A6C  thumb  ov053
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021F3B40  0x021F3B40  thumb  ov053
 */

extern int *func_021897BC(int, int);
extern int func_02188C58(int);
extern void func_0218ECE4(int, int *);
extern void func_0218ECB4(int, int *);
extern void func_0202B93C(int, int *, int *);
extern void func_021F3A5C(int *, int);
extern int func_021C4DE4(int, int);
extern void func_021F3A38(int *, int);
extern void func_021F3A7C(int *, int);
extern void func_021F3A6C(int *);
extern int func_02188D2C(int);
extern void func_021BE580(int);
extern int func_02188CB4(int);
extern void func_021F3B40(int *, int, int);

void func_021F3778(int a)
{
    int i;
    int h;
    int *p;
    int v1[3];
    int v2[3];

    i = 0;
    p = func_021897BC(a, 0);
    h = func_02188C58(a);
    func_0218ECE4(h, v1);
    func_0218ECB4(h, v2);
    func_0202B93C(p[1], v1, v2);
    for (i = 0; i < 5; i++) {
        int *q = p + i;
        if (q[7] > 0) {
            if (--q[7] <= 0) {
                func_021F3A5C(p, i);
                switch (i) {
                case 0:
                    p[8] = 1;
                    break;
                case 2:
                    p[10] = 1;
                    break;
                }
            }
        } else if (func_021C4DE4(q[2], 0x1000)) {
            func_021F3A38(p, i);
        }
    }
    func_021F3A7C(p, a);
    func_021F3A6C(p);
    func_021BE580(func_02188D2C(a));
    func_021F3B40(p + 0x1a, h, func_02188CB4(a));
}
