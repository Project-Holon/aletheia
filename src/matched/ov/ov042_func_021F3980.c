/*
 * function: func_021F3980
 * address:  0x021F3980
 * packet:   pkt_ov042_021F3980
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern u8 *func_021897BC(void *a, int b);
struct Big;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u8 *func_0200B3A4(u32 a, u32 b);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6B8(u8 *p, int v);
extern int func_021BE6BC(u8 *p);
extern void func_021BE6CC(int a, int b, int c, int d, int e);

int func_021F3980(void *a, int *st)
{
    void *s;
    u32 t;
    u8 *p;
    u8 *q;
    u8 *e;
    u8 x;

    s = func_0201210C(func_020124E4(a));
    t = func_02188D2C(s);
    p = func_021897BC(s, 1);
    q = func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80(s))), 4);
    switch (*st) {
    case 0:
        x = p[1] + 9;
        func_021BE700((void *)t, 0, x, 0, 1);
        e = func_021BE674((char *)t, 0, x, 0);
        func_021BE6B0(e, 0);
        func_021BE6CC(t, 0, x, 0, 0);
        func_021BE6B8(e, 0);
        (*st)++;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674((char *)t, 0, (u8)(p[1] + 9), 0))) {
            q[p[1]] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
