/*
 * function: func_021F3828
 * address:  0x021F3828
 * packet:   pkt_ov053_021F3828
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     the five-word loop stores 0 (copied once from the zero in r4), not i.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   func_021C4D7C  0x021C4D7C  thumb  ov021
 *   func_021C4DC0  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021F3978  0x021F3978  thumb  ov053
 *   func_021F39BC  0x021F39BC  thumb  ov053
 *   func_021F3B30  0x021F3B30  thumb  ov053
 */

typedef unsigned short u16;

typedef struct O {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int w[5];
    char pad30[0x34];
    int f64;
    char f68[1];
} O;

extern int func_02188C84(int);
extern int func_02188D2C(int);
extern int func_02188C80(int);
extern int func_02012134(int);
extern int func_0202B57C(int);
extern int *func_02048F60(int, int, int);
extern int func_021BE480(int, int, int);
extern int func_021C4D14(int, int, int, int, int);
extern int func_021C4D7C(int, int);
extern void func_021C4DC0(int, int, int, int);
extern void func_020307B0(int *);
extern void func_021F3978(O *);
extern void func_021F39BC(O *);
extern void func_021F3B30(void *);

void func_021F3828(O *o, int q)
{
    int i;
    int a;
    int t8;
    int s0;
    int s1;
    int *p;
    int r;

    a = func_02188C84(q);
    t8 = func_02188D2C(q);
    i = 0;
    o->h0 = a;
    o->f64 = 0;
    o->f4 = func_0202B57C(func_02012134(func_02188C80(q)));
    p = func_02048F60(0x94, 1, a);
    s0 = func_021C4D14(q, func_021BE480(t8, 0, 0), 8, p[0] << 12, p[1]);
    func_021C4DC0(s0, 0x94, 3, 10);
    o->f8 = s0;
    func_020307B0(p);
    r = func_021C4D7C(q, func_021BE480(t8, 0, 1));
    func_021C4DC0(r, 0x94, 5, 10);
    o->fc = r;
    p = func_02048F60(0x94, 6, a);
    s1 = func_021C4D14(q, func_021BE480(t8, 0, 2), 9, p[0] << 12, p[1]);
    func_021C4DC0(s1, 0x94, 8, 10);
    o->f10 = s1;
    func_020307B0(p);
    r = func_021C4D7C(q, func_021BE480(t8, 0, 3));
    func_021C4DC0(r, 0x94, 10, 10);
    o->f14 = r;
    p = func_02048F60(0x94, 12, a);
    r = func_021C4D14(q, func_021BE480(t8, 0, 4), 7, p[0] << 12, p[1]);
    func_021C4DC0(r, 0x94, 11, 10);
    o->f18 = r;
    func_020307B0(p);
    for (i = 0; i < 5; i++)
        o->w[i] = 0;
    func_021F3978(o);
    func_021F39BC(o);
    func_021F3B30(o->f68);
}
