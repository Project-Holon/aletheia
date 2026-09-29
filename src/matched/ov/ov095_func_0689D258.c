/*
 * function: func_0689D258
 * address:  0x0689D258
 * packet:   pkt_ov095_0689D258
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0689D2B8  0x0689D2B8  thumb
 *   func_0689D2C8  0x0689D2C8  thumb
 *   func_0689D2D8  0x0689D2D8  thumb
 *   func_0689D2E8  0x0689D2E8  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

typedef struct {
    Rec r[6];
    u8 idx[6];
} T;

extern void func_0689D2B8(int, int, u8 *, u8 *);
extern int func_0689D2C8(int, int, int);
extern int func_0689D2D8(int);
extern int func_0689D2E8(int);

void func_0689D258(T *a, int b, int c, u8 d)
{
    u8 o1;
    u8 o0;
    int x;
    int y;

    func_0689D2B8(b, d, &o1, &o0);
    x = func_0689D2C8(c, o1, o0);
    if (x != 0 && func_0689D2D8(x) == 0) {
        y = func_0689D2E8(x);
        a->r[d].c = y;
        a->idx[y] = d;
    } else {
        a->r[d].c = 0x1f;
    }
    a->r[d].b = o1;
    a->r[d].a = 1;
}
