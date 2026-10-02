/*
 * function: func_021F3AF8
 * address:  0x021F3AF8
 * packet:   pkt_ov064_021F3AF8
 * region:   ov064
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct {
    u8 pad[0x18];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    u16 h34;
    u16 h36;
} W;

extern void *func_020124E4(void *task);
extern void *func_0201210C(void *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern int func_021BE480(int a, unsigned b, int c);

int func_021F3AF8(void *task)
{
    V3 v;
    W *w;
    void *sys;
    int s;
    int n;
    int m;
    int a;
    int d;

    sys = func_0201210C(func_020124E4(task));
    s = func_02188D2C(sys);
    w = (W *)func_021897BC((char *)sys, 1);
    w->h36++;
    a = w->f18;
    n = w->h36;
    d = w->f24 - a;
    m = w->h34;
    v.a = a + d * n / m;
    a = w->f1c;
    d = w->f28 - a;
    v.b = a + d * n / m;
    a = w->f20;
    d = w->f2c - a;
    v.c = a + d * n / m;
    if (n >= (m + 1) / 2)
        n = m - n;
    v.b += w->f30 * n / m;
    *(V3 *)func_021BE480(s, 0, 1) = v;
    if (w->h36 >= w->h34)
        return 1;
    return 0;
}
