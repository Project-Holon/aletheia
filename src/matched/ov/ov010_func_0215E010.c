/*
 * function: func_0215E010
 * address:  0x0215E010
 * packet:   pkt_ov010_0215E010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_021CD688  0x021CD688  thumb  ov021
 *   func_021FC804  0x021FC804  thumb  ov132
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct W {
    u8 pad00[4];
    void *f4;
    void *f8;
    u8 pad0c[0x24];
    u16 *f30;
};

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *p);
extern struct W *func_02012F80(void *p);
extern u32 func_021CD688(u8 *p);
extern void func_021FC804(char *p);
extern u32 func_021CD5A4(u32 *p);

int func_0215E010(void *a, void *b)
{
    struct W *w;
    int r;
    int v;

    func_0215A5F4(b);
    w = func_02012F80(func_0215A5E4(b));
    r = 0;
    switch (func_021CD688(w->f8)) {
    case 1:
        *w->f30 = 3;
        func_021FC804(w->f4);
        r = 1;
        break;
    case 2:
        v = 4;
        *w->f30 = v;
        r = 1;
        break;
    case 4:
        v = 2;
        *w->f30 = v;
        r = 1;
        break;
    }
    if (r == 1) {
        func_021CD5A4(w->f8);
        w->f8 = 0;
    }
    return r;
}
