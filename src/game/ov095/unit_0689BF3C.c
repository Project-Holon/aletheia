/*
 * file:     unit_0689BF3C.c
 * function: func_0689BF3C
 * address:  0x0689BF3C
 * packet:   pkt_ov095_0689BF3C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_0689BFF8   0x0689BFF8  thumb  ov095
 *   func_0689C0A8   0x0689C0A8  thumb  ov095
 *   func_0689C1A4   0x0689C1A4  thumb  ov095
 *   func_0689C214   0x0689C214  thumb  ov095
 *   func_0689C464   0x0689C464  thumb  ov095
 */

typedef struct Word { int v; } Word;
typedef struct Blk { int w[9]; } Blk;
typedef struct Rec {
    int f00;
    Blk blk;
} Rec;

extern int func_0689C464(int, Word, void *, int, Blk *);
extern Rec *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, Rec *);
extern void func_0689BFF8(void *, void *);
extern void func_0689C0A8(void *, void *);
extern void func_0689C1A4(void *, void *);
extern void func_0689C214(void *, void *);

void func_0689BF3C(void *a, void *b, int c, int d, Word e)
{
    Blk buf;
    Rec *r;

    if (func_0689C464(d, e, b, 0, &buf) != 0) {
        r = func_021C88A4(a, 4, c);
        r->blk = buf;
        func_021C88C8(a, r);
    }
    switch (d) {
    case 14:
        func_0689BFF8(a, b);
        return;
    case 20:
        func_0689C0A8(a, b);
        return;
    case 19:
        func_0689C1A4(a, b);
        return;
    case 15:
        func_0689C214(a, b);
        return;
    }
}
