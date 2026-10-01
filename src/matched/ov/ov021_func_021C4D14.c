/*
 * function: func_021C4D14
 * address:  0x021C4D14
 * packet:   pkt_ov021_021C4D14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0202B928 and func_0202B920 are witnessed by src/matched/arm9/.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202B928  0x0202B928  thumb
 *   func_0202B920  0x0202B920  thumb
 *   d_021DE48C     0x021DE48C  data  a4
 */

typedef unsigned short u16;

extern int d_021DE48C;

extern int func_02188C84(int a);
extern void func_02188C80(int a);
extern void func_02012134(void);
extern int func_0202B57C(void);
extern void *func_02030734(int a, int b, int c, void *d, int e);
extern int func_0202B928(int a, int b);
extern void func_0202B920(int a, int b, int c, int d);

void *func_021C4D14(int a, int b, int c, int d, int e)
{
    int n = func_02188C84(a);
    int r;
    int *p;

    func_02188C80(a);
    func_02012134();
    r = func_0202B57C();
    p = (int *)func_02030734(n, 0x18, 0, &d_021DE48C, 0x3c);
    *(u16 *)p = n;
    p[1] = a;
    p[2] = r;
    p[3] = c;
    p[4] = 0;
    p[5] = b;
    if (func_0202B928(r, c) == 0) {
        func_0202B920(r, c, d, e);
    }
    return p;
}
