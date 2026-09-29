/*
 * function: func_021E0850
 * address:  0x021E0850
 * packet:   pkt_ov093_021E0850
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E08E0  0x021E08E0  thumb  ov093
 *   func_021E08F0  0x021E08F0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8;
extern int func_021D775C(int key);
extern int func_021B9A40(u8 k);
extern int func_021E08E0(int a, int b);
extern int func_021E08F0(int a, int b);
extern u8 *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E0850(int a, void *b, int c)
{
    int t;
    u8 *p;
    u8 *q;
    unsigned i;

    if (c == func_021D775C(3)) {
        t = func_021B9A40(func_021D775C(4));
        if (func_021E08E0(t, 0) != 0 || func_021E08F0(t, 1) != 0) {
            p = func_021C88A4(b, 0x1a, c);
            p[7] = t;
            p[4] = 3;
            for (i = 1; i < 3; i++) {
                p[4 + i] = 0;
            }
            if (p[4] > 1) {
                p[5] |= 1;
            }
            if (p[4] > 1) {
                p[5] |= 2;
            }
            func_021C88C8(b, p);
            q = func_021C88A4(b, 0x3a, c);
            q[4] = 1;
            func_021C88C8(b, q);
        }
    }
}
