/*
 * function: func_021D09D0
 * address:  0x021D09D0
 * packet:   pkt_ov021_021D09D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200E5A0  0x0200E5A0  thumb
 *   func_0200E5CC  0x0200E5CC  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021DE674     0x021DE674  data  a4
 */

extern int d_021DE674;

extern int func_020120F4(int x);
extern int func_02012EBC(int x);
extern void *func_02030734(int a, int b, int c, void *d, int e);
extern void func_020072CC(int a, int b, int c, void *d, int e);
extern int func_020073D8(int a, int b, int c);
extern int func_0200E5A0(int a);
extern int func_0200E5CC(int a);
extern void func_0200734C(int a, int b);
extern void func_020307B0(void *p);

void func_021D09D0(int a, char *out)
{
    int v;
    int t;
    int h;
    void *buf;

    h = func_02012EBC(func_020120F4(a));
    buf = func_02030734(0x8004, 0x8004 >> 3, 1, &d_021DE674, 0x79);
    v = 0x8004 >> 3;
    func_020072CC(h, 5, 0x8004, buf, v);
    v = 0;
    t = func_020073D8(h, 5, 0);
    if (func_0200E5A0(t)) {
        int r = func_0200E5CC(t);
        v = 1;
        if (r == 0) {
            v = 2;
        }
    }
    func_0200734C(h, 5);
    func_020307B0(buf);
    *(int *)(out + 0x150) = v;
}
