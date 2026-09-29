/*
 * function: func_021EE908
 * address:  0x021EE908
 * packet:   pkt_ov027_021EE908
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021EEAF4  0x021EEAF4  thumb  ov027
 */

int *func_021A21B8(int a);
int func_021A223C(int a, int b);
void func_021A2390(int a, int b, int c, int d);
int func_021A23B0(int a);
int func_021A21BC(int a);
void func_021EEAF4(int a, int *p);

int func_021EE908(int a, int b, int c)
{
    int *p = func_021A21B8(a);
    int t = func_021A223C(a, c);
    int r;

    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0)
            func_021A2390(a, 0x7fdf, 0x5a, b);
    } else {
        if (b != 0)
            r = func_021A23B0(a);
        else
            r = 1;
        if (r != 0 && t != 0) {
            if (func_021A21BC(a) == 0)
                return 1;
        }
    }
    func_021EEAF4(a, p);
    return 0;
}
