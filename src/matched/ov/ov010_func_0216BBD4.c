/*
 * function: func_0216BBD4
 * address:  0x0216BBD4
 * packet:   pkt_ov010_0216BBD4
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
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F39B8  0x021F39B8  thumb  ov045
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_0201210C(int p);
extern int func_02159B10();
extern int func_02188CB4();
extern void func_021A3038();
extern int func_021F39B8();
extern void func_0215897C();

int func_0216BBD4(int c, int vm)
{
    int ws;
    int p8;
    int p10;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int buf[3];
    int vec[3];
    int *x;
    int *y;
    int r;

    ws = func_0215A5F4(vm);
    p8 = func_0215A5DC(vm);
    p10 = func_0201210C(p8);
    a1 = func_02159B10(c, vm);
    a2 = func_02159B10(c, vm);
    a3 = func_02159B10(c, vm);
    a4 = func_02159B10(c, vm);
    a5 = func_02159B10(c, vm);
    a6 = func_02159B10(c, vm);
    func_021A3038(func_02188CB4(p10), buf);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    if (a1 == 0) {
        x = buf;
        y = vec;
    } else {
        x = vec;
        y = buf;
    }
    r = func_021F39B8(p8, a1, x, y, a5 << 15, a6);
    if (r == 0) {
        return 1;
    }
    func_0215897C(ws, r);
    return 1;
}
