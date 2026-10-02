/*
 * function: func_021A2D88
 * address:  0x021A2D88
 * packet:   pkt_ov021_021A2D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A35E0  0x021A35E0  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   d_021DDE90     0x021DDE90  data  a4
 */

typedef unsigned short u16;

extern int d_021DDE90;

void *func_02030734(int a, int b, int c, void *d, int e);
int func_02188C84(int obj);
int func_02188CB4(int obj);
int func_021A3074(int obj);
void func_0216D5E0(int a, int b);
void func_021A35E0(int a, int b);
int func_0216D888(int a);
void func_02188D40(int a, int b);
void func_02188CAC(int a, void *b);

void func_021A2D88(int obj, int unused, int y)
{
    int h;
    int a;
    int b;
    char *p;

    h = func_02188C84(obj);
    p = (char *)func_02030734(h, 0x10, 1, &d_021DDE90, 0x68);
    *(u16 *)p = h;
    *(int *)(p + 4) = obj;
    a = func_02188CB4(obj);
    b = func_021A3074(a);
    func_0216D5E0(b, y);
    func_021A35E0(a, h);
    func_02188D40(obj, func_0216D888(b));
    func_02188CAC(obj, p);
}
