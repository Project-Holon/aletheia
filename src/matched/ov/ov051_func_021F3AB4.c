/*
 * function: func_021F3AB4
 * address:  0x021F3AB4
 * packet:   pkt_ov051_021F3AB4
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D3CC  0x0216D3CC  thumb
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454  0x0216D454  thumb
 *   func_0216D480  0x0216D480  thumb
 *   func_021C90AC  0x021C90AC  thumb
 *   func_021C90D0  0x021C90D0  thumb
 */

extern int func_02188CB4(int a);
extern int func_021A3074(int a);
extern int func_0216D3CC(int a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(int a, int b);
extern void func_020061E4(int a);
extern int func_0216D454(int a);
extern void func_0216D480(int a);
extern void func_021C90AC(int a);
extern int func_021C90D0(int a);

int func_021F3AB4(int a, int *s, int *t)
{
    int r6;

    r6 = func_021A3074(func_02188CB4(*(int *)(t[3] + 8)));
    switch (*s) {
    case 0:
        if (func_0216D3CC(r6) == 1) {
            func_0216D410(r6, func_02197E7C(*(unsigned short *)t, 0x1c));
            func_020061E4(0x55a);
            *s = *s + 1;
        }
    case 1:
        func_021C90AC(((int *)t[2])[1]);
        *s = *s + 1;
        break;
    case 2:
        if (func_021C90D0(((int *)t[2])[1]) == 0)
            break;
        *s = *s + 1;
    case 3:
        if (func_0216D454(r6) == 1) {
            func_0216D480(r6);
            return 1;
        }
        break;
    }
    return 0;
}
