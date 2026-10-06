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

extern int func_02188D2C(int *p);
extern void *func_02188CB4(unsigned char *p);
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern int *func_021897BC(char *a, int idx);
extern u16 func_02188C9C(u8 *p);
extern void func_021F388C(int *o, int a);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE580(int a);
extern int func_021BE6BC(int *p);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern int func_021F3868(void *unused, void *x);
extern u16 func_021A3050(u8 *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_02162478(char *p, int *v);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void func_021BE6B0(u8 *p, int v);

void func_021F376C(u8 *a)
{
    int *o;
    int s;
    void *g;
    int h;
    int cur;
    u8 *e;
    V3 v;

    s = func_02188D2C((int *)a);
    g = func_02188CB4(a);
    h = func_02012844(func_020120F4(func_02188C80(a)));
    o = func_021897BC((char *)a, 0);
    cur = func_02188C9C(a);
    if (o[2] != cur) {
        func_021F388C(o, (int)a);
        o[2] = cur;
    }
    e = func_021BE674((char *)s, 0, 0, 0);
    func_021BE580(s);
    if (o[0] != 0 && func_021BE6BC((int *)e) != 0) {
        func_021BE4B4((char *)s, 0, 0, 1);
        o[0] = 0;
    }
    if (func_021F3868(o, g) == 0) {
        return;
    }
    func_021A3364(g, func_021A3050(g), (int *)(&v));
    v.a -= 0x8000;
    v.c -= 0x8000;
    if (func_02162478((char *)h, (int *)(&v)) == 0) {
        return;
    }
    o[0] = 1;
    func_021BE4B4((char *)s, 0, 0, 0);
    e = func_021BE674((char *)s, 0, 0, 0);
    func_021BE6CC(s, 0, 0, 0, 0);
    func_021BE6B0(e, 0);
    *(V3 *)o[1] = v;
}
