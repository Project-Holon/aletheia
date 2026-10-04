/*
 * function: func_021EE888
 * address:  0x021EE888
 * packet:   pkt_ov027_021EE888
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2248  0x021A2248  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021EEA04  0x021EEA04  thumb  ov027
 *   func_021EEAF4  0x021EEAF4  thumb  ov027
 *   d_021EEB48     0x021EEB48  data  ov027  a4
 */

int *func_021A21B8(int *p);
int func_021A2248(unsigned char *o, int arg);
int func_0209C0A4(int a, int b);
void func_021EEA04(int a, int b, int c);
void func_021EEAF4(int a, int *p);
extern int d_021EEB48[];

int func_021EE888(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);

    if (func_021A2248((unsigned char *)a, c) != 0) {
        int v = d_021EEB48[func_0209C0A4(p[1], 40)];
        p[3] = v;
        if (v <= -6)
            func_021EEA04(a, 1, c);
    }
    func_021EEAF4(a, p);
    return 0;
}
