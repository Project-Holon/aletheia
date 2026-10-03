/*
 * function: func_021B0EF4
 * address:  0x021B0EF4
 * packet:   pkt_ov021_021B0EF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B0EF4  0x021B0EF4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0202A310  0x0202A310  thumb
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0215A63C  0x0215A63C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_021B0B08  0x021B0B08  thumb  ov021
 *   func_021B0ADC  0x021B0ADC  thumb  ov021
 *   func_0215A660  0x0215A660  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021B0CEC  0x021B0CEC  thumb
 */

typedef unsigned short u16;

typedef struct V3 {
    int y;
    void *x;
    void *z;
} V3;

typedef struct S {
    u16 id;
    u16 flag;
    V3 sum;
    V3 a;
    V3 b;
} S;

extern void *func_0215A5F4(void *p);
extern unsigned char **func_02158F58(void *);
extern int func_02159B10(void *, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02158F78(u8 *p);
extern int func_02159190(int);
extern int func_0215A5CC(int);
extern void func_0202A310(int, int, int, int);
extern void *func_0215A5EC(int);
extern void *func_0216DE94(void *map, u32 id);
extern S *func_0215A63C(int);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D88C(void *, V3 *);
extern int func_021B0A40(void *, V3 *);
extern void func_021B0B08(int, int);
extern void func_021B0ADC(int, unsigned char *, int, V3 *, int, int, int);
extern void func_0215A660(int, int);
extern void func_020113D0(void *, int (*)(int, int));
extern int func_021B0CEC(int, int);

int func_021B0EF4(void *a, int b)
{
    void *o;
    unsigned char **q;
    int k0, k1, k2, m, r, flag;
    int y;
    void *x;
    void *z;
    S *s;
    V3 v;

    o = func_0215A5F4((void *)b);
    q = func_02158F58(o);
    k0 = func_02159B10(a, b);
    k1 = func_02159B10(a, b);
    k2 = func_02159B10(a, b);
    m = func_02158F78(o);
    if (func_02159190(2) != 0) {
        return 1;
    }
    func_0202A310(k0, k1, m, func_0215A5CC(b));
    if (func_0216DE94(func_0215A5EC(b), k2) == 0) {
        k2 = 0xff;
    }
    s = func_0215A63C(b);
    flag = 0;
    func_02082BCC(s, 0, 0x28);
    s->id = k2;
    x = func_02188CB4(q[1]);
    y = (int)func_0215A5EC(b);
    z = func_021A3074((void *)x);
    func_0216D88C(func_0216DE94((void *)y, s->id), &v);
    r = func_021B0A40(z, &v);
    if (r != 1) {
        flag = 1;
    }
    s->flag = flag;
    func_021B0B08(b, 1);
    func_021B0ADC(b, *q, flag, &s->sum, m, 0, 0);
    func_0215A660(b, r);
    func_020113D0(a, func_021B0CEC);
    return 1;
}
