/*
 * function: func_021F385C
 * address:  0x021F385C
 * packet:   pkt_ov065_021F385C
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
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

extern int func_02188D2C(int a);
extern int *func_021897BC(char *p, int idx);
extern void func_021BE4B4(int a, int b, int c, int d);
extern int *func_021BE674(int a, int b, int c, unsigned short d);
extern void func_021BE6B0(int *p, int v);
extern void func_020061E4(int a);

void func_021F385C(int a)
{
    int i;
    int s;
    int *w;

    s = func_02188D2C(a);
    w = func_021897BC((char *)a, 1);
    w[0] = 1;
    func_021BE4B4(s, 0, 0, 0);
    for (i = 0; i < 2; i++)
        func_021BE6B0(func_021BE674(s, 0, 0, i), 0);
    if (w[1] != 0)
        func_020061E4(0x7F7);
    else
        func_020061E4(0x7F8);
}
