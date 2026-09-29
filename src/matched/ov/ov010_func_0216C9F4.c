/*
 * function: func_0216C9F4
 * address:  0x0216C9F4
 * packet:   pkt_ov010_0216C9F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_020144DC  0x020144DC  thumb
 *   func_0216C9CC  0x0216C9CC  thumb  ov010
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */

extern int func_02161824(int);
extern void func_02012374(int, int);
extern int func_02029BCC(int, int);
extern void func_02188CE8(int);
extern void func_021AAABC(void);
extern int func_02189A08(int);
extern void func_021CF498(int, int, int);
extern int func_020144DC(int, int);
extern int func_0216C9CC(int, int, int);
extern int func_02029C00(int);
extern int func_020145CC(int);
extern int func_02029CC0(int);
extern int func_021BE92C(int, int, int, int, int, int, int);

int func_0216C9F4(int a, int *st, int *o)
{
    int x = o[0];
    int y = o[1];
    switch (*st) {
    case 0:
        func_02012374(a, func_02161824(x));
        (*st)++;
        break;
    case 1:
        func_02012374(a, func_02029BCC(x, *(unsigned short *)(o[2] + 0x18)));
        (*st)++;
        break;
    case 2:
        func_02188CE8(y);
        func_021AAABC();
        func_021CF498(func_02189A08(o[1]), a, 9);
        (*st)++;
        break;
    case 3:
        func_02012374(a, func_020144DC(x, y));
        (*st)++;
        break;
    case 4:
        func_02012374(a, func_0216C9CC(x, o[2], o[3]));
        (*st)++;
        break;
    case 5:
        func_02012374(a, func_02029C00(x));
        (*st)++;
        break;
    case 6:
        func_02012374(a, func_020145CC(x));
        (*st)++;
        break;
    case 7:
        func_02012374(a, func_02029CC0(x));
        (*st)++;
        break;
    case 8:
        func_02012374(a, func_021BE92C(x, y, 0, 0, 1, 0, 0));
        (*st)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}
