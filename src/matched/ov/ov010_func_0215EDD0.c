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

extern void *func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern void func_02159058(void *p, u32 a, u32 b, u32 c, u32 d);
extern void *func_02184EEC(void *p);
extern void func_0201235C(void *a, void *b);

int func_0215EDD0(void *a, int *st, struct C *c)
{
    u32 h;
    void *t;

    switch (*st) {
    case 0:
        h = c->fc;
        t = func_02158780(a, 0x271a, 0, 0, 0x15);
        func_02159058(t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_0201235C(a, func_02184EEC(c->f8));
        break;
    }
    return 0;
}
