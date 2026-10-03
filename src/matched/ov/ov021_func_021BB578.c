/*
 * function: func_021BB578
 * address:  0x021BB578
 * packet:   pkt_ov021_021BB578
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021BB778  0x021BB778  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A90     0x021D9A90  data  a4
 */

extern int d_021D9A90;

typedef unsigned int   u32;
int func_021ABEA0(u32 a, u32 b);
void func_0216E1A4(int a, void *out);
int func_021ABE14(int a);
void func_021BB778(int n);
void func_021ABFA8(int a, void *b, int c, int d, void *e, int f);

void func_021BB578(int a, int b, int c, int d)
{
    int s[7];

    s[0] = c;
    s[1] = d;
    s[2] = func_021ABEA0(a, 4);
    s[3] = b;
    func_0216E1A4(b, &s[4]);
    s[6] = func_021ABE14(a);
    if (d == 1) {
        func_021BB778(c);
    }
    func_021ABFA8(a, &d_021D9A90, 0, 0, s, 0);
}
