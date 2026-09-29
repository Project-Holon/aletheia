/*
 * function: func_021AFCD8
 * address:  0x021AFCD8
 * packet:   pkt_ov021_021AFCD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02012104  0x02012104  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02184D38  0x02184D38  thumb  ov020
 */

extern int func_0215A5F4();
extern int func_02158F54();
extern int func_0201210C();
extern int func_02011330();
extern int func_02012104();
extern int func_02012374();
extern int func_02184D38();

int func_021AFCD8(int a0, int a1)
{
    int h;
    int a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = func_02158F54(func_0215A5F4(a1));
    a = func_0201210C();
    b = func_02011330(a0);
    c = func_02011330(a0);
    d = func_02011330(a0);
    e = func_02011330(a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104(h);
    func_02012374(w, func_02184D38(h, a, b, arr, e, 0));
    return 1;
}
