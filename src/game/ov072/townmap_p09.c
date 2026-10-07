/*
 * file:     townmap_p09.c
 * unit:     yes
 * function: func_021BACB0, func_021BAD10
 * address:  0x021BACB0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_021BBB3C  0x021BBB3C  thumb  ov072
 *   func_0204B5AC  0x0204B5AC  arm
 */
struct Obj;
struct Pair;
typedef unsigned int u32;

typedef struct {
    int f[13];
    int f34;
    int f38;
    int f3c;
    int f40;
} W_021BACB0;

typedef unsigned short u16;

typedef struct {
    int obj;
    char *f4;
    int f8;
    int v[8];
    int f2c;
    int f30;
    int f34;
} W_021BAD10;

extern int func_021BA774(char *p, int i);
extern u16 func_021BBB3C(char *p, int a, int b);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
int func_021BACB0(W_021BACB0 *p, int *c, int *o, u32 *out);
void func_021BAD10(W_021BAD10 *p, int s, int *r);


int func_021BACB0(W_021BACB0 *p, int *c, int *o, u32 *out)
{
    int x;
    int y;
    int dx;
    int dy;
    int a;
    int lim;

    x = o[0] + func_021BA774((char *)p, 4);
    y = o[1] + func_021BA774((char *)p, 5);
    dx = x - c[0];
    dx = dx * dx;
    dy = y - c[1];
    dy = dy * dy;
    if (p->f40 != 0) {
        return 0;
    }
    a = p->f34;
    if (a < 0) {
        a = -a;
    }
    lim = (a * 0x90) >> 12;
    if ((u32)(dx + dy) < lim) {
        if (out != 0) {
            *out = dx + dy;
        }
        return 1;
    }
    return 0;
}


void func_021BAD10(W_021BAD10 *p, int s, int *r)
{
    int i;
    int base;
    int d;
    int t[2];

    for (i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            base = r[0];
        } else {
            base = r[1];
        }
        d = func_021BBB3C(p->f4, (u16)p->f8, i + 2) - base;
        d = d * s >> 12;
        p->v[i] = d + base;
    }
    p->f2c = s * func_021BBB3C(p->f4, (u16)p->f8, 10) >> 12;
    p->f34 = s;
    if (p->obj != 0) {
        t[0] = s;
        t[1] = s;
        func_0204B5AC((struct Obj *)p->obj, (struct Pair *)t);
    }
}
