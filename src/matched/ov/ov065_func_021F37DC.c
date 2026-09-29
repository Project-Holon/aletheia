/*
 * function: func_021F37DC
 * address:  0x021F37DC
 * packet:   pkt_ov065_021F37DC
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */

extern int func_02188D2C(int a);
extern int *func_021897BC(char *p, int idx);
extern void func_021BE580(int a);
extern int func_021BE6E8(int a, int b, int c, int d);
extern void func_020061E4(int a);
extern int *func_021BE674(int a, int b, int c, int d);
extern int func_021BE6BC(int *p);
extern void func_021BE4B4(int a, int b, int c, int d);
extern int func_02188C80(int a);
extern int func_020120F4(int a);
extern int func_02012EC4(int a);
extern int *func_0200B3A4(int a, int b);

void func_021F37DC(int a)
{
    int s;
    int *w;

    s = func_02188D2C(a);
    w = func_021897BC((char *)a, 1);
    if (w[0] != 0) {
        func_021BE580(s);
        if (w[1] == 0) {
            if (func_021BE6E8(s, 0, 0, 0) == 0x3C000)
                func_020061E4(0x7F9);
        }
        if (func_021BE6BC(func_021BE674(s, 0, 0, 0)) != 0) {
            func_021BE4B4(s, 0, 0, 1);
            w[0] = 0;
            *func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(a))), 0x36) = 0;
        }
    }
}
