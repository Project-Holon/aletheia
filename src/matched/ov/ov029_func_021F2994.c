/*
 * function: func_021F2994
 * address:  0x021F2994
 * packet:   pkt_ov029_021F2994
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202223C  0x0202223C  thumb
 *   func_02022230  0x02022230  thumb
 *   func_021F26E0  0x021F26E0  thumb  ov029
 *   func_021F251C  0x021F251C  thumb  ov029
 *   func_021F2180  0x021F2180  thumb  ov029
 */

extern void func_0202223C(int a, int b);
extern void func_02022230(int a);
extern void func_021F26E0(int *p);
extern void func_021F251C(int *p, int a, int b, int c, int d);
extern void func_021F2180(void);

int func_021F2994(int *p)
{
    int a = p[8];
    int b = p[6];
    int c = p[7];

    if (p[0] == (int)func_021F2180) {
        func_0202223C(1, 0);
        func_021F26E0(p);
        func_021F251C(p, a, b, c, 0);
        func_02022230(1);
        return 1;
    }
    return 0;
}
