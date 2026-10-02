/*
 * function: func_0216AE10
 * address:  0x0216AE10
 * packet:   pkt_ov010_0216AE10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012FB0  0x02012FB0  thumb
 *   func_0216662C  0x0216662C  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021767F0  0x021767F0  thumb  ov011
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_021665F0  0x021665F0  thumb  ov010
 *   func_0216B3A8  0x0216B3A8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_0215A5E4();
extern int func_02159B10();
extern int func_02012FB0();
extern int func_0216662C();
extern int func_0201210C();
extern int func_02188CB4(int p);
extern int func_02012138();
extern void func_021A3038();
extern void func_021767F0();
extern int func_02184D38();
extern int func_021665F0();
extern int func_0216B3A8();
extern void func_0215897C();

int func_0216AE10(int a0, int a1)
{
    int buf[3];
    int q[3];
    int hd;
    int b;
    int c;
    int kind;
    int v;
    int x;
    int y;
    int r;
    int s;

    hd = func_0215A5F4(a1);
    b = func_0215A5DC(a1);
    c = func_0215A5E4(a1);
    kind = func_02159B10(a0, a1);
    v = func_02012FB0(c);
    if (kind == 1 && func_0216662C(v) != 0) {
        x = func_0201210C(b);
        y = func_02188CB4(x);
        s = func_02012138(b);
        func_021A3038(y, q);
        func_021767F0(s, c, buf);
        buf[0] = buf[0] + (q[0] - (0x3E << 14));
        r = func_02184D38(b, x, 0x117, buf, 1, 0);
    } else {
        if (kind != 9)
            v = func_021665F0(b, func_02012FB0(c), kind);
        r = func_0216B3A8(b, kind, v);
    }
    func_0215897C(hd, r);
    return 1;
}
