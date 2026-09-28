/*
 * function: func_021BBE84
 * address:  0x021BBE84
 * packet:   pkt_ov021_021BBE84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050340  0x02050340  arm
 */
typedef unsigned short u16;
typedef signed char s8;

struct Head {
    unsigned char pad[4];
    void *h4;
    u16 tab[1];
};

typedef struct Src {
    struct Head *head;
    u16 idx;
    u16 x;
} Src;

typedef struct Res {
    struct Head *head;
    u16 idx;
    u16 x;
    u16 h8;
    unsigned char padA[4];
    short h0e;
} Res;

typedef struct Desc1 {
    u16 a, b, c;
    s8 d;
    int e, f;
} Desc1;

typedef struct Desc2 {
    int pad[3];
    int a;
    Res *b;
} Desc2;

extern Src *func_021AC1AC(int a);
extern void func_021AC1B8(int a, Desc2 *d);
extern void func_021AC154(int a);
extern u16 func_02050340(void *a, int b, Desc1 *c, int d, int e);

void func_021BBE84(int a0, Res *r)
{
    Desc2 d2;
    Desc1 d1;
    Src *s = func_021AC1AC(a0);

    *(Src *)r = *s;
    r->h0e = 0x1f;
    d1.a = r->head->tab[r->idx];
    d1.b = 0x1000;
    d1.c = 0x1000;
    d1.d = r->h0e;
    d1.e = 1;
    d1.f = 1;
    d2.a = 0;
    d2.b = r;
    func_021AC1B8(a0, &d2);
    r->h8 = func_02050340(r->head->h4, 0, &d1, 1, 3);
    if (r->h8 == 0xFFFF) {
        func_021AC154(a0);
    }
}
