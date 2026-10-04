/*
 * function: func_021B0E74
 * address:  0x021B0E74
 * packet:   pkt_ov021_021B0E74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B0E74  0x021B0E74  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021B0BAC  0x021B0BAC  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_021B0CEC  0x021B0CEC  thumb
 */

extern unsigned int func_02159B10(void *, void *);
extern int func_021B0BAC(int, int, int, int, int, int);
extern void func_020113D0(int, int (*)(int, int));
extern int func_021B0CEC(int, int);

int func_021B0E74(int a, int b)
{
    int v0, v2, v3, v4, v5;
    v0 = func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    v4 = func_02159B10((void *)a, (void *)b);
    v5 = func_02159B10((void *)a, (void *)b);
    if (func_021B0BAC(b, v3, v0, v2, v4, v5) == 1) {
        func_020113D0(a, func_021B0CEC);
        return 1;
    }
    return 0;
}
