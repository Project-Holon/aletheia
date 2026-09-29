/*
 * function: func_021B0000
 * address:  0x021B0000
 * packet:   pkt_ov021_021B0000
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
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3E8  0x021BB3E8  thumb  ov021
 *   func_02184DE8  0x02184DE8  thumb  ov020
 */

extern int func_0215A5F4();
extern int func_02158F54();
extern int func_0201210C();
extern int func_02011330();
extern int func_02012104();
extern int func_02012374();
extern int func_02188C5C();
extern int func_021BB3E8();
extern int func_02184DE8();

int func_021B0000(int a0, int a1)
{
    int h;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int w;
    int loc[2];

    h = func_02158F54(func_0215A5F4(a1));
    a = func_0201210C();
    b = func_02011330(a0);
    c = func_02011330(a0);
    d = func_02011330(a0);
    e = func_02011330(a0);
    f = func_02011330(a0);
    w = func_02012104(h);
    func_021BB3E8(func_02188C5C(a), b, c, d, e, loc, 0x15);
    func_02012374(w, func_02184DE8(h, a, b, loc, f, 0));
    return 1;
}
