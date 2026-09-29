/*
 * function: func_021BBDD4
 * address:  0x021BBDD4
 * packet:   pkt_ov021_021BBDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5FC  0x0216D5FC  thumb  ov010
 *   func_021BBD84  0x021BBD84  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9AF8     0x021D9AF8  data  a4
 */

typedef unsigned short u16;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Arg {
    int a;
    u16 h;
} Arg;

extern int d_021D9AF8;

int func_021ABEA0(int a, int b);
u16 func_0216D5F8(int a);
u16 func_0216D5FC(int a);
int func_021BBD84(int a, int n, int x, int y);
void func_0216D88C(int a, Vec *out);
int func_0216D804(int a);
int func_0216D81C(int a);
void func_02164280(int a, int b, Vec *c);
void func_021ABFA8(int a, void *b, Vec *c, int d, Arg *e, int f);

void func_021BBDD4(int a, int b, int c)
{
    int x;
    int t;
    int u;
    int w;
    Vec v;
    Arg s;

    x = func_021ABEA0(b, 5);
    s.a = x;
    t = func_0216D5F8(a);
    u = func_0216D5FC(a);
    w = (u16)func_021BBD84(x, c, t, u);
    func_0216D88C(a, &v);
    t = func_0216D804(a);
    func_02164280(t, func_0216D81C(a), &v);
    if (c == 0 && (u16)(w + 0xFFFE) <= 1) {
        v.z -= 0x2000;
    } else if (c == 4 && (u16)(w + 0xFFFE) <= 1) {
        v.z -= 0x2000;
    }
    if (c == 4) {
        v.y -= *(int *)(x + 0x3c);
    }
    s.h = w;
    func_021ABFA8(b, &d_021D9AF8, &v, 0, &s, 0);
}
