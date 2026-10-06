/*
 * function: func_0215EDD0
 * address:  0x0215EDD0
 * packet:   pkt_ov010_0215EDD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02184EEC  0x02184EEC  thumb  ov020
 *   func_0201235C  0x0201235C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

extern int func_02158780(void *p, int b, int c, int d, u16 e);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02184EEC(void *p);
struct S0201235C;
extern void func_0201235C(struct S0201235C *o, u32 *out);

int func_0215EDD0(void *a, int *st, struct C *c)
{
    u32 h;
    void *t;

    switch (*st) {
    case 0:
        h = c->fc;
        t = (void *)func_02158780(a, 0x271a, 0, 0, 0x15);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_0201235C(a, func_02184EEC(c->f8));
        break;
    }
    return 0;
}
