/*
 * function: func_021B855C
 * address:  0x021B855C
 * packet:   pkt_ov071_021B855C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both tail returns are 0; the load of *p survives only through a
 * `switch` with a `default`, and `(!s[0xc]) == 1` keeps the boolean.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021B6F04  0x021B6F04  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_021B8798  0x021B8798  thumb  ov071
 */
#include "../include/Obj06187.h"

typedef struct {
    char pad0[8];
    void *f8;
} Q;

typedef struct {
    void **f0;
    Q *f4;
    unsigned char *f8;
    char pad[0x21];
    unsigned char f2d;
} C;

typedef unsigned int   u32;
struct Ctx;
struct Descriptor;
struct PrintSys;
typedef unsigned char  u8;
int func_021B855C(int a, int *p, C *c, unsigned char *d)
{
    extern u32 func_02012138(const struct Ctx *p);
    extern int func_02158344(int a0);
    extern int func_021B6F04(void **p, u8 *q);
    extern void *func_02045770(struct Descriptor *p);
    extern u32 func_0201C6C4(struct PrintSys *p, void *v);
    extern void func_02045334(struct Descriptor *d);
    extern void func_021B8798(C *, Q *, unsigned char *, int, unsigned);
    int r;
    int n;
    int i;

    r = func_02158344(func_02012138(*c->f0));
    n = 0;
    if (c->f2d == 1) {
        return 1;
    }
    func_021B6F04((void **)c->f4, d + 0x18);
    for (i = 0; i < 2; i++) {
        void *q = c->f4->f8;
        unsigned char *s = d + i * 8;
        if (s[0xc] != 0) {
            if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj06187 *)s)->f8))) == 0) {
                func_02045334(((struct Obj06187 *)s)->f8);
                s[0xc] = 0;
            }
        }
        if ((!s[0xc]) == 1) {
            n++;
        }
    }
    if (n == 2) {
        unsigned v = *c->f8;
        if (d[0x24] != v) {
            func_021B8798(c, c->f4, d, r, v);
            d[0x24] = *c->f8;
        }
    }
    switch (*p) {
    case 0:
        return 0;
    default:
        return 0;
    }
}
