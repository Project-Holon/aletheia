/*
 * function: func_021AFDAC
 * address:  0x021AFDAC
 * packet:   pkt_ov021_021AFDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02012104  0x02012104  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_02162A6C  0x02162A6C  thumb  ov010
 *   func_02184E40  0x02184E40  thumb  ov020
 *   func_021BB578  0x021BB578  thumb  ov021
 */

extern int func_0215A5F4();
extern int func_02158F54();
extern int func_0201210C();
extern int func_02011330();
extern int func_02012104();
extern int func_02012374();
extern int func_020120F4();
extern int func_02012844();
extern int func_0201296C();
extern int func_02188CB4();
extern int func_02188CD0();
extern int func_021A3038();
extern int func_021A3074();
extern int func_0216282C();
extern int func_02162A6C();
extern int func_02184E40();
extern int func_021BB578();

int func_021AFDAC(int a0, int a1)
{
    int h;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int w;
    int out[3];
    int arr[3];
    int buf[3];

    h = func_02158F54(func_0215A5F4(a1));
    a = func_0201210C();
    b = func_02011330(a0);
    c = func_02011330(a0);
    d = func_02011330(a0);
    e = func_020120F4(h);
    f = func_02012844();
    g = func_0201296C(e);
    func_021A3038(func_02188CB4(a), buf);
    w = func_0216282C(f, g, buf, 9);
    if (w != 0)
        func_02162A6C(w, out);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104(h);
    func_02012374(w, func_02184E40(h, a, out, b, arr));
    g = func_021A3074(func_02188CB4(a));
    func_021BB578(func_02188CD0(a), g, 0, 1);
    return 1;
}
