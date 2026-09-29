/*
 * function: func_021EE800
 * address:  0x021EE800
 * packet:   pkt_ov028_021EE800
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 */

int *func_021A21B8(int a);
void func_021A2390(int a, int b, int c, int d);
int func_021A23B0(int a);
int func_021A21BC(int a);

int func_021EE800(int a, int b)
{
    int *p = func_021A21B8(a);
    int v = *p;
    int r;

    if (v == 0) {
        *p = v - 1;
        func_021A2390(a, 0x7fdf, 0x3c, b);
    } else {
        if (b != 0)
            r = func_021A23B0(a);
        else
            r = 1;
        if (r != 0) {
            if (func_021A21BC(a) == 0)
                return 1;
        }
    }
    return 0;
}
