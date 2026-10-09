/*
 * file:     unit_0689BFF8.c
 * function: func_0689BFF8
 * address:  0x0689BFF8
 * packet:   pkt_ov095_0689BFF8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689C048   0x0689C048  thumb  ov095
 *   func_0689C058   0x0689C058  thumb  ov095
 *   func_0689C068   0x0689C068  thumb  ov095
 *   func_0689C078   0x0689C078  thumb  ov095
 *   func_0689C088   0x0689C088  thumb  ov095
 *   func_0689C098   0x0689C098  thumb  ov095
 */

typedef unsigned char u8;

typedef struct Rec {
    int f00;
    int f04;
    int f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
} Rec;

extern int func_0689C048(int, int);
extern int func_0689C058(void *);
extern int func_0689C068(void *);
extern Rec *func_0689C078(void *, int, int);
extern int func_0689C088(u8);
extern void func_0689C098(void *, Rec *);

void func_0689BFF8(void *a, void *b)
{
    int n;
    int k;
    Rec *r;

    n = func_0689C048(2, 4);
    if (n > 0) {
        if (func_0689C058(b) == 0) {
            k = func_0689C068(b);
            r = func_0689C078(a, 0xc, k);
            r->f0c = 1;
            r->f04 = 2;
            r->f08 = func_0689C088(n);
            r->f0f = k;
            func_0689C098(a, r);
        }
    }
}
