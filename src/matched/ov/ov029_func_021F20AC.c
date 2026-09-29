/*
 * function: func_021F20AC
 * address:  0x021F20AC
 * packet:   pkt_ov029_021F20AC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F133C  0x021F133C  thumb  ov029
 *   func_0204B404  0x0204B404  arm
 *   func_0204B800  0x0204B800  arm
 */

extern int func_021F133C(void *, int, int *, int *);
extern void func_0204B404(int, void *, int);
extern void func_0204B800(int, int);

void func_021F20AC(char *p)
{
    int i;
    int a;
    int b;
    short s[2];

    for (i = 0; i < 3; i++) {
        if (func_021F133C(p, i + 1, &a, &b)) {
            a = a * 8;
            b = b * 8;
            s[0] = a + 0x10;
            s[1] = b + 0xf;
            func_0204B404(*(int *)(p + i * 4 + 0x158), s, 0);
            a += 0x20;
            func_0204B800(*(int *)(p + i * 4 + 0x158), (a / 8) & 0xff);
        } else {
            s[0] = -0x40;
            s[1] = 0;
            func_0204B404(*(int *)(p + i * 4 + 0x158), s, 0);
        }
    }
}
