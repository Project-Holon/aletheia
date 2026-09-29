/*
 * function: func_021F376C
 * address:  0x021F376C
 * packet:   pkt_ov061_021F376C
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F388C  0x021F388C  thumb  ov061
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021F3868  0x021F3868  thumb  ov061
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_02162478  0x02162478  thumb  ov010
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern int func_02188D2C(int a);
extern int func_02188CB4(int a);
extern int func_02188C80(int a);
extern int func_020120F4(int a);
extern int func_02012844(int a);
extern int *func_021897BC(int a, int idx);
extern int func_02188C9C(int a);
extern void func_021F388C(int *o, int a);
extern u8 *func_021BE674(int a, int b, int c, u16 d);
extern void func_021BE580(int a);
extern int func_021BE6BC(u8 *p);
extern void func_021BE4B4(int a, int b, int c, int d);
extern int func_021F3868(int *o, int g);
extern int func_021A3050(int g);
extern void func_021A3364(int g, int b, V3 *out);
extern int func_02162478(int h, V3 *v);
extern void func_021BE6CC(int a, int b, int c, u16 d, int e);
extern void func_021BE6B0(u8 *p, int v);

void func_021F376C(int a)
{
    int *o;
    int s;
    int g;
    int h;
    int cur;
    u8 *e;
    V3 v;

    s = func_02188D2C(a);
    g = func_02188CB4(a);
    h = func_02012844(func_020120F4(func_02188C80(a)));
    o = func_021897BC(a, 0);
    cur = func_02188C9C(a);
    if (o[2] != cur) {
        func_021F388C(o, a);
        o[2] = cur;
    }
    e = func_021BE674(s, 0, 0, 0);
    func_021BE580(s);
    if (o[0] != 0 && func_021BE6BC(e) != 0) {
        func_021BE4B4(s, 0, 0, 1);
        o[0] = 0;
    }
    if (func_021F3868(o, g) == 0) {
        return;
    }
    func_021A3364(g, func_021A3050(g), &v);
    v.a -= 0x8000;
    v.c -= 0x8000;
    if (func_02162478(h, &v) == 0) {
        return;
    }
    o[0] = 1;
    func_021BE4B4(s, 0, 0, 0);
    e = func_021BE674(s, 0, 0, 0);
    func_021BE6CC(s, 0, 0, 0, 0);
    func_021BE6B0(e, 0);
    *(V3 *)o[1] = v;
}
