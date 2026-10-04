/*
 * function: func_021F3B90
 * address:  0x021F3B90
 * packet:   pkt_ov059_021F3B90
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the task callback func_021F39B8 installs: steps w->g towards
 *           w->f and interpolates a position between w->c and w->d with a
 *           bump of w->e on the middle axis. Each difference goes through
 *           the named temporary k (the original computes it into r1 and
 *           copies it to r0 for muls; inline, it lands in r0 and the
 *           function is 6 bytes short). The tail is one if with the
 *           return 1 inside it (the inverse early return flips the blo).
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int b;
    V c;
    V d;
    int e;
    u16 f;
    u16 g;
} W;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern W *func_021897BC(void *p, int i);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4B4(void *p, int i, u16 j, int v);

int func_021F3B90(void *a)
{
    void *t;
    void *s;
    W *w;
    int flag;
    int n;
    int d;
    int k;
    V pos;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    flag = 1;
    w = func_021897BC(t, 1);
    if (w->b == 0)
        flag = 0;
    w->g++;
    n = w->g;
    d = w->f;
    k = w->d.a - w->c.a;
    pos.a = w->c.a + k * n / d;
    k = w->d.b - w->c.b;
    pos.b = w->c.b + k * n / d;
    k = w->d.c - w->c.c;
    pos.c = w->c.c + k * n / d;
    if (n >= (d + 1) / 2)
        n = d - n;
    pos.b += w->e * n / d;
    *func_021BE480(s, 0, flag) = pos;
    if (w->g >= w->f) {
        if (w->b == 1)
            func_021BE4B4(s, 0, flag, 1);
        return 1;
    }
    return 0;
}
